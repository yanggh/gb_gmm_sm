#ifndef __NBE_COMMON_H__
#define __NBE_COMMON_H__

#include <errno.h>

#define PG_TRY()
#define PG_CATCH()
#define PG_END_TRY()


#define UNIQUE_LABEL( x, y ) x##y
#define LABEL_CONCAT( x, y ) UNIQUE_LABEL( x, y )

typedef struct code2dict {
    uint32_t code;
    char str[128];
} code2dict;

#ifdef YYFILL
#undef YYFILL
#endif

#define YYFILL(s, n)  ENSURE_DATA(sz)
		  
//elog(ERROR, "reached end of buffer."); \

#include <stdlib.h>
#include <setjmp.h>

#define um_trymax 16

#define UM_MAIN
#ifdef UM_MAIN
  int      umErr = 0;
  int      um_jbn = 0;
  jmp_buf  um_jbv[um_trymax];  
#else 
  extern int      umErr;
  extern int      um_jbn;
  extern jmp_buf  um_jbv[um_trymax];  
#endif

#define umTry      for (  umErr = -1  \
                         ; umErr == -1 && um_jbn < um_trymax \
                         ; (um_jbn> 0 ? um_jbn-- : 0 ) , \
                           ((umErr > 0)? umThrow(umErr) : 0), \
                           (umErr = 0) ) \
                       if ((umErr = setjmp(um_jbv[um_jbn++])) == 0 )

#define umCatch(e)    else if ((umErr == (e)) && ((umErr = 0) == 0))

#define umCatchAny    else for ( ;umErr > 0; umErr = 0)

#define umThrow(e) (umErr=e, (um_jbn > 0 && umErr? \
                                  longjmp(um_jbv[um_jbn-1], umErr):\
                                      exit(umErr)))

#define ENSURE_DATA(sz) do { \
      if(YYLIMIT < (YYCURSOR + sz)) { \
		  umThrow(1);	\
	  } \
    } while(0)
    
#define POS(v) do { \
        v = YYCURSOR - input; \
    } while(0)

#define SKIP(n) do { \
      ENSURE_DATA(n); \
      YYCURSOR += (n); \
    } while(0)

#define BACK(n) do { \
        YYCURSOR -= (n); \
    } while(0)

#define BX(v, sz, typ)  do { \
      ENSURE_DATA(sz); \
      v = *(typ*) YYCURSOR; \
    } while(0)

#define B8(v) BX(v, 1, uint8_t)
#define B16(v) BX(v, 2, uint16_t)
#define B32(v) BX(v, 4, uint32_t)
#define B64(v) BX(v, 8, uint64_t)

#define NO_SWAP
#define SWAP16 do { \
     typedef struct ps {uint8_t dt[2];} ps; \
     ps *s = (ps*) &d; \
     uint8_t tmp = s->dt[1]; \
     s->dt[1] = s->dt[0];\
     s->dt[0] = tmp; \
     } while(0)

#define SWAP32 do { \
     typedef struct ps {uint8_t dt[4];} ps; \
     ps *s = (ps*) &d; \
     uint8_t tmp = s->dt[3]; \
     s->dt[3] = s->dt[0];\
     s->dt[0] = tmp; \
     tmp = s->dt[2]; \
     s->dt[2] = s->dt[1]; \
     s->dt[1] = tmp; \
     } while(0)

#define SWAP64 do { \
     typedef struct ps {uint8_t dt[8];} ps; \
     ps *s = (ps*) &d; \
     uint8_t tmp = s->dt[7]; \
     s->dt[7] = s->dt[0];\
     s->dt[0] = tmp; \
     tmp = s->dt[6]; \
     s->dt[6] = s->dt[1]; \
     s->dt[1] = tmp; \
     tmp = s->dt[5]; \
     s->dt[5] = s->dt[2];\
     s->dt[2] = tmp; \
     tmp = s->dt[4]; \
     s->dt[4] = s->dt[3]; \
     s->dt[3] = tmp; \
     } while(0)

#define BITSTR_FORMAT(typ, v, sz, data, start, end) do  { \
     char bit_buf[8 * sz + 1]; \
     int i; \
     memset(bit_buf, '-', sizeof(bit_buf) - 1); \
     for (i = start; i <= end; i++) { \
        bit_buf[8 * sz - i] =  ((1 << (i -start)) & data) ? '1' : '0'; \
     } \
     nbe_string s; \
     s.str = (uint8_t*) bit_buf; \
     s.len = 8 * sz; \
     nbe_ ##typ##_set_## v ##_bin(&MYVAR(typ), s); \
     } while(0)

#define BX_BIT(v, sz, typ, swap, mask, start, end)  do { \
      ENSURE_DATA(sz); \
      typ d = *(typ*) YYCURSOR; \
      swap; \
      typ res = (d >> (start - 1)) & (mask >> (8 * sz -(end - start + 1))) ; \
      v = res; \
    } while(0)

#define B8_BIT(v, start, end) BX_BIT(v, 1, uint8_t, NO_SWAP , 0xFF, start, end) 
#define B16_BIT(v, start, end) BX_BIT(v, 2, uint16_t, SWAP16, 0xFFFF, start, end) 
#define B24_BIT(v, start, end) BX_BIT(v, 3, uint32_t, NO_SWAP, 0xFFFFFFFF, start, end) 
#define B32_BIT(v, start, end) BX_BIT(v, 4, uint32_t, SWAP32, 0xFFFFFFFF, start, end) 
#define B64_BIT(v, start, end) BX_BIT(v, 8, uint64_t, SWAP64, 0xFFFFFFFFFFFFFFFF, start, end) 


#define BX_BIT_FRT(stream, fld, sz, typ, swap, mask, start, end)  do { \
      ENSURE_DATA(sz); \
      typ d = *(typ*) YYCURSOR; \
      swap; \
      typ res = (d >> (start - 1)) & (mask >> (8 * sz - (end - start + 1))) ; \
      nbe_ ##stream##_set_## fld (MYVAR(stream), res); \
      BITSTR_FORMAT(stream, fld, sz, res, start, end); \
    } while(0)

#define B8_BIT_FRT(stream, fld, start, end) BX_BIT_FRT(stream, fld, 1, uint8_t, NO_SWAP , 0xFF, start, end) 
#define B16_BIT_FRT(stream, fld, start, end) BX_BIT_FRT(stream, fld, 2, uint16_t, SWAP16, 0xFFFF, start, end) 
#define B24_BIT_FRT(stream, fld, start, end) BX_BIT_FRT(stream, fld, 3, uint32_t, NO_SWAP, 0xFFFFFF, start, end) 
#define B32_BIT_FRT(stream, fld, start, end) BX_BIT_FRT(stream, fld, 4, uint32_t, SWAP32, 0xFFFFFFFF, start, end) 
#define B64_BIT_FRT(stream, fld, start, end) BX_BIT_FRT(stream, fld, 8, uint64_t, SWAP64, 0xFFFFFFFFFFFFFFFF, start, end) 

#define SET_V(stream, fld, v) do { \
      nbe_ ##stream##_set_## fld (MYVAR(stream), v); \
    } while(0)

#define SET_STR(stream, fld, v) do { \
     nbe_string s; \
     s.str = (uint8_t*) v; \
     s.len = strlen(v); \
     nbe_ ##stream##_set_## fld (&MYVAR(stream), s); \
    } while(0)

#define SET_NSTR(stream, fld, v, length) do { \
     nbe_string s; \
     s.str = (uint8_t*) v; \
     s.len = length; \
     nbe_ ##stream##_set_## fld (&MYVAR(stream), s); \
    } while(0)


/**TODO:adding logic when there is no code matched. */
#define SET_STR1(stream, fld, c, dict) do { \
     nbe_string s; \
     int i;        \
     int len = sizeof(dict) / sizeof(dict[0]); \
     for (i = 0; i < len; i++) { \
         if (dict[i].code == c) { \
             s.str = (uint8_t*) dict[i].str; \
             s.len = strlen(dict[i].str); \
             nbe_ ##stream##_set_## fld (&MYVAR(stream), s); \
             break; \
         } \
     } \
    } while(0)

#define SET_PU(stream, fld, pu) do { \
     nbe_ ##stream##_set_## fld (&MYVAR(stream), MYVAR(pu)); \
    } while(0)

#if 0

#define EXT_STR(stream, fld, start, end) do { \
    nbe_string s; \
    s.str = YYCURSOR; \
    s.len = end - start + 1; \
    nbe_ ##stream##_set_## fld (&MYVAR(stream), s); \
    } while(0);
#endif

#define B8_BIT_FRT_DESC(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, uint8_t, NO_SWAP , 0xFF, start, end); \
    SET_STR(stream, fld##_desc, str); \
    } while(0)

#define B16_BIT_FRT_DESC(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, 2, uint16_t, SWAP16, 0xFFFF, start, end); \
    SET_STR(stream, fld##_desc, str); \
    } while(0)

#define B32_BIT_FRT_DESC(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, 4, uint32_t, SWAP32, 0xFFFFFFFF, start, end); \
    SET_STR(stream, fld ##_desc, str); \
   } while(0)

#define B64_BIT_FRT_DESC(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, 8, uint64_t, SWAP64, 0xFFFFFFFFFFFFFFFF, start, end); \
    SET_STR(stream, fld ##_desc, str); \
    } while(0)

#define B8_BIT_FRT_NAME(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, uint8_t, NO_SWAP , 0xFF, start, end); \
    SET_STR(stream, fld##_name, str); \
    } while(0)

#define B16_BIT_FRT_NAME(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, 2, uint16_t, SWAP16, 0xFFFF, start, end); \
    SET_STR(stream, fld##_name, str); \
    } while(0)

#define B32_BIT_FRT_NAME(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, 4, uint32_t, SWAP32, 0xFFFFFFFF, start, end); \
    SET_STR(stream, fld##_name, str); \
    } while(0)

#define B64_BIT_FRT_NAMEC(stream, fld, start, end, str) do { \
    BX_BIT_FRT(stream, fld, 8, uint64_t, SWAP64, 0xFFFFFFFFFFFFFFFF, start, end); \
    SET_STR(stream, fld##_name, str); \
    } while(0)

#define B8_BIT_FRT_NAME_DESC(stream, fld, start, end, nm, dc) do { \
    BX_BIT_FRT(stream, fld, uint8_t, NO_SWAP , 0xFF, start, end); \
    SET_STR(stream, fld##_name, nm); \
    SET_STR(stream, fld##_desc, dc); \
    } while(0)

#define B16_BIT_FRT_NAME_DESC(stream, fld, start, end, nm, dc) do { \
    BX_BIT_FRT(stream, fld, 2, uint16_t, SWAP16, 0xFFFF, start, end); \
    SET_STR(stream, fld##_name, nm); \
    SET_STR(stream, fld##_desc, dc); \
    } while(0)

#define B32_BIT_FRT_NAME_DESC(stream, fld, start, end, nm, dc) do { \
    BX_BIT_FRT(stream, fld, 4, uint32_t, SWAP32, 0xFFFFFFFF, start, end); \
    SET_STR(stream, fld##_name, nm); \
    SET_STR(stream, fld##_desc, dc); \
    } while(0)

#define B64_BIT_FRT_NAMEC_DESC(stream, fld, start, end, nm, dc) do { \
    BX_BIT_FRT(stream, fld, 8, uint64_t, SWAP64, 0xFFFFFFFFFFFFFFFF, start, end); \
    SET_STR(stream, fld##_name, nm); \
    SET_STR(stream, fld##_desc, dc); \
    } while(0)
#if 0
#define EX_BIT_FRT(stream, sz, typ, swap, mask, start, end)  do { \
      ENSURE_DATA(sz); \
      char buf[8 * sz + 1]; \
      char bit_buf[9]; \
      int pos = 0; \
      memset(buf, '\0', sizeof(buf)); \
      while(sz--) \
      { \
        typ d = *(typ*) YYCURSOR; \
        swap; \
        typ res = (d >> (start - 1)) & (mask >> (8 - (end - start + 1))) ; \
        int i; \
        memset(bit_buf, '-', sizeof(bit_buf) - 1); \
        for (i = start; i <= end; i++) { \
            bit_buf[8 - i] =  ((1 << (i -start)) & res) ? '1' : '0'; \
        } \
        pos += sprintf(buf+pos, "%s", bit_buf); \
        printf("bit_buf: %s, bit_buf_size: %d pos: %d\n", bit_buf, strlen(bit_buf), pos);\
        SKIP(1);\
       } \
    printf("f_bin:%s, f_bin_size: %d\n", buf, strlen(buf));\
    SET_STR(stream, f_bin, buf);\
 } while(0)
#endif
 
#if 1
#define EX_BIT_FRT(stream, sz, typ, swap, mask, start, end)  do { \
      ENSURE_DATA(sz); \
      char buf[8*sz + 1]; \
      char bit_buf[9]; \
      int pos = 0; \
      bzero(buf, sizeof(buf)); \
      while(sz--) \
      { \
        typ d = *(typ*) YYCURSOR; \
        swap; \
        typ res = (d >> (start - 1)) & (mask >> (8 - (end - start + 1))) ; \
        int i; \
        memset(bit_buf, '-', sizeof(bit_buf) - 1); \
        for (i = start; i <= end; i++) { \
            bit_buf[8 - i] =  ((1 << (i -start)) & res) ? '1' : '0'; \
        } \
        memcpy(buf+pos, bit_buf, sizeof(bit_buf)-1); \
        pos += sizeof(bit_buf) - 1; \
		SKIP(1);\
       } \
       SET_STR(stream, f_bin, buf);\
 } while(0)
#endif
        //printf("bit_buf: %s, bit_buf_size: %d pos: %d\n", bit_buf, strlen(bit_buf), pos);\
       //printf("f_bin:%s, f_bin_size: %d\n", buf, strlen(buf));\

/** FIXME: check sprintf's parameter convertion */
#define A_BIT(stream, fid, nm, sz) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    EX_BIT_FRT(stream, sz, uint8_t, NO_SWAP, 0xFF, 1, 8); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    SET_STR(stream, f_id, #fid); \
    SET_STR(stream, f_name, nm); \
	if(_hex_desc != NULL) { \
		SET_STR(stream, f_desc, _hex_desc); \
        _hex_desc = NULL; \
    } \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define A_B8_BIT1(stream, fid, nm, start, end) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    BX_BIT_FRT(stream, f, 1, uint8_t, NO_SWAP, 0xFF, start, end); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_id, #fid); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    char b[16]; \
    memset(b, 0, sizeof(b)); \
    sprintf(b, "%d", (int)MYVAR(stream)->f); \
    SET_STR(stream, f_desc, b); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define A_B8_HEX_BIT1(stream, fid, nm, start, end) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    BX_BIT_FRT(stream, f, 1, uint8_t, NO_SWAP, 0xFF, start, end); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_id, #fid); \
    char b[16]; \
    memset(b, 0, sizeof(b)); \
    if (_hex != NULL) { \
        if(start == 1 && end == 8) \
        { \
            SET_STR(stream, f_hex, _hex); \
        } \
        sprintf(b, "%s", _hex); \
        _hex = NULL; \
    } \
    SET_STR(stream, f_desc, b); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define A_B8_BIT2(stream, fid, nm, start, end, desc) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    BX_BIT_FRT(stream, f, 1, uint8_t, NO_SWAP, 0xFF, start, end); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    SET_STR(stream, f_id, #fid); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_desc, desc); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define A_B16_BIT2(stream, fid, nm, start, end, desc) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    BX_BIT_FRT(stream, f, 2, uint16_t, NO_SWAP, 0xFFFF, start, end); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    SET_STR(stream, f_id, #fid); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_desc, desc); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define A_B32_BIT2(stream, fid, nm, start, end, desc) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    BX_BIT_FRT(stream, f, 4, uint32_t, NO_SWAP, 0xFFFFFFFF, start, end); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    SET_STR(stream, f_id, #fid); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_desc, desc); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define A_B8_VALUE(stream, fid, nm, value) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    SET_STR(stream, f_id, #fid); \
    SET_STR(stream, f_name, nm); \
    SET_V(stream, f, value); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)



#define A_B8_BIT3(stream, fid, nm, start, end, dict) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    BX_BIT_FRT(stream, f, 1, uint8_t, NO_SWAP, 0xFF, start, end); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    SET_STR(stream, f_id, #fid); \
    SET_STR(stream, f_name, nm); \
    SET_STR1(stream, f_desc, MYVAR(stream)->f, dict); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)

#define RBE(stream, fid, nbits) do { \
    uint64_t d; \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    RBS(d, nbits); \
    SET_V(stream, f, d); \
    SET_STR(stream, f_name, #fid); \
    SET_STR(stream, f_id, #fid); \
    TO_HEX(d, nbits); \
    if (_hex_buf != NULL) { \
        SET_STR(stream, f_hex, _hex_buf); \
    } \
    char b[16]; \
    memset(b, 0, sizeof(b)); \
    sprintf(b, "%d", (int)MYVAR(stream)->f); \
        SET_STR(stream, f_desc, b); \
        int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
        if (rv == -1) { \
                printf("error:failed to call nbe_list_add.\n"); \
                return -1; \
        } \
    } while(0)

#define RBE_BYTE(stream, name, nbytes, desc) do { \
    uint64_t d; \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    RBS(d, nbytes * 8); \
    SET_V(stream, f, d); \
    SET_STR(stream, f_name, name); \
    TO_HEX(d, nbytes * 8); \
    if (_hex_buf != NULL) { \
        SET_STR(stream, f_hex, _hex_buf); \
    } \
    if (nbytes < 4 && strcmp(desc, "") == 0) \
	{ \
		char str[16]; \
		sprintf(str,"%lld", d);	\
    	SET_STR(stream, f_desc, str); \
	} \
	else \
	{ \
    	SET_STR(stream, f_desc, desc); \
	} \
        int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
        if (rv == -1) { \
                printf("error:failed to call nbe_list_add.\n"); \
                return -1; \
        } \
    } while(0)


#define A_B16_BIT1(stream, fid, nm, start, end) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    B16_BIT_FRT(stream, f, start, end); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_id, #fid); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    char b[16]; \
    memset(b, 0, sizeof(b)); \
    sprintf(b, "%d", (int)MYVAR(stream)->f); \
    SET_STR(stream, f_desc, b); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)


#define A_B24_BIT1(stream, fid, nm, start, end) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    B24_BIT_FRT(stream, f, start, end); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_id, #fid); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    char b[24]; \
    memset(b, 0, sizeof(b)); \
    sprintf(b, "%d", (int)MYVAR(stream)->f); \
    SET_STR(stream, f_desc, b); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)


#define A_B32_BIT1(stream, fid, nm, start, end) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    B32_BIT_FRT(stream, f, start, end); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_id, #fid); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    char b[32]; \
    memset(b, 0, sizeof(b)); \
    sprintf(b, "%d", (int)MYVAR(stream)->f); \
    SET_STR(stream, f_desc, b); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)


#define A_B64_BIT1(stream, fid, nm, start, end) do { \
    nbe_gbf_free(MYVAR(gbf)); \
    MYVAR(gbf) = nbe_gbf_new(); \
    B64_BIT_FRT(stream, f, start, end); \
    SET_STR(stream, f_name, nm); \
    SET_STR(stream, f_id, #fid); \
    if (_hex != NULL) { \
        SET_STR(stream, f_hex, _hex); \
        _hex = NULL; \
    } \
    char b[64]; \
    memset(b, 0, sizeof(b)); \
    sprintf(b, "%d", (int)MYVAR(stream)->f); \
    SET_STR(stream, f_desc, b); \
    int rv = nbe_list_add(&MYVAR(ls_fields), (nbe_pu*)MYVAR(gbf)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    } while(0)





#define PBE(v , nbits) do { \
    uint8_t *old_cur = YYCURSOR; \
    uint32_t old_bit_remain = bit_remain; \
    RBS(v, nbits); \
    YYCURSOR = old_cur; \
    bit_remain = old_bit_remain; \
    } while(0);
    
#define RBS(v, nbits) do { \
    int scale = 0; \
    int c = 0; \
    int finish = 0; \
    int left = nbits; \
    v = 0; \
    if (bit_remain <= 0) { \
        SKIP(1); \
        bit_remain = 8; \
    } \
    do { \
      int t = bit_remain - left; \
      if (t >= 0) { \
          c = left; \
          finish = 1; \
      } \
      else { \
          left = left - bit_remain; \
          c = bit_remain; \
      } \
      v = (v << c) + (uint8_t)(((uint8_t)((*(YYCURSOR) ) <<(8-bit_remain)) & (0xFF << (8 - c))) >> (8-c)) ; \
      if (t < 0) { \
          SKIP(1); \
          bit_remain = 8; \
      }\
      else { \
          bit_remain = t; \
      } \
      scale = scale + c; \
     } while(!finish); \
    } while(0)


#define BEGIN_LAPDM() do { \
	umTry \
	{ \
    SET_STR(fr_msg, layer, "0"); \
    { \
    char *hexbuf = malloc(len * 3 + 1); \
    memset(hexbuf, 0x00, len*2+1); \
    int pos = 0; \
    uint8_t *p = input; \
    while(p != limit) { \
    pos += sprintf(hexbuf + pos, "%02x ", *p); \
    p++; \
    } \
    SET_STR(fr_msg, frame_type, "Unknown"); \
    SET_STR(fr_msg, signal_type, "Unknown"); \
    SET_STR(fr_msg, raw, hexbuf); \
    SET_V(fr_msg, raw_len, len); \
    free(hexbuf); \
    }
    
   
    
     

/**
 * save parsed list of elements to gb's elements field.
 * FIXME:the input=input is used to remove gcc compiler error regarding with label cannot followed by empty stmt
 */
#define END_LAPDM()  \
	}	\
	umCatch(1) \
    { \
        ; \  
    } \
	{ \
    input = input; \
    int num = nbe_list_count(MYVAR(ls_elements)); \
    if (num > 0) { \
        nbe_list_finish(MYVAR(ls_elements)); \
        SET_PU(fr_msg, elements, ls_elements); \
    } \
	} \
	\
    } while(0)

#define SET_LAYER(gb_layer) do { \
    SET_STR(gb, layer, gb_layer); \
}while(0)

#define SET_FRAME_TYPE(type) do { \
    SET_STR(gb, frame_type, type); \
}while(0)

#define SET_MSG_TYPE(name) do { \
    SET_STR(gb, signal_name, name); \
}while(0)

#define SET_L2_MSG_TYPE(name) do { \
    SET_STR(fr_msg, signal_name, name); \
}while(0)

#define BEGIN_SIGNAL(gb_layer, type, name) do { \
	umTry \
	{ \
    SET_STR(gb, layer, gb_layer); \
    SET_STR(gb, frame_type, type); \
    SET_STR(gb, signal_name, name); \
    { \
    char *hexbuf = malloc(len * 3 + 1); \
    memset(hexbuf, 0x00, len*2+1); \
    int pos = 0; \
    uint8_t *p = input; \
    while(p != limit) { \
    pos += sprintf(hexbuf + pos, "%02x ", *p); \
    p++; \
    } \
    SET_STR(gb, raw, hexbuf); \
    SET_V(gb, raw_len, len); \
    free(hexbuf); \
    }

#define A_BN_BIT1(length) do { \
	uint32_t pos; \
	POS(pos); \
	SET_V(gb, next_pos, pos); \
	SET_V(gb, next_len, length);\ 
    }while(0)

#define CHECK_SUM(length) \
({ \
    uint8_t sum = 0; \
    uint8_t checksum; \
    uint8_t *p = (uint8_t*) YYCURSOR; \
    int i; \
    for(i = 0; i < length; i++) \
    { \
        sum += *(p + i); \
    } \
    if (sum&0x80 == 0) \
    { \
        checksum = sum & 0xFF; \
    } \
    else \
    {  \
        checksum = (uint8_t)~(sum); \
        checksum |= (uint8_t)(sum & 0x80); \
        checksum = (uint8_t)checksum + 1; \
    } \
    checksum; \
})


