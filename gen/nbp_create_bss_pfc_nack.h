/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_create_bss_pfc_nack_h
#define __nbp_create_bss_pfc_nack_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *create_bss_pfc_nack_state_new(nbp_pd_extract_context *extctx);
void create_bss_pfc_nack_state_free(void *state);
nbe_pu_gb *create_bss_pfc_nack_get_userdata(void *pState);
int create_bss_pfc_nack_get_param(void *pState, int index,  void *param, int len);
int create_bss_pfc_nack_set_param(void *pState, int index,  void *param, int len);
int create_bss_pfc_nack_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif