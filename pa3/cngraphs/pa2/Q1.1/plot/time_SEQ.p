set   autoscale                        

unset log                              
unset label
                            
set xtic auto              
set ytic auto                          

set title "Graph between Sequence no. and Time "

set xlabel "Time"
set ylabel "Sequence Number"

set term png 
set output "tcp_SEQ.png" ;
plot "time_SEQ.txt" using 1:2 title "Seq no." with  linespoint;
set term x11

plot "time_SEQ.txt" using 1:2 title "Seq no." with  linespoint;
