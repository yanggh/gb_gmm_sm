/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_ns_alive_h
#define __nbp_ns_alive_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *ns_alive_state_new(nbp_pd_extract_context *extctx);
void ns_alive_state_free(void *state);
nbe_pu_gb *ns_alive_get_userdata(void *pState);
int ns_alive_get_param(void *pState, int index,  void *param, int len);
int ns_alive_set_param(void *pState, int index,  void *param, int len);
int ns_alive_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif