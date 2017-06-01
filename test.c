#include <stdio.h>
#include "test.h"

void* ptr_v = NULL;
nbe_pu_gb  *ptr = NULL;

void* NEW()
{
    ptr_v = sndcp_state_new(NULL);
    return ptr_v;
}

void FREE(void* state)
{
    sndcp_state_free(state);
}

nbe_pu_gb *GET(void* pState) 
{
    ptr = sndcp_get_userdata(pState);
    return  ptr;
}

int PARSE(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx)
{
    int ret = sndcp_parse(pState, input, input_len, flag, ctx);
    return ret;
}

