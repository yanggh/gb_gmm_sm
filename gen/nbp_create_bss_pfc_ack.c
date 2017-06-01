/* Generated by nbec  on Sat May 27 04:19:05 2017
 */
#include <stdlib.h>
#include "nbp_rt.h"
#include "nbe_pu_gb.h"

#include "nbe_pu_gb.h"
#include "nbe_pu_gbe.h"
#include "nbe_pu_gbe.h"
#include "nbe_pu_gbf.h"
#include "nbe_pu_gbf.h"
#include "nbp_create_bss_pfc_ack.h"

#define NPCTX      struct create_bss_pfc_ack_ctx*
#define YYCTYPE     uint8_t
#define YYCURSOR    (cursor)
#define YYLIMIT     (limit)
#define YYMARKER    (marker)
#define CTXMARKER  (ctxmarker)
#define YYSTART     (input)
#define YYDEBUG(s,c) { if (s == -1) { printf("%c", c); } }
#define NBPCALL(n)       goto n
#define NBPRET(n)       goto n
#define SET_NOMATCH()  (match = -1)
#define SET_MATCH(n)  (match = (n))
#define NOMATCH()      (match == -1)
#define IS_MATCH()      (match != -1)
#define MATCH      (match)
#define MYVAR(v)   (pctx->v)
#define SAVEPOS(p) (MYVAR(p) = YYCURSOR - YYSTART)
#define RESTOREPOS(p) (YYCURSOR = YYSTART + MYVAR(p), MYVAR(p) = -1)
struct create_bss_pfc_ack_ctx {
    scan_state __ss;
    nbe_pu_gb *gb;
    nbe_list *ls_elements;
    nbe_pu_gbe *gbe;
    nbe_list *ls_fields;
    nbe_pu_gbf *gbf;
    int data_len;
    int dir;
    int $ipt[1];
    int app;
    int module;
    int __g;
    int gtype;
    decompressor_gzip_t*__gdecom;
};
static int do_scan(void *pState, uint8_t *input, uint32_t len, int flag, uint32_t *plen, void *userdata);
static int do_scan(void *pState, uint8_t *input, uint32_t len, int flag, uint32_t *plen, void *userdata) {
    register uint16_t yych = 0x100;
    yych = yych + 0;
    uint8_t *cursor = input;
    uint8_t *limit = input + len;
    uint8_t *marker = input;
    uint8_t *ctxmarker = input;
    int match = -1;
    int eof = flag;
    eof = eof + 0;
    int bit_remain = 8;
    int last_left = 0;
    NPCTX pctx = (NPCTX) pState;
    if (pctx->__ss.c) NBERESUME();
    if (pctx->$ipt[0] > 0) pctx->$ipt[1] = -1;
    goto APP_ca;
APP_ca:
{{ 
      #include "nbe_common.h"
      #include "dict.h"
      #include "gb_l3_common.h"
      #include "stdio.h"

      BEGIN_SIGNAL("2", "BSSGP Layer", "CREATE-BSS-PFC-ACK");

      uint8_t h = 0;
      int len = 10;
      int abqp_len = 0;

      bssgp_pdu_type();
      bssgp_tlli(1, 1);

      packet_flow_identifier(1, 1);
      abqp_len = abqp(1, 1, MYVAR(dir));
      len += abqp_len;

      if (MYVAR(data_len) - len > 0)
      {
		  uint32_t pos = 0;
          POS(pos);
          SET_V(gb, next_pos, pos);
          SET_V(gb, next_len, MYVAR(data_len) - len);
      }

      END_SIGNAL();
   };SET_MATCH(0);}return match;
}
#ifdef __cpluscplus
extern "C" {
#endif
void *create_bss_pfc_ack_state_new(nbp_pd_extract_context *extctx){
    NPCTX pState = (NPCTX) malloc(sizeof(struct create_bss_pfc_ack_ctx));
    if (!pState) {
      printf("out of memory");
      return NULL;
    }
    memset(pState, 0, sizeof(*pState));
    if(extctx) {
        pState->app = extctx->app;
        pState->module = extctx->module;
    }
    pState->gb = nbe_gb_new();
    pState->$ipt[0] = 0;
    if(pState->$ipt[0] > 0) pState->$ipt[1] = -1;
    pState->ls_elements = nbe_list_new(NBE_STRUCT, NBE_ID_gbe, sizeof(nbe_pu_gbe), 4096);
    pState->gbe = nbe_gbe_new();
    pState->ls_fields = nbe_list_new(NBE_STRUCT, NBE_ID_gbf, sizeof(nbe_pu_gbf), 4096);
    pState->gbf = nbe_gbf_new();
    return pState;//TODO:NULL LOG
}
void create_bss_pfc_ack_state_free(void *state) {
    NPCTX pState = (NPCTX) state;
    if (pState->__ss.bf != NULL) free(pState->__ss.bf);
    if(pState->ls_elements && !pState->ls_elements->uhd.m) {nbe_list_free(pState->ls_elements);}
    if(pState->gbe && !pState->gbe->uhd.m) {nbe_gbe_free(pState->gbe);}
    if(pState->ls_fields && !pState->ls_fields->uhd.m) {nbe_list_free(pState->ls_fields);}
    if(pState->gbf && !pState->gbf->uhd.m) {nbe_gbf_free(pState->gbf);}
    nbe_gb_free(pState->gb);
    if (pState->__gdecom) pState->__gdecom->super.destroy(pState->__gdecom);
    free(pState);
}
nbe_pu_gb *create_bss_pfc_ack_get_userdata(void *pState) {
    return ((NPCTX)pState)->gb;
}
int create_bss_pfc_ack_get_param(void *pState, int index, void *param, int len) {
    NPCTX pctx = (NPCTX) pState;
    switch (index) {
        case 1:
           memcpy(param, &pctx->data_len, len);
           break;
        case 2:
           memcpy(param, &pctx->dir, len);
           break;
        default:
            return -1;
    }
    return 0;
}
int create_bss_pfc_ack_set_param(void *pState, int index, void *param, int len) {
    NPCTX pctx = (NPCTX) pState;
    switch (index) {
        case 1:
           memcpy(&pctx->data_len, param, len);
           break;
        case 2:
           memcpy(&pctx->dir, param, len);
           break;
        default:
            return -1;
    }
    return 0;
}
int create_bss_pfc_ack_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx) {
    NPCTX pctx = (NPCTX) pState;
    uint32_t plen = 0;
    int match = -1;
    if (pctx->__g == 0) {
       match = do_scan(pState, input, input_len, flag, &plen, ctx);
       if (pctx->__g == 1) {
         goto decom;
       }
       return match;
    }
decom:
    if (pctx->__gdecom == NULL) {
       pctx->__gdecom =(decompressor_gzip_t*) gzip_decompressor_create(pctx->gtype);
       pctx->__gdecom->super.callback = do_scan;
    }
    pctx->__gdecom->ueof = flag;
    pctx->__gdecom->ustate = pctx;
    return pctx->__gdecom->super.decompress(pctx->__gdecom, input + plen, (uint32_t)(input_len - plen));
}
#ifdef __cpluscplus
}
#endif
