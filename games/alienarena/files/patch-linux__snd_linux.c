--- ./linux/snd_linux.c.orig	Tue May 16 15:20:09 2006
+++ ./linux/snd_linux.c	Tue May 16 15:20:10 2006
@@ -25,13 +25,17 @@
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include <stdio.h>
 
 #include "../client/client.h"
 #include "../client/snd_loc.h"
 
-int audio_fd;
+int audio_fd = -1;
 int snd_inited;
 
 cvar_t *sndbits;
@@ -39,24 +43,26 @@
 cvar_t *sndchannels;
 cvar_t *snddevice;
 
-static int tryrates[] = { 11025, 22051, 44100, 8000 };
+static int tryrates[] = { 11025, 22051, 44100, 48000, 8000 };
 
 qboolean SNDDMA_Init(void)
 {
 
 	int rc;
-    int fmt;
+	int fmt;
 	int tmp;
-    int i;
-    char *s;
+	int i;
 	struct audio_buf_info info;
 	int caps;
 	extern uid_t saved_euid;
 
 	if (snd_inited)
-		return;
+		return 1;
 
-	if (!snddevice) {
+	snd_inited = 0;
+	
+	if (!snddevice)
+	{
 		sndbits = Cvar_Get("sndbits", "16", CVAR_ARCHIVE);
 		sndspeed = Cvar_Get("sndspeed", "0", CVAR_ARCHIVE);
 		sndchannels = Cvar_Get("sndchannels", "2", CVAR_ARCHIVE);
@@ -65,165 +71,182 @@
 
 // open /dev/dsp, confirm capability to mmap, and get size of dma buffer
 
-	if (!audio_fd) {
+	if (audio_fd == -1)
+	{
 		seteuid(saved_euid);
 
 		audio_fd = open(snddevice->string, O_RDWR);
 
-		seteuid(getuid());
-
-		if (audio_fd < 0)
+		if (audio_fd == -1)
 		{
 			perror(snddevice->string);
-			Com_Printf("Could not open %s\n", snddevice->string);
+			seteuid(getuid());
+			Com_Printf("SNDDMA_Init: Could not open %s.\n", snddevice->string);
 			return 0;
 		}
+		seteuid(getuid());
 	}
 
-    rc = ioctl(audio_fd, SNDCTL_DSP_RESET, 0);
-    if (rc < 0)
+	rc = ioctl(audio_fd, SNDCTL_DSP_RESET, 0);
+	if (rc == -1)
 	{
 		perror(snddevice->string);
-		Com_Printf("Could not reset %s\n", snddevice->string);
+		Com_Printf("SNDDMA_Init: Could not reset %s.\n", snddevice->string);
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
 
 	if (ioctl(audio_fd, SNDCTL_DSP_GETCAPS, &caps)==-1)
 	{
 		perror(snddevice->string);
-        Com_Printf("Sound driver too old\n");
+		Com_Printf("SNDDMA_Init: Sound driver too old.\n");
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
 
 	if (!(caps & DSP_CAP_TRIGGER) || !(caps & DSP_CAP_MMAP))
 	{
-		Com_Printf("Sorry but your soundcard can't do this\n");
+		Com_Printf("SNDDMA_Init: Sorry, but your soundcard doesn't support trigger or mmap. (%08x)\n", caps);
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
 
-    if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
-    {   
-        perror("GETOSPACE");
-		Com_Printf("Um, can't do GETOSPACE?\n");
+	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
+	{   
+		perror("GETOSPACE");
+		Com_Printf("SNDDMA_Init: GETOSPACE ioctl failed.\n");
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
-    }
+	}
     
 // set sample bits & speed
 
-    dma.samplebits = (int)sndbits->value;
+	dma.samplebits = (int)sndbits->value;
 	if (dma.samplebits != 16 && dma.samplebits != 8)
-    {
-        ioctl(audio_fd, SNDCTL_DSP_GETFMTS, &fmt);
-        if (fmt & AFMT_S16_LE) dma.samplebits = 16;
-        else if (fmt & AFMT_U8) dma.samplebits = 8;
-    }
-
-	dma.speed = (int)sndspeed->value;
-	if (!dma.speed) {
-        for (i=0 ; i<sizeof(tryrates)/4 ; i++)
-            if (!ioctl(audio_fd, SNDCTL_DSP_SPEED, &tryrates[i])) break;
-        dma.speed = tryrates[i];
-    }
-
-	dma.channels = (int)sndchannels->value;
-	if (dma.channels < 1 || dma.channels > 2)
-		dma.channels = 2;
-	
-	dma.samples = info.fragstotal * info.fragsize / (dma.samplebits/8);
-	dma.submission_chunk = 1;
-
-// memory map the dma buffer
+	{
+		ioctl(audio_fd, SNDCTL_DSP_GETFMTS, &fmt);
+		if (fmt & AFMT_S16_LE) dma.samplebits = 16;
+		else if (fmt & AFMT_U8) dma.samplebits = 8;
+	}
 
-	if (!dma.buffer)
-		dma.buffer = (unsigned char *) mmap(NULL, info.fragstotal
-			* info.fragsize, PROT_WRITE, MAP_FILE|MAP_SHARED, audio_fd, 0);
-	if (!dma.buffer)
+	if (dma.samplebits == 16)
+	{
+        	rc = AFMT_S16_LE;
+		rc = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &rc);
+		if (rc < 0)
+		{
+			perror(snddevice->string);
+			Com_Printf("SNDDMA_Init: Could not support 16-bit data.  Try 8-bit.\n");
+			close(audio_fd);
+			audio_fd = -1;
+			return 0;
+		}
+	}
+	else if (dma.samplebits == 8)
+    	{
+		rc = AFMT_U8;
+		rc = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &rc);
+		if (rc < 0)
+		{
+			perror(snddevice->string);
+			Com_Printf("SNDDMA_Init: Could not support 8-bit data.\n");
+			close(audio_fd);
+			audio_fd = -1;
+			return 0;
+		}
+	}
+	else
 	{
 		perror(snddevice->string);
-		Com_Printf("Could not mmap %s\n", snddevice->string);
+		Com_Printf("SNDDMA_Init: %d-bit sound not supported.", dma.samplebits);
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
 
+	dma.speed = (int)sndspeed->value;
+	if (!dma.speed)
+	{
+		for (i=0 ; i<sizeof(tryrates)/4 ; i++)
+			if (!ioctl(audio_fd, SNDCTL_DSP_SPEED, &tryrates[i]))
+				break;
+		dma.speed = tryrates[i];
+	}
+
+	dma.channels = (int)sndchannels->value;
+	if (dma.channels < 1 || dma.channels > 2)
+		dma.channels = 2;
+        
 	tmp = 0;
 	if (dma.channels == 2)
 		tmp = 1;
-    rc = ioctl(audio_fd, SNDCTL_DSP_STEREO, &tmp);
-    if (rc < 0)
-    {
+	rc = ioctl(audio_fd, SNDCTL_DSP_STEREO, &tmp); //FP: bugs here.
+	if (rc < 0)
+	{
 		perror(snddevice->string);
-        Com_Printf("Could not set %s to stereo=%d", snddevice->string, dma.channels);
+		Com_Printf("SNDDMA_Init: Could not set %s to stereo=%d.", snddevice->string, dma.channels);
 		close(audio_fd);
-        return 0;
-    }
+		audio_fd = -1;
+		return 0;
+	}
+
 	if (tmp)
 		dma.channels = 2;
 	else
 		dma.channels = 1;
 
-    rc = ioctl(audio_fd, SNDCTL_DSP_SPEED, &dma.speed);
-    if (rc < 0)
-    {
+
+	rc = ioctl(audio_fd, SNDCTL_DSP_SPEED, &dma.speed);
+	if (rc < 0)
+	{
 		perror(snddevice->string);
-        Com_Printf("Could not set %s speed to %d", snddevice->string, dma.speed);
+		Com_Printf("SNDDMA_Init: Could not set %s speed to %d.", snddevice->string, dma.speed);
 		close(audio_fd);
-        return 0;
-    }
+		audio_fd = -1;
+		return 0;
+	}
 
-    if (dma.samplebits == 16)
-    {
-        rc = AFMT_S16_LE;
-        rc = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &rc);
-        if (rc < 0)
-		{
-			perror(snddevice->string);
-			Com_Printf("Could not support 16-bit data.  Try 8-bit.\n");
-			close(audio_fd);
-			return 0;
-		}
-    }
-    else if (dma.samplebits == 8)
-    {
-        rc = AFMT_U8;
-        rc = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &rc);
-        if (rc < 0)
-		{
-			perror(snddevice->string);
-			Com_Printf("Could not support 8-bit data.\n");
-			close(audio_fd);
-			return 0;
-		}
-    }
-	else
+	dma.samples = info.fragstotal * info.fragsize / (dma.samplebits/8);
+	dma.submission_chunk = 1;
+
+// memory map the dma buffer
+
+	if (!dma.buffer)
+		dma.buffer = (unsigned char *) mmap(NULL, info.fragstotal
+			* info.fragsize, PROT_WRITE|PROT_READ, MAP_FILE|MAP_SHARED, audio_fd, 0);
+	if (!dma.buffer || dma.buffer == MAP_FAILED)
 	{
 		perror(snddevice->string);
-		Com_Printf("%d-bit sound not supported.", dma.samplebits);
+		Com_Printf("SNDDMA_Init: Could not mmap %s.\n", snddevice->string);
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
 
 // toggle the trigger & start her up
 
-    tmp = 0;
-    rc  = ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp);
+	tmp = 0;
+	rc  = ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp);
 	if (rc < 0)
 	{
 		perror(snddevice->string);
-		Com_Printf("Could not toggle.\n");
+		Com_Printf("SNDDMA_Init: Could not toggle. (1)\n");
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
-    tmp = PCM_ENABLE_OUTPUT;
-    rc = ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp);
+	tmp = PCM_ENABLE_OUTPUT;
+	rc = ioctl(audio_fd, SNDCTL_DSP_SETTRIGGER, &tmp);
 	if (rc < 0)
 	{
 		perror(snddevice->string);
-		Com_Printf("Could not toggle.\n");
+		Com_Printf("SNDDMA_Init: Could not toggle. (2)\n");
 		close(audio_fd);
+		audio_fd = -1;
 		return 0;
 	}
 
@@ -231,12 +254,10 @@
 
 	snd_inited = 1;
 	return 1;
-
 }
 
 int SNDDMA_GetDMAPos(void)
 {
-
 	struct count_info count;
 
 	if (!snd_inited) return 0;
@@ -244,8 +265,9 @@
 	if (ioctl(audio_fd, SNDCTL_DSP_GETOPTR, &count)==-1)
 	{
 		perror(snddevice->string);
-		Com_Printf("Uh, sound dead.\n");
+		Com_Printf("SNDDMA_GetDMAPos: GETOPTR failed.\n");
 		close(audio_fd);
+		audio_fd = -1;
 		snd_inited = 0;
 		return 0;
 	}
@@ -254,7 +276,6 @@
 	dma.samplepos = count.ptr / (dma.samplebits / 8);
 
 	return dma.samplepos;
-
 }
 
 void SNDDMA_Shutdown(void)
@@ -263,6 +284,7 @@
 	if (snd_inited)
 	{
 		close(audio_fd);
+		audio_fd = -1;
 		snd_inited = 0;
 	}
 #endif
