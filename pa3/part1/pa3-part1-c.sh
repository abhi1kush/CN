echo "1" > /proc/sys/net/ipv4/ip_forward
modprobe ip_tables
modprobe ip_conntrack
modprobe ip_conntrack_irc
modprobe ip_conntrack_ftp

iptables -F
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
sudo iptables -t nat -A OUTPUT -p tcp  -s 192.168.7.41 -d 192.168.6.41 --dport 5000 -j DNAT --to-destination 10.16.35.77:5041

