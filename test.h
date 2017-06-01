#ifndef  __TEST_
#define  __TEST_
#include "nbp_rt.h"
#include "gen/nbe_pu_gb.h"

void* NEW();
void FREE(void* state);
nbe_pu_gb *GET(void* pState);
int PARSE(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif
