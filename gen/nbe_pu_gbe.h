/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#ifndef __nbe_pu_gbe_h
#define __nbe_pu_gbe_h
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "nbe_rt.h"
#include "nbe_pu_gbf.h"
#define NBE_ID_gbe 1001
struct nbe_pu_gbe_ {
   nbe_pu uhd;
   nbe_ptr element_name;
   nbe_ptr element_desc;
   nbe_ptr fields;
};
typedef struct nbe_pu_gbe_ nbe_pu_gbe;

nbe_pu_gbe *nbe_gbe_new(void);
void nbe_gbe_free(nbe_pu_gbe *pu);
#define nbe_gbe_size(p) ((p)->uhd.tail) 
nbe_string nbe_gbe_get_element_name(nbe_pu_gbe *pu);
void nbe_gbe_set_element_name_post(void *v, nbe_ptr p, int delta);
#define nbe_gbe_set_element_name(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->element_name); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, d, nbe_gbe_set_element_name_post, &o); \
   } while(0); 

nbe_string nbe_gbe_get_element_desc(nbe_pu_gbe *pu);
void nbe_gbe_set_element_desc_post(void *v, nbe_ptr p, int delta);
#define nbe_gbe_set_element_desc(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->element_desc); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, d, nbe_gbe_set_element_desc_post, &o); \
   } while(0); 

nbe_list *nbe_gbe_get_fields(nbe_pu_gbe *pu);
void nbe_gbe_set_fields_post(void *v, nbe_ptr p, int delta);
#define nbe_gbe_set_fields(pu, d) \
   do { \
      int o; \
      nbe_ptr *ptr = &((*pu)->fields); \
      nbe_string nbe_str;  \
      nbe_str.str = (uint8_t*) (d); \
      nbe_str.len = nbe_list_size(d); \
      nbe_pu_set_ptr_data((nbe_pu**)pu, ptr, nbe_str, nbe_gbe_set_fields_post, &o); \
   } while(0); 


#endif