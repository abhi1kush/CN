#!/bin/bash

tcpdump -nn -tt -r tcp-example-0-0.pcap > node0_tcpdump.txt
tcpdump -nn -tt -r tcp-example-1-0.pcap > node1_tcpdump.txt

tmp_script/./seq_ack.py 
tmp_script/./tcp_throughput.py 
tmp_script/./queue_occupancy.py 
tmp_script/./queueing_delay.py 

gnuplot <<- EOF
	load "tmp_plot/all_graphs.p"
	
EOF

#gnuplot --persist -e 'plot "queue_occupancy.txt" u 1:2 with linespoints' > queue_occupancy.png
#gnuplot --persist -e 'plot "queueing_delay.txt" u 1:2 with linespoints' > queueing_delay.png

