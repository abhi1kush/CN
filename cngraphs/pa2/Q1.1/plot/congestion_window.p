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
