/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_authentication_and_ciphering_failure_h
#define __nbp_authentication_and_ciphering_failure_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *authentication_and_ciphering_failure_state_new(nbp_pd_extract_context *extctx);
void authentication_and_ciphering_failure_state_free(void *state);
nbe_pu_gb *authentication_and_ciphering_failure_get_userdata(void *pState);
int authentication_and_ciphering_failure_get_param(void *pState, int index,  void *param, int len);
int authentication_and_ciphering_failure_set_param(void *pState, int index,  void *param, int len);
int authentication_and_ciphering_failure_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif