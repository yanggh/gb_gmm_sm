/* Generated by nbec  on Sat May 27 04:19:06 2017
 */
#ifndef __nbp_request_secondary_pdp_context_activation_h
#define __nbp_request_secondary_pdp_context_activation_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *request_secondary_pdp_context_activation_state_new(nbp_pd_extract_context *extctx);
void request_secondary_pdp_context_activation_state_free(void *state);
nbe_pu_gb *request_secondary_pdp_context_activation_get_userdata(void *pState);
int request_secondary_pdp_context_activation_get_param(void *pState, int index,  void *param, int len);
int request_secondary_pdp_context_activation_set_param(void *pState, int index,  void *param, int len);
int request_secondary_pdp_context_activation_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif