/* Generated by nbec  on Sat May 27 04:19:06 2017
 */
#ifndef __nbp_ip_h
#define __nbp_ip_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *ip_state_new(nbp_pd_extract_context *extctx);
void ip_state_free(void *state);
nbe_pu_gb *ip_get_userdata(void *pState);
int ip_get_param(void *pState, int index,  void *param, int len);
int ip_set_param(void *pState, int index,  void *param, int len);
int ip_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif