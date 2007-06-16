#!/bin/sh
#
# $FreeBSD: ports/dns/maradns/files/rc_d.sh,v 1.3 2006/02/20 20:46:57 dougb Exp $
#

# PROVIDE: %%SERVICE%%
# REQUIRE: SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move %%SERVICE%%.sh to /etc/rc.d/%%SERVICE%%

prefix=%%PREFIX%%

# Define these %%SERVICE%%_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/%%SERVICE%%
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
%%SERVICE%%_enable=${%%SERVICE%%_enable-"NO"}
# %%SERVICE%%_flags can be something like "-f /path/alternate_rc"

. %%RC_SUBR%%

name="%%SERVICE%%"
rcvar=`set_rcvar`
command="${prefix}/bin/duende"
pidfile="/var/run/${name}.pid"

load_rc_config $name

flags="${prefix}/sbin/${name} ${%%SERVICE%%_flags}"

run_rc_command "$1"
