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
