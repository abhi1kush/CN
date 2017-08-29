set autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Queueing Delay"
set xlabel "Time"
set ylabel "Queueing Delay"

set term png 
set output "queueing_delay.png" ;
plot "queueing_delay.txt" u 1:2 title "Queueing Delay" with linespoint;

set term x11
plot "queueing_delay.txt" u 1:2 title "Queueing Delay" with linespoint;

