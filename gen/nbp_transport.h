/* Generated by nbec  on Sat May 27 04:19:06 2017
 */
#ifndef __nbp_transport_h
#define __nbp_transport_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *transport_state_new(nbp_pd_extract_context *extctx);
void transport_state_free(void *state);
nbe_pu_gb *transport_get_userdata(void *pState);
int transport_get_param(void *pState, int index,  void *param, int len);
int transport_set_param(void *pState, int index,  void *param, int len);
int transport_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif