
echo "1" > /proc/sys/net/ipv4/ip_forward

iptables -F
# Load iptables module:
modprobe ip_tables
        
# activate connection tracking
modprobe ip_conntrack

# Special features for IRC:
modprobe ip_conntrack_irc

# Special features for FTP:
modprobe ip_conntrack_ftp

bash ifconfig.sh

iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE

sudo iptables -t nat -A OUTPUT -p tcp -s 192.168.7.41 -d 192.168.6.41 --dport 5000  -j DNAT --to-destination 10.16.35.1:5041
sudo iptables -t nat -A OUTPUT -p tcp -s 192.168.7.42 -d 192.168.6.42 --dport 5000  -j DNAT --to-destination 10.16.35.1:5042
sudo iptables -t nat -A OUTPUT -p tcp -s 192.168.7.43 -d 192.168.6.43 --dport 5000  -j DNAT --to-destination 10.16.35.1:5043

