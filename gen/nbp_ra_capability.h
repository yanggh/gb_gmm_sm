/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_ra_capability_h
#define __nbp_ra_capability_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *ra_capability_state_new(nbp_pd_extract_context *extctx);
void ra_capability_state_free(void *state);
nbe_pu_gb *ra_capability_get_userdata(void *pState);
int ra_capability_get_param(void *pState, int index,  void *param, int len);
int ra_capability_set_param(void *pState, int index,  void *param, int len);
int ra_capability_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif