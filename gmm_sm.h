#ifndef __NEW_H__
#define __NEW_H__

#include "nbe_common.h"

void auxiliary_states(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Auxiliary states", auxiliary_states); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, auxiliary_states_iei, "Auxiliary states IEI", 1, 8, "Auxiliary states");  
        SKIP(1); 
    }    

    int len = -1;
    B8_HEX(); 
    B8_BIT(len, 1, 8);
    A_B8_BIT1(c3f, auxiliary_states_length, "Length of Auxiliary states contents", 1, 8);
    SKIP(1); 

    if(len > 0)
    {
        A_B8_BIT1(c3f, ext, "ext", 8, 8);
        A_B8_BIT1(c3f, spare, "spare", 5, 7);
        A_B8_BIT3(c3f, hold_auxiliary_state, "Hold auxiliary state", 3, 4, auxiliary_states_hold_auxiliary_state);
        A_B8_BIT3(c3f, multi_party_auxiliary_state, "Multi party auxiliary state", 1, 2, auxiliary_states_multi_party_a_s);
        SKIP(1); 
    }

    END_ELEMENT(); 
}

/*************************************************/
void ms_network_capability(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("MS network capability", ms_network_capability); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, , "MS network capability IEI", 1, 8, "MS network capability");  
        SKIP(1); 
    }    

    int len = -1;
    B8_HEX();
    B8_BIT(len, 1, 8);
    A_B8_BIT1(c3f, ms_network_capability_length, "Length of MS network capability contents", 1, 8);
    SKIP(1);

    if(len > 0)
    {
        A_B8_BIT3(c3f, revision_level_indicator, "Revision level indicator", 8, 8, ms_network_capability_revision_level_indicator);
        A_B8_BIT3(c3f, solsa_capbility, "SoLSA Capability", 7, 7, ms_network_capability_solsa_capbility);
        A_B8_BIT3(c3f, ss_screening_indicator, "SS Screening Indicator", 5, 6, ms_network_capability_ss_screening_indicator);
        A_B8_BIT3(c3f, ucs2_support, "UCS2 support", 4, 4, ms_network_capability_ucs2_support);
        A_B8_BIT3(c3f, sm_capabilities_via_gprs_channels, "SM capabilities via GPRS channels", 3, 3, ms_network_capability_sm_capabilities_via_gprs_channels);
        A_B8_BIT3(c3f, sm_capabilities_via_dedicated_channels, "SM capabilities via dedicated channels", 2, 2, ms_network_capability_sm_capabilities_via_dedicated_channels);
        A_B8_BIT1(c3f, gea1, "GEA1", 1, 1);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        A_B8_BIT3(c3f, rfc_feature_mode, "PFC feature mode", 8, 8, ms_network_capability_rfc_feature_mode);
        A_B8_BIT1(c3f, gea7, "GEA/7", 7, 7);
        A_B8_BIT1(c3f, gea6, "GEA/6", 6, 6);
        A_B8_BIT1(c3f, gea5, "GEA/5", 5, 5);
        A_B8_BIT1(c3f, gea4, "GEA/4", 4, 4);
        A_B8_BIT1(c3f, gea3, "GEA/3", 3, 3);
        A_B8_BIT1(c3f, gea2, "GEA/2", 2, 2);
        A_B8_BIT3(c3f, lcs_va_capability, "LCS VA capability", 1, 1, ms_network_capability_lcs_va_capability);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        A_B8_BIT3(c3f, ps_inter_ho_from_grean_to_utran_iu_mode_cap, "PS inter-RAT HO from GERAN to UTRAN Iu mode capability", 8, 8, ms_network_capability_ps_inter_ho_from_grean_to_utran_iu_mode_cap);
        A_B8_BIT3(c3f, ps_inter_ho_from_grean_to_eutran_s1_mode_cap, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode capability", 7, 7, ms_network_capability_ps_inter_ho_from_grean_to_eutran_s1_mode_cap);
        A_B8_BIT3(c3f, emm_combined_procedures_capability, "EMM Combined procedures Capability", 6, 6, ms_network_capability_emm_combined_procedures_capability);
        A_B8_BIT3(c3f, isr_support, "ISR support", 5, 5, ms_network_capability_isr_support);
        A_B8_BIT3(c3f, srvcc_to_geran_utran_capability, "SRVCC to GERAN/UTRAN capability", 4, 4, ms_network_capability_srvcc_to_geran_utran_capability);
        A_B8_BIT3(c3f, epc_capability, "EPC capability", 3, 3, ms_network_capability_epc_capability);
        A_B8_BIT3(c3f, nf_capability, "NF capability", 2, 2, ms_network_capability_nf_capability);
        A_B8_BIT3(c3f, geran_network_sharing_capability, "GERAN network sharing capability", 1, 1, ms_network_capability_geran_network_sharing_capability);
        SKIP(1);
    }
    END_ELEMENT(); 
}

struct code2dict ms_network_capability_revision_level_indicator[]= 
{
    {0, "used by a mobile station not supporting R99 or later versions of the protocol"},
    {1, "used by a mobile station supporting R99 or later versions of the protocol"},
};

struct code2dict ms_network_capability_solsa_capbility[]= 
{
    {0, "The ME does not support SoLSA"},
    {1, "The ME supports SoLSA"},
};

struct code2dict ms_network_capability_ss_screening_indicator[]= 
{
    {0, "defined in 3GPP TS 24.080 [24]"},
    {1, "defined in 3GPP TS 24.080 [24]"},
    {2, "defined in 3GPP TS 24.080 [24]"},
    {3, "defined in 3GPP TS 24.080 [24]"},
};

struct code2dict ms_network_capability_ucs2_support[]= 
{
    {0, "the ME has a preference for the default alphabet (defined in 3GPP TS 23.038 [8b]) over UCS2."},
    {1, "the ME has no preference between the use of the default alphabet and the use of UCS2."},
};

struct code2dict ms_network_capability_sm_capabilities_via_dedicated_channels[]= 
{
    {0, "Mobile station does not support mobile terminated point to point SMS via CS domain"},
    {1, "Mobile station supports mobile terminated point to point SMS via CS domain"},
};

struct code2dict ms_network_capability_rfc_feature_mode[]= 
{
    {0, "Mobile station does not support BSS packet flow procedures"},
    {1, "Mobile station does support BSS packet flow procedures"},
};

struct code2dict ms_network_capability_lcs_va_capability[]= 
{
    {0, "location request notification via PS domain not supported"},
    {1, "location request notification via PS domain supported"},
};

struct code2dict ms_network_capability_ps_inter_ho_from_grean_to_utran_iu_mode_cap[]= 
{
    {0, "PS inter-RAT HO from GERAN to UTRAN Iu mode not supported"},
    {1, "PS inter-RAT HO from GERAN to UTRAN Iu mode supported"},
};

