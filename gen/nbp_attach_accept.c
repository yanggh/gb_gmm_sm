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
#include "nbp_attach_accept.h"

#define NPCTX      struct attach_accept_ctx*
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
struct attach_accept_ctx {
    scan_state __ss;
    nbe_pu_gb *gb;
    nbe_list *ls_elements;
    nbe_pu_gbe *gbe;
    nbe_list *ls_fields;
    nbe_pu_gbf *gbf;
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
    #include "gb_gmm_sm.h"

    uint8_t iei = 0;
    uint8_t location = 0;
    uint8_t h = 0;

    BEGIN_SIGNAL("4", "GMM", "ATTACH ACCEPT");
    si_pd();
    msg_type(MESSAGE_TYPE_GMM);

    force_to_standby(iei, location);
    location = 1;
    attach_result(iei, location);

    location = 0;
    gprs_timer(iei, location);

    radio_priority_2(iei, location);
    location = 1;
    radio_priority(iei, location);
    location = 0;
    routeing_area(iei, location);
    //routing_area_identification(iei, location);

    B8_BIT(h, 1, 8);
    if(h == 0x19)
    {
        iei = 1;
        p_tmsi_signature(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x17)
    {
        iei = 1;
        gprs_timer(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x18)
    {
        iei = 1;
        location = 1;
        mobile_identity(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x23)
    {
        iei = 1;
        location = 1;
        mobile_identity(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x25)
    {
        iei = 1;
        gmm_cause(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x2a)
    {
        iei = 1;
        location = 1;
        gprs_timer_2(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x8c)
    {
        iei = 1;
        cell_notification(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x4a)
    {
        iei = 1;
        location = 1;
        plmn_list(iei, location);
    }

    B8_BIT(h, 1, 8);
    if((h & 0xf0) == 0xb0)
    {
        iei = 1;
        network_feature_support(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x34)
    {
        iei = 1;
        location = 1;
        emergency_number_list(iei, location);
    }

    B8_BIT(h, 1, 8);
    if((h & 0xf0) == 0xa0)
    {
        iei = 1;
        requested_ms_information(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x37)
    {
        iei = 1;
        location = 1;
        gprs_timer_2(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x38)
    {
        iei = 1;
        location = 1;
        gprs_timer_2(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x39)
    {
        iei = 1;
        location = 1;
        gprs_timer_2(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x66)
    {
        iei = 1;
        location = 1;
        additional_network_feature_support(iei, location);
    }

    B8_BIT(h, 1, 8);
    if(h == 0x6a)
    {
        iei = 1;
        location = 1;
        gprs_timer_2(iei, location);
    }
    END_SIGNAL();
    };SET_MATCH(0);}return match;
}
#ifdef __cpluscplus
extern "C" {
#endif
void *attach_accept_state_new(nbp_pd_extract_context *extctx){
    NPCTX pState = (NPCTX) malloc(sizeof(struct attach_accept_ctx));
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
void attach_accept_state_free(void *state) {
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
nbe_pu_gb *attach_accept_get_userdata(void *pState) {
    return ((NPCTX)pState)->gb;
}
int attach_accept_get_param(void *pState, int index, void *param, int len) {
    NPCTX pctx = (NPCTX) pState;
    switch (index) {
        default:
            return -1;
    }
    return 0;
}
int attach_accept_set_param(void *pState, int index, void *param, int len) {
    NPCTX pctx = (NPCTX) pState;
    switch (index) {
        default:
            return -1;
    }
    return 0;
}
int attach_accept_parse(void *pState, uint8_t *input, uint32_t input_len, int flag, void *ctx) {
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
