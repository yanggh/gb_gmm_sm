/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_fr_layer_h
#define __nbp_fr_layer_h
#include "nbp_rt.h"
#include "nbe_pu_fr_msg.h"
void *fr_layer_state_new(nbp_pd_extract_context *extctx);
void fr_layer_state_free(void *state);
nbe_pu_fr_msg *fr_layer_get_userdata(void *pState);
int fr_layer_get_param(void *pState, int index,  void *param, int len);
int fr_layer_set_param(void *pState, int index,  void *param, int len);
int fr_layer_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif