/*
 * Copyright (c) 1980, 1989, 1993, 1994
 *      The Regents of the University of California.  All rights reserved.
 * Copyright (c) 2001
 *      David Rufino <daverufino@btinternet.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* most of this was ripped from the mount(3) source */

#include "config.h"
#include "mntent.h"
#if !defined(HAVE_MNTENT_H)
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>

static int pos = -1;
static int mntsize = -1;
static struct mntent _mntent;

char *
hasmntopt (const struct mntent *mnt, const char *option)
{
        int found;
        char *opt, *optbuf;

        optbuf = strdup(mnt->mnt_opts);
        found = 0;
        for (opt = optbuf; (opt = strtok(opt, " ")) != NULL; opt = NULL) {
                if (!strcasecmp(opt, option)) {
			opt = opt - optbuf + mnt->mnt_opts;
			free (optbuf);
			return (opt);
		}
        }
	free (optbuf);
        return (NULL);
}

static char *
catopt (char *s0, const char *s1)
{
        size_t i;
        char *cp;

        if (s1 == NULL || *s1 == '\0')
                return s0;
        if (s0 && *s0) {
                i = strlen(s0) + strlen(s1) + 1 + 1;
                if ((cp = (char *)malloc(i)) == NULL)
			return (NULL);
                (void)snprintf(cp, i, "%s %s", s0, s1);
        } else
                cp = strdup(s1);

        if (s0)
                free(s0);
        return (cp);
}


static char *
flags2opts (int flags)
{
        char *res;
        res = NULL;
        res = catopt(res, (flags & MNT_RDONLY) ? "ro" : "rw");
        if (flags & MNT_SYNCHRONOUS)    res = catopt(res, "sync");
        if (flags & MNT_NOEXEC)         res = catopt(res, "noexec");
        if (flags & MNT_NOSUID)         res = catopt(res, "nosuid");
        if (flags & MNT_NODEV)          res = catopt(res, "nodev");
        if (flags & MNT_UNION)          res = catopt(res, "union");
        if (flags & MNT_ASYNC)          res = catopt(res, "async");
        if (flags & MNT_NOATIME)        res = catopt(res, "noatime");
        if (flags & MNT_NOCLUSTERR)     res = catopt(res, "noclusterr");
        if (flags & MNT_NOCLUSTERW)     res = catopt(res, "noclusterw");
        if (flags & MNT_NOSYMFOLLOW)    res = catopt(res, "nosymfollow");
        if (flags & MNT_SUIDDIR)        res = catopt(res, "suiddir");

        return res;
}

static struct mntent *
statfs_to_mntent (struct statfs *mntbuf)
{
	static char opts_buf[40], *tmp;
	
	_mntent.mnt_fsname = mntbuf->f_mntfromname;
	_mntent.mnt_dir = mntbuf->f_mntonname;
	_mntent.mnt_type = mntbuf->f_fstypename;
	tmp = flags2opts (mntbuf->f_flags);
	if (tmp) {
		opts_buf[sizeof(opts_buf)-1] = '\0';
		strncpy (opts_buf, tmp, sizeof(opts_buf)-1);
		free (tmp);
	} else {
		*opts_buf = '\0';
	}
	_mntent.mnt_opts = opts_buf;	
	_mntent.mnt_freq = _mntent.mnt_passno = 0;
	return (&_mntent);
}

struct mntent *
getmntent (FILE *fp)
{
	struct statfs *mntbuf;

	if (pos == -1 || mntsize == -1)
		mntsize = getmntinfo (&mntbuf, MNT_NOWAIT);

	++pos;
	if (pos == mntsize) {
		pos = mntsize = -1;
		return (NULL);
	}

	return (statfs_to_mntent (&mntbuf[pos]));
}

#endif /* HAVE_MNTENT_H */
