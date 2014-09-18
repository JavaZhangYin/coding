#
# Random graph on 1000 nodes. G(100, 1000) (Thu Mar 20 17:42:12 2014)
#

set title "Random graph on 1000 nodes. G(100, 1000)"
set key bottom right
set logscale xy 10
set format x "10^{%L}"
set mxtics 10
set format y "10^{%L}"
set mytics 10
set grid
set xlabel "WCC size"
set ylabel "Count"
set tics scale 2
set terminal png size 1000,800
set output 'wcc.RndGraph.png'
plot 	"wcc.RndGraph.tab" using 1:2 title "" with linespoints pt 6
