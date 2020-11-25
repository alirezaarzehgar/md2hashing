#include "structures.h"

/*
 *	calculate md2 hash
 */

void calc_md2(MD2 *ctx){
  int count = 0;
  int temp = 0;
  int k = 0;

  for(count = 0; count < 16; count++){
    ctx->state[count+16] = ctx->data[count];
    ctx->state[count+32] = (ctx->state[count+16])^(ctx->state[count]);
  }
  
  temp = 0;
  for(count = 0 ; count < 18; count++){
    for(k = 0; k<48; k++){
      ctx->state[k] ^= PI_SUBST[temp];
      temp = ctx->state[k];
    }
    temp = (temp+count) % 256;
  }
  
  //compute the checksum
  temp = ctx->checksum[15];
  for(count = 0 ; count < 16 ;count++){
    ctx->checksum[count] = PI_SUBST[ctx->data[count]^temp];
    temp = ctx->checksum[count];
  }
}
