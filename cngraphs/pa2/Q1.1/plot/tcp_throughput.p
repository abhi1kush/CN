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
plot "tcp_throughput.txt" using 1:2 title "Throughput" with linespoint;

set term x11
plot "tcp_throughput.txt" using 1:2 title "Throughput" with linespoint;
