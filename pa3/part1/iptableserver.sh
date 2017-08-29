
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

sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -s 10.16.35.105 -d 10.16.35.77 --dport 5041 -j DNAT --to-destination 192.168.6.41:5000
sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -s 10.16.35.105 -d 10.16.35.77 --dport 5042 -j DNAT --to-destination 192.168.6.42:5000
sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -s 10.16.35.105 -d 10.16.35.77 --dport 5043 -j DNAT --to-destination 192.168.6.43:5000

