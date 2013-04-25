#include "def.h"

#define PREFIX "\t"

extern long sum;
extern FILE* fp;

void DependOn(int* ar, int place, int_fast8_t* dned)
{
	int i, j;
	int cnt=0;
	int cabricnt=0;

	for(i=0; i<Ceilings; i++)
		dned[i]=0;

	for(i=0; i<X; i++)
		dned[ar[i+place*X]]=1;

	for(i=place+1; i<ple; i++){
		for(j=0; j<X; j++)
			if(dned[ar[j+i*X]])
				cabricnt++;
		//fputs(PREFIX, fp);
		if(cabricnt==X%2){
			cnt++;
			for(j=0; j<X; j++)
				fprintf(fp, "%3d", ar[j+i*X]);
			fputc('\n', fp);
		}
		cabricnt=0;
	}

	//printf(PREFIX "%d\n", cnt);
	sum+=cnt;
	return;
}
