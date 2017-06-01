#ifndef __GB_L3_COMMON_H__
#define __GB_L3_COMMON_H__

#include "nbe_common.h"

#define MESSAGE_TYPE_MM 0
#define MESSAGE_TYPE_RR 1
#define MESSAGE_TYPE_CC 2
#define MESSAGE_TYPE_GMM 3
#define MESSAGE_TYPE_SM 4
#define MESSAGE_TYPE_UNKNOWN 5

char _hex_buf[1024];
char *_hex = NULL;

void dec_to_bin(int ival, char *buf)
{
   int  n = 0;
   char bin[32];
   //char buf[32]; 
   char *p = buf;
   int pos = 0;

   if(ival == 0)
   {   
      sprintf(p, "%d", ival);
      return;
   }

   while(ival > 0) { 
       bin[n++] = ival & 0x01; 
       ival >>= 1;  
   }   
   for(n--; n >= 0; n--) 
       pos += sprintf(p + pos, "%d", bin[n]); 
   //return buf;
} 

int bin_to_dec(char *bin)
{
    int a, b[10], i=0, c=0;
    a = strtol(bin, NULL, 10); 
    while(a!=0)
    {   
        b[i]=a%10;
        a/=10;
        i++;
    }   
    i--;
    for(;i>=0;i--)
        c=c*2+b[i];
    return c;
}

void bit_map0_format() 
{
	int tmp; 
    char buf[100]; 
    memset(buf, 0x00, sizeof(buf)); 
    char *p = buf; 
    B8_HEX(); 
    strcpy(p, "bit map 0 format ARFCH="); 
    p += 23; 
    int i; 
    int j = 4; 
    int var = 125; 
    int pos = 0;
    for(i = 0; i < 4; i++) 
    { 
		B8_BIT(tmp, j, j); 
        var--;
        if(tmp == 1) 
        { 
            pos += sprintf(p + pos, "%d ", var); 
        } 
        j--; 
    } 
	A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "Bit map 0"); 
    A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
    A_B8_BIT2(gbf, arfch, "ARFCH", 1, 4, buf); 
    SKIP(1); 

    int k;
    for(k = 0; k < 15; k++) 
    { 
        memset(buf, 0x00, sizeof(buf)); 
        p = buf; 
        strcpy(p, "ARFCH="); 
        p += 6; 
        pos = 0; 
        for(i = 0, j = 8; i < 8; i++) 
        { 
            var--;
			B8_BIT(tmp, j, j); 
            if(tmp == 1) 
            { 
                pos += sprintf(p + pos, "%d ", var); 
            } 
            j--; 
        } 
        B8_HEX(); 
		A_B8_BIT2(gbf, arfch, "ARFCH", 1, 8, buf); 
		SKIP(1); 
    } 
}

void um_bit_map0_format(int flag) 
{
	int tmp; 
    char buf[100]; 
    memset(buf, 0x00, sizeof(buf)); 
    char *p = buf; 
    B8_HEX(); 
    strcpy(p, "bit map 0 format ARFCH="); 
    p += 23; 
    int i; 
    int j = 4; 
    int var = 125; 
    int pos = 0;

    if(!flag)
    {
        for(i = 0; i < 4; i++) 
        { 
	    	B8_BIT(tmp, j, j); 
            var--;
            if(tmp == 1) 
            { 
                pos += sprintf(p + pos, "%d ", var); 
            } 
            j--; 
        } 
        A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "Bit map 0 format"); 
        A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
        A_B8_BIT2(gbf, arfch, "ARFCH", 1, 4, buf); 
    }
    else
    {
        B8_BIT(tmp, 8, 8);
        if(tmp == 1)
            pos += sprintf(p + pos, "%d ", 128);
        for(i = 0; i < 4; i++) 
        { 
	    	B8_BIT(tmp, j, j); 
            var--;
            if(tmp == 1) 
            { 
                pos += sprintf(p + pos, "%d ", var); 
            } 
            j--; 
        } 

        A_B8_BIT2(gbf, format_id, "FORMAT-ID", 8, 8, "Bit map 0 format"); 
        A_B8_BIT1(gbf, multiband_reporting, "Multiband reporting", 6, 7); 
        A_B8_BIT1(gbf, ba_ind, "BA-IND", 5, 5); 
        A_B8_BIT2(gbf, arfch, "ARFCH", 1, 4, buf); 
    }
        
    SKIP(1); 

    int k;
    for(k = 0; k < 15; k++) 
    { 
        memset(buf, 0x00, sizeof(buf)); 
        p = buf; 
        strcpy(p, "ARFCH="); 
        p += 6; 
        pos = 0; 
        for(i = 0, j = 8; i < 8; i++) 
        { 
            var--;
			B8_BIT(tmp, j, j); 
            if(tmp == 1) 
            { 
                pos += sprintf(p + pos, "%d ", var); 
            } 
            j--; 
        } 
        B8_HEX(); 
		A_B8_BIT2(gbf, arfch, "ARFCH", 1, 8, buf); 
		SKIP(1); 
    } 
}


void range1024_format(int len) 
{
    B8_HEX(); 
    //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "FORMAT = 1024 range"); 
    //A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
    //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 4, 4, "FORMAT = 1024 range"); 
    //A_B8_BIT3(gbf, f0, "F0", 3, 3, frequency_list_1024f_f0); 
    //A_B8_BIT2(gbf, arfcn, "W(1)(high part)", 1, 2, "-"); 
    A_B8_BIT2(gbf, format_identifier, "Format Identifier", 1, 8, "1024 range"); 
    int tmp = -1;
    char buf[100];
	memset(buf, 0x00, sizeof(buf)); 
    B16_BIT(tmp, 1, 10); 
    len -= 1;
	SKIP(1); 

	int w1 = tmp; 
    int pos, w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17;
    sprintf(buf, "ARFCN = %d", tmp); 
	B8_HEX(); 
	A_B8_BIT2(gbf, w1, "W(1)(low part)", 1, 8, buf); 
    len -= 1;
	SKIP(1); 

	if(len > 0)
    {
	    B16_BIT(tmp, 8, 16); 
	    w2 = tmp; 
	    int f2 = (w1 - 512 + w2) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f2); 
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w2_h, "ARFCN", 1, 8, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
	if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w2_l, "ARFCN", 8, 8, buf); 
	    B16_BIT(tmp, 7, 15); 
	    w3 = tmp; 
	    int f3 = (w1 + w3) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f3); 
	    A_B8_BIT2(gbf, w3_h, "ARFCN", 1, 7, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w3_l, "ARFCN", 7, 8, buf); 
	    
	    B16_BIT(tmp, 7, 14); 
	    w4 = tmp; 
	    int f4 = (w1 - 512 + (w2 - 256 + w4) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f4); 
	    A_B8_BIT2(gbf, w4_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w4_l, "ARFCN", 7, 8, buf); 
	    
	    B16_BIT(tmp, 7, 14); 
	    w5 = tmp; 
	    int f5 = (w1 + (w3 - 256 + w5) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f5); 
	    A_B8_BIT2(gbf, w5_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w5_l, "ARFCN", 7, 8, buf); 
	    
	    B16_BIT(tmp, 7, 14); 
	    w6 = tmp; 
	    int f6 = (w1 - 512 + (w2 + w6) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f6); 
	    A_B8_BIT2(gbf, w6_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w6_l, "ARFCN", 7, 8, buf); 
	    
	    B16_BIT(tmp, 7, 14); 
	    w7 = tmp; 
	    int f7 = (w1 + (w3 + w7) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f7); 
	    A_B8_BIT2(gbf, w7_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w7_l, "ARFCN", 7, 8, buf); 
	    
	    B16_BIT(tmp, 8, 14); 
	    w8 = tmp; 
	    int f8 = (w1 - 512 + (w2 - 256 + (w4 - 128 + w8 ) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f8); 
	    A_B8_BIT2(gbf, w8_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w8_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 1, 7); 
	    w9 = tmp; 
	    int f9 = (w1 + (w3 - 256 + (w5 - 128 + w9 ) % 255) % 511) % 1023; 
        sprintf(buf, "ARFCN = %d", f9); 
	    A_B8_BIT2(gbf, w9, "ARFCN", 1, 7, buf);
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_BIT(tmp, 2, 8); 
	    w10 = tmp; 
	    int f10 = (w1 - 512 + (w2 + (w6 - 128 + w10) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f10); 
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w10, "ARFCN", 2, 8, buf); 
	    B16_BIT(tmp, 3, 9); 
	    w11 = tmp; 
	    int f11 = (w1 + (w3 + (w7 - 128 + w11) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f11); 
	    A_B8_BIT2(gbf, w11_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w11_l, "ARFCN", 3, 8, buf); 
	    
	    B16_BIT(tmp, 4, 10); 
	    w12 = tmp; 
	    int f12 = (w1 - 512 + (w2 - 256 + (w4 + w12) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f12); 
	    A_B8_BIT2(gbf, w12_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w12_l, "ARFCN", 4, 8, buf); 
	    
	    B16_BIT(tmp, 5, 11); 
	    w13 = tmp; 
	    int f13 = (w1 + (w3 - 256 + (w5 + w13) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f13); 
	    A_B8_BIT2(gbf, w13_h, "ARFCN", 1, 3, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w13_l, "ARFCN", 5, 8, buf); 
	    
	    B16_BIT(tmp, 6, 12); 
	    w14 = tmp; 
	    int f14 = (w1 - 512 + (w2 + (w6 + w14) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f14); 
	    A_B8_BIT2(gbf, w14_h, "ARFCN", 1, 4, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w14_l, "ARFCN", 6, 8, buf); 
	    
	    B16_BIT(tmp, 7, 13); 
	    w15 = tmp; 
	    int f15 = (w1 + (w3 + (w7 + w15) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f15); 
	    A_B8_BIT2(gbf, w15_h, "ARFCN", 1, 5, "-"); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w15_l, "ARFCN", 7, 8, buf); 
	    B8_BIT(tmp, 1, 6); 
	    w16 = tmp; 
	    int f16 = (w1 - 512 + (w2 - 256 + (w4 - 128 + (w8 - 64 + w16) % 127) % 255) % 511) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, " %d", f16); 
	    A_B8_BIT2(gbf, w16, "ARFCN", 1, 6, buf);
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    SKIP(len); 
    }

}

void range512_format(int len) 
{
    char buf[100];
    int tmp = -1;
    int w0, w1, w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17;
	memset(buf, 0x00, sizeof(buf)); 

    if(len > 0)
    {
        B8_HEX(); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "FORMAT = range 512"); 
        //A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 2, 4, "FORMAT = range 512"); 
	    B24_BIT(tmp, 8, 17); 
	    w0 = tmp; 
        //A_B8_BIT2(gbf, orig_arfcn_h, "ARFCN", 1, 1, "-"); 
        A_B8_BIT2(gbf, format_identifier, "Format Identifier", 1, 8, "512 range"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        A_B8_BIT2(gbf, orig_arfcn_m, "ORIG-ARFCN (middle part)", 1, 8, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        sprintf(buf, "ORIG-ARFCN = %d", tmp); 
	    A_B8_BIT2(gbf, orig_arfcn, "ORIG-ARFCN", 8, 8, buf); 
        B16_BIT(tmp, 7, 15); 
	    w1 = tmp; 
	    int f1 = (w0 + w1) % 1024; 
        sprintf(buf, "ARFCN = %d", f1); 
        A_B8_BIT2(gbf, w1_h, "ARFCN", 1, 7, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w1_l, "ARFCN", 7, 8, buf); 
	    B16_BIT(tmp, 7, 14); 
	    w2 = tmp; 
	    int f2 = (w1 - 512 + w2) % 1023; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f2); 
	    A_B8_BIT2(gbf, w2_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w2_l, "ARFCN", 7, 8, buf); 
	    B16_BIT(tmp, 7, 14); 
	    w3 = tmp; 
	    int f3 = (w0 + (w1 + w3) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f3); 
	    A_B8_BIT2(gbf, w3_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w3_l, "ARFCN", 7, 8, buf); 
	    B16_BIT(tmp, 8, 14); 
	    w4 = tmp; 
	    int f4 = (w0 + (w1 - 256 + (w2 - 128 + w4) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f4); 
	    A_B8_BIT2(gbf, w4_h, "ARFCN", 1, 6, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w4_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 1, 7); 
	    w5 = tmp; 
	    int f5 = (w0 + (w1 + (w3 - 128 + w5) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f5); 
	    A_B8_BIT2(gbf, w5, "ARFCN", 1, 7, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
	    B8_BIT(tmp, 2, 8); 
	    w6 = tmp; 
	    int f6 = (w0 + (w1 - 256 + (w2 + w6) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f6); 
	    A_B8_BIT2(gbf, w6, "ARFCN", 2, 8, buf); 
	    B16_BIT(tmp, 3, 9); 
	    w7 = tmp; 
	    int f7 = (w0 + (w1 + (w3 + w7) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f7); 
	    A_B8_BIT2(gbf, w7_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w7_l, "ARFCN", 3, 8, buf); 
	    B16_BIT(tmp, 5, 10); 
	    w8 = tmp; 
	    int f8 = (w0 + (w1 - 256 + (w2 - 128 + (w4 - 64 + w8 ) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f8); 
	    A_B8_BIT2(gbf, w8_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w8_l, "ARFCN", 5, 8, buf); 
	    B16_BIT(tmp, 7, 12); 
	    w9 = tmp; 
	    int f9 = (w0 + (w1 + (w3 - 128 + (w5 - 64 + w9 ) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f9); 
	    A_B8_BIT2(gbf, w9_h, "ARFCN", 1, 4, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w9_l, "ARFCN", 7, 8, buf); 
	    B8_BIT(tmp, 1, 6); 
	    w10 = tmp; 
	    int f10 = (w0 + (w1 - 256 + (w2 + (w6 - 64 + w10) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f10); 
	    A_B8_BIT2(gbf, w10, "ARFCN", 1, 6, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    B8_BIT(tmp, 3, 8); 
	    w11 = tmp; 
	    int f11 = (w0 + (w1 + (w3 + (w7 - 64 + w11) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f11); 
	    A_B8_BIT2(gbf, w11, "ARFCN", 3, 8, buf); 
	    B16_BIT(tmp, 5, 10); 
	    w12 = tmp; 
	    int f12 = (w0 + (w1 - 256 + (w2 - 128 + (w4 + w12) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f12); 
	    A_B8_BIT2(gbf, w12_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w12_l, "ARFCN", 5, 8, buf); 
	    B16_BIT(tmp, 7, 12); 
	    w13 = tmp; 
	    int f13 = (w0 + (w1 + (w3 - 128 + (w5 + w13) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f13); 
	    A_B8_BIT2(gbf, w13_h, "ARFCN", 1, 4, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w13_l, "ARFCN", 7, 8, buf); 
	    B8_BIT(tmp, 1, 6); 
	    w14 = tmp; 
	    int f14 = (w0 + (w1 - 256 + (w2 + (w6 + w14) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f14); 
	    A_B8_BIT2(gbf, w14_h, "ARFCN", 1, 6, buf); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
	    B8_BIT(tmp, 3, 8); 
	    w15 = tmp; 
	    int f15 = (w0 + (w1 + (w3 + (w7 + w15) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f15); 
	    A_B8_BIT2(gbf, w15, "ARFCN", 3, 8, buf); 
	    B16_BIT(tmp, 6, 10); 
	    w16 = tmp; 
	    int f16 = (w0 + (w1 - 256 + (w2 - 128 + (w4 - 64 + (w8 - 32 + w16) % 63) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f16); 
	    A_B8_BIT2(gbf, w16_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w16_l, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 1, 5); 
	    w17 = tmp; 
	    int f17 = (w0 + (w1 + (w3 - 128 + (w5 - 64 + (w9 - 32 + w17) % 63) % 127) % 255) % 511) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f17); 
	    A_B8_BIT2(gbf, w17, "ARFCN", 1, 5, buf); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
        SKIP(len);
    }

}

void range256_format(int len) 
{
    char buf[100];
    int tmp = -1;
    int w0, w1, w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17,w18,w19,w20,w21;
	memset(buf, 0x00, sizeof(buf)); 

    if(len > 0)
    {
        B8_HEX(); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "FORMAT = range 256"); 
        //A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 2, 4, "FORMAT = range 256"); 
	    B24_BIT(tmp, 8, 17); 
	    w0 = tmp; 
        //A_B8_BIT2(gbf, orig_arfcn_h, "ARFCN", 1, 1, "-"); 
        A_B8_BIT2(gbf, format_identifier, "Format Identifier", 1, 8, "256 range"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        A_B8_BIT2(gbf, orig_arfcn_m, "ORIG_ARFCN(middle part)", 1, 8, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        sprintf(buf, "ORIG_ARFCN = %d", tmp); 
	    A_B8_BIT2(gbf, orig_arfcn, "ORIG_ARFCN", 8, 8, buf); 
        B16_BIT(tmp, 8, 15); 
	    w1 = tmp; 
	    int f1 = (w0 + w1) % 1024; 
        sprintf(buf, "ARFCN = %d", f1); 
        A_B8_BIT2(gbf, w1_h, "ARFCN", 1, 7, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w1_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 1, 7); 
	    w2 = tmp; 
	    int f2 = (w0 + (w1 - 128 + w2) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f2); 
	    A_B8_BIT2(gbf, w2, "ARFCN", 1, 6, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    B8_BIT(tmp, 2, 8); 
	    w3 = tmp; 
	    int f3 = (w0 + (w1 + w3) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f3); 
	    A_B8_BIT2(gbf, w3, "ARFCN", 2, 8, buf); 
	    B8_BIT(tmp, 4, 9); 
	    w4 = tmp; 
	    int f4 = (w0 + (w1 - 128 + (w2 - 64 + w4) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f4); 
	    A_B8_BIT2(gbf, w4_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w4_l, "ARFCN", 4, 8, buf); 
	    B16_BIT(tmp, 6, 11); 
	    w5 = tmp; 
	    int f5 = (w0 + (w1 + (w3 - 64 + w5) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f5); 
	    A_B8_BIT2(gbf, w5_h, "ARFCN", 1, 3, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w5_l, "ARFCN", 6, 8, buf); 
	    B16_BIT(tmp, 8, 13); 
	    w6 = tmp; 
	    int f6 = (w0 + (w1 - 128 + (w2 + w6) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f6); 
	    A_B8_BIT2(gbf, w6_h, "ARFCN", 1, 5, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
	    A_B8_BIT2(gbf, w6_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 2, 7); 
	    w7 = tmp; 
	    int f7 = (w0 + (w1 + (w3 + w7) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f7); 
	    A_B8_BIT2(gbf, w7, "ARFCN", 2, 7, buf); 
	    B16_BIT(tmp, 5, 9); 
	    w8 = tmp; 
	    int f8 = (w0 + (w1 - 128 + (w2 - 64 + (w4 - 32 + w8 ) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f8); 
	    A_B8_BIT2(gbf, w8_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w8_l, "ARFCN", 5, 8, buf); 
	    B16_BIT(tmp, 9, 12); 
	    w9 = tmp; 
	    int f9 = (w0 + (w1 + (w3 - 64 + (w5 - 32 + w9 ) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f9); 
	    A_B8_BIT2(gbf, w9_h, "ARFCN", 1, 4, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w9_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 3, 7); 
	    w10 = tmp; 
	    int f10 = (w0 + (w1 - 128 + (w2 + (w6 - 32 + w10) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f10); 
	    A_B8_BIT2(gbf, w10, "ARFCN", 3, 7, buf); 
	    B16_BIT(tmp, 6, 10); 
	    w11 = tmp; 
	    int f11 = (w0 + (w1 + (w3 + (w7 - 32 + w11) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f11); 
	    A_B8_BIT2(gbf, w11_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w11_l, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 1, 5); 
	    w12 = tmp; 
	    int f12 = (w0 + (w1 - 128 + (w2 - 64 + (w4 + w12) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f12); 
	    A_B8_BIT2(gbf, w12, "ARFCN", 1, 5, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    B8_BIT(tmp, 4, 8); 
	    w13 = tmp; 
	    int f13 = (w0 + (w1 + (w3 - 64 + (w5 + w13) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f13); 
	    A_B8_BIT2(gbf, w13, "ARFCN", 4, 8, buf); 
	    B16_BIT(tmp, 7, 11); 
	    w14 = tmp; 
	    int f14 = (w0 + (w1 - 128 + (w2 + (w6 + w14) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f14); 
	    A_B8_BIT2(gbf, w14_h, "ARFCN", 1, 3, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w14_l, "ARFCN", 7, 8, buf); 
	    B8_BIT(tmp, 2, 6); 
	    w15 = tmp; 
	    int f15 = (w0 + (w1 + (w3 + (w7 + w15) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f15); 
	    A_B8_BIT2(gbf, w15, "ARFCN", 2, 6, buf); 
	    B16_BIT(tmp, 6, 9); 
	    w16 = tmp; 
	    int f16 = (w0 + (w1 - 128 + (w2 - 64 + (w4 - 32 + (w8 - 16 + w16) % 31) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f16); 
	    A_B8_BIT2(gbf, w16_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w16_l, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 2, 5); 
	    w17 = tmp; 
	    int f17 = (w0 + (w1 + (w3 - 64 + (w5 - 32 + (w9 - 16 + w17) % 31) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f17); 
	    A_B8_BIT2(gbf, w17, "ARFCN", 2, 5, buf); 
	    B16_BIT(tmp, 6, 9); 
	    w18 = tmp; 
	    int f18 = (w0 + (w1 - 128 + (w2 + (w6 - 32 + (w10 - 16 + w18) % 31) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f18); 
	    A_B8_BIT2(gbf, w18_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w18_l, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 2, 5); 
	    w19 = tmp; 
	    int f19 = (w0 + (w1 + (w3 + (w7 - 32 + (w11 - 16 + w19) % 31) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f19); 
	    A_B8_BIT2(gbf, w19, "ARFCN", 2, 5, buf); 
	    B16_BIT(tmp, 6, 9); 
	    w20 = tmp; 
	    int f20 = (w0 + (w1 - 128 + (w2 - 64 + (w4 + (w12 - 16 + w20) % 31) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f20); 
	    A_B8_BIT2(gbf, w20_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w20_l, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 2, 5); 
	    w21 = tmp; 
	    int f21 = (w0 + (w1 + (w3 - 64 + (w5 + (w13 - 16 + w21) % 31) % 63) % 127) % 255) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f21); 
	    A_B8_BIT2(gbf, w21, "ARFCN", 2, 5, buf); 
	    A_B8_BIT1(gbf, spare, "Spare", 1, 1); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
        SKIP(len);
    }

}

void range128_format(len)
{
    char buf[100];
    int tmp = -1;
    int w0, w1, w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17,w18,w19,w20,w21,w22,w23,w24,w25,w26,w27,w28;
	memset(buf, 0x00, sizeof(buf)); 

    if(len > 0)
    {
        B8_HEX(); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "FORMAT = range 128"); 
        //A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 2, 4, "FORMAT = range 128"); 
	    B24_BIT(tmp, 8, 17); 
	    w0 = tmp; 
        //A_B8_BIT2(gbf, orig_arfcn_h, "ARFCN", 1, 1, "-"); 
        A_B8_BIT2(gbf, format_identifier, "Format Identifier", 1, 8, "128 range"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        A_B8_BIT2(gbf, orig_arfcn_m, "ORIG_ARFCN(middle part)", 1, 8, "-"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        sprintf(buf, "ORIG_ARFCN = %d", tmp); 
	    A_B8_BIT2(gbf, orig_arfcn, "ORIG_ARFCN", 8, 8, buf); 
        B8_BIT(tmp, 1, 7); 
	    w1 = tmp; 
	    int f1 = (w0 + w1) % 1024; 
        sprintf(buf, "ARFCN = %d", f1); 
        A_B8_BIT2(gbf, w1, "ARFCN", 1, 7, buf); 
        len -= 1;
	    SKIP(1); 
    }
    if(len > 0)
    {
	    B8_HEX(); 
	    B8_BIT(tmp, 3, 8); 
	    w2 = tmp; 
	    int f2 = (w0 + (w1 - 64 + w2) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f2); 
	    A_B8_BIT2(gbf, w2, "ARFCN", 3, 8, buf); 
	    B16_BIT(tmp, 5, 10); 
	    w3 = tmp; 
	    int f3 = (w0 + (w1 + w3) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f3); 
	    A_B8_BIT2(gbf, w3_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w3_l, "ARFCN", 5, 8, buf); 
	    B16_BIT(tmp, 8, 12); 
	    w4 = tmp; 
	    int f4 = (w0 + (w1 - 64 + (w2 - 32 + w4) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f4); 
	    A_B8_BIT2(gbf, w4_h, "ARFCN", 1, 4, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w4_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 3, 7); 
	    w5 = tmp; 
	    int f5 = (w0 + (w1 + (w3 - 32 + w5) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f5); 
	    A_B8_BIT2(gbf, w5, "ARFCN", 3, 7, buf); 
	    B16_BIT(tmp, 6, 10); 
	    w6 = tmp; 
	    int f6 = (w0 + (w1 - 64 + (w2 + w6) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f6); 
	    A_B8_BIT2(gbf, w6_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w6_l, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 1, 5); 
	    w7 = tmp; 
	    int f7 = (w0 + (w1 + (w3 + w7) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f7); 
	    A_B8_BIT2(gbf, w7, "ARFCN", 1, 5, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
	    B8_BIT(tmp, 5, 8); 
	    w8 = tmp; 
	    int f8 = (w0 + (w1 - 64 + (w2 - 32 + (w4 - 16 + w8 ) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f8); 
	    A_B8_BIT2(gbf, w8, "ARFCN", 5, 8, buf); 
	    B8_BIT(tmp, 1, 4); 
	    w9 = tmp; 
	    int f9 = (w0 + (w1 + (w3 - 32 + (w5 - 16 + w9 ) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f9); 
	    A_B8_BIT2(gbf, w9, "ARFCN", 1, 4, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
	    B8_BIT(tmp, 5, 8); 
	    w10 = tmp; 
	    int f10 = (w0 + (w1 - 64 + (w2 + (w6 - 16 + w10) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f10); 
	    A_B8_BIT2(gbf, w10, "ARFCN", 5, 8, buf); 
	    B8_BIT(tmp, 1, 4); 
	    w11 = tmp; 
	    int f11 = (w0 + (w1 + (w3 + (w7 - 16 + w11) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f11); 
	    A_B8_BIT2(gbf, w11, "ARFCN", 1, 4, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
	    B8_BIT(tmp, 5, 8); 
	    w12 = tmp; 
	    int f12 = (w0 + (w1 - 64 + (w2 - 32 + (w4 + w12) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f12); 
	    A_B8_BIT2(gbf, w12, "ARFCN", 5, 8, buf); 
	    B8_BIT(tmp, 1, 4); 
	    w13 = tmp; 
	    int f13 = (w0 + (w1 + (w3 - 32 + (w5 + w13) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f13); 
	    A_B8_BIT2(gbf, w13, "ARFCN", 1, 4, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
	    B8_BIT(tmp, 5, 8); 
	    w14 = tmp; 
	    int f14 = (w0 + (w1 - 64 + (w2 + (w6 + w14) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f14); 
	    A_B8_BIT2(gbf, w14, "ARFCN", 5, 8, buf); 
	    B8_BIT(tmp, 1, 4); 
	    w15 = tmp; 
	    int f15 = (w0 + (w1 + (w3 + (w7 + w15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f15); 
	    A_B8_BIT2(gbf, w15, "ARFCN", 1, 4, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
        B8_BIT(tmp, 6, 8);
	    w16 = tmp; 
	    int f16 = (w0 + (w1 - 64 + (w2 - 32 + (w4 - 16 + (w8 - 8 + w16) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f16); 
	    A_B8_BIT2(gbf, w16, "ARFCN", 6, 8, buf); 
        B8_BIT(tmp, 3, 5);
	    w17 = tmp; 
	    int f17 = (w0 + (w1 + (w3 - 32 + (w5 - 16 + (w9 - 8 + w17) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f17); 
	    A_B8_BIT2(gbf, w17, "ARFCN", 3, 5, buf); 
	    B16_BIT(tmp, 8, 10); 
	    w18 = tmp; 
	    int f18 = (w0 + (w1 - 64 + (w2 + (w6 - 16 + (w10 - 8 + w18) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f18); 
	    A_B8_BIT2(gbf, w18_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w18_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 5, 7); 
	    w19 = tmp; 
	    int f19 = (w0 + (w1 + (w3 + (w7 - 16 + (w11 - 8 + w19) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f19); 
	    A_B8_BIT2(gbf, w19, "ARFCN", 5, 7, buf); 
	    B8_BIT(tmp, 2, 4); 
	    w20 = tmp; 
	    int f20 = (w0 + (w1 - 64 + (w2 - 32 + (w4 + (w12 - 8 + w20) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f20); 
	    A_B8_BIT2(gbf, w20, "ARFCN", 2, 4, buf); 
	    B16_BIT(tmp, 7, 9); 
	    w21 = tmp; 
	    int f21 = (w0 + (w1 + (w3 - 32 + (w5 + (w13 - 8 + w21) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f21); 
	    A_B8_BIT2(gbf, w21_h, "ARFCN", 1, 1, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w21_l, "ARFCN", 7, 8, buf); 
	    B8_BIT(tmp, 4, 6); 
	    w22 = tmp; 
	    int f22 = (w0 + (w1 - 64 + (w2 + (w6 + (w14 - 8 + w22) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f22); 
	    A_B8_BIT2(gbf, w22, "ARFCN", 4, 6, buf); 
	    B8_BIT(tmp, 1, 3); 
	    w23 = tmp; 
	    int f23 = (w0 + (w1 + (w3 + (w7 + (w15 - 8 + w23) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f23); 
	    A_B8_BIT2(gbf, w23, "ARFCN", 1, 3, buf); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    B8_BIT(tmp, 6, 8); 
	    w24 = tmp; 
	    int f24 = (w0 + (w1 - 64 + (w2 - 32 + (w4 - 16 + (w8 + w24) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f24); 
	    A_B8_BIT2(gbf, w24, "ARFCN", 6, 8, buf); 
	    B8_BIT(tmp, 3, 5); 
	    w25 = tmp; 
	    int f25 = (w0 + (w1 + (w3 - 32 + (w5 - 16 + (w9 + w25) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f25); 
	    A_B8_BIT2(gbf, w25, "ARFCN", 3, 5, buf); 
	    B16_BIT(tmp, 8, 10); 
	    w26 = tmp; 
	    int f26 = (w0 + (w1 - 64 + (w2 + (w6 - 16 + (w10 + w26) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f26); 
	    A_B8_BIT2(gbf, w26_h, "ARFCN", 1, 2, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
	    A_B8_BIT2(gbf, w26_l, "ARFCN", 8, 8, buf); 
	    B8_BIT(tmp, 5, 7); 
	    w17 = tmp; 
	    int f27 = (w0 + (w1 + (w3 + (w7 - 16 + (w11 + w27) % 15) % 31) % 63) % 127) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f27); 
	    A_B8_BIT2(gbf, w27, "ARFCN", 2, 6, buf); 
	    B8_BIT(tmp, 2, 4); 
	    w28 = tmp; 
	    int f28 = (w0 + (w1 - 64 + (w2 - 32 + (w4 + (w12 + w28 % 15) % 31) % 63) % 127)) % 1024; 
	    memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "ARFCN = %d", f28); 
	    A_B8_BIT2(gbf, w28, "ARFCN", 2, 4, buf); 
	    A_B8_BIT1(gbf, spare, "Spare", 1, 1); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
        SKIP(len);
    }

}

void variable_bit_map_format(len)
{
    char buf[100];
    int tmp = -1;
	memset(buf, 0x00, sizeof(buf)); 
    char *p = buf;
    int w0, i, j, k, n, pos = 0;

    if(len > 0)
    {
        B8_HEX(); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 7, 8, "FORMAT = Variable bit map format"); 
        //A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
        //A_B8_BIT2(gbf, format_id, "FORMAT-ID", 2, 4, "FORMAT = Variable bit map format"); 
	    //B24_BIT(tmp, 8, 17); 
	    //w0 = tmp; 
        B8_BIT(tmp, 1, 1);
        pos = sprintf(p, "%d", tmp);
        //dec_to_bin(tmp, p);
        p = p + pos;
        //A_B8_BIT2(gbf, orig_arfcn_h, "ARFCN", 1, 1, "-"); 
        A_B8_BIT2(gbf, format_identifier, "Format Identifier", 1, 8, "variable bit map"); 
        len -= 1;
	    SKIP(1); 
    }
	
    if(len > 0)
    {
	    B8_HEX(); 
        B8_BIT(tmp, 1, 8);
        dec_to_bin(tmp, p);
        p = p + 8;
        A_B8_BIT2(gbf, orig_arfcn_m, "ORIG_ARFCN(middle part)", 1, 8, "-"); 
        len -= 1;
	    SKIP(1); 
    }

    if(len > 0)
    {
	    B8_HEX(); 
        B8_BIT(tmp, 8, 8);
        sprintf(p, "%d", tmp);
        //dec_to_bin(tmp, p);
        tmp = bin_to_dec(buf);
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "ORIG_ARFCN = %d", tmp); 
        //pos += sprintf(p, "ORIG_ARFCN = %d", tmp); 
	    A_B8_BIT2(gbf, orig_arfcn, "ORIG_ARFCN", 8, 8, buf); 
        memset(buf, 0, sizeof(buf));
        p = buf;
        pos = 0;
        memcpy(p, "RRFCN = ", 8);
        p += 8;
        k = 7;
        for(j = 1; j <= 7; j++)
        {
            B8_BIT(tmp, k, k); 
            if(tmp == 1)
            {
                //tmp = (w0 + j) % 1024;
                pos += sprintf(p + pos, "%d ", j);
            }
            k--;
        }
	    A_B8_BIT2(gbf, arfcn, "RRFCN", 1, 7, buf); 
        len -= 1;
	    SKIP(1); 
    }

    for(i = 0; i < len; i++)
    {
	    B8_HEX(); 
        memset(buf, 0, sizeof(buf));
        p = buf;
        pos = 0;
        memcpy(p, "RRFCN = ", 8);
        p += 8;
        k = 8;
        n = j;
        for(j; j <= n+7; j++)
        {
            B8_BIT(tmp, k, k); 
            if(tmp == 1)
            {
                //tmp = (w0 + j) % 1024;
                pos += sprintf(p + pos, "%d ", j);
            }
            k--;
        }
	    A_B8_BIT2(gbf, arfcn, "RRFCN", 1, 8, buf); 
	    SKIP(1); 
    } 
}

void number_digit(int len)
{
    int i, j, tmp = -1;
    char name[128];
    char tmp_h[8];
    char tmp_l[8];
    char buf[100];
    memset(buf, 0, sizeof(buf));
    j = len;

    for(i = 0; i < len - 1; i++)
    {

        memset(name, 0x00, sizeof(name));
        memset(tmp_h, 0x00, sizeof(tmp_h));
        memset(tmp_l, 0x00, sizeof(tmp_l));

        B8_BIT(tmp, 5, 8);
        if(tmp == 0x0F)
        {
            break;
        }

        sprintf(name, "Number digit %d", i * 2 + 2);
        B8_HEX();
        A_B8_BIT2(gbf, number_digit, name, 5, 8, "-");
        if(MYVAR(gbf)->f == 10)
            sprintf(tmp_h, "%s", "*");
        else if(MYVAR(gbf)->f == 11)
            sprintf(tmp_h, "%s", "#");
        else if(MYVAR(gbf)->f == 12)
            sprintf(tmp_h, "%s", "a");
        else if(MYVAR(gbf)->f == 13)
            sprintf(tmp_h, "%s", "b");
        else if(MYVAR(gbf)->f == 14)
            sprintf(tmp_h, "%s", "c");
        else
            sprintf(tmp_h, "%x", MYVAR(gbf)->f);

        memset(name, 0x00, sizeof(name));
        sprintf(name, "Number digit %d", i * 2 + 1);
        A_B8_BIT2(gbf, number_digit, name, 1, 4, "-");
        if(MYVAR(gbf)->f == 10)
            sprintf(tmp_l, "%s", "*");
        else if(MYVAR(gbf)->f == 11)
            sprintf(tmp_l, "%s", "#");
        else if(MYVAR(gbf)->f == 12)
            sprintf(tmp_l, "%s", "a");
        else if(MYVAR(gbf)->f == 13)
            sprintf(tmp_l, "%s", "b");
        else if(MYVAR(gbf)->f == 14)
            sprintf(tmp_l, "%s", "c");
        else
            sprintf(tmp_l, "%x", MYVAR(gbf)->f);

        strcat(buf, tmp_l);
        strcat(buf, tmp_h);
        j -= 1;
        SKIP(1);
    }

    B8_BIT(tmp, 5, 8);
    memset(name, 0x00, sizeof(name));
    memset(tmp_h, 0x00, sizeof(tmp_h));
    memset(tmp_l, 0x00, sizeof(tmp_l));
    sprintf(name, "Number digit %d", i * 2 + 2);
    B8_HEX();
    A_B8_BIT2(gbf, number_digit, name, 5, 8, "-");
    if(MYVAR(gbf)->f == 10)
        sprintf(tmp_h, "%s", "*");
    else if(MYVAR(gbf)->f == 11)
        sprintf(tmp_h, "%s", "#");
    else if(MYVAR(gbf)->f == 12)
        sprintf(tmp_h, "%s", "a");
    else if(MYVAR(gbf)->f == 13)
        sprintf(tmp_h, "%s", "b");
    else if(MYVAR(gbf)->f == 14)
        sprintf(tmp_h, "%s", "c");
    else
        sprintf(tmp_h, "%x", MYVAR(gbf)->f);

    if(tmp != 0x0F)
    {
        sprintf(tmp_h, "%x", MYVAR(gbf)->f);
    }

    memset(name, 0x00, sizeof(name));
    sprintf(name, "Number digit %d", i * 2 + 1);
    B8_BIT(tmp, 1, 4);
    if(tmp == 10)
        sprintf(tmp_l, "%s", "*");
    else if(tmp == 11)
        sprintf(tmp_l, "%s", "#");
    else if(tmp == 12)
        sprintf(tmp_l, "%s", "a");
    else if(tmp == 13)
        sprintf(tmp_l, "%s", "b");
    else if(tmp == 14)
        sprintf(tmp_l, "%s", "c");
    else
        sprintf(tmp_l, "%x", tmp);

    strcat(buf, tmp_l);
    strcat(buf, tmp_h);
    A_B8_BIT2(gbf, number_digit, name, 1, 4, buf);
    j -= 1;
    SKIP(1);

    if(j > 0)
    {
        SKIP(j);
    }
}

void mac(int len)
{
    char buf[100]; 
    char *p = NULL; 
    int i, j, k, tmp; 
    for(i = 0; i < len; i++) 
    {    
        int pos = 0; 
        memset(buf, 0x00, sizeof(buf)); 
        p = buf;
        strcpy(buf, "Mobile Allocation: "); 
        p += 19;  
     
        for(j = 8, k = 0; j >= 1; j--, k++) 
        {    
            B8_BIT(tmp, j, j); 
            if(tmp == 1) 
            {
                pos += sprintf(p+pos, "%d ", (len-i)*8-k); 
            }    
        }
        B8_HEX();
        A_B8_BIT2(gbf, mac, "MAC", 1, 8, buf);
        SKIP(1);
    }
}

void l2_pseudo_length(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("L2 Pseudo Length field", l2_pseudo_l);
	B8_HEX();
    A_B8_BIT1(gbf, l2_pseudo_length, "L2 Pseudo Length", 1, 8);
    SKIP(1);
    END_ELEMENT();
}

void si_pd() {
	BEGIN_ELEMENT("SI+PD field", sp_id_ele);
    int tmp = -1;
    B8_BIT(tmp, 1, 4);
	B8_HEX();
    if(tmp == 6 || tmp == 5 || tmp == 8)
        A_B8_BIT1(gbf, si, "Skip Indicator", 5, 8);
    else if(tmp == 3 || tmp == 10)
        A_B8_BIT1(gbf, si, "Transaction Identifier", 5, 8);
    if(tmp == 3 || tmp == 5 || tmp == 6 || tmp == 8 || tmp == 10)
        A_B8_BIT3(gbf, pd, "Protocol Discriminator", 1, 4, protocol_discriminator_);
    else
        A_B8_BIT2(gbf, pd, "Protocol Discriminator", 1, 4, "Unkonwn");
    SKIP(1);
    END_ELEMENT();
}

void msg_type(uint8_t pd)
{ 
    BEGIN_ELEMENT("Message Type Field",  msg_type_sec);
    B8_HEX();
    if(pd == 0)
        A_B8_BIT3(gbf, msg_type, "Message Type", 1, 8, message_type_mm);
    else if(pd == 1)
        A_B8_BIT3(gbf, msg_type, "Message Type", 1, 8, message_type_rr);
    else if(pd == 2)
        A_B8_BIT3(gbf, msg_type, "Message Type", 1, 8, message_type_cc);
    else if(pd == 3)
        A_B8_BIT3(gbf, msg_type, "Message Type", 1, 8, message_type_gmm);
    else if(pd == 4)
        A_B8_BIT3(gbf, msg_type, "Message Type", 1, 8, message_type_sm);
    else
        A_B8_BIT2(gbf, msg_type, "Message Type", 1, 8, "Unknown");
    SKIP(1);
    END_ELEMENT();
}

void cm_service_type(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("CM service type", cm_service_type );
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT3(gbf, service_type, "Service Type", 1, 4, cm_service_type_service_type);
			SKIP(1);
		}
		else
		{
			B8_HEX(); 
			A_B8_BIT3(gbf, service_type, "Service Type", 5, 8, cm_service_type_service_type);
		}
	}
	else
	{
		B8_HEX(); 
		A_B8_BIT2(gbf, cm_service_type_iei, "CM service type IEI", 5, 8,"CM service type");
		A_B8_BIT3(gbf, service_type, "Service Type", 1, 4, cm_service_type_service_type);
		SKIP(1);
	}
    END_ELEMENT();
}

void key_sequence(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Ciphering key sequence number", ciphering_key_sequence_number );
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT1(gbf, spare, "Spare", 4, 4);
			A_B8_BIT3(gbf, key_seq, "Key sequence", 1, 3, ciphering_key_s_key_sequence);
			SKIP(1);
		}
		else
		{
			B8_HEX(); 
			A_B8_BIT1(gbf, spare, "Spare", 8, 8);
			A_B8_BIT3(gbf, key_seq, "Key sequence", 5, 7, ciphering_key_s_key_sequence);
		}
	}
	else
	{
		B8_HEX(); 
		A_B8_BIT2(gbf, ciphering_key_iei, "Ciphering Key Sequence Number IEI", 5, 8,"Ciphering Key Sequence Number");
    	A_B8_BIT1(gbf, spare1, "Spare", 4, 4);
    	A_B8_BIT3(gbf, key_seq, "Key sequence", 1, 3, ciphering_key_s_key_sequence);
    	SKIP(1);
	}
    END_ELEMENT();
}


void mobile_station(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Mobile station classmark 2", mobile_station_c);
	if(iei == 1)
	{
		B8_HEX();
		A_B8_BIT2(gbf, mobile_station_iei, "Mobile station classmark 2 IEI", 1, 8,"Mobile station classmark 2");
		SKIP(1);
	}


    if(location == 1)
    {
        B8_HEX();
        A_B8_BIT1(gbf, length, "Length of mobile station classmark 2 contents", 1, 8);
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, spare2, "spare", 8, 8);
    A_B8_BIT3(gbf, revision, "Revision level", 6, 7, mobile_station_revision_level);
    A_B8_BIT3(gbf, es ,"ES IND", 5, 5, mobile_station_es_ind);
    A_B8_BIT3(gbf, A5_1 ,"A5/1 algorithm", 4, 4, mobile_station_A51_algorithm_s);
    A_B8_BIT3(gbf, rf ,"RF Power Capability", 1, 3, mobile_station_rf_power_c);  
    SKIP(1);
    B8_HEX();
    A_B8_BIT1(gbf, spare3 ,"spare", 8, 8);
    A_B8_BIT3(gbf, ps_capa ,"PS capability", 7, 7, mobile_station_ps_capability);
    A_B8_BIT1(gbf, ss_screen ,"SS Screening Indicator", 5, 6);
    A_B8_BIT3(gbf, smcapabi ,"SM capability", 4, 4, mobile_station_sm_capability);
    A_B8_BIT3(gbf, vbs ,"VBS notification reception", 3, 3, mobile_station_vbs_notification_r);
    A_B8_BIT3(gbf, vgcs ,"VGCS notification reception", 2, 2, mobile_station_vgcs_notification_r);
    A_B8_BIT3(gbf, fc ,"FC", 1, 1, mobile_station_fc_frequency_c);
    SKIP(1);
    B8_HEX();
    A_B8_BIT3(gbf, cm3 ,"CM3", 8, 8, mobile_station_cm3);
    A_B8_BIT1(gbf, spare4 ,"spare", 7, 7);
    A_B8_BIT3(gbf, LCSVACAP ,"LCS VA capability", 6, 6, mobile_station_lcs_va_c);
    A_B8_BIT3(gbf, UCS2 ,"UCS2 treatment", 5, 5, mobile_station_ucs2_treatment);
    A_B8_BIT3(gbf, SoLSA ,"SoLSA", 4, 4, mobile_station_solsa);
    A_B8_BIT3(gbf, CMSP ,"CMSP", 3, 3, mobile_station_cmsp);
    A_B8_BIT3(gbf, A5_3 ,"A5/3 algorithm surported", 2, 2, mobile_station_A53_algorithm_s);
    A_B8_BIT3(gbf, A5_2 ,"A5/2 algorithm surported", 1, 1, mobile_station_a52_algorithm_s);
    SKIP(1);
    END_ELEMENT();
}

int mobile_identity(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Mobile identity", mobile_identity);
	int ele_len = 0;
	if(iei == 1)
	{
		B8_HEX();
		A_B8_BIT2(gbf, mobile_identity_iei, "Mobile Identity IEI", 1, 8, "Mobile Identity");
		SKIP(1);
		ele_len += 1;
	}

    SKIP(1);
	int type = -1;
    B8_BIT(type, 1, 3);
    BACK(1);

    if (type == 5)
    {

            char mcc_buf[16*1024];
            char mnc_buf[16*1024];
            uint8_t mnc1;
            uint8_t mnc2;
            uint8_t mnc3;
            uint8_t mcc1;
            uint8_t mcc2;
            uint8_t mcc3;
            uint16_t mcc;
            uint16_t mnc;
            int tmp;

			B8_BIT(tmp, 1, 8);
			ele_len += tmp + 1;
            B8_HEX();
            A_B8_BIT1(gbf, length ,"Length of mobile identity contents", 1, 8);
            SKIP(1);
            
            B8_HEX();
            A_B8_BIT1(gbf, spare ,"Spare", 7, 8);
            A_B8_BIT3(gbf, mbms_sessid_indic ,"MBMS Session Identity indication", 6, 6, mobile_identity_mbms_session_i_i);
            A_B8_BIT3(gbf, mcc_mnc_i ,"MCC/MNC indication", 6, 6, mobile_identity_mcc_mnc_i);
            A_B8_BIT3(gbf, odd_even_indic ,"odd/even indic", 4, 4, mobile_identity_odd_even_i);
            
			tmp = 0;
            B8_BIT(tmp, 1, 3);
            if(tmp >=0 && tmp <=5)
                A_B8_BIT3(gbf, Type_identity ,"Type of identity", 1, 3, mobile_identity_type_identity);
            else
                A_B8_BIT2(gbf, Type_identity ,"Type of identity", 1, 3, "reserved");
            SKIP(1);

            B8_HEX();
            SKIP(3);

            B8_BIT(mcc2, 5, 8);
            B8_BIT(mcc1, 1, 4);
            SKIP(1);
            B8_BIT(mnc3, 5, 8);
            B8_BIT(mcc3, 1, 4);
            SKIP(1);
            B8_BIT(mnc2, 5, 8);
            B8_BIT(mnc1, 1, 4);
            mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
            sprintf(mcc_buf, "MCC = %d", mcc);
            mnc = 100 * mnc1 + 10 * mnc2 + mnc3;
            sprintf(mnc_buf, "MNC = %d", mnc);
            BACK(2);

            B8_HEX();
            A_B8_BIT2(gbf, mcc_digit2 ,"MCC digit 2", 5, 8, "-");
            A_B8_BIT2(gbf, mcc_digit1 ,"MCC digit 1", 1, 4, "-");
            SKIP(1);
            
            B8_HEX();
            A_B8_BIT2(gbf, mnc_digit3 ,"MNC digit 3", 5, 8, mnc_buf);
            A_B8_BIT2(gbf, mcc_digit3 ,"MCC digit 3", 1, 4, mcc_buf);
            SKIP(1);

            B8_HEX();
            A_B8_BIT2(gbf, mnc_digit2 ,"MNC digit 2", 5, 8, "-");
            A_B8_BIT2(gbf, mnc_digit1 ,"MNC digit 1", 1, 4, "-");
            SKIP(1);

            B8_HEX();
            A_B8_BIT1(gbf, mbms_session_i ,"MBMS Session Identity", 1, 8);
            SKIP(1);
    }
    else  
    {
        char buf[16*1024];
        memset(buf, 0x00, sizeof(buf));

        uint8_t len;
		uint8_t i;
        B8_BIT(len, 1, 8);
		ele_len += len + 1;
        len = len - 1;
        B8_HEX();
        A_B8_BIT1(gbf, length ,"Length of mobile identity contents", 1, 8);
        SKIP(1);

        B8_HEX();
        A_B8_BIT2(gbf, identity_digit1 ,"Identity digit 1", 5, 8, "-");
        //sprintf(buf, "Identity = %x", MYVAR(gbf)->f);
        sprintf(buf, "%x", MYVAR(gbf)->f);
        A_B8_BIT3(gbf, odd_even_indic ,"odd/even indic", 4, 4, mobile_identity_odd_even_i);
        int tmp;
        B8_BIT(tmp, 1, 3);
        if(tmp >=0 && tmp <=5)
            A_B8_BIT3(gbf, Type_identity ,"Type of identity", 1, 3, mobile_identity_type_identity);
        else
            A_B8_BIT2(gbf, Type_identity ,"Type of identity", 1, 3, "reserved");
        if(tmp != 1 && tmp != 2 && tmp != 3 )
        {     
            memset(buf, 0x00, sizeof(buf));
        }  
        SKIP(1);

        char name[128];
        char tmp_h[8];
        char tmp_l[8];

        for(i = 0; i < len - 1; i++)
        {

            memset(name, 0x00, sizeof(name));
            memset(tmp_h, 0x00, sizeof(tmp_h));
            memset(tmp_l, 0x00, sizeof(tmp_l));
            sprintf(name, "Identity digit %d", i * 2 + 3);
            B8_HEX();
            A_B8_BIT2(gbf, identity_digit, name, 5, 8, "-");
            sprintf(tmp_h, "%x", MYVAR(gbf)->f);

            memset(name, 0x00, sizeof(name));
            sprintf(name, "Identity digit %d", i * 2 + 2);
            A_B8_BIT2(gbf, identity_digit, name, 1, 4, "-");
            sprintf(tmp_l, "%x", MYVAR(gbf)->f);
            strcat(buf, tmp_l);
            strcat(buf, tmp_h);
            SKIP(1);
        }

            memset(name, 0x00, sizeof(name));
            memset(tmp_h, 0x00, sizeof(tmp_h));
            memset(tmp_l, 0x00, sizeof(tmp_l));
            sprintf(name, "Identity digit %d", i * 2 + 3);
            B8_HEX();
            A_B8_BIT2(gbf, identity_digit, name, 5, 8, "-");
            sprintf(tmp_h, "%x", MYVAR(gbf)->f);

            memset(name, 0x00, sizeof(name));
            sprintf(name, "Identity digit %d", i * 2 + 2);
            B8_BIT(type, 1, 4);
            sprintf(tmp_l, "%x", type);
            strcat(buf, tmp_l);
            strcat(buf, tmp_h);
            A_B8_BIT2(gbf, identity_digit, name, 1, 4, buf);
            SKIP(1);
    }
    END_ELEMENT();
	return ele_len;
}

void priority_level(uint8_t iei, uint8_t location) 
{
	BEGIN_ELEMENT("Priority Level", priority_level);
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT1(gbf, spare5 ,"spare", 4, 4);
			A_B8_BIT3(gbf, call_pri ,"Call priority", 1, 3, priority_level_call_priority);
			SKIP(1);
		}
		else
		{
			B8_HEX();
			A_B8_BIT1(gbf, spare5 ,"spare", 8, 8);
			A_B8_BIT3(gbf, call_pri ,"Call priority", 5, 7, priority_level_call_priority);
		}
	}
	else
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei ,"Priority Level IEI", 5, 8,"Priority Level");
        A_B8_BIT1(gbf, spare5 ,"spare", 4, 4);
        A_B8_BIT3(gbf, call_pri ,"Call priority", 1, 3, priority_level_call_priority);
        SKIP(1);
    }
    END_ELEMENT();
}

void additional_param(uint8_t iei, uint8_t location) 
{
	BEGIN_ELEMENT("Additional update parameters", additional_update_p);
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT1(gbf, spare7 ,"spare", 4, 4);
        	A_B8_BIT1(gbf, spare8 ,"spare", 3, 3);
        	A_B8_BIT3(gbf, CSMO ,"CSMO", 2, 2, additional_update_p_csmo);
        	A_B8_BIT3(gbf, CSMT ,"CSMT", 1, 1, additional_update_p_csmt);
        	SKIP(1);
		}
		else
		{
			B8_HEX();
			A_B8_BIT1(gbf, spare7 ,"spare", 8, 8);
        	A_B8_BIT1(gbf, spare8 ,"spare", 7, 7);
        	A_B8_BIT3(gbf, CSMO ,"CSMO", 6, 6, additional_update_p_csmo);
        	A_B8_BIT3(gbf, CSMT ,"CSMT", 5, 5, additional_update_p_csmt);
		}
	}
	else
	{
		B8_HEX();
    	A_B8_BIT2(gbf, additional_ipdate_iei ,"Additional update parameters IEI", 5, 8,"Additional update parameters");
    	A_B8_BIT1(gbf, spare7 ,"spare", 4, 4);
    	A_B8_BIT1(gbf, spare8 ,"spare", 3, 3);
    	A_B8_BIT3(gbf, CSMO ,"CSMO", 2, 2, additional_update_p_csmo);
    	A_B8_BIT3(gbf, CSMT ,"CSMT", 1, 1, additional_update_p_csmt);
    	SKIP(1);
	}

    END_ELEMENT();
}

void device_properties(uint8_t iei, uint8_t location) 
{
	BEGIN_ELEMENT("Device properties", device_properties);
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT1(gbf, spare9, "spare", 4, 4);
        	A_B8_BIT1(gbf, spare10, "spare", 3, 3);
        	A_B8_BIT1(gbf, spare11, "spare", 2, 2);
        	A_B8_BIT3(gbf, low_priority, "Low priority", 1, 1, device_properties_low_priority);
        	SKIP(1);
		}
		else
		{
			B8_HEX();
			A_B8_BIT1(gbf, spare9, "spare", 8, 8);
        	A_B8_BIT1(gbf, spare10, "spare", 7, 7);
        	A_B8_BIT1(gbf, spare11, "spare", 6, 6);
        	A_B8_BIT3(gbf, low_priority, "Low priority", 5, 5, device_properties_low_priority);
		}
	}
	else
    {
		B8_HEX();
        A_B8_BIT2(gbf, iei3, "Device properties IEI", 5, 8,"Device properties");
        A_B8_BIT1(gbf, spare9, "spare", 4, 4);
        A_B8_BIT1(gbf, spare10, "spare", 3, 3);
        A_B8_BIT1(gbf, spare11, "spare", 2, 2);
        A_B8_BIT3(gbf, low_priority, "Low priority", 1, 1, device_properties_low_priority);
        SKIP(1);
    }
    END_ELEMENT();
}

void page_mode(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("PAGE MODE", page_mode); 
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "SPARE", 3, 4); 
            A_B8_BIT3(gbf, pm, "PM", 1, 2, page_mode_pm); 
            SKIP(1);
        }
        else
        {
            B8_HEX(); 
            A_B8_BIT1(gbf, spare, "SPARE", 7, 8); 
            A_B8_BIT3(gbf, pm, "PM", 5, 6, page_mode_pm); 
        }
    }
    else
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, page_mode_iei, "Page Mode IEI", 5, 8,"Page Mode"); 
        A_B8_BIT1(gbf, spare, "SPARE", 3, 4); 
        A_B8_BIT3(gbf, pm, "PM", 1, 2, page_mode_pm); 
        SKIP(1);
    }
    END_ELEMENT(); 
}

void dedicated_mode_or_tbf(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Dedicated mode or TBF", dedicated_mode_or_tbf); 
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "SPARE", 4, 4); 
            A_B8_BIT3(gbf, dedicated_mode_tbf, "Dedicated mode or TBF", 1, 3, immediate_assignment_dedicated_mode_or_tbf); 
            SKIP(1); 
        }
        else
        {
            B8_HEX(); 
            A_B8_BIT1(gbf, spare, "SPARE", 4, 4); 
            A_B8_BIT3(gbf, dedicated_mode_tbf, "Dedicated mode or TBF", 1, 3, immediate_assignment_dedicated_mode_or_tbf); 
        }
    }
    else
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, page_mode_iei, "Dedicated mode or TBF IEI", 5, 8,"Dedicated mode or TBF"); 
        A_B8_BIT1(gbf, spare, "SPARE", 4, 4); 
        A_B8_BIT3(gbf, dedicated_mode_tbf, "Dedicated mode or TBF", 1, 3, immediate_assignment_dedicated_mode_or_tbf); 
        SKIP(1); 
    }
    END_ELEMENT(); 
}

int channel_description(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Channel Description", channel_description); 
    if(iei == 1)
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Channel Description IEI", 1, 8, "Channel Description"); 
        SKIP(1); 
    }

    uint8_t tn;
    B8_HEX(); 
    int tmp;
    B8_BIT(tmp, 4, 8);
    if(tmp > 0 && tmp < 16)
        A_B8_BIT3(gbf, channel_type_a_t_o, "Channel type and TDMA offset", 4, 8, channel_description_channel_type_t_o); 
    else
        A_B8_BIT2(gbf, channel_type_a_t_o, "Channel type and TDMA offset", 4, 8, "reserved"); 
    B8_BIT(tn, 1, 3);
    A_B8_BIT1(gbf, tn, "TN", 1, 3); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, tsc, "TSC", 6, 8); 
    int type = -1;
    B8_BIT(type, 5, 5); 
    A_B8_BIT3(gbf, hopping_channel, "Hopping channel", 5, 5, channel_description_h); 
    char buf[12]; 
    memset(buf, 0x00, sizeof(buf)); 
    if (type == 0) 
    { 

		B16_BIT(type, 1, 10); 
        A_B8_BIT1(gbf, spare, "Spare", 3, 4); 
        A_B8_BIT2(gbf, arfcn_h, "ARFCH (high part)", 1, 2, "-"); 
        SKIP(1); 

        B8_HEX(); 
        sprintf(buf, "ARFCH=%d", type); 
        A_B8_BIT2(gbf, arfcn_l, "ARFCH (low part)", 1, 8, buf); 
        SKIP(1); 
    } 
    else 
    { 
        B16_BIT(type, 7, 12); 
        A_B8_BIT2(gbf, maio_h, "MAIO (high part)", 1, 4, "-"); 
        SKIP(1); 

        B8_HEX(); 
        sprintf(buf, "MAIO=%d", type); 
        A_B8_BIT2(gbf, arfcn_l, "MAIO (low part)", 7, 8, buf); 
        A_B8_BIT1(gbf, arfcn_l, "HSN", 1, 6); 
	    SKIP(1); 
    } 

    END_ELEMENT(); 

    return tn;
}

void request_reference(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Request Reference", request_reference); 
    if(iei == 1)
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, request_reference_iei, "Request Reference IEI", 1, 8, "Request Reference"); 
        SKIP(1); 
    }
    B8_HEX(); 
    A_B8_BIT1(gbf, ra, "Random Access Information", 1, 8); 
    SKIP(1); 
    
    char buf[10] = {0}; 
    uint8_t t3; 
    B16_BIT(t3, 6, 11); 
    sprintf(buf, "T3=%d", t3); 
    B8_HEX(); 
    A_B8_BIT1(gbf, t1, "T1", 4, 8); 
    A_B8_BIT2(gbf, t3_h, "T3(high part)", 1, 3, "-"); 
	SKIP(1); 
    
    B8_HEX(); 
    A_B8_BIT2(gbf, t3_h, "T3(high part)", 6, 8, buf); 
    A_B8_BIT1(gbf, t2, "T2", 1, 5); 
    SKIP(1); 
    END_ELEMENT(); 
}

void timing_advance(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Timing Advance", timing_advance); 
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Timing Advance IEI", 1, 8, "Timing Advance"); 
        SKIP(1); 
    }
	B8_HEX(); 
    A_B8_BIT1(gbf, timing_advance_value, "Timing advance value", 1, 8); 

    SKIP(1); 
    END_ELEMENT(); 
}

void mobile_allocation(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Mobile Allocation", mobile_allocation); 
    if(iei) 
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Mobile Allocation IEI", 1, 8, "Mobile Allocation"); 
        SKIP(1); 
    }    
    
    int len; 
    B8_HEX(); 
    B8_BIT(len, 1, 8);  
    A_B8_BIT1(gbf, length, "Length of mobile allocation contents", 1, 8);  
    SKIP(1); 

    mac(len);
    
    END_ELEMENT();
}

void starting_time(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Starting Time", starting_time); 
    if(iei == 1)
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, starting_timing_iei, "Starting Timing IEI", 1, 8, "Starting Timing"); 
        SKIP(1); 
    }

    char buf[10] = {0}; 
    uint8_t t3; 
	B16_BIT(t3, 6, 11); 
    sprintf(buf, "T3=%d", t3); 
    B8_HEX(); 
    A_B8_BIT1(gbf, t1, "T1", 4, 8); 
    A_B8_BIT2(gbf, t3_h, "T3(high part)", 1, 3, "-"); 
    SKIP(1); 
    
    B8_HEX(); 
    A_B8_BIT2(gbf, t3_h, "T3(low part)", 6, 8, buf); 
    A_B8_BIT1(gbf, t2, "T2", 1, 5); 
    SKIP(1); 
    END_ELEMENT(); 
}

void spare_half_octet(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Spare Half Octet", spare_half_octet );
	B8_HEX(); 
    A_B8_BIT1(gbf, spare_half_octet, "Spare Half Octet", 5, 8);
    END_ELEMENT();
}

void authentication_parameter_r(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Authentication parameter RAND", authentication_parameter_r); 
    if(iei == 1) 
    { 
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Authentication parameter RAND IEI", 1, 8, "Authentication parameter RAND"); 
        SKIP(1); 
    } 
    char buf[50] = {0};
    int i;
    int pos = 0;
    int tmp = -1;
    for(i = 1; i < 16; i++) 
    {
        B8_BIT(tmp, 1, 8);
        pos += sprintf((char *)buf + pos, "%02x", tmp);
        B8_HEX(); 
        //A_B8_BIT1(gbf, rand_value, "RAND value", 1, 8); 
        A_B8_BIT2(gbf, rand_value, "RAND value", 1, 8, "-"); 
        SKIP(1); 
    }
    B8_BIT(tmp, 1, 8);
    sprintf((char *)buf + pos, "%02x", tmp);
    B8_HEX(); 
    A_B8_BIT2(gbf, rand_value, "RAND value", 1, 8, buf); 
    SKIP(1); 

    END_ELEMENT(); 
}

void authentication_parameter_a(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Authentication Parameter AUTN", authentication_parameter_a); 
    if(iei == 1) 
    { 
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Authentication parameter AUTN IEI", 1, 8, "Authentication parameter AUTN"); 
        SKIP(1); 
    } 
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of AUTN contents", 1, 8); 
    SKIP(1); 
    
    int i;
    for(i = 0; i < 17; i++) 
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, autn_value, "AUTN value", 1, 8); 
        SKIP(1); 
    }

    END_ELEMENT(); 
}

void auth_response_parameter(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Authentication Response parameter", authentication_response_p); 
    if(iei == 1) 
    { 
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Authentication Response parameter IEI", 1, 8, "Authentication Response parameter"); 
        SKIP(1); 
    } 
    int i;
    for(i = 0; i < 4; i++)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, sres_value, "SRES value", 1, 8); 
        SKIP(1); 
    }

    END_ELEMENT(); 
}
 
void auth_response_parameter_ext(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Authentication Response parameter (extension)", authentication_response_p_ext); 
    if(iei == 1) 
    { 
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Authentication Response (extension) IEI", 1, 8, "Authentication Response (extension)"); 
        SKIP(1); 
    } 
    int len = 0;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Authentication Response contents", 1, 8); 
    SKIP(1); 

    if(len < 5)
    {
        int i;
        for(i = 0; i < len; i++)
        {
            B8_HEX(); 
            A_B8_BIT1(gbf, sres_value, "SRES value", 1, 8); 
            SKIP(1); 
        }
    }

    END_ELEMENT(); 
}

void location_area_identification(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Location Area Identification", location_area_i); 
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Location Area Identification IEI", 1, 8, "Location Area Identification"); 
        SKIP(1); 
    } 
    char mcc_buf[16*1024] = {0}; 
    char mnc_buf[16*1024] = {0}; 
	char buf[10] = {0}; 
    uint8_t mnc1; 
    uint8_t mnc2; 
    uint8_t mnc3; 
    uint8_t mcc1; 
    uint8_t mcc2; 
    uint8_t mcc3; 
    uint16_t mcc; 
    uint16_t mnc; 
    uint16_t tmp; 

    B8_BIT(mcc1, 1, 4); 
    B8_BIT(mcc2, 5, 8); 
    SKIP(1); 
    B8_BIT(mnc3, 5, 8); 
    B8_BIT(mcc3, 1, 4); 
    SKIP(1); 
    B8_BIT(mnc2, 5, 8); 
    B8_BIT(mnc1, 1, 4); 
    mcc = 100 * mcc1 + 10 * mcc2 + mcc3; 
    sprintf(mcc_buf, "MCC = %d", mcc); 
    mnc = 100 * mnc1 + 10 * mnc2 + mnc3; 
    sprintf(mnc_buf, "MNC = %d", mnc); 
    BACK(2); 

    B8_HEX(); 
    A_B8_BIT2(gbf, mcc_digit2 ,"MCC digit 2", 5, 8, "-"); 
    A_B8_BIT2(gbf, mcc_digit1 ,"MCC digit 1", 1, 4, "-"); 
    SKIP(1); 
    
    B8_HEX(); 
    A_B8_BIT2(gbf, mnc_digit3 ,"MNC digit 3", 5, 8, "-"); 
    A_B8_BIT2(gbf, mcc_digit3 ,"MCC digit 3", 1, 4, mcc_buf); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT2(gbf, mnc_digit2 ,"MNC digit 2", 5, 8, "-"); 
    A_B8_BIT2(gbf, mnc_digit1 ,"MNC digit 1", 1, 4, mnc_buf); 
    SKIP(1); 

    B8_HEX(); 
	B16_BIT(tmp, 1, 16); 
	sprintf(buf, "LAC=%d", tmp); 
    A_B8_BIT1(gbf, lac ,"LAC", 1, 8); 
    SKIP(1); 
    B8_HEX(); 
    A_B8_BIT2(gbf, lac_c ,"LAC (continued)", 1, 8, buf); 
    SKIP(1); 

    END_ELEMENT(); 
}

void cipher_mode_setting(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Cipher Mode Setting", cipher_mode_s); 

    int type = -1;
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, ciph_mod_set_iei, "Ciph Mod Set IEI", 5, 8, "Ciph Mod Set IEI");
        B8_BIT(type, 1, 1);
        if(type == 0)
        {
            A_B8_BIT1(gbf, spare, "Spare", 2, 4);
        }
        else
        {
            A_B8_BIT3(gbf, algorithm_identifier, "Algorithm identifier", 2, 4, cipher_mode_s_algorithm_identifier);
        }
        A_B8_BIT3(gbf, sc, "SC", 1, 1, cipher_mode_s_sc);
        SKIP(1);
    }
    else
    {
        if(location == 1)
        {
            B8_BIT(type, 1, 1);  
            if(type == 0) 
            {    
                A_B8_BIT1(gbf, spare, "Spare", 2, 4); 
            }    
            else 
            {    
                A_B8_BIT3(gbf, algorithm_identifier, "Algorithm identifier", 2, 4, cipher_mode_s_algorithm_identifier); 
            }    
            A_B8_BIT3(gbf, sc, "SC", 1, 1, cipher_mode_s_sc);  
            SKIP(1);
        }
        else
        {
            B8_HEX(); 
            B8_BIT(type, 5, 5);  
            if(type == 0) 
            {    
                A_B8_BIT1(gbf, spare, "Spare", 6, 8); 
            }    
            else 
            {    
                A_B8_BIT3(gbf, algorithm_identifier, "Algorithm identifier", 6, 8, cipher_mode_s_algorithm_identifier); 
            }    
            A_B8_BIT3(gbf, sc, "SC", 5, 5, cipher_mode_s_sc);  
        }    
    }

    END_ELEMENT();
}

void cipher_response(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Cipher Response", cipher_response); 

    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, ciph_mod_set_iei, "Cipher Resp. IEI", 5, 8, "Cipher Resp");
        A_B8_BIT1(gbf, spare, "Spare", 2, 4);
        A_B8_BIT3(gbf, cr, "CR", 1, 1, cipher_response_cr_c_r); 
        SKIP(1);
    }
    else
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "Spare", 2, 4);
            A_B8_BIT3(gbf, cr, "CR", 1, 1, cipher_response_cr_c_r); 
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "Spare", 6, 8);
            A_B8_BIT3(gbf, cr, "CR", 5, 5, cipher_response_cr_c_r); 
        }
    }

    END_ELEMENT();
}

void repeat_indicator(uint8_t iei, uint8_t location) 
{     
    BEGIN_ELEMENT("Repeat indicator", repeat_indicator); 
    int tmp = -1;
    if(iei == 1) 
    {    
        B8_BIT(tmp, 1, 4);
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Repeat indicator IEI", 5, 8, "Repeat indicator");  
        if(tmp > 0 && tmp < 5)
            A_B8_BIT3(gbf, repeat_indicator, "Repeat indicator", 1, 4, repeat_indicator_repeat_indication); 
        else
            A_B8_BIT2(gbf, repeat_indicator, "Repeat indicator", 1, 4, "reserved"); 
        SKIP(1);
    }    
    else 
    {
        if(location == 1) 
        {    
            B8_BIT(tmp, 1, 4);
            if(tmp > 0 && tmp < 5)
                A_B8_BIT3(gbf, repeat_indicator, "Repeat indicator", 1, 4, repeat_indicator_repeat_indication); 
            else
                A_B8_BIT2(gbf, repeat_indicator, "Repeat indicator", 1, 4, "reserved"); 
            SKIP(1);
        }    
        else 
        {    
            B8_BIT(tmp, 5, 8);
            B8_HEX(); 
            if(tmp > 0 && tmp < 5)
                A_B8_BIT3(gbf, repeat_indicator, "Repeat indicator", 5, 8, repeat_indicator_repeat_indication); 
            else
                A_B8_BIT2(gbf, repeat_indicator, "Repeat indicator", 5, 8, "reserved"); 
        }
    }

    END_ELEMENT(); 
}
#if 1 
void bearer_capability(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Bearer capability", bearer_capability); 
	int tmp; 
	uint8_t ext = 1; 
	int length; 
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Bearer capability IEI", 1, 8, "Bearer capability"); 
        SKIP(1); 
    } 
	B8_BIT(length, 1, 8); 
	B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of the bearer capability contents", 1, 8); 
    SKIP(1); 
	
	B8_HEX(); 
	B8_BIT(ext, 8, 8); 
    A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
    A_B8_BIT3(gbf, radio_channel_r, "Radio channel requirement", 6, 7, bearer_capability_radio_channel_r); 
    A_B8_BIT3(gbf, coding_standard, "Coding standard", 5, 5, bearer_capability_coding_standard); 
    A_B8_BIT3(gbf, transfer_mode, "Transfer mode", 4, 4, bearer_capability_transfer_mode); 
    A_B8_BIT3(gbf, information_transfer_c, "Information transfer capability", 1, 3, bearer_capability_information_transfer_c); 
	length -= 1; 
    SKIP(1); 
	
	if(ext == 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 2; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, coding, "Coding", 7, 7, bearer_capability_coding); 
		A_B8_BIT3(gbf, ctm, "CTM", 6, 6, bearer_capability_ctm_text_t_i); 
		A_B8_BIT1(gbf, spare, "Spare", 5, 5); 
		A_B8_BIT3(gbf, speech_version_i, "Speech version indication", 1, 4, bearer_capability_speech_version_i); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(ext == 2) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, coding, "Coding", 7, 7, bearer_capability_coding); 
		A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
		A_B8_BIT3(gbf, speech_version_i, "Speech version indication", 1, 4, bearer_capability_speech_version_i); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(length > 0) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, compression, "Compression", 7, 7, bearer_capability_compression_n_m); 
		A_B8_BIT3(gbf, structure, "Structure", 5, 6, bearer_capability_structure); 
		A_B8_BIT3(gbf, duplex_mode, "Duplex mode", 4, 4, bearer_capability_duplex_mode); 
		A_B8_BIT3(gbf, configuration, "Configuration", 3, 3, bearer_capability_configuration); 
		A_B8_BIT3(gbf, nirr, "NIRR ", 2, 2, bearer_capability_nirr); 
		A_B8_BIT3(gbf, establishment, "Establishment", 1, 1, bearer_capability_establishment); 
		length -= 1; 
		SKIP(1); 
	}
	if(length > 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 3; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, access_identity, "Access identity", 6, 7, bearer_capability_access_identity); 
		A_B8_BIT3(gbf, rate_adaption, "Rate adaption", 4, 5, bearer_capability_rate_adaption); 
		A_B8_BIT3(gbf, signalling_access_p, "Signalling access protocol", 1, 3, bearer_capability_signalling_access_p); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(ext == 3) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 4; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, other_itc, "Other ITC", 6, 7, bearer_capability_other_itc); 
		A_B8_BIT3(gbf, other_rate_adaption, "Other rate adaption", 4, 5, bearer_capability_other_rate_a); 
		A_B8_BIT1(gbf, spare, "Spare", 1, 3); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(ext == 4) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, hdr_nohde, "Hdr/noHdr", 7, 7, bearer_capability_rate_adaption_h); 
		A_B8_BIT3(gbf, multiframe, "Multiframe", 6, 6, bearer_capability_multiple_frame_e); 
		A_B8_BIT3(gbf, mode, "Mode", 5, 5, bearer_capability_mode_operation); 
		A_B8_BIT3(gbf, lli, "LLI", 4, 4, bearer_capability_logical_link_i); 
		A_B8_BIT3(gbf, assignor_e, "Assignor/e", 3, 3, bearer_capability_assignor_assignee); 
		A_B8_BIT3(gbf, inb_neg, "Inb.neg", 2, 2, bearer_capability_inout_negotiation); 
		A_B8_BIT1(gbf, spare, "Spare", 1, 1); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(length > 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 5; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 6, 7); 
		if(tmp == 1) 
		{
			A_B8_BIT2(gbf, layer1_id, "layer 1 id.", 6, 7, "octet identifier"); 
		}
		else
		{
			A_B8_BIT2(gbf, layer1_id, "layer 1 id.", 6, 7, "reserved"); 
		}
		B8_BIT(tmp, 2, 5); 
		if(tmp == 0) 
		{
			A_B8_BIT2(gbf, User_information_l_p, "User information layer 1 protocol", 2, 5, "default layer 1 protocol"); 
		}
		else
		{
			A_B8_BIT2(gbf, User_information_l_p, "User information layer 1 protocol", 2, 5, "reserved"); 
		}
		A_B8_BIT3(gbf, sync_async, "sync/async", 1, 1, bearer_capability_synchronous_asynchronou); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 5) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 6; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, numb_stop_bits, "numb.stop bits", 7, 7, bearer_capability_number_stop_b); 
		B8_BIT(tmp, 6, 6); 
		if(tmp == 1) 
		{
			A_B8_BIT2(gbf, negotiation, "negotiation", 6, 6, "in-band negotiation not possible"); 
		}
		else
		{
			A_B8_BIT2(gbf, negotiation, "negotiation", 6, 6, "reserved"); 
		}
		A_B8_BIT3(gbf, numb_data_bits, "numb.data bits", 5, 5, bearer_capability_number_data_b_e_p); 
		A_B8_BIT3(gbf, user_rate, "User rate", 1, 4, bearer_capability_user_rate); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 6) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 7; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, intermed_rate, "intermed. rate", 6, 7, bearer_capability_intermediate_rate); 
		A_B8_BIT3(gbf, nic_on_tx, "NIC on TX", 5, 5, bearer_capability_nic_tx); 
		A_B8_BIT3(gbf, mic_on_rx, "NIC on RX", 4, 4, bearer_capability_nic_rx); 
		A_B8_BIT3(gbf, parity, "Parity", 1, 3, bearer_capability_parity_information); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 7) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 8; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, connection_element, "connection element", 6, 7, bearer_capability_connection_element); 
		B8_BIT(tmp, 1, 5); 
		if(tmp >= 0 && tmp <= 8)
		{
			A_B8_BIT3(gbf, modem_type, "modem type", 1, 5, bearer_capability_modem_type); 
		}
		else
		{
			A_B8_BIT2(gbf, modem_type, "modem type", 1, 5, "reserved"); 
		}
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 8) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 9; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, other_modem_type, "Other modem type", 6, 7, bearer_capability_other_modem_type); 
		B8_BIT(tmp, 1, 5); 
		if(tmp == 0 || tmp == 1 || (tmp > 3 && tmp < 12))
		{
			A_B8_BIT3(gbf, fixed_network_user_rate, "Fixed network user rate", 1, 5, bearer_capability_fixed_network_u_r); 
		}
		else
		{
			A_B8_BIT2(gbf, fixed_network_user_rate, "Fixed network user rate", 1, 5, "reserved"); 
		}
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 9) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 10; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 7, 7); 
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 7, 7, "TCH/F14.4 not acceptable"); 
		}
		else
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 7, 7, "TCH/F14.4 acceptable"); 
		}
		A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 6, 6, "Spare"); 
		B8_BIT(tmp, 5, 5); 
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 5, 5, "TCH/F9.6 not acceptable"); 
		}
		else
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 5, 5, "TCH/F9.6 acceptable"); 
		}
		B8_BIT(tmp, 4, 4); 
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 4, 4, "TCH/F4.8 not acceptable"); 
		}
		else
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 4, 4, "TCH/F4.8 acceptable"); 
		}
		A_B8_BIT3(gbf, maximum_number_o_t_c, "Maximum number of traffic channels", 1, 3, bearer_capability_maximum_number_o_t_c); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 10) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 11; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 5, 7); 
		if(tmp >= 0 && tmp <= 4)
			A_B8_BIT3(gbf, uimi, "UIMI", 5, 7, bearer_capability_uimi); 
		else
			A_B8_BIT2(gbf, uimi, "UIMI", 5, 7, "reserved"); 
		B8_BIT(tmp, 1, 4); 
		if((tmp > 0 && tmp < 4) || (tmp > 4 && tmp < 13))
			A_B8_BIT3(gbf, ext_f, "Wanted air interface user rate", 1, 4, bearer_capability_wanted_air_i_u_r); 
		else
			A_B8_BIT2(gbf, ext_f, "Wanted air interface user rate", 1, 4, "reserved"); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 11) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 7, 7); 
		if(tmp == 0)
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 7, 7, "TCH/F28.8 not acceptable"); 
		else
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 7, 7, "TCH/F28.8 acceptable"); 
		B8_BIT(tmp, 6, 6);
		if(tmp == 0)
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 6, 6, "TCH/F32.0 not acceptable"); 
		else
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 6, 6, "TCH/F32.0 acceptable"); 
		B8_BIT(tmp, 5, 5);
		if(tmp == 0)
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 5, 5, "TCH/F43.2 not acceptable"); 
		else
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 5, 5, "TCH/F43.2 acceptable"); 
		A_B8_BIT3(gbf, asymmetry_indication, "Asymmetry Indication", 3, 4, bearer_capability_asymmetry_indication); 
		A_B8_BIT1(gbf, spare, "Spare", 1, 2); 
		length -= 1; 
		SKIP(1); 
	}
	if(length > 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 12; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, layer2_id, "layer 2 id.", 6, 7, bearer_capability_layer2_identity); 
		B8_BIT(tmp, 1, 5);
		if(tmp == 6 || tmp == 8 || tmp == 9 || (tmp >= 10 && tmp <= 13))
			A_B8_BIT3(gbf, user_information_l2_p, "User information layer 2 protocol", 1, 5, bearer_capability_user_information_l2_p); 
		else
			A_B8_BIT2(gbf, user_information_l2_p, "User information layer 2 protocol", 1, 5, "reserved"); 
		SKIP(1); 
	}
		
    END_ELEMENT(); 
}
#endif


void facility(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Facility", facility); 
	int tmp; 
	uint8_t ext = 1; 
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, facility_iei, "Facility IEI", 1, 8, "Facility");
        SKIP(1);
    }
    B8_BIT(tmp, 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of facility contents", 1, 8);
    SKIP(tmp+1);
		
    END_ELEMENT(); 
}

void progress_indicator(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Progress indicator", progress_indicator); 
	int tmp; 
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Progress indicator IEI", 1, 8, "Progress indicator");
        SKIP(1);
    }
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of progress indicator contents", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT3(gbf, ext, "ext", 8, 8, ext_dict);
    A_B8_BIT3(gbf, coding_standard, "Coding standard", 6, 7, progress_indicator_coding_standard);
    A_B8_BIT1(gbf, spare, "Spare", 5, 5);
    B8_BIT(tmp, 1, 4);
    if(tmp == 0 || tmp == 1 || tmp == 2 || tmp == 4 || tmp == 5 || tmp == 10)
        A_B8_BIT3(gbf, location, "Location", 1, 4, progress_indicator_location);
    else
        A_B8_BIT2(gbf, location, "Location", 1, 4, "reserved");
    SKIP(1);

    A_B8_BIT3(gbf, ext, "ext", 8, 8, ext_dict);
    B8_BIT(tmp, 1, 7);
    if((tmp > 0 && tmp < 5) || tmp == 8 || tmp == 9 || tmp == 32 || tmp == 64)
        A_B8_BIT3(gbf, progress_description, "Progress description", 1, 7, progress_indicator_progress_description);
    else
        A_B8_BIT2(gbf, progress_description, "Progress description", 1, 7, "Unspecific");
    SKIP(1);
		
    END_ELEMENT(); 
}

void network_call_control_cap(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Network Call Control Capabilities", network_call_c_c); 
	int tmp; 
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Network Call Control Capabilities IEI", 1, 8, "Network Call Control Capabilities");
        SKIP(1);
    }
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of NW Call Control Cap. contents", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(gbf, spare, "Spare", 2, 8);
    A_B8_BIT3(gbf, mcs, "MCS", 1, 1, network_call_c_c_mcs);
    SKIP(1);
		
    END_ELEMENT(); 
}

void rr_cause(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("RR Cause", rr_cause); 
	int tmp; 
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "RR Cause IEI", 1, 8, "RR Cause");
        SKIP(1);
    }
    B8_BIT(tmp, 1, 8);
    B8_HEX();
    if((tmp >=0 && tmp < 7) || (tmp > 7 && tmp < 13) || tmp == 65 || (tmp > 94 && tmp < 99) || tmp == 100 || tmp == 101 || tmp == 111)
        A_B8_BIT3(gbf, rr_cause_v, "RR cause value", 1, 8, rr_cause_rr_cause_v);
    else
        A_B8_BIT2(gbf, rr_cause_v, "RR cause value", 1, 8, "normal event");
    SKIP(1);
 
    END_ELEMENT(); 
}

void user_user(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("User-user", user_user); 
	int tmp; 
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "User-user IEI", 1, 8, "User_user");
        SKIP(1);
    }
    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of user-user contents", 1, 8);
    SKIP(1);

    B8_BIT(tmp, 1, 8);
    B8_HEX();
    if((tmp >= 0 && tmp < 5) || tmp == 7 || tmp == 8 || (tmp > 15 && tmp < 255))
        A_B8_BIT3(gbf, user_user_p_d, "User-user protocol discriminator", 1, 8, user_user_user_user_p_d);
    else
        A_B8_BIT2(gbf, user_user_p_d, "User-user protocol discriminator", 1, 8, "reserved");
    len -= 1;
    SKIP(1);

    int i;
    for(i = 0; i < len; i++)
    {
        B8_HEX();
        A_B8_BIT1(gbf, user_user_i, "User-user information", 1, 8);
        SKIP(1);
    }
 
    END_ELEMENT(); 
}

void ss_version_indicator(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("SS Version Indicator", ss_version_indicator); 
	int tmp; 
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "SS Version Indicator IEI", 1, 8, "SS Version Indicator");
        SKIP(1);
    }
    B8_BIT(tmp, 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of SS version indicator contents", 1, 8);
    SKIP(tmp + 1);

    END_ELEMENT(); 
}

void mobile_station_classmark_1(uint8_t iei, uint8_t location) 
{    
        BEGIN_ELEMENT("Mobile Station Classmark 1", mobile_station_classmark_1); 
        if(iei == 1)
        {    
                B8_HEX(); 
                A_B8_BIT2(gbf, mobile_station_classmark_1_iei, "Mobile Station Classmark 1 IEI", 1, 8, "Mobile Station Classmark 1");  
                SKIP(1); 
        }    
        B8_HEX();
        A_B8_BIT1(gbf, spare2, "spare", 8, 8);  
        A_B8_BIT3(gbf, revision, "Revision level", 6, 7, mobile_station_revision_level);
        A_B8_BIT3(gbf, es ,"ES IND", 5, 5, mobile_station_es_ind);
        A_B8_BIT3(gbf, A5_1 ,"A5/1 algorithm", 4, 4, mobile_station_A51_algorithm_s);
        A_B8_BIT3(gbf, rf ,"RF Power Capability", 1, 3, mobile_station_rf_power_c);  
        SKIP(1);
        END_ELEMENT(); 

}
void reject_cause(uint8_t iei, uint8_t location, uint8_t a) 
{    
        int tmp;
        BEGIN_ELEMENT("Reject cause", reject_cause); 
        if(iei == 1)
        {    
                B8_HEX(); 
                A_B8_BIT2(gbf, reject_cause_iei, "Reject cause IEI", 1, 8, "Reject cause");  
                SKIP(1); 
        }    
        B8_BIT(tmp, 1, 8);
        B8_HEX();
        if((tmp >= 2 && tmp <= 6)|| tmp ==11 || tmp ==12 || tmp==13 || tmp==15 || tmp==17 || (tmp >=20 && tmp <=23) || tmp == 25 || tmp == 32 || tmp ==33 || tmp ==34 || tmp ==38 || tmp ==48 || tmp ==63 || (tmp >=95 && tmp <= 101) || tmp== 111)

        A_B8_BIT3(gbf, rf ,"reject cause value", 1, 8, reject_cause_reject_cause_v);
        else if(a==1)
        A_B8_BIT2(gbf, rf ,"reject cause value", 1, 8, "Service option temporarily out of order");
        else if(a==0)
        A_B8_BIT2(gbf, rf ,"reject cause value", 1, 8, "Protocol error, unspecified");       
         SKIP(1);
        END_ELEMENT();
}
void mm_timer(uint8_t iei, uint8_t location)
{
        int tmp; 
        BEGIN_ELEMENT("MM Timer", mm_timer);
        if(iei == 1)
        {    
                B8_HEX();
                A_B8_BIT2(gbf, mm_timer_iei, "MM Timer IEI", 1, 8, "MM Timer");
                SKIP(1);
        }    
        B8_HEX();
        A_B8_BIT1(gbf, length_of_mm_timer_contents, "Length of MM Timer contents", 1, 8);
        SKIP(1);
        B8_HEX();
        B8_BIT(tmp, 6, 8);  
        if(tmp==1 || tmp==2 || tmp==7)
        A_B8_BIT3(gbf, mm_timer_value ,"MM Timer value", 6, 8, mm_timer_timer_value);
        else
        A_B8_BIT2(gbf, mm_timer_value ,"MM Timer value", 6, 8, "multiples of 1 minute in this version of the protocol");
        A_B8_BIT1(gbf, time_value, "Time value", 1, 5);  
     
        SKIP(1);
        END_ELEMENT();

}
void location_updating_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Location updating type", location_updating_type );
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT3(gbf, for1, "FOR", 4, 4, for1);
            A_B8_BIT1(gbf, spare, "spare", 3, 3);
            A_B8_BIT3(gbf, LUT, "LUT", 1, 2, lut);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT3(gbf, for1, "FOR", 8, 8, for1);
            A_B8_BIT1(gbf, spare, "spare", 7, 7);
            A_B8_BIT3(gbf, LUT, "LUT", 5, 6, lut);

        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, location_updating_type_iei, "Location updating type IEI", 5, 8, "Location updating type");
        A_B8_BIT3(gbf, for1, "FOR", 4, 4, for1);
        A_B8_BIT1(gbf, spare, "spare", 3, 3);
        A_B8_BIT3(gbf, LUT, "LUT", 1, 2, lut);
        SKIP(1);
   }
    END_ELEMENT();
}

void ms_network_feature_support(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("MS network feature support",  ms_network_feature_support );
        if(iei == 0)
        {
                if(location == 1)
                {
                        B8_HEX();
                        A_B8_BIT1(gbf, spare3, "Spare", 2, 4);
                        A_B8_BIT3(gbf, extended_periodic_timers, "extended periodic timers", 1, 1, ms_network_fea_sup_extended_periodic_t);
                }
                else
                {
                        A_B8_BIT1(gbf, spare3, "Spare", 6, 8);
                        A_B8_BIT3(gbf, extended_periodic_timers, "extended periodic timers", 5, 5, ms_network_fea_sup_extended_periodic_t);
                        SKIP(1);
                }
        }
        else
        {
                B8_HEX();

                A_B8_BIT2(gbf, ms_network_feature_support_iei, "MS network feature support IEI", 5, 8, "MS network feature support");
                A_B8_BIT1(gbf, spare3, "Spare", 2, 4);
               A_B8_BIT3(gbf, extended_periodic_timers, "extended periodic timers", 1, 1, ms_network_fea_sup_extended_periodic_t);
                SKIP(1);
        }
        END_ELEMENT();
}

void authentication_failure_parameter(uint8_t iei, uint8_t location)
{
        int i;
        BEGIN_ELEMENT("Authentication Failure parameter", authentication_failure_parameter );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, authentication_failure_parameter_iei, "Authentication Failure parameter IEI", 1, 8, "Authentication Failure parameter");
                SKIP(1);
        }

        if(location == 1)
        {
            B8_HEX();
            A_B8_BIT1(gbf, Length ofAuthentication Failure parameter contents, "Length ofAuthentication Failure parameter contents", 1, 8);
        }
        SKIP(1);
        for( i=1; i<=14 ;i++)
        {
                B8_HEX();
                A_B8_HEX_BIT1(gbf, Authentication Failure paramete, "Authentication Failure paramete", 1, 8);
                SKIP(1);
        }
        END_ELEMENT();
}

void follow_on_proceed(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("Follow-on Proceed", follow_on_proceed );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, follow_on_proceed_iei, "Follow-on Proceed IEI", 1, 8, "Follow-on Proceed");
                SKIP(1);
        }
        END_ELEMENT();
}

void cts_permission(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("CTS permission", cts_permission );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, cts_permission_iei, "CTS Permission IEI", 1, 8, "CTS Permission");
                SKIP(1);
        }
        END_ELEMENT();
}

void identity_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Identity type", identity_type );
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            A_B8_BIT3(gbf, type_of_identity, "type of identity", 1, 3, type_of_identity);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            A_B8_BIT3(gbf, type_of_identity, "type of identity", 5, 7, type_of_identity);

        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, identity_type_iei, "Identity type IEI", 5, 8, "Identity type");
        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        A_B8_BIT3(gbf, type_of_identity, "type of identity", 1, 3, type_of_identity);
        SKIP(1);
    }
    END_ELEMENT();
}


void p_tmsi_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("P-TMSI type",  p_tmsi_type );
    if(iei == 0)
    {
        if(location == 1)
                 {
            A_B8_BIT1(gbf, spare, "spare", 2, 4);
            A_B8_BIT3(gbf,  p_tmsi_type, "P-TMSI type", 1, 1, ptmsi_type_ptmsi_type);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 6, 8);
            A_B8_BIT3(gbf, p_tmsi_type, "P-TMSI type", 5, 5, ptmsi_type_ptmsi_type);

        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, p_tmsi_type_iei, "P-TMSI type IEI", 5, 8, "P-TMSI type");
        A_B8_BIT1(gbf, spare, "spare", 2, 4);
        A_B8_BIT3(gbf, p_tmsi_type, "P-TMSI type", 1, 1, ptmsi_type_ptmsi_type);
        SKIP(1);
    }
    END_ELEMENT();
}


void routing_area_identification_2(uint8_t iei, uint8_t location)
{
    int t,i;
    BEGIN_ELEMENT("Routing area identification 2", Routing_area_identification_2 );
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, routing_area_identification_2_iei, "Routing area identification 2 IEI", 1, 8, "Routing area identification 2");
        SKIP(1);
    }

    if(location == 1)
    {
        B8_BIT(t, 1, 8);
        B8_HEX();
        A_B8_BIT1(gbf, length_of_routing_area_identification_2_contents, "Length of routing area identification 2 contents", 1, 8);
        SKIP(1);
    }

    for(i =0; i<t; i++ )
    {
        B8_HEX();
        A_B8_BIT1(gbf, routing_area_identification_2_value, "Routing area identification 2 value", 1, 8);
        SKIP(1);
    }
    END_ELEMENT();
}

void p_tmsi_signature_2(uint8_t iei, uint8_t location)
{
        int t,i;
        BEGIN_ELEMENT("P-TMSI signature 2", p_tmsi_signature_2 );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, p_tmsi_signature_2_iei, "P-TMSI signature 2 IEI", 1, 8, "P-TMSI signature 2");
                SKIP(1);
        }

        if(location == 1)
        {
            B8_BIT(t, 1, 8);
            B8_HEX();
            A_B8_BIT1(gbf, length_of_p_tmsi_signature_2_contents, "Length of P-TMSI signature 2 contents", 1, 8);
            SKIP(1);
        }

        for(i =0; i<t; i++ )
        {
            B8_HEX();
            A_B8_BIT1(gbf, routing_area_identification_2_value, "Routing area identification 2 value", 1, 8);
            SKIP(1);
        }
    END_ELEMENT();
}

void pd_and_sapi(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("PD and SAPI", pd_and_sapi );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, pd_and_sapi_iei, "PD and SAPI IEI", 1, 8, "PD and SAPI");
                SKIP(1);
        }
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 7, 8);
        A_B8_BIT3(gbf, sapi, "SAPI", 5, 6, pd_sapi_sapi);
        A_B8_BIT1(gbf, pd, "PD", 1, 4);
        SKIP(1);
        END_ELEMENT();

}


void channel_mode(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Channel Mode", channel_mode);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, pd_and_sapi_iei, "Channel Mode IEI", 1, 8, "Channel Mode");
        SKIP(1);
    }
    B8_HEX();
    int tmp = -1;
    B8_BIT(tmp, 1, 8);
    if(tmp == 0 || tmp == 1 || tmp == 3 || tmp == 11 || tmp == 15 || tmp == 19 || tmp == 33 || tmp == 39 || tmp == 65 || tmp == 67 || tmp == 97 || tmp == 98 || tmp == 99 || (tmp >= 129 && tmp <= 131) || (tmp > 99 && tmp < 104))
        A_B8_BIT3(gbf, mode, "MODE", 1, 8, channel_mode_mode_field);
    else
        A_B8_BIT2(gbf, mode, "MODE", 1, 8, "reserved");
    SKIP(1);

    END_ELEMENT();
}

void channel_mode_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Channel Mode", channel_mode);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, channel_mode_iei, "Channel Mode IEI", 1, 8, "Channel Mode");
        SKIP(1);
    }
    B8_HEX();
    int tmp = -1;
    B8_BIT(tmp, 1, 8);
    if(tmp == 0 || tmp == 5 || tmp == 37 || tmp == 69 || tmp == 133 || tmp == 70 || tmp == 15 || tmp == 23 )
        A_B8_BIT3(gbf, mode, "MODE", 1, 8, channel_mode_2_mode_field);
    else
        A_B8_BIT2(gbf, mode, "MODE", 1, 8, "reserved");
    SKIP(1);

    END_ELEMENT();
}

void measurement_results(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Measurement Results", measurement_results);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, measurement_results_iei, "Measurement Results IEI", 1, 8, "Measurement Results");
        SKIP(1);
    }
    B8_HEX();
    A_B8_BIT1(gbf, ba_used, "BA-USED", 8, 8);
    A_B8_BIT3(gbf, dtx_used, "DTX-USED", 7, 7, measurement_results_dtx_used);
    A_B8_BIT1(gbf, rxlev_full_s_c, "RXLEV-FULL-SERVING-CELL", 1, 6);
    SKIP(1);
 
    B8_HEX();
    A_B8_BIT1(gbf, 3g_ba_used, "3G-BA-USED", 8, 8);
    A_B8_BIT3(gbf, meas_valid, "MEAS-VALID", 7, 7, measurement_results_meas_meas_valid);
    A_B8_BIT1(gbf, rxlev_sub_s_c, "RXLEV-SUB-SERVING-CELL", 1, 6);
    SKIP(1);

    char buf[100];
    int tmp = -1;
    B16_BIT(tmp, 7, 9);
    B8_HEX();
    A_B8_BIT1(gbf, spare, "Spare", 8, 8);
    A_B8_BIT1(gbf, rxqual_full_s_c, "RXQUAL-FULLSERVING-CELL", 5, 7);
    A_B8_BIT1(gbf, rqual_sub_s_c, "RXQUAL-SUBSERVING-CELL", 2, 4);
    A_B8_BIT2(gbf, no_ncell_m_h, "NO-NCELL-M(high part)", 1, 1, "-");
    SKIP(1);

    B8_HEX();
    if(tmp == 0)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "None");
    else if(tmp == 1)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "1");
    else if(tmp == 2)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "2");
    else if(tmp == 3)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "3");
    else if(tmp == 4)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "4");
    else if(tmp == 5)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "5");
    else if(tmp == 6)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "6");
    else if(tmp == 7)
        A_B8_BIT2(gbf, no_ncell_m_l, "NO-NCELL-M(low part)", 7, 8, "Neighbour cell information not available for serving cell");
    A_B8_BIT1(gbf, rxlev_ncell1, "RXLEV-NCELL 1", 1, 6);
    SKIP(1);

    B16_BIT(tmp, 6, 11);
    B8_HEX();
    A_B8_BIT1(gbf, bcch_freq_n1, "BCCH-FREQ-NCELL 1", 4, 8);
    A_B8_BIT2(gbf, bsic_ncell1_h, "BSIC-NCELL 1(high part)", 1, 3, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 8, 13);
    B8_HEX();
    A_B8_BIT2(gbf, bsic_ncell1_l, "BSIC-NCELL 1(low part)", 6, 8, buf);
    A_B8_BIT2(gbf, rxlev_ncell2_h, "RXLEV-NCELL 2(high part))", 1, 5, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_ncell2_h, "RXLEV-NCELL 2(low part))", 8, 8, buf);
    A_B8_BIT1(gbf, bcch_freq_n, "BCCH-FREQ-NCELL 2", 3, 7);
    A_B8_BIT2(gbf, bsic_ncell2_h, "BSIC-NCELL 2(high part)", 1, 2, "-");
    SKIP(1);


    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 12);
    B8_HEX();
    A_B8_BIT2(gbf, bsic_ncell2_l, "BSIC-NCELL 2(low part)", 5, 8, buf);
    A_B8_BIT2(gbf, rxlev_ncell3_h, "RXLEV-NCELL 3(high part)", 1, 4, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 4, 9);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_ncell3_l, "RXLEV-NCELL 3(low part)", 7, 8, buf);
    A_B8_BIT1(gbf, bcch_freq_n3, "BCCH-FREQ-NCELL 3", 2, 6);
    A_B8_BIT2(gbf, bsic_ncell3_h, "BSIC-NCELL 3(high part)", 1, 1, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 6, 11);
    B8_HEX();
    A_B8_BIT2(gbf, bsic_ncell3_l, "BSIC-NCELL 3(low part)", 4, 8, buf);
    A_B8_BIT2(gbf, rxlev_ncell4_h, "RXLEV-NCELL 4(high part)", 1, 3, "-");
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, rxlev_ncell4_l, "RXLEV-NCELL 4(low part)", 6, 8, buf);
    A_B8_BIT1(gbf, bcch_freq_n4, "BCCH-FREQ-NCELL 4", 1, 5);
    SKIP(1);

    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT1(gbf, bsic_ncell4, "BSIC-NCELL 4", 3, 8);
    A_B8_BIT2(gbf, rxlev_ncell5_h, "RXLEV-NCELL 5(high part)", 1, 2, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 8, 12);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_ncell5_l, "RXLEV-NCELL 5(low part)", 5, 8, buf);
    A_B8_BIT2(gbf, bcch_freq_n5_h, "BCCH-FREQ-NCELL 5(high part)", 1, 4, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 4, 9);
    B8_HEX();
    A_B8_BIT2(gbf, bcch_freq_n5_l, "BCCH-FREQ-NCELL 5(low part)", 8, 8, buf);
    A_B8_BIT1(gbf, bsic_ncell5, "BSIC-NCELL 5", 2, 7);
    A_B8_BIT2(gbf, rxlev_ncell6_h, "RXLEV-NCELL 6(high part)", 1, 1, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 11);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_ncell6_l, "RXLEV-NCELL 6(low part)", 4, 8, buf);
    A_B8_BIT2(gbf, bcch_freq_n6_h, "BCCH-FREQ-NCELL 6(high part)", 1, 3, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, bcch_freq_n6_l, "BCCH-FREQ-NCELL 6(low part)", 7, 8, buf);
    A_B8_BIT1(gbf, bsic_ncell6, "BSIC-NCELL 6", 1, 6);
    SKIP(1);

    END_ELEMENT();
}
#if 1
void cause(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cause", cause);
    int tmp = -1;
    int pos = 0;
    char buf[100];
    memset(buf, 0x00, sizeof(buf));
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, cause_iei, "Cause IEI", 1, 8, "Cause");
        SKIP(1);
    }

    int len = 0;
    B8_BIT(len, 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of cause contents", 1, 8);
    SKIP(1);

    int ext = 1;
    B8_BIT(ext, 8, 8);
    B8_HEX();
    A_B8_BIT3(gbf, ext, "Ext Flag", 8, 8, ext_dict);
    A_B8_BIT3(gbf, coding_standard, "Coding standard", 6, 7, progress_indicator_coding_standard); 
    A_B8_BIT1(gbf, spare, "Spare", 5, 5);
    A_B8_BIT3(gbf, location, "Location", 1, 4, progress_indicator_location);
    len -= 1;
    SKIP(1);

    if(len > 0 && ext == 0)
    {
        B8_BIT(tmp, 1, 7);
        B8_HEX();
        A_B8_BIT3(gbf, ext, "Ext Flag", 8, 8, ext_dict);
        if(tmp == 0 || tmp == 3 || tmp == 4 || tmp == 5)
            A_B8_BIT3(gbf, recommendation, "Recommendation", 1, 7, recommendation_dict); 
        else
            A_B8_BIT2(gbf, recommendation, "Recommendation", 1, 7, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    char *cause_val = NULL;
    if(len > 0)
    {
        B8_BIT(tmp, 1, 7);
        pos = sprintf(buf, "Cause ID=%d ", tmp);
        if(tmp == 1)
            cause_val = "Normal Event/Unassigned (unallocated) number";
        else if(tmp == 2)
            cause_val = "No route to specified transit network";
        else if(tmp == 3)
            cause_val = "Normal Event/No Route to destination";
        else if(tmp == 6)
            cause_val = "Normal Event/Channel unacceptable";
        else if(tmp == 7)
            cause_val = "Call awarded and being delivered in an established channel";
        else if(tmp == 8)
            cause_val = "Normal Event/Operator determined barring";
        else if(tmp == 16)
            cause_val = "Normal Event/Normal call clearing";
        else if(tmp == 17)
            cause_val = "Normal Event/User Busy";
        else if(tmp == 18)
            cause_val = "Normal Event/No User Responding";
        else if(tmp == 19)
            cause_val = "Normal Event/User alerting,no answer";
        else if(tmp == 21)
            cause_val = "Normal Event/Call Reject";
        else if(tmp == 22)
            cause_val = "Normal Event/Number changed";
		else if(tmp == 24)
			cause_val ="Normal Event/Call rejected due to feature at the destination";
        else if(tmp == 25)
            cause_val = "Normal Event/Pre-emption";
        else if(tmp == 26)
            cause_val = "Normal Event/Non-selected user clearing";
        else if(tmp == 27)
            cause_val = "Normal Event/Destination out of order";
        else if(tmp == 28)
            cause_val = "Normal Event/Invalid number format (incomplete number)";
        else if(tmp == 29)
            cause_val = "Normal Event/Facility Rejected (Authentication Failure)";
        else if(tmp == 30)
            cause_val = "Normal Event/Response to STATUS ENQUIRY";
        else if(tmp == 31)
            cause_val = "Normal Event/Normal, unspecified";
        else if(tmp == 34)
            cause_val = "Resource Unavailable/Circuit Channel Congestion";
        else if(tmp == 38)
            cause_val = "Resource Unavailable/NetWork Out of Order";
        else if(tmp == 41)
            cause_val = "Resource Unavailable/Temporary Failure";
        else if(tmp == 42)
            cause_val = "Resource Unavailable/Switching equipment congestion";
        else if(tmp == 43)
            cause_val = "Resource Unavailable/Access information discarded";
        else if(tmp == 44)
            cause_val = "Resource Unavailable/Requested circuit/channel not available";
        else if(tmp == 47)
            cause_val = "Resource Unavailable/Resource unavailable,unspecified";
        else if(tmp == 49)
            cause_val = "Service or option not available/Quality of service unavailable";
        else if(tmp == 50)
            cause_val = "Service or option not available/Requested facility not subscribed";
        else if(tmp == 55)
            cause_val = "Service or option not available/Incoming calls barred within the CUG";
        else if(tmp == 57)
            cause_val = "Service or option not available/Bearer capability not authorized";
        else if(tmp == 58)
            cause_val = "Service or option not available/Bearer capability not presently available";
        else if(tmp == 63)
            cause_val = "Service or option not available/Service or option not available, unspecified";
        else if(tmp == 65)
            cause_val = "Service or option not implemented/Bearer capability not implemented";
        else if(tmp == 66)
            cause_val = "Channel type not implemented";
        else if(tmp == 68)
            cause_val = "Service or option not implemented/ACM equal to or greater than ACMmax";
        else if(tmp == 69)
            cause_val = "Service or option not implemented/Requested facility not implemented";
        else if(tmp == 70)
            cause_val = "Service or option not implemented/Only restricted digital information bearer capability is available";
        else if(tmp == 79)
            cause_val = "Service or option not implemented/Service or option not implemented, unspecified";
        else if(tmp == 81)
            cause_val = "Invalid message/Invalid transaction identifier value";
        else if(tmp == 82)
            cause_val = "Identified channel does not exist";
        else if(tmp == 87)
            cause_val = "Invalid message/User not member of CUG";
        else if(tmp == 88)
            cause_val = "Invalid message/Incompatible destination";
        else if(tmp == 91)
            cause_val = "Invalid message/Invalid transit network selection";
        else if(tmp == 95)
            cause_val = "Invalid message/Semantically incorrect message";
        else if(tmp == 96)
            cause_val = "Protocol error/Invalid mandatory information";
        else if(tmp == 97)
            cause_val = "Protocol error/Message type non-existent or not implemented";
        else if(tmp == 98)
            cause_val = "Protocol error/Message type not compatible with protocol state";
        else if(tmp == 99)
            cause_val = "Protocol error/Information element non-existent or not implemented";
        else if(tmp == 100)
            cause_val = "Protocol error/Conditional IE error";
        else if(tmp == 101)
            cause_val = "Protocol error/Message State Error";
        else if(tmp == 102)
            cause_val = "Protocol error/Recovery on Timer Expiry";
        else if(tmp == 111)
            cause_val = "Protocol error/Protocol error, unspecified";
        else if(tmp == 127)
            cause_val = "Interworking/Interworking, unspecified";
        else
            cause_val = "Reserved";
        sprintf(buf+pos, "Cause Value=%s", cause_val);
        
        B8_HEX();
        A_B8_BIT3(gbf, ext, "Ext Flag", 8, 8, ext_dict);
        A_B8_BIT2(gbf, cause_value, "Cause value", 1, 7, buf);
        len -= 1;
        SKIP(1);
    }
    if(len > 0)
        SKIP(len);
 
    END_ELEMENT();
}
#endif

void allowed_actions(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Allowed Actions", allowed_actions);
    int tmp = -1;
    int pos = 0;
    char buf[100];
    memset(buf, 0x00, sizeof(buf));
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, allowed_actions_iei, "Allowed Actions IEI", 1, 8, "Allowed Actions");
        SKIP(1);
    }

    int len = 0;
    B8_BIT(len, 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of allowed actions contents", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT3(gbf, ccbs_act, "CCBS activation", 8, 8, allowed_actions_ccbs_activation);
    A_B8_BIT1(gbf, spare, "Spare", 1, 7);
    SKIP(1);

    END_ELEMENT();
}
void gprs_timer_3(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("GPRS Timer 3", gprs_timer_3 );
        if(iei==1)
        {    
                B8_HEX();
                A_B8_BIT2(gbf, gprs_timer_3_iei, "GPRS Timer 3 IEI", 1, 8, "GPRS Timer 3");
                SKIP(1);
        }

        if(location == 1)
        {
            B8_HEX();
            A_B8_BIT1(gbf, length_of_gprs_timer_3_contents, "Length of GPRS Timer 3 contents", 1, 8);
            SKIP(1);
        }
B8_HEX();
        A_B8_BIT3(gbf, unit, "Unit", 6, 8, cprs_timer3_gprs_timer3_v);
        A_B8_BIT1(gbf, time_value, "Timer value", 1, 5);
        SKIP(1);
        END_ELEMENT();


}
void plmn_list(uint8_t iei, uint8_t location)
{
     
        uint8_t mnc1;
        uint8_t mnc2;
        uint8_t mnc3;
        uint8_t mcc1;
        uint8_t mcc2;
        uint8_t mcc3;
        uint16_t mcc; 
        uint16_t mnc; 
        int t, i;
        BEGIN_ELEMENT("PLMN list", plmn_list );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, plmn_list_iei, "PLMN List IEI", 1, 8, "PLMN List");
                SKIP(1);
        }
        B8_BIT(t, 1, 8);
        B8_HEX();
        A_B8_BIT1(gbf, length_of_plmn_list_contents, "Length of PLMN List contents", 1, 8);
        SKIP(1);
        for(i=1; i<=t/3; i++)
        {
                char mcc_digit1buf[16*1024]={};
                char mcc_digit2buf[16*1024]={};
                char mcc_digit3buf[16*1024]={};

                char mnc_digit1buf[16*1024]={};
                char mnc_digit2buf[16*1024]={};
                char mnc_digit3buf[16*1024]={};

                char mcc_buf[16*1024]={};
                char mnc_buf[16*1024]={};
                B8_BIT(mcc2, 5, 8);
                B8_BIT(mcc1, 1, 4);
                SKIP(1);
                B8_BIT(mnc3, 5, 8);
                B8_BIT(mcc3, 1, 4);
                SKIP(1);
                B8_BIT(mnc2, 5, 8);
                B8_BIT(mnc1, 1, 4);
                mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
                sprintf(mcc_buf, "MCC = %d", mcc);
                mnc = 100 * mnc1 + 10 * mnc2 + mnc3;
                sprintf(mnc_buf, "MNC = %d", mnc);
                BACK(2);
                B8_HEX();
                sprintf(mcc_digit1buf, "MCC digit 1,PLMN %d", i);
                sprintf(mcc_digit2buf, "MCC digit 2,PLMN %d", i);
                A_B8_BIT2(gbf, mcc_digit2 ,mcc_digit2buf, 5, 8, "-");
                A_B8_BIT2(gbf, mcc_digit1 ,mcc_digit1buf, 1, 4, "-");
                SKIP(1);

                B8_HEX();
                sprintf(mnc_digit3buf, "MNC digit 3,PLMN %d", i);
                sprintf(mcc_digit3buf, "MCC digit 3,PLMN %d", i);
                A_B8_BIT2(gbf, mnc_digit3 ,mnc_digit3buf, 5, 8, "-");
                A_B8_BIT2(gbf, mcc_digit3 ,mcc_digit3buf, 1, 4, mcc_buf);
                SKIP(1);

                B8_HEX();
                sprintf(mnc_digit1buf, "MNC digit 1,PLMN %d", i);
                sprintf(mnc_digit2buf, "MNC digit 2,PLMN %d", i);
                A_B8_BIT2(gbf, mnc_digit2 ,mnc_digit2buf, 5, 8, "-");
                A_B8_BIT2(gbf, mnc_digit1 ,mnc_digit1buf, 1, 4, mnc_buf);
                SKIP(1);
        }
        END_ELEMENT();
}
void emergency_num(int digitnum, int digit_m, int z)
{
                char emergency[1024]={0};
                int j;
                for(j=0; j<digitnum-1; j++) 
                {    
                        int f,c; 
                        char num_dig[1024]={0};
                        char num_1_4[1024]={0};
                        char num_5_8[1024]={0};
                        digit_m+=2;
                        B8_BIT(c, 5, 8);
                        B8_BIT(f, 1, 4);
                        B8_HEX();
                        if(f==1)
                        {    
                                strcat(num_dig,"1");
                        }    
                        if(f==2)
                        {    
                                strcat(num_dig,"2");
                        }    
                        if(f==3)
                        {    
                                strcat(num_dig,"3");
                        }    
                        if(f==4)
                        {    
                                strcat(num_dig,"4");
                        }    
                        if(f==5)
                        {
                                strcat(num_dig,"5");
                        }
                        if(f==6)
                        {
                                strcat(num_dig,"6");
                        }
                        if(f==7)
                        {
                                strcat(num_dig,"7");
                        }
                        if(f==8)
                        {
                                strcat(num_dig,"8");
                        }
                        if(f==9)
                        {
                                strcat(num_dig,"9");
                        }
                        if(f==10)
                        {
                                strcat(num_dig,"*");
                        }
                        if(f==11)
                        {
                                strcat(num_dig,"#");
                        }
                        if(f==12)
                        {
                                strcat(num_dig,"a");
                        }
                        if(f==13)
                        {
                                strcat(num_dig,"b");
                        }
                        if(f==14)
                        {
                                strcat(num_dig,"c");
                        }
                        if(f==15)
                        {
                                strcat(num_dig,"f");
                        }

                        if(c==1)
                        {
                                strcat(num_dig,"1");
                        }
                        if(c==2)
                        {
                                strcat(num_dig,"2");
                        }
                        if(c==3)
                        {
                                strcat(num_dig,"3");
                        }
                        if(c==4)
                        {
                                strcat(num_dig,"4");
                        }
                        if(c==5)
                        {
                                strcat(num_dig,"5");
                        }
                        if(c==6)
                        {
                                strcat(num_dig,"6");
                        }
                        if(c==7)
                        {
                                strcat(num_dig,"7");
                        }
                        if(c==8)
                        {
                                strcat(num_dig,"8");
                        }
                        if(c==9)
                        {
                                strcat(num_dig,"9");
                        }
                        if(c==10)
                        {
                                strcat(num_dig,"*");
                        }
                        if(c==11)
                        {
                                strcat(num_dig,"#");
                        }
                        if(c==12)
                        {
                                strcat(num_dig,"a");
                        }
                        if(c==13)
                        {
                                strcat(num_dig,"b");
                        }
                        if(c==14)
                        {
                                strcat(num_dig,"c");
                        }
                        if(c==15)
                        {
                                if((z==1)&&(j==digitnum-2))
                                {}
                                else
                                        strcat(num_dig,"f");
                        }
                        strcat(emergency,num_dig);
                        sprintf(num_5_8, "Number digit %d", digit_m);

                        A_B8_BIT2(gbf, number_digit, num_5_8, 5,8, "-");
                        digit_m--;
                        sprintf(num_1_4, "Number digit %d", digit_m);
                        A_B8_BIT2(gbf, number_digit, num_1_4, 1, 4, emergency);
                        SKIP(1);
                        digit_m++;
                }
}
void emergency_number_list(uint8_t iei, uint8_t location)
{
        int t, i=1, digit,j;
        BEGIN_ELEMENT("Emergency Number List", emergency_number_list );
        if(iei==1)
        {
                B8_HEX();
                A_B8_BIT2(gbf, emergency_number_list_iei, "Emergency Number List IEI", 1, 8,"Emergency Number List");
                SKIP(1);
        }
        B8_BIT(t, 1, 8);
        B8_HEX();
        A_B8_BIT1(gbf, length_of_emergency_number_list_ie_contents, "Length of Emergency Number List IE contents", 1, 8);
        SKIP(1);
        while(t!=0)
        {

                int digit_m=0, m, n, z=0,digitnum;
                char length[1024]={0};
                char emergency[1024]={0};
                B8_BIT(digitnum, 1, 8);
                t=t-digitnum-1;
                B8_HEX();
                sprintf(length, "Length of %dst Emergency Number information", i);
                i++;
                A_B8_BIT1(gbf, length_of_emergency_number_information, length, 1, 8);
                SKIP(1);
                m=digitnum%10;
                n=digitnum/10;
                if((m%2==1) || (n%2==1))
                        z=1;
                B8_HEX();
                A_B8_BIT1(gbf, spare, "spare", 6, 8);
                A_B8_BIT1(gbf, emergency_service_category_value,"Emergency Service Category Value", 1 ,5);
                SKIP(1);

                if(digitnum>0)
                emergency_num(digitnum, digit_m, z );
        }
        END_ELEMENT();
}
void signal(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Signal", signal);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, sianal_iei, "Signal IEI", 1, 8, "Signal");
        SKIP(1);
    }

    int tmp = -1;
    B8_BIT(tmp, 1, 8);
    if((tmp >= 0 && tmp < 9) || tmp == 63 || tmp == 79)
    {
        B8_HEX();
        A_B8_BIT3(gbf, signal_value, "Signal value", 1, 8, signal_signal_value);
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, signal_value, "Signal value", 1, 8, "reserved");
    }
    SKIP(1);

    END_ELEMENT();
}

void power_command(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Power Command", power_command);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, sianal_iei, "Power Command IEI", 1, 8, "Power Command");
        SKIP(1);
    }

    int tmp = -1;
    B8_BIT(tmp, 7, 7);
    B8_HEX();
    A_B8_BIT1(gbf, spare, "Spare", 8, 8);
    A_B8_BIT3(gbf, epc_mode, "EPC mode", 7, 7, power_command_epc_mode);
    if(tmp == 0)
    {
        A_B8_BIT3(gbf, fpc_epc, "FPC_EPC", 6, 6, power_command_fpc_epc0);
    }
    else if(tmp == 1)
    {
        A_B8_BIT3(gbf, fpc_epc, "FPC_EPC", 6, 6, power_command_fpc_epc1);
    }
    A_B8_BIT1(gbf, power_level, "POWER LEVEL", 1, 5);
    SKIP(1);

    END_ELEMENT();
}
 

void frequency_list(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Frequency List", frequency_list); 
	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Frequency List IEI", 1, 8, "Frequency List"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of frequency list contents", 1, 8); 
    SKIP(1); 

    int tmp; 
    char buf[100]; 
    memset(buf, 0x00, sizeof(buf)); 
    int f_id_7_8; 
    int f_id_4; 
    int f_id_2_4; 
    B8_BIT(f_id_7_8, 7, 8); 
    B8_BIT(f_id_4, 4, 4); 
    B8_BIT(f_id_2_4, 2, 4); 
    if(f_id_7_8 == 0) 
    { 
		bit_map0_format(); 
    } 
    if(f_id_7_8 == 2) 
    { 
        if(f_id_4 == 0) 
        { 
			range1024_format(len);			
		} 
        else if(f_id_2_4 == 4) 
        { 
			range512_format(len); 
        } 
        else if(f_id_2_4 == 5) 
        { 
			range256_format(len); 
        } 
        else if(f_id_2_4 == 6) 
        { 
			range128_format(len); 
        } 
        else
        {
            variable_bit_map_format(len);
        } 
    } 

    END_ELEMENT(); 
}

void cell_channel_description(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Cell Channel Description", cell_channel_d); 
	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Cell Channel Description IEI", 1, 8, "Cell Channel Description"); 
        SKIP(1); 
    } 
	int f_id_7_8; 
    int f_id_4; 
    int f_id_2_4; 
    B8_BIT(f_id_7_8, 7, 8); 
    B8_BIT(f_id_4, 4, 4); 
    B8_BIT(f_id_2_4, 2, 4); 
    if(f_id_7_8 == 0) 
    { 
		bit_map0_format(); 
    } 
    if(f_id_7_8 == 2) 
    { 
        if(f_id_4 == 0) 
        { 
			range1024_format(16);			
		} 
        else if(f_id_2_4 == 4) 
        { 
			range512_format(16); 
        } 
        else if(f_id_2_4 == 5) 
        { 
			range256_format(16); 
        } 
        else if(f_id_2_4 == 6) 
        { 
			range128_format(16); 
        } 
        else
        {
            variable_bit_map_format(16);
        } 
    } 


    END_ELEMENT(); 
}

void multislot_allocation(uint8_t iei, uint8_t location, uint8_t tn) 
{
    BEGIN_ELEMENT("Multislot Allocation", multislot_allocation); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Multislot Allocation IEI", 1, 8, "Multislot Allocation"); 
        SKIP(1); 
    } 

    int len = -1;
    int ext = 1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of the multislot allocation contents", 1, 8); 
    SKIP(1); 
    
    char buf[50];
    char desc_buf[50];
    char *p = desc_buf;
    int tmp = 0;
    int pos = 0;
    int tn_v = 0;
    int j, i;
    memset(desc_buf, 0, sizeof(desc_buf));
    memcpy(desc_buf, "TN = ", 5);
    p += 5;
    B8_BIT(ext, 8, 8);
    for(i = 7; i > 0; i--)
    {
        B8_BIT(tmp, i, i);
        if(tmp == 1)
        {
            tn_v = (i + tn) % 8;
            pos += sprintf(p + pos, "%d ", tn_v);
        }
    }
    B8_HEX();
    A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
    A_B8_BIT2(gbf, da, "Downlink assignment", 1, 7, desc_buf); 
    len -= 1;
    SKIP(1);

    if(len > 0 && ext == 0)
    {
        memset(desc_buf, 0, sizeof(desc_buf));
        p = desc_buf;
        memcpy(desc_buf, "TN = ", 5);
        p += 5;
        pos = 0;
        for(i = 7; i > 0; i--)
        {
            B8_BIT(tmp, i, i);
            if(tmp == 1)
            {
                tn_v = (i + tn) % 8;
                pos += sprintf(p + pos, "%d ", tn_v);
            }
        }
        B8_HEX();
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT2(gbf, ua, "Uplink assignment", 1, 7, desc_buf); 
        len -= 1;
        SKIP(1);
    }

    for(i = 1; i <= len; i++)
    {
        memset(buf, 0, sizeof(buf));
        memset(desc_buf, 0, sizeof(desc_buf));
        sprintf(buf, "Channel set%d", i);
        p = desc_buf;
        memcpy(desc_buf, "TN = ", 5);
        p += 5;
        pos = 0;
        for(j = 8; j > 0; j--)
        {
            B8_BIT(tmp, j, j); 
            if(tmp == 1)
            {
                pos += sprintf(p + pos, "%d ", j - 1);
            }
        }
        B8_HEX();
	    A_B8_BIT2(gbf, channel_set, buf, 1, 8, desc_buf); 
	    SKIP(1); 
    }

    END_ELEMENT(); 
}

void frequency_channel_sequence(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Frequency Channel Sequence", frequency_channel_sequence); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Frequency Channel Sequence IEI", 1, 8, "Frequency Channel Sequence"); 
        SKIP(1); 
    } 

	B8_HEX(); 
    A_B8_BIT1(gbf, spare, "Spare", 8, 8); 
    A_B8_BIT1(gbf, lowest_arfcn, "Lowest ARFCN", 1, 7); 
    SKIP(1);
    
    int i;
    for(i = 0; i < 8; i++)
    {
		B8_HEX(); 
        A_B8_BIT2(gbf, skip_arfcn, "inc skip of ARFCN", 1, 8, "inc skip of ARFCN"); 
        SKIP(1);
    }

    END_ELEMENT(); 
}

void vgcs_target_mode_indication(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("VGCS target mode Indication", vgcs_target_m_i); 

    SKIP(3);

    END_ELEMENT(); 
}

void vgcs_amr_configuration(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("VGCS AMR Configuration", vgcs_amr_c); 

    SKIP(3);

    END_ELEMENT(); 
}

void multirate_configuration(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("MultiRate configuration", multiRate_configuration); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Multirate speech configuration IEI", 1, 8, "Multirate speech configuration"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Multirate speech configuration", 1, 8); 
    SKIP(1); 

    int tmp = -1;
    B8_BIT(tmp, 6, 8);
    if(tmp == 1 || tmp == 2)
        A_B8_BIT3(gbf, multirate_speech_v, "Multirate speech version", 6, 8, multirate_configuration_info_multirate_speech_v); 
    else
        A_B8_BIT2(gbf, multirate_speech_v, "Multirate speech version", 6, 8, "reserved"); 
    A_B8_BIT3(gbf, nscb, "NSCB", 5, 5, multirate_configuration_info_noise_suppression_c); 
    A_B8_BIT3(gbf, icmi, "ICMI", 4, 4, multirate_configuration_info_initial_codec_m_i); 
    A_B8_BIT1(gbf, spare, "Spare", 3, 3); 
    A_B8_BIT1(gbf, start_mode, "Start mode", 1, 2); 
    SKIP(1); 

    if(len > 0)
    {
        if(tmp == 1)
        {
            A_B8_BIT3(gbf, amr_codec_modes_bit8, "Set of AMR codec modes", 8, 8, multirate_configuration_info_amr_codec_m_bit8); 
            A_B8_BIT3(gbf, amr_codec_modes_bit7, "Set of AMR codec modes", 7, 7, multirate_configuration_info_amr_codec_m_bit7); 
            A_B8_BIT3(gbf, amr_codec_modes_bit6, "Set of AMR codec modes", 6, 6, multirate_configuration_info_amr_codec_m_bit6); 
            A_B8_BIT3(gbf, amr_codec_modes_bit5, "Set of AMR codec modes", 5, 5, multirate_configuration_info_amr_codec_m_bit5); 
            A_B8_BIT3(gbf, amr_codec_modes_bit4, "Set of AMR codec modes", 4, 4, multirate_configuration_info_amr_codec_m_bit4); 
            A_B8_BIT3(gbf, amr_codec_modes_bit3, "Set of AMR codec modes", 3, 3, multirate_configuration_info_amr_codec_m_bit3); 
            A_B8_BIT3(gbf, amr_codec_modes_bit2, "Set of AMR codec modes", 2, 2, multirate_configuration_info_amr_codec_m_bit2); 
            A_B8_BIT3(gbf, amr_codec_modes_bit1, "Set of AMR codec modes", 1, 1, multirate_configuration_info_amr_codec_m_bit1); 
            SKIP(1); 
        }
        else if(tmp == 2)
        {
            A_B8_BIT1(gbf, spare, "Spare", 6, 8); 
            A_B8_BIT3(gbf, amr_codec_modes_bit4, "Set of AMR codec modes", 5, 5, multirate_configuration_info_amr_codec_m_bit5_ext); 
            A_B8_BIT3(gbf, amr_codec_modes_bit4, "Set of AMR codec modes", 4, 4, multirate_configuration_info_amr_codec_m_bit4_ext); 
            A_B8_BIT3(gbf, amr_codec_modes_bit3, "Set of AMR codec modes", 3, 3, multirate_configuration_info_amr_codec_m_bit3_ext); 
            A_B8_BIT3(gbf, amr_codec_modes_bit2, "Set of AMR codec modes", 2, 2, multirate_configuration_info_amr_codec_m_bit2_ext); 
            A_B8_BIT3(gbf, amr_codec_modes_bit1, "Set of AMR codec modes", 1, 1, multirate_configuration_info_amr_codec_m_bit1_ext); 
            SKIP(1); 
        }
        else
        {
            SKIP(len);
            return;
        }

        if(len == 3)
        {
            A_B8_BIT1(gbf, spare, "Spare", 7, 8); 
            A_B8_BIT1(gbf, threshold1, "Threshold 1", 1, 6); 
            SKIP(1);
            A_B8_BIT1(gbf, hysteresis1, "Hysteresis 1", 5, 8); 
            A_B8_BIT1(gbf, spare, "Spare", 1, 4); 
            SKIP(1);
        }
        else if(len == 4)
        {
            A_B8_BIT1(gbf, spare, "Spare", 7, 8); 
            A_B8_BIT1(gbf, threshold1, "Threshold 1", 1, 6); 
            SKIP(1);
            A_B8_BIT1(gbf, hysteresis1, "Hysteresis 1", 5, 8); 
            A_B8_BIT1(gbf, threshold2, "Threshold 2", 1, 4); 
            SKIP(1);
            A_B8_BIT1(gbf, threshold2_cont, "Threshold 2(cont.)", 7, 8); 
            A_B8_BIT1(gbf, hysteresis2, "Hysteresis 2", 3, 6); 
            A_B8_BIT1(gbf, spare, "Spare", 1, 2); 
            SKIP(1);

        }
        else if(len == 5)
        {
            A_B8_BIT1(gbf, spare, "Spare", 7, 8); 
            A_B8_BIT1(gbf, threshold1, "Threshold 1", 1, 6); 
            SKIP(1);
            A_B8_BIT1(gbf, hysteresis1, "Hysteresis 1", 5, 8); 
            A_B8_BIT1(gbf, threshold2, "Threshold 2", 1, 4); 
            SKIP(1);
            A_B8_BIT1(gbf, threshold2_cont, "Threshold 2(cont.)", 7, 8); 
            A_B8_BIT1(gbf, hysteresis2, "Hysteresis 2", 3, 6); 
            A_B8_BIT1(gbf, threshold3, "Threshold 3", 1, 2); 
            SKIP(1);
            A_B8_BIT1(gbf, threshold3, "Threshold 3", 5, 8); 
            A_B8_BIT1(gbf, hysteresis3, "Hysteresis 3", 5, 8); 
            SKIP(1);
        }
    }

    END_ELEMENT(); 
}

void vgcs_ciphering_parameters(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("VGCS Ciphering Parameters", vgcs_ciphering_p); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "VGCS Ciphering Parameters IEI", 1, 8, "VGCS Ciphering Parameters"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of VGCS Ciphering Parameters", 1, 8); 
    SKIP(1); 

    SKIP(len); 

    END_ELEMENT(); 
}

void connected_number(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Connected number", connected_number); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Connected number IEI", 1, 8, "Connected number"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of connected number contents", 1, 8); 
    SKIP(1); 

    int ext = 1;
    B8_BIT(ext, 8, 8);
    int tmp = -1;
    B8_BIT(tmp, 1, 4);

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_number, "Type of number", 5, 7, called_party_b_n_type_number); 
    if((tmp >= 0 && tmp < 5) || tmp == 8 || tmp == 9 || tmp == 11 || tmp == 15)
        A_B8_BIT3(gbf, number_plan_i, "Number plan identification", 1, 4, called_party_b_n_numbering_plan_i); 
    else
        A_B8_BIT2(gbf, number_plan_i, "Number plan identification", 1, 4, "reserved"); 
    len -= 1;
    SKIP(1);
    
    if(ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
        A_B8_BIT3(gbf, presentation_indicator, "Presentation indicator", 6, 7, calling_party_b_n_presentation_indicator); 
        A_B8_BIT1(gbf, spare, "Spare", 3, 5); 
        A_B8_BIT3(gbf, presentation_indicator, "Screening indicator", 1, 2, calling_party_b_n_screening_indicator); 
        len -= 1;
        SKIP(1);
    }

    number_digit(len);

    END_ELEMENT(); 
}

void calling_party_bcd_num(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Calling party BCD number", calling_party_bcd_number); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Calling party BCD number IEI", 1, 8, "Calling party BCD number"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of calling party BCD number contents", 1, 8); 
    SKIP(1); 

    int ext = 1;
    B8_BIT(ext, 8, 8);
    int tmp = -1;
    B8_BIT(tmp, 1, 4);

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_number, "Type of number", 5, 7, called_party_b_n_type_number); 
    if((tmp >= 0 && tmp < 5) || tmp == 8 || tmp == 9 || tmp == 11 || tmp == 15)
        A_B8_BIT3(gbf, number_plan_i, "Number plan identification", 1, 4, called_party_b_n_numbering_plan_i); 
    else
        A_B8_BIT2(gbf, number_plan_i, "Number plan identification", 1, 4, "reserved"); 
    len -= 1;
    SKIP(1);
    
    if(ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
        A_B8_BIT3(gbf, presentation_indicator, "Presentation indicator", 6, 7, calling_party_b_n_presentation_indicator); 
        A_B8_BIT1(gbf, spare, "Spare", 3, 5); 
        A_B8_BIT3(gbf, presentation_indicator, "Screening indicator", 1, 2, calling_party_b_n_screening_indicator); 
        len -= 1;
        SKIP(1);
    }

    number_digit(len);

    END_ELEMENT(); 
}

void called_party_bcd_num(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Called party BCD number", called_party_bcd_number); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Called party BCD number IEI", 1, 8, "Called party BCD number"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of called party BCD number contents", 1, 8); 
    SKIP(1); 

    int tmp = -1;
    B8_BIT(tmp, 1, 4);

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_number, "Type of number", 5, 7, called_party_b_n_type_number); 
    if((tmp >= 0 && tmp < 5) || tmp == 8 || tmp == 9 || tmp == 11 || tmp == 15)
        A_B8_BIT3(gbf, number_plan_i, "Number plan identification", 1, 4, called_party_b_n_numbering_plan_i); 
    else
        A_B8_BIT2(gbf, number_plan_i, "Number plan identification", 1, 4, "reserved"); 
    len -= 1;
    SKIP(1);

    number_digit(len);

    END_ELEMENT(); 
}

void redirecting_party_bcd_num(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Redirecting party BCD number", called_party_bcd_number); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Redirecting party BCD number IEI", 1, 8, "Redirecting party BCD number"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of redirecting party BCD number contents", 1, 8); 
    SKIP(1); 

    int ext = 1;
    B8_BIT(ext, 8, 8);
    int tmp = -1;
    B8_BIT(tmp, 1, 4);

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_number, "Type of number", 5, 7, called_party_b_n_type_number); 
    if((tmp >= 0 && tmp < 5) || tmp == 8 || tmp == 9 || tmp == 11 || tmp == 15)
        A_B8_BIT3(gbf, number_plan_i, "Number plan identification", 1, 4, called_party_b_n_numbering_plan_i); 
    else
        A_B8_BIT2(gbf, number_plan_i, "Number plan identification", 1, 4, "reserved"); 
    len -= 1;
    SKIP(1);
    
    if(ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
        A_B8_BIT3(gbf, presentation_indicator, "Presentation indicator", 6, 7, calling_party_b_n_presentation_indicator); 
        A_B8_BIT1(gbf, spare, "Spare", 3, 5); 
        A_B8_BIT3(gbf, presentation_indicator, "Screening indicator", 1, 2, calling_party_b_n_screening_indicator); 
        len -= 1;
        SKIP(1);
    }

    number_digit(len);

    END_ELEMENT(); 
}

void connected_subaddress(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Connected subaddress", connected_subaddress); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Connected subaddress IEI", 1, 8, "Connected subaddress"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of connected subaddress contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_subaddress, "Type of subaddress", 5, 7, calling_party_s_type_subaddress); 
    A_B8_BIT3(gbf, odd_even_i, "odd/even indicator", 4, 4, calling_party_s_odd_even_i); 
    A_B8_BIT1(gbf, spare, "Spare", 1, 3); 
    SKIP(1); 
    
    int i;
    for(i = 0; i < len; i++)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, subaddress_information, "Subaddress information", 1, 8); 
        len -= 1;
        SKIP(1); 
    }
    
    END_ELEMENT(); 
}

void calling_party_subaddr(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Calling party subaddress", calling_part_subaddress); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Calling party Subaddress IEI", 1, 8, "Calling party Subaddress"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of calling party subaddress contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_subaddress, "Type of subaddress", 5, 7, calling_party_s_type_subaddress); 
    A_B8_BIT3(gbf, odd_even_i, "odd/even indicator", 4, 4, calling_party_s_odd_even_i); 
    A_B8_BIT1(gbf, spare, "Spare", 1, 3); 
    SKIP(1); 
    
    int i;
    for(i = 0; i < len; i++)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, subaddress_information, "Subaddress information", 1, 8); 
        len -= 1;
        SKIP(1); 
    }
    
    END_ELEMENT(); 
}

void called_party_subaddr(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Called party subaddress", called_part_subaddress); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Called party Subaddress IEI", 1, 8, "Called party Subaddress"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of called party subaddress contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_subaddress, "Type of subaddress", 5, 7, calling_party_s_type_subaddress); 
    A_B8_BIT3(gbf, odd_even_i, "odd/even indicator", 4, 4, calling_party_s_odd_even_i); 
    A_B8_BIT1(gbf, spare, "Spare", 1, 3); 
    SKIP(1); 
    
    int i;
    for(i = 0; i < len; i++)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, subaddress_information, "Subaddress information", 1, 8); 
        len -= 1;
        SKIP(1); 
    }
    
    END_ELEMENT(); 
}

void redirecting_party_subaddress(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Redirecting party subaddress", redirecting_party_subaddress); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Redirecting party Subaddress IEI", 1, 8, "Redirecting party Subaddress"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of redirecting party subaddress contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "Ext", 8, 8); 
    A_B8_BIT3(gbf, type_of_subaddress, "Type of subaddress", 5, 7, calling_party_s_type_subaddress); 
    A_B8_BIT3(gbf, odd_even_i, "odd/even indicator", 4, 4, calling_party_s_odd_even_i); 
    A_B8_BIT1(gbf, spare, "Spare", 1, 3); 
    SKIP(1); 
    
    int i;
    for(i = 0; i < len; i++)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, subaddress_information, "Subaddress information", 1, 8); 
        len -= 1;
        SKIP(1); 
    }
    
    END_ELEMENT(); 
}
 
void stream_identifier(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Stream Identifier", stream_identifier); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Stream Identifier IEI", 1, 8, "Stream Identifier"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Stream Identifier contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    int tmp = -1;
    B8_BIT(tmp, 1, 8);
    if(tmp == 0)
        A_B8_BIT2(gbf, stream_identifier_value, "Stream Identifier Value", 1, 8, "No bearer"); 
    else
        A_B8_BIT1(gbf, stream_identifier_value, "Stream Identifier Value", 1, 8); 
    SKIP(1);
    END_ELEMENT(); 
}

void ba_range(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("BA Range", ba_range); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "BA Range IEI", 1, 8, "BA Range"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of BA Range contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, number_of_ranges, "Number of Ranges", 1, 8); 
    len -= 1;
    SKIP(1); 

    int tmp = -1;
    char buf[100];
    memset(buf, 0x00, sizeof(buf));
    B16_BIT(tmp, 7, 16);
    sprintf(buf, "RANGE1_LOWER = %d", tmp);
    B8_HEX(); 
    A_B8_BIT2(gbf, range1_lower_h, "RANGE1_LOWER (high part)", 1, 8, "-"); 
    len -= 1;
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT2(gbf, range1_lower_l, "RANGE1_LOWER (low part)", 7, 8, buf); 
    memset(buf, 0x00, sizeof(buf));
    B16_BIT(tmp, 5, 14);
    sprintf(buf, "RANGE1_HIGHER = %d", tmp);
    A_B8_BIT2(gbf, range1_higher_h, "RANGE1_HIGHER (high part)", 1, 6, "-"); 
    len -= 1;
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT2(gbf, range1_higher_l, "RANGE1_HIGHER (low part)", 5, 8, buf); 
    memset(buf, 0x00, sizeof(buf));
    B16_BIT(tmp, 3, 12);
    sprintf(buf, "RANGE2_LOWER = %d", tmp);
    A_B8_BIT2(gbf, range2_higher_h, "RANGE2_LOWER (high part)", 1, 4, "-"); 
    len -= 1;
    SKIP(1); 

    if(len > 0)
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, range2_lower_l, "RANGE2_LOWER (low part)", 3, 8, buf); 
        memset(buf, 0x00, sizeof(buf));
        B16_BIT(tmp, 1, 10);
        sprintf(buf, "RANGE2_HIGHER = %d", tmp);
        A_B8_BIT2(gbf, range2_higher_h, "RANGE2_HIGHER (high part)", 1, 2, "-"); 
        len -= 1;
        SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, range2_higher_l, "RANGE2_HIGHER (low part)", 1, 8, buf); 
        len -= 1;
        SKIP(1); 
    }
    
    if(len > 0)
    {
        SKIP(len);
    }

    END_ELEMENT(); 
}

void group_channel_description(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Group Channel Description", grpup_channel_description); 
    if(iei == 1)
    {
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Group Channel Description IEI", 1, 8, "Group Channel Description"); 
        SKIP(1); 
    }

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Group Channel Description contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    int tmp;
    B8_BIT(tmp, 4, 8);
    if(tmp > 0 && tmp < 16)
        A_B8_BIT3(gbf, channel_type_a_t_o, "Channel type and TDMA offset", 4, 8, channel_description_channel_type_t_o); 
    else
        A_B8_BIT2(gbf, channel_type_a_t_o, "Channel type and TDMA offset", 4, 8, "reserved"); 
    A_B8_BIT1(gbf, tn, "TN", 1, 3); 
    len -= 1;
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, tsc, "TSC", 6, 8); 
    int type = -1;
    B8_BIT(type, 5, 5); 
    A_B8_BIT3(gbf, hopping_channel, "Hopping channel", 5, 5, channel_description_h); 
    char buf[12]; 
    memset(buf, 0x00, sizeof(buf)); 
    if (type == 0) 
    { 

		B16_BIT(type, 1, 10); 
        A_B8_BIT1(gbf, spare, "Spare", 3, 4); 
        A_B8_BIT2(gbf, arfcn_h, "ARFCH (high part)", 1, 2, "-"); 
        len -= 1;
        SKIP(1); 

        B8_HEX(); 
        sprintf(buf, "ARFCH=%d", type); 
        A_B8_BIT2(gbf, arfcn_l, "ARFCH (low part)", 1, 8, buf); 
        len -= 1;
        SKIP(1); 
    } 
    else 
    { 
        B16_BIT(type, 7, 12); 
        A_B8_BIT2(gbf, maio_h, "MAIO (high part)", 1, 4, "-"); 
        len -= 1;
        SKIP(1); 

        B8_HEX(); 
        sprintf(buf, "MAIO=%d", type); 
        A_B8_BIT2(gbf, arfcn_l, "MAIO (low part)", 7, 8, buf); 
        A_B8_BIT1(gbf, arfcn_l, "HSN", 1, 6); 
        len -= 1;
	    SKIP(1); 
    } 

    if(len > 0)
    {
        mac(len);
    }

    END_ELEMENT(); 
}

void group_cipher_key_number(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Group Cipher Key Number", group_cipher_key_number);
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT3(gbf, group_cipher_key_number, "Group Cipher Key Number", 1, 4, channel_release_group_cipher_k_n);
			SKIP(1);
		}
		else
		{
			B8_HEX(); 
			A_B8_BIT3(gbf, group_cipher_key_number, "Group Cipher Key Number", 5, 8, channel_release_group_cipher_k_n);
		}
	}
	else
	{
		B8_HEX(); 
		A_B8_BIT2(gbf, grpup_cipher_key_iei, "Group Cipher Key Number IEI", 5, 8, "Group Cipher Key Number");
    	A_B8_BIT3(gbf, group_cipher_key_number, "Group Cipher Key Number", 1, 4, channel_release_group_cipher_k_n);
    	SKIP(1);
	}
    END_ELEMENT();
}

void gprs_resumption(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("GPRS Resumption", gprs_resumption);
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT1(gbf, spare, "Spare", 2, 4);
			A_B8_BIT3(gbf, ack, "ACK", 1, 1, channel_release_gprs_resumption_ack);
			SKIP(1);
		}
		else
		{
			B8_HEX(); 
			A_B8_BIT1(gbf, spare, "Spare", 6, 8);
			A_B8_BIT3(gbf, ack, "ACK", 7, 7, channel_release_gprs_resumption_ack);
		}
	}
	else
	{
		B8_HEX(); 
		A_B8_BIT2(gbf, gprs_resumption_iei, "GPRS resumption IEI", 5, 8, "GPRS resumption");
	    A_B8_BIT1(gbf, spare, "Spare", 2, 4);
		A_B8_BIT3(gbf, ack, "ACK", 1, 1, channel_release_gprs_resumption_ack);
    	SKIP(1);
	}

    END_ELEMENT();
}

void cell_selection_indicator_after_release_of_all_tch_and_sdcch(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Cell selection indicator after release of all TCH and SDCCH IE", cell_selection_i); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Cell selection indicator after release of all TCH and SDCCH IEI", 1, 8, "Cell selection indicator after release of all TCH and SDCCH"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Cell selection indicator after release of all TCH and SDCCH value part", 1, 8); 
    SKIP(1); 

    SKIP(len);

    END_ELEMENT();
}

void enhanced_dtm_cs_release_indication(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Enhanced DTM CS Release Indication", enhanced_dtm_c_r_i);
	if(iei == 0)
	{
		if(location == 1)
		{
			A_B8_BIT1(gbf, spare, "Spare", 2, 4);
			A_B8_BIT3(gbf, ack, "IND", 1, 1, enhanced_dtm_r_i_ind);
			SKIP(1);
		}
		else
		{
			B8_HEX(); 
			A_B8_BIT1(gbf, spare, "Spare", 6, 8);
			A_B8_BIT3(gbf, ack, "IND", 7, 7, enhanced_dtm_r_i_ind);
		}
	}
	else
	{
		B8_HEX(); 
		A_B8_BIT2(gbf, gprs_resumption_iei, "Enhanced DTM CS Release Indication IEI", 5, 8, "Enhanced DTM CS Release Indication");
	    A_B8_BIT1(gbf, spare, "Spare", 2, 4);
		A_B8_BIT3(gbf, ack, "IND", 1, 1, enhanced_dtm_r_i_ind);
    	SKIP(1);
	}

    END_ELEMENT();
}

void group_channel_description_2(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Group Channel Description 2", group_channel_description_2); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Group Channel Description 2 IEI", 1, 8, "Group Channel Description 2"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Group Channel Description 2", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    int tmp;
    B8_BIT(tmp, 4, 8);
    if(tmp > 0 && tmp < 31)
        A_B8_BIT3(gbf, channel_type_a_t_o, "Channel type and TDMA offset", 4, 8, channel_description_channel_type_t_o); 
    else
        A_B8_BIT2(gbf, channel_type_a_t_o, "Channel type and TDMA offset", 4, 8, "reserved"); 
    A_B8_BIT1(gbf, tn, "TN", 1, 3); 
    len -= 1;
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, tsc, "TSC", 6, 8); 
    A_B8_BIT1(gbf, spare, "Spare", 5, 5); 
    char buf[12]; 
    memset(buf, 0x00, sizeof(buf)); 

    B16_BIT(tmp, 7, 12); 
    A_B8_BIT2(gbf, maio_h, "MAIO (high part)", 1, 4, "-"); 
    len -= 1;
    SKIP(1); 

    B8_HEX(); 
    sprintf(buf, "MAIO=%d", tmp); 
    A_B8_BIT2(gbf, arfcn_l, "MAIO (low part)", 7, 8, buf); 
    A_B8_BIT1(gbf, arfcn_l, "HSN", 1, 6); 
    len -= 1;
	SKIP(1); 
    
    if(len > 0)
    {
        mac(len);
    }

    END_ELEMENT();
}

void ba_list_pref(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("BA List Pref", ba_list_pref); 

    int len = -1;
    B8_BIT(len, 1, 8);

    SKIP(len);
 
    END_ELEMENT();
}

void utran_freq_list(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("UTRAN Freq List", utran_freq_list); 

    int len = -1;
    B8_BIT(len, 1, 8);

    SKIP(len);
 
    END_ELEMENT();
}

void low_layer_comp(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Low layer compatibility", low_layer_compatibility); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Low layer compatibility IEI", 1, 8, "Low layer compatibility"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of the low layer compatibility contents", 1, 8); 
    SKIP(1); 

    int ext = 1;
    int tmp = -1;
    if(len > 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, coding_standard, "Coding standard", 6, 7, low_layer_co_coding_standard); 
        if(tmp == 0 || tmp == 8 || tmp == 9 || tmp == 16 || tmp == 17 || tmp == 24)
            A_B8_BIT3(gbf, information_transfer_c, "Information transfer capability", 1, 5, low_layer_co_information_transfer_c); 
        else
            A_B8_BIT2(gbf, information_transfer_c, "Information transfer capability", 1, 5, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, negotiation_indicator, "Negotiation indicator", 7, 7, low_layer_co_negotiation_indicator); 
        A_B8_BIT1(gbf, spare, "Spare", 1, 6); 
        len -= 1;
        ext = 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_BIT(tmp, 1, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, transfer_mode, "Transfer mode", 6, 7, low_layer_co_transfer_mode); 
        if(tmp == 16 || tmp == 17 || tmp == 19 || tmp == 21 || tmp == 23 || tmp == 24)
            A_B8_BIT3(gbf, information_transfer_r, "Information transfer rate", 1, 5, low_layer_co_information_transfer_r); 
        else
            A_B8_BIT2(gbf, information_transfer_r, "Information transfer rate", 1, 5, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, rate_multiplier, "Rate multiplier", 1, 7); 
        len -= 1;
        SKIP(1);
    }
     
    if(len > 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, layer1_ident, "Layer 1 ident", 6, 7); 
        if((tmp > 0 && tmp < 6) || tmp == 8 || tmp == 9)
            A_B8_BIT3(gbf, user_information_l1_p, "User information layer 1 protocol", 1, 5, low_layer_co_user_information_l1_p); 
        else
            A_B8_BIT2(gbf, user_information_l1_p, "User information layer 1 protocol", 1, 5, "Reserved"); 
        len -= 1;
        SKIP(1);
    }
        
    if(len > 0 && ext == 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, synchronous_asynchronous, "Synchronous/Asynchronous", 7, 7, low_layer_co_synchronous_asynchronous); 
        A_B8_BIT3(gbf, negotiation, "Negotiation", 6, 6, low_layer_co_negotiation); 
        if((tmp >= 0 && tmp < 13) || (tmp > 13 && tmp < 17) || (tmp > 20 && tmp < 32))
            A_B8_BIT3(gbf, user_rate, "User rate", 1, 5, low_layer_co_user_rate); 
        else
            A_B8_BIT2(gbf, user_rate, "User rate", 1, 5, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_BIT(ext, 8, 8);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, intermediate_rat, "Intermediate rat", 6, 7, low_layer_co_intermediate_rate); 
        A_B8_BIT3(gbf, nic_tx, "NIC on Tx", 5, 5, low_layer_co_nic_tx); 
        A_B8_BIT3(gbf, nic_rx, "NIC on Rx", 4, 4, low_layer_co_nic_rx); 
        A_B8_BIT3(gbf, flow_control_tx, "Flow control on transmission", 3, 3, low_layer_co_flow_control_tx); 
        A_B8_BIT3(gbf, flow_control_rx, "Flow control on reception", 2, 2, low_layer_co_flow_control_rx); 
        A_B8_BIT1(gbf, spare, "Spare", 1, 1); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_BIT(ext, 8, 8);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, rate_adaption_h_n_h, "Rate adaption header/no header", 7, 7, low_layer_co_rate_adaption_h); 
        A_B8_BIT3(gbf, multiple, "Multiple", 6, 6, low_layer_co_multiple_frame_e_s_i_d_l); 
        A_B8_BIT3(gbf, mode, "Mode", 5, 5, low_layer_co_mode_operation); 
        A_B8_BIT3(gbf, logical_link_l_i_n, "Logical link identifier negotiation", 4, 4, low_layer_co_logical_link_i_n); 
        A_B8_BIT3(gbf, assignor_assignee, "Assignor Assignee", 3, 3, low_layer_co_assignor_assignee); 
        A_B8_BIT3(gbf, in_band_negot, "in-band/out-band negotiation", 2, 2, low_layer_co_in_band_o_b_n); 
        A_B8_BIT1(gbf, spare, "Spare", 1, 1); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 3);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, number_stop_b, "Number of stop bits", 6, 7, low_layer_co_number_stop_b); 
        A_B8_BIT3(gbf, number_data_b, "Number of data bits", 4, 5, low_layer_co_number_data_b); 
        if(tmp == 0 || (tmp > 1 && tmp < 6)) 
            A_B8_BIT3(gbf, parity, "Parity information", 1, 3, low_layer_co_parity_information); 
        else
            A_B8_BIT2(gbf, parity, "Parity information", 1, 3, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_BIT(tmp, 1, 6);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, duplex_mode, "Duplex mode", 7, 7, low_layer_co_duplex_mode); 
        if((tmp >= 0 && tmp < 6) || (tmp > 16 && tmp < 29) || (tmp > 31 && tmp < 64))
            A_B8_BIT3(gbf, modem_type, "Modem type", 1, 6, low_layer_co_modem_type); 
        else
            A_B8_BIT2(gbf, modem_type, "Modem type", 1, 6, "Reserved"); 
        len -= 1;
        ext = 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, layer2_ident, "Layer 2 ident", 6, 7); 
        if(tmp == 1 || tmp == 2 || tmp == 15 || tmp == 6 || (tmp > 7 && tmp < 18))
            A_B8_BIT3(gbf, user_information_l2_p, "User information layer 2 protocol", 1, 5, low_layer_co_user_information_l2_p); 
        else
            A_B8_BIT2(gbf, user_information_l2_p, "User information layer 2 protocol", 1, 5, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, mode, "Mode of operation", 6, 7, low_layer_co_mode_operation_6a); 
        A_B8_BIT1(gbf, spare, "Spare", 3, 5); 
        A_B8_BIT3(gbf, q933_use, "Q.933 use", 1, 2, low_layer_co_q933_use); 
        len -= 1;
        SKIP(1);
    }
        
    if(len > 0 && ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, user_specified_l2_o_i, "User specified layer protocol information", 1, 7); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, window_size, "Window size(k)", 1, 7); 
        len -= 1;
        ext = 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, layer3_ident, "Layer 3 ident", 6, 7); 
        if(tmp == 16 || tmp == 2 || (tmp > 5 && tmp < 12))
            A_B8_BIT3(gbf, user_information_l3_p, "User information layer 3 protocol", 1, 5, low_layer_co_user_information_l3_p); 
        else
            A_B8_BIT2(gbf, user_information_l3_p, "User information layer 3 protocol", 1, 5, "Reserved"); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_BIT(ext, 8, 8);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, mode, "Mode", 6, 7, low_layer_co_mode_operation_7a); 
        A_B8_BIT1(gbf, spare, "Spare", 1, 5); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, optional_layer3_p_i, "Optional layer 3 protocol information", 1, 7); 
        len -= 1;
        ext = 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_BIT(ext, 8, 8);
        B8_BIT(tmp, 1, 4);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, spare, "Spare", 5, 7); 
        if(tmp > 3 && tmp < 13)
        A_B8_BIT3(gbf, default_packet_s, "Default packet size", 1, 4, low_layer_co_default_packet_s); 
        len -= 1;
        SKIP(1);
    }

    if(len > 0 && ext == 0)
    {
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT1(gbf, packet_window_s, "Packet window size", 1, 7); 
        SKIP(1);
    }
        
    END_ELEMENT();
}

void high_layer_comp(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("High layer compatibility", high_layer_compatibility); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "High layer compatibility IEI", 1, 8, "High layer compatibility"); 
        SKIP(1); 
    } 

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of the high layer compatibility contents", 1, 8); 
    SKIP(1); 
    
    int ext = 1;
    int tmp = -1;
    if(len > 0)
    {
        B8_BIT(tmp, 3, 5);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        A_B8_BIT3(gbf, coding_standard, "Coding standard", 6, 7, high_layer_c_coding_standard); 
        if(tmp == 4)
                A_B8_BIT2(gbf, interpretation, "Interpretation", 3, 5, "First(primary or only) high layer characteristics identification(in octet 4) to be used in the call"); 
        else
                A_B8_BIT2(gbf, interpretation, "Interpretation", 3, 5, "reserved"); 
        B8_BIT(tmp, 1, 2);
        if(tmp == 1)
            A_B8_BIT2(gbf, presentation_method_o_p_p, "Presentation method of protocol profile", 1, 2, "High layer protocol profile(without specification of attributes)"); 
        else
            A_B8_BIT2(gbf, presentation_method_o_p_p, "Presentation method of protocol profile", 1, 2, "reserved"); 
        len -= 1;
        SKIP(1); 
    }
    if(len > 0)
    {
        B8_BIT(tmp, 1, 7);
        B8_BIT(ext, 8, 8);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        if(tmp == 1 || tmp == 4 || tmp == 33 || tmp == 36 || tmp == 40 || tmp == 49 || tmp == 50 || tmp == 51 || tmp == 53 || tmp == 56 || tmp == 65 || tmp == 127 || (tmp > 93 && tmp < 112))
            A_B8_BIT3(gbf, high_layer_c_i, "High layer characteristics identification", 1, 7, high_layer_c_high_layer_c_i); 
        else
            A_B8_BIT2(gbf, high_layer_c_i, "High layer characteristics identification", 1, 7, "Reserved"); 
        len -= 1;
        SKIP(1); 
    }
    if(len > 0 && ext == 0)
    {
        B8_BIT(tmp, 1, 7);
        B8_HEX(); 
        A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
        if(tmp == 1 || tmp == 4 || tmp == 33 || tmp == 36 || tmp == 40 || tmp == 49 || tmp == 50 || tmp == 51 || tmp == 53 || tmp == 56 || tmp == 65 || tmp == 127 || (tmp > 93 && tmp < 112))
            A_B8_BIT3(gbf, extended_high_l_c_i, "Extended high layer characteristics identification", 1, 7, high_layer_c_high_layer_c_i); 
        else
            A_B8_BIT2(gbf, extended_high_l_c_i, "Extended high layer characteristics identification", 1, 7, "Reserved"); 
        SKIP(1); 
    }

    END_ELEMENT();
}

void talker_identity(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Talker Identity", talker_identity); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Talker Identity IEI", 1, 8, "Talker Identity"); 
        SKIP(1); 
    } 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of talker identity contents", 1, 8); 
    SKIP(1); 

    A_B8_BIT1(gbf, spare, "Spare", 4, 8); 
    A_B8_BIT1(gbf, filler_bits, "Filler Bits", 1, 3); 
    SKIP(1); 

    A_B8_BIT1(gbf, talker_identity_field, "Talker Identity field", 1, 8); 
    SKIP(1); 
 
    END_ELEMENT();
}

void talker_priority_status(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Talker Priority Status", talker_priority_status); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Talker Priority Status IEI", 1, 8, "Talker Priority Status"); 
        SKIP(1); 
    } 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Talker Priority Status", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT3(gbf, es, "ES - Emergency Status", 8, 8, talker_priority_s_es); 
    A_B8_BIT1(gbf, spare, "Spare", 5, 7); 
    A_B8_BIT3(gbf, uai, "UAI- Uplink Access Indication", 4, 4, talker_priority_s_uai); 
    A_B8_BIT3(gbf, priority, "Priority", 1, 3, talker_priority_s_priority); 
    SKIP(1); 

    END_ELEMENT();
}

void alerting_pattern(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Alerting Pattern", alerting_pattern); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Alerting Pattern IEI", 1, 8, "Alerting Pattern"); 
        SKIP(1); 
    } 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of alerting pattern contents", 1, 8); 
    SKIP(1); 

    int tmp = -1;
    B8_BIT(tmp, 1, 4);
    B8_HEX(); 
    A_B8_BIT1(gbf, spare, "Spare", 5, 8); 
    if((tmp >= 0 && tmp < 3) || (tmp > 3 && tmp < 9))
        A_B8_BIT3(gbf, alerting_pattern_v, "Alerting Pattern value", 1, 4, alerting_pattern_n_alerting_pattern_v); 
    else
        A_B8_BIT2(gbf, alerting_pattern_v, "Alerting Pattern value", 1, 4, "reserved"); 
    SKIP(1); 
 
    END_ELEMENT();
}

void network_call_control_capabilities(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Network Call Control Capabilities", network_call_c_c); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Network Call Control Capabilities IEI", 1, 8, "Network Call Control Capabilities"); 
        SKIP(1); 
    } 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of NW Call Control Cap. contents", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, spare, "Spare", 2, 8); 
    A_B8_BIT3(gbf, mcs, "MCS", 1, 1, network_call_c_c_mcs); 
    SKIP(1); 

    END_ELEMENT();
}

void cause_of_no_cli(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Cause of No CLI", cause_o_n_c); 

	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Cause of No CLI IEI", 1, 8, "Cause of No CLI"); 
        SKIP(1); 
    } 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of cause of No CLI contents", 1, 8); 
    SKIP(1); 

    int tmp = -1;
    B8_BIT(tmp, 1, 8);
    B8_HEX(); 
    if(tmp >= 0 && tmp < 4)
        A_B8_BIT3(gbf, cause_no_c, "Cause of No CLI", 1, 8, cause_no_c_cause_no_cli); 
    else
        A_B8_BIT2(gbf, cause_no_c, "Cause of No CLI", 1, 8, "Unavailable"); 
    SKIP(1); 

    END_ELEMENT();
}

void backup_bearer_capability(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Backup bearer capability", backup_bearer_capability); 
	int tmp; 
	uint8_t ext = 1; 
	int length; 
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Backup bearer capability IEI", 1, 8, "Backup bearer capability"); 
        SKIP(1); 
    } 
	B8_BIT(length, 1, 8); 
	B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of the backup bearer capability contents", 1, 8); 
    SKIP(1); 
	
	B8_HEX(); 
	B8_BIT(ext, 8, 8); 
    A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
    A_B8_BIT3(gbf, radio_channel_r, "Radio channel requirement", 6, 7, bearer_capability_radio_channel_r); 
    A_B8_BIT3(gbf, coding_standard, "Coding standard", 5, 5, bearer_capability_coding_standard); 
    A_B8_BIT3(gbf, transfer_mode, "Transfer mode", 4, 4, bearer_capability_transfer_mode); 
    A_B8_BIT3(gbf, information_transfer_c, "Information transfer capability", 1, 3, bearer_capability_information_transfer_c); 
	length -= 1; 
    SKIP(1); 
	
	if(length > 0) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, compression, "Compression", 7, 7, bearer_capability_compression_n_m); 
		A_B8_BIT3(gbf, structure, "Structure", 5, 6, bearer_capability_structure); 
		A_B8_BIT3(gbf, duplex_mode, "Duplex mode", 4, 4, bearer_capability_duplex_mode); 
		A_B8_BIT3(gbf, configuration, "Configuration", 3, 3, bearer_capability_configuration); 
		A_B8_BIT3(gbf, nirr, "NIRR ", 2, 2, bearer_capability_nirr); 
		A_B8_BIT3(gbf, establishment, "Establishment", 1, 1, bearer_capability_establishment); 
		length -= 1; 
		SKIP(1); 
	}
	if(length > 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 3; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, access_identity, "Access identity", 6, 7, bearer_capability_access_identity); 
		A_B8_BIT3(gbf, rate_adaption, "Rate adaption", 4, 5, bearer_capability_rate_adaption); 
		A_B8_BIT3(gbf, signalling_access_p, "Signalling access protocol", 1, 3, bearer_capability_signalling_access_p); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(ext == 3) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, other_itc, "Other ITC", 6, 7, bearer_capability_other_itc); 
		A_B8_BIT3(gbf, other_rate_adaption, "Other rate adaption", 4, 5, bearer_capability_other_rate_a); 
		A_B8_BIT1(gbf, spare, "Spare", 1, 3); 
		length -= 1; 
		SKIP(1); 
	}
	
	if(length > 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 5; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 6, 7); 
		if(tmp == 1) 
		{
			A_B8_BIT2(gbf, layer1_id, "layer 1 id.", 6, 7, "octet identifier"); 
		}
		else
		{
			A_B8_BIT2(gbf, layer1_id, "layer 1 id.", 6, 7, "reserved"); 
		}
		B8_BIT(tmp, 2, 5); 
		if(tmp == 0) 
		{
			A_B8_BIT2(gbf, User_information_l_p, "User information layer 1 protocol", 2, 5, "default layer 1 protocol"); 
		}
		else
		{
			A_B8_BIT2(gbf, User_information_l_p, "User information layer 1 protocol", 2, 5, "reserved"); 
		}
		A_B8_BIT3(gbf, sync_async, "sync/async", 1, 1, bearer_capability_synchronous_asynchronou); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 5) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 6; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, numb_stop_bits, "numb.stop bits", 7, 7, bearer_capability_number_stop_b); 
		B8_BIT(tmp, 6, 6); 
		if(tmp == 1) 
		{
			A_B8_BIT2(gbf, negotiation, "negotiation", 6, 6, "in-band negotiation not possible"); 
		}
		else
		{
			A_B8_BIT2(gbf, negotiation, "negotiation", 6, 6, "reserved"); 
		}
		A_B8_BIT3(gbf, numb_data_bits, "numb.data bits", 5, 5, bearer_capability_number_data_b_e_p); 
		A_B8_BIT3(gbf, user_rate, "User rate", 1, 4, bearer_capability_user_rate); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 6) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 7; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, intermed_rate, "intermed. rate", 6, 7, bearer_capability_intermediate_rate); 
		A_B8_BIT3(gbf, nic_on_tx, "NIC on TX", 5, 5, bearer_capability_nic_tx); 
		A_B8_BIT3(gbf, mic_on_rx, "NIC on RX", 4, 4, bearer_capability_nic_rx); 
		A_B8_BIT3(gbf, parity, "Parity", 1, 3, bearer_capability_parity_information); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 7) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 8; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, connection_element, "connection element", 6, 7, bearer_capability_connection_element); 
		B8_BIT(tmp, 1, 5); 
		if(tmp >= 0 && tmp <= 8)
		{
			A_B8_BIT3(gbf, modem_type, "modem type", 1, 5, bearer_capability_modem_type); 
		}
		else
		{
			A_B8_BIT2(gbf, modem_type, "modem type", 1, 5, "reserved"); 
		}
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 8) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 9; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, other_modem_type, "Other modem type", 6, 7, bearer_capability_other_modem_type); 
		B8_BIT(tmp, 1, 5); 
		if(tmp == 0 || tmp == 1 || (tmp > 3 && tmp < 12))
		{
			A_B8_BIT3(gbf, fixed_network_user_rate, "Fixed network user rate", 1, 5, bearer_capability_fixed_network_u_r); 
		}
		else
		{
			A_B8_BIT2(gbf, fixed_network_user_rate, "Fixed network user rate", 1, 5, "reserved"); 
		}
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 9) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 10; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 7, 7); 
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 7, 7, "TCH/F14.4 not acceptable"); 
		}
		else
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 7, 7, "TCH/F14.4 acceptable"); 
		}
		A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 6, 6, "Spare"); 
		B8_BIT(tmp, 5, 5); 
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 5, 5, "TCH/F9.6 not acceptable"); 
		}
		else
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 5, 5, "TCH/F9.6 acceptable"); 
		}
		B8_BIT(tmp, 4, 4); 
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 4, 4, "TCH/F4.8 not acceptable"); 
		}
		else
		{
			A_B8_BIT2(gbf, acceptable_channel_codings, "Acceptable channel codings", 4, 4, "TCH/F4.8 acceptable"); 
		}
		A_B8_BIT3(gbf, maximum_number_o_t_c, "Maximum number of traffic channels", 1, 3, bearer_capability_maximum_number_o_t_c); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 10) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 11; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 5, 7); 
		if(tmp >= 0 && tmp <= 4)
			A_B8_BIT3(gbf, uimi, "UIMI", 5, 7, bearer_capability_uimi); 
		else
			A_B8_BIT2(gbf, uimi, "UIMI", 5, 7, "reserved"); 
		B8_BIT(tmp, 1, 4); 
		if((tmp > 0 && tmp < 4) || (tmp > 4 && tmp < 13))
			A_B8_BIT3(gbf, ext_f, "Wanted air interface user rate", 1, 4, bearer_capability_wanted_air_i_u_r); 
		else
			A_B8_BIT2(gbf, ext_f, "Wanted air interface user rate", 1, 4, "reserved"); 
		length -= 1; 
		SKIP(1); 
	}
	if(ext == 11) 
	{
		B8_HEX(); 
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		B8_BIT(tmp, 7, 7); 
		if(tmp == 0)
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 7, 7, "TCH/F28.8 not acceptable"); 
		else
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 7, 7, "TCH/F28.8 acceptable"); 
		B8_BIT(tmp, 6, 6);
		if(tmp == 0)
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 6, 6, "TCH/F32.0 not acceptable"); 
		else
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 6, 6, "TCH/F32.0 acceptable"); 
		B8_BIT(tmp, 5, 5);
		if(tmp == 0)
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 5, 5, "TCH/F43.2 not acceptable"); 
		else
			A_B8_BIT2(gbf, acceptable_channel_c_e, "Acceptable channel codings extended", 5, 5, "TCH/F43.2 acceptable"); 
		A_B8_BIT3(gbf, asymmetry_indication, "Asymmetry Indication", 3, 4, bearer_capability_asymmetry_indication); 
		A_B8_BIT1(gbf, spare, "Spare", 1, 2); 
		length -= 1; 
		SKIP(1); 
	}
	if(length > 0) 
	{
		B8_HEX(); 
		B8_BIT(ext, 8, 8); 
		if(ext == 0)
		{
			ext = 12; 
		}
		A_B8_BIT3(gbf, ext_f, "Ext Flag", 8, 8, ext_dict); 
		A_B8_BIT3(gbf, layer2_id, "layer 2 id.", 6, 7, bearer_capability_layer2_identity); 
		B8_BIT(tmp, 1, 5);
		if(tmp == 6 || tmp == 8 || tmp == 9 || (tmp >= 10 && tmp <= 13))
			A_B8_BIT3(gbf, user_information_l2_p, "User information layer 2 protocol", 1, 5, bearer_capability_user_information_l2_p); 
		else
			A_B8_BIT2(gbf, user_information_l2_p, "User information layer 2 protocol", 1, 5, "reserved"); 
		SKIP(1); 
	}
		
    END_ELEMENT(); 
}

void clir_suppression(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("CLIR suppression", clir_suppression); 

    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT1(gbf, iei, "CLIR suppression IEI", 1, 8); 
        SKIP(1); 
    } 

    END_ELEMENT(); 
}

void clir_invocation(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("CLIR invocation", clir_invocation); 

    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT1(gbf, iei, "CLIR invocation IEI", 1, 8); 
        SKIP(1); 
    } 

    END_ELEMENT(); 
}

void redial(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Redial", redial); 

    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT1(gbf, iei, "Redial IEI", 1, 8); 
        SKIP(1); 
    } 

    END_ELEMENT(); 
}

void call_control_capabilities(uint8_t iei, uint8_t location)
{
    int tmp; 
    BEGIN_ELEMENT("Call Control Capabilities", call_control_capabilities); 
    char buf[1024]={};
    if(iei==1) 
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Call Control Capabilities IEI", 1, 8, "Call Control Capabilities"); 
        SKIP(1); 
    }    
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "Length of Call Control Capabilities contents", 1, 8);  
    SKIP(1); 
    B8_BIT(tmp,5,8);
    B8_HEX(); 
    sprintf(buf,"%d bearer supported", tmp);
    A_B8_BIT2(gbf, maximum_number_of_supported_bearers, "Maximum number of supported bearers", 5, 8, buf); 
    A_B8_BIT3(gbf, mact, "MCAT", 4, 4, call_control_c_mcat); 
    A_B8_BIT3(gbf, enicm, "ENICM", 3, 3,call_control_c_enicm ); 
    A_B8_BIT3(gbf, pcp, "PCP", 2, 2, call_control_c_pcp); 
    A_B8_BIT3(gbf, dtmf, "DTMF", 1, 1,  call_control_c_dtmf); 
    SKIP(1); 
    B8_HEX(); 
    A_B8_BIT1(gbf, spare, "spare", 5, 8);  
    A_B8_BIT1(gbf, maximum_number_of_supported_bearers, "Maximum number of supported bearers", 1, 4);  
    SKIP(1);
    END_ELEMENT();
}
void supported_codec_list(uint8_t iei, uint8_t location)
{
    int tmp;
    BEGIN_ELEMENT("Supported codec list", supported_codec_list );
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Supported Codec List IEI", 1, 8,"Supported Codec List");
        SKIP(1);
    }
    B8_BIT(tmp, 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length_of_supported_codec_list, "Length Of Supported Codec list", 1, 8);

    SKIP(tmp+1);
    END_ELEMENT();
}
void service_category(uint8_t iei, uint8_t location)
{
    char buf[1000]={};
    int tmp;
    BEGIN_ELEMENT("Service category", service_category);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Service Category IEI", 1, 8, "Service Category");
        SKIP(1);
    }
    B8_HEX();
    A_B8_BIT1(gbf, length_of_service_category, "Length of Service Category", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(gbf, spare, "spare", 8, 8);
    B8_BIT(tmp, 7, 7);
    if(tmp==1)
    strcat(buf, "automatically initiated eCall");
    B8_BIT(tmp, 6, 6);
    if(tmp==1)
    strcat(buf, " manually initiated eCall");
    B8_BIT(tmp, 5, 5);
    if(tmp==1)
    strcat(buf, " Mountain Rescue");
    B8_BIT(tmp, 4, 4);
    if(tmp==1)
    strcat(buf, " Marine Guard");
    B8_BIT(tmp, 3, 3);    if(tmp==1)
    strcat(buf, " Fire Brigade");
    B8_BIT(tmp, 2, 2);
    if(tmp==1)
    strcat(buf, " Ambulance");
    B8_BIT(tmp, 1, 1);
    if(tmp==1)
    strcat(buf, " Police");


    A_B8_BIT2(gbf, , "Emergency Service Category Value", 1, 7, buf);
    SKIP(1);
    END_ELEMENT();
}
void reverse_call_setup_direction(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Reverse call setup direction", reverse_call_setup_direction );
    if(iei==1)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "reverse call setup direction IEI", 1, 8,"reverse call setup direction");
        SKIP(1);
    }    
    END_ELEMENT();
}
void network_initiated_service_upgrade_indicator(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Network-initiated Service Upgrade indicator", network_initiated_service_upgrade_indicator);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Network-initiated Service Upgrade indicator IEI", 1, 8,"network_initiated_service_upgrade_indicator");
        SKIP(1);
    }
    END_ELEMENT();
}

//liusai(4450-5049)
void cell_identity(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cell Identity", cell_identity);
    
    int tmp; 
    char buf[10] = {0}; 
    if(iei)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Cell Identity IEI", 1, 8, "Cell Identity");
        SKIP(1);     
    }    
    
    B8_HEX();
    B16_BIT(tmp, 1, 16); 
    sprintf(buf, "Cl value=%d", tmp);
    A_B8_BIT2(gbf, cl_value, "Cl value", 1, 8, "-");
    SKIP(1);
    B8_HEX();
    A_B8_BIT2(gbf, cl_value_continued, "Cl value (continued)", 1, 8, buf);
    SKIP(1);

    END_ELEMENT();

}

void control_channel_description(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Control Channel Description", control_channel_description);
    
    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Control Channel Description IEI", 1, 8, "Control Channel Description");
        SKIP(1);
    }

    B8_HEX();
    int tmp = -1;
    B8_BIT(tmp, 1, 3);
        A_B8_BIT3(gbf, mscr, "MSCR", 8, 8, control_channel_description_mscr);
        A_B8_BIT3(gbf, att, "ATT", 7, 7, control_channel_description_att);
        A_B8_BIT1(gbf, bs_ag_blks_r, "BS_AG_BLKS_RES", 4, 6);
        A_B8_BIT3(gbf, ccch_conf, "CCCH CONF", 1, 3, control_channel_description_ccch_conf);
    SKIP(1);

    B8_HEX();
        A_B8_BIT3(gbf, si22ind, "SI22IND", 8, 8, control_channel_description_si22ind);
        A_B8_BIT3(gbf, cbq3, "CBQ3", 6, 7, control_channel_description_cbq3);
        A_B8_BIT1(gbf, spare, "Spare", 4, 5);
        A_B8_BIT3(gbf, bs-pa-mfrms, "BS-PA-MFRMS", 1, 3, control_channel_description_bs_pa_m);

    SKIP(1);

    B8_HEX();
       A_B8_BIT1(gbf, t3212, "T3212 time-out value", 1, 8 );
    SKIP(1);

    END_ELEMENT();
}

void cell_options_bcch(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cell Options (BCCH)",cell_option);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Cell Options (BCCH) IEI", 1, 8, "Cell Options (BCCH)");
        SKIP(1);
    }

    B8_HEX();
        A_B8_BIT3(gbf, dn-ind, "DN-IND", 8, 8, cell_options_s_dynamic_arfcn_m_i );
        A_B8_BIT3(gbf, pwrc, "PWRC", 7, 7, cell_options_s_power_control_i);
        A_B8_BIT3(gbf, dtx, "DTX", 5, 6, cell_options_s_dtx_indicator1);
        A_B8_BIT3(gbf, radio_link_t, "RADIO-LINK-TIMEOUT", 1, 4, cell_options_radio_link_t);
    SKIP(1);

    END_ELEMENT();
}

void cell_selection_parameters(uint8_t iei, uint8_t location, uint8_t flag)
{
    BEGIN_ELEMENT("Cell Selection Parameters", cell_selection_parameters);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Cell Selection Parameters IEI", 1, 8, "Cell Selection Parameters");
        SKIP(1);
    }

    B8_HEX();
        A_B8_BIT3(gbf, cell_reselect_h, "CELL-RESELECT HYSTERESIS", 6, 8, cell_selection_p_cell_reselect_h);
        A_B8_BIT1(gbf, ms-txpwr-max-cch, "MS-TXPWR-MAX-CCH", 1, 5);
    SKIP(1);

    B8_HEX();
    if(flag == 0)
    {
        A_B8_BIT3(gbf, acs, "ACS", 8, 8, cell_selection_p_acs_t3);
    }
    else 
    {
        A_B8_BIT3(gbf, acs, "ACS", 8, 8, cell_selection_p_acs_t4);
    }
        A_B8_BIT3(gbf, neci, "NECI", 7, 7, cell_selection_p_neci);
        A_B8_BIT1(gbf, rxlev_access_m, "RXLEV-ACCESS-MIN", 1, 6);
    SKIP(1);

    END_ELEMENT();
}

void ac(int len)
{
    char buf[100];
    char *p = NULL;
    int i, j, k, tmp;
    for(i = 0; i < len; i++)
    {
        int pos = 0;
        memset(buf, 0x00, sizeof(buf));
        p = buf;
        strcpy(buf, "AC = ");
        p += 5;

        for(j = 8, k = 1; j >= 1; j--, k++) 
        {
            B8_BIT(tmp, j, j);  
            if(tmp == 0)
            {
                pos += sprintf(p+pos, "%d ", (len-i)*8-k);
            }
        }
        B8_HEX();
        A_B8_BIT2(gbf, ac, "AC = ", 1, 8, buf);
        SKIP(1);
    }
}

void rach_control_parameters(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("RACH Control Parameters", rach_control_parameters);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "RACH Control Parameters IEI", 1, 8, "RACH Control Parameters");
        SKIP(1);
    }

    B8_HEX();
        A_B8_BIT3(gbf, max_retrans, "Max retrans", 7, 8, rach_control_p_max_retrans);
        A_B8_BIT3(gbf, tx_integer, "Tx-integer", 3, 6, rach_control_p_tx_integer);
        A_B8_BIT3(gbf, cell_barr_access, "CELL BARR ACCESS", 2, 2, rach_control_p_cell_bar_access);
        A_B8_BIT3(gbf, re, "RE", 1, 1, rach_control_p_re);
    SKIP(1);

    ac(2);

    END_ELEMENT();
}

void cell_options_sacch(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cell Options (SACCH)",cell_options_sacch);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Cell Options (SACCH) IEI", 1, 8, "Cell Options (SACCH)");
        SKIP(1);
    }

    B8_HEX();
        int tmp[3] = {0};
        B8_BIT(tmp[2], 8, 8);
        B8_BIT(tmp[1], 6, 6);
        B8_BIT(tmp[0], 5, 5);
        A_B8_BIT3(gbf, dtx, "DTX", tmp[0], tmp[2], cell_options_s_dtx_indicator2);
        A_B8_BIT3(gbf, pwrc, "PWRC", 7, 7, cell_options_s_power_control_i);
        A_B8_BIT3(gbf, radio_link_t, "RADIO-LINK-TIMEOUT", 1, 4, cell_options_radio_link_t);
    SKIP(1);

    END_ELEMENT();
}

void ncc_permitted(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("NCC Permitted",ncc_permitted);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "NCC Permitted IEI", 1, 8, "NCC Permitted");
        SKIP(1);
    }

    B8_HEX();
        char buf[10] = {""};
        int tmp, i;
        int num = 0;
        memset(buf, 0x00, sizeof(buf));
        B8_BIT(tmp, 1, 8);
        for(i = 0; i < 8; i++)
        {
            if(tmp%2 == 0)
            {
                tmp = tmp/2;
                num++;
            }
            else{
                sprintf(buf, "%d", num);
                break;
            }
        }
        A_B8_BIT2(gbf, ncc_permitted, "NCC Permitted", 1, 8, buf);
    SKIP(1);

    END_ELEMENT();
}

void handover_reference(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Handover Reference", handover_reference);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Handover Reference IEI", 1, 8, "Handover Reference");
        SKIP(1);
    }
    B8_HEX();
    A_B8_BIT1(gbf, handover_reference_v, "Handover reference value", 1, 8);
    SKIP(1);

    END_ELEMENT();
}

void cell_description(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cell Description", cell_description);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Cell Description IEI", 1, 8, cell_description);
        SKIP(1);
    }
    char buf[100] = {0};
    char *p = buf;
    int tmp;
    int pos = 0;

    B8_HEX();
    B8_BIT(tmp, 7, 8);
    dec_to_bin(tmp, buf);
    p = p + strlen(buf);
    A_B8_BIT2(gbf, bcch_arfcn_h, "BCCH ARFCN (High Part)", 7, 8, "-");
    A_B8_BIT1(gbf, ncc, "NCC", 4, 6);
    A_B8_BIT1(gbf, bcc, "BCC", 1, 3);
    SKIP(1);

    B8_HEX();
    B8_BIT(tmp, 1, 8);
    dec_to_bin(tmp, p);
    tmp = bin_to_dec(buf);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "BCCH ARFCN = %d", tmp);
    A_B8_BIT2(gbf, bcch_arfcn_l, "BCCH ARFCN (Low Part)", 1, 8, buf);
    SKIP(1);

    END_ELEMENT();
}

void channel_description_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Channel Description", channel_description);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Channel Description IEI", 1, 8, channel_description);
        SKIP(1);
    }

    B8_HEX();
      int tmp;
        B8_BIT(tmp, 4, 8);
        if(tmp > 0 && tmp < 31)
            A_B8_BIT3(gbf, channel_type_a_t_o_2, "Channel type and TDMA offset", 4, 8, channel_description_channel_type_t_o_2);
        else
            A_B8_BIT2(gbf, channel_type_a_t_o_2, "Channel type and TDMA offset", 4, 8, "reserved");
        A_B8_BIT1(gbf, tn, "TN", 1, 3);
    SKIP(1);

    B8_HEX();
        A_B8_BIT1(gbf, tsc, "TSC", 6, 8);
        int type = -1;
        B8_BIT(type, 5, 5);
        A_B8_BIT3(gbf, hopping_channel, "Hopping channel", 5, 5, channel_description_h);
        char buf[12];
        memset(buf, 0x00, sizeof(buf));
        if (type == 0)
        {

            B16_BIT(type, 1, 10);
            A_B8_BIT1(gbf, spare, "Spare", 3, 4);
            A_B8_BIT2(gbf, arfcn_h, "ARFCH (high part)", 1, 2, "-");
            SKIP(1);

        B8_HEX();
        sprintf(buf, "ARFCH=%d", type);
        A_B8_BIT2(gbf, arfcn_l, "ARFCH (low part)", 1, 8, buf);
        SKIP(1);
    }
    else
    {
        B16_BIT(type, 7, 12);
        A_B8_BIT2(gbf, maio_h, "MAIO (high part)", 1, 4, "-");
        SKIP(1);

        B8_HEX();
        sprintf(buf, "MAIO=%d", type);
        A_B8_BIT2(gbf, arfcn_l, "MAIO (low part)", 7, 8, buf);
        A_B8_BIT1(gbf, arfcn_l, "HSN", 1, 6);
        SKIP(1);
    }
    END_ELEMENT();
}

void power_command_and_access_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Power Command and Access Type", power_command_and_access_type);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Power Command and Access Type IEI", 1, 8, "Power Command and Access Type");
        SKIP(1);
    }

        int tmp = -1;
        B8_BIT(tmp, 7, 7);

        B8_HEX();
            A_B8_BIT3(gbf, atc, "ATC", 8, 8, power_command_a_t_atc);
            A_B8_BIT3(gbf, epc_mode, "EPC mode", 7, 7, power_command_epc_mode);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, fpc_epc, "FPC_EPC", 6, 6, power_command_fpc_epc0);
        }
        else if(tmp == 1)
        {
            A_B8_BIT3(gbf, fpc_epc, "FPC_EPC", 6, 6, power_command_fpc_epc1);
        }
            A_B8_BIT1(gbf, power_level, "POWER LEVEL", 1, 5);

        SKIP(1);

    END_ELEMENT();
}

void synchronization_indication(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Synchronization Indication", synchronization_indication);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Synch.Indic.IEI", 5, 8, "Synchronization Indication");
    }

    A_B8_BIT3(gbf, nci, "NCI", 4, 4, synchronization_indication_nci);
    A_B8_BIT3(gbf, rot, "ROT", 3, 3, synchronization_indication_rot);
    A_B8_BIT3(gbf, si, "SI", 1, 2, synchronization_indication_si);
    SKIP(1);

    END_ELEMENT();
}

void frequency_short_list(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Frequency Short List", frequency_short_list);
    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Frequency Short List IEI", 1, 8, "Frequency Short List");
        SKIP(1);
    }

    int len = -1;
    B8_BIT(len, 1, 8);
    B8_HEX();
        A_B8_BIT1(gbf, length, "Length of frequency list contents", 1, 8);
    SKIP(1);

    char buf[100];
    memset(buf, 0x00, sizeof(buf));
    int f_id_7_8;
    int f_id_4;
    int f_id_2_4;
    B8_BIT(f_id_7_8, 7, 8); 
    B8_BIT(f_id_4, 4, 4); 
    B8_BIT(f_id_2_4, 2, 4); 
    if(f_id_7_8 == 0)
    {
        bit_map0_format();
    }
    if(f_id_7_8 == 2)
    {
        if(f_id_4 == 0)
        {
            range1024_format(len);
        }
        else if(f_id_2_4 == 4)
        {
            range512_format(len); 
        }
        else if(f_id_2_4 == 5)
        {
			range256_format(len); 
        }
        else if(f_id_2_4 == 6)
        {
			range128_format(len); 
        }
        else
        {
            variable_bit_map_format(len);
        } 
    }

    END_ELEMENT();
}

void time_difference(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Time Difference", time_difference);

    if(iei)
    {
        B8_HEX();
            A_B8_BIT2(gbf, iei, "Time Difference IEI", 1, 8, "Time Difference");
        SKIP(1);
    }

        B8_HEX();
            A_B8_BIT1(gbf, length_of_t_d_c, "Length of frequency list contents", 1, 8);
        SKIP(1);

        B8_HEX();
            A_B8_BIT1(gbf, time_d_v, "Time difference value", 1, 8);
        SKIP(1);

    END_ELEMENT();
}

void dedicated_service_information(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Dedicated Service Information",dedicated_service_information);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Dedicated Service Information IEI", 1, 8, "Dedicated Service Information");
        SKIP(1);
    }

    B8_HEX();
        A_B8_BIT1(gbf, spare, "Spare", 2, 8);
        A_B8_BIT3(gbf, last_segment, "LAST SEGMENT", 1, 1, dedicated_service_i_last_segment);
    SKIP(1);

    END_ELEMENT();
}

void mobile_time_difference(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Mobile Time Difference", mobile_time_difference);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Mobile Time Difference IEI", 1, 8, "Mobile Time Difference");
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of Mobile Time difference contents", 1, 8);
    SKIP(1);

    char buf[100];
    int num, num_h, num_l, num_c;
    int tmp_h = -1;
    int tmp_l = -1;
    int tmp_c = -1;
    memset(buf, 0x00, sizeof(buf));

    B8_HEX();
    B8_BIT(tmp_h, 1, 8);
    num_h = tmp_h * 8192;
    A_B8_BIT2(gbf, mobile_time_d_v_h, "Mobile Time Difference value(high)", 1, 8, "-");
    SKIP(1);

    B8_HEX();
    B8_BIT(tmp_c, 1, 8);
    num_c = tmp_c * 32;
    A_B8_BIT2(gbf, mobile_time_d_v_c, "Mobile Time Difference value(contd)", 1, 8, "-");
    SKIP(1);

    B8_HEX();
    B8_BIT(tmp_l, 4, 8);
    num_l = tmp_l * 1;
    num = num_h + num_l + num_c;
    sprintf(buf,"Mobile Time Difference value =%d", num);
    A_B8_BIT2(gbf, mobile_time_d_v_l, "Mobile Time Difference value(low)", 4, 8, buf);
    A_B8_BIT2(gbf, spare, "Spare", 1, 3, "000");
    SKIP(1);

    END_ELEMENT();
}

//end liusai(4450-5049)
//start dang
void classmark_enquiry_mask(uint8_t iei, uint8_t location)
{   
    char buf[1024]={};
    int tmp; 
    BEGIN_ELEMENT("Classmark Enquiry Mask",classmark_enquiry_mask);
    if(iei==1)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Classmark Enquiry Mask IEI", 1, 8,"Classmark Enquiry Mask");
        SKIP(1);
    }    
        B8_HEX();
        A_B8_BIT1(gbf, length, "Length of Classmark Enquiry Mask contents", 1, 8);
        SKIP(1);
        B8_HEX();
        B8_BIT(tmp, 8, 8);
        if(tmp==0)
        strcat(buf, "CLASSMARK CHANGE message is requested" );
        else
        strcat(buf, "CLASSMARK CHANGE message is not requested" );
        B8_BIT(tmp, 5, 7);
        if(tmp==0)
        strcat(buf, "UTRAN CLASSMARK CHANGE message is requested" );
        if(tmp==7)
        strcat(buf, "UTRAN CLASSMARK CHANGE message is not requested." );
        B8_BIT(tmp, 4, 4);
        if(tmp==0)
        strcat(buf, "CDMA2000 CLASSMARK CHANGE message requested" );
        else        strcat(buf, "CDMA2000 CLASSMARK CHANGE message not requested." );
        B8_BIT(tmp, 3, 3);
        if(tmp==0)
        strcat(buf, "GERAN IU MODE CLASSMARK CHANGE message requested" );
        else
        strcat(buf, "GERAN IU MODE CLASSMARK CHANGE message not requested." );

        A_B8_BIT2(gbf, classmark_enquiry_mask_value_part, "Classmark Enquiry Mask value part", 1, 8, buf);
        SKIP(1);
    END_ELEMENT();
}
void synchronization_channel_information(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Synchronization channel information", synchronization_channel_information);
    int t;
    char buf[10]={};
    char buf1[10]={};
    char buf2[10]={};
    char buf3[10]={};
    char buf4[10]={};
    char buf5[10]={};
    char buf6[10]={};
    char buf7[10]={};
    B8_HEX();
    A_B8_BIT1(gbf, bsic, "BSIC", 3, 8 );
    B8_BIT(t ,1 ,2);
    sprintf(buf,"%d", t);
    strcat(buf3, buf);
    A_B8_BIT2(gbf, t1_high, "T1(high)", 1, 2, "-");
    SKIP(1);
    B8_HEX();
    B8_BIT(t ,1 ,8);
    sprintf(buf1, "%d", t);
    strcat(buf3,buf1);
    A_B8_BIT2(gbf, t1_middle, "T1 (middle)", 1, 8, "-" );
    SKIP(1);
    B8_HEX();
    B8_BIT(t ,8 ,8);
    sprintf(buf2, "%d", t);
    strcat(buf3, buf2);
    A_B8_BIT2(gbf, t1_low, "T1 (low)", 8, 8, buf3 );
    B8_BIT(t ,3 ,7);
    sprintf(buf4, "%d", t);
    A_B8_BIT2(gbf, t2, "T2", 3, 7, buf4 );
    B8_BIT(t ,1 ,2);
    sprintf(buf5, "%d", t);
    sprintf(buf7,buf5);
    A_B8_BIT2(gbf, t3_high, "T3 (high)", 1, 2, "-" );
    SKIP(1);
    B8_HEX();
    B8_BIT(t ,1 ,1);
    sprintf(buf6, "%d", t);
   strcat(buf7,buf6);
    A_B8_BIT2(gbf, t3_low, "T3 (low)", 1, 1, buf7 );
    SKIP(1);
    END_ELEMENT();
}
void si_9_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(17);
} 
void si_8_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
} 
void si_7_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
}
void si_16_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
}
void si_17_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
}
void extended_tsc_set(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Extended TSC Set",extended_tsc_set );
    if(iei==1)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Extended TSC Set IEI", 1, 8, "extended_tsc_set");
        SKIP(1);
    }    

    B8_HEX();
    A_B8_BIT1(gbf, secondary_ps_domain_tsc_value, "Secondary PS Domain TSC Value", 6, 8 ); 
    A_B8_BIT3(gbf, secondary_ps_domain_tsc_set, "Secondary PS Domain TSC Set", 5, 5,secondary_ps_domain_tsc_set );
    A_B8_BIT3(gbf, primary_ps_domain_tsc_set, "Primary PS Domain TSC Set", 4, 4,primary_ps_domain_tsc_set );
    A_B8_BIT3(gbf, nd_ps_domain_tsc_assigned, "2nd PS Domain TSC Assigned", 3, 3, nd_ps_domain_tsc_assigned);
    A_B8_BIT3(gbf, cs_domain_tsc_set, "CS Domain TSC Se", 1, 2, cs_domain_tsc_set);
    SKIP(1);
    END_ELEMENT();
} 
//dang

//liusai

void wait_indication(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Wait Indication", wait_indication);

    if(iei)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Wait Indication IEI", 1, 8, "Wait Indication");
        SKIP(1);
    }    

    B8_HEX();
    A_B8_BIT1(gbf, t3122/t3142_timeout_value, "T3122/T3142 Timeout Value", 1, 8);
    SKIP(1);

    END_ELEMENT();
}

void neighbour_cell_description(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Neighbour Cell Description", neighbour_cell_description);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Neighbour Cell Description IEI", 1, 8, "Neighbour Cell Description");
        SKIP(1);
    }

    int tmp;
    char buf[100];
    memset(buf, 0x00, sizeof(buf));
    char *p = buf; 
    B8_HEX(); 
    strcpy(p, "ARFCH=");
    p += 6;
    int i;
    int j = 4;
    int var = 128;
    int pos = 0;
    B8_BIT(tmp, 8, 8);
    if(tmp == 1)
        pos += sprintf(p + pos, "%d ", var);
    B8_BIT(tmp, 7, 7);
    if(tmp == 1)
        pos += sprintf(p + pos, "%d ", var);
    var = 125;
    A_B8_BIT2(gbf, arfch, "ARFCH", 7, 8, "-");
    A_B8_BIT3(gbf, ext_ind,"EXT-IND", 6, 6, neighbour_cell_d_e_i);
    A_B8_BIT1(gbf, ba_ind, "BA-IND", 5, 5);
    for(i = 0; i < 4; i++)
    {
        B8_BIT(tmp, j, j);
        var--;
        if(tmp == 1)
        {
            pos += sprintf(p + pos, "%d ", var);
        }
        j--;
    }
    A_B8_BIT2(gbf, arfch, "ARFCH", 1, 4, buf);
    SKIP(1);

    int k;
    for(k = 0; k < 15; k++)
    {
        memset(buf, 0x00, sizeof(buf));
        p = buf;
        strcpy(p, "ARFCH=");
        p += 6;
        pos = 0;
        for(i = 0, j = 8; i < 8; i++)
        {
            var--;
            B8_BIT(tmp, j, j);
            if(tmp == 1)
            {
                pos += sprintf(p + pos, "%d ", var);
            }
            j--;
        }
        B8_HEX();
        A_B8_BIT2(gbf, arfch, "ARFCH", 1, 8, buf);
        SKIP(1);
    }
    END_ELEMENT();
}

void neighbour_cell_description_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Neighbour Cell Description", neighbour_cell_description_2);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Neighbour Cell Description IEI", 1, 8, "Neighbour Cell Description");
        SKIP(1);
    }

    B8_HEX();

    int f_id_8;
    int f_id_4;
    int f_id_2_4;
    B8_BIT(f_id_8, 8, 8);
    B8_BIT(f_id_4, 4, 4);
    B8_BIT(f_id_2_4, 2, 4);
    B8_HEX();
    if(f_id_8 == 0)
    {
        um_bit_map0_format(1);
    }
    if(f_id_8 == 1)
    {
        if(f_id_4 == 0)
        {
            range1024_format(16);
        }
        else if(f_id_2_4 == 4)
        {
            range512_format(16);
        }
        else if(f_id_2_4 == 5)
        {
            range256_format(16);
        }
        else if(f_id_2_4 == 6)
        {
            range128_format(16);
        }
        else if(f_id_2_4 == 7)
        {
            variable_bit_map_format(16);
        }
    }
    END_ELEMENT();
}

void ps_cause(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("PS Cause", ps_cause);
    
    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "PS Cause IEI", 5, 8, "PS Cause");
    }
        
        A_B8_BIT3(gbf, ps_cause_v, "PS Cause value", 1, 4, ps_cause_ps_cause_v);
        SKIP(1);

    END_ELEMENT();
}

void feature_indicator(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Feature Indicator", feature_indicator);

    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "Spare", 3, 4);
            A_B8_BIT3(gbf, cs_ir, "CS IR", 2, 2, feature_indicator_cs_ir); 
            A_B8_BIT3(gbf, ps_ir, "PS IR", 1, 1, feature_indicator_ps_ir); 
            SKIP(1);
        }
    }
    
    END_ELEMENT();
}

void plmn_index(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("PLMN Index", plmn_index);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "PLMN Index IEI", 5, 8, "PLMN Index");
    }
        int tmp = -1;
        B8_BIT(tmp , 1, 4);
        if(tmp > 0 && tmp <6)
            A_B8_BIT3(gbf, plmn_index, "PLMN Index", 1, 4, plmn_index_plmn_index);
        else
            A_B8_BIT2(gbf, plmn_index, "PLMN Index", 1, 4, "reserved");
        SKIP(1);

    END_ELEMENT();
}

void additional_update_parameters(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Additional update parameters", additional_update_parameters);

    if(iei)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Additional update parameters IEI", 5, 8, "Additional update parameters");
    }    
    
    A_B8_BIT1(gbf, spare, "Spare", 3, 4);
    A_B8_BIT3(gbf, csmo, "CSMO", 2, 2, additional_update_parameters_csmo);
    A_B8_BIT3(gbf, csmt, "CSMT", 1, 1, additional_update_parameters_csmt);
    SKIP(1);
    
    END_ELEMENT();
}

void mobile_time_difference_on_hyperframe_level(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Mobile Time Difference on Hyperframe level", mobile_time_difference_on_hyperframe_level);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Mobile Time Difference on Hyperframe level IEI", 1, 8, "Mobile Time Difference on Hyperframe level");
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of Mobile Time difference on Hyperframe level contents", 1, 8);
    SKIP(1);

    int tmp_h, tmp_c1, tmp_c2, tmp_gb, tmp_l;
    char buf[100] = {0};
    char buf1[100] = {0};
    B8_HEX();
    B8_BIT(tmp_h, 1, 8);
    sprintf(buf, "%d", tmp_h);
    A_B8_BIT2(gbf, mobile_time_d_o_h_l_v_h, "Mobile Time Difference on Hyperframe level value (high)", 1, 8, "-");
    SKIP(1);
    
    B8_HEX();
    B8_BIT(tmp_c1, 1, 8);
    sprintf(buf1, "%d", tmp_c1);
    strcat(buf, buf1);
    A_B8_BIT2(gbf, mobile_time_d_o_h_l_v_c1, "Mobile Time Difference on Hyperframe level value (contd)", 1, 8, "-");
    SKIP(1);

    B8_HEX();
    B8_BIT(tmp_c2, 1, 8);
    sprintf(buf1, "%d", tmp_c2);
    strcat(buf, buf1);
    A_B8_BIT2(gbf, mobile_time_d_o_h_l_v_c2, "Mobile Time Difference on Hyperframe level value (contd)", 1, 8, "-");
    SKIP(1);

    B8_HEX();
    B8_BIT(tmp_gb, 1, 8);
    sprintf(buf1, "%d", tmp_gb);
    strcat(buf, buf1);
    A_B8_BIT2(gbf, mobile_time_d_o_h_l_v_gb, "Mobile Time Difference on Hyperframe level value (contd)", 1, 8, "-");
    SKIP(1);

    B8_HEX();
    B8_BIT(tmp_l, 1, 8);
    sprintf(buf1, "%d", tmp_l);
    strcat(buf, buf1);
    A_B8_BIT2(gbf, mobile_time_d_o_h_l_v_l, "Mobile Time Difference on Hyperframe level value (low)", 1, 8, buf);
    A_B8_BIT1(gbf, spare, "Spare", 1, 7); 
    SKIP(1);

    END_ELEMENT();    
}

//end liusai

//si_N_rest_octets

void si_3_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(4);
}

void si6_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(7);
}

void si_1_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(1);
}

void si_2bis_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(1);
}

void si_2ter_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(4);
}

void si_2quater_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
}

void si_2n_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
}


//end si_N_rest_octets

//IA*_rest_octets

void iar_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(3);
}

//end IA*_rest_octets

//end liusai


void nt_n_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(20);
}

void extended_measurement_results(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Extended Measurement Results", extended_measurement_results);
    if(iei==1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, measurement_results_iei, "Extended Measurement Results IEI", 1, 8, "Extended Measurement Results");
        SKIP(1);
    }
    B8_HEX();
    A_B8_BIT1(gbf, sc_used, "SC-USED", 8, 8);
    A_B8_BIT3(gbf, dtx_used, "DTX-USED", 7, 7, measurement_results_dtx_used);
    A_B8_BIT1(gbf, rxlev_carrier0, "RXLEV carrier 0", 1, 6);
    SKIP(1);
 
    char buf[100];
    int tmp = -1;
    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT1(gbf, rxlev_carrier1, "RXLEV carrier 1", 3, 8);
    A_B8_BIT2(gbf, rxlev_carrier2_h, "RXLEV carrier 2 (high part)", 1, 2, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 12);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier2_l, "RXLEV carrier 2 (low part)", 5, 8, buf);
    A_B8_BIT2(gbf, rxlev_carrier3_h, "RXLEV carrier 3 (high part)", 1, 4, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier3_l, "RXLEV carrier 3 (low part)", 7, 8, buf);
    A_B8_BIT1(gbf, rxlev_carrier4, "RXLEV carrier 4", 1, 6);
    SKIP(1);

    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT1(gbf, rxlev_carrier5, "RXLEV carrier 5", 3, 8);
    A_B8_BIT2(gbf, rxlev_carrier6_h, "RXLEV carrier 6 (high part)", 1, 2, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 12);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier6_l, "RXLEV carrier 6 (low part)", 5, 8, buf);
    A_B8_BIT2(gbf, rxlev_carrier7_h, "RXLEV carrier 7 (high part)", 1, 4, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier7_l, "RXLEV carrier 7 (low part)", 7, 8, buf);
    A_B8_BIT1(gbf, rxlev_carrier8, "RXLEV carrier 8", 1, 6);
    SKIP(1);

    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT1(gbf, rxlev_carrier9, "RXLEV carrier 9", 3, 8);
    A_B8_BIT2(gbf, rxlev_carrier10_h, "RXLEV carrier 10 (high part)", 1, 2, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 12);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier10_l, "RXLEV carrier 10 (low part)", 5, 8, buf);
    A_B8_BIT1(gbf, rxlev_carrier11_h, "RXLEV carrier 11 (high part)", 1, 4);
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier11_l, "RXLEV carrier 11 (low part)", 7, 8, buf);
    A_B8_BIT2(gbf, rxlev_carrier12_h, "RXLEV carrier 12 (high part)", 1, 6, "-");
    SKIP(1);

    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT1(gbf, rxlev_carrier13, "RXLEV carrier 13", 3, 8);
    A_B8_BIT2(gbf, rxlev_carrier14_h, "RXLEV carrier 14 (high part)", 1, 2, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 12);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier14_l, "RXLEV carrier 14 (low part)", 5, 8, buf);
    A_B8_BIT2(gbf, rxlev_carrier15_h, "RXLEV carrier 15 (high part)", 1, 4, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier15_l, "RXLEV carrier 15 (low part)", 7, 8, buf);
    A_B8_BIT1(gbf, rxlev_carrier16, "RXLEV carrier 16", 1, 6);
    SKIP(1);

    B16_BIT(tmp, 5, 10);
    B8_HEX();
    A_B8_BIT1(gbf, rxlev_carrier17, "RXLEV carrier 17", 3, 8);
    A_B8_BIT2(gbf, rxlev_carrier18_h, "RXLEV carrier 18 (high part)", 1, 2, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B16_BIT(tmp, 7, 12);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier18_l, "RXLEV carrier 18 (low part)", 5, 8, buf);
    A_B8_BIT2(gbf, rxlev_carrier19_h, "RXLEV carrier 19 (high part)", 1, 4, "-");
    SKIP(1);

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, rxlev_carrier19_l, "RXLEV carrier 19 (low part)", 7, 8, buf);
    A_B8_BIT1(gbf, rxlev_carrier20, "RXLEV carrier 20", 1, 6);
    SKIP(1);

    END_ELEMENT();
}

void apdu_id(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("APDU ID", apdu_id); 
    int tmp = -1;
    if(iei)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "APDU ID IEI", 5, 8, "APDU ID");
        B8_BIT(tmp , 1, 4);
        if(tmp == 0)
            A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 1, 4, "RRLP/LCS");
        else if(tmp == 1)
            A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 1, 4, "ETWS");
        else
            A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 1, 4, "reserved for future use");
        SKIP(1);
    }    
    else
    { 
        if(location == 1)
        {
            B8_BIT(tmp , 1, 4);
            if(tmp == 0)
                A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 1, 4, "RRLP/LCS");
            else if(tmp == 1)
                A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 1, 4, "ETWS");
            else
                A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 1, 4, "reserved for future use");
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp , 5, 8);
            if(tmp == 0)
                A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 5, 8, "RRLP/LCS");
            else if(tmp == 1)
                A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 5, 8, "ETWS");
            else
                A_B8_BIT2(gbf, protocol_identifier, "Protocol identifier", 5, 8, "reserved for future use");
        }
    } 
    END_ELEMENT(); 
}

void apdu_flags(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("APDU FLAGS", apdu_flags);
    int tmp = -1;
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "APDU Flags IEI", 5, 8, "APDU Flags");
        A_B8_BIT1(gbf, spare, "Spare", 4, 4);
        B8_BIT(tmp , 3, 3);
        if(tmp == 0)
            A_B8_BIT2(gbf, cr, "CR", 3, 3, "Command or Final Response");
        else
            A_B8_BIT2(gbf, cr, "CR", 3, 3, "Not Command or Final Response");
        B8_BIT(tmp , 2, 2);
        if(tmp == 0)
            A_B8_BIT2(gbf, first_segment, "First Segment", 2, 2, "First or only segment");
        else
            A_B8_BIT2(gbf, first_segment, "First Segment", 2, 2, "Not First or only segment");
        B8_BIT(tmp , 1, 1);
        if(tmp == 0)
            A_B8_BIT2(gbf, first_segment, "Last Segment", 1, 1, "Last or only segment");
        else
            A_B8_BIT2(gbf, first_segment, "Last Segment", 1, 1, "Not Last or only segment");
        SKIP(1);
    }
    else
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "Spare", 4, 4);
            B8_BIT(tmp , 3, 3);
            if(tmp == 0)
                A_B8_BIT2(gbf, cr, "CR", 3, 3, "Command or Final Response");
            else
                A_B8_BIT2(gbf, cr, "CR", 3, 3, "Not Command or Final Response");
            B8_BIT(tmp , 2, 2);
            if(tmp == 0)
                A_B8_BIT2(gbf, first_segment, "First Segment", 2, 2, "First or only segment");
            else
                A_B8_BIT2(gbf, first_segment, "First Segment", 2, 2, "Not First or only segment");
            B8_BIT(tmp , 1, 1);
            if(tmp == 0)
                A_B8_BIT2(gbf, first_segment, "Last Segment", 1, 1, "Last or only segment");
            else
                A_B8_BIT2(gbf, first_segment, "Last Segment", 1, 1, "Not Last or only segment");
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "Spare", 8, 8);
            B8_BIT(tmp , 7, 7);
            if(tmp == 0)
                A_B8_BIT2(gbf, cr, "CR", 7, 7, "Command or Final Response");
            else
                A_B8_BIT2(gbf, cr, "CR", 7, 7, "Not Command or Final Response");
            B8_BIT(tmp , 6, 6);
            if(tmp == 0)
                A_B8_BIT2(gbf, first_segment, "First Segment", 6, 6, "First or only segment");
            else
                A_B8_BIT2(gbf, first_segment, "First Segment", 6, 6, "Not First or only segment");
            B8_BIT(tmp , 5, 5);
            if(tmp == 0)
                A_B8_BIT2(gbf, first_segment, "Last Segment", 5, 5, "Last or only segment");
            else
                A_B8_BIT2(gbf, first_segment, "Last Segment", 5, 5, "Not Last or only segment");
        }
    } 

    END_ELEMENT();
}

void apdu_data(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("APDU Data", apdu_data);

    if(iei)
    {
        B8_HEX();
        A_B8_BIT2(gbf, iei, "APDU Data IEI", 1, 8, "APDU Data");
        SKIP(1);
    }

    int tmp = -1;
    B8_BIT(tmp , 1, 8);
    B8_HEX();
    A_B8_BIT1(gbf, length, "Length of APDU contents", 1, 8);
    SKIP(1);

    int i = 0;
    for(i; i < tmp; i++)
    {
        B8_HEX();
        A_B8_BIT1(gbf, apdu_data_information, "APDU Data information", 1, 8);
        SKIP(1);
    }
}

void extended_measurement_frequency_list(uint8_t iei, uint8_t location) 
{
    BEGIN_ELEMENT("Extended Measurement Frequency List", extended_measurement_f_l); 
	if(iei) 
	{ 
		B8_HEX(); 
		A_B8_BIT2(gbf, iei, "Extended Measurement Frequency List IEI", 1, 8, "Extended Measurement Frequency List"); 
        SKIP(1); 
    } 
	int f_id_7_8; 
    int f_id_4; 
    int f_id_2_4; 
    B8_BIT(f_id_7_8, 7, 8); 
    B8_BIT(f_id_4, 4, 4); 
    B8_BIT(f_id_2_4, 2, 4); 
    if(f_id_7_8 == 0) 
    { 
		bit_map0_format(); 
    } 
    if(f_id_7_8 == 2) 
    { 
        if(f_id_4 == 0) 
        { 
			range1024_format(16);			
		} 
        else if(f_id_2_4 == 4) 
        { 
			range512_format(16); 
        } 
        else if(f_id_2_4 == 5) 
        { 
			range256_format(16); 
        } 
        else if(f_id_2_4 == 6) 
        { 
			range128_format(16); 
        } 
        else
        {
            variable_bit_map_format(16);
        } 
    } 


    END_ELEMENT(); 
}

void mobile_station_classmark_2(uint8_t iei, uint8_t location) 
{    
        BEGIN_ELEMENT("Mobile Station Classmark 2", mobile_station_classmark_2); 
        if(iei == 1)
        {    
                B8_HEX(); 
                A_B8_BIT2(gbf, mobile_station_classmark_2_iei, "Mobile Station Classmark 2 IEI", 1, 8, "Mobile Station Classmark 2");  
                SKIP(1); 
        }    
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 8, 8);  
        A_B8_BIT3(gbf, revision, "Revision level", 6, 7, mobile_station_revision_level);
        A_B8_BIT3(gbf, es ,"ES IND", 5, 5, mobile_station_es_ind);
        A_B8_BIT3(gbf, a5_1 ,"A5/1 algorithm", 4, 4, mobile_station_A51_algorithm_s);
        A_B8_BIT3(gbf, rf ,"RF Power Capability", 1, 3, mobile_station_rf_power_c);  
        SKIP(1);

        A_B8_BIT1(gbf, spare, "spare", 8, 8);  
        A_B8_BIT3(gbf, ps_capability, "PS capability", 7, 7, mobile_station_ps_capability);
        A_B8_BIT3(gbf, ss_screening_indicator, "SS Screening Indicator", 5, 6, mobile_station_c2_ss_screening_ind);
        A_B8_BIT3(gbf, sm_capability, "SM capability", 4, 4, mobile_station_c2_sm_capability);
        A_B8_BIT3(gbf, vbs_notification_reception, "VBS notification reception", 3, 3, mobile_station_c2_vbs_notification_rec);
        A_B8_BIT3(gbf, vgcs_notification_reception, "VGCS notification reception", 2, 2, mobile_station_c2_vgcs_notification_rec);
        A_B8_BIT1(gbf, fc_frequency_capability, "FC Frequency Capability", 1, 1);
        SKIP(1);

        B8_HEX();
        A_B8_BIT3(gbf, cm3, "CM3", 8, 8, mobile_station_c2_cm3);
        A_B8_BIT1(gbf, spare, "spare", 7, 7);  
        A_B8_BIT3(gbf, lcs_va_capability, "LCS VA capability", 6, 6, mobile_station_c2_cm3);
        A_B8_BIT3(gbf, ucs2_treatment, "UCS2 treatment", 5, 5, mobile_station_c2_ucs2_treatment);
        A_B8_BIT3(gbf, solsa, "SoLSA", 4, 4, mobile_station_c2_solas);
        A_B8_BIT3(gbf, cmsp, "CMSP", 3, 3, mobile_station_c2_cm_service_p);
        A_B8_BIT3(gbf, a5_3, "A5/3", 2, 2, mobile_station_c2_a53_algorithm_sup);
        A_B8_BIT3(gbf, a5_2, "A5/2", 1, 1, mobile_station_c2_a52_algorithm_sup);
        END_ELEMENT(); 
}

void descriptive_group_or_broadcast_call_reference(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Descriptive group or broadcast call reference", descriptive_group_or_b_c_r); 
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, descriptive_group_or_b_c_r_iei, "Descriptive group or broadcast call reference IEI", 1, 8, "Descriptive group or broadcast call reference");  
            SKIP(1); 
    }    
    char buf[100];
    int tmp = -1;
    B32_BIT(tmp, 6, 32);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "binary code length = %ld", tmp);

    B8_HEX();
    A_B8_BIT2(gbf, binary_coding_or_b_c_r, "Binary coding of the group or broadcast call reference", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, binary_coding_or_b_c_r, "Binary coding of the group or broadcast call reference", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, binary_coding_or_b_c_r, "Binary coding of the group or broadcast call reference", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, binary_coding_or_b_c_r, "Binary coding of the group or broadcast call reference", 6, 8, buf);  
    B8_BIT(tmp, 5, 5);
    if(tmp == 0)
        A_B8_BIT2(gbf, sf, "SF Service flag", 5, 5, "VBS (broadcast call reference)");
    else if(tmp == 1)
        A_B8_BIT2(gbf, sf, "SF Service flag", 5, 5, "VGCS (group call reference)");
    B8_BIT(tmp, 4, 4);
    if(tmp == 0)
        A_B8_BIT2(gbf, af, "AF Acknowledgement flag", 4, 4, "acknowledgement is not required");
    else if(tmp == 1)
        A_B8_BIT2(gbf, af, "AF Acknowledgement flag", 4, 4, "acknowledgement is required");
    A_B8_BIT3(gbf, call_priority, "Call priority", 1, 3, descriptive_group_broadcast_call_reference_call_priority);  
    SKIP(1);

    B8_HEX();
    A_B8_BIT3(gbf, ciphering_information, "Ciphering information", 5, 8, descriptive_group_broadcast_call_reference_ciphering_information);  
    A_B8_BIT1(gbf, spare, "Spare", 1, 4);  
    SKIP(1);

    END_ELEMENT(); 
}

void channel_needed(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Channel Needed", channel_needed); 
    int tmp = -1;
    if(iei)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, iei, "Channel Needed IEI", 5, 8, "Channel Needed");
        B8_BIT(tmp , 1, 4);
        if(tmp == 0)
            A_B8_BIT2(gbf, channel, "Channel", 1, 4, "Any channel");
        else if(tmp == 1)
            A_B8_BIT2(gbf, channel, "Channel", 1, 4, "SDCCH");
        else if(tmp == 2)
            A_B8_BIT2(gbf, channel, "Channel", 1, 4, "TCH/F (Full rate)");
        else
            A_B8_BIT2(gbf, channel, "Channel", 1, 4, "TCH/H or TCH/F (Dual rate)");
        SKIP(1);
    }    
    else
    { 
        if(location == 1)
        {
            B8_BIT(tmp , 1, 4);
            if(tmp == 0)
                A_B8_BIT2(gbf, channel, "Channel", 1, 4, "Any channel");
            else if(tmp == 1)
                A_B8_BIT2(gbf, channel, "Channel", 1, 4, "SDCCH");
            else if(tmp == 2)
                A_B8_BIT2(gbf, channel, "Channel", 1, 4, "TCH/F (Full rate)");
            else
                A_B8_BIT2(gbf, channel, "Channel", 1, 4, "TCH/H or TCH/F (Dual rate)");
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp , 5, 8);
            if(tmp == 0)
                A_B8_BIT2(gbf, channel, "Channel", 5, 8, "Any channel");
            else if(tmp == 1)
                A_B8_BIT2(gbf, channel, "Channel", 5, 8, "SDCCH");
            else if(tmp == 2)
                A_B8_BIT2(gbf, channel, "Channel", 5, 8, "TCH/F (Full rate)");
            else
                A_B8_BIT2(gbf, channel, "Channel", 5, 8, "TCH/H or TCH/F (Dual rate)");
        }
    } 
    END_ELEMENT(); 
}

void tmsi_p_tmsi(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("TMSI/P-TMSI", tmsi_p_tmsi); 
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, tmsi_p_tmsi_iei, "TMSI/P-TMSI IEI", 1, 8, "TMSI/P-TMSI");  
            SKIP(1); 
    }    
    char buf[100];
    int tmp = -1;
    B32_BIT(tmp, 1, 32);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "TMSI/P-TMSI value = %ld", tmp);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value (contd)", 1, 8, buf);  
    SKIP(1);

    END_ELEMENT(); 
}


