/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_suspend_ack_h
#define __nbp_suspend_ack_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *suspend_ack_state_new(nbp_pd_extract_context *extctx);
void suspend_ack_state_free(void *state);
nbe_pu_gb *suspend_ack_get_userdata(void *pState);
int suspend_ack_get_param(void *pState, int index,  void *param, int len);
int suspend_ack_set_param(void *pState, int index,  void *param, int len);
int suspend_ack_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif