#
# demo N=98  E=200  Beta=0.1 (Thu Mar 20 14:49:30 2014)
#

set title "demo N=98  E=200  Beta=0.1"
set key bottom right
set autoscale
set grid
set xlabel "Fraction of observed data (P)"
set ylabel "Average Out-Degree (of a non-leaf)"
set tics scale 2
set terminal png size 1000,800
set output 'outDeg-demo-B010.png'
plot 	"outDeg-demo-B010.tab" using 1:3 title "Influence cascade Average" with linespoints lw 2,\
	"outDeg-demo-B010.tab" using 1:2 title "Network cascade Average" with linespoints lw 2
