#include "def.h"
#define RES "Result: "

int X, Ceilings, OneLine;
long ple;
long sum;

int main(int argc, char* argv[])
{
	int i, j;
	char* buf;
	int* ar;
	FILE* fp;
	int_fast8_t* dned;

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
	for(i=0; i<ple; i++){
		separ(ar+i*X, fgets(buf, 32, fp));
		for(j=0; j<X; j++)
			printf("%3d", ar[j+i*X]);
		putchar('\n');
	}

	dned=(int_fast8_t*)malloc(sizeof(int_fast8_t)*Ceilings);
	sum=0;

	puts("------------");

	for(i=0; i<ple; i++){
		/*for(j=0; j<X; j++)
			printf("%3d", ar[j+i*X]);
		putchar('\n');*/
		DependOn(ar, i, dned);
	}
	printf("sum: %ld\n", sum);

	return 0;
}