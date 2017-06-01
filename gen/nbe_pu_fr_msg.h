/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbe_pu_fr_msg_h
#define __nbe_pu_fr_msg_h
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "nbe_rt.h"
#include "nbe_pu_gbe.h"
#define NBE_ID_fr_msg 1005
struct nbe_pu_fr_msg_ {
   nbe_pu uhd;
   nbe_ptr layer;
   nbe_ptr frame_type;
   nbe_ptr signal_type;
   nbe_ptr raw;
   uint32_t raw_len;
   uint32_t next_pos;
   uint32_t next_len;
   nbe_ptr elements;
};
typedef struct nbe_pu_fr_msg_ nbe_pu_fr_msg;

nbe_pu_fr_msg *nbe_fr_msg_new(void);
void nbe_fr_msg_free(nbe_pu_fr_msg *pu);
#define nbe_fr_msg_size(p) ((p)->uhd.tail) 
nbe_string nbe_fr_msg_get_layer(nbe_pu_fr_msg *pu);
void nbe_fr_msg_set_layer_post(void *v, nbe_ptr p, int delta);
#define nbe_fr_msg_set_layer(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->layer); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, d, nbe_fr_msg_set_layer_post, &o); \
   } while(0); 

nbe_string nbe_fr_msg_get_frame_type(nbe_pu_fr_msg *pu);
void nbe_fr_msg_set_frame_type_post(void *v, nbe_ptr p, int delta);
#define nbe_fr_msg_set_frame_type(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->frame_type); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, d, nbe_fr_msg_set_frame_type_post, &o); \
   } while(0); 

nbe_string nbe_fr_msg_get_signal_type(nbe_pu_fr_msg *pu);
void nbe_fr_msg_set_signal_type_post(void *v, nbe_ptr p, int delta);
#define nbe_fr_msg_set_signal_type(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->signal_type); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, d, nbe_fr_msg_set_signal_type_post, &o); \
   } while(0); 

nbe_string nbe_fr_msg_get_raw(nbe_pu_fr_msg *pu);
void nbe_fr_msg_set_raw_post(void *v, nbe_ptr p, int delta);
#define nbe_fr_msg_set_raw(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->raw); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, d, nbe_fr_msg_set_raw_post, &o); \
   } while(0); 

#define nbe_fr_msg_get_raw_len(pu) ((pu)->raw_len)
#define nbe_fr_msg_set_raw_len(pu, d) ((pu)->raw_len = (d))

#define nbe_fr_msg_get_next_pos(pu) ((pu)->next_pos)
#define nbe_fr_msg_set_next_pos(pu, d) ((pu)->next_pos = (d))

#define nbe_fr_msg_get_next_len(pu) ((pu)->next_len)
#define nbe_fr_msg_set_next_len(pu, d) ((pu)->next_len = (d))

nbe_list *nbe_fr_msg_get_elements(nbe_pu_fr_msg *pu);
void nbe_fr_msg_set_elements_post(void *v, nbe_ptr p, int delta);
#define nbe_fr_msg_set_elements(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->elements); \
      nbe_string nbe_str;  \
      nbe_str.str = (uint8_t*) (d); \
      nbe_str.len = nbe_list_size(d); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, nbe_str, nbe_fr_msg_set_elements_post, &o); \
   } while(0); 


#endif