void p3_rest_octets(uint8_t iei, uint8_t location)
{
    SKIP(3);
}

void tlli(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("TLLI", tlli); 
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, tlli_iei, "TLLI IEI", 1, 8, "TLLI");  
            SKIP(1); 
    }    
    char buf[100];
    int tmp = -1;
    B32_BIT(tmp, 1, 32);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "TLLI value = %ld", tmp);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, buf);  
    SKIP(1);

    END_ELEMENT(); 
}

void channel_request_description_2(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Channel Request Description 2", channel_request_description_2); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, channel_request_description_2_iei, "Channel Request Description 2 IEI", 1, 8, "Channel Request Description 2");  
        SKIP(1); 
    }    
 
    int tmp = -1;
    B8_BIT(tmp, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, channel_request_description_2_length, "Length of Channel Request Description 2 value part", 1, 8);
    SKIP(1); 

    SKIP(tmp); 
    END_ELEMENT(); 
}

void network_name(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Network Name", network_name); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, network_name_iei, "Network Name IEI", 1, 8, "Network Name");  
        SKIP(1); 
    }    
 
    int len = -1;
    int tmp = -1;
    if(location == 1)
    {
        B8_HEX(); 
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, network_name_length, "Length of Network Name", 1, 8);
        SKIP(1); 
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, ext, "ext", 8, 8);
        B8_BIT(tmp, 5, 7);
        if(tmp == 0)
            A_B8_BIT2(gbf, coding_scheme, "coding scheme", 5, 7, "Cell Broadcast data coding scheme, GSM default alphabet, language unspecified");  
        else if(tmp == 1)
            A_B8_BIT2(gbf, coding_scheme, "coding scheme", 5, 7, "UCS2 (16 bit)");  
        else
            A_B8_BIT2(gbf, coding_scheme, "coding scheme", 5, 7, "reserved");  
        A_B8_BIT3(gbf, add_ci, "Add CI", 4, 4, network_name_add_ci);  
        A_B8_BIT3(gbf, number_of_spare_bits, "Number of spare bits in last octe", 1, 3, network_name_number_of_s_b_i_l_o);
        SKIP(1); 
        len = len - 1;
    }
    if(len > 0)
        SKIP(len); 

    END_ELEMENT(); 
}

void time_zone(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Time Zone", time_zone); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, time_zone_iei, "Time Zone IEI", 1, 8, "Time Zone");  
        SKIP(1); 
    }    

    B8_HEX(); 
    A_B8_BIT1(gbf, time_zone, "Time Zone", 1, 8);  
    SKIP(1); 
 
    END_ELEMENT(); 
}

void time_zone_and_time(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Time Zone and time", time_zone); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, time_zone_and_time_iei, "Time Zone and time IEI", 1, 8, "Time Zone and time");  
        SKIP(1); 
    }    

    B8_HEX(); 
    A_B8_BIT1(gbf, year, "Year", 1, 8);  
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, month, "Month", 1, 8);  
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, day, "Day", 1, 8);  
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, hour, "Hour", 1, 8);  
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, minute, "Minute", 1, 8);  
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, second, "Second", 1, 8);  
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, time_zone, "Time Zone", 1, 8);  
    SKIP(1); 
 
    END_ELEMENT(); 
}

void lsa_identifier(uint8_t iei, uint8_t location) 
{    
    int len = -1;
    BEGIN_ELEMENT("LSA Identifier", lsa_identifier); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, tlli_iei, "LSA Identifier IEI", 1, 8, "LSA Identifier");  
        SKIP(1); 
    }    

    if(location == 1)
    {
        B8_HEX(); 
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, lsa_identifier_length, "Length of LSA Identifier contents", 1, 8);
        SKIP(1); 
    }

    int i = 0;
    int tmp = -1;
    B24_BIT(tmp, 1, len);
    for(i = 0; i < len -1; i++)
    {
        B8_HEX();
        A_B8_BIT2(gbf, lsa_id, "LSA ID", 1, 8, "-");  
        SKIP(1);
    }

    char buf[100];
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "LSA ID = %ld", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, lsa_id, "LSA ID cont", 1, 8, buf);  
    SKIP(1);
    END_ELEMENT(); 
}

void daylight_saving_time(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Daylight Saving Time", daylight_saving_time); 
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, daylight_saving_time_iei, "Daylight Saving Time IEI", 1, 8, "Daylight Saving Time");  
            SKIP(1); 
    }    

    if(location == 1)
    {
        int len = -1;
        B8_HEX(); 
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, daylight_saving_time_length, "Length of Daylight Saving Time  contents", 1, 8);
        SKIP(1); 
    }

    B8_HEX();
    A_B8_BIT1(gbf, spare, "spare", 3, 8);
    A_B8_BIT3(gbf, daylight_saving_time_value , "Daylight Saving Time value", 1, 2, network_name_daylight_saving_t_v);
    SKIP(1); 

    END_ELEMENT(); 
}

void container(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("SETUP Container", setup_container); 
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, setup_container_iei, "SETUP Container IEI", 1, 8, "SETUP Container");  
            SKIP(1); 
    }    

    int len = -1;
    B8_HEX(); 
    B8_BIT(len, 1, 8);
    A_B8_BIT1(gbf, setup_container_length, "Length of SETUP container contents", 1, 8);
    SKIP(1); 

    if(len > 0)
        SKIP(len); 

    END_ELEMENT(); 
}

void more_data(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("More data", more_data); 
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, more_data_iei, "More data IEI", 1, 8, "More data");  
            SKIP(1); 
    }    

    END_ELEMENT(); 
}

void congestion_level(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Congestion level", more_data); 

    int tmp = -1;
    if(iei)
    {    
        B8_HEX();
        A_B8_BIT2(gbf, congestion_level_iei, "Congestion level IEI", 5, 8, "Congestion level");  
        B8_BIT(tmp , 1, 4);
        if(tmp == 0)
            A_B8_BIT2(gbf, congestion_level, "Congestion level", 1, 4, "receiver ready");
        else if(tmp == 15)
            A_B8_BIT2(gbf, congestion_level, "Congestion level", 1, 4, "receiver not ready");
        else
            A_B8_BIT2(gbf, congestion_level, "Congestion level", 1, 4, "reserved");
        SKIP(1);
    }    
    else
    { 
        if(location == 1)
        {
            B8_BIT(tmp , 1, 4);
            if(tmp == 0)
                A_B8_BIT2(gbf, congestion_level, "Congestion level", 1, 4, "receiver ready");
            else if(tmp == 15)  
                A_B8_BIT2(gbf, congestion_level, "Congestion level", 1, 4, "receiver not ready");
            else               
                A_B8_BIT2(gbf, congestion_level, "Congestion level", 1, 4, "reserved");
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp , 5, 8);
            if(tmp == 0)
                A_B8_BIT2(gbf, congestion_level, "Congestion level", 5, 8, "receiver ready");
            else if(tmp == 15)
                A_B8_BIT2(gbf, congestion_level, "Congestion level", 5, 8, "receiver not ready");
            else
                A_B8_BIT2(gbf, congestion_level, "Congestion level", 5, 8, "reserved");
        }
    } 

    END_ELEMENT(); 
}

void notification_indicator(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Notification indicator", more_data); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, more_data_iei, "Notification indicator IEI", 1, 8, "Notification indicator");  
        SKIP(1); 
    }    

    int tmp = -1;
    B8_BIT(tmp, 1, 7);
    B8_HEX(); 
    A_B8_BIT1(gbf, ext, "ext", 8, 8);  
    if(tmp == 0)
        A_B8_BIT2(gbf, notification_description, "Notification description", 1, 7, "User suspended");  
    else if(tmp == 1)
        A_B8_BIT2(gbf, notification_description, "Notification description", 1, 7, "User resumed");  
    else if(tmp == 2)
        A_B8_BIT2(gbf, notification_description, "Notification description", 1, 7, "Bearer change");  
    else
        A_B8_BIT2(gbf, notification_description, "Notification description", 1, 7, "reserved");  
    SKIP(1); 

    END_ELEMENT(); 
}

void call_state(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Call state ", more_data); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, call_state_iei, "Call state IEI", 1, 8, "Call state");  
        SKIP(1); 
    }    

    int tmp = -1;
    B8_BIT(tmp, 1, 6);
    B8_HEX(); 
    A_B8_BIT3(gbf, coding_standard, "Coding standard", 7, 8, progress_indicator_coding_standard);  
    if((tmp > 0 && tmp < 6) || (tmp > 5 && tmp < 13) || tmp == 19 || (tmp > 25 && tmp < 29) || (tmp > 33 && tmp < 39))
        A_B8_BIT3(gbf, call_state_value, "Call state value", 1, 6, call_state_call_state_value);  
    else
        A_B8_BIT2(gbf, call_state_value, "Call state value", 1, 6, "reserved");  
    SKIP(1); 
 
    END_ELEMENT(); 
}

void auxiliary_states(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Auxiliary states", auxiliary_states); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, auxiliary_states_iei, "Auxiliary states IEI", 1, 8, "Auxiliary states");  
        SKIP(1); 
    }    

    int len = -1;
    B8_HEX(); 
    B8_BIT(len, 1, 8);
    A_B8_BIT1(gbf, auxiliary_states_length, "Length of Auxiliary states contents", 1, 8);
    SKIP(1); 

    if(len > 0)
    {
        A_B8_BIT1(gbf, ext, "ext", 8, 8);
        A_B8_BIT1(gbf, spare, "spare", 5, 7);
        A_B8_BIT3(gbf, hold_auxiliary_state, "Hold auxiliary state", 3, 4, auxiliary_states_hold_auxiliary_state);
        A_B8_BIT3(gbf, multi_party_auxiliary_state, "Multi party auxiliary state", 1, 2, auxiliary_states_multi_party_a_s);
        SKIP(1); 
    }

    END_ELEMENT(); 
}

void ns_pdu_type()
{
	BEGIN_ELEMENT("NS PDU type", ns_pdu_type); 

    int tmp;
    B8_HEX(); 
    B8_BIT(tmp, 1, 8);
    if ((tmp > 1 && tmp < 9) || tmp == 0 || tmp == 10 || tmp == 11)
        A_B8_BIT3(gbf, ns_pdu_t, "NS PDU type", 1, 8, gb_ns_pdu_type); 
    else
        A_B8_BIT2(gbf, ns_pdu_t, "NS PDU type", 1, 8, "reserved"); 
    SKIP(1); 
    END_ELEMENT(); 
}

int ns_cause()
{
	BEGIN_ELEMENT("CAUSE", cause); 

    B8_HEX(); 
    A_B8_BIT1(gbf, iei, "IEI", 1, 8);
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "length indicator", 1, 8);
    SKIP(1); 

    int tmp;
    B8_BIT(tmp, 1, 8);
    B8_HEX(); 
    A_B8_BIT3(gbf, cause_v, "cause value", 1, 8, gb_cause);
    SKIP(1); 

    END_ELEMENT(); 
    return tmp;
}

void ns_vci()
{
	BEGIN_ELEMENT("NS-VCI", ns_vci); 

    char buf[100] = {0};
    int tmp, tmp0, tmp1;
    B8_HEX(); 
    A_B8_BIT1(gbf, iei, "IEI", 1, 8);
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "length indicator", 1, 8);
    SKIP(1); 

    B8_BIT(tmp0, 1, 8);
    B8_HEX(); 
    A_B8_BIT2(gbf, most_significant_octe, "most significant octet", 1, 8, "-");
    SKIP(1); 

    B8_BIT(tmp1, 1, 8);
    tmp = (tmp0 << 8) + tmp1;
    sprintf((char *)buf, "%d", tmp);
    B8_HEX(); 
    A_B8_BIT2(gbf, least_significant_octe, "least significant octet", 1, 8, buf);
    SKIP(1); 

    END_ELEMENT(); 
}

void nsei()
{
	BEGIN_ELEMENT("NSEI", nsei); 

    char buf[100] = {0};
    int tmp, tmp0, tmp1;
    B8_HEX(); 
    A_B8_BIT1(gbf, iei, "IEI", 1, 8);
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, length, "length indicator", 1, 8);
    SKIP(1); 

    B8_BIT(tmp0, 1, 8);
    B8_HEX(); 
    A_B8_BIT2(gbf, most_significant_octe, "most significant octet", 1, 8, "-");
    SKIP(1); 

    B8_BIT(tmp1, 1, 8);
    tmp = (tmp0 << 8) + tmp1;
    sprintf((char *)buf, "%d", tmp);
    B8_HEX(); 
    A_B8_BIT2(gbf, least_significant_octe, "least significant octet", 1, 8, buf);
    SKIP(1); 

    END_ELEMENT(); 
}

int ns_pdu()
{
	BEGIN_ELEMENT("NS-PDU", ns_pdu); 

    char buf[100] = {0};
    int ns_pdu_len = 0;
    int len, tmp, tmp0, tmp1;
    B8_HEX(); 
    A_B8_BIT1(gbf, iei, "IEI", 1, 8);
    SKIP(1); 
    ns_pdu_len += 1;

    B8_BIT(len, 1, 8);
    B8_HEX(); 
    A_B8_BIT1(gbf, length, "length indicator", 1, 8);
    SKIP(1); 
    ns_pdu_len += 1;

    if(len == 1)
    {
        B8_HEX(); 
        A_B8_BIT1(gbf, ns_pdu, "NS PDU", 1, 8);
        SKIP(1); 
        ns_pdu_len += 1;
    }
    else if(len == 2)
    {
        B8_BIT(tmp0, 1, 8);
        B8_HEX(); 
        A_B8_BIT2(gbf, ns_pdu, "NS PDU", 1, 8, "-");
        SKIP(1); 

        B8_BIT(tmp1, 1, 8);
        tmp = (tmp0 << 8) + tmp1;
        sprintf((char *)buf, "%d", tmp);
        B8_HEX(); 
        A_B8_BIT2(gbf, ns_pdu, "NS PDU", 1, 8, buf);
        SKIP(1); 
        ns_pdu_len += 2;
    }

    END_ELEMENT(); 
    return ns_pdu_len;
}

void bvci(uint8_t iei, uint8_t location)
{
	BEGIN_ELEMENT("BVCI", bvci); 

    char buf[100] = {0};
    int tmp, tmp0, tmp1;
	if(iei == 1)
	{
    	B8_HEX(); 
    	A_B8_BIT1(gbf, iei, "IEI", 1, 8);
    	SKIP(1); 
	}

	if(location == 1)
	{
    	B8_HEX(); 
    	A_B8_BIT1(gbf, length, "length indicator", 1, 8);
    	SKIP(1); 
	}

    B8_BIT(tmp0, 1, 8);
    B8_HEX(); 
    A_B8_BIT2(gbf, most_significant_octe, "most significant octet", 1, 8, "-");
    SKIP(1); 

    B8_BIT(tmp1, 1, 8);
    tmp = (tmp0 << 8) + tmp1;
    sprintf((char *)buf, "%d", tmp);
    B8_HEX(); 
    A_B8_BIT2(gbf, least_significant_octe, "least significant octet", 1, 8, buf);
    SKIP(1); 

    END_ELEMENT(); 
}

void spare()
{
	BEGIN_ELEMENT("SPARE", spare); 

    B8_HEX(); 
    A_B8_BIT1(gbf, spare, "spare octet", 1, 8);
    SKIP(1); 

    END_ELEMENT(); 
}

void bssgp_pdu_type()
{
	BEGIN_ELEMENT("BSSGP PDU type", bssgp_pdu_type); 

    int tmp;
    B8_HEX(); 
    B8_BIT(tmp, 1, 8);
    if ((tmp >= 0 && tmp < 4) || (tmp > 5 && tmp < 17) || (tmp > 31 || tmp == 45) || tmp == 64 || tmp == 65 || (tmp > 79 && tmp < 88))
        A_B8_BIT3(gbf, bssgp_pdu_t, "BSSGP PDU type", 1, 8, gb_bssgp_pdu_type); 
    else
        A_B8_BIT2(gbf, bssgp_pdu_t, "BSSGP PDU type", 1, 8, "reserved"); 
    SKIP(1); 
    END_ELEMENT(); 
}

//flag 等于1属于DL_UNITDATA信令,flag等于0属于UL_UNITDATA信令
void qos_profile(uint8_t iei, uint8_t location, uint8_t flag)
{
	BEGIN_ELEMENT("Qos Profile", qos_profile); 
	int len = 0;
	if(iei == 1)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, iei, "IEI", 1, 8);
		SKIP(1); 
	}
	if(location == 1)
	{
        int tmp = -1; 
        B8_BIT(tmp, 8, 8);
        if(tmp)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	int tmp0 = 0;
	int tmp1 = 0;
	int pos = 0;
    char buf[100] = {0};
	B8_BIT(tmp0, 1, 8);
    B8_HEX(); 
    A_B8_BIT2(gbf, r_value_msb, "R Value (MSB)", 1, 8, "-");
	SKIP(1); 

	B8_BIT(tmp1, 1, 8);
	tmp = (tmp0 << 8) + tmp1;
	pos = sprintf((char *)buf, "%d", tmp);
	sprintf((char *)buf + pos, "%s", " * 100 bits/sec");
    B8_HEX(); 
    A_B8_BIT2(gbf, r_value_lsb, "R Value (LSB)", 1, 8, buf);
	SKIP(1); 

    B8_HEX(); 
	A_B8_BIT1(gbf, spare, "SPARE", 7, 8);
	B8_BIT(tmp, 6, 6);
	if(tmp == 0)
		A_B8_BIT2(gbf, cr, "C/R", 6, 6, "The SDU contains a LLC ACK or SACK command/response frame type");
	else
		A_B8_BIT2(gbf, cr, "C/R", 6, 6, "The SDU does not contain a LLC ACK or SACK command/response frame type");
	B8_BIT(tmp, 5, 5);
	if(tmp == 0)
		A_B8_BIT2(gbf, t, "T", 5, 5, "The SDU contains signalling");
	else
		A_B8_BIT2(gbf, t, "T", 5, 5, "The SDU contains data");
	B8_BIT(tmp, 4, 4);
	if(tmp == 0)
		A_B8_BIT2(gbf, a, "A", 4, 4, "Radio interface uses RLC/MAC ARQ functionality");
	else
		A_B8_BIT2(gbf, a, "A", 4, 4, "Radio interface uses RLC/MAC-UNITDATA functionality");
	if(flag)
		A_B8_BIT3(gbf, precedence, "Precedence", 1, 3, gb_precedence_dl);
	else
		A_B8_BIT3(gbf, precedence, "Precedence", 1, 3, gb_precedence_ul);
	SKIP(1);

    END_ELEMENT(); 
}

void pdu_lifetime(uint8_t iei, uint8_t location)
{
	BEGIN_ELEMENT("PDU Lifetime", pdu_lifetime); 
	int len = 0;
	if(iei == 1)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, iei, "IEI", 1, 8);
		SKIP(1); 
	}
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	int tmp0 = 0;
	int tmp1 = 0;
    char buf[100] = {0};
	B8_BIT(tmp0, 1, 8);
    B8_HEX(); 
    A_B8_BIT2(gbf, delay_value, "Delay Value", 1, 8, "-");
	SKIP(1); 

	B8_BIT(tmp1, 1, 8);
	tmp = (tmp0 << 8) + tmp1;
	sprintf((char *)buf, "%d", tmp);
    B8_HEX(); 
    A_B8_BIT2(gbf, delay_value, "Delay Value", 1, 8, buf);
	SKIP(1); 

    END_ELEMENT(); 
}

int ms_radio_access_capability(uint8_t iei, uint8_t location)
{
	BEGIN_ELEMENT("MS Radio Access Capability", ms_radio_access_capability); 
	int ele_len = 0;
	int len = 0;
	if(iei == 1)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, iei, "IEI", 1, 8);
		ele_len += 1;
		SKIP(1); 
	}
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

    char buf[100] = {0};
    char *p = buf;
	int i;
	long long tmp = 0;
	int pos = 0;
	int tmp1 = 0;

    for(i = 0; i < len - 1; i++)
    {
        int tmp0 = 0;
        B8_BIT(tmp0, 1, 8);
        B8_HEX(); 
        A_B8_BIT2(gbf, ms_ra_capability_value, "MS RA capability value", 1, 8, "-"); 
        SKIP(1); 

        pos += sprintf(p + pos, "%02x", tmp0);
        //tmp += (tmp0 << 8*(len-1-i));
    }
    B8_BIT(tmp1, 1, 8);
    sprintf(p + pos, "%02x", tmp1);
    B8_HEX(); 
    A_B8_BIT2(gbf, ms_ra_capability_value, "MS RA capability value last", 1, 8, buf); 
    SKIP(1); 

    END_ELEMENT(); 
    return ele_len;
}

void priority(uint8_t iei, uint8_t location)
{
	BEGIN_ELEMENT("Priority", priority); 
	int len = 0;
	if(iei == 1)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, iei, "IEI", 1, 8);
		SKIP(1); 
	}
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}
	A_B8_BIT1(gbf, priority_iei, "Priority Level IEI", 5, 8);
	A_B8_BIT1(gbf, spare, "Spare", 4, 4);
	A_B8_BIT3(gbf, call_priority, "call priority", 1, 3, descriptive_group_broadcast_call_reference_call_priority);
	SKIP(1); 

    END_ELEMENT(); 
}

void drx_parameters(uint8_t iei, uint8_t location)
{
	BEGIN_ELEMENT("DRX Parameters", drx_parameters); 
	int len = 0;
	if(iei == 1)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, iei, "IEI", 1, 8);
		SKIP(1); 
	}
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}
	int tmp = 0;
	B8_BIT(tmp, 1, 8);
	B8_HEX(); 
	if(tmp == 0)
		A_B8_BIT2(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "704");
	else if(tmp > 64 && tmp < 99)
		A_B8_BIT3(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, gb_split_pg_cycle_code);
	else if(tmp > 0 && tmp < 65)
		A_B8_BIT2(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "respectively");
	else
		A_B8_BIT2(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "reserved");
	SKIP(1); 

	tmp = 0;
	B8_BIT(tmp, 5, 8);
	B8_HEX(); 
	if(tmp == 0 || (tmp > 5 && tmp < 10))
		A_B8_BIT3(gbf, drx_parameters_length, "CN Specific DRX cycle length coefficient", 5, 8, gb_cn_specific_drx_cycle);
	else
		A_B8_BIT2(gbf, drx_parameters_length, "CN Specific DRX cycle length coefficient", 5, 8, "CN Specific DRX cycle length coefficient not specified by the MS and DRX value not specified by the MS");
	A_B8_BIT3(gbf, split_on_ccch, "SPLIT on CCCH", 4, 4, gb_split_on_ccch);
	A_B8_BIT3(gbf, non_drx_timer, "non-DRX timer", 1, 3, gb_non_drx_timer);
	SKIP(1); 

    END_ELEMENT(); 
}

void bssgp_tlli(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("TLLI", tlli); 
	int len = 0;
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, tlli_iei, "TLLI IEI", 1, 8, "TLLI");  
            SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

    char buf[100];
    int tmp = -1;
    B32_BIT(tmp, 1, 32);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%u", tmp);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, buf);  
    SKIP(1);

    END_ELEMENT(); 
}

void bssgp_tlli_old(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("TLLI(old)", tlli); 
	int len = 0;
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, tlli_iei, "TLLI IEI", 1, 8, "TLLI");  
            SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

    char buf[100];
    int tmp = -1;
    B32_BIT(tmp, 1, 32);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%u", tmp);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TLLI value (contd)", 1, 8, buf);  
    SKIP(1);

    END_ELEMENT(); 
}

#if 0 
void packet_flow_identifier(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Packet Flow Identifier", packet_flow_identifier); 
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "Packet Flow Identifier IEI");  
        SKIP(1); 
    }    

    if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	B8_BIT(tmp, 1, 7);
	B8_HEX(); 
	A_B8_BIT1(gbf, spare, "Spare", 8, 8);
	if(tmp > 3 && tmp < 8)
		A_B8_BIT2(gbf, packet_flow_identifier_v, "Packet Flow Identifier value", 1, 7, "reserved");
	else if(tmp > 7 && tmp < 256)
		A_B8_BIT2(gbf, packet_flow_identifier_v, "Packet Flow Identifier value", 1, 7, "dynamically assigned");
	else
		A_B8_BIT3(gbf, packet_flow_identifier_v, "Packet Flow Identifier value", 1, 7, gb_packet_flow_identifier_v);
	SKIP(1); 

    END_ELEMENT(); 
}
#endif 
void packet_flow_identifier(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Packet Flow Identifier", packet_flow_identifier); 
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "Packet Flow Identifier IEI");  
        SKIP(1); 
    }    

    if(location == 1)
    {

        B8_BIT(len, 1, 8);
        B8_HEX(); 
        A_B8_BIT1(gbf, ie_length, "Length of Packet Flow Identifier IE", 1, 8);
        SKIP(1); 
    }

	int tmp = 0;
	B8_BIT(tmp, 1, 7);
	B8_HEX(); 
	A_B8_BIT1(gbf, spare, "Spare", 8, 8);
	if(tmp > 3 && tmp < 8)
		A_B8_BIT2(gbf, packet_flow_identifier_v, "Packet Flow Identifier value", 1, 7, "reserved");
	else if(tmp > 7 && tmp < 256)
		A_B8_BIT2(gbf, packet_flow_identifier_v, "Packet Flow Identifier value", 1, 7, "dynamically assigned");
	else
		A_B8_BIT3(gbf, packet_flow_identifier_v, "Packet Flow Identifier value", 1, 7, gb_packet_flow_identifier_v);
	SKIP(1); 
    END_ELEMENT(); 
}

int lsa_information(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("LSA Information", lsa_information); 
	int ele_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
		ele_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            ele_len += len + 2;
            SKIP(1);
        }
	}

	int i = 0;
	for(i = 0; i < len; i++)
	{
        B8_HEX(); 
		A_B8_BIT1(gbf, lsa_information_coded, "LSA Information coded", 1, 8);
		ele_len += 1;
		SKIP(1);
	}

    END_ELEMENT(); 
	return ele_len;
}

int lsa_identifier_list(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("LSA Identifier List", lsa_identifier_list); 
	int ele_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
		ele_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

	int i = 0;
	for(i = 0; i < len; i++)
	{
        B8_HEX(); 
		A_B8_BIT1(gbf, lsa_identifier_list_coded, "LSA Identifier List coded", 1, 8);
		ele_len += 1;
		SKIP(1);
	}

    END_ELEMENT(); 
}


void service_utran_cco(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Service UTRAN CCO", service_utran_cco); 
	int len = 0;
    if(iei == 1)
    {    
            B8_HEX(); 
            A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
            SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}
	int tmp = 0;
	B8_BIT(tmp, 1, 3);
	B8_HEX(); 
	A_B8_BIT1(gbf, spare, "Spare", 4, 8);
	if (tmp >= 0 && tmp < 3)
		A_B8_BIT3(gbf, service_utran_cco_value, "Service UTRAN CCO Value", 1, 3, gb_service_utran_cco_v);
	else
		A_B8_BIT2(gbf, service_utran_cco_value, "Service UTRAN CCO Value", 1, 3, "No information available");
	SKIP(1); 

    END_ELEMENT(); 
}

int alignment_octets(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Alignment octets", alignment_octets); 
	int alignment_octets_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
		alignment_octets_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    alignment_octets_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    alignment_octets_len += len + 2;
            SKIP(1);
        }
	}
	int i = 0;
	for(i = 0; i < len; i++)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, spare, "Spare", 1, 8);
		SKIP(1); 
	}

    END_ELEMENT(); 
	return alignment_octets_len;
}

int llc_pdu(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("LLC-PDU", llc_pdu); 
	int ele_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
		ele_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            ele_len += 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            ele_len += 2;
            SKIP(1);
        }
	}

#if 0
    char buf[100] = {0};
	int i = 0;
	long long tmp = 0;
	int tmp1 = 0;
    if(len > 0)
    {
	    for(i = 0; i < len - 1; i++)
	    {
	    	int tmp0 = 0;
	    	B8_BIT(tmp0, 1, 8);
        	B8_HEX(); 
        	A_B8_BIT2(gbf, llc_pdu_value, "LLC-PDU value", 1, 8, "-");
	    	SKIP(1); 

	    	tmp += (tmp0 << 8*(len-1-i));
	    }
	    B8_BIT(tmp1, 1, 8);
	    tmp += tmp1;
	    sprintf((char *)buf, "%ld", tmp);
        B8_HEX(); 
        A_B8_BIT2(gbf, llc_pdu_value_last, "LLC-PDU value last", 1, 8, buf);
	    SKIP(1); 
    }
#endif

    END_ELEMENT(); 
	return ele_len;
}

int routing_area_identification(uint8_t iei, uint8_t location)
{
	int ele_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
		ele_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

    char mcc_buf[16*1024] = {0}; 
    char mnc_buf[16*1024] = {0}; 
	char buf[10] = {0}; 
    uint8_t mnc1; 
    uint8_t mnc2; 
    uint8_t mnc3; 
    uint8_t mcc1; 
    uint8_t mcc2; 
    uint8_t mcc3; 
    uint16_t mcc; 
    uint16_t mnc; 
    uint16_t tmp; 

    B8_BIT(mcc1, 1, 4); 
    B8_BIT(mcc2, 5, 8); 
    SKIP(1); 
    B8_BIT(mnc3, 5, 8); 
    B8_BIT(mcc3, 1, 4); 
    SKIP(1); 
    B8_BIT(mnc2, 5, 8); 
    B8_BIT(mnc1, 1, 4); 
    mcc = 100 * mcc1 + 10 * mcc2 + mcc3; 
    sprintf(mcc_buf, "MCC = %d", mcc); 
    mnc = 100 * mnc1 + 10 * mnc2 + mnc3; 
    sprintf(mnc_buf, "MNC = %d", mnc); 
    BACK(2); 

    B8_HEX(); 
    A_B8_BIT2(gbf, mcc_digit2 ,"MCC digit 2", 5, 8, "-"); 
    A_B8_BIT2(gbf, mcc_digit1 ,"MCC digit 1", 1, 4, "-"); 
    SKIP(1); 
    
    B8_HEX(); 
    A_B8_BIT2(gbf, mnc_digit3 ,"MNC digit 3", 5, 8, "-"); 
    A_B8_BIT2(gbf, mcc_digit3 ,"MCC digit 3", 1, 4, mcc_buf); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT2(gbf, mnc_digit2 ,"MNC digit 2", 5, 8, "-"); 
    A_B8_BIT2(gbf, mnc_digit1 ,"MNC digit 1", 1, 4, mnc_buf); 
    SKIP(1); 

    B8_HEX(); 
	B16_BIT(tmp, 1, 16); 
	sprintf(buf, "LAC=%d", tmp); 
    A_B8_BIT1(gbf, lac ,"LAC", 1, 8); 
    SKIP(1); 
    B8_HEX(); 
    A_B8_BIT2(gbf, lac_c ,"LAC (continued)", 1, 8, buf); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT1(gbf, rac, "Rac", 1, 8);
	SKIP(1);

	return ele_len;
}


int cell_identifier(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cell Identifier", cell_identifier); 
	int ele_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
		ele_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

	routing_area_identification(0, 0);

    B8_HEX();
	int tmp = 0;
	char buf[100] = {0};
    B16_BIT(tmp, 1, 16); 
    sprintf(buf, "Cl value=%d", tmp);
    A_B8_BIT2(gbf, cl_value, "Cl value", 1, 8, "-");
    SKIP(1);
    B8_HEX();
    A_B8_BIT2(gbf, cl_value_continued, "Cl value (continued)", 1, 8, buf);
    SKIP(1);

    END_ELEMENT(); 
	return ele_len;
}

void bssgp_bvci(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("BSSGP Virtual Connection Identifier", bssgp_bvci); 
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "IEI");  
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	char buf[100] = {0};
    B16_BIT(tmp, 1, 16); 
    sprintf(buf, "%d", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, unstructured_value, "Unstructured value", 1, 8, "-");
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, unstructured_value, "Unstructured value", 1, 8, buf);
    SKIP(1);

    END_ELEMENT(); 
}

void location_area(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Location Area", location_area); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "Location Area IEI", 1, 8, "Location Area"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

    char mcc_buf[16*1024] = {0}; 
    char mnc_buf[16*1024] = {0}; 
	char buf[10] = {0}; 
    uint8_t mnc1; 
    uint8_t mnc2; 
    uint8_t mnc3; 
    uint8_t mcc1; 
    uint8_t mcc2; 
    uint8_t mcc3; 
    uint16_t mcc; 
    uint16_t mnc; 
    uint16_t tmp; 

    B8_BIT(mcc1, 1, 4); 
    B8_BIT(mcc2, 5, 8); 
    SKIP(1); 
    B8_BIT(mnc3, 5, 8); 
    B8_BIT(mcc3, 1, 4); 
    SKIP(1); 
    B8_BIT(mnc2, 5, 8); 
    B8_BIT(mnc1, 1, 4); 
    mcc = 100 * mcc1 + 10 * mcc2 + mcc3; 
    sprintf(mcc_buf, "MCC = %d", mcc); 
    mnc = 100 * mnc1 + 10 * mnc2 + mnc3; 
    sprintf(mnc_buf, "MNC = %d", mnc); 
    BACK(2); 

    B8_HEX(); 
    A_B8_BIT2(gbf, mcc_digit2 ,"MCC digit 2", 5, 8, "-"); 
    A_B8_BIT2(gbf, mcc_digit1 ,"MCC digit 1", 1, 4, "-"); 
    SKIP(1); 
    
    B8_HEX(); 
    A_B8_BIT2(gbf, mnc_digit3 ,"MNC digit 3", 5, 8, "-"); 
    A_B8_BIT2(gbf, mcc_digit3 ,"MCC digit 3", 1, 4, mcc_buf); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT2(gbf, mnc_digit2 ,"MNC digit 2", 5, 8, "-"); 
    A_B8_BIT2(gbf, mnc_digit1 ,"MNC digit 1", 1, 4, mnc_buf); 
    SKIP(1); 

    B8_HEX(); 
	B16_BIT(tmp, 1, 16); 
	sprintf(buf, "LAC=%d", tmp); 
    A_B8_BIT1(gbf, lac ,"LAC", 1, 8); 
    SKIP(1); 

    B8_HEX(); 
    A_B8_BIT2(gbf, lac_c ,"LAC (continued)", 1, 8, buf); 
    SKIP(1); 

    END_ELEMENT(); 
}

void routeing_area(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Routing Area", routing_area); 

	routing_area_identification(iei, location);

    END_ELEMENT(); 
}

void bss_area_indication(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("BSS Area Indication", bss_area_indication); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	B8_HEX(); 
	A_B8_BIT1(gbf, bss_indicator, "BSS Indicator", 1, 8);
	SKIP(1); 

    END_ELEMENT(); 
}

void tmsi(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("TMSI", tmsi); 
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, tmsi_p_tmsi_iei, "IEI", 1, 8, "TMSI IEI");  
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

    char buf[100];
    int tmp = -1;
    B32_BIT(tmp, 1, 32);
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "TMSI/P-TMSI value = %ld", tmp);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value (contd)", 1, 8, "-");  
    SKIP(1);

    B8_HEX();
    A_B8_BIT2(gbf, tmsi_p_tmsi_value, "TMSI/P-TMSI value (contd)", 1, 8, buf);  
    SKIP(1);

    END_ELEMENT(); 
}

