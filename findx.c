#include "def.h"

int findx(char* str)
{
	int numcont=0;
	_Bool priortype=0;	//0 is char, 1 is num

	do{
		if(isdigit((int)*str)){
			if(!priortype)
				numcont++;
			priortype=1;
		}else
			priortype=0;
	}while(*++str);
	return numcont;
}
