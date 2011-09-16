busybox ifconfig usb0 192.168.0.2  netmask 255.255.255.0
busybox route delete default
iptables -F
iptables -F -t nat
busybox route add default gw 192.168.0.1
setprop net.dns1 8.8.8.8
setprop "net.gprs.http-proxy" ""