int abqp(uint8_t iei, uint8_t location, uint8_t dir) 
{    
    BEGIN_ELEMENT("Aggregate BSS QoS Profile", sbqp); 
	int ele_len = 0;
	int len = 0;
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, tmsi_p_tmsi_iei, "IEI", 1, 8, "IEI");  
		ele_len += 1;
        SKIP(1); 
    }    
	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

	int tmp = 0;
	B8_BIT(tmp, 4, 6);
	B8_HEX(); 
	A_B8_BIT1(gbf, spare, "Spare", 7, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Reserved");
		else
			A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Subscribed delay class");
	}
	else if((tmp > 0 && tmp < 5) || tmp == 7)
		A_B8_BIT3(gbf, delay_class, "Delay class", 4, 6, gb_delay_class);
	else
		A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Delay class 4 (best effort)");
	B8_BIT(tmp, 1, 3);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Reserved");
		else
			A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Subscribed reliability class");
	}
	else if((tmp > 0 && tmp < 6) || tmp == 7)
		A_B8_BIT3(gbf, reliability_class, "Reliability class", 1, 3, gb_reliability_class);
	else
		A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Unacknowledged GTP and LLC; Acknowledged RLC, Protected data");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 5, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Reserved");
		else
			A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Subscribed peak throughput");
	}
	else if((tmp > 0 && tmp < 10) || tmp == 15)
		A_B8_BIT3(gbf, peak_throughput, "Reak throughput", 5, 8, gb_peak_throughput);
	else
		A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 1000 octet/s");
	A_B8_BIT1(gbf, spare, "Spare", 4, 4);
	B8_BIT(tmp, 1, 3);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Reserved");
		else
			A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Subscribed precedence");
	}
	else if((tmp > 0 && tmp < 4) || tmp == 7)
		A_B8_BIT3(gbf, precedence_class, "Precedence class", 1, 3, gb_precedence_class);
	else
		A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Normal priority");
	SKIP(1);

	B8_HEX();
	A_B8_BIT1(gbf, spare, "Spare", 6, 8);
	B8_BIT(tmp, 1, 5);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "Reserved");
		else
			A_B8_BIT2(gbf, mean_throughput, "Mean throughpu", 1, 5, "Subscribed mean throughput");
	}
	else if((tmp > 0 && tmp < 19) || tmp == 30 || tmp == 31)
		A_B8_BIT3(gbf, mean_throughput, "Mean throughput", 1, 5, gb_mean_throughput);
	else
		A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "Best effort");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 6, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, traffic_class, "Traffic Class", 6, 8, "Reserved");
		else
			A_B8_BIT2(gbf, traffic_class, "Traffic Class", 6, 8, "Subscribed traffic class");
	}
	else if((tmp > 0 && tmp < 5) || tmp == 7)
		A_B8_BIT3(gbf, traffic_class, "Traffic Class", 6, 8, gb_traffic_class);
	else
		A_B8_BIT2(gbf, traffic_class, "Traffic Class", 6, 8, "reserved");
	B8_BIT(tmp, 4, 5);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "Reserved");
		else
			A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "Subscribed delivery order");
	}
	else
		A_B8_BIT3(gbf, delivery_order, "Delivery order", 4, 5, gb_delivery_order);
	B8_BIT(tmp, 1, 3);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, delivery_of_erroneous_sdu, "Delivery of erroneous SDU", 1, 3, "Reserved");
		else
			A_B8_BIT2(gbf, delivery_of_erroneous_sdu, "Delivery of erroneous SDU", 1, 3, "Subscribed delivery of erroneous SDUs");
	}
	else if((tmp > 0 && tmp < 4) || tmp == 7)
		A_B8_BIT3(gbf, delivery_of_erroneous_sdu, "Delivery of erroneous SDU", 1, 3, gb_delivery_of_erroneous_sdu);
	else
		A_B8_BIT2(gbf, delivery_of_erroneous_sdu, "Delivery of erroneous SDU", 1, 3, "reserved");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 1, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "Reserved");
		else
			A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "Subscribed maximum SDU size");
	}
	else if(tmp > 0 && tmp < 151)
	{
		int maximum_sdu_size_v = 0;
		maximum_sdu_size_v = tmp * 10 + 10;
		char str_maximum_sdu_size_v[20] = {0};
		sprintf(str_maximum_sdu_size_v, "%d octets", maximum_sdu_size_v);
		A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "str_maximum_sdu_size_v");
	}
	else if(tmp > 150 && tmp < 154)
		A_B8_BIT3(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, gb_maximum_sdu_size);
	else
		A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "reserved");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 1, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, maximum_bit_rate_f_u, "Maximum bit rate for uplink", 1, 8, "Reserved");
		else
			A_B8_BIT2(gbf, maximum_bit_rate_f_u, "Maximum bit rate for uplink", 1, 8, "Subscribed maximum  bit rate for uplink");
	}
	else if(tmp == 1 || tmp == 63 || tmp == 64 || tmp == 127 || tmp == 128 || tmp == 254 || tmp == 255)
		A_B8_BIT3(gbf, maximum_bit_rate_f_u, "Maximum bit rate for uplink", 1, 8, gb_maximum_bit_rate_f_u);
	else
		A_B8_BIT2(gbf, maximum_bit_rate_f_u, "Maximum bit rate for uplink", 1, 8, "reserved");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 1, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, maximum_bit_rate_f_d, "Maximum bit rate for downlink", 1, 8, "Reserved");
		else
			A_B8_BIT2(gbf, maximum_bit_rate_f_d, "Maximum bit rate for downlink", 1, 8, "Subscribed maximum  bit rate for downlink");
	}
	else if(tmp == 1 || tmp == 63 || tmp == 64 || tmp == 127 || tmp == 128 || tmp == 254 || tmp == 255)
		A_B8_BIT3(gbf, maximum_bit_rate_f_d, "Maximum bit rate for downlink", 1, 8, gb_maximum_bit_rate_f_u);
	else
		A_B8_BIT2(gbf, maximum_bit_rate_f_d, "Maximum bit rate for downlink", 1, 8, "reserved");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 5, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, residual_ber, "Residual Bit Error Rate (BER)", 5, 8, "Reserved");
		else
			A_B8_BIT2(gbf, residual_ber, "Residual Bit Error Rate (BER)", 5, 8, "Subscribed residual BER");
	}
	else if((tmp > 0 && tmp < 10) || tmp == 15)
		A_B8_BIT3(gbf, residual_ber, "Residual Bit Error Rate (BER)", 5, 8, gb_residual_ber);
	else
		A_B8_BIT2(gbf, residual_ber, "Residual Bit Error Rate (BER)", 5, 8, "reserved");
	B8_BIT(tmp, 1, 4);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, sdu_error_ratio, "SDU error ratio", 1, 4, "Reserved");
		else
			A_B8_BIT2(gbf, sdu_error_ratio, "SDU error ratio", 1, 4, "Subscribed SDU error ratio");
	}
	else if((tmp > 0 && tmp < 8) || tmp == 15)
		A_B8_BIT3(gbf, sdu_error_ratio, "SDU error ratio", 1, 4, gb_sdu_error_ratio);
	else
		A_B8_BIT2(gbf, sdu_error_ratio, "SDU error ratio", 1, 4, "reserved");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 3, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "Reserved");
		else
			A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "Subscribed transfer delay");
	}
	else if(tmp == 1 || tmp == 63 || tmp == 64 || tmp == 127 || tmp == 128 || tmp == 254 || tmp == 255)
		A_B8_BIT3(gbf, transfer_delay, "Transfer delay", 3, 8, gb_transfer_delay);
	else
		A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "reserved");
	B8_BIT(tmp, 1, 2);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, traffic_handling_priority, "Traffic handling priority", 1, 2, "Reserved");
		else
			A_B8_BIT2(gbf, traffic_handling_priority, "Traffic handling priority", 1, 2, "Subscribed traffic handling priority");
	}
	else if(tmp > 0 && tmp < 4)
		A_B8_BIT3(gbf, traffic_handling_priority, "Traffic handling priority", 1, 2, gb_traffic_handling_priority);
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 1, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_u, "Guaranteed bit rate for uplink", 1, 8, "Reserved");
		else
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_u, "Guaranteed bit rate for uplink", 1, 8, "Subscribed guaranteed bit rate for uplink");
	}
	else if(tmp == 1 || tmp == 63 || tmp == 64 || tmp == 127 || tmp == 128 || tmp == 254 || tmp == 255)
		A_B8_BIT3(gbf, guaranteed_bit_rate_f_u, "Guaranteed bit rate for uplink", 1, 8, gb_guaranteed_bit_rate_f_u);
	else
		A_B8_BIT2(gbf, guaranteed_bit_rate_f_u, "Guaranteed bit rate for uplink", 1, 8, "reserved");
	SKIP(1);

	B8_HEX();
	B8_BIT(tmp, 1, 8);
	if (tmp == 0)
	{
		if(dir == 0)
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_d, "Guaranteed bit rate for downlink", 1, 8, "Reserved");
		else
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_d, "Guaranteed bit rate for downlink", 1, 8, "Subscribed guaranteed bit rate for downlink");
	}
	else if(tmp == 1 || tmp == 63 || tmp == 64 || tmp == 127 || tmp == 128 || tmp == 254 || tmp == 255)
		A_B8_BIT3(gbf, guaranteed_bit_rate_f_d, "Guaranteed bit rate for downlink", 1, 8, gb_guaranteed_bit_rate_f_u);
	else
		A_B8_BIT2(gbf, guaranteed_bit_rate_f_d, "Guaranteed bit rate for downlink", 1, 8, "reserved");
	SKIP(1);

	if(ele_len > 13)
	{
		B8_HEX();
		A_B8_BIT1(gbf, spare, "Spare", 6, 8);
		A_B8_BIT3(gbf, signalling_indication, "Signalling Indication", 5, 5, gb_signalling_indication);
		B8_BIT(tmp, 1, 4);
		if(dir == 0)
			A_B8_BIT2(gbf, source_statistics_descriptor, "Source Statistics Descriptor", 1, 4, "0");
		else
		{
			if(tmp == 1)
				A_B8_BIT2(gbf, source_statistics_descriptor, "Source Statistics Descriptor", 1, 4, "speech");
			else
				A_B8_BIT2(gbf, source_statistics_descriptor, "Source Statistics Descriptor", 1, 4, "unknown");
		}
		SKIP(1);
	}
	if(ele_len > 14)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for downlink (extended)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for downlink (extended)", 1, 8, "Subscribed maximum  bit rate for downlink");
		}
		else if(tmp == 1 || tmp == 74 || tmp == 75 || tmp == 186 || tmp == 187 || tmp == 250)
			A_B8_BIT3(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for downlink (extended)", 1, 8, gb_maximum_bit_rate_f_u_e);
		else
			A_B8_BIT2(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for downlink (extended)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 15)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for downlink (extended)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for downlink (extended)", 1, 8, "Subscribed guaranteed bit rate for downlink");
		}
		else if(tmp == 1 || tmp == 74 || tmp == 75 || tmp == 186 || tmp == 187 || tmp == 250)
			A_B8_BIT3(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for downlink (extended)", 1, 8, gb_guaranteed_bit_rate_f_u_e);
		else
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for downlink (extended)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 16)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for uplink (extended)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for uplink (extended)", 1, 8, "Subscribed maximum  bit rate for uplink");
		}
		else if(tmp == 1 || tmp == 74 || tmp == 75 || tmp == 186 || tmp == 187 || tmp == 250)
			A_B8_BIT3(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for uplink (extended)", 1, 8, gb_maximum_bit_rate_f_u_e);
		else
			A_B8_BIT2(gbf, maximum_bit_rate_f_d_e, "Maximum bit rate for uplink (extended)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 17)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for uplink (extended)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for uplink (extended)", 1, 8, "Subscribed guaranteed bit rate for uplink");
		}
		else if(tmp == 1 || tmp == 74 || tmp == 75 || tmp == 186 || tmp == 187 || tmp == 250)
			A_B8_BIT3(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for uplink (extended)", 1, 8, gb_guaranteed_bit_rate_f_u_e);
		else
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e, "Guaranteed bit rate for uplink (extended)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 18)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, maximum_bit_rate_f_d_e2, "Maximum bit rate for downlink (extended-2)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, maximum_bit_rate_f_d_e2, "Maximum bit rate for downlink (extended-2)", 1, 8, "Subscribed maximum bit rate for downlink (extended-2)");
		}
		else if(tmp == 1 || tmp == 61 || tmp == 62 || tmp == 161 || tmp == 162 || tmp == 246)
			A_B8_BIT3(gbf, maximum_bit_rate_f_d_e2, "Maximum bit rate for downlink (extended-2)", 1, 8, gb_maximum_bit_rate_f_u_e2);
		else
			A_B8_BIT2(gbf, maximum_bit_rate_f_d_e2, "Maximum bit rate for downlink (extended-2)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 19)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "Subscribed guaranteed bit rate for downlink (extended-2)");
		}
		else if(tmp == 1 || tmp == 61 || tmp == 62 || tmp == 161 || tmp == 162 || tmp == 246)
			A_B8_BIT3(gbf, guaranteed_bit_rate_f_d_e2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, gb_guaranteed_bit_rate_f_u_e2);
		else
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_d_e2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 20)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, maximum_bit_rate_f_u_e2, "Maximum bit rate for uplink (extended-2)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, maximum_bit_rate_f_u_e2, "Maximum bit rate for uplink (extended-2)", 1, 8, "Subscribed maximum bit rate for uplink (extended-2)");
		}
		else if(tmp == 1 || tmp == 61 || tmp == 62 || tmp == 161 || tmp == 162 || tmp == 246)
			A_B8_BIT3(gbf, maximum_bit_rate_f_u_e2, "Maximum bit rate for uplink (extended-2)", 1, 8, gb_maximum_bit_rate_f_u_e2);
		else
			A_B8_BIT2(gbf, maximum_bit_rate_f_u_e2, "Maximum bit rate for uplink (extended-2)", 1, 8, "reserved");
		SKIP(1);
	}

	if(ele_len > 21)
	{
		B8_HEX();
		B8_BIT(tmp, 1, 8);
		if (tmp == 0)
		{
			if(dir == 0)
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_u_e2, "Guaranteed bit rate for uplink (extended-2)", 1, 8, "Reserved");
			else
				A_B8_BIT2(gbf, guaranteed_bit_rate_f_u_e2, "Guaranteed bit rate for uplink (extended-2)", 1, 8, "Subscribed guaranteed bit rate for uplink (extended-2)");
		}
		else if(tmp == 1 || tmp == 61 || tmp == 62 || tmp == 161 || tmp == 162 || tmp == 246)
			A_B8_BIT3(gbf, guaranteed_bit_rate_f_u_e2, "Guaranteed bit rate for uplink (extended-2)", 1, 8, gb_guaranteed_bit_rate_f_u_e2);
		else
			A_B8_BIT2(gbf, guaranteed_bit_rate_f_u_e2, "Guaranteed bit rate for uplink (extended-2)", 1, 8, "reserved");
		SKIP(1);
	}

    END_ELEMENT(); 
	return ele_len;
}

void bssgp_channel_needed(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Channel Needed", bssgp_channel_needed); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	B8_HEX(); 
	A_B8_BIT1(gbf, channel_needed_iei, "Channel Needed IEI", 5, 8);
    B8_BIT(tmp , 1, 4);
    if(tmp == 0)
        A_B8_BIT2(gbf, channel, "Channel", 1, 4, "Any channel");
    else if(tmp == 1)
        A_B8_BIT2(gbf, channel, "Channel", 1, 4, "SDCCH");
    else if(tmp == 2)
        A_B8_BIT2(gbf, channel, "Channel", 1, 4, "TCH/F (Full rate)");
    else
        A_B8_BIT2(gbf, channel, "Channel", 1, 4, "TCH/H or TCH/F (Dual rate)");
    SKIP(1);

    END_ELEMENT(); 
}

void emlpp_priority(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("eMLPP-Priority", emlpp_priority); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	B8_HEX(); 
	A_B8_BIT1(gbf, spare, "Spare", 8, 8);
    B8_BIT(tmp , 7, 7);
	if(tmp == 0)
		A_B8_BIT2(gbf, pci, "pci", 7, 7, "this allocation request shall not preempt an existing connection");
	else
		A_B8_BIT2(gbf, pci, "pci", 7, 7, "this allocation request may preempt an existing connection");
	A_B8_BIT3(gbf, priority_level, "priority level", 3, 6, gb_priority_level);
    B8_BIT(tmp , 2, 2);
	if(tmp == 0)
		A_B8_BIT2(gbf, qa, "queueing allowed indicator", 2, 2, "queueing not allowed");
	else
		A_B8_BIT2(gbf, qa, "queueing allowed indicator", 2, 2, "queueing allowed");
    B8_BIT(tmp , 1, 1);
	if(tmp == 0)
		A_B8_BIT2(gbf, pvi, "Preemption Vulnerability indicator", 1, 1, "this connection shall not be preempted by another allocation request");
	else
		A_B8_BIT2(gbf, pvi, "Preemption Vulnerability indicator", 1, 1, "this connection might be preempted by another allocation request");

    END_ELEMENT(); 
}

void tag(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Tag", tag); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	B8_HEX(); 
	A_B8_BIT1(gbf, unstructured_value, "Unstructured value", 1, 8);
	SKIP(1); 

    END_ELEMENT(); 
}

void ra_cap_upd_cause(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("RA-Cap-UPD-Cause", ra_cap_upd_cause); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	B8_HEX(); 
	B8_BIT(tmp, 1, 8);
	if(tmp == 0)
		A_B8_BIT2(gbf, ra_cap_upd_cause_v, "RA-Cap-UPD-Cause value", 1, 8, "OK, RA capability IE present");
	else if(tmp == 1)
		A_B8_BIT2(gbf, ra_cap_upd_cause_v, "RA-Cap-UPD-Cause value", 1, 8, "TLLI unknown in SGSN");
	else if(tmp == 2)
		A_B8_BIT2(gbf, ra_cap_upd_cause_v, "RA-Cap-UPD-Cause value", 1, 8, "No RA Capabilities or IMSI available for this MS");
	else
		A_B8_BIT2(gbf, ra_cap_upd_cause_v, "RA-Cap-UPD-Cause value", 1, 8, "All values not explicitly listed are reserved. If received, they shall be handled as \"TLLI unknown in SGSN\"");
	SKIP(1); 

    END_ELEMENT(); 
}

void radio_cause(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Radio Cause", radio_cause); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	B8_HEX(); 
	B8_BIT(tmp, 1, 8);
	if(tmp == 0)
		A_B8_BIT2(gbf, radio_cause_v, "Radio Cause value", 1, 8, "Radio contact lost with the MS");
	else if(tmp == 1)
		A_B8_BIT2(gbf, radio_cause_v, "Radio Cause value", 1, 8, "Radio link quality insufficient to continue communication");
	else if(tmp == 2)
		A_B8_BIT2(gbf, radio_cause_v, "Radio Cause value", 1, 8, "cell-reselection ordered");
	else
		A_B8_BIT2(gbf, radio_cause_v, "Radio Cause value", 1, 8, "All values not explicitly listed are reserved. If received, they shall be handled as \"radio contact lost with the MS\"");
	SKIP(1); 

    END_ELEMENT(); 
}

void suspend_reference_number(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Suspend Reference Number", suspended_reference_number); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	B8_HEX(); 
	A_B8_BIT1(gbf, suspended_reference_number_v, "Suspend Reference Number", 1, 8);
	SKIP(1);

    END_ELEMENT(); 
}

void bssgp_cause(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Cause", bssgp_cause); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	B8_HEX(); 
	B8_BIT(tmp, 1, 8);
	if((tmp >= 0 && tmp < 11) || (tmp > 31 && tmp < 41))
		A_B8_BIT3(gbf, cause_v, "Cause value", 1, 8, gb_cause_v);
	else
		A_B8_BIT2(gbf, cause_v, "Cause value", 1, 8, "protocol error - unspecified");
	SKIP(1);

    END_ELEMENT(); 
}

int flush_action(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Flush Action", flush_action); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	int is_transferred = 0;
	B8_HEX(); 
	B8_BIT(tmp, 1, 8);
	if(tmp == 0)
		A_B8_BIT2(gbf, action_v, "Action value", 1, 8, "LLC-PDU(s) deleted");
	else if(tmp == 1)
	{
		A_B8_BIT2(gbf, action_v, "Action value", 1, 8, "LLC-PDU(s) transferred");
		is_transferred = 1;
	}
	else
		A_B8_BIT2(gbf, action_v, "Action value", 1, 8, "reserved");
	SKIP(1);

    END_ELEMENT(); 
	return is_transferred;
}

void number_of_octets_affected(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Number of octets affected", number_of_octets_affected); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	char buf[100] = {0};

	B8_HEX(); 
	B8_BIT(tmp0, 1, 8);
	A_B8_BIT2(gbf, number_of_octets_t_o_d, "number of octets transferred or deleted", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	B8_BIT(tmp1, 1, 8);
	A_B8_BIT2(gbf, number_of_octets_t_o_d, "number of octets transferred or deleted", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	B8_BIT(tmp2, 1, 8);
	tmp = (tmp0 << 16) + (tmp1 << 8) + tmp2;
	sprintf((char *)buf, "%d", tmp);
	if(tmp <= 6553500)
		A_B8_BIT2(gbf, number_of_octets_t_o_d, "number of octets transferred or deleted", 1, 8, buf);
	else
		A_B8_BIT2(gbf, number_of_octets_t_o_d, "number of octets transferred or deleted", 1, 8, "6553500");
	SKIP(1);

    END_ELEMENT(); 
}

void llc_frames_discarded(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("LLC Frames Discarded", llc_frames_discarded); 
	int len = 0;
    if(iei == 1) 
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B8_HEX(); 
	B8_BIT(tmp, 1, 8);
	sprintf((char *)buf, "%x", tmp);
	A_B8_BIT2(gbf, number_of_frames_d , "Number of frames discarded", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void bvc_bucket_size(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("BVC Bucket Size", bvc_bucket_size); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B16_BIT(tmp, 1, 16);
	tmp = tmp * 100;
	sprintf((char *)buf, "%d octets", tmp);

	B8_HEX(); 
	A_B8_BIT2(gbf, bmax_msb , "Bmax (MSB)", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	A_B8_BIT2(gbf, bmax_lsb , "Bmax (LSB)", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void bucket_leak_rate(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Bucket Leak Rate", bucket_leak_rate); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B16_BIT(tmp, 1, 16);
	tmp = tmp * 100;
	sprintf((char *)buf, "%d octets", tmp);

	B8_HEX(); 
	A_B8_BIT2(gbf, r_value_msb , "R Value (MSB)", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	A_B8_BIT2(gbf, r_value_lsb , "R Value (LSB)", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void bmax_default_ms(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Bmax default MS", bmax_default_ms); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B16_BIT(tmp, 1, 16);
	tmp = tmp * 100;
	sprintf((char *)buf, "%d octets", tmp);

	B8_HEX(); 
	A_B8_BIT2(gbf, bmax_msb , "Bmax (MSB)", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	A_B8_BIT2(gbf, bmax_lsb , "Bmax (LSB)", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void r_default_ms(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("R_default_MS", r_default_ms); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B16_BIT(tmp, 1, 16);
	tmp = tmp * 100;
	sprintf((char *)buf, "%d octets", tmp);

	B8_HEX(); 
	A_B8_BIT2(gbf, r_default_ms_v_m , "R_default_MS Value (MSB)", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	A_B8_BIT2(gbf, r_default_ms_v_l , "R_default_MS Value (LSB)", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void bucket_full_ratio(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Bucket Full Ratio", bucket_full_ratio); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	B8_HEX(); 
	A_B8_BIT1(gbf, filled_up_data , "Filled up data", 1, 8);
	SKIP(1);

    END_ELEMENT(); 
}

void bvc_measurement(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("BVC Measurement", bvc_measurement); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B16_BIT(tmp, 1, 16);
	sprintf((char *)buf, "%d", tmp);

	B8_HEX(); 
	A_B8_BIT2(gbf, delay_v , "Delay Value", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	A_B8_BIT2(gbf, delay_v, "Delay Value", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void ms_bucket_size(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("MS Bucket Size", ms_bucket_size); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}


	int tmp = 0;
	char buf[100] = {0};
	B16_BIT(tmp, 1, 16);
	tmp = tmp * 100;
	sprintf((char *)buf, "%d octets", tmp);

	B8_HEX(); 
	A_B8_BIT2(gbf, bmax_msb , "Bmax (MSB)", 1, 8, "-");
	SKIP(1);

	B8_HEX(); 
	A_B8_BIT2(gbf, bmax_lsb , "Bmax (LSB)", 1, 8, buf);
	SKIP(1);

    END_ELEMENT(); 
}

void feature_bitmap(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Feature Bitmap", feature_bitmap); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	B8_HEX(); 
	A_B8_BIT1(gbf, spare, "Spare", 3, 8);
	B8_BIT(tmp, 2, 2);
	if(tmp == 0)
		A_B8_BIT2(gbf, cbl, "CBL", 2, 2, "Current Bucket Level Procedures not supported");
	else
		A_B8_BIT2(gbf, cbl, "CBL", 2, 2, "Current Bucket Level Procedures supported");
	B8_BIT(tmp, 1, 1);
	if(tmp == 0)
		A_B8_BIT2(gbf, pfc, "PFC", 1, 1, "Packet Flow Context Procedures not supported");
	else
		A_B8_BIT2(gbf, pfc, "PFC", 1, 1, "Packet Flow Context Procedures supported");
	SKIP(1);

    END_ELEMENT(); 
}

int pdu_in_error(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("PDU In Error", pdu_in_error); 
	int len = 0;
	int ele_len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
		ele_len += 1;
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

	int i = 0;
	for(i = 0; i < len; i++)
	{
		int tmp = 0;
		char buf[50] = {0};
		B8_BIT(tmp, 1, 8);
		sprintf((char *)buf, "%x", tmp);
		B8_HEX(); 
		A_B8_BIT2(gbf, erroneous_bssgp_pdu, "Erroneous BSSGP PDU", 1, 8, buf);
		SKIP(1);
	}

    END_ELEMENT(); 
	return ele_len;
}

void trace_reference(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Trace Reference", trace_reference); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	char buf[50] = {0};
	B16_BIT(tmp, 1, 16);
	sprintf((char *)buf, "%d", tmp);
	B8_HEX();
    A_B8_BIT2(gbf, trace_reference_v, "Trace Reference", 1, 8, "-"); 
	SKIP(1);

	B8_HEX();
    A_B8_BIT2(gbf, trace_reference_v, "Trace Reference", 1, 8, buf); 
	SKIP(1);

    END_ELEMENT(); 
}

void gprs_timer(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("GPRS Timer", gprs_timer); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
    B8_HEX();
	B8_BIT(tmp , 6, 8);
	if((tmp >= 0 && tmp < 3) || tmp == 7)
        A_B8_BIT3(gbf, unit_value, "Unit Value", 6, 8, gb_unit_value); 
	else
        A_B8_BIT2(gbf, unit_value, "Unit Value", 6, 8, "multiples of 1 minute"); 
    A_B8_BIT1(gbf, timer_value, "Timer Value", 1, 5); 
	SKIP(1);

    END_ELEMENT(); 
}

int omc_id(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("OMC Id", omc_id); 
	int len = 0;
	int ele_len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
		ele_len += 1;
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

	int i = 0;
	for(i = 0; i < len; i++)
	{
		int tmp = 0;
		char buf[50] = {0};
		B8_BIT(tmp, 1, 8);
		sprintf((char *)buf, "%x", tmp);
		B8_HEX(); 
		A_B8_BIT2(gbf, omc_identity, "OMC identity", 1, 8, buf);
		SKIP(1);
	}

    END_ELEMENT(); 
	return ele_len;
}

void trace_type(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Trace Type", trace_type); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	char buf[50] = {0};
	B8_BIT(tmp, 1, 8);
	sprintf((char *)buf, "%x", tmp);
	B8_HEX(); 
    A_B8_BIT2(gbf, trace_type_v, "Trace Type value", 1, 8, buf); 
	SKIP(1);

    END_ELEMENT(); 
}

int trigger_id(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Trigger Id", trigger_id); 
	int len = 0;
	int ele_len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
		ele_len += 1;
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            SKIP(1);
        }
	}

	int i = 0;
	for(i = 0; i < len; i++)
	{
		int tmp = 0;
		char buf[50] = {0};
		B8_BIT(tmp, 1, 8);
		sprintf((char *)buf, "%x", tmp);
		B8_HEX(); 
		A_B8_BIT2(gbf, entity_identity, "Entity Identity", 1, 8, buf);
		SKIP(1);
	}

    END_ELEMENT(); 
	return ele_len;
}

void transaction_id(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Transaction Id", transaction_id); 
	int len = 0;
    if(iei == 1)
    { 
		B8_HEX(); 
        A_B8_BIT2(gbf, iei, "IEI", 1, 8, "iei"); 
        SKIP(1); 
    } 

	if(location == 1)
	{
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
            SKIP(1);
        }
	}

	int tmp = 0;
	char buf[50] = {0};
	B16_BIT(tmp, 1, 16);
	sprintf((char *)buf, "%d", tmp);
	B8_HEX();
    A_B8_BIT2(gbf, transaction_id_v, "Transaction Id", 1, 8, "-"); 
	SKIP(1);

	B8_HEX();
    A_B8_BIT2(gbf, transaction_id_v, "Transaction Id", 1, 8, buf); 
	SKIP(1);

    END_ELEMENT(); 
}

int imsi(uint8_t iei, uint8_t location) 
{      
    BEGIN_ELEMENT("Mobile identity", mobile_identity);
	int ele_len = 0;
	if(iei == 1)
	{
		B8_HEX();
		A_B8_BIT2(gbf, mobile_identity_iei, "Mobile Identity IEI", 1, 8, "Mobile Identity");
		SKIP(1);
		ele_len += 1;
	}

	SKIP(1);
	int type = -1;
    B8_BIT(type, 1, 3);
    BACK(1);

    if (type == 5)
    {
        char mcc_buf[16*1024];
        char mnc_buf[16*1024];
        uint8_t mnc1;
        uint8_t mnc2;
        uint8_t mnc3;
        uint8_t mcc1;
        uint8_t mcc2;
        uint8_t mcc3;
        uint16_t mcc;
        uint16_t mnc;
        int tmp;

        uint8_t len;
        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += tmp + 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += tmp + 2;
            SKIP(1);
        }
        
        B8_HEX();
        A_B8_BIT1(gbf, spare ,"Spare", 7, 8);
        A_B8_BIT3(gbf, mbms_sessid_indic ,"MBMS Session Identity indication", 6, 6, mobile_identity_mbms_session_i_i);
        A_B8_BIT3(gbf, mcc_mnc_i ,"MCC/MNC indication", 6, 6, mobile_identity_mcc_mnc_i);
        A_B8_BIT3(gbf, odd_even_indic ,"odd/even indic", 4, 4, mobile_identity_odd_even_i);
        
		tmp = 0;
        B8_BIT(tmp, 1, 3);
        if(tmp >=0 && tmp <=5)
            A_B8_BIT3(gbf, Type_identity ,"Type of identity", 1, 3, mobile_identity_type_identity);
        else
            A_B8_BIT2(gbf, Type_identity ,"Type of identity", 1, 3, "reserved");
        SKIP(1);

        B8_HEX();
        SKIP(3);

        B8_BIT(mcc2, 5, 8);
        B8_BIT(mcc1, 1, 4);
        SKIP(1);
        B8_BIT(mnc3, 5, 8);
        B8_BIT(mcc3, 1, 4);
        SKIP(1);
        B8_BIT(mnc2, 5, 8);
        B8_BIT(mnc1, 1, 4);
        mcc = 100 * mcc1 + 10 * mcc2 + mcc3;
        sprintf(mcc_buf, "MCC = %d", mcc);
        mnc = 100 * mnc1 + 10 * mnc2 + mnc3;
        sprintf(mnc_buf, "MNC = %d", mnc);
        BACK(2);

        B8_HEX();
        A_B8_BIT2(gbf, mcc_digit2 ,"MCC digit 2", 5, 8, "-");
        A_B8_BIT2(gbf, mcc_digit1 ,"MCC digit 1", 1, 4, "-");
        SKIP(1);
        
        B8_HEX();
        A_B8_BIT2(gbf, mnc_digit3 ,"MNC digit 3", 5, 8, mnc_buf);
        A_B8_BIT2(gbf, mcc_digit3 ,"MCC digit 3", 1, 4, mcc_buf);
        SKIP(1);

        B8_HEX();
        A_B8_BIT2(gbf, mnc_digit2 ,"MNC digit 2", 5, 8, "-");
        A_B8_BIT2(gbf, mnc_digit1 ,"MNC digit 1", 1, 4, "-");
        SKIP(1);

        B8_HEX();
        A_B8_BIT1(gbf, mbms_session_i ,"MBMS Session Identity", 1, 8);
        SKIP(1);
    }
    else  
    {
        char buf[16*1024];
        memset(buf, 0x00, sizeof(buf));

        uint8_t len;
		uint8_t i;

        int flag = -1; 
        B8_BIT(flag, 8, 8);
        if(flag)
        {     
            B8_BIT(len, 1, 7);
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator", 8, 8, "Last Length Octet");
            A_B8_BIT1(gbf, ie_length, "IE Length", 1, 7);
		    ele_len += len + 1;
            len = len - 1;
            SKIP(1); 
        }     
        else  
        {     
            char buf[20] = {0};
            B16_BIT(len, 1, 15);  
            sprintf((char *)buf, "%d", len); 
            B8_HEX(); 
            A_B8_BIT2(gbf, length, "Length Indicator octets", 8, 8, "another Length Octet");
            A_B8_BIT1(gbf, ie_length_msb, "IE Length MSB", 1, 7);
            SKIP(1);
            B8_HEX(); 
            A_B8_BIT2(gbf, ie_length_lsb, "IE Length LSB", 1, 8, buf); 
		    ele_len += len + 2;
            len = len - 1;
            SKIP(1);
        }

        B8_HEX();
        A_B8_BIT2(gbf, identity_digit1 ,"Identity digit 1", 5, 8, "-");
        //sprintf(buf, "Identity = %x", MYVAR(gbf)->f);
        sprintf(buf, "%x", MYVAR(gbf)->f);
        A_B8_BIT3(gbf, odd_even_indic ,"odd/even indic", 4, 4, mobile_identity_odd_even_i);
        int tmp;
        B8_BIT(tmp, 1, 3);
        if(tmp >=0 && tmp <=5)
            A_B8_BIT3(gbf, Type_identity ,"Type of identity", 1, 3, mobile_identity_type_identity);
        else
            A_B8_BIT2(gbf, Type_identity ,"Type of identity", 1, 3, "reserved");
        SKIP(1);

        char name[128];
        char tmp_h[8];
        char tmp_l[8];

        for(i = 0; i < len - 1; i++)
        {

            memset(name, 0x00, sizeof(name));
            memset(tmp_h, 0x00, sizeof(tmp_h));
            memset(tmp_l, 0x00, sizeof(tmp_l));
            sprintf(name, "Identity digit %d", i * 2 + 3);
            B8_HEX();
            A_B8_BIT2(gbf, identity_digit, name, 5, 8, "-");
            sprintf(tmp_h, "%x", MYVAR(gbf)->f);

            memset(name, 0x00, sizeof(name));
            sprintf(name, "Identity digit %d", i * 2 + 2);
            A_B8_BIT2(gbf, identity_digit, name, 1, 4, "-");
            sprintf(tmp_l, "%x", MYVAR(gbf)->f);
            strcat(buf, tmp_l);
            strcat(buf, tmp_h);
            SKIP(1);
        }

        memset(name, 0x00, sizeof(name));
        memset(tmp_h, 0x00, sizeof(tmp_h));
        memset(tmp_l, 0x00, sizeof(tmp_l));
        sprintf(name, "Identity digit %d", i * 2 + 3);
        B8_HEX();
        A_B8_BIT2(gbf, identity_digit, name, 5, 8, "-");
        sprintf(tmp_h, "%x", MYVAR(gbf)->f);

        memset(name, 0x00, sizeof(name));
        sprintf(name, "Identity digit %d", i * 2 + 2);
        B8_BIT(type, 1, 4);
        sprintf(tmp_l, "%x", type);
        strcat(buf, tmp_l);
        strcat(buf, tmp_h);
        A_B8_BIT2(gbf, identity_digit, name, 1, 4, buf);
        SKIP(1);
    }
    END_ELEMENT();
	return ele_len;
}

int gmm_ms_radio_access_capability(uint8_t iei, uint8_t location)
{
	BEGIN_ELEMENT("MS Radio Access Capability", ms_radio_access_capability); 
	int ele_len = 0;
	int len = 0;
	if(iei == 1)
	{
		B8_HEX(); 
		A_B8_BIT1(gbf, iei, "IEI", 1, 8);
		ele_len += 1;
		SKIP(1); 
	}
	if(location == 1)
	{
        B8_BIT(len, 1, 8);
        B8_HEX(); 
        A_B8_BIT1(gbf, ie_length, "IE Length", 1, 8);
		ele_len += len + 1;
        SKIP(1); 
	}

    char buf[100] = {0};
    char *p = buf;
	int i;
	long long tmp = 0;
	int pos = 0;
	int tmp1 = 0;

    for(i = 0; i < len - 1; i++)
    {
        int tmp0 = 0;
        B8_BIT(tmp0, 1, 8);
        B8_HEX(); 
        A_B8_BIT2(gbf, ms_ra_capability_value, "MS RA capability value", 1, 8, "-"); 
        SKIP(1); 

        pos += sprintf(p + pos, "%02x", tmp0);
        //tmp += (tmp0 << 8*(len-1-i));
    }
    B8_BIT(tmp1, 1, 8);
    sprintf(p + pos, "%02x", tmp1);
    B8_HEX(); 
    A_B8_BIT2(gbf, ms_ra_capability_value, "MS RA capability value last", 1, 8, buf); 
    SKIP(1); 

    END_ELEMENT(); 
    return ele_len;
}
#endif
