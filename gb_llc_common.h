#ifndef __GB_LLC_COMMON_H__
#define __GB_LLC_COMMON_H__

#include "nbe_common.h"
#include "dict.h"

char _hex_buf[1024];
char _hex_desc_buf[1024];
char *_hex = NULL;
char *_hex_desc = NULL;

void address_field()
{
	BEGIN_ELEMENT("Address Field", address_field); 
	B8_HEX(); 
	A_B8_BIT1(gbf, pd, "Protocol Discriminator bit (PD)", 8, 8); 
	int tmp = 0;
	B8_BIT(tmp, 7, 7);
	if(MYVAR(dir) == 0)
	{
		if(tmp == 0)
			A_B8_BIT2(gbf, cr, "Command/Response bit (C/R)", 7, 7, "Response"); 
		else
			A_B8_BIT2(gbf, cr, "Command/Response bit (C/R)", 7, 7, "Command"); 
	}
	if(MYVAR(dir) == 1)  
	{
		if(tmp == 0)
			A_B8_BIT2(gbf, cr, "Command/Response bit (C/R)", 7, 7, "Command"); 
		else
			A_B8_BIT2(gbf, cr, "Command/Response bit (C/R)", 7, 7, "Response"); 
	}
	A_B8_BIT1(gbf, spare, "Spare", 5, 6); 
	B8_BIT(tmp, 1, 4);
	A_B8_BIT3(gbf, sapi, "Service Access Point Identifier (SAPI)", 1, 4, gb_sapi); 
	SKIP(1); 
	END_ELEMENT(); 
}

int control_field(uint32_t len)
{
	BEGIN_ELEMENT("Control Field", control_field);
	B8_HEX();
	int ele_len = 0;
	int tmp = -1;
	char buf[50] = {0};
	int i_flag = -1;
	int sack_flag = -1;
	int s_flag = -1;
	int u_flag = -1;
	B8_BIT(i_flag, 8, 8);
	if(i_flag == 0)   //I format
	{
		SET_STR(gb, frame_type, "I Frame");
		SET_STR(gb, signal_name, "");
		SKIP(2);
		B8_BIT(sack_flag, 1, 2);
		BACK(2);
		if(sack_flag == 3)
			A_B8_BIT2(gbf, format_indicator, "Format Indicator", 8, 8, "I frame SACK format"); 
		else
			A_B8_BIT2(gbf, format_indicator, "Format Indicator", 8, 8, "I frame format"); 
		B8_BIT(tmp, 7, 7);
		if(tmp == 0)
			A_B8_BIT2(gbf, a, "Acknowledgement request bit", 7, 7, "not requested to send an acknowledgement"); 
		else
			A_B8_BIT2(gbf, a, "Acknowledgement request bit", 7, 7, "solicit an acknowledgement"); 
		A_B8_BIT1(gbf, spare, "Spare", 6, 6); 
		A_B8_BIT2(gbf, ns, "N(S)", 1, 5, "-"); 
		B16_BIT(tmp, 5, 13);
		sprintf((char *)buf, "%d", tmp);
		ele_len += 1;
		SKIP(1);

		B8_HEX();
		A_B8_BIT2(gbf, ns, "N(S)", 5, 8, buf); 
		A_B8_BIT1(gbf, spare, "Spare", 4, 4); 
		A_B8_BIT2(gbf, nu, "N(R)", 1, 3, "-"); 
		B16_BIT(tmp, 3, 11);
		memset((char *)buf, 0x00, sizeof(buf));
		sprintf((char *)buf, "%d", tmp);
		ele_len += 1;
		SKIP(1);

		B8_HEX();
		A_B8_BIT2(gbf, nu, "N(U)", 3, 8, buf); 
		A_B8_BIT3(gbf, s1_2, "s1-s2", 1, 2, gb_s1_s2); 
		ele_len += 1;
		SKIP(1);

		if(sack_flag == 3)
		{
			B8_HEX();
			A_B8_BIT1(gbf, spare, "Spare", 6, 8); 
			B8_BIT(tmp, 1, 5);
			A_B8_BIT2(gbf, k, "K", 1, 5, "Bitmap Length Indicator"); 

			int i = 0;
			for(i = 0; i < tmp; i++)
			{
				B8_HEX();
				A_B8_BIT2(gbf, Rn, "R(n)", 1, 8, "Bitmap bit"); 
				ele_len += 1;
				SKIP(1);
			}
		}
	}
	else
	{
		B8_BIT(s_flag, 7, 8);
		if(s_flag == 2)   //S format
		{
			SET_STR(gb, frame_type, "S Frame");
			SKIP(1);
			B8_BIT(sack_flag, 1, 2);
			BACK(1);
			if(sack_flag == 3)
				A_B8_BIT2(gbf, format_indicator, "Format Indicator", 7, 8, "S frame SACK format"); 
			else 
			{
				A_B8_BIT2(gbf, format_indicator, "Format Indicator", 7, 8, "S frame format"); 
				if(sack_flag == 0)
					SET_STR(gb, signal_name, "RR");
				else if(sack_flag == 1)
					SET_STR(gb, signal_name, "ACK");
				else if(sack_flag == 2)
					SET_STR(gb, signal_name, "RNR");
				else
					SET_STR(gb, signal_name, "SACK");
			}
			B8_BIT(tmp, 6, 6);
			if(tmp == 0)
				A_B8_BIT2(gbf, a, "Acknowledgement request bit", 7, 7, "not requested to send an acknowledgement"); 
			else
			{
				A_B8_BIT2(gbf, a, "Acknowledgement request bit", 7, 7, "solicit an acknowledgement"); 
				SET_STR(gb, signal_name, "ACK");
			}
			A_B8_BIT1(gbf, spare, "Spare", 4, 5); 
			A_B8_BIT2(gbf, ns, "N(R)", 1, 3, "-"); 
			B16_BIT(tmp, 3, 11);
			sprintf((char *)buf, "%d", tmp);
			ele_len += 1;
			SKIP(1);

			B8_HEX();
			A_B8_BIT2(gbf, ns, "N(R)", 3, 8, buf); 
			A_B8_BIT3(gbf, s1_2, "s1-s2", 1, 2, gb_s1_s2); 
			ele_len += 1;
			SKIP(1);

			if(sack_flag == 3)
			{
				int i = 0;
				for(i = 0; i < len - 2; i++)
				{
					B8_HEX();
					A_B8_BIT2(gbf, Rn, "R(n)", 1, 8, "Bitmap bit"); 
					ele_len += 1;
					SKIP(1);
				}
			}

		}
		else
		{
			B8_BIT(u_flag, 6, 8);
			if(u_flag == 7)   //U format
			{
				SET_STR(gb, frame_type, "U Frame");
				A_B8_BIT2(gbf, format_indicator, "Format Indicator", 6, 8, "U format"); 
				A_B8_BIT3(gbf, p_f, "Final bit", 5, 5, p_dict);
				B8_BIT(tmp, 1, 4);
				if(tmp == 1)
				{
					SET_STR(gb, signal_name, "DM");
				    A_B8_BIT2(gbf, m, "m1-m4", 1, 4, "DM");
				    ele_len += 1;
				    SKIP(1);
				}
				else if(tmp == 4)
				{
					SET_STR(gb, signal_name, "DISC");
				    A_B8_BIT2(gbf, m, "m1-m4", 1, 4, "DISC");
				    ele_len += 1;
				    SKIP(1);
				}
				else if(tmp == 6)
				{
					SET_STR(gb, signal_name, "UA");
				    A_B8_BIT2(gbf, m, "m1-m4", 1, 4, "UA");
				    ele_len += 1;
				    SKIP(1);
				}
				else if(tmp == 7)
				{
					SET_STR(gb, signal_name, "SABM");
				    A_B8_BIT2(gbf, m, "m1-m4", 1, 4, "SABM");
				    ele_len += 1;
				    SKIP(1);
				}
				else if(tmp == 8)
				{
					SET_STR(gb, signal_name, "FRMR");
				    A_B8_BIT2(gbf, m, "m1-m4", 1, 4, "FRMR");
				    ele_len += 1;
				    SKIP(1);
				}
				else if(tmp == 11)
				{
					SET_STR(gb, signal_name, "XID");
				    A_B8_BIT2(gbf, m, "m1-m4", 1, 4, "XID");
                    ele_len += 1;
                    SKIP(1);
				}
				else
                {
					SET_STR(gb, signal_name, "Unknown");
				    A_B8_BIT1(gbf, m, "m1-m4", 1, 4);
				    ele_len += 1;
				    SKIP(1);
                }
			}
			else   //UI format
			{
				SET_STR(gb, frame_type, "UI Frame");
				SET_STR(gb, signal_name, "");
				A_B8_BIT2(gbf, format_indicator, "Format Indicator", 6, 8, "UI format"); 
				A_B8_BIT1(gbf, spare, "Spare", 4, 5); 
				A_B8_BIT2(gbf, nu, "N(U)", 1, 3, "-"); 
				B16_BIT(tmp, 3, 11);
				sprintf((char *)buf, "%d", tmp);
				ele_len += 1;
				SKIP(1);

				B8_HEX();
				A_B8_BIT2(gbf, nu, "N(U)", 3, 8, buf); 
				B8_BIT(tmp, 2, 2);
				if(tmp == 0)
				{
					B8_BIT(tmp, 1, 1);
					if(tmp == 0)
					{
						A_B8_BIT2(gbf, e, "Encryption mode bit", 2, 2, "non-ciphered information"); 
						A_B8_BIT2(gbf, pm, "Protected Mode bit", 1, 1, "unprotected"); 
						ele_len += 1;
						SKIP(1);
					}
					else
					{
						A_B8_BIT2(gbf, e, "Encryption mode bit", 2, 2, "ciphered information"); 
						A_B8_BIT2(gbf, pm, "Protected Mode bit", 1, 1, "unprotected"); 
						ele_len += 1;
						SKIP(1);
					}
				}
				else
				{
					B8_BIT(tmp, 1, 1);
					if(tmp == 0)
					{
						A_B8_BIT2(gbf, e, "Encryption mode bit", 2, 2, "non-ciphered information"); 
						A_B8_BIT2(gbf, pm, "Protected Mode bit", 1, 1, "protected"); 
						ele_len += 1;
						SKIP(1);
					}
					else
					{
						A_B8_BIT2(gbf, e, "Encryption mode bit", 2, 2, "ciphered information"); 
						A_B8_BIT2(gbf, pm, "Protected Mode bit", 1, 1, "protected"); 
						ele_len += 1;
						SKIP(1);
					}
				}
			}
			
		}
	}
	END_ELEMENT(); 
	return ele_len;
}

void fcs_field()
{
	BEGIN_ELEMENT("Fcs Field", fcs_field);
    int tmp = 0;
    char buf[10] = {0};

	B8_HEX();
    B8_BIT(tmp, 1, 8);
    sprintf((char *)buf, "%02x", tmp);
	A_B8_BIT2(gbf, fcs1, "FCS short 1", 1, 8, buf); 
    SKIP(1);

    memset((char *)buf, 0x00, sizeof(buf));
	B8_HEX();
    B8_BIT(tmp, 1, 8);
    sprintf((char *)buf, "%02x", tmp);
	A_B8_BIT2(gbf, fcs2, "FCS short 2", 1, 8, buf); 
    SKIP(1);

    memset((char *)buf, 0x00, sizeof(buf));
	B8_HEX();
    B8_BIT(tmp, 1, 8);
    sprintf((char *)buf, "%02x", tmp);
	A_B8_BIT2(gbf, fcs3, "FCS short 3", 1, 8, buf); 
    SKIP(1);

	END_ELEMENT(); 
}

void frmr_frame_field()
{
	BEGIN_ELEMENT("FRMR Frame Field", frmr_field);

    int i = 6;
    while(i--)
    {
        B8_HEX();
	    A_B8_BIT1(gbf, rejected_frame_control_field, "Rejected frame control field", 1, 8);
        SKIP(1);
    }
    int tmp = 0;
    B16_BIT(tmp, 4, 12);
    B8_HEX();
	A_B8_BIT1(gbf, spare, "Spare", 5, 8);
	A_B8_BIT2(gbf, vs, "V(S)", 1, 4, "-");
    SKIP(1);

    char buf[10] = {0};
    sprintf((char *)buf, "%d", tmp);
    B16_BIT(tmp, 1, 10);
    B8_HEX();
	A_B8_BIT2(gbf, vs, "V(S)", 4, 8, buf);
	A_B8_BIT1(gbf, spare, "Spare", 3, 3);
	A_B8_BIT2(gbf, vr, "V(R)", 1, 2, "-");
    SKIP(1);

    memset((char *)buf, 0x00, sizeof(buf));
    sprintf((char *)buf, "%d", tmp);
    B8_BIT(tmp, 1, 1);
    B8_HEX();
	A_B8_BIT2(gbf, vr, "V(R)", 2, 8, buf);
    if(tmp)
	    A_B8_BIT2(gbf, cr, "C/R", 1, 1, "response");
    else
	    A_B8_BIT2(gbf, cr, "C/R", 1, 1, "command");
    SKIP(1);

    B8_HEX();
	A_B8_BIT1(gbf, spare, "Spare", 5, 8);
	A_B8_BIT1(gbf, w4, "W4", 4, 4);
	A_B8_BIT1(gbf, w3, "W3", 3, 3);
	A_B8_BIT1(gbf, w2, "W2", 2, 2);
	A_B8_BIT1(gbf, w1, "W1", 1, 1);

	END_ELEMENT(); 
}


int xid_parameter_field(uint32_t len)
{
	BEGIN_ELEMENT("XID Parameter Field", xid_field);
    int ele_len = 0;

    while(len)
    {
        int xl_v = -1;
        int xid_len = 0;
        int type_v = 0;
        B8_BIT(xl_v, 8, 8);
        B8_HEX();
        if(!xl_v)
        {
            B8_BIT(xid_len, 1, 2);
            B8_BIT(type_v, 3, 7);
	        A_B8_BIT2(gbf, xl, "XID Length", 8, 8, "2 bits Length");
            if(type_v >= 0 || type_v < 13)
	            A_B8_BIT3(gbf, type, "Type", 3, 7, gb_llc_xid_type);
            else
	            A_B8_BIT2(gbf, type, "Type", 3, 7, "reserved");
	        A_B8_BIT1(gbf, length, "Length", 1, 2);
	        ele_len += 1;
            len -= 1;
            SKIP(1);

	        ele_len += xid_len;
            len -= xid_len;
            SKIP(xid_len);
        }
        else
        {
            B16_BIT(xid_len, 3, 10);
            B8_BIT(type_v, 3, 7);
	        A_B8_BIT2(gbf, xl, "XID Length", 8, 8, "8 bits Length");
            if(type_v >= 0 || type_v < 13)
	            A_B8_BIT3(gbf, type, "Type", 3, 7, gb_llc_xid_type);
            else
	            A_B8_BIT2(gbf, type, "Type", 3, 7, "reserved");
	        A_B8_BIT2(gbf, length, "Length", 1, 2, "-");
	        ele_len += 1;
            len -= 1;
            SKIP(1);

            char buf_t[10] = {0};
            sprintf((char *)buf_t, "%d", xid_len);
            B8_HEX();
	        A_B8_BIT2(gbf, length, "Length", 3, 8, buf_t);
	        A_B8_BIT1(gbf, xx, "XX", 1, 2);
	        ele_len += 1;
            len -= xid_len;
            SKIP(1);

	        ele_len += xid_len;
            SKIP(xid_len);
        }
    }

	END_ELEMENT(); 
    return ele_len;
}
#endif
