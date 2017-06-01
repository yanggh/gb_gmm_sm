#ifndef __GMM_SM_H__
#define __GMM_SM_H__

#include "nbe_common.h"
#include "gmm_sm_dict.h"
/*************************************************/
void ms_network_capability(uint8_t iei, uint8_t location)
{    
    BEGIN_ELEMENT("MS network capability", ms_network_capability); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, ms_network_capability_iei, "MS network capability IEI", 1, 8, "MS network capability"); 
        SKIP(1); 
    }    

    
    int len = -1;
    if(location == 1)
    {	
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, ms_network_capability_length, "Length of MS network capability contents", 1, 8);
	    //len -= 1;
	    SKIP(1);
    }
#if 1
    int  tmp = -1;
    if(len > 0)
    {
	    B8_HEX();
        B8_BIT(tmp, 8, 8);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea1, "GEA1 bits", 8, 8, "GEA/1 not available");
        else
            A_B8_BIT2(gbf, gea1, "GEA1 bits", 8, 8, "GEA/1 available");
        B8_BIT(tmp, 7, 7);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, sm_capabilities_via_dedicated_channels, "SM capabilities via dedicated channels", 7, 7, "Mobile station does not support mobile terminated point to point SMS via CS domain");
        }
        else
        {
            A_B8_BIT2(gbf, sm_capabilities_via_dedicated_channels, "SM capabilities via dedicated channels", 7, 7, "Mobile station supports mobile terminated point to point SMS via CS domain");
        }

        B8_BIT(tmp, 6, 6);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, sm_capabilities_via_gprs_channels, "SM capabilities via GPRS channels", 6, 6, "Mobile station does not support mobile terminated point to point SMS via PS domain");
        }
        else
        {
            A_B8_BIT2(gbf, sm_capabilities_via_gprs_channels, "SM capabilities via GPRS channels", 6, 6, "Mobile station supports mobile terminated point to point SMS via PS domain");            
        }
        B8_BIT(tmp, 5, 5);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, ucs2_support, "UCS2 support", 5, 5, "the ME has a preference for the default alphabet (defined in 3GPP TS 23.038 [8b]) over UCS2.");
        }
        else
        {
            A_B8_BIT2(gbf, ucs2_support, "UCS2 support", 5, 5, "the ME has no preference between the use of the default alphabet and the use of UCS2.");
        }
        A_B8_BIT2(gbf, ss_screening_indicator, "SS Screening Indicator", 3, 4, "defined in 3GPP TS 24.080 [24]");
        B8_BIT(tmp, 2, 2);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, solsa_capbility, "SoLSA Capability", 2, 2, "The ME does not support SoLSA.");
        }
        else
        {
            A_B8_BIT2(gbf, solsa_capbility, "SoLSA Capability", 2, 2, "The ME supports SoLSA.");
        }

        B8_BIT(tmp, 1, 1);
        if(tmp ==  0)
        {
            A_B8_BIT2(gbf, revision_level_indicator, "Revision level indicator", 1, 1, "used by a mobile station not supporting R99 or later versions of the protocol");
        }
        else
        {
            A_B8_BIT2(gbf, revision_level_indicator, "Revision level indicator", 1, 1, "used by a mobile station supporting R99 or later versions of the protocol");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
	    B8_HEX();
        B8_BIT(tmp, 8, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, rfc_feature_mode, "PFC feature mode", 8, 8, "Mobile station does not support BSS packet flow procedures");
        }
        else
        {
            A_B8_BIT2(gbf, rfc_feature_mode, "PFC feature mode", 8, 8, "Mobile station does support BSS packet flow procedures");
        }
        
        B8_BIT(tmp, 7, 7);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea2, "GEA2 bits", 7, 7, "encryption algorithm GEA/2 not available");
        else
            A_B8_BIT2(gbf, gea2, "GEA2 bits", 7, 7, "encryption algorithm GEA/2 available");
        B8_BIT(tmp, 6, 6);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea3, "GEA3 bits", 6, 6, "encryption algorithm GEA/3 not available");
        else
            A_B8_BIT2(gbf, gea3, "GEA3 bits", 6, 6, "encryption algorithm GEA/3 available");
        B8_BIT(tmp, 5, 5);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea4, "GEA4 bits", 5, 5, "encryption algorithm GEA/4 not available");
        else
            A_B8_BIT2(gbf, gea4, "GEA4 bits", 5, 5, "encryption algorithm GEA/4 available");
        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea5, "GEA5 bits", 4, 4, "encryption algorithm GEA/5 not available");
        else
            A_B8_BIT2(gbf, gea5, "GEA5 bits", 4, 4, "encryption algorithm GEA/5 available");
        B8_BIT(tmp, 3, 3);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea6, "GEA6 bits", 3, 3, "encryption algorithm GEA/6 not available");
        else
            A_B8_BIT2(gbf, gea6, "GEA6 bits", 3, 3, "encryption algorithm GEA/6 available");
        B8_BIT(tmp, 2, 2);
        if(tmp == 0)
            A_B8_BIT2(gbf, gea7, "GEA7 bits", 2, 2, "encryption algorithm GEA/7 not available");
        else
            A_B8_BIT2(gbf, gea7, "GEA7 bits", 2, 2, "encryption algorithm GEA/7 available");

        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, lcs_va_capability, "LCS VA capability", 1, 1, "location request notification via PS domain not supported");    
        }
        else
        {
            A_B8_BIT2(gbf, lcs_va_capability, "LCS VA capability", 1, 1, "location request notification via PS domain supported");
        }
        
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
	    B8_HEX();
        B8_BIT(tmp, 8, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, ps_inter_ho_from_grean_to_utran_iu_mode_cap, "PS inter-RAT HO from GERAN to UTRAN Iu mode capability", 8, 8, "PS inter-RAT HO from GERAN to UTRAN Iu mode not supported");
        }
        else
        {
            A_B8_BIT2(gbf, ps_inter_ho_from_grean_to_utran_iu_mode_cap, "PS inter-RAT HO from GERAN to UTRAN Iu mode capability", 8, 8, "PS inter-RAT HO from GERAN to UTRAN Iu mode supported");
        }
        
        B8_BIT(tmp, 7, 7);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, ps_inter_ho_from_grean_to_eutran_s1_mode_cap, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode capability", 7, 7, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode not supported");
        }
        else
        {
            A_B8_BIT2(gbf, ps_inter_ho_from_grean_to_eutran_s1_mode_cap, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode capability", 7, 7, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode supported");            
        }

        B8_BIT(tmp, 6, 6);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, emm_combined_procedures_capability, "EMM Combined procedures capability", 6, 6, "Mobile station does not support EMM combined procedures");
        }
        else
        {
            A_B8_BIT2(gbf, emm_combined_procedures_capability, "EMM Combined procedures capability", 6, 6, "Mobile station supports EMM combined procedures");
        }
        
        B8_BIT(tmp, 5, 5);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, isr_support, "ISR support", 5, 5, "The mobile station does not support ISR");
        }
        else
        {
            A_B8_BIT2(gbf, isr_support, "ISR support", 5, 5, "The mobile station supports ISR");
        }
        
        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, srvcc_to_geran_utran_capability, "SRVCC to GERAN/UTRAN capability", 4, 4, "SRVCC from UTRAN HSPA or E-UTRAN to GERAN/UTRAN not supported");
        }
        else
        {
            A_B8_BIT2(gbf, srvcc_to_geran_utran_capability, "SRVCC to GERAN/UTRAN capability", 4, 4, "SRVCC from UTRAN HSPA or E-UTRAN to GERAN/UTRAN supported");   
        }

        B8_BIT(tmp, 3, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, epc_capability, "EPC capability", 3, 3, "EPC not supported");
        }
        else
        {
            A_B8_BIT2(gbf, epc_capability, "EPC capability", 3, 3, "EPC supported");
        }

        B8_BIT(tmp, 2, 2);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, nf_capability, "NF capability", 2, 2, "Mobile station does not support the notification procedure");
        }
        else
        {
            A_B8_BIT2(gbf, nf_capability, "NF capability", 2, 2, "Mobile station supports the notification procedure");
        }

        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, geran_network_sharing_capability, "GERAN network sharing capability", 1, 1, "Mobile station does not support GERAN network sharing");    
        }
        else
        {
            A_B8_BIT2(gbf, geran_network_sharing_capability, "GERAN network sharing capability", 1, 1, "Mobile station supports GERAN network sharing");                
        }
        
        len -= 1;
        SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "Spare", 1, 8);
        len -= 1;
        SKIP(1);
    }
#endif
    END_ELEMENT(); 
}

void attach_type(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Attach type", attach_type); 
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, follow_on_request , "Follow-on request ", 4, 4, "No follow-on request pending");    
            }
            else
            {
                A_B8_BIT2(gbf, follow_on_request , "Follow-on request ", 4, 4, "Follow-on request pending");
            }
            
            A_B8_BIT3(gbf, type_of_attach , "Type of attach",  1, 3, attach_type_type_of_attach);
            SKIP(1); 
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, follow_on_request , "Follow-on request ", 8, 8, "No follow-on request pending");                
            }
            else
            {
                A_B8_BIT2(gbf, follow_on_request , "Follow-on request ", 8, 8, "Follow-on request pending");                
            }
            
            A_B8_BIT3(gbf, type_of_attach , "Type of attach",  5, 7, attach_type_type_of_attach);
        }
    }
    else
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, attach_type_iei, "Attach type IEI", 5, 8, "Attach type"); 
        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, follow_on_request , "Follow-on request ", 4, 4, "No follow-on request pending");    
        }
        else
        {
            A_B8_BIT2(gbf, follow_on_request , "Follow-on request ", 4, 4, "Follow-on request pending");
        }
        
        B8_BIT(tmp, 1, 3);
        if(tmp > 0 && tmp < 5)
            A_B8_BIT3(gbf, type_of_attach , "Type of attach",  1, 3, attach_type_type_of_attach);
        else
            A_B8_BIT2(gbf, type_of_attach , "Type of attach",  1, 3, "GPRS attach");
        SKIP(1); 
    }    
    END_ELEMENT(); 
}

void drx_paramete(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("DRX paramete", drx_paramete); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, drx_paramete_iei, "DRX parameter IEI", 1, 8, "DRX parameter");  
        SKIP(1); 
    }       

    B8_HEX();
    int  code = -1;
    B8_BIT(code, 1, 8);
    if(code == 0)
    {
        A_B8_BIT2(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "704 (equivalent to no DRX)");
    }
    else if(code >= 1 && code <= 64)
    {
        A_B8_BIT1(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8);
    }
    else if(code >= 65 && code <= 98)
    {
        A_B8_BIT3(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, drx_paramete_split_pg_cycle_code);
    }
    else 
    {
        A_B8_BIT2(gbf, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "reserved");
    }
    SKIP(1);

    int tmp = -1;
    B8_HEX();
    B8_BIT(tmp, 5, 8);
    if(tmp == 0 || tmp == 6 || tmp == 7 || tmp == 8 || tmp == 9)
    {
        A_B8_BIT3(gbf, cn_drx_cycle_len_drx , "CN Specific DRX cycle length coefficient and DRX value for S1 mode",  5, 8, drx_paramete_cn_drx_cycle_len_drx);
    }
    else
    {
        A_B8_BIT2(gbf, cn_drx_cycle_len_drx , "CN Specific DRX cycle length coefficient and DRX value for S1 mode",  5, 8, "CN Specific DRX cycle length coefficient not specified by the MS, DRX value not specified by the MS by this version of the protocol.");
    }

    B8_BIT(tmp, 4, 4);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, split_on_ccch , "SPLIT on CCCH", 4, 4, "Split pg cycle on CCCH is not supported by the mobile station");
    }
    else
    {
        A_B8_BIT2(gbf, split_on_ccch , "SPLIT on CCCH", 4, 4, "Split pg cycle on CCCH is supported by the mobile station");
    }

    A_B8_BIT3(gbf, non_drx_timer , "non-DRX timer", 1, 3, drx_paramete_non_drx_timer);
    SKIP(1); 

    END_ELEMENT(); 
}

void p_tmsi_signature(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("P-TMSI signature", p_tmsi_signature);
        if(iei==1)
        {
            B8_HEX();
            A_B8_BIT2(gbf, p_tmsi_signature_iei, "P-TMSI signature IEI", 1, 8, "P-TMSI signature");
            SKIP(1);
        }
     
        int sum = -1;
        int tmp = -1;
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        sum = tmp;
        A_B8_BIT2(gbf, p_tmsi_signature_value, "P-TMSI signature value", 1, 8, "-");
        SKIP(1);

        B8_HEX();
        B8_BIT(tmp, 1, 8);
        sum = sum * 255 + tmp;
        A_B8_BIT2(gbf, p_tmsi_signature_value, "P-TMSI signature value", 1, 8, "-");
        SKIP(1);

        char buf[100];
        memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "%d", sum);
    	B8_HEX();
        A_B8_BIT2(gbf, p_tmsi_signature_value, "P-TMSI signature value", 1, 8, buf);
        SKIP(1);

        END_ELEMENT();
}

void tmsi_status(uint8_t iei, uint8_t location) 
{    
    int tmp = -1;
    BEGIN_ELEMENT("TMSI status", tmsi_status); 
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, tmsi_status_spare, "spare", 2, 4);
            B8_BIT(tmp, 1, 1);
            if(tmp == 0)
            {
                A_B8_BIT1(gbf, tmsi_status_spare, "no valid TMSI available", 1, 1);
            }
            else
            {
                A_B8_BIT1(gbf, tmsi_status_spare, "valid TMSI available", 1, 1);
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, tmsi_status_spare, "spare", 6, 8);
            B8_BIT(tmp, 5, 5);
            if(tmp == 0)
            {
                A_B8_BIT1(gbf, tmsi_status_spare, "no valid TMSI available", 5, 5);
            }
            else
            {
                A_B8_BIT1(gbf, tmsi_status_spare, "valid TMSI available", 5, 5);
            }
        }
    }
    else
    {    
        B8_HEX();
        A_B8_BIT2(gbf, tmsi_status_iei, "TMSI status IEI",  5, 8, "TMSI status");
        A_B8_BIT1(gbf, tmsi_status_spare, "spare", 2, 4);
        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT1(gbf, tmsi_status_spare, "no valid TMSI available", 1, 1);
        }
        else
        {
            A_B8_BIT1(gbf, tmsi_status_spare, "valid TMSI available", 1, 1);
        }
        SKIP(1);
    }

    END_ELEMENT();
}

void ps_lcs_capability(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("PS LCS Capability", ps_lcs_Capability); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, ps_lcs_capability_iei, "PS LCS Capability IEI", 1, 8, "PS LCS Capability");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    if(len > 0)
	    {
		    A_B8_BIT1(gbf, ps_lcs_capability_length, "Length of PS LCS Capability contents", 1, 8);
		    SKIP(1);
	    }
    }

    B8_HEX();
    A_B8_BIT1(gbf, spare, "Spare", 7, 8);

    int i = 0, tmp = -1;
    for(i = 6; i > 0; i--)
    {
        B8_BIT(tmp, 6, 6);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, capability_o, apc_otd_gps[6], 6, 6, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(gbf, capability_i, apc_otd_gps[6], 6, 6, ps_lcs_capability_i);
        }

        B8_BIT(tmp, 5, 5);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, capability_o, apc_otd_gps[5], 5, 5, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(gbf, capability_i, apc_otd_gps[5], 5, 5, ps_lcs_capability_i);
        }

        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, capability_o, apc_otd_gps[4], 4, 4, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(gbf, capability_i, apc_otd_gps[4], 4, 4, ps_lcs_capability_i);
        }

        B8_BIT(tmp, 3, 3);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, capability_o, apc_otd_gps[3], 3, 3, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(gbf, capability_i, apc_otd_gps[3], 3, 3, ps_lcs_capability_i);
        }

        B8_BIT(tmp, 2, 2);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, capability_o, apc_otd_gps[2], 2, 2, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(gbf, capability_i, apc_otd_gps[2], 2, 2, ps_lcs_capability_i);
        }

        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT3(gbf, capability_o, apc_otd_gps[1], 1, 1, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(gbf, capability_i, apc_otd_gps[1], 1, 1, ps_lcs_capability_i);
        }
    }    
    SKIP(1);

    END_ELEMENT();
}

void mobile_station_classmark_3(uint8_t iei, uint8_t location)
{
    int len = -1;
    BEGIN_ELEMENT("Mobile station classmark 3", mobile_station_classmark_3);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, mobile_station_classmark_3_iei, "Mobile station classmark 3 IEI", 1, 8, "Mobile station classmark 3");
        SKIP(1);
    }

    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, len_mobile_station_classmark_3, "Length of Mobile station classmark 3", 1, 8);
	    SKIP(1);
    }

    if(len > 0)
    SKIP(len);
    END_ELEMENT();
}

void  ue_network_capability(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("UE network capability", ue_network_capability);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, ue_network_capability_iei, "UE network capability", 1, 8, "UE network capability IEI");
        SKIP(1);
    }
 
    int len = -1;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_ue_network_capability, "Length of UE network capability contents", 1, 8);
	    SKIP(1);
    }

    B8_HEX();
    if(len > 0)
    {
        A_B8_BIT3(gbf, eea0, "EEA0", 1, 1, ue_network_capability_eea1);
        A_B8_BIT3(gbf, eea1, "128-EEA1", 2, 2, ue_network_capability_eea2);
        A_B8_BIT3(gbf, eea2, "128-EEA2", 3, 3, ue_network_capability_eea3);
        A_B8_BIT3(gbf, eea3, "128-EEA3", 4, 4, ue_network_capability_eea4);
        A_B8_BIT3(gbf, eea4, "EEA4", 5, 5, ue_network_capability_eea5);
        A_B8_BIT3(gbf, eea5, "EEA5", 6, 6, ue_network_capability_eea6);
        A_B8_BIT3(gbf, eea6, "EEA6", 7, 7, ue_network_capability_eea7);
        A_B8_BIT3(gbf, eea7, "EEA7", 8, 8, ue_network_capability_eea8);
        len -= 1;   
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(gbf, eia1, "EIA0", 1, 1, ue_network_capability_eia1);
        A_B8_BIT3(gbf, 128_eia2, "128-EIA1", 2, 2, ue_network_capability_eia2);
        A_B8_BIT3(gbf, 128_eia3, "128-EIA2", 3, 3, ue_network_capability_eia3);
        A_B8_BIT3(gbf, 128_eia4, "128-EIA3", 4, 4, ue_network_capability_eia4);
        A_B8_BIT3(gbf, eia5, "EIA4", 5, 5, ue_network_capability_eia5);
        A_B8_BIT3(gbf, eia6, "EIA5", 6, 6, ue_network_capability_eia6);
        A_B8_BIT3(gbf, eia7, "EIA6", 7, 7, ue_network_capability_eia7);
        A_B8_BIT3(gbf, eia8, "EIA7", 8, 8, ue_network_capability_eia8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(gbf, uea1, "UEA0", 1, 1, ue_network_capability_uea1);
        A_B8_BIT3(gbf, uea2, "UEA1", 2, 2, ue_network_capability_uea2);
        A_B8_BIT3(gbf, uea3, "UEA2", 3, 3, ue_network_capability_uea3);
        A_B8_BIT3(gbf, uea4, "UEA3", 4, 4, ue_network_capability_uea4);
        A_B8_BIT3(gbf, uea5, "UEA4", 5, 5, ue_network_capability_uea5);
        A_B8_BIT3(gbf, uea6, "UEA5", 6, 6, ue_network_capability_uea6);
        A_B8_BIT3(gbf, uea7, "UEA6", 7, 7, ue_network_capability_uea7);
        A_B8_BIT3(gbf, uea8, "UEA7", 8, 8, ue_network_capability_uea8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(gbf, ucs2, "UCS2", 1, 1, ue_network_capability_ucs2);
        A_B8_BIT3(gbf, uia1, "UIA1", 2, 2, ue_network_capability_uia1);
        A_B8_BIT3(gbf, uia2, "UIA2", 3, 3, ue_network_capability_uia2);
        A_B8_BIT3(gbf, uia3, "UIA3", 4, 4, ue_network_capability_uia3);
        A_B8_BIT3(gbf, uia4, "UIA4", 5, 5, ue_network_capability_uia4);
        A_B8_BIT3(gbf, uia5, "UIA5", 6, 6, ue_network_capability_uia5);
        A_B8_BIT3(gbf, uia6, "UIA6", 7, 7, ue_network_capability_uia6);
        A_B8_BIT3(gbf, uia7, "UIA7", 8, 8, ue_network_capability_uia7);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(gbf, prosedd, "Prosedd", 1, 1, ue_network_capability_prosedd);
        A_B8_BIT3(gbf, prose, "ProSe", 2, 2, ue_network_capability_prose);
        A_B8_BIT3(gbf, h245_ash, "H.245-ASH", 3, 3, ue_network_capability_ash);
        A_B8_BIT3(gbf, acc_csfb, "ACC-CSFB", 4, 4, ue_network_capability_scfb);
        A_B8_BIT3(gbf, lpp, "LPP", 5, 5, ue_network_capability_lpp);
        A_B8_BIT3(gbf, lcs, "LCS", 6, 6, ue_network_capability_lcs);
        A_B8_BIT3(gbf, 1xsrvcc, "1xSRVCC", 7, 7, ue_network_capability_1xsrvcc);
        A_B8_BIT3(gbf, nf, "NF", 8, 8, ue_network_capability_nf);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 1, 7);
        A_B8_BIT3(gbf, spare, "ProSe-dc", 8, 8, ue_network_capability_prose_dc);
        len -= 1;
        SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT2(gbf, spare, "Spare", 1, 8, "Spare");
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void voice_domain_preference_and_ue_usage_setting(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Voice domain preference and UE's usage setting", voice_domain_preference_and_ue_usage_setting); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, voice_domain_preference_and_ue_usage_setting_iei, "Voice domain preference and UE's usage setting IEI", 1, 8, "Voice domain preference and UE's usage setting");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_voice_domain_preference_and_ue_usage_setting_contents, "Length of Voice domain preference and UE's usage setting contents", 1, 8);
	    SKIP(1);
    }

    //if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "Spare", 4, 8);
        int tmp = -1;
        B8_BIT(tmp, 3, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, ue_s_useage_setting, "UE's usage setting", 3, 3, "Voice centric");
        }
        else
        {
            A_B8_BIT2(gbf, ue_s_useage_setting, "UE's usage setting", 3,  3, "Data centric");
        }

        A_B8_BIT3(gbf, voice_domain_preference_for_e_utran, "Voice domain preference for E-UTRAN", 1, 2, voice_domain_preference_for_e_utran_dict);
        SKIP(1);
    }
    END_ELEMENT();
}

void location_area_identification_2(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Location Area Identification 2", location_area_identification_2); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, location_area_identification_2_iei, "Location Area Identification 2 IEI", 1, 8, "Location Area Identification 2");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_location_area_identification_2_iei, "Length of Location Area Identification 2 IEI", 1, 8);
	    SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, location_area_identification_2_val, "Location Area Identification 2 value", 1, 8);
        len -= 1;
        SKIP(1);
    }

    END_ELEMENT();
}

void additional_update_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Additional update type", additional_update_type);
    if(iei == 0)
    {
        int tmp = -1;
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "Spare", 4, 4);
            A_B8_BIT1(gbf, spare, "Spare", 3, 3);
            A_B8_BIT1(gbf, spare, "Spare", 2, 2);
            
            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, autv, "AUTV", 1, 1, "No additional information. If received it shall be interpreted as request for combined attach or combined tracking area updating.");
            }
            else
            {
                A_B8_BIT2(gbf, autv, "AUTV", 1, 1, "SMS only");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "Spare", 8, 8);
            A_B8_BIT1(gbf, spare, "Spare", 7, 7);
            A_B8_BIT1(gbf, spare, "Spare", 6, 6);
            
            B8_BIT(tmp, 5, 5);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, autv, "AUTV", 5, 5, "No additional information. If received it shall be interpreted as request for combined attach or combined tracking area updating.");
            }
            else
            {
                A_B8_BIT2(gbf, autv, "AUTV", 5, 5, "SMS only");
            }
        }
    }
    else
    {
        int tmp = -1;
        B8_HEX();
        A_B8_BIT2(gbf, additional_update_type_iei, "Additional update type IEI", 5, 8, "Additional update type");

        A_B8_BIT1(gbf, spare, "Spare", 4, 4);
        A_B8_BIT1(gbf, spare, "Spare", 3, 3);
        A_B8_BIT1(gbf, spare, "Spare", 2, 2);

        B8_BIT(tmp, 1, 1);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, autv, "AUTV", 1, 1, "No additional information. If received it shall be interpreted as request for combined attach or combined tracking area updating.");
        }
        else
        {
           A_B8_BIT2(gbf, autv, "AUTV", 1, 1, "SMS only");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

//tmsi
void network_resource_identifier_container(uint8_t iei, uint8_t location) 
{ 
    BEGIN_ELEMENT("Network resource identifier container", network_resource_identifier_container); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(gbf, network_resource_identifier_container_iei, "Network resource identifier container IEI", 1, 8, "Network resource identifier container");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
	    B8_HEX(); 
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_network_resource_identifier_container_contents, "Length of Network resource identifier container contents", 1, 8);
	    SKIP(1);
    }

    if(len > 0)
    {
        int val_8 = 0;
        int val_2 = 0;
        char buf[256];
        B8_HEX();
        B8_BIT(val_8, 1, 8);
        A_B8_BIT2(gbf, nri_container_value, "NRI container value", 1, 8, "-");
        SKIP(1);

        B8_HEX();
        B8_BIT(val_2, 7, 8);
        val_8 = val_8 << 2 + val_2;
        memset(buf, 0x00, 256);
        sprintf(buf, "%d", val_8);
        A_B8_BIT2(gbf, nri_container_value, "NRI container value", 7, 8, buf);
        A_B8_BIT1(gbf, spare, "spare", 1, 6);
        SKIP(1);
    }

    END_ELEMENT();
}

void gprs_timer_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("GPRS Timer 2", gprs_timer_2 );
    if(iei==1)
    {    
            B8_HEX();
            A_B8_BIT2(gbf, gprs_timer_2_iei, "GPRS Timer 2 IEI", 1, 8, "GPRS Timer 2");
            SKIP(1);
    }

    if(location == 1)
    {
        B8_HEX();
        A_B8_BIT1(gbf, length_of_gprs_timer_2_contents, "Length of GPRS Timer 2 contents", 1, 8);
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, time_2_value, "GPRS Timer 2 value", 1, 8);
    SKIP(1);
    END_ELEMENT();
}

void attach_result(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Attach result", attach_result);
    if(iei == 0)
    {    
        if(location == 1)
        {
            int tmp = -1;
            B8_BIT(tmp, 4, 4);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, attach_result_fop, "FOP", 4, 4, "Follow-on proceed");
            }
            else
            {
                A_B8_BIT2(gbf, attach_result_fop, "FOP", 4, 4, "No follow-on proceed");
            }

            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, result_of_attach, "Result of attach", 1, 3, "GPRS only attached");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, result_of_attach   , "Result of attach", 1, 3, "Combined GPRS/IMSI attached");
            }
            else
            {
                A_B8_BIT2(gbf, result_of_attach   , "Result of attach", 1, 3, "reserved");
            }
            SKIP(1);            
        }
        else
        {
            int tmp = -1;
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, attach_result_fop, "FOP", 8, 8, "Follow-on proceed");
            }
            else
            {
                A_B8_BIT2(gbf, attach_result_fop, "FOP", 8, 8, "No follow-on proceed");
            }

            B8_BIT(tmp, 5, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, result_of_attach, "Result of attach", 5, 7, "GPRS only attached");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, result_of_attach, "Result of attach", 5, 7, "Combined GPRS/IMSI attached");
            }
            else
            {
                A_B8_BIT2(gbf, result_of_attach, "Result of attach", 5, 7, "reserved");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, attach_result_iei, "Attach result IEI", 5, 8, "Attach result");

        int tmp = -1;
        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, attach_result_fop, "FOP", 4, 4, "Follow-on proceed");
        }
        else
        {
            A_B8_BIT2(gbf, attach_result_fop, "FOP", 4, 4, "No follow-on proceed");
        }

        B8_BIT(tmp, 1, 3);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, result_of_attach, "Result of attach", 1, 3, "GPRS only attached");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, result_of_attach, "Result of attach", 1, 3, "Combined GPRS/IMSI attached");
        }
        else
        {
            A_B8_BIT2(gbf, result_of_attach, "Result of attach", 1, 3, "reserved");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void force_to_standby(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Force to standby", force_to_standby);
    if(iei==0)
    {
        if(location == 1)
        {
            A_B8_BIT2(gbf, force_to_standby_spare, "spare", 4, 4, "spare");
            int tmp = -1;
            B8_BIT(tmp, 1, 3);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 1, 3, "Force to standby not indicated");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 1, 3, "Force to standby indicated");
            }
            else
            {
                A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 1, 3, "force to standby not indicated by this version of the protocol.");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT2(gbf, force_to_standby_spare, "spare", 8, 8, "spare");
            int tmp = -1;
            B8_BIT(tmp, 5, 7);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 5, 7, "Force to standby not indicated");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 5, 7, "Force to standby indicated");
            }
            else
            {
               A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 5, 7, "force to standby not indicated by this version of the protocol.");
            }
        }
    }
    else
    {    
        B8_HEX();
        A_B8_BIT2(gbf, force_to_standby_iei, "Force to standby IEI", 5, 8, "Force to standby");
        A_B8_BIT2(gbf, force_to_standby_spare, "spare", 4, 4, "spare");
        int tmp = -1;
        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 1, 3, "Force to standby not indicated");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 1, 3, "Force to standby indicated");
        }
        else
        {
            A_B8_BIT2(gbf, force_to_standby_value, "Force to standby value", 1, 3, "force to standby not indicated by this version of the protocol.");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void radio_priority(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Radio priority", radio_priority);
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT2(gbf, radio_priority_spare, "spare", 4, 4, "spare");
            int tmp = -1;
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 3");
            }
            else
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
            }
            SKIP(1);            
        }
        else
        {
            B8_HEX();
            A_B8_BIT2(gbf, radio_priority_spare, "spare", 8, 8, "spare");
            int tmp = -1;
            B8_BIT(tmp, 5, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 5, 7, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 5, 7, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 5, 7, "priority level 3");
            }
            else
            {
                A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 5, 7, "priority level 4 (lowest)");
            }
        }
    }
    else
    {    
        B8_HEX();
        A_B8_BIT2(gbf, radio_priority_iei, "Radio priority IEI", 5, 8, "Radio priority");
        A_B8_BIT2(gbf, radio_priority_spare, "spare", 4, 4, "spare");
        int tmp = -1;
        B8_BIT(tmp, 1, 3);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 2");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 3");
        }
        else
        {
            A_B8_BIT2(gbf, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void radio_priority_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Radio priority 2",  radio_priority_2);
     if(iei == 0)
    {
        int tmp = -1;
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "Spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 3");
            }
            else
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "Spare", 8, 8);
            B8_BIT(tmp, 5, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 3");
            }
            else
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 4 (lowest)");
            }
        }
    }
    else
    {
	    int tmp = -1;
            B8_HEX();
            A_B8_BIT2(gbf, radio_priority_2_iei, "Radio priority 2 IEI", 5, 8, "Radio priority 2");

            A_B8_BIT1(gbf, spare, "Spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 3");
            }
            else
            {
                A_B8_BIT2(gbf, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
            }
            SKIP(1);
    }
    END_ELEMENT();
}

//DB
void gmm_cause(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("GMM cause",  gmm_cause);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, gmm_cause_iei, "GMM cause IEI", 1, 8, "GMM cause");
        SKIP(1);
    }

    int tmp = -1;
    B8_HEX();
    B8_BIT(tmp, 1, 8);
    if(tmp == 2)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "IMSI unknown in HLR");
    }
    else if(tmp == 3)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, " Illegal MS");
    }
    else if(tmp == 5)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "IMEI not accepted");
    }
    else if(tmp == 6)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Illegal ME");
    }
    else if(tmp == 7)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "GPRS services not allowed");
    }
    else if(tmp == 8)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "GPRS services and non-GPRS services not allowed");
    }
    else if(tmp == 9)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "MS identity cannot be derived by the network");
    }
    else if(tmp == 10)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Implicitly detached");
    }
    else if(tmp == 11)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "PLMN not allowed");
    }
    else if(tmp == 12)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Location Area not allowed");
    }
    else if(tmp == 13)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Roaming not allowed in this location area");
    }
    else if(tmp == 14)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "GPRS services not allowed in this PLMN");
    }
    else if(tmp == 15)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "No Suitable Cells In Location Area");
    }
    else if(tmp == 16)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "MSC temporarily not reachable");
    }
    else if(tmp == 17)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Network failure");
    }
    else if(tmp == 20)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "MAC failure");
    }
    else if(tmp == 21)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Synch failure");
    }
    else if(tmp == 22)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Congestion");
    }
    else if(tmp == 23)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "GSM authentication unacceptable");
    }
    else if(tmp == 25)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Not authorized for this CSG");
    }
    else if(tmp == 28)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "SMS provided via GPRS in this routing area");
    }
    else if(tmp == 40)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "No PDP context activated");
    }
    else if(tmp >= 48 && tmp <= 63)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "retry upon entry into a new cell");
    }
    else if(tmp == 95)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Semantically incorrect message");
    }
    else if(tmp == 96)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Invalid mandatory information");
    }
    else if(tmp == 97)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Message type non-existent or not implemented");
    }
    else if(tmp == 98)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Message type not compatible with the protocol state");
    }
    else if(tmp == 99)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Information element non-existent or not implemented");
    }
    else if(tmp == 100)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Conditional IE error");
    }
    else if(tmp == 101)
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Message not compatible with the protocol state");
    }
    else
    {
        A_B8_BIT2(gbf, gmm_cause_value, "Cause value", 1, 8, "Protocol error, unspecified");
    }
    SKIP(1);
    END_ELEMENT();
}


void cell_notification(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Cell Notification", cell_notification);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, cell_notification_iei, "Cell Notification IEI", 1, 8, "Cell Notification");
        SKIP(1);
    }
    END_ELEMENT();
}

void network_feature_support(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Network feature support", network_feature_support);
    if(iei == 0)
    {
        int tmp = -1;
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain supported");
            }
            else
            {
                 A_B8_BIT2(gbf, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain not supported");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, mbms, "MBMS", 3, 3,  "MBMS supported");
            }
            else
            {
                 A_B8_BIT2(gbf, mbms, "MBMS", 3, 3,  "MBMS not supported");
            }

            B8_BIT(tmp, 2, 2);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(gbf, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session in Iu mode and A/Gb mode not supported");
            }

            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, emcbs, "EMCBS", 1, 1,  "Emergency bearer services supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(gbf, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode not supported");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, lcs_molr, "LCS-MOLR", 8, 8,  "LCS-MOLR via PS domain supported");
            }
            else
            {
                 A_B8_BIT2(gbf, lcs_molr, "LCS-MOLR", 8, 8,  "LCS-MOLR via PS domain not supported");
            }

            B8_BIT(tmp, 7, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, mbms, "MBMS", 7, 7,  "MBMS supported");
            }
            else
            {
                 A_B8_BIT2(gbf, mbms, "MBMS", 7, 7,  "MBMS not supported");
            }

            B8_BIT(tmp, 6, 6);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, imsvops, "IMSVoPS", 6, 6,  "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(gbf, imsvops, "IMSVoPS", 6, 6,  "IMS voice over PS session in Iu mode and A/Gb mode not supported");
            }

            B8_BIT(tmp, 5, 5);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, emcbs, "EMCBS", 5, 5,  "Emergency bearer services supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(gbf, emcbs, "EMCBS", 5, 5,  "Emergency bearer services in Iu mode and A/Gb mode not supported");
            }
        }
    }
    else
    {
        int tmp = -1;
        B8_HEX();
        A_B8_BIT2(gbf, network_feature_support_iei, "Network feature support IEI", 5, 8, "Network feature support");
        B8_BIT(tmp, 4, 4);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain supported");
        }
        else
        {
             A_B8_BIT2(gbf, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain not supported");
        }

        B8_BIT(tmp, 3, 3);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, mbms, "MBMS", 3, 3,  "MBMS supported");
        }
        else
        {
             A_B8_BIT2(gbf, mbms, "MBMS", 3, 3,  "MBMS not supported");
        }

        B8_BIT(tmp, 2, 2);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode");
        }
        else
        {
             A_B8_BIT2(gbf, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session in Iu mode and A/Gb mode not supported");
        }

        B8_BIT(tmp, 1, 1);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode supported");
        }
        else
        {
             A_B8_BIT2(gbf, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode not supported");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void requested_ms_information(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Requested MS information", requested_ms_information);
    if(iei == 0)
    {
        int tmp = -1;
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE requested");
            }
            else
            {
                 A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE not requested");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 3, 3);
            }
            else
            {
                 A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 3, 3);
            }

            A_B8_BIT1(gbf, Spare, "Spare", 1, 2);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, i_rat, "I-RAT", 8, 8,  "Inter RAT information container IE requested");
            }
            else
            {
                 A_B8_BIT2(gbf, i_rat, "I-RAT", 8, 8,  "Inter RAT information container IE not requested");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 7, 7);
            }
            else
            {
                 A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 7, 7);
            }

            A_B8_BIT1(gbf, Spare, "Spare", 5, 6);
        }
    }
    else
    {
        int tmp = -1;
        B8_HEX();
        A_B8_BIT2(gbf, requested_ms_information, "Requested MS information IEI", 5, 8, "Requested MS information");
        B8_BIT(tmp, 4, 4);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE requested");
        }
        else
        {
             A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE not requested");
        }

        B8_BIT(tmp, 3, 3);
        if(tmp == 1)
        {
            A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 3, 3);
        }
        else
        {
             A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 3, 3);
        }

        A_B8_BIT1(gbf, Spare, "Spare", 1, 2);
        SKIP(1);
    }
    END_ELEMENT();

}

void additional_network_feature_support(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Additional network feature support", additional_network_feature_support);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, additional_network_feature_support_iei, "Additional network feature support IEI", 1, 8, "Additional network feature support");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_additional_network_feature_support_contents, "Length of additional network feature support contents", 1, 8);
	    SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        int tmp = -1;
        A_B8_BIT1(gbf, spare, "Spare", 2, 8);
        B8_BIT(tmp, 1, 1);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, gprs_sms, "GPRS-SMS", 1, 1, "SMS via GPRS not supported");
        }
        else
        {
            A_B8_BIT2(gbf, gprs_sms, "GPRS-SMS", 1, 1, "SMS via GPRS supported");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void inter_rat_information_container(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Inter RAT information container", inter_rat_information_container);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, inter_rat_information_container_iei, "Inter RAT information container IEI", 1, 8, "Inter RAT information container");
        SKIP(1);
    }
    
    int len = -1;
    if(location == 1)
    {
        B8_HEX();
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, length_of_inter_rat_information_container, "Length of inter RAT information container", 1, 8);
        SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, inter_rat_information_container_value_part, "Inter RAT information container value part", 1, 8);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();

}

void e_utran_inter_rat_information_container(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("E-UTRAN inter RAT information container", e_utran_inter_rat_information_container);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, e_utran_inter_rat_information_container_iei, "E-UTRAN Inter RAT information container IEI", 1, 8, "E-UTRAN inter RAT information container");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
        B8_HEX();
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, length_of e_utran_inter_rat_information_container, "Length of E-UTRAN Inter RAT information container", 1, 8);
        SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, e_utran_inter_rat_information_container_value_part, "E-UTRAN Inter RAT information container value part", 1, 8);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void detach_type(uint8_t iei, uint8_t location, int ms_to_net)
{
    BEGIN_ELEMENT("Detach type", detach_type);
    if(iei == 0)
    {
        if(location == 1)
        {
            int tmp = -1;
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, power_off, "Power off", 4, 4, "power switched off");
            }
            else
            {
                A_B8_BIT2(gbf, power_off, "Power off", 4, 4, "normal detach");
            }

            B8_BIT(tmp, 1, 3);
            if(ms_to_net == 1)
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "GPRS detach");
                }
                else if(tmp == 2)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "IMSI detach");
                }
                else
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "Combined GPRS/IMSI detach");                                            
                }
            }
            else
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "re-attach required");
                }
                else if(tmp == 3)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "IMSI detach (after VLR failure)");                    
                }
                else
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "re-attach not required");
                }                
            }
            SKIP(1);
        }
        else
        {
            int tmp = -1;
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, power_off, "Power off", 8, 8, "power switched off");
            }
            else
            {
                A_B8_BIT2(gbf, power_off, "Power off", 8, 8, "normal detach");
            }

            B8_BIT(tmp, 5, 7);
            if(ms_to_net == 1)
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 5, 7, "GPRS detach");
                }
                else if(tmp == 2)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 5, 7, "IMSI detach");
                }
                else
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 5, 7, "Combined GPRS/IMSI detach");                                            
                }
            }
            else
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 5, 7, "re-attach required");
                }
                else if(tmp == 3)
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 5, 7, "IMSI detach (after VLR failure)");                    
                }
                else
                {
                    A_B8_BIT2(gbf, type_of_detach, "Type of detach", 5, 7, "re-attach not required");
                }                
            }
        }        
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, detach_type_iei, "Detach type IEI", 5, 8, "Detach type");
        int tmp = -1;
        B8_BIT(tmp, 4, 4);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, power_off, "Power off", 4, 4, "power switched off");
        }
        else
        {
            A_B8_BIT2(gbf, power_off, "Power off", 4, 4, "normal detach");
        }

        B8_BIT(tmp, 1, 3);
        if(ms_to_net == 1)
        {
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "GPRS detach");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "IMSI detach");
            }
            else
            {
                A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "Combined GPRS/IMSI detach");                                            
            }
        }
        else
        {
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "re-attach required");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "IMSI detach (after VLR failure)");                    
            }
            else
            {
                A_B8_BIT2(gbf, type_of_detach, "Type of detach", 1, 3, "re-attach not required");
            }                
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void ciphering_algorithm(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Ciphering algorithm", ciphering_algorithm);
    char  buf[256];
//    bzero(buf, 256);
    memset(buf, 0x00, 256);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp != 0)
            {
                sprintf(buf, "GPRS Encryption Algorithm GEA/%d", tmp);
            }
            else
            {
                sprintf(buf, "ciphering not used");   
            }

            A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 1, 3, buf);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            B8_BIT(tmp, 5, 7);
            if(tmp != 0)
            {
                sprintf(buf, "GPRS Encryption Algorithm GEA/%d", tmp);
            }
            else
            {
                sprintf(buf, "ciphering not used");   
            }

            A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 5, 7, buf);
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, ciphering_algorithm_iei, "Ciphering algorithm IEI", 5, 8, "Ciphering algorithm");
        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        B8_BIT(tmp, 1, 3);
        if(tmp != 0)
        {
            sprintf(buf, "GPRS Encryption Algorithm GEA/%d", tmp);
        }
        else
        {
            sprintf(buf, "ciphering not used");   
        }

        A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 1, 3, buf);
        SKIP(1);
    }
    
    END_ELEMENT();
}

void imeisv_request(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("IMEISV request", imeisv_request);
    char  buf[256];
    //bzero(buf, 256);
    memset(buf, 0x00, 256);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 1, 3, "IMEISV requested");
            }
            else
            {
                A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 1, 3, "IMEISV not requested");
            }

            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            B8_BIT(tmp, 5, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 5, 7, "IMEISV requested");
            }
            else
            {
                A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 5, 7, "IMEISV not requested");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, ciphering_algorithm_iei, "Ciphering algorithm IEI", 5, 8, "Ciphering algorithm");
        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        B8_BIT(tmp, 1, 3);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 1, 3, "IMEISV requested");
        }
        else
        {
            A_B8_BIT2(gbf, type_of_algorithm, "Type of algorithm", 1, 3, "IMEISV not requested");
        }

        SKIP(1);
    }
    
    END_ELEMENT();
}

void ac_reference_number(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("A&C reference number", ac_reference_number);
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, ac_reference_number_val, "A&C reference number value", 1, 4);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, ac_reference_number_val, "A&C reference number value", 5, 8);
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, ac_reference_number_iei, "A&C reference number IEI", 5, 8, "A&C reference number");
        A_B8_BIT1(gbf, ac_reference_number_val, "A&C reference number value", 1, 4);
        SKIP(1);
    }
    END_ELEMENT();
}


void authentication_response_parameter(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Authentication Response parameter", authentication_response_parameter);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, authentication_response_parameter_iei, "Authentication Response parameter IEI", 1, 8, "Authentication Response parameter");
        SKIP(1);
    }

    int pos = 0; 
    int tmp = -1;
    char buf[50] = {0}; 
    B8_BIT(tmp, 1, 8);
    pos = sprintf((char *)buf, "%02x", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, sres_value_or_most_significat, "SRES value or most significant 4 octets of RES", 1, 8, "-");
    SKIP(1);

    B8_BIT(tmp, 1, 8);
    pos += sprintf((char *)buf + pos, "%02x", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, sres_value_or_most_significat, "SRES value or most significant 4 octets of RES", 1, 8, "-");
    SKIP(1);

    B8_BIT(tmp, 1, 8);
    pos += sprintf((char *)buf + pos, "%02x", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, sres_value_or_most_significat, "SRES value or most significant 4 octets of RES", 1, 8, "-");
    SKIP(1);

    B8_BIT(tmp, 1, 8);
    sprintf((char *)buf + pos, "%02x", tmp);
    B8_HEX();
    A_B8_BIT2(gbf, sres_value_or_most_significat, "SRES value or most significant 4 octets of RES", 1, 8, buf);
    SKIP(1);

    END_ELEMENT();
}

void dentity_type_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("dentity type 2", dentity_type_2);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp > 0 && tmp < 5)
            {
                A_B8_BIT3(gbf, type_of_identity, "Type of identity", 1, 3, type_of_identity_dict);
            }
            else
            {
                A_B8_BIT2(gbf, type_of_identity, "Type of identity", 1, 3, "IMSI");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            B8_BIT(tmp, 5, 7);
            if(tmp > 0 && tmp < 5)
            {
                A_B8_BIT3(gbf, type_of_identity, "Type of identity", 5, 7, type_of_identity_dict);
            }
            else
            {
                A_B8_BIT2(gbf, type_of_identity, "Type of identity", 5, 7, "IMSI");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, dentity_type_2_iei, "dentity type 2 IEI", 8, 5, "dentity type 2");
        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        B8_BIT(tmp, 1, 3);
        if(tmp > 0 && tmp < 5)
        {
            A_B8_BIT3(gbf, type_of_identity, "Type of identity", 1, 3, type_of_identity_dict);
        }
        else
        {
            A_B8_BIT2(gbf, type_of_identity, "Type of identity", 1, 3, "IMSI");
        }
        SKIP(1);
    }
    END_ELEMENT();   
}

void update_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Update type", dentity_type_2);
    int  tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_for, "FOR", 4, 4, "No follow-on request pending");
            }
            else
            {
                A_B8_BIT2(gbf, update_type_for, "FOR", 4, 4, "Follow-on request pending");
            }

            B8_BIT(tmp, 1, 3);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "RA updating");
            }
            else if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "combined RA/LA updating");
            }
            else if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "combined RA/LA updating with IMSI attach");
            }
            else
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "reserved");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_for, "FOR", 8, 8, "No follow-on request pending");
            }
            else
            {
                A_B8_BIT2(gbf, update_type_for, "FOR", 8, 8, "Follow-on request pending");
            }

            B8_BIT(tmp, 5, 7);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 5, 7, "RA updating");
            }
            else if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 5, 7, "combined RA/LA updating");
            }
            else if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 5, 7, "combined RA/LA updating with IMSI attach");
            }
            else
            {
                A_B8_BIT2(gbf, update_type_value, "Update type value", 5, 7, "reserved");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, update_type_iei, "Update type IEI", 5, 8, "Update type");
        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, update_type_for, "FOR", 4, 4, "No follow-on request pending");
        }
        else
        {
            A_B8_BIT2(gbf, update_type_for, "FOR", 4, 4, "Follow-on request pending");
        }

        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "RA updating");
        }
        else if(tmp == 0)
        {
            A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "combined RA/LA updating");
        }
        else if(tmp == 0)
        {
            A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "combined RA/LA updating with IMSI attach");
        }
        else
        {
            A_B8_BIT2(gbf, update_type_value, "Update type value", 1, 3, "reserved");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void update_result(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Update result", update_result);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, fop, "FOP", 4, 4, "Follow-on proceed");
            }
            else
            {
                A_B8_BIT2(gbf, fop, "FOP", 4, 4, "No follow-on proceed");
            }
         
            B8_BIT(tmp, 1, 3);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "RA updated");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "combined RA/LA updated");
            }
            else if(tmp == 4)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "RA updated and ISR activated");
            }
            else if(tmp == 5)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "combined RA/LA updated and ISR activated");
            }
            else
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "reserved");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, fop, "FOP", 8, 8, "Follow-on proceed");
            }
            else
            {
                A_B8_BIT2(gbf, fop, "FOP", 8, 8, "No follow-on proceed");
            }
         
            B8_BIT(tmp, 5, 7);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 5, 7, "RA updated");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 5, 7, "combined RA/LA updated");
            }
            else if(tmp == 4)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 5, 7, "RA updated and ISR activated");
            }
            else if(tmp == 5)
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 5, 7, "combined RA/LA updated and ISR activated");
            }
            else
            {
                A_B8_BIT2(gbf, update_result_value, "Update result value", 5, 7, "reserved");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, update_result_iei, "Update result IEI", 5, 8, "Update result");
        B8_BIT(tmp, 4, 4);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, fop, "FOP", 4, 4, "Follow-on proceed");
        }
        else
        {
            A_B8_BIT2(gbf, fop, "FOP", 4, 4, "No follow-on proceed");
        }
     
        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "RA updated");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "combined RA/LA updated");
        }
        else if(tmp == 4)
        {
            A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "RA updated and ISR activated");
        }
        else if(tmp == 5)
        {
            A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "combined RA/LA updated and ISR activated");
        }
        else
        {
            A_B8_BIT2(gbf, update_result_value, "Update result value", 1, 3, "reserved");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void receive_n_pdu_numbers_list(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Receive N PDU Numbers list", receive_n_pdu_numbers_list);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, receive_n_pdu_numbers_list_iei, "Receive N PDU Number list IEI", 1, 8, "Receive N PDU Number list");
        SKIP(1);
    }

    int len = -1;
    B8_HEX();
    B8_BIT(len, 1, 8);
    A_B8_BIT1(gbf, length_receive_n_pdu_numbers_list_contents, "Length of Receive N PDU Number list contents", 1, 8);
    //len -= 1;
    SKIP(1);

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, receive_n_pdu_number_list, "Receive N PDU Number-list", 1, 8);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void pdp_context_status(uint8_t iei, uint8_t location)
{
    int len = -1;
    BEGIN_ELEMENT("PDP context status", pdp_context_status);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, pdp_context_status, "PDP context status IEI", 1, 8, "PDP context status");
        SKIP(1);
    }
 
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, pdp_context_status_length, "Length of PDP context status contents", 1, 8);
	    SKIP(1);
    }

    char buf[256];
    int  i = -1;
    int  tmp = -1;
    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 8, 8);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(7)", 8, 8, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(7)", 8, 8, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 7, 7);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(6)", 7, 7, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(6)", 7, 7, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 6, 6);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(5)", 6, 6, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(5)", 6, 6, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }
        A_B8_BIT2(gbf, nsapi, "NSAP 4-0 ", 1, 5, "spare") ;
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 8, 8);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(15)", 8, 8, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(15)", 8, 8, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 7, 7);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(14)", 7, 7, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(14)", 7, 7, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 6, 6);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(13)", 6, 6, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(13)", 6, 6, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 5, 5);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(12)", 5, 5, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(12)", 5, 5, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 4, 4);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(11)", 4, 4, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(11)", 4, 4, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 3, 3);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(10)", 3, 3, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(10)", 3, 3, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 2, 2);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(9)", 2, 2, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(9)", 2, 2, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }

        B8_BIT(tmp, 1, 1);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(8)", 1, 1, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
        }
        else
        {
            A_B8_BIT2(gbf, nsapi, "NSAP(8)", 1, 1, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");     
        }
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void mbms_context_status(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("MBMS context status", mbms_context_status);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, mbms_context_status_iei, "MBMS context status IEI", 1, 8, "MBMS context status");
        SKIP(1);
    }

    int len = -1;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, mbms_context_status_length, "Length of MBMS context status contents", 1, 8);
	    SKIP(1);
    }
	int i = 0;
    int j = 0;
    int tmp = -1;
	char buf[256];
    while(len > 0)
    {
        B8_HEX();
//        for(i = 8; i > 0; i = i - 1)
        {
            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (135 + j * 8));
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 8, 8, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 8, 8, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }

            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (134 + j * 8));
            B8_BIT(tmp, 7, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 7, 7, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 7, 7, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }

            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (133 + j * 8));

            B8_BIT(tmp, 6, 6);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 6, 6, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 6, 6, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }
            
            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (132 + j * 8));
            B8_BIT(tmp, 5, 5);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 5, 5, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 5, 5, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }

            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (131 + j * 8));
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 4, 4, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 4, 4, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }

            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (130 + j * 8));
            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 3, 3, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 3, 3, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }

            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (129 + j * 8));
            B8_BIT(tmp, 2, 2);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 2, 2, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 2, 2, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }

            bzero(buf, 256);
            sprintf(buf, "NSAP %d ", (128 + j * 8));
            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, nsapi, buf, 1, 1, "indicates that the SM state of the corresponding PDP context is not PDP-INACTIVE.");
            }
            else
            {
                A_B8_BIT2(gbf, nsapi, buf, 1, 1, "indicates that the SM state of the corresponding PDP context is PDP-INACTIVE");
            }
        }
        SKIP(1);
        j ++;
        len -= 1;
    }

    END_ELEMENT();
}

void requested_ms_Information(int8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Requested MS Information", requested_ms_Information);
	int  tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if (tmp == 1)
            {
                A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4, "Inter RAT information container IE requested");
            }
            else
            {
                A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4, "Inter RAT information container IE not requested");    
            }
            
            A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 3, 3);
            A_B8_BIT1(gbf, spare, "Spare", 1, 2);
            SKIP(1);
        }
        else
        {
            B8_HEX();
            B8_BIT(tmp, 8, 8);
            if (tmp == 1)
            {
                A_B8_BIT2(gbf, i_rat, "I-RAT", 8, 8, "Inter RAT information container IE not requested");
            }
            else
            {
                A_B8_BIT2(gbf, i_rat, "I-RAT", 8, 8, "Inter RAT information container IE requested");    
            }
            
            A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 7, 7);
            A_B8_BIT1(gbf, spare, "Spare", 5, 6);
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, requested_ms_Information_iei, "Requested MS information IEI", 5, 8, "Requested MS information");
        B8_BIT(tmp, 4, 4);
        if (tmp == 1)
        {
            A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4, "Inter RAT information container IE not requested");
        }
        else
        {
            A_B8_BIT2(gbf, i_rat, "I-RAT", 4, 4, "Inter RAT information container IE requested");    
        }

        A_B8_BIT1(gbf, i_rat_2, "I-RAT2", 3, 3);
        A_B8_BIT1(gbf, spare, "Spare", 1, 2);
        SKIP(1);
    }
    END_ELEMENT();
}

void  service_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Service type", service_type);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "Signalling");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "Data");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "Paging Response");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "MBMS Multicast Service Reception");
            }
            else if(tmp == 4)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "MBMS Broadcast Service Reception");
            }
            else
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "reserved");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            tmp = 0;
            B8_BIT(tmp, 5, 7);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 5, 7, "Signalling");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 5, 7, "Data");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 5, 7, "Paging Response");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 5, 7, "MBMS Multicast Service Reception");
            }
            else if(tmp == 4)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 5, 7, "MBMS Broadcast Service Reception");
            }
            else
            {
                A_B8_BIT2(gbf, service_type, "Service type", 5, 7, "reserved");
            }
        }
    }
    else
    {
            B8_HEX();
            A_B8_BIT2(gbf, service_type_iei, "Service type IEI", 5, 8, "Service type");
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "Signalling");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "Data");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "Paging Response");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "MBMS Multicast Service Reception");
            }
            else if(tmp == 4)
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "MBMS Broadcast Service Reception");
            }
            else
            {
                A_B8_BIT2(gbf, service_type, "Service type", 1, 3, "reserved");
            }
            SKIP(1);
    }
    END_ELEMENT();
}

void uplink_data_status(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Uplink data status", uplink_data_status);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, uplink_data_status_iei, "Uplink data status IEI", 1, 8, "Uplink data status");
        SKIP(1);
    }

    if(location == 1)
    {
        B8_HEX();
        A_B8_BIT1(gbf, length_of_uplink_data_status_contents, "Length of Uplink data status contents", 1, 8);
        SKIP(1);
    }

    B8_HEX();
    char buf[16];
    int tmp = -1;
    int i = 0, j = 0;

    B8_HEX();
    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 7);
    B8_BIT(tmp, 8, 8);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 8, 8, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 8, 8, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 6);
    B8_BIT(tmp, 7, 7);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 7, 7, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 7, 7, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 5);
    B8_BIT(tmp, 6, 6);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 6, 6, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 6, 6, "1 uplink data are pending for the preserved PDP context.");
    }

    A_B8_BIT1(gbf, spare, "spare", 1, 5);
    SKIP(1);

    B8_HEX();
    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 15);
    B8_BIT(tmp, 8, 8);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 8, 8, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 8, 8, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 14);
    B8_BIT(tmp, 7, 7);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 7, 7, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 7, 7, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 13);
    B8_BIT(tmp, 6, 6);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 6, 6, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 6, 6, "1 uplink data are pending for the preserved PDP context.");
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 12);
    B8_BIT(tmp, 5, 5);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 5, 5, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 5, 5, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 11);
    B8_BIT(tmp, 4, 4);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 4, 4, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 4, 4, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 10);
    B8_BIT(tmp, 3, 3);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 3, 3, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 3, 3, "1 uplink data are pending for the preserved PDP context.");
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 9);
    B8_BIT(tmp, 2, 2);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 2, 2, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 2, 2, "1 uplink data are pending for the preserved PDP context.");   
    }

    memset(buf, 0x00, 16);
    sprintf(buf, "NSAPI (%d)", 8);
    B8_BIT(tmp, 1, 1);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, nsapi, buf, 1, 1, "no uplink data are pending for the preserved PDP context or the PDP context is PDP-INACTIVE or is PDP-ACTIVE with a RAB already established.");
    }
    else
    {
        A_B8_BIT2(gbf, nsapi, buf, 1, 1, "1 uplink data are pending for the preserved PDP context.");   
    }
    SKIP(1);
    END_ELEMENT();
}

void  network_service_access_point_identifier(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Network service access point identifier", network_service_access_point_identifier);
    int tmp = -1;
    char buf[16];
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, network_service_access_point_identifier_iei, "Network service access point identifier IEI", 1, 8, "Network service access point identifier");
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, spare, "spare", 5, 8);
    B8_BIT(tmp, 1, 4);
    if(tmp >= 0 && tmp < 5)
    {
        A_B8_BIT2(gbf, nsapi_value, "NSAPI value", 1, 4, "Reserved");
    }
    else
    {
        sprintf(buf, "NSAPI %d", tmp);
        A_B8_BIT2(gbf, nsapi_value, "NSAPI value", 1, 4, buf);
    }
    SKIP(1);

    END_ELEMENT();
}

void llc_service_access_point_identifier(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("LLC service access point identifier",  llc_service_access_point_identifier);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, llc_service_access_point_identifier_iei, "LLC service access point identifier IEI", 1, 8, "LLC service access point identifier");
        SKIP(1);
    }

    B8_HEX();
    int tmp = 0;
    A_B8_BIT1(gbf, spare, "Spare", 5, 8);
    B8_BIT(tmp, 1, 4);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, llc_sapi_value,  "LLC SAPI value", 1, 4, "LLC SAPI not assigned");
    }
    else if(tmp == 3)
    {
        A_B8_BIT2(gbf, llc_sapi_value,  "LLC SAPI value", 1, 4, "SAPI3");
    }
    else if(tmp == 5)
    {
        A_B8_BIT2(gbf, llc_sapi_value,  "LLC SAPI value", 1, 4, "SAPI5");
    }
    else if(tmp == 9)
    {
        A_B8_BIT2(gbf, llc_sapi_value,  "LLC SAPI value", 1, 4, "SAPI9");
    }
    else if(tmp == 11)
    {
        A_B8_BIT2(gbf, llc_sapi_value,  "LLC SAPI value", 1, 4, "SAPI11");
    }
    else
    {
        A_B8_BIT2(gbf, llc_sapi_value,  "LLC SAPI value", 1, 4, "reserved");
    }
    
    SKIP(1);
    END_ELEMENT();
}

void quality_of_service(uint8_t iei, uint8_t location, int ms_to_net)
{
    int len = -1;
    BEGIN_ELEMENT("Quality of service", quality_of_service);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, quality_of_service_iei, "Quality of service IEI", 1, 8, "Quality of service");
        SKIP(1);
    }

    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_quality_of_service_ie , "Length of quality of service IE", 1, 8);
	    SKIP(1);
    }

    int tmp = -1;
    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 7, 8);
        B8_BIT(tmp, 4, 6);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Subscribed delay class");    
            }
            else
            {
                A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Delay class 1");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Delay class 2");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Delay class 3");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Reserved");
        }
        else
        {
            A_B8_BIT2(gbf, delay_class, "Delay class", 4, 6, "Delay class 4 (best effort)");
        }
        
        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Subscribed reliability class");
            }
            else
            {
                A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Reserved");
            }
        }
        else if(tmp = 1)
        {
            A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Unused. If received, it shall be interpreted as '010' (Note)");
        }
        else if(tmp = 2)
        {
            A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Unacknowledged GTP; Acknowledged LLC and RLC, Protected data");
        }
        else if(tmp = 4)
        {
            A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Unacknowledged GTP, LLC, and RLC, Protected data");
        }
        else if(tmp = 5)
        {
            A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Unacknowledged GTP, LLC, and RLC, Unprotected data");
        }
        else if(tmp = 7)
        {
            A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Reserved");
        }
        else
        {
           A_B8_BIT2(gbf, reliability_class, "Reliability class", 1, 3, "Unacknowledged GTP and LLC; Acknowledged RLC, Protected data");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 5, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Subscribed peak throughput");
            }
            else
            {
                A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Reserved");
            }
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 2 000 octet/s");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 4 000 octet/s");
        }
        else if(tmp == 4)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 8 000 octet/s");
        }
        else if(tmp == 5)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 16 000 octet/s");
        }
        else if(tmp == 6)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 32 000 octet/s");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 64 000 octet/s");
        }
        else if(tmp == 8)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 128 000 octet/s");
        }
        else if(tmp == 9)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 256 000 octet/s");
        }
        else if(tmp == 15)
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Reserved");
        }
        else
        {
            A_B8_BIT2(gbf, peak_throughput, "Peak throughput", 5, 8, "Up to 1 000 octet/s");
        }

        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Subscribed precedence");
            }
            else
            {
                A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "High priority");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Low priority");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Reserved");
        }
        else
        {
            A_B8_BIT2(gbf, precedence_class, "Precedence class", 1, 3, "Normal priority");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 6, 8);
        B8_BIT(tmp, 1, 5);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "Subscribed mean throughput");
            }
            else
            {
                A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "100 octet/h");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "200 octet/h");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "500 octet/h");
        }
        else if(tmp == 4)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "1 000 octet/h");
        }
        else if(tmp == 5)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "2 000 octet/h");
        }
        else if(tmp == 6)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "5 000 octet/h");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "10 000 octet/h");
        }
        else if(tmp == 8)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "20 000 octet/h");
        }
        else if(tmp == 9)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "50 000 octet/h");
        }
        else if(tmp == 10)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "100 000 octet/h");
        }
        else if(tmp == 11)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "200 000 octet/h");
        }
        else if(tmp == 12)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "500 000 octet/h");
        }
        else if(tmp == 13)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "1 000 000 octet/h");
        }
        else if(tmp == 14)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "2 000 000 octet/h");
        }
        else if(tmp == 15)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "5 000 000 octet/h");
        }
        else if(tmp == 16)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "10 000 000 octet/h");
        }
        else if(tmp == 17)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "20 000 000 octet/h");
        }
        else if(tmp == 18)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "50 000 000 octet/h");
        }
        else if(tmp == 30)
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "Reserved");
        }
        else
        {
            A_B8_BIT2(gbf, mean_throughput, "Mean throughput", 1, 5, "Best effort");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 6, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Subscribed traffic class");
            }
            else
            {
                A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Conversational class");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Streaming class");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Interactive class");
        }
        else if(tmp == 4)
        {
            A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Background class");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, traffic_class, "Traffic class", 6, 8, "Reserved");
        }
        
        B8_BIT(tmp, 4, 5);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "Subscribed delivery order");
            }
            else
            {
                A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "With delivery order ('yes')");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "Without delivery order ('no')");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, delivery_order, "Delivery order", 4, 5, "Reserved");
        }

        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, delivery_of_erroneous_sdus, "Delivery of erroneous SDUs", 1, 3, "Subscribed delivery of erroneous SDUs");
            }
            else
            {
                A_B8_BIT2(gbf, delivery_of_erroneous_sdus, "Delivery of erroneous SDUs", 1, 3, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, delivery_of_erroneous_sdus, "Delivery of erroneous SDUs", 1, 3, "No detect ('-')");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, delivery_of_erroneous_sdus, "Delivery of erroneous SDUs", 1, 3, "Erroneous SDUs are delivered ('yes')");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, delivery_of_erroneous_sdus, "Delivery of erroneous SDUs", 1, 3, "Erroneous SDUs are not delivered ('no')");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, delivery_of_erroneous_sdus, "Delivery of erroneous SDUs", 1, 3, "Reserved");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "Subscribed maximum bit rate for uplink");
            }
            else
            {
                A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "Reserved");
            }    
        }
        else if(tmp == 151)
        {
            A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "1502 octets");
        }
            else if(tmp == 152)
        {
            A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "1510 octets");
        }
            else if(tmp == 153)
        {
            A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "1520 octets");
        }
        else
        {
            A_B8_BIT2(gbf, maximum_sdu_size, "Maximum SDU size", 1, 8, "Reserved");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "Subscribed maximum bit rate for uplink");
            }
            else
            {
                A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "The maximum bit rate is binary coded in 8 bits, using a granularity of 1 kbps");
        }
        else if(tmp == 63)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "giving a range of values from 1 kbps to 63 kbps in 1 kbps increments.");
        }
        else if(tmp == 64)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "The maximum bit rate is 64 kbps + ((the binary coded value in 8 bits –01000000) * 8 kbps)");
        }
        else if(tmp == 127)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "giving a range of values from 64 kbps to 568 kbps in 8 kbps increments.");
        }
        else if(tmp == 128)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "The maximum bit rate is 576 kbps + ((the binary coded value in 8 bits –10000000) * 64 kbps)");
        }
        else if(tmp == 254)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "giving a range of values from 576 kbps to 8640 kbps in 64 kbps increments.");
        }
        else if(tmp == 255)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink, "Maximum bit rate for uplink", 1, 8, "0kbps");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "Subscribed maximum bit rate for downlink");
            }
            else
            {
                A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "The maximum bit rate is binary coded in 8 bits, using a granularity of 1 kbps");
        }
        else if(tmp == 63)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "giving a range of values from 1 kbps to 63 kbps in 1 kbps increments.");
        }
        else if(tmp == 64)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "The maximum bit rate is 64 kbps + ((the binary coded value in 8 bits –01000000) * 8 kbps)");
        }
        else if(tmp == 127)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "giving a range of values from 64 kbps to 568 kbps in 8 kbps increments.");
        }
        else if(tmp == 128)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "The maximum bit rate is 576 kbps + ((the binary coded value in 8 bits –10000000) * 64 kbps)");
        }
        else if(tmp == 254)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "giving a range of values from 576 kbps to 8640 kbps in 64 kbps increments.");
        }
        else if(tmp == 255)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink, "Maximum bit rate for downlink", 1, 8, "0kbps");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 5, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "Subscribed residual BER");
            }
            else
            {
                A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "5*10^-2");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "1*10^-2");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "5*10^-3");
        }
        else if(tmp == 4)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "4*10^-3");   
        }
        else if(tmp == 5)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "1*10^-3");
        }
        else if(tmp == 6)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "1*10^-4");
        }
        else if(tmp == 7)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "1*10^-5");
        }
        else if(tmp == 8)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "1*10^-6");
        }
        else if(tmp == 9)
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "6*10^-8");
        }
        else
        {
            A_B8_BIT2(gbf, residual_bit_error_rate, "Residual Bit Error Rate", 5, 8, "Reserved");
        }

        B8_BIT(tmp, 1, 4);
        if(tmp  == 1)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "1*10^-2");   
        }
        else if(tmp  == 2)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "7*10^-3");   
        }
        else if(tmp  == 3)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "1*10^-3");   
        }
        else if(tmp  == 4)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "1*10^-4");   
        }
        else if(tmp  == 5)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "1*10^-5");   
        }
        else if(tmp  == 6)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "1*10^-6");   
        }
        else if(tmp  == 7)
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "1*10^-1");   
        }
        else
        {
            A_B8_BIT2(gbf, sdu_error_ratio, "SDU Error Ratio", 5, 8, "Reserved");   
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 3, 8);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "Subscribed transfer delay");
            }
            else
            {
                A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "Reserved");   
            }
        }
        else if(tmp == 1)
        {
             A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "The Transfer delay is binary coded in 6 bits, using a granularity of 10 ms");
        }
        else if(tmp == 15)
        {
             A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "giving a range of values from 10 ms to 150 ms in 10 ms increments");
        }
        else if(tmp == 16)
        {
            A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "The transfer delay is 200 ms + ((the binary coded value in 6 bits – 010000) * 50 mss)");        
        }
        else if(tmp == 31)
        {
            A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "giving a range of values from 200 ms to 950 ms in 50ms increments");
        }
        else if(tmp == 32)
        {
            A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "The transfer delay is 1000 ms + ((the binary coded value in 6 bits – 100000) * 100 ms)");        
        }
        else if(tmp == 62)
        {
            A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "giving a range of values from 1000 ms to 4000 ms in 100ms increments");
        }
        else if(tmp == 63)
        {
            A_B8_BIT2(gbf, transfer_delay, "Transfer delay", 3, 8, "Reserved");   
        }

        B8_BIT(tmp, 1, 2);
        if(tmp == 0)
        {
            if(ms_to_net == 1)
            {
                A_B8_BIT2(gbf, traffic_handling_riority, "Traffic Handling priority", 1, 2, "Subscribed traffic handling priority");    
            }
            else
            {
                A_B8_BIT2(gbf, traffic_handling_riority, "Traffic Handling priority", 1, 2, "Reserved");
            }
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, traffic_handling_riority, "Traffic Handling priority", 1, 2, "Priority level 1");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, traffic_handling_riority, "Traffic Handling priority", 1, 2, "Priority level 2");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, traffic_handling_riority, "Traffic Handling priority", 1, 2, "Priority level 3");
        }
        len -= 1;
        SKIP(1);
    }

    int  downlink = -1;
    if(len > 0)
    {
        int  uplink = -1;
        B8_HEX();
        B8_BIT(uplink, 1, 8);
        A_B8_BIT1(gbf, guaranteed_bit_rate_for_uplink, "Guaranteed bit rate for uplink", 1, 8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(downlink, 1, 8);
        A_B8_BIT1(gbf, guaranteed_bit_rate_for_uplink, "Guaranteed bit rate for downlink", 1, 8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 6, 8);
        B8_BIT(tmp, 5, 5);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, signalling_indication, "Signalling Indication", 5, 5, "Not optimised for signalling traffic");
        }
        else
        {
            A_B8_BIT2(gbf, signalling_indication, "Signalling Indication", 5, 5, "Optimised for signalling traffic");
        }

        B8_BIT(tmp, 1, 4);
        if(ms_to_net == 1)
        {
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, Source Statistics Descriptor, "Source Statistics Descriptor", 1, 4, "unknown");
            }
            else
            {
                A_B8_BIT2(gbf, Source Statistics Descriptor, "Source Statistics Descriptor", 1, 4, "speech");
            }
        }
        else
        {
            A_B8_BIT2(gbf, Source Statistics Descriptor, "Source Statistics Descriptor", 1, 4, "spare");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "Use the value indicated by the Maximum bit rate for downlink in octet 9.");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "The maximum bit rate is 8600 kbps + ((the binary coded value in 8 bits) * 100 kbps)");
        }
        else if(tmp == 74)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "giving a range of values from 8700 kbps to 16000 kbps in 100 kbps increments.");
        }
        else if(tmp == 75)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "The maximum bit rate is 16 Mbps + ((the binary coded value in 8 bits - 01001010) * 1 Mbps).");
        }
        else if(tmp == 186)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "giving a range of values from 17 Mbps to 128 Mbps in 1 Mbps increments.");
        }
        else if(tmp == 187)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "The maximum bit rate is 128 Mbps + ((the binary coded value in 8 bits - 10111010) * 2 Mbps)");
        }
        else if(tmp == 250)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended, "Maximum bit rate for downlink (extended)", 1, 8, "giving a range of values from 130 Mbps to 256 Mbps in 2 Mbps increments.");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "Use the value indicated by the Guaranteed bit rate for downlink in octet 13.");
        }
        else  if(tmp == 1)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "The guaranteed bit rate is 8600 kbps + ((the binary coded value in 8 bits) * 100 kbps),");
        }
        else  if(tmp == 74)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "giving a range of values from 8700 kbps to 16000 kbps in 100 kbps increments.");
        }
        else  if(tmp == 75)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "The maximum bit rate is 16 Mbps + ((the binary coded value in 8 bits - 01001010) * 1 Mbps),");
        }
        else  if(tmp == 186)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "giving a range of values from 17 Mbps to 128 Mbps in 1 Mbps increments.");
        }
        else  if(tmp == 187)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "The maximum bit rate is 128 Mbps + ((the binary coded value in 8 bits - 10111010) * 2 Mbps),");
        }
        else  if(tmp == 250) 
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended, "Guaranteed bit rate for downlink (extended)", 1, 8, "giving a range of values from 130 Mbps to 256 Mbps in 2 Mbps increments.");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "Use the value indicated by the Maximum bit rate for downlink in octet 9.");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "The maximum bit rate is 8600 kbps + ((the binary coded value in 8 bits) * 100 kbps)");
        }
        else if(tmp == 74)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "giving a range of values from 8700 kbps to 16000 kbps in 100 kbps increments.");
        }
        else if(tmp == 75)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "The maximum bit rate is 16 Mbps + ((the binary coded value in 8 bits - 01001010) * 1 Mbps).");
        }
        else if(tmp == 186)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "giving a range of values from 17 Mbps to 128 Mbps in 1 Mbps increments.");
        }
        else if(tmp == 187)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "The maximum bit rate is 128 Mbps + ((the binary coded value in 8 bits - 10111010) * 2 Mbps)");
        }
        else if(tmp == 250)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_uplink_extended, "Maximum bit rate for uplink (extended)", 1, 8, "giving a range of values from 130 Mbps to 256 Mbps in 2 Mbps increments.");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "Use the value indicated by the Guaranteed bit rate for downlink in octet 13.");
        }
        else  if(tmp == 1)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "The guaranteed bit rate is 8600 kbps + ((the binary coded value in 8 bits) * 100 kbps),");
        }
        else  if(tmp == 74)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "giving a range of values from 8700 kbps to 16000 kbps in 100 kbps increments.");
        }
        else  if(tmp == 75)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "The maximum bit rate is 16 Mbps + ((the binary coded value in 8 bits - 01001010) * 1 Mbps),");
        }
        else  if(tmp == 186)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "giving a range of values from 17 Mbps to 128 Mbps in 1 Mbps increments.");
        }
        else  if(tmp == 187)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "The maximum bit rate is 128 Mbps + ((the binary coded value in 8 bits - 10111010) * 2 Mbps),");
        }
        else  if(tmp == 250) 
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_uplink_extended, "Guaranteed bit rate for uplink (extended)", 1, 8, "giving a range of values from 130 Mbps to 256 Mbps in 2 Mbps increments.");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "Use the value indicated by the Maximum bit rate for downlink in octet 9 and octet 15.");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 256 Mbps + ((the binary coded value in 8 bits) * 4 Mbps),");
        }
        else if(tmp == 61)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "giving a range of values from 260 Mbps to 500 Mbps in 4 Mbps increments.");
        }
        else if(tmp == 62)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 500 Mbps + ((the binary coded value in 8 bits - 00111101) * 10 Mbps),");
        }
        else if(tmp == 161)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "giving a range of values from 510 Mbps to 1500 Mbps in 10 Mbps increments");
        }
        else if(tmp == 162)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 1500 Mbps + ((the binary coded value in 8 bits - 10100001) * 100 Mbps),");
        }
        else if(tmp == 246)
        {
            A_B8_BIT2(gbf, maximum_bit_rate_for_downlink_extended_2, "Maximum bit rate for downlink (extended-2)", 1, 8, "giving a range of values from 1600 Mbps to 10 Gbps in 100 Mbps increments.");
        }
        len -= 1;
        SKIP(1);        
    }

    if(len > 0)
    {
        B8_HEX();
        B8_BIT(tmp, 1, 8);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "Use the value indicated by the Maximum bit rate for downlink in octet 9 and octet 15.");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 256 Mbps + ((the binary coded value in 8 bits) * 4 Mbps)");
        }
        else if(tmp == 61)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "giving a range of values from 260 Mbps to 500 Mbps in 4 Mbps increments.");
        }
        else if(tmp == 62)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 500 Mbps + ((the binary coded value in 8 bits - 00111101) * 10 Mbps)");            
        }
        else if(tmp == 161)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 500 Mbps + ((the binary coded value in 8 bits - 00111101) * 10 Mbps)");
        }
        else if(tmp == 162)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 1500 Mbps + ((the binary coded value in 8 bits - 10100001) * 100 Mbps)");
        }
        else if(tmp == 246)
        {
            A_B8_BIT2(gbf, guaranteed_bit_rate_for_downlink_extended_2, "Guaranteed bit rate for downlink (extended-2)", 1, 8, "The maximum bit rate is 1500 Mbps + ((the binary coded value in 8 bits - 10100001) * 100 Mbps)");
        }
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, maximum_bit_rate_for_uplink_extended_2, "Maximum bit rate for uplink (extended-2)", 1, 8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, guaranteed_bit_rate_for_uplink_extended_2, "Guaranteed bit rate for uplink (extended-2)", 1, 8);
        len -= 1;
        SKIP(1);        
    }

    END_ELEMENT();
}

void packet_data_protocol_address(uint8_t iei, uint8_t location, int ms_to_net)
{
    int tmp = -1;
    int tmp0 = -1;
    BEGIN_ELEMENT("Packet data protocol address", packet_data_protocol_address);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, packet_data_protocol_address_iei, "Packet data protocol address IEI", 1, 8, "Packet data protocol address");
        SKIP(1);
    }

    int len = -1;
    if(location = 1)
    {
        B8_HEX();
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, length_of_pdp_address_contents, "Length of PDP address contents", 1, 8);
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, spare, "Spare", 5, 8);
    B8_BIT(tmp, 1, 4);
    if(ms_to_net == 1)
    {
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "ETSI allocated address");
            SKIP(1);
            len -= 1;

            B8_HEX();
            B8_BIT(tmp0, 1, 8);
            if(tmp0 == 0)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "Reserved, used in earlier version of this protocol");
            }
            else if(tmp0 == 1)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "PDP-type PPP");
            }
            else
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "reserved");
            }
            SKIP(1);
            len -= 1;
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "IETF allocated address");
            SKIP(1);
            len -= 1;

            B8_HEX();
            B8_BIT(tmp0, 1, 8);
            if(tmp0 == 33)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, " IPv4 address");
            }
            else if(tmp0 == 87)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, " IPv6 address");
            }
            else if(tmp0 == 141)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "IPv4v6 address");
            }
            else
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "IPv4 address");   
            }
            SKIP(1); 
            len -= 1;
        }
        else if(tmp == 15)
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "Empty PDP type");
            SKIP(1);
            len -= 1;

            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 1, 8);
            SKIP(1);
            len -= 1;
        }
        else
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "reserved");
            SKIP(1);
            len -= 1;

            B8_HEX();
            A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "reserved");
            SKIP(1);
            len -= 1;
        }
    }
    else
    {
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "ETSI allocated address");
            SKIP(1);
            len -= 1;

            B8_HEX();
            B8_BIT(tmp0, 1, 8);
            if(tmp0 == 0)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "Reserved, used in earlier version of this protocol");
            }
            else if(tmp0 == 1)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "PDP-type PPP");
            }
            else
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "reserved");
            }
            SKIP(1);
            len -= 1;
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "IETF allocated address");
            SKIP(1);
            len -= 1;

            B8_HEX();
            B8_BIT(tmp0, 1, 8);
            if(tmp0 == 41)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, " IPv4 address");
            }
            else if(tmp0 == 127)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, " IPv6 address");
            }
            else if(tmp0 == 215)
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "IPv4v6 address");
            }
            else
            {
                A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "IPv4 address");   
            }
            SKIP(1); 
            len -= 1;
        }
        else
        {
            A_B8_BIT2(gbf, pdp_type_organisation, "PDP type organisation", 1, 4, "reserved");
            SKIP(1);
            len -= 1;

            B8_HEX();
            A_B8_BIT2(gbf, pdp_type_numbe, "PDP type numbe", 1, 8, "reserved");
            SKIP(1);
            len -= 1;
        }
    }
    
    int pos = 0;
    int i = 0;
    char buf[50] = {0};
    if(len > 0)
    {
        for(i = 0; i < len - 1; i++)
        {
            B8_BIT(tmp0, 1, 8);
            pos += sprintf((char *)buf + pos, "%d.", tmp0);
            B8_HEX();
            A_B8_BIT2(gbf, address_information, "Address information", 1, 8, "-");    
            SKIP(1);
        }
        B8_BIT(tmp0, 1, 8);
        sprintf((char *)buf + pos, "%d", tmp0);
        B8_HEX();
        A_B8_BIT2(gbf, address_information, "Address information", 1, 8, buf);    
        SKIP(1);
    }

    END_ELEMENT();
}

void  access_point_name(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Access point name", access_point_name);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, access_point_name_iei, "Access point name IEI", 1, 8, "Access point name");
        SKIP(1);
    }

    int len = 0;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_access_point_name_contents, "Length of access point name contents", 1, 8);
	    SKIP(1);
    }

    while(len > 0)
    {
        A_B8_BIT1(gbf, access_point_name_value, "Access point name value", 1, 8);
        SKIP(1);
        len -= 1;
    }
    END_ELEMENT();

}

void protocol_configuration_options(uint8_t iei, uint8_t location, int ms_to_net)
{
    int tmp = -1;
    int sum = -1;
    BEGIN_ELEMENT("Protocol configuration options", protocol_configuration_options);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, protocol_configuration_options_iei, "Protocol configuration options IEI", 1, 8, "Protocol configuration options");
        SKIP(1);
    }

    int len = 0;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_protocol_config_options_contents, "Length of protocol config. options contents", 1, 8);
	    SKIP(1);
    }

    if(len >0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, ext, "ext", 8, 8);
        A_B8_BIT1(gbf, spare, "Spare", 4, 7);
        B8_BIT(tmp, 1, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, configuration_protocol, "Configuration protocol", 1, 3, "PPP for use with IP PDP type or IP PDN type (see 3GPP TS 24.301 [120])");
        }
        else if(tmp == 1)
        {
            A_B8_BIT2(gbf, configuration_protocol, "Configuration protocol", 1, 3, " interpreted as PPP in this version of the protocol.");   
        }
        len -= 1;
        SKIP(1);
    }
    if(len > 0)
    {
        int pos = 0;
        int i = 0;
        char buf[200] = {0};
        for(i = 0; i < len - 1; i++)
        {
            B8_BIT(tmp, 1, 8);
            pos += sprintf((char *)buf + pos, "%02x", tmp);
            B8_HEX();
            A_B8_BIT2(gbf, address_information, "Address information", 1, 8, "-");    
            SKIP(1);
        }
        B8_BIT(tmp, 1, 8);
        sprintf((char *)buf + pos, "%02x", tmp);
        B8_HEX();
        A_B8_BIT2(gbf, address_information, "Address information", 1, 8, buf);    
        SKIP(1);
    }

#if 0
    int ID = 1;
    char  id_buf[256] = {0};
    char  len_buf[256] = {0};
    char  content_buf[256] = {0};
    while(len > 0)
    {
        bzero(id_buf, 256);
        bzero(len_buf, 256);
        bzero(content_buf, 256);

        B8_HEX();
        B8_BIT(tmp, 1, 8);
        sum = tmp;
        A_B8_BIT2(gbf, protocol_identifier, id_buf, 1, 8, "-");
        len -= 1;
        SKIP(1);

        B8_HEX();
        B8_BIT(tmp, 1, 8);
        sum += tmp;

        if(sum == 0xC021 || sum == 0xC023 || sum == 0xC223 || sum == 0x8021)
        {
            sprintf(id_buf, "Protocol ID %d", ID);
            sprintf(len_buf, "Length of protocol ID %d contents", ID);
            sprintf(content_buf, "Protocol ID %d contents", ID);

            if(sum == 0xC021)
            {
                A_B8_BIT2(gbf, protocol_identifier, id_buf, 1, 8, "LCP");
            }
            if(sum == 0xC023)
            {
                A_B8_BIT2(gbf, protocol_identifier, id_buf, 1, 8, "PAP");
            }
            if(sum == 0xC223)
            {
                A_B8_BIT2(gbf, protocol_identifier, id_buf, 1, 8, "CHAP");
            }
            if(sum == 0x8021)
            {
                A_B8_BIT2(gbf, protocol_identifier, id_buf, 1, 8, "IPCP");
            }
            len -= 1;
            SKIP(1);

            int len_con = -1;
            B8_HEX();
            B8_BIT(len_con, 1, 8);
            A_B8_BIT1(gbf, length_of_protocol_id_1_contents, len_buf, 1, 8);
            //len -= 1;
            SKIP(1);

            len -= len_con;
            while(len_con > 0)
            {
                B8_HEX();
                A_B8_BIT1(gbf, protocol_id_contents, content_buf, 1, 8);
                len_con -= 1;
                SKIP(1);
            }
        }
        else if((sum > 0 && sum <= 0x12) || (sum >= 0xff00 && sum <= 0xffff))
        {
            sprintf(id_buf, "Container ID %d", ID);
            sprintf(len_buf, "Length of container ID %d contents", ID);
            sprintf(content_buf, "Container ID %d contents", ID);

            if(sum > 0 && sum <= 0x12)
            {
                if(ms_to_net == 1)
                {
                    A_B8_BIT3(gbf, container_id, id_buf, 1, 8, con_id_m_to_n_dict);
                }
                else
                {
                    A_B8_BIT3(gbf, container_id, id_buf, 1, 8, con_id_n_to_m_dict);
                }
            }
            else
            {
                A_B8_BIT2(gbf, container_id, id_buf, 1, 8, "reserved for operator specific use");
            }
            len -= 1;
            SKIP(1);

            int len_con = -1;
            B8_HEX();
            B8_BIT(len_con, 1, 8);
            A_B8_BIT1(gbf, length_of_container_id_contents, len_buf, 1, 8);
            SKIP(1);

            len -= len_con;
            while(len_con > 0)
            {
                B8_HEX();
                B8_BIT(tmp, 1, 8);
                A_B8_BIT1(gbf, contentsontainer_id_contents, content_buf, 1, 8);
                len_con -= 1;
                SKIP(1);
            }

        }      
        ID++;
    }
#endif
    END_ELEMENT();
}

void request_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Request type", request_type);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "initial request");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "Handover");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "Unused. If received, the network shall interpret this as \"initial request\".");
            }
            else if(tmp == 4)
            {                
                A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "emergency");
            }
            else
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "reserved");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            B8_BIT(tmp, 5, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 5, 7, "initial request");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 5, 7, "Handover");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 5, 7, "Unused. If received, the network shall interpret this as \"initial request\".");
            }
            else if(tmp == 4)
            {                
                A_B8_BIT2(gbf, request_type_value, "Request type value", 5, 7, "emergency");
            }
            else
            {
                A_B8_BIT2(gbf, request_type_value, "Request type value", 5, 7, "reserved");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, request_type_iei, "Request type IEI", 5, 8, "Request type");
        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        B8_BIT(tmp, 1, 3);
        if(tmp == 1)
        {
            A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "initial request");
        }
        else if(tmp == 2)
        {
            A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "Handover");
        }
        else if(tmp == 3)
        {
            A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "Unused. If received, the network shall interpret this as \"initial request\".");
        }
        else if(tmp == 4)
        {                
            A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "emergency");
        }
        else
        {
            A_B8_BIT2(gbf, request_type_value, "Request type value", 1, 3, "reserved");
        }
        SKIP(1);
    }
    END_ELEMENT();
}
/*
void  packet_flow_identifier(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Packet Flow Identifier", packet_flow_identifier);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, packet_flow_identifier_iei, "Packet Flow Identifier IEI", 1, 8, "Packet Flow Identifier");
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, length_of_packet_flow_identifier_ie, "Length of Packet Flow Identifier IE", 1, 8);
    SKIP(1);

    int tmp = -1;
    B8_HEX();
    A_B8_BIT1(gbf, spare, "spare", 8, 8);
    B8_BIT(tmp, 1, 7);
    if(tmp == 0)
    {
        A_B8_BIT2(gbf, packet_flow_identifier_value, "Packet Flow Identifier value", 1, 7, "Best Effort");
    }
    else if(tmp == 1)
    {
        A_B8_BIT2(gbf, packet_flow_identifier_value, "Packet Flow Identifier value", 1, 7, "Signaling");
    }
    else if(tmp == 2)
    {
        A_B8_BIT2(gbf, packet_flow_identifier_value, "Packet Flow Identifier value", 1, 7, "SMS");   
    }
    else if(tmp == 3)
    {
        A_B8_BIT2(gbf, packet_flow_identifier_value, "Packet Flow Identifier value", 1, 7, "TOM8");
    }
    else if(tmp >= 4 && tmp <= 7)
    {
        A_B8_BIT2(gbf, packet_flow_identifier_value, "Packet Flow Identifier value", 1, 7, "reserved");
    }
    else if(tmp >= 8 && tmp <= 177)
    {
        A_B8_BIT2(gbf, packet_flow_identifier_value, "Packet Flow Identifier value", 1, 7, "dynamically assigned");
    }
    
    SKIP(1);
    END_ELEMENT();
}
*/
void sm_cause_2(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("SM cause 2", sm_cause_2);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, sm_cause_2_iei, "SM cause 2 IEI", 1, 8, "SM cause 2");
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, length_of_sm_cause_2_contents, "Length of SM cause 2 contents", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(gbf, sm_cause_2_value, "SM cause 2 value", 1, 8);
    SKIP(1);
    END_ELEMENT();
}

void connectivity_type(uint8_t iei, uint8_t location)
{
    int tmp = -1;
	BEGIN_ELEMENT("Connectivity type", connectivity_type);
	if(iei == 0)
	{
		int tmp = -1;
		if(location == 1)
		{
			B8_BIT(tmp, 1, 4);
			if(tmp == 0)
			{
				A_B8_BIT2(gbf, connectivity_type_value, "Connectivity type value", 1, 4, "The PDN connection type is not indicated");
			}
			else
			{
				A_B8_BIT2(gbf, connectivity_type_value, "Connectivity type value", 1, 4, "The PDN connection is considered a LIPA PDN connection");
			}
			SKIP(1);
		}
		else
		{
			B8_HEX();
			B8_BIT(tmp, 5, 8);
			if(tmp == 0)
			{
				A_B8_BIT2(gbf, connectivity_type_value, "Connectivity type value", 5, 8, "The PDN connection type is not indicated");
			}
			else
			{
				A_B8_BIT2(gbf, connectivity_type_value, "Connectivity type value", 5, 8, "The PDN connection is considered a LIPA PDN connection");
			}
		}
	}
	else
	{
		B8_HEX();
		A_B8_BIT2(gbf, connectivity_type_iei, "Connectivity type IEI", 5, 8, "Connectivity type");
		B8_BIT(tmp, 1, 4);
		if(tmp == 0)
		{
			A_B8_BIT2(gbf, connectivity_type_value, "Connectivity type value", 1, 4, "The PDN connection type is not indicated");
		}
		else
		{
			A_B8_BIT2(gbf, connectivity_type_value, "Connectivity type value", 1, 4, "The PDN connection is considered a LIPA PDN connection");
		}
		SKIP(1);
	}
	END_ELEMENT();
}

void wlan_offload_acceptability(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("WLAN offload acceptability", wlan_offload_acceptability);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 4, 4);
            A_B8_BIT1(gbf, spare, "spare", 3, 3);
            B8_BIT(tmp, 2, 2);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, utran_offload_acceptability_value, "UTRAN offload acceptability value", 2, 2, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is not acceptable");
            }
            else
            {
                A_B8_BIT2(gbf, utran_offload_acceptability_value, "UTRAN offload acceptability value", 2, 2, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is acceptable");
            }

            B8_BIT(tmp, 1, 1);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, eutran_offload_acceptability_value, "E-UTRAN offload acceptability value", 1, 1, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is not acceptable");
            }
            else
            {
                A_B8_BIT2(gbf, eutran_offload_acceptability_value, "E-UTRAN offload acceptability value", 1, 1, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is acceptable");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 8, 8);
            A_B8_BIT1(gbf, spare, "spare", 7, 7);
            B8_BIT(tmp, 2, 2);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, utran_offload_acceptability_value, "UTRAN offload acceptability value", 6, 6, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is not acceptable");
            }
            else
            {
                A_B8_BIT2(gbf, utran_offload_acceptability_value, "UTRAN offload acceptability value", 6, 6, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is acceptable");
            }

            B8_BIT(tmp, 1, 1);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, eutran_offload_acceptability_value, "E-UTRAN offload acceptability value", 5, 5, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is not acceptable");
            }
            else
            {
                A_B8_BIT2(gbf, eutran_offload_acceptability_value, "E-UTRAN offload acceptability value", 5, 5, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is acceptable");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, wlan_offload_acceptability_iei, "WLAN offload acceptability IEI", 5, 8, "WLAN offload acceptability");
        A_B8_BIT1(gbf, spare, "spare", 4, 4);
        A_B8_BIT1(gbf, spare, "spare", 3, 3);
        B8_BIT(tmp, 2, 2);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, utran_offload_acceptability_value, "UTRAN offload acceptability value", 2, 2, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is not acceptable");
        }
        else
        {
            A_B8_BIT2(gbf, utran_offload_acceptability_value, "UTRAN offload acceptability value", 2, 2, "Offloading the traffic of the PDN connection via a WLAN when in Iu mode is acceptable");
        }

        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, eutran_offload_acceptability_value, "E-UTRAN offload acceptability value", 1, 1, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is not acceptable");
        }
        else
        {
            A_B8_BIT2(gbf, eutran_offload_acceptability_value, "E-UTRAN offload acceptability value", 1, 1, "Offloading the traffic of the PDN connection via a WLAN when in S1 mode is acceptable");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void sm_cause(uint8_t iei, uint8_t location)
{
    int  tmp = -1;
    BEGIN_ELEMENT("SM Cause", sm_cause);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, sm_cause_iei, "SM cause IEI", 1, 8, "SM cause");
        SKIP(1);
    }

    B8_HEX();
    B8_BIT(tmp, 1, 8);
    if(tmp == 8 || (tmp >= 24 && tmp <= 48) || tmp == 50 || tmp == 51 || tmp == 52 || tmp == 56 || tmp == 60 || tmp == 65 || tmp == 66 || tmp == 81 || tmp == 95 || tmp == 96 || tmp == 97 || tmp == 98 || tmp == 99 || tmp == 100 || tmp == 101 || tmp == 111 || tmp == 112)
    {
        A_B8_BIT3(gbf, cause_value, "Cause value", 1, 8, cause_value_dict);
    }
    else
    {
        A_B8_BIT2(gbf, cause_value, "Cause value", 1, 8, "Protocol error, unspecified");
    }
    SKIP(1);
    END_ELEMENT();
}

void linked_ti(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Linked TI", linked_ti);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, linked_ti_iei, "Linked TI IEI", 1, 8, "Linked TI");
        SKIP(1);
    }

    if(location == 1)
    {
        B8_HEX();
        A_B8_BIT1(gbf, length_of_linked_ti_ie, "Length of Linked TI IE", 1, 8);
        SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(gbf, ti_flag, "TI flag", 8, 8);
    A_B8_BIT1(gbf, ti_value, "TI value", 5, 7);
    A_B8_BIT1(gbf, spare, "spare", 1, 4);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(gbf, ext, "1 EXT", 8, 8);
    A_B8_BIT1(gbf, ti_value, "TI value", 1, 7);
    SKIP(1);

    END_ELEMENT();
}

//TO DO
void traffic_flow_template(uint8_t iei, uint8_t location)
{
    int tmp = -1;
    int num = -1;
    int sum_len = -1;
    int operation = -1;

    BEGIN_ELEMENT("Traffic Flow Template", traffic_flow_template);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, traffic_flow_template_iei, "Traffic flow template IEI", 1, 8, "Traffic flow template");
        SKIP(1);
    }

    if(location == 1)
    {
        B8_HEX();
        B8_BIT(sum_len, 1, 8);
        A_B8_BIT1(gbf, length_of_traffic_flow_template_ie, "Length of traffic flow template IE", 1, 8);
        SKIP(1);
    }

    int  Ebit = -1;
    if(sum_len > 0 )
    {
        B8_HEX();
        B8_BIT(operation, 6, 8);
        A_B8_BIT3(gbf, tft_operation_code, "TFT operation code", 6, 8, tft_operation_dict);
        B8_BIT(Ebit, 5, 5);
        if(Ebit == 0)
        {
            A_B8_BIT2(gbf, e_bit, "E bit", 5, 5, "parameters list is not included");
        }
        else
        {
            A_B8_BIT2(gbf, e_bit, "E bit", 5, 5, "parameters list is included");   
        }

        B8_BIT(num, 1, 4);
        A_B8_BIT1(gbf, number_of_packet_filters, "Number of packet filters", 1, 4);
        sum_len -= 1;
        SKIP(1);
    }
    int i = 0;
    int j = 0;
    if(operation == 5)
    {
        for(i = 0; i < num; i++)
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 5, 8);
            A_B8_BIT1(gbf, Packet_filter_identifier, "Packet filter identifier", 1, 4);
            sum_len -= 1;
            SKIP(1);
        }
    }
    else if(operation == 1 || operation == 3 || operation == 4)
    {
        int abc = -1;
        for(i = 0; i < num; i++)
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 7, 8);

            B8_BIT(abc, 5, 6);
            if(abc == 0)
            {
                A_B8_BIT2(gbf, packet_filter_direction, "Packet filter direction", 5, 6, "pre Rel-7 TFT filter");
            }
            else if(abc == 1)
            {
                A_B8_BIT2(gbf, packet_filter_direction, "Packet filter direction", 5, 6, "downlink only");
            }
            else if(abc == 2)
            {
                A_B8_BIT2(gbf, packet_filter_direction, "Packet filter direction", 5, 6, "uplink only");
            }
            else if(abc == 3)
            {
                A_B8_BIT2(gbf, packet_filter_direction, "Packet filter direction", 5, 6, "bidirectional");
            }
            
            A_B8_BIT1(gbf, Packet_filter_identifier, "Packet filter identifier", 1, 4);
            sum_len -= 1;
            SKIP(1);

            B8_HEX();
            A_B8_BIT1(gbf, packet_filter_evaluation_precedence, "Packet filter evaluation precedence", 1, 8);
            sum_len -= 1;
            SKIP(1);

	    if(location == 1)
	    {
		    B8_HEX();
		    B8_BIT(len, 1, 8);
		    A_B8_BIT1(gbf, length_of_packet_filter_contents, "Length of Packet filter contents", 1, 8);
		    sum_len -= 1;
		    SKIP(1);
	    }
            for(j = 0; j < len; j++)
            {
                B8_HEX();
                B8_BIT(tmp, 1, 8);
                if(tmp == 16)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "IPv4 remote address type");
                }
                else if(tmp == 17)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "IPv4 local address type");
                }
                else if(tmp == 32)
                {
                   A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "IPv6 remote address type"); 
                }
                else if(tmp == 33)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "IPv6 remote address/prefix length type");    
                }
                else if(tmp == 35)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "IPv6 local address/prefix length type"); 
                }
                else if(tmp == 48)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Protocol identifier/Next header type"); 
                }
                else if(tmp == 64)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Single local port type"); 
                }
                else if(tmp == 65)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Local port range type"); 
                }
                else if(tmp == 80)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Single remote port type"); 
                }
                else if(tmp == 81)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Remote port range type"); 
                }
                else if(tmp == 96)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Security parameter index type"); 
                }
                else if(tmp == 112)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Type of service/Traffic class type"); 
                }
                else if(tmp == 128)
                {
                    A_B8_BIT2(gbf, packet_filter_contents, "Packet filter contents", 1, 8, "Flow label type"); 
                }
                sum_len -= 1;
                SKIP(1);
            }
        }

        if(Ebit == 1)
        {
            while(sum_len > 0)
            {                
                B8_HEX();
                B8_BIT(tmp, 1, 8);
                if(tmp ==  0x01)
                {
                    A_B8_BIT2(gbf, parameter_identifier, "Parameter identifier", 1, 8, "Authorization Token");
                }
                else if(tmp == 0x02)
                {
                    A_B8_BIT2(gbf, parameter_identifier, "Parameter identifier", 1, 8, "Flow Identifier)");
                }
                else if(tmp == 0x03)
                {
                    A_B8_BIT2(gbf, parameter_identifier, "Parameter identifier", 1, 8, "Packet Filter Identifier");
                }
                else
                {
                    A_B8_BIT2(gbf, parameter_identifier, "Parameter identifier", 1, 8, "unknown");    
                }
                sum_len -= 1;
                SKIP(1);
                if(sum_len > 0)
                {
                    B8_HEX();
                    B8_BIT(len, 1, 8);
                    A_B8_BIT1(gbf, length_of_parameter_contents, "Length of Parameter contents", 1, 8);
                    sum_len -= 1;
                    SKIP(1);

                    sum_len -= len;
                    while(len > 0)
                    {
                        B8_HEX();
                        A_B8_BIT1(gbf, parameter_contents, "Parameter contents", 1, 8);
                        len -= 1;
                        SKIP(1);
                    }
                }
            }
        }
    }
    END_ELEMENT();
}

void tear_down_indicator(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Tear down indicator", tear_down_indicator);
    int tmp = -1;
    if(iei == 0)
    {
        if(location == 1)
        {
            A_B8_BIT1(gbf, spare, "spare", 2, 4);
            B8_BIT(tmp, 1, 1);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, tdi_flag, "TDI flag", 1, 1, "tear down not requested");
            }
            else
            {
                A_B8_BIT2(gbf, tdi_flag, "TDI flag", 1, 1, "tear down requested");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(gbf, spare, "spare", 6, 8);
            B8_BIT(tmp, 5, 5);
            if(tmp == 0)
            {
                A_B8_BIT2(gbf, tdi_flag, "TDI flag", 5, 5, "tear down not requested");
            }
            else
            {
                A_B8_BIT2(gbf, tdi_flag, "TDI flag", 5, 5, "tear down requested");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(gbf, tear_down_indicator_iei, "Tear down indicator IEI", 5, 8, "Tear down indicator");
        A_B8_BIT1(gbf, spare, "spare", 2, 4);
        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT2(gbf, tdi_flag, "TDI flag", 1, 1, "tear down not requested");
        }
        else
        {
            A_B8_BIT2(gbf, tdi_flag, "TDI flag", 1, 1, "tear down requested");
        }
        SKIP(1);
    }
    END_ELEMENT();
}

void mbms_protocol_configuration_options(uint8_t iei, uint8_t location)
{
    int len = 0;
    BEGIN_ELEMENT("MBMS protocol configuration options", mbms_protocol_configuration_options);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, mbms_protocol_configuration_options_iei, "MBMS protocol configuration options IEI", 1, 8, "MBMS protocol configuration options");
        SKIP(1);
    }

    if(location == 1)
    {
        B8_HEX();
        B8_BIT(len, 1, 8);
        A_B8_BIT1(gbf, length_of_mbms_protocol_configuration_options_contents, "Length of MBMS protocol configuration options contents", 1, 8);
        SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, spare, "spare", 1, 8);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void enhanced_network_service_access_point_identifier(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Enhanced network service access point identifier", enhanced_network_service_access_point_identifier);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, Enhandced_nsapi_iei, "Enhanced NSAPI IEI", 1, 8, "Enhanced NSAPI");
        SKIP(1);
    }

    int tmp = -1;
    char buf[256] = {0};
    B8_BIT(tmp, 1, 8);
    if(0 <= tmp && tmp <= 127)
    {
        A_B8_BIT2(gbf, Enhandced_nsapi_value, "Enhanced NSAPI Value", 1, 8, "Reserved");
    }
    else if(128 <= tmp && tmp <= 254)
    {
        //bzero(buf, 256);
        memset(buf, 0x00, 256);
        sprintf(buf, "NSAPI 128 for Multimedia Broadcast/Multicast Service (MBMS) Multicast mode", tmp);
        A_B8_BIT2(gbf, Enhandced_nsapi_value, "Enhanced NSAPI Value", 1, 8, buf);
    }
    else if(tmp == 255)
    {
        A_B8_BIT2(gbf, Enhandced_nsapi_value, "Enhanced NSAPI Value", 1, 8, "Reserved (NOTE)");
    }
    SKIP(1);

    END_ELEMENT();
}

void  mbms_bearer_capabilities(uint8_t iei, uint8_t location)
{
    int len = -1;
    BEGIN_ELEMENT("MBMS bearer capabilities", mbms_bearer_capabilities);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, mbms_bearer_capabilities_iei, "MBMS bearer capabilities IEI", 1, 8, "MBMS bearer capabilities");
        SKIP(1);
    }

    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_mbms_bearer_capabilities_ie, "Length of MBMS bearer capabilities IE", 1, 8);
	    SKIP(1);
    }
    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, maximum_bit_rate_for_downlink,  "Maximum bit rate for downlink", 1, 8);
        len -= 1;
        SKIP(1);
    }
    
    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, maximum_bit_rate_for_downlink_extended,  "Maximum bit rate for downlink (extended)", 1, 8);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void temporary_mobile_group_identity(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Temporary Mobile Group Identity", temporary_mobile_group_identity);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(gbf, temporary_mobile_group_identity_iei, "Temporary Mobile Group Identity IEI", 1, 8, "Temporary Mobile Group Identity");
        SKIP(1);
    }

    int len = 0;
    if(location == 1)
    {
	    B8_HEX();
	    B8_BIT(len, 1, 8);
	    A_B8_BIT1(gbf, length_of_temporary_mobile_group_identity_contents, "Length of Temporary Mobile Group Identity contents", 1, 8);
	    SKIP(1);
    }
    int id_sum = 0;
    int id = 0;
    char buf[16] = {0};
    if(len > 0)
    {
        B8_HEX();
        B8_BIT(id, 1, 8);
        id_sum = id;
        A_B8_BIT2(gbf, mbms_service_id, "MBMS Service ID", 1, 8, "-");
        len -= 1;
        SKIP(1);
    }
        
    if(len > 0)
    {
        B8_HEX();
        B8_BIT(id, 1, 8);
        id_sum += id;
        A_B8_BIT2(gbf, mbms_service_id, "MBMS Service ID", 1, 8, "-");
        len -= 1;
        SKIP(1);
    }
        
    if(len > 0)
    {
        B8_HEX();
        B8_BIT(id, 1, 8);
        //bzero(buf, 16);
        memset(buf, 0x00, 16);
        id_sum += id;
        //spare(buf, "%02x", id_sum);
        sprintf(buf, "%02x", id_sum);
        A_B8_BIT2(gbf, mbms_service_id, "MBMS Service ID", 1, 8, buf);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, mcc_digit_2, "MCC digit 2", 5, 8);
        A_B8_BIT1(gbf, mcc_digit_1, "MCC digit 1", 1, 4);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, mcc_digit_2, "MNC digit 2", 5, 8);
        A_B8_BIT1(gbf, mcc_digit_1, "MCC digit 3", 1, 4);
        len -= 1;
        SKIP(1);
    }
     
    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(gbf, mcc_digit_2, "MNC digit 2", 5, 8);
        A_B8_BIT1(gbf, mcc_digit_1, "MNC digit 1", 1, 4);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}
#endif

