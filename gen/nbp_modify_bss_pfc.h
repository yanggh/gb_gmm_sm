/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_modify_bss_pfc_h
#define __nbp_modify_bss_pfc_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *modify_bss_pfc_state_new(nbp_pd_extract_context *extctx);
void modify_bss_pfc_state_free(void *state);
nbe_pu_gb *modify_bss_pfc_get_userdata(void *pState);
int modify_bss_pfc_get_param(void *pState, int index,  void *param, int len);
int modify_bss_pfc_set_param(void *pState, int index,  void *param, int len);
int modify_bss_pfc_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif