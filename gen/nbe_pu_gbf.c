/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#include <stdlib.h>

#include "nbe_pu_gbf.h"

nbe_pu_gbf *nbe_gbf_new(void) {
    uint32_t extra = 4096;
    uint32_t fixed_size = sizeof(nbe_pu_gbf);
    nbe_pu_gbf *pu = (nbe_pu_gbf*) malloc(fixed_size +extra);
    check_pu_new(pu);
    memset(pu, 0, fixed_size + extra);
    pu->uhd.uid = 1002;
    pu->uhd.type = NBE_STRUCT;
    pu->uhd.packed = 0;
    uint32_t t = 1;
    pu->uhd.endian = ( *((uint8_t*) &t) != 1);
    pu->uhd.tail = fixed_size;
    pu->uhd.avail = extra;
    return pu;
}

void  nbe_gbf_free(nbe_pu_gbf *pu) {
    free(pu);
}
nbe_string nbe_gbf_get_f_name(nbe_pu_gbf *pu) {
   nbe_string nstring; 
   nbe_ptr ptr = pu->f_name;
   nstring.str = ptr.offset == 0 ? 0 : ((uint8_t*)pu) + ptr.offset;
   nstring.len = ptr.len;
   return nstring;
}

void nbe_gbf_set_f_name_post(void *v, nbe_ptr p, int delta) {
   nbe_pu_gbf *pu = (nbe_pu_gbf*) v;
    if (pu->f_id.offset > p.offset)
       pu->f_id.offset += delta;
    if (pu->f_bin.offset > p.offset)
       pu->f_bin.offset += delta;
    if (pu->f_hex.offset > p.offset)
       pu->f_hex.offset += delta;
    if (pu->f_desc.offset > p.offset)
       pu->f_desc.offset += delta;
}

nbe_string nbe_gbf_get_f_id(nbe_pu_gbf *pu) {
   nbe_string nstring; 
   nbe_ptr ptr = pu->f_id;
   nstring.str = ptr.offset == 0 ? 0 : ((uint8_t*)pu) + ptr.offset;
   nstring.len = ptr.len;
   return nstring;
}

void nbe_gbf_set_f_id_post(void *v, nbe_ptr p, int delta) {
   nbe_pu_gbf *pu = (nbe_pu_gbf*) v;
    if (pu->f_name.offset > p.offset)
       pu->f_name.offset += delta;
    if (pu->f_bin.offset > p.offset)
       pu->f_bin.offset += delta;
    if (pu->f_hex.offset > p.offset)
       pu->f_hex.offset += delta;
    if (pu->f_desc.offset > p.offset)
       pu->f_desc.offset += delta;
}

nbe_string nbe_gbf_get_f_bin(nbe_pu_gbf *pu) {
   nbe_string nstring; 
   nbe_ptr ptr = pu->f_bin;
   nstring.str = ptr.offset == 0 ? 0 : ((uint8_t*)pu) + ptr.offset;
   nstring.len = ptr.len;
   return nstring;
}

void nbe_gbf_set_f_bin_post(void *v, nbe_ptr p, int delta) {
   nbe_pu_gbf *pu = (nbe_pu_gbf*) v;
    if (pu->f_name.offset > p.offset)
       pu->f_name.offset += delta;
    if (pu->f_id.offset > p.offset)
       pu->f_id.offset += delta;
    if (pu->f_hex.offset > p.offset)
       pu->f_hex.offset += delta;
    if (pu->f_desc.offset > p.offset)
       pu->f_desc.offset += delta;
}

nbe_string nbe_gbf_get_f_hex(nbe_pu_gbf *pu) {
   nbe_string nstring; 
   nbe_ptr ptr = pu->f_hex;
   nstring.str = ptr.offset == 0 ? 0 : ((uint8_t*)pu) + ptr.offset;
   nstring.len = ptr.len;
   return nstring;
}

void nbe_gbf_set_f_hex_post(void *v, nbe_ptr p, int delta) {
   nbe_pu_gbf *pu = (nbe_pu_gbf*) v;
    if (pu->f_name.offset > p.offset)
       pu->f_name.offset += delta;
    if (pu->f_id.offset > p.offset)
       pu->f_id.offset += delta;
    if (pu->f_bin.offset > p.offset)
       pu->f_bin.offset += delta;
    if (pu->f_desc.offset > p.offset)
       pu->f_desc.offset += delta;
}

nbe_string nbe_gbf_get_f_desc(nbe_pu_gbf *pu) {
   nbe_string nstring; 
   nbe_ptr ptr = pu->f_desc;
   nstring.str = ptr.offset == 0 ? 0 : ((uint8_t*)pu) + ptr.offset;
   nstring.len = ptr.len;
   return nstring;
}

void nbe_gbf_set_f_desc_post(void *v, nbe_ptr p, int delta) {
   nbe_pu_gbf *pu = (nbe_pu_gbf*) v;
    if (pu->f_name.offset > p.offset)
       pu->f_name.offset += delta;
    if (pu->f_id.offset > p.offset)
       pu->f_id.offset += delta;
    if (pu->f_bin.offset > p.offset)
       pu->f_bin.offset += delta;
    if (pu->f_hex.offset > p.offset)
       pu->f_hex.offset += delta;
}

static nbe_def _pu_def_ = {
                       1002,
                       0,
                       1,
                       0,
                      "gbf",
                       6,
                       {
                          {12, "f_name", 0}
                         ,{12, "f_id", 0}
                         ,{8, "f", 0}
                         ,{12, "f_bin", 0}
                         ,{12, "f_hex", 0}
                         ,{12, "f_desc", 0}
                       }
};

nbe_def *nbe_get_pu_def_1002(uint32_t uid);
nbe_def *nbe_get_pu_def_1002(uint32_t uid) {
    nbe_pu_gbf pu;
    uint8_t *p = (uint8_t*) &pu;
    _pu_def_.flds[0].offset = (uint8_t*)&pu.f_name - p;
    _pu_def_.flds[1].offset = (uint8_t*)&pu.f_id - p;
    _pu_def_.flds[2].offset = (uint8_t*)&pu.f - p;
    _pu_def_.flds[3].offset = (uint8_t*)&pu.f_bin - p;
    _pu_def_.flds[4].offset = (uint8_t*)&pu.f_hex - p;
    _pu_def_.flds[5].offset = (uint8_t*)&pu.f_desc - p;
    return &_pu_def_;
}

