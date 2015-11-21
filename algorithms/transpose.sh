#!/usr/bin/awk -f
# Transpose a matrix.

BEGIN {
    FS=",";
}
{
     for (i=1; i<=NF; i++) {
	a[NR, i] = $i;
    }
}

END {
    for (j = 1; j <= NF; j++) {
	for (i = 1; i <= NR; i++) {
	    printf("%s", a[i, j]);
	    if (i < NR) {
		printf(",");
	    }
	}
	if (j < NF) {
	    printf("\n");
	}
	
    }
}
