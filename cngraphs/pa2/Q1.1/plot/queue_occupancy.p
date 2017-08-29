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
