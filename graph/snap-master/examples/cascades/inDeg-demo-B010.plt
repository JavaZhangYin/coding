#
# demo N=98  E=200  Beta=0.1 (Thu Mar 20 14:49:30 2014)
#

set title "demo N=98  E=200  Beta=0.1"
set key bottom right
set autoscale
set grid
set xlabel "Fraction of observed data (P)"
set ylabel "Average In-Degree (of a non-root)"
set tics scale 2
set terminal png size 1000,800
set output 'inDeg-demo-B010.png'
plot 	"inDeg-demo-B010.tab" using 1:3 title "Influence cascade Average" with linespoints lw 2,\
	"inDeg-demo-B010.tab" using 1:2 title "Network cascade Average" with linespoints lw 2
