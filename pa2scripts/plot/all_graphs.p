set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Graph between Sequence no. and Time "

set xlabel "Time"
set ylabel "Sequence Number"

set term png 
set output "time_SEQ.png" ;
plot "time_SEQ.txt" using 1:2 title "Seq no." with  linespoint ,  "time_ACK.txt" using 1:2 title "Ack no." with linespoint lt rgb "blue";
set term x11

plot "time_SEQ.txt" using 1:2 title "Seq no." with  linespoint , "time_ACK.txt" using 1:2 title "Ack no." with linespoint lt rgb "blue";



set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Graph between Time and Ack Number"
set xlabel "Time"
set ylabel "Ack Number"

set term png 
set output "time_ACK.png" ;
plot "time_ACK.txt" using 1:2 title "Ack no." with linespoint;

set term x11
plot "time_ACK.txt" using 1:2 title "Ack no." with linespoint;




set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Graph between Time and Troughput per sec"
set xlabel "Time"
set ylabel "Throughput"

set term png 
set output "tcp_throughput.png" ;
plot "tcp_throughput.txt" using 1:2 title "Throughput bitps" with linespoint;

set term x11
plot "tcp_throughput.txt" using 1:2 title "Throughput bitps" with linespoint;


set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Queue Occupancy Graph"
set xlabel "Time"
set ylabel "Number of packets in queue"

set term png 
set output "queue_occupancy.png" ;
plot "queue_occupancy.txt" using 1:2 title "Number of packets in queue" with linespoint;

set term x11
plot "queue_occupancy.txt" using 1:2 title "Number of packets in queue" with linespoint;


set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Queueing Delay"
set xlabel "Time"
set ylabel "Queueing Delay"

set xr [0:10]
set yr [0.0:]

set term png 
set output "queueing_delay.png" ;
plot "queueing_delay.txt" using 1:2 title "Queueing Delay" with linespoint;

set term x11
plot "queueing_delay.txt" using 1:2 title "Queueing Delay" with linespoint;



set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "TCP Congestion Window Graph"
set xlabel "Time"
set ylabel "Change in Congestion window size"

set term png 
set output "congestion_window.png" ;
plot "tcp-example.cwnd" using 1:2 title "window size" with linespoint;

set term x11
plot "tcp-example.cwnd" using 1:2 title "window size" with linespoint;
