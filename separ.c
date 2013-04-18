#include "def.h"

void separ(int* c, char* str)
{
#if 0
	int cont=0;
	char* t;
	_Bool priortype=0;	//0 is char, 1 is num

	puts(str);
	do{
		putchar(*str);
		putchar('\n');
		if(isdigit((int)*str)){
			priortype=1;
		}else{
			if(priortype){
				//*str='\0';	//NOTICE: destroying
				printf("t: %s", t);
				c[cont]=atoi(t);
				cont++;
				t=str+1;
			}
			priortype=0;
		}
	}while(*++str);
#else
	int i;
	for(i=0; i<X; i++)
		c[i]=(int)strtol(str, &str, 10);
#endif
	return;
}
