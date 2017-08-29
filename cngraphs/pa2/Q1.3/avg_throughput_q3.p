set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Graph between Throughput and Link Loss rate "

set xlabel "Link Loss rate"
set ylabel " Throughput "

set term png 
set output "avg_throughput_q3.png" ;
plot "avg_throughput_q3.txt" using 1:2 title " Throughput " with  linespoint ;
set term x11

plot "avg_throughput_q3.txt" using 1:2 title " Throughput " with  linespoint ;


