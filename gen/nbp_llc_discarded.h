/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_llc_discarded_h
#define __nbp_llc_discarded_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *llc_discarded_state_new(nbp_pd_extract_context *extctx);
void llc_discarded_state_free(void *state);
nbe_pu_gb *llc_discarded_get_userdata(void *pState);
int llc_discarded_get_param(void *pState, int index,  void *param, int len);
int llc_discarded_set_param(void *pState, int index,  void *param, int len);
int llc_discarded_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif