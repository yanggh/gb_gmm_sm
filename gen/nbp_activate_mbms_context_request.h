/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_activate_mbms_context_request_h
#define __nbp_activate_mbms_context_request_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *activate_mbms_context_request_state_new(nbp_pd_extract_context *extctx);
void activate_mbms_context_request_state_free(void *state);
nbe_pu_gb *activate_mbms_context_request_get_userdata(void *pState);
int activate_mbms_context_request_get_param(void *pState, int index,  void *param, int len);
int activate_mbms_context_request_set_param(void *pState, int index,  void *param, int len);
int activate_mbms_context_request_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif