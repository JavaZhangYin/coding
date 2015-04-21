#include <stdio.h>
#include "byutr.h"

p2AddrTr tr;

int main(int argc, char **argv)
{
	FILE *ifp;
	unsigned long i;

	if(argc != 2)
	{
		fprintf(stderr,"usage: b2a input_byutr_file\n");
		exit(1);
	}
	
	if((ifp = fopen(argv[1],"rb")) == NULL)
	{
		fprintf(stderr,"cannot open %s for reading\n",argv[1]);
		exit(1);
	}
	
	
	fread(&tr, sizeof(p2AddrTr), 1, ifp);
	i = 1;
	while(!feof(ifp))
	{
		printf("%08lx ", tr.addr);
		switch(tr.reqtype)
		{
		case 0x00:
			printf("FETCH\t\t");
			break;
		case 0x01:
			printf("MEMREAD\t");
			break;
		case 0x02:
			printf("MEMREADINV\t");
			break;
		case 0x03:
			printf("MEMWRITE\t");
			break;
		case 0x10:
			printf("IOREAD\t\t");
			break;
		case 0x11:
			printf("IOWRITE\t");
			break;
		case 0x20:
			printf("DEFERREPLY\t");
			break;
		case 0x21:
			printf("INTA\t\t");
			break;
		case 0x22:
			printf("CNTRLAGNTRES\t");
			break;
		case 0x23:
			printf("BRTRACEREC\t");
			break;
		case 0x31:
			printf("SHUTDOWN\t");
			break;
		case 0x32:
			printf("FLUSH\t\t");
			break;
		case 0x33:
			printf("HALT\t\t");
			break;
		case 0x34:
			printf("SYNC\t\t");
			break;
		case 0x35:
			printf("FLUSHACK\t");
			break;
		case 0x36:
			printf("STOPCLKAK\t");
			break;
		case 0x37:
			printf("SMIACK\t\t");
			break;
		}
		printf("%2d\t%02x\t%1d\t%ld\n", tr.size, tr.attr, tr.proc, tr.time);

		fread(&tr, sizeof(p2AddrTr), 1, ifp);
		i++;
		if((i % 100000) == 0)
			fprintf(stderr,"%d samples processed\r", i);
	}
	
	fclose(ifp);

	return( 0 );
}

