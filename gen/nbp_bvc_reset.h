/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_bvc_reset_h
#define __nbp_bvc_reset_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *bvc_reset_state_new(nbp_pd_extract_context *extctx);
void bvc_reset_state_free(void *state);
nbe_pu_gb *bvc_reset_get_userdata(void *pState);
int bvc_reset_get_param(void *pState, int index,  void *param, int len);
int bvc_reset_set_param(void *pState, int index,  void *param, int len);
int bvc_reset_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif