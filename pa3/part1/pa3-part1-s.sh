echo "1" > /proc/sys/net/ipv4/ip_forward
modprobe ip_tables
modprobe ip_conntrack
modprobe ip_conntrack_irc
modprobe ip_conntrack_ftp
iptables -F
ifconfig eth0:1 192.168.6.41
ifconfig eth0:2 192.168.6.42
ifconfig eth0:3 192.168.6.43

sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -s 10.16.35.77 -d 10.16.35.1 --dport 5041 -j DNAT --to-destination 192.168.6.41:5000

sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -s 10.16.35.77 -d 10.16.35.1 --dport 5042 -j DNAT --to-destination 192.168.6.42:5000

sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -s 10.16.35.77 -d 10.16.35.1 --dport 5043 -j DNAT --to-destination 192.168.6.43:5000
