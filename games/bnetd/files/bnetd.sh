#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	cd ${PREFIX}; [ -x sbin/bnetd -a -f bnetd/conf/bnetd.conf ] && sbin/bnetd -c bnetd/conf/bnetd.conf > /dev/null && echo -n ' bnetd'
	;;
stop)
	killall bnetd && echo -n ' bnetd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
