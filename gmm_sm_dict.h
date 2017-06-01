#ifndef  __GMM_SM_DICT_H__
#define  __GMM_SM_DICT_H__

/************************1st*************************/
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

struct code2dict ms_network_capability_ucs2_support[]= 
{
    {0, "the ME has a preference for the default alphabet (defined in 3GPP TS 23.038 [8b]) over UCS2."},
    {1, "the ME has no preference between the use of the default alphabet and the use of UCS2."},
};

struct code2dict ms_network_capability_sm_capabilities_via_gprs_channels[] =
{
    {0, "Mobile station does not support mobile terminated point to point SMS via PS domain"},
    {1, "Mobile station supports mobile terminated point to point SMS via PS domain"},
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

/******************2rd****************/
struct code2dict  s_network_capability_sm_capabilities_via_gprs_channels[]=
{
   {0, "Mobile station does not support mobile terminated point to point SMS via PS domain"},
   {1, "Mobile station supports mobile terminated point to point SMS via PS domain"},
};

struct code2dict attach_type_follow_on_request[]= 
{
    {0, "No follow-on request pending"},
    {1, "Follow-on request pending"},
};

struct code2dict attach_type_type_of_attach[]=
{ 
    {1, "GPRS attach"},
    {2, "Not used. This value was allocated in earlier versions of the protocol (Note1)}"},
    {3, "Combined GPRS/IMSI attach"},
    {4, "Emergency attach"},
};

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
};

struct code2dict drx_paramete_cn_drx_cycle_len_drx[]=
{
    {0, "For Iu mode, CN Specific DRX cycle length coefficient not specified by the MS; For S1 mode, DRX value not specified by the MS."},
    {6, "CN Specific DRX cycle length coefficient 6 and T = 32"},
    {7, "CN Specific DRX cycle length coefficient 7 and T = 64"},
    {8, "CN Specific DRX cycle length coefficient 8 and T = 128"},
    {9, "N Specific DRX cycle length coefficient 9 and T = 256"},
};

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

struct code2dict ue_network_capability_eia2[]=
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
    {0, "The UE has a preference for the default alphabet over UCS2 (see ISO/IEC 10646 [29])."},
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
    {1, "eNodeB-based access class control for CSFB supported(see 3GPP TS 22.011 [1A])"},
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

struct code2dict voice_domain_preference_for_e_utran_dict[]=
{
    {0, "CS Voice only"},
    {1, "IMS PS Voice only"},
    {2, "CS voice preferred, IMS PS Voice as secondary"},
    {3, "IMS PS voice preferred, CS Voice as secondary"},
};

char *apc_otd_gps[]=
{
    "APC",
    "OTDA",
    "OTDB",
    "GPSA",
    "GPSB",
    "GPSC",
};

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

struct code2dict type_of_identity_dict[] =
{
    {1, "IMSI"},
    {2, "IMEI"},
    {3, "IMEISV"},
    {4, "TMSI"},
};


struct code2dict tft_operation_dict[] =
{
    { 0, "Spare"},
    { 1, "Create new TFT"},
    { 2, "Delete existing TFT"},
    { 3, "Add packet filters to existing TFT"},
    { 4, "Replace packet filters in existing TFT"},
    { 5, "Delete packet filters from existing TFT"},
    { 6, "No TFT operation"},
    { 7, "Reserved"},
};


struct  code2dict con_id_m_to_n_dict[] = 
{
    { 1, "P-CSCF IPv6 Address Request"},
    { 2, "IM CN Subsystem Signaling Flag"},
    { 3, "DNS Server IPv6 Address Request"},
    { 4, "Not Supported"},
    { 5, "MS Support of Network Requested Bearer Control indicator"},
    { 6, "Reserved"}, 
    { 7, "DSMIPv6 Home Agent Address Request"},
    { 8, "DSMIPv6 Home Network Prefix Request"},
    { 9,  "DSMIPv6 IPv4 Home Agent Address Request"},
    { 10, "IP address allocation via NAS signalling"},
    { 11, "IPv4 address allocation via DHCPv4"},
    { 12, "P-CSCF IPv4 Address Request"},
    { 13, "DNS Server IPv4 Address Request"},
    { 14, "MSISDN Request"},
    { 15, "IFOM-Support-Request"},
    { 16, "IPv4 Link MTU Request"},
    { 17, "MS support of Local address in TFT indicator"},
    { 18, "P-CSCF Re-selection support"},
};

struct  code2dict con_id_n_to_m_dict[] = 
{
    { 1, "P-CSCF IPv6 Address"},
    { 2, "IM CN Subsystem Signaling Flag"},
    { 3, "DNS Server IPv6 Address"},
    { 4, "Policy Control rejection code"},
    { 5, "Selected Bearer Control Mode"},
    { 6, "Reserved"}, 
    { 7, "DSMIPv6 Home Agent Address"},
    { 8, "DSMIPv6 Home Network Prefix"},
    { 9,  "DSMIPv6 IPv4 Home Agent Address"},
    { 10, "Reserved"},
    { 11, "Reserved"},
    { 12, "P-CSCF IPv4 Address"},
    { 13, "DNS Server IPv4 Address"},
    { 14, "MSISDN"},
    { 15, "IFOM-Support"},
    { 16, "IPv4 Link MTU"},
    { 17, "Network support of Local address in TFT indicator"},
    { 18, "Reserved"},
};


struct code2dict cause_value_dict[] =
{
    { 8, "Operator Determined Barring" },
    { 24, "MBMS bearer capabilities insufficient for the service" },
    { 25, "LLC or SNDCP failure(A/Gb mode only)" },
    { 26, "Insufficient resources" },
    { 27, "Missing or unknown APN" },
    { 28, "Unknown PDP address or PDP type" },
    { 29, "User authentication failed" },
    { 30, "Activation rejected by GGSN, Serving GW or PDN GW" },
    { 31, "Activation rejected, unspecified" },
    { 32, "Service option not supported" },
    { 33, "Requested service option not subscribed" },
    { 34, "Service option temporarily out of order" },
    { 35, "NSAPI already used (not sent)" },
    { 36, "Regular deactivation" },
    { 37, "QoS not accepted" },
    { 38, "Network failure" },
    { 39, "Reactivation requested" },
    { 40, "Feature not supported" },
    { 41, "Semantic error in the TFT operation" },
    { 42, "Syntactical error in the TFT operation" },
    { 43, "Unknown PDP context" },
    { 44, "Semantic errors in packet filter(s)" },
    { 45, "Syntactical errors in packet filter(s)" },
    { 46, "PDP context without TFT already activated" },
    { 47, "Multicast group membership time-out" },
    { 48, "Request rejected, BCM violation" },
    { 50, "PDP type IPv4 only allowed" },
    { 51, "PDP type IPv6 only allowed" },
    { 52, "Single address bearers only allowed" },
    { 56, "Collision with network initiated request" },
    { 60, "Bearer handling not supported" },
    { 65, "Maximum number of PDP contexts reached" },
    { 66, "Requested APN not supported in current RAT and PLMN combination" },
    { 81, "Invalid transaction identifier value" },
    { 95, "Semantically incorrect message" },
    { 96, "Invalid mandatory information" },
    { 97, "Message type non-existent or not implemented" },
    { 98, "Message type not compatible with the protocol state" },
    { 99, "Information element non-existent or not implemented" },
    { 100, "Conditional IE error" },
    { 101, "Message not compatible with the protocol state" },
    { 111, "Protocol error, unspecified" },
    { 112, "APN restriction value incompatible with active PDP context" },
};


#endif
