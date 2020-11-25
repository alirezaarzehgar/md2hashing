#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/structures.h"
#include "src/calc_md2.h"
#include "src/chartohex.h"


int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("ERROR: Not enough parameters \nUSAGE: %s <file_name>\n", argv[0]);
		exit(0);
	}
	
	char *text = argv[1];
	char buffer[16];
	int offset = 0;
	int c; //for getc()
	int i = 0;
	int counter = 0;
	MD2 *ctx = malloc(sizeof(MD2));
	
	memset(ctx->data,0,15);

	for(i = 0; i < 48; i++)
		ctx->state[i] = 0;

	for(i = 0; i < 16; i++)
		ctx->checksum[i] = 0;
	
	strcpy(ctx->data, text);
	calc_md2(ctx);

	offset = 16 - counter;

	//pad the data
	while(counter < 16)
		ctx->data[counter++] = *((char*)&offset);

	//recalculate md2 with padding
	calc_md2(ctx);
  
	//append checksum
	memcpy(ctx->data, ctx->checksum, 16);

	//recalculate md2 with checksum appended
	calc_md2(ctx);

	//print final result
	ctoh(ctx->state, "result");

	printf("\n");

	free(ctx);
}

