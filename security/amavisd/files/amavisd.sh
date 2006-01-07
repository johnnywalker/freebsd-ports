#!/bin/sh
#
# $FreeBSD: ports/security/amavisd/files/amavisd.sh,v 1.4 2004/05/30 11:33:25 pav Exp $
#
 
# PROVIDE: amavisd
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

prefix=%%PREFIX%%

# Define these amavisd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
amavisd_enable="${amavisd_enable-NO}"
amavisd_flags=""
amavisd_user=%%AMAVISUSER%%

. %%RC_SUBR%%

name="amavisd"
rcvar=`set_rcvar`
start_precmd="remove_socket"
stop_postcmd="remove_socket"
command=${prefix}/sbin/amavisd
command_arg="> /dev/null 2>&1"
command_interpreter="%%PERL%%"
pidfile="/var/amavis/amavisd.pid"

# Remove the AMaViSd Socket
remove_socket()
{
	if [ -S /var/amavis/amavisd.sock ]; then
		rm -f /var/amavis/amavisd.sock
	fi
}

load_rc_config $name
run_rc_command "$1"
