/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_gb_head_h
#define __nbp_gb_head_h
#include "nbp_rt.h"
#include "nbe_pu_gb_public.h"
void *gb_head_state_new(nbp_pd_extract_context *extctx);
void gb_head_state_free(void *state);
nbe_pu_gb_public *gb_head_get_userdata(void *pState);
int gb_head_get_param(void *pState, int index,  void *param, int len);
int gb_head_set_param(void *pState, int index,  void *param, int len);
int gb_head_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif