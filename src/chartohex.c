#include <stdio.h>
#include "chartohex.h"


void ctoh(char data[], char *string)
{
	printf("%s = ", string);
	char temp_data;
	int count = 0;

	for(count = 0; count < 16; count++)
	{
		temp_data = data[count];
		printf("%x", temp_data & 0xff);
	}
	
	printf("\n");
}