/**
 * save parsed list of elements to gb's elements field.
 * FIXME:the input=input is used to remove gcc compiler error regarding with label cannot followed by empty stmt
 */
#define END_SIGNAL()  \
	}	\
	umCatch(1) \
    { \
        ; \
    } \
	{ \
    input = input; \
    int num = nbe_list_count(MYVAR(ls_elements)); \
    if (num > 0) { \
        nbe_list_finish(MYVAR(ls_elements)); \
        SET_PU(gb, elements, ls_elements); \
    } \
	} \
	\
    } while(0)

#define TO_HEX(value, nbits) do { \
    typedef struct byte8 \
    { \
       uint8_t v[8]; \
    } byte8; \
    int i; \
    int pos = 0; \
    int nbytes = (nbits + 7) / 8; \
    byte8 *b =(byte8*) &value; \
    memset(_hex_buf, 0, sizeof(_hex_buf)); \
    for (i = 0; i < nbytes; i++) { \
        if (i == 0) { \
           pos += sprintf(_hex_buf + pos, "%02x", b->v[i]); \
        } \
        else { \
            pos += sprintf(_hex_buf + pos, " %02x", b->v[i]); \
        } \
    } \
} while(0)


#define HEX(len) do { \
    uint8_t v; \
    int pos = 0; \
	int i; \
    memset(_hex_buf, 0, sizeof(_hex_buf)); \
    for(i = 0; i < len; i++) \
    { \
        v = *YYCURSOR; \
        pos += sprintf(_hex_buf + pos, "%02x ", v); \
        SKIP(1); \
    } \
    _hex = _hex_buf; \
	BACK(len); \
} while(0)

#define HEX_DESC(len) do { \
    uint8_t v; \
    int pos = 0; \
	int i; \
    memset(_hex_desc_buf, 0, sizeof(_hex_desc_buf)); \
    for(i = 0; i < len; i++) \
    { \
        v = *YYCURSOR; \
        pos += sprintf(_hex_desc_buf + pos, "%02x", v); \
        SKIP(1); \
    } \
    _hex_desc = _hex_desc_buf; \
	BACK(len); \
} while(0)


#define B8_HEX() do { \
     uint8_t v = *YYCURSOR; \
     memset(_hex_buf, 0, sizeof(_hex_buf)); \
     sprintf(_hex_buf, "%02x", v); \
     _hex = _hex_buf; \
    } while(0)



/**FIXME:using common log to log error. 
 * request for a slot of type of gbe in current elements list.
 * 
 */
#define BEGIN_ELEMENT(label, ele_name) do { \
    SET_STR(gbe, element_name, #ele_name); \
    SET_STR(gbe, element_desc, label); \
    } while(0)

#define SET_ELEMENT(label, ele_name) do { \
    SET_STR(gbe, element_name, #ele_name); \
    SET_STR(gbe, element_desc, label); \
    } while(0)


/**
 * save fields to current element node's fields property.
 * then reset the fields list for reuse.
 */
#define END_ELEMENT() do { \
    int num = nbe_list_count(MYVAR(ls_fields)); \
    if (num > 0) { \
        nbe_list_finish(MYVAR(ls_fields)); \
        SET_PU(gbe, fields, ls_fields); \
        nbe_list_reset(&MYVAR(ls_fields)); \
    } \
    int rv = nbe_list_add(&MYVAR(ls_elements), (nbe_pu*)MYVAR(gbe)); \
    if (rv == -1) { \
        printf("error:failed to call nbe_list_add.\n"); \
        return -1; \
    } \
    nbe_gbe_free(MYVAR(gbe)); \
    MYVAR(gbe) = nbe_gbe_new(); \
    } while(0)


//#define LIST_NEW(pv, element, id) (nbe_pu_list *pv = nbe_list_new(NBE_STRUCT, id, sizeof(element), sizeof(element) + 1024)

#define listadd(ls, el)
#if 0
#define listadd(ls, el) do { \
    int rv = nbe_list_append(&MYVAR(ls), (nbe_pu*)&MYVAR(el)); \
    } while(0)
#endif
#endif //end __NBE_COMMON_H__
