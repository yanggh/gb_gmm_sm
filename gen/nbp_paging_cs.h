/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_paging_cs_h
#define __nbp_paging_cs_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *paging_cs_state_new(nbp_pd_extract_context *extctx);
void paging_cs_state_free(void *state);
nbe_pu_gb *paging_cs_get_userdata(void *pState);
int paging_cs_get_param(void *pState, int index,  void *param, int len);
int paging_cs_set_param(void *pState, int index,  void *param, int len);
int paging_cs_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif