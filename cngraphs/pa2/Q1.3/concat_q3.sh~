#!/bin/bash
cat > throughput_q3.txt <<-EOF
start
EOF
cat 1ms/tcp_throughput.txt >> throughput_q3.txt

cat >> throughput_q3.txt <<-EOF
end
start
EOF
cat 5ms/tcp_throughput.txt >> throughput_q3.txt

cat >> throughput_q3.txt <<-EOF
end
start
EOF
cat 10ms/tcp_throughput.txt >> throughput_q3.txt
cat >> throughput_q3.txt <<-EOF
end
start
EOF
cat 50ms/tcp_throughput.txt >> throughput_q3.txt
cat >> throughput_q3.txt <<-EOF
end
start
EOF
cat 100ms/tcp_throughput.txt >> throughput_q3.txt
cat >> throughput_q3.txt <<-EOF
end
EOF

python avg_throughput_q3.py
gnuplot <<EOF 
load "avg_throughput_q3.p"
EOF


