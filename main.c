#include "def.h"
#include <unistd.h>
#include <errno.h>
#define RES "Result: "

int X, Ceilings, OneLine;
long ple;
long sum;
FILE* fp;

int main(int argc, char* argv[])
{
	int i, j;
	char* buf;
	char s[10];
	int* ar;
	int_fast8_t* dned;
	FILE* ifp;

	if(argc!=2){
		fputs("Invalid the number of the argument.\n", stderr);
		exit(EXIT_FAILURE);
	}
	fp=fopen(argv[1], "r");
	assert(fp);
	buf=(char*)malloc(sizeof(char)*32);
	do{
		fgets(buf, 32, fp);
	}while(strncmp(buf, RES, sizeof(RES)-1));
	buf+=sizeof(RES)-1;
	ple=atol(buf);
	printf("ple: %ld\n", ple);

	rewind(fp);
	fgets(buf, 32, fp);
	X=findx(buf);
	printf("X: %d\n", X);
	ar=(int*)malloc(sizeof(int)*ple*X);

	rewind(fp);

	system("rm -rf out; mkdir out");
	chdir("out");
	if(errno)
		perror("chdir: out");

	ifp=fopen("index", "w");
	if(errno)
		perror("fopen: index");

	for(i=0; i<ple; i++){
		separ(ar+i*X, fgets(buf, 32, fp));
		for(j=0; j<X; j++)
			fprintf(ifp, "%3d", ar[j+i*X]);
		putc('\n', ifp);
	}
	fclose(fp);

	dned=(int_fast8_t*)malloc(sizeof(int_fast8_t)*Ceilings);
	sum=0;

	puts("------------");

	for(i=0; i<ple; i++){
		sprintf(s, "%d", i);
		fp=fopen(s, "w");
		DependOn(ar, i, dned);
		fclose(fp);
	}
	printf("sum: %ld\n", sum);

	return 0;
}
