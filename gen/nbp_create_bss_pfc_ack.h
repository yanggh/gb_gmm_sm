/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbp_create_bss_pfc_ack_h
#define __nbp_create_bss_pfc_ack_h
#include "nbp_rt.h"
#include "nbe_pu_gb.h"
void *create_bss_pfc_ack_state_new(nbp_pd_extract_context *extctx);
void create_bss_pfc_ack_state_free(void *state);
nbe_pu_gb *create_bss_pfc_ack_get_userdata(void *pState);
int create_bss_pfc_ack_get_param(void *pState, int index,  void *param, int len);
int create_bss_pfc_ack_set_param(void *pState, int index,  void *param, int len);
int create_bss_pfc_ack_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx);
#endif