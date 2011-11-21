#!/bin/sh
case `uname -s` in
"FreeBSD")
	PLATFORM="freebsd"
	;;
"Linux")
    gnome-open $1 > /dev/null 2>&1
	;;
"Darwin")
    open $1
	;;
"SunOS")
	PLATFORM="solaris"
	;;
"CYGWIN_NT-6.1-WOW64")
	PLATFORM="linux"
	;;
*)
	echo "Unknown platform" >&2
	exit 1
esac
echo $PLATFORM
exit 0