struct code2dict ms_network_capability_ps_inter_ho_from_grean_to_eutran_s1_mode_cap[]= 
{
    {0, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode not supported"},
    {1, "PS inter-RAT HO from GERAN to E-UTRAN S1 mode supported"},
};

struct code2dict ms_network_capability_emm_combined_procedures_capability[]= 
{
    {0, "Mobile station does not support EMM combined procedures"},
    {1, "Mobile station supports EMM combined procedures"},
};

struct code2dict ms_network_capability_isr_support[]= 
{
    {0, "The mobile station does not support ISR."},
    {1, "The mobile station supports ISR."},
};

struct code2dict ms_network_capability_srvcc_to_geran_utran_capability[]= 
{
    {0, "SRVCC from UTRAN HSPA or E-UTRAN to GERAN/UTRAN not supported"},
    {1, "SRVCC from UTRAN HSPA or E-UTRAN to GERAN/UTRAN supported"},
};

struct code2dict ms_network_capability_epc_capability[]= 
{
    {0, "EPC not supported"},
    {1, "EPC supported"},
};

struct code2dict ms_network_capability_nf_capability[]= 
{
    {0, "Mobile station does not support the notification procedure."},
    {1, "Mobile station supports the notification procedure."},
};

struct code2dict ms_network_capability_geran_network_sharing_capability[]= 
{
    {0, "Mobile station does not support GERAN network sharing."},
    {1, "Mobile station supports GERAN network sharing."},
};
/*************************************************/
void attach_type(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Attach type", attach_type); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, attach_type_iei, "Attach type IEI", 5, 8, "Attach type"); 
        A_B8_BIT3(c3f, follow_on_request , "Follow-on request ", 4, 4, attach_type_follow_on_request);
        A_B8_BIT3(c3f, type_of_attach , "Type of attach",  1, 3, attach_type_type_of_attach);
        SKIP(1); 
    }    
    END_ELEMENT(); 
}

struct code2dict attach_type_follow_on_request[]= 
{
    {0, "No follow-on request pending"},
    {1, "Follow-on request pending"},
};

struct code2dict attach_type_type_of_attach[]= 
{
    {0, "GPRS attach"},
    {1, "Not used. This value was allocated in earlier versions of the protocol (Note1)}"
    {2, "Combined GPRS/IMSI attach"},
    {3, "Emergency attach"},
};
/*****************************/
/*************************************************/
void drx_paramete(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("DRX paramete", drx_paramete); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, drx_paramete_iei, "DRX parameter IEI", 1, 8, "DRX parameter");  
        SKIP(1); 
    }       


    B8_HEX();
    int  code = -1;
    B8_BIT(code, 1, 8);
    if(code == 0)
    {
        A_B8_BIT2(c3f, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "704 (equivalent to no DRX)");
    }
    else if(code >= 1 && code <= 64)
    {
        A_B8_BIT1(c3f, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8);
    }
    else if(code >= 65 && code <= 98)
    {
        A_B8_BIT2(c3f, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, drx_paramete_split_pg_cycle_code);
    }
    else 
    {
        A_B8_BIT2(c3f, split_pg_cycle_code, "SPLIT PG CYCLE CODE", 1, 8, "reserved");
    }
    SKIP(1);

    B8_HEX();
    int tmp = -1;
    B8_BIT(tmp, 5, 8);
    if(tmp == 0 || tmp == 6 || tmp == 8 || tmp == 9)
    {
        A_B8_BIT3(c3f, cn_drx_cycle_len_drx , "CN Specific DRX cycle length coefficient and DRX value for S1 mode",  5, 8, drx_paramete_cn_drx_cycle_len_drx);
    }
    else
    {
        A_B8_BIT2(c3f, cn_drx_cycle_len_drx , "CN Specific DRX cycle length coefficient and DRX value for S1 mode",  5, 8, "CN Specific DRX cycle length coefficient not specified by the MS, DRX value not specified by the MS by this version of the protocol.");
    }

    int tmp = -1;
    B8_BIT(tmp, 4, 4);
    if(tmp == 0)
    {
        A_B8_BIT2(c3f, split_on_ccch , "SPLIT on CCCH", 4, 4, "Split pg cycle on CCCH is not supported by the mobile station");
    }
    else
    {
        A_B8_BIT2(c3f, split_on_ccch , "SPLIT on CCCH", 4, 4, "Split pg cycle on CCCH is supported by the mobile station")
    }

    A_B8_BIT3(c3f, non_drx_timer , "non-DRX timer", 1, 3, drx_paramete_non_drx_timer);
    SKIP(1); 

    END_ELEMENT(); 
}

struct code2dict drx_paramete_split_pg_cycle_code[]= 
{
    {65,  "71"},
    {66,  "72"},
    {67,  "74"},
    {68,  "75"},
    {69,  "77"},
    {70,  "79"},
    {71,  "80"},
    {72,  "83"},
    {73,  "86"},
    {74,  "88"},
    {75,  "90"},
    {76,  "92"},
    {77,  "96"},
    {78,  "101"},
    {79,  "103"},
    {80,  "107"},
    {81,  "112"},
    {82,  "116"},
    {83,  "118"},
    {84,  "128"},
    {85,  "141"},
    {86,  "144"},
    {87,  "150"},
    {88,  "160"},
    {89,  "171"},
    {90,  "176"},
    {91,  "192"},
    {92,  "214"},
    {93,  "224"},
    {94,  "235"},
    {95,  "256"},
    {96,  "288"},
    {97,  "320"},
    {98,  "352"},
};

struct code2dict drx_paramete_split_pg_cycle_code[]= 
{
    {0,   "For Iu mode, CN Specific DRX cycle length coefficient not specified by the MS, ie. the system information value 'CN domain specific DRX cycle length' is used . For S1 mode, DRX value not specified by the MS."},
    {6,   "CN Specific DRX cycle length coefficient 6 and T = 32"},
    {7,   "CN Specific DRX cycle length coefficient 7 and T = 64"},
    {8,   "CN Specific DRX cycle length coefficient 8 and T = 128"},
}
struct code2dict drx_paramete_non_drx_timer[]= 
{
    {0,  "no non-DRX mode after transfer state"},
    {1,  "max.  1 sec non-DRX mode after transfer state"},
    {2,  "max.  2 sec non-DRX mode after transfer state"},
    {3,  "max.  4 sec non-DRX mode after transfer state"},
    {4,  "max.  8 sec non-DRX mode after transfer state"},
    {5,  "max. 16 sec non-DRX mode after transfer state"},
    {6,  "max. 32 sec non-DRX mode after transfer state"},
    {7,  "max. 64 sec non-DRX mode after transfer state"},
}
/*****************************/
/*************************************************/
void (uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("", ); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, , "", 1, 8, "");  
        SKIP(1); 
    }    

    int len = -1;
    B8_HEX(); 
    B8_BIT(len, 1, 8);
    A_B8_BIT1(c3f, auxiliary_states_length, "Length of Auxiliary states contents", 1, 8);
    SKIP(1); 

    if(len > 0)
    {

    }
    END_ELEMENT(); 
}

struct code2dict []= 
{
    {0, ""},
    {1, ""},
};
/*****************************/
/*************************************************/

void p_tmsi_signature(uint8_t iei, uint8_t location)
{
        int t,i;
        BEGIN_ELEMENT("P-TMSI signature", p_tmsi_signature);
        if(iei==1)
        {
            B8_HEX();
            A_B8_BIT2(c3f, p_tmsi_signature_iei, "P-TMSI signature IEI", 1, 8, "P-TMSI signature");
            SKIP(1);
        }
     
        int sum = -1;
        int t = -1;
        B8_HEX();
        B8_BIT(t, 1, 8);
        sum = t;
        SKIP(1);

        B8_HEX();
        B8_BIT(t, 1, 8);
        sum = sum * 255 + t;
        SKIP(1);

        B8_HEX();
        B8_BIT(t, 1, 8);
        sum = sum * 255 + t;
            
        char buf[100];
        memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "%d", sum);
        A_B8_BIT2(c3f, p_tmsi_signature_value, "P-TMSI signature value", buf);
        SKIP(1);

        END_ELEMENT();
}

void gprs_timer(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("GPRS Timer", gprs_timer); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, gprs_timer_iei, 1, 8, "GPRS Timer IEI");  
        SKIP(1); 
    }    

    B8_HEX();
    int tmp = -1;
    B8_BIT(tmp, 6, 8);
    if(tmp == 0 || tmp == 1 || tmp == 2 || tmp == 7)
    {
        A_B8_BIT3(c3f, unit, "Unit", 6, 8, gprs_timer_unit);
    }
    else
    {
        A_B8_BIT2(c3f, unit, "Unit", 6, 8, "multiples of 1 minute in this version of the protocol.");
    }

    A_B8_BIT1(c3f, timer_value, "Timer value", 1, 5);
    SKIP(1); 
    END_ELEMENT(); 
}

struct code2dict gprs_timer_unit[]
{
    {0,  "value is incremented in multiples of 2 seconds"},
    {1,  "value is incremented in multiples of 1 minute"},
    {2,  "value is incremented in multiples of decihours"},
    {7,  "value indicates that the timer is deactivated."},
};

void tmsi_status(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("TMSI status", tmsi_status); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, tmsi_status_iei, 5, 8, "TMSI status IEI");
        A_B8_BIT2(c3f, tmsi_status_spare, 2, 4, "spare");
        B8_BIT(tmp, 1, 1);
        if(tmp == 0)
        {
            A_B8_BIT2(c3f, tmsi_status_spare, 1, 1, "no valid TMSI available");
        }
        else
        {
            A_B8_BIT2(c3f, tmsi_status_spare, 1, 1, "valid TMSI available");
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
        A_B8_BIT2(c3f, ps_lcs_capability_iei, 1, 8, "PS LCS Capability IEI");
        SKIP(1);
    }

    int len = -1;
    B8_BIT(len, 1, 8);
    if(len > 0)
    {
        A_B8_BIT2(c3f, ps_lcs_capability_length, 1, 8, "Length of PS LCS Capability contents");
        len -= 1;
        SKIP(1);
    }
    
    B8_HEX();
    A_B8_BIT2(c3f, spare, 7, 8, "Spare");

    for(i = 0; i  < 6; i--)
    {
        B8_BIT(tmp, i, i);
        if(tmp == 0)
        {
            A_B8_BIT3(c3f, capability_o, i, i, ps_lcs_capability_o);
        }
        else
        {
            A_B8_BIT3(c3f, capability_i, i, i, ps_lcs_capability_i);
        }
    }    
    SKIP(1);

    END_ELEMENT();
}

struct code2dict ps_lcs_capability_o[]= 
{
    {6, "Additional Positioning Capabilities which can be retrieved by RRLP are not supported"},
    {5, "MS assisted E-OTD not supported"},
    {4, "MS based E-OTD not supported"},
    {3, "MS assisted GPS not supported"},
    {2, "MS based GPS not supported"}, 
    {1, "Conventional GPS not supported "},
};
struct code2dict ps_lcs_capability_i[]= 
{
    {6, "Additional Positioning Capabilities which can be retrieved by RRLP are supported"},
    {5, "MS assisted E-OTD supported"},
    {4, "MS based E-OTD supported"},
    {3, "MS assisted GPS supported"},
    {2, "MS based GPS supported"},
    {1, "Conventional GPS supported"},
};

//TO DO
void mobile_station_classmark_3(uint8_t iei, uint8_t location)
{

}


void  ue_network_capability(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("UE network capability", ue_network_capability);
    if(iei == 1)
    {
    B8_HEX();
        A_B8_BIT2(c3f, ue_network_capability_iei, "UE network capability", 1, 8, "UE network capability IEI");
    SKIP(1);
    }
 
    int len = -1;
    B8_HEX();
    A_B8_BIT1(c3f, length_of_ue_network_capability, "Length of UE network capability contents", 1, 8);
    SKIP(1);

    B8_HEX();
    B8_BIT(len, 1, 8);
    if(len > 0)
    {
        A_B8_BIT3(c3f, eea0, "EEA0", 1, 1, ue_network_capability_eea1);
        A_B8_BIT3(c3f, eea1, "128-EEA1", 2, 2, ue_network_capability_eea2);
        A_B8_BIT3(c3f, eea2, "128-EEA2", 3, 3, ue_network_capability_eea3);
        A_B8_BIT3(c3f, eea3, "128-EEA3", 4, 4, ue_network_capability_eea4);
        A_B8_BIT3(c3f, eea4, "EEA4", 5, 5, ue_network_capability_eea5);
        A_B8_BIT3(c3f, eea5, "EEA5", 6, 6, ue_network_capability_eea6);
        A_B8_BIT3(c3f, eea6, "EEA6", 7, 7, ue_network_capability_eea7);
        A_B8_BIT3(c3f, eea7, "EEA7", 8, 8, ue_network_capability_eea8);
        len -= 1;   
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, eia1, "EIA0", 1, 1, ue_network_capability_eia1);
        A_B8_BIT3(c3f, 128_eia2, "128-EIA1", 2, 2, ue_network_capability_eia2);
        A_B8_BIT3(c3f, 128_eia3, "128-EIA2", 3, 3, ue_network_capability_eia3);
        A_B8_BIT3(c3f, 128_eia4, "128-EIA3", 4, 4, ue_network_capability_eia4);
        A_B8_BIT3(c3f, eia5, "EIA4", 5, 5, ue_network_capability_eia5);
        A_B8_BIT3(c3f, eia6, "EIA5", 6, 6, ue_network_capability_eia6);
        A_B8_BIT3(c3f, eia7, "EIA6", 7, 7, ue_network_capability_eia7);
        A_B8_BIT3(c3f, eia8, "EIA7", 8, 8, ue_network_capability_eia8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, uea1, "UEA0", 1, 1, ue_network_capability_uea1);
        A_B8_BIT3(c3f, uea2, "UEA1", 2, 2, ue_network_capability_uea2);
        A_B8_BIT3(c3f, uea3, "UEA2", 3, 3, ue_network_capability_uea3);
        A_B8_BIT3(c3f, uea4, "UEA3", 4, 4, ue_network_capability_uea4);
        A_B8_BIT3(c3f, uea5, "UEA4", 5, 5, ue_network_capability_uea5);
        A_B8_BIT3(c3f, uea6, "UEA5", 6, 6, ue_network_capability_uea6);
        A_B8_BIT3(c3f, uea7, "UEA6", 7, 7, ue_network_capability_uea7);
        A_B8_BIT3(c3f, uea8, "UEA7", 8, 8, ue_network_capability_uea8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, ucs2, "UCS2", 1, 1, ue_network_capability_ucs2);
        A_B8_BIT3(c3f, uia1, "UIA1", 2, 2, ue_network_capability_uia1);
        A_B8_BIT3(c3f, uia2, "UIA2", 3, 3, ue_network_capability_uia2);
        A_B8_BIT3(c3f, uia3, "UIA3", 4, 4, ue_network_capability_uia3);
        A_B8_BIT3(c3f, uia4, "UIA4", 5, 5, ue_network_capability_uia4);
        A_B8_BIT3(c3f, uia5, "UIA5", 6, 6, ue_network_capability_uia5);
        A_B8_BIT3(c3f, uia6, "UIA6", 7, 7, ue_network_capability_uia6);
        A_B8_BIT3(c3f, uia7, "UIA7", 8, 8, ue_network_capability_uia7);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, prosedd, "Prosedd", 1, 1, ue_network_capability_prosedd);
        A_B8_BIT3(c3f, prose, "ProSe", 2, 2, ue_network_capability_prose);
        A_B8_BIT3(c3f, h245_ash, "H.245-ASH", 3, 3, ue_network_capability_ash);
        A_B8_BIT3(c3f, acc_csfb, "ACC-CSFB", 4, 4, ue_network_capability_scfb);
        A_B8_BIT3(c3f, lpp, "LPP", 5, 5, ue_network_capability_lpp);
        A_B8_BIT3(c3f, lcs, "LCS", 6, 6, ue_network_capability_lcs);
        A_B8_BIT3(c3f, 1xsrvcc, "1xSRVCC", 7, 7, ue_network_capability_1xsrvcc);
        A_B8_BIT3(c3f, nf, "NF", 8, 8, ue_network_capability_nf);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(c3f, spare, "spare", 1, 7);
        A_B8_BIT3(c3f, spare, "ProSe-dc", 8, 8, ue_network_capability_prose_dc);
        len -= 1;
        SKIP(1);
    }

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, spare, "Spare", 1, 8, "Spare");
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

struct code2dict ue_network_capability_eea1[]= 
{
    {0, "EPS encryption algorithm EEA0 not supported"},
    {1, "EPS encryption algorithm EEA0 supported"},
};

struct code2dict ue_network_capability_eea2[]= 
{
    {0, "EPS encryption algorithm 128-EEA1 not supported"},
    {1, "EPS encryption algorithm 128-EEA1 supported"},
};

struct code2dict ue_network_capability_eea3[]= 
{
    {0, "EPS encryption algorithm 128-EEA2 not supported"},
    {1, "EPS encryption algorithm 128-EEA2 supported"},
};

struct code2dict ue_network_capability_eea4[]= 
{
    {0, "EPS encryption algorithm 128-EEA3 not supported"},
    {1, "EPS encryption algorithm 128-EEA3 supported"},
};

struct code2dict ue_network_capability_eea5[]= 
{
    {0, "EPS encryption algorithm EEA4 not supported"},
    {1, "EPS encryption algorithm EEA4 supported"},
};

struct code2dict ue_network_capability_eea6[]= 
{
    {0, "EPS encryption algorithm EEA5 not supported"},
    {1, "EPS encryption algorithm EEA5 supported"},
};

struct code2dict ue_network_capability_eea7[]= 
{
    {0, "EPS encryption algorithm EEA6 not supported"},
    {1, "EPS encryption algorithm EEA6 supported"},
};

struct code2dict ue_network_capability_eea8[]= 
{
    {0, "EPS encryption algorithm EEA7 not supported"},
    {1, "EPS encryption algorithm EEA7 supported"},
};

struct code2dict ue_network_capability_eia1[]= 
{
    {0, "EPS integrity algorithm EIA0 not supported"},
    {1, "EPS integrity algorithm EIA0 supported"},
};

struct code2dict ue_network_capability_eia2[]
{
    {0, "EPS integrity algorithm 128-EIA1 not supported"},
    {1, "EPS integrity algorithm 128-EIA1 supported"},
};

struct code2dict ue_network_capability_eia3[]= 
{
    {0, "EPS integrity algorithm 128-EIA2 not supported"},
    {1, "EPS integrity algorithm 128-EIA2 supported"},
};

struct code2dict  ue_network_capability_eia4[]= 
{
    {0, "EPS integrity algorithm 128-EIA3 not supported"},
    {1, "EPS integrity algorithm 128-EIA3 supported"},
};

struct code2dict ue_network_capability_eia5[]= 
{
    {0, "EPS integrity algorithm EIA4 not supported"},
    {1, "EPS integrity algorithm EIA4 supported"},
};

struct code2dict ue_network_capability_eia6[]= 
{
    {0, "EPS integrity algorithm EIA5 not supported"},
    {1, "EPS integrity algorithm EIA5 supported"},
};

struct code2dict ue_network_capability_eia7[]= 
{
    {0, "EPS integrity algorithm EIA6 not supported"},
    {1, "EPS integrity algorithm EIA6 supported"},
};

struct code2dict ue_network_capability_eia8[]= 
{
    {0, "EPS integrity algorithm EIA7 not supported"},
    {1, "EPS integrity algorithm EIA7 supported"},
};

struct code2dict ue_network_capability_uea1[]= 
{
    {0, "UMTS encryption algorithm UEA0 not supported"},
    {1, "UMTS encryption algorithm UEA0 supported"},
};

struct code2dict ue_network_capability_uea2[]= 
{
    {0, "UMTS encryption algorithm UEA1 not supported"},
    {1, "UMTS encryption algorithm UEA1 supported"},
};

struct code2dict ue_network_capability_uea3[]= 
{
    {0, "UMTS encryption algorithm UEA2 not supported"},
    {1, "UMTS encryption algorithm UEA2 supported"},
};

struct code2dict ue_network_capability_uea4[]= 
{
    {0, "UMTS encryption algorithm UEA3 not supported"},
    {1, "UMTS encryption algorithm UEA3 supported"},
};

struct code2dict ue_network_capability_uea5[]= 
{
    {0, "UMTS encryption algorithm UEA4 not supported"},
    {1, "UMTS encryption algorithm UEA4 supported"},
};

struct code2dict ue_network_capability_uea6[]= 
{
    {0, "UMTS encryption algorithm UEA5 not supported"},
    {1, "UMTS encryption algorithm UEA5 supported"},
};

struct code2dict ue_network_capability_uea7[]= 
{
    {0, "UMTS encryption algorithm UEA6 not supported"},
    {1, "UMTS encryption algorithm UEA6 supported"},
};

struct code2dict ue_network_capability_uea8[]= 
{
    {0, "UMTS encryption algorithm UEA7 not supported"},
    {1, "UMTS encryption algorithm UEA7 supported"},
};

struct code2dict ue_network_capability_ucs2[]= 
{
    {0, "The UE has a preference for the default alphabet over UCS2 (see ISO/IEC 10646 [29]).
"},
    {1, "The UE has no preference between the use of the default alphabet and the use of UCS2."},
};

struct code2dict ue_network_capability_uia1[]= 
{
    {0, "UMTS integrity algorithm UIA1 not supported"},
    {1, "UMTS integrity algorithm UIA1 supported"},
};

struct code2dict ue_network_capability_uia2[]= 
{
    {0, "UMTS integrity algorithm UIA2 not supported"},
    {1, "UMTS integrity algorithm UIA2 supported"},
};

struct code2dict ue_network_capability_uia3[]= 
{
    {0, "UMTS integrity algorithm UIA3 not supported"},
    {1, "UMTS integrity algorithm UIA3 supported"},
};

struct code2dict ue_network_capability_uia4[]= 
{
    {0, "UMTS integrity algorithm UIA4 not supported"},
    {1, "UMTS integrity algorithm UIA4 supported"},
};

struct code2dict ue_network_capability_uia5[]= 
{
    {0, "UMTS integrity algorithm UIA5 not supported"},
    {1, "UMTS integrity algorithm UIA5 supported"},
};

struct code2dict ue_network_capability_uia6[]= 
{
    {0, "UMTS integrity algorithm UIA6 not supported"},
    {1, "UMTS integrity algorithm UIA6 supported"},
};

struct code2dict ue_network_capability_uia7[]= 
{
    {0, "UMTS integrity algorithm UIA7 not supported"},
    {1, "UMTS integrity algorithm UIA7 supported"},
};

struct code2dict ue_network_capability_prosedd[]= 
{
    {0, "ProSe direct discovery not supported"},
    {1, "ProSe direct discovery supported"},
};

struct code2dict ue_network_capability_prose[]= 
{
    {0, "ProSe not supported"},
    {1, "ProSe supported"},
};

struct code2dict ue_network_capability_ash[]= 
{
    {0, "H.245 after SRVCC handover capability not supported"},
    {1, "       H.245 after SRVCC handover capability supported(see 3GPP TS 23.216 [8])"},
};

struct code2dict ue_network_capability_scfb[]= 
{
    {0, "eNodeB-based access class control for CSFB not supported"},
    {1, "eNodeB-based access class control for CSFB supported(see 3GPP TS 22.011 [1A]) 
"},
};

struct code2dict ue_network_capability_lpp[]= 
{
    {0, "LPP not supported"},
    {1, "LPP supported (see 3GPP TS 36.355 [22A])"},
};

struct code2dict ue_network_capability_lcs[]= 
{
    {0, "LCS notification mechanisms not supported "},
    {1, "LCS notification mechanisms supported (see 3GPP TS 24.171 [13C])"},
};

struct code2dict ue_network_capability_1xsrvcc[]= 
{
    {0, "UMTS integrity algorithm UIA7 not supported"},
    {1, "UMTS integrity algorithm UIA7 supported"},
};

struct code2dict ue_network_capability_nf[]= 
{
    {0, "notification procedure not supported"},
    {1, "notification procedure supported"},
};

struct code2dict ue_network_capability_prose_dc[]= 
{
    {0, "ProSe direct communication not supported"},
    {1, "ProSe direct communication supported"},
};


void supported_codec_list(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Supported codec list", supported_codec_list);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(c3f, supported_codec_list_iei, "Supported Codec List IEI", 1, 8, "Supported codec list");
        SKIP(1);
    }

    int len = -1;
    B8_HEX();
    B8_BIT(len, 1, 8);
    if(len > 0)
    {
        A_B8_BIT1(c3f, length_of_supported_codec_list, "Length Of Supported Codec list", 1, 8);
        len -= 1;
        SKIP(1);
    }
   
    if(len > 0)
    {
    B8_HEX();
    A_B8_BIT2(c3f, system_identification_1, "System Identification 1 (SysID 1)", 1, 8);
    len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, Length_Of_Bitmap_for_SysID_1, "Length Of Bitmap for SysID 1", 1, 8);
        len -= 1;
        SKIP(1);
    }
  
    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT3(c3f, Codec Bitmap for SysID 1, bits 1 to 8, "Codec Bitmap for SysID 1, bits 1 to 8", 1, 8);
        len -= 1;
        SKIP(1);
    } 
}

void voice_domain_preference_and_ue_usage_setting(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Voice domain preference and UE's usage setting", voice_domain_preference_and_ue_usage_setting); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, voice_domain_preference_and_ue_usage_setting_iei, 1, 8, "Voice domain preference and UE's usage setting IEI");
        SKIP(1);
    }

    int len = -1;
    B8_HEX();
    B8_BIT(len, 1, 8);
    SKIP(1);

    if(len > 0)
    {
        A_B8_BIT2(c3f, spare, 4, 8, "Spare");
        int tmp = -1;
        B8_BIT(tmp, 3, 3);
        if(tmp == 0)
        {
            A_B8_BIT2(c3f, ue_s_useage_setting, "UE's usage setting", 3， 3, "Voice centric");
        }
        else
        {
            A_B8_BI2(c3f，ue_s_useage_setting, "UE's usage setting", 3， 3, "Data centric");   
        }

        A_B8_BIT2(c3f, voice_domain_preference_for_e_utran, "Voice domain preference for E-UTRAN", 1, 2, voice_domain_preference_for_e_utran_dict);
        SKIP(1);
    }
    END_ELEMENT();
}

struct code2dict voice_domain_preference_for_e_utran_dict[]= 
{
    {0, "CS Voice only"},
    {1, "IMS PS Voice only"},
    {2, "CS voice preferred, IMS PS Voice as secondary"},
    {3, "IMS PS voice preferred, CS Voice as secondary"},
};

void location_area_identification_2(uint8_t iei, uint8_t location) 
{    
    BEGIN_ELEMENT("Location Area Identification 2", location_area_identification_2); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, location_area_identification_2_iei, 1, 8, "Location Area Identification 2 IEI");
        SKIP(1);
    }

    int len = -1;
    B8_BIT(len, 1, 8);
    SKIP(1);

    len -= 2;
    which(len > 0)
    {
        A_B8_BIT1(c3f, location_area_identification_2_val, "Location Area Identification 2 value", 1, 8);
        len -= 1;
        SKIP(1);
    }

    END_ELEMENT();
}

//TO DO
void additional_update_type(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Additional update type", additional_update_type);
    if(iei == 0)
    {
        int tmp = -1;
        if(location == 1)
        {
            A_B8_BIT1(c3f, spare, "Spare", 4, 4);
            A_B8_BIT1(c3f, spare, "Spare", 3, 3);
            A_B8_BIT1(c3f, spare, "Spare", 2, 2);
            
            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, autv, "AUTV", 1, 1, "No additional information. If received it shall be interpreted as request for combined attach or combined tracking area updating.");
            }
            else
            {
                A_B8_BIT2(c3f, autv, "AUTV", 1, 1, "SMS only");
            }
            SKIP(1);
        }
        else
        {
            B8_HEX();
            A_B8_BIT1(c3f, spare, "Spare", 8, 8);
            A_B8_BIT1(c3f, spare, "Spare", 7, 7);
            A_B8_BIT1(c3f, spare, "Spare", 6, 6);
            
            B8_BIT(tmp, 5, 5);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, autv, "AUTV", 5, 5, "No additional information. If received it shall be interpreted as request for combined attach or combined tracking area updating.");
            }
            else
            {
                A_B8_BIT2(c3f, autv, "AUTV", 5, 5, "SMS only");
            }
        }
    }
    else
    {
            B8_HEX();
            A_B8_BIT2(c3f, additional_update_type_iei, "Additional update type IEI", 5, 8, "Additional update type");

            A_B8_BIT1(c3f, spare, "Spare", 4, 4);
            A_B8_BIT1(c3f, spare, "Spare", 3, 3);
            A_B8_BIT1(c3f, spare, "Spare", 2, 2);
            
            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, autv, "AUTV", 1, 1, "No additional information. If received it shall be interpreted as request for combined attach or combined tracking area updating.");
            }
            else
            {
                A_B8_BIT2(c3f, autv, "AUTV", 1, 1, "SMS only");
            }
            SKIP(1);
    }
    END_ELEMENT();
}

void network_resource_identifier_container(uint8_t iei, uint8_t location) 
{ 
    BEGIN_ELEMENT("Network resource identifier container", network_resource_identifier_container); 
    if(iei == 1)
    {    
        B8_HEX(); 
        A_B8_BIT2(c3f, network_resource_identifier_container_iei, 1, 8, "Network resource identifier container IEI");
        SKIP(1);
    }

    int len = -1;
    B8_HEX(); 
    B8_BIT(len, 1, 8);
    SKIP(1);

    len -= 2；
    if(len > 0)
    {
        A_B8_BIT1(c3f, nri_container_value, "NRI container value", 1, 8);
        len -= 1;
        SKIP(1);
    }

    if(len > 0)
    {
        int val_8 = 0;
        int val_2 = 0;
        char buf[256];
        B8_BIT(val_8, 1, 8);
        A_B8_BIT2(c3f, nri_container_value, "NRI container value", 1, 8, "");
        SKIP(1);

        B8_BIT(val_2, 7, 8);
        val_8 = val_8 << 2 + val_2;
        memset(buf, 0, 256);
        sprintf(buf, "%d", val_8);
        A_B8_BIT2(c3f, nri_container_value, "NRI container value", 7, 8, buf);
        A_B8_BIT1(c3f, spare, "spare", 1, 6);
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
                A_B8_BIT2(c3f, gprs_timer_2_iei, "GPRS Timer 2 IEI", 1, 8, "GPRS Timer 2");
                SKIP(1);
        }

        B8_HEX();
        A_B8_BIT1(c3f, length_of_gprs_timer_2_contents, "Length of GPRS Timer 2 contents", 1, 8);
        SKIP(1);

        B8_HEX();
        A_B8_BIT1(c3f, time_2_value, "GPRS Timer 2 value", 1, 8);
        SKIP(1);
        END_ELEMENT();
}

void attach_result(uint8_t iei, uint8_t location)
{
        BEGIN_ELEMENT("Attach result", attach_result);
        if(iei==1)
        {    
                B8_HEX();
                A_B8_BIT2(c3f, attach_result_iei, "Attach result IEI", 5, 8, "Attach result");

                int tmp = -1;
                B8_BIT(tmp, 4, 4);
                if(tmp == 0)
                {
                    A_B8_BIT2(c3f, attach_result_fop, "FOP", 4, 4, "Follow-on proceed");
                }
                else
                {
                    A_B8_BIT2(c3f, attach_result_fop, "FOP", 4, 4, "No follow-on proceed");
                }

                B8_BIT(tmp, 1, 3);
                if(tmp == 1)
                {
                    A_B8_BIT2(c3f, attach_result_   , "Result of attach", 1, 3, "GPRS only attached");
                }
                else if(tmp == 3)
                {
                    A_B8_BIT2(c3f, attach_result_   , "Result of attach", 1, 3, "Combined GPRS/IMSI attached");
                }
                else
                {
                    A_B8_BIT2(c3f, attach_result_   , "Result of attach", 1, 3, "reserved");
                }
                SKIP(1);
        }
        END_ELEMENT();
}

void force_to_standby(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Force to standby", force_to_standby);
    if(iei==1)
    {    
            B8_HEX();
            A_B8_BIT2(c3f, force_to_standby_iei, "Force to standby IEI", 5, 8, "Force to standby");
            A_B8_BIT2(c3f, force_to_standby_spare, "spare", 4, 4, "spare");
            int tmp = -1;
            B8_BIT(tmp, 1, 3);
            if(tmp == 0)
            {
                A_B8_BIT2(c3f, force_to_standby_value, "Force to standby value", 4, 4, "Force to standby not indicated");
            }
            else if(tmp == 1)
            {
                A_B8_BIT2(c3f, force_to_standby_value, "Force to standby value", 4, 4, "Force to standby indicated");
            }
            else
            {
                A_B8_BIT2(c3f, force_to_standby_value, "Force to standby value", 4, 4, "force to standby not indicated by this version of the protocol.");
            }
            SKIP(1);
    }
    END_ELEMENT();
}

void radio_priority(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Radio priority", radio_priority);
    if(iei==1)
    {    
            B8_HEX();
            A_B8_BIT2(c3f, radio_priority_iei, "Radio priority IEI", 5, 8, "Radio priority");
            A_B8_BIT2(c3f, radio_priority_spare, "spare", 4, 4, "spare");
            int tmp = -1;
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(c3f, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(c3f, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 3");
            }
            else
            {
                A_B8_BIT2(c3f, radio_priority_level_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
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
        B8_HEX();
        if(location == 1)
        {
            A_B8_BIT1(c3f, spare, "Spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 3");
            }
            else
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
            }
            SKIP(1);
        }
        else
        {
            A_B8_BIT1(c3f, spare, "Spare", 8, 8);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 3");
            }
            else
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 5, 7, "priority level 4 (lowest)");
            }
        }
    }
    else
    {
            B8_HEX();
            A_B8_BIT2(c3f, radio_priority_2_iei, "Radio priority 2 IEI", 5, 8, "Radio priority 2");

            A_B8_BIT1(c3f, spare, "Spare", 4, 4);
            B8_BIT(tmp, 1, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 1 (highest)");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 2");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 3");
            }
            else
            {
                A_B8_BIT2(c3f, radio_priority_2_value, "Radio priority level value", 1, 3, "priority level 4 (lowest)");
            }
            SKIP(1);
    }
    END_ELEMENT();
}

void routing_area_identification(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("Routing area identification", routing_area_identification);
    if(iei==1)
    {    
            B8_HEX();
            A_B8_BIT2(c3f, routing_area_identification_iei, "Routing area identification IEI", 1, 8, "Routing area identification");
            SKIP(1);
    }

    B8_HEX();
    A_B8_BIT1(c3f, mcc_digit_2, "MCC digit 2", 5, 8);
    A_B8_BIT1(c3f, mcc_digit_1, "MCC digit 1", 1, 4);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(c3f, mnc_digit_3, "MNC digit 3", 5, 8);
    A_B8_BIT1(c3f, mcc_digit_3, "MCC digit 3", 1, 4);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(c3f, mnc_digit_2, "MNC digit 2", 5, 8);
    A_B8_BIT1(c3f, mnc_digit_1, "MNC digit 1", 1, 4);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(c3f, lac, "LAC", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(c3f, lac_cont_d "LAC cont'd", 1, 8);
    SKIP(1);

    B8_HEX();
    A_B8_BIT1(c3f, rac, "RAC", 1, 8);
    SKIP(1);
    END_ELEMENT();
}

//TO DO
void ms_radio_access_capability(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("MS Radio Access Capability", ms_radio_access_capability);
    if(iei == 1)
    {
        B8_HEX();
	    A_B8_BIT2(c3f, ms_radio_access_capability_iei, "MS Radio Access Capability IEI IEI", 1, 8, "MS Radio Access Capability IEI");
        SKIP(1);
    }

    int  len = -1;
    B8_HEX();
    B8_BIT(len, 1, 8);
    SKIP(1);

    if(len > 0)
    {

    }
}

void gmm_cause(uint8_t iei, uint8_t location)
{
    BEGIN_ELEMENT("GMM cause"， gmm_cause);
    if(iei == 1)
    {
        B8_HEX();
        A_B8_BIT2(c3f, gmm_cause_iei, "GMM cause IEI", 1, 8, "GMM cause");
        SKIP(1);
    }

    B8_HEX();
    B8_BIT(tmp, 1, 8);
    if(tmp == 2)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "IMSI unknown in HLR");
    }
    else if(tmp == 3)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "  Illegal MS");
    }
    else if(tmp == 5)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "IMEI not accepted");
    }
    else if(tmp == 6)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Illegal ME");
    }
    else if(tmp == 7)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "GPRS services not allowed");
    }
    else if(tmp == 8)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "GPRS services and non-GPRS services not allowed");
    }
    else if(tmp == 9)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "MS identity cannot be derived by the network");
    }
    else if(tmp == 10)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Implicitly detached");
    }
    else if(tmp == 11)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "PLMN not allowed");
    }
    else if(tmp == 12)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Location Area not allowed");
    }
    else if(tmp == 13)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Roaming not allowed in this location area");
    }
    else if(tmp == 14)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "GPRS services not allowed in this PLMN");
    }
    else if(tmp == 15)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "No Suitable Cells In Location Area");
    }
    else if(tmp == 16)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "MSC temporarily not reachable");
    }
    else if(tmp == 17)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Network failure");
    }
    else if(tmp == 20)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "MAC failure");
    }
    else if(tmp == 21)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Synch failure");
    }
    else if(tmp == 22)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Congestion");
    }
    else if(tmp == 23)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "GSM authentication unacceptable");
    }
    else if(tmp == 25)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Not authorized for this CSG");
    }
    else if(tmp == 28)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "SMS provided via GPRS in this routing area");
    }
    else if(tmp == 40)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "No PDP context activated");
    }
    else if(tmp >= 48 && tmp <= 63)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "retry upon entry into a new cell");
    }
    else if(tmp == 137)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Semantically incorrect message");
    }
    else if(tmp == 140)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Invalid mandatory information");
    }
    else if(tmp == 141)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Message type non-existent or not implemented");
    }
    else if(tmp == 142)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Message type not compatible with the protocol state");
    }
    else if(tmp == 143)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Information element non-existent or not implemented");
    }
    else if(tmp == 144)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Conditional IE error");
    }
    else if(tmp == 145)
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Message not compatible with the protocol state");
    }
    else
    {
        A_B8_BIT2(c3f, gmm_cause_value, "Cause value", 1, 8, "Protocol error, unspecified");
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
        A_B8_BIT2(c3f, cell_notification_iei, "Cell Notification IEI", 1, 8, "Cell Notification");
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
        B8_HEX();
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain supported");
            }
            else
            {
                 A_B8_BIT2(c3f, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain not supported");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, mbms, "MBMS", 3, 3,  "MBMS supported");
            }
            else
            {
                 A_B8_BIT2(c3f, mbms, "MBMS", 3, 3,  "MBMS not supported");
            }

            B8_BIT(tmp, 2, 2);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(c3f, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session in Iu mode and A/Gb mode not supported");
            }

            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode supported");
            }
            else
            {
                 A_B8_BIT2(c3f, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode not supported");
            }
            SKIP(1);
        }
        else
        {
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, lcs_molr, "LCS-MOLR", 8, 8,  "LCS-MOLR via PS domain supported");
            }
            else
            {
                 A_B8_BIT2(c3f, lcs_molr, "LCS-MOLR", 8, 8,  "LCS-MOLR via PS domain not supported");
            }

            B8_BIT(tmp, 7, 7);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, mbms, "MBMS", 7, 7,  "MBMS supported");
            }
            else
            {
                 A_B8_BIT2(c3f, mbms, "MBMS", 7, 7,  "MBMS not supported");
            }

            B8_BIT(tmp, 6, 6);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, imsvops, "IMSVoPS", 6, 6,  "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(c3f, imsvops, "IMSVoPS", 6, 6,  "IMS voice over PS session in Iu mode and A/Gb mode not supported");
            }

            B8_BIT(tmp, 5, 5);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, emcbs, "EMCBS", 5, 5,  "Emergency bearer services in Iu mode and A/Gb mode supported");
            }
            else
            {
                 A_B8_BIT2(c3f, emcbs, "EMCBS", 5, 5,  "Emergency bearer services in Iu mode and A/Gb mode not supported");
            }
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(c3f, network_feature_support_iei, "Network feature support IEI", 5, 8, "Network feature support");
               B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain supported");
            }
            else
            {
                 A_B8_BIT2(c3f, lcs_molr, "LCS-MOLR", 4, 4,  "LCS-MOLR via PS domain not supported");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, mbms, "MBMS", 3, 3,  "MBMS supported");
            }
            else
            {
                 A_B8_BIT2(c3f, mbms, "MBMS", 3, 3,  "MBMS not supported");
            }

            B8_BIT(tmp, 2, 2);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session supported in Iu mode, but not supported in A/Gb mode");
            }
            else
            {
                 A_B8_BIT2(c3f, imsvops, "IMSVoPS", 2, 2,  "IMS voice over PS session in Iu mode and A/Gb mode not supported");
            }

            B8_BIT(tmp, 1, 1);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode supported");
            }
            else
            {
                 A_B8_BIT2(c3f, emcbs, "EMCBS", 1, 1,  "Emergency bearer services in Iu mode and A/Gb mode not supported");
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
        B8_HEX();
        if(location == 1)
        {
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE requested");
            }
            else
            {
                 A_B8_BIT2(c3f, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE not requested");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT1(c3f, i_rat_2, "I-RAT2", 3, 3);
            }
            else
            {
                 A_B8_BIT1(c3f, i_rat_2, "I-RAT2", 3, 3);
            }

            A_B8_BIT2(c3f, Spare, "Spare", 1, 2);
            SKIP(1);
        }
        else
        {
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, i_rat, "I-RAT", 8, 8,  "Inter RAT information container IE requested");
            }
            else
            {
                 A_B8_BIT2(c3f, i_rat, "I-RAT", 8, 8,  "Inter RAT information container IE not requested");
            }

            B8_BIT(tmp, 3, 3);
            if(tmp == 1)
            {
                A_B8_BIT1(c3f, i_rat_2, "I-RAT2", 7, 7);
            }
            else
            {
                 A_B8_BIT1(c3f, i_rat_2, "I-RAT2", 7, 7);
            }

            A_B8_BIT2(c3f, Spare, "Spare", 5, 6);
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(c3f, requested_ms_information, "Requested MS information IEI", 5, 8, "Requested MS information");
        B8_BIT(tmp, 4, 4);
        if(tmp == 1)
        {
            A_B8_BIT2(c3f, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE requested");
        }
        else
        {
             A_B8_BIT2(c3f, i_rat, "I-RAT", 4, 4,  "Inter RAT information container IE not requested");
        }

        B8_BIT(tmp, 3, 3);
        if(tmp == 1)
        {
            A_B8_BIT1(c3f, i_rat_2, "I-RAT2", 3, 3);
        }
        else
        {
             A_B8_BIT1(c3f, i_rat_2, "I-RAT2", 3, 3);
        }

        A_B8_BIT2(c3f, Spare, "Spare", 1, 2);
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
        A_B8_BIT2(c3f, additional_network_feature_support_iei, "Additional network feature support IEI", 1, 8, "Additional network feature support");
        SKIP(1);
    }

    B8_HEX();
    int len = -1;
    B8_BIT(len, 1, 8);
    A_B8_BIT2(c3f, length_of_additional_network_feature_support_contents， "Length of additional network feature support contents", 1, 8);
    SKIP(1);

    if(len > 0)
    {
        B8_HEX();
        A_B8_BIT2(c3f, spare, "Spare", 2, 8);
        B8_BIT(tmp, 1, 1);
        if(tmp == 1)
        {
            A_B8_BIT2(c3f, gprs_sms, "GPRS-SMS", 1, 1, "SMS via GPRS not supported");
        }
        else
        {
            A_B8_BIT2(c3f, gprs_sms, "GPRS-SMS", 1, 1, "SMS via GPRS supported");
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
        A_B8_BIT2(c3f, inter_rat_information_container_iei, "Inter RAT information container IEI", 1, 8, "Inter RAT information container");
        SKIP(1);
    }
    
    int len = -1;
    B8_HEX();
    B8_BIT(len, 1, 8);
    A_B8_BIT1(c3f, length_of_inter_rat_information_container, "Length of inter RAT information container", 1, 8);
    len -= 1;
    SKIP(1);

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(c3f, inter_rat_information_container_value_part, "Inter RAT information container value part", 1, 8);
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
        A_B8_BIT2(c3f, e_utran_inter_rat_information_container_iei, "E-UTRAN inter RAT information container IEI", 1, 8, "E-UTRAN inter RAT information container");
        SKIP(1);
    }

    B8_HEX();
    int len = -1;
    B8_BIT(len, 1, 8);
    A_B8_BIT1(c3f, length_of e_utran_inter_rat_information_container, "Length of E-UTRAN Inter RAT information container");
    SKIP(1);

    while(len > 0)
    {
        B8_HEX();
        A_B8_BIT1(c3f, e_utran_inter_rat_information_container_value_part, "E-UTRAN Inter RAT information container value part", 1, 8);
        len -= 1;
        SKIP(1);
    }
    END_ELEMENT();
}

void detach_type(uint8_t iei, uint8_t location, int ms_to_net)
{
    BEGIN_ELEMENT("BEGIN_ELEMENT", detach_type);
    if(iei == 0)
    {
        B8_HEX();
        if(Location == 1)
        {
            int tmp = -1;
            B8_BIT(tmp, 4, 4);
            if(tmp == 1)
            {
                A_B8_BIT1(c3f, power_off, "Power off", 4, 4, "power switched off");
            }
            else
            {
                A_B8_BIT1(c3f, power_off, "Power off", 4, 4, "normal detach");
            }

            B8_BIT(tmp, 1, 3);
            if(ms_to_net == 1)
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "GPRS detach");
                }
                else if(tmp == 2)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "IMSI detach");
                }
                else
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "Combined GPRS/IMSI detach");                                            
                }
            }
            else
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "re-attach required");
                }
                else if(tmp == 3)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "IMSI detach (after VLR failure)");                    
                }
                else
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "re-attach not required");
                }                
            }
            SKIP(1);
        }
        else
        {
            int tmp = -1;
            B8_BIT(tmp, 8, 8);
            if(tmp == 1)
            {
                A_B8_BIT1(c3f, power_off, "Power off", 8, 8, "power switched off");
            }
            else
            {
                A_B8_BIT1(c3f, power_off, "Power off", 8, 8, "normal detach");
            }

            B8_BIT(tmp, 5, 7);
            if(ms_to_net == 1)
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 5, 7, "GPRS detach");
                }
                else if(tmp == 2)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 5, 7, "IMSI detach");
                }
                else
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 5, 7, "Combined GPRS/IMSI detach");                                            
                }
            }
            else
            {
                if(tmp == 1)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 5, 7, "re-attach required");
                }
                else if(tmp == 3)
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 5, 7, "IMSI detach (after VLR failure)");                    
                }
                else
                {
                    A_B8_BIT2(c3f, type_of_detach, "Type of detach", 5, 7, "re-attach not required");
                }                
            }
        }        
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(c3f, detach_type_iei, "Detach type IEI", 5, 8, "Detach type");
        int tmp = -1;
        B8_BIT(tmp, 4, 4);
        if(tmp == 1)
        {
            A_B8_BIT1(c3f, power_off, "Power off", 4, 4, "power switched off");
        }
        else
        {
            A_B8_BIT1(c3f, power_off, "Power off", 4, 4, "normal detach");
        }

        B8_BIT(tmp, 1, 3);
        if(ms_to_net == 1)
        {
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "GPRS detach");
            }
            else if(tmp == 2)
            {
                A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "IMSI detach");
            }
            else
            {
                A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "Combined GPRS/IMSI detach");                                            
            }
        }
        else
        {
            if(tmp == 1)
            {
                A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "re-attach required");
            }
            else if(tmp == 3)
            {
                A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "IMSI detach (after VLR failure)");                    
            }
            else
            {
                A_B8_BIT2(c3f, type_of_detach, "Type of detach", 1, 3, "re-attach not required");
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
    bzero(buf, 256);
    int tmp = -1;
    if(iei == 0)
    {
        B8_HEX();
        if(location == 1)
        {
            A_B8_BIT1(c3f, spare, "spare", 4, 4);
            B8_BIT(tmp, 4, 4);
            if(tmp != 0)
            {
                sprintf(buf, "GPRS Encryption Algorithm GEA/%d", tmp);
            }
            else
            {
                sprintf(buf, "ciphering not used");   
            }

            A_B8_BIT2(c3f, type_of_algorithm, "Type of algorithm", 1, 3, buf);
            SKIP(1);
        }
        else
        {
            A_B8_BIT1(c3f, spare, "spare", 8, 8);
            B8_BIT(tmp, 8, 8);
            if(tmp != 0)
            {
                sprintf(buf, "GPRS Encryption Algorithm GEA/%d", tmp);
            }
            else
            {
                sprintf(buf, "ciphering not used");   
            }

            A_B8_BIT2(c3f, type_of_algorithm, "Type of algorithm", 5, 7, buf);
        }
    }
    else
    {
        B8_HEX();
        A_B8_BIT2(c3f, ciphering_algorithm_iei, "Ciphering algorithm IEI", 5, 8);
        A_B8_BIT1(c3f, spare, "spare", 4, 4);
        B8_BIT(tmp, 4, 4);
        if(tmp != 0)
        {
            sprintf(buf, "GPRS Encryption Algorithm GEA/%d", tmp);
        }
        else
        {
            sprintf(buf, "ciphering not used");   
        }

        A_B8_BIT2(c3f, type_of_algorithm, "Type of algorithm", 1, 3, buf);
        SKIP(1);
    }
    
    END_ELEMENT();
}

def gmm_sm_layer<900> = proto{

  APP <- ""[
  nbe.cdef[[
    #include "nbe_common.h"
    #include "dict.h"
    #include "gb_l3_common.h"
    #include "stdio.h"

    BEGIN_SIGNAL("4", "GMM", "DETACH REQUEST");

    uint8_t iei = 0;
    uint8_t location = 0;

    si_pd();
    msg_type(MESSAGE_TYPE_GMM);
    detach_type(iei, location);
    
    location = 1;
    force_to_standby(iei, location);
    B8_BIT(h, 1, 8);
    if(h & 0xf0 == 0x25)
    {
        iei = 1;
        gmm_cause(iei, location);
    }

    END_LAPDM();
  ]]]
};

struct code2dict cause_value_dict[]= 
{
    {0, ""},
    {1, ""},
};
//
struct code2dict radio_priority_2_value_dict[]= 
{
    {0, ""},
    {1, ""},
};
//
//struct code2dict []= 
//{
//    {0, ""},
//    {1, ""},
//};
//
//struct code2dict []= 
//{
//    {0, ""},
//    {1, ""},
//};
//
//struct code2dict []= 
//{
//    {0, ""},
//    {1, ""},
//};
//
//struct code2dict []= 
//{
//    {0, ""},
//    {1, ""},
//};
//
//struct code2dict []= 
//{
//    {0, ""},
//    {1, ""},
//};
//
#endif

