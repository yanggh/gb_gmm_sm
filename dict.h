
code2dict lpd_dict[] = { 
    {0, "LPD"}, 
    {1, "LPD for SMSCB"}, 
};

code2dict sapi_dict[] = { 
    {0, "MM, RR, CM management signal"}, 
    {1, "Reserved for future standardization"}, 
    {2, "Reserved for future standardization"}, 
    {3, "Short message service"}, 
    {4, "Reserved for future standardization"}, 
    {5, "Reserved for future standardization"}, 
    {6, "Reserved for future standardization"}, 
    {7, "Reserved for future standardization"}, 
};

code2dict ea_dict[] = { 
    {0, "Extension"}, 
    {1, "No Extension"}, 
};

code2dict p_dict[] = { 
    {0, "No Response"}, 
    {1, "Response"}, 
};

code2dict m_dict[] = { 
    {0, "The last segment of a layer 3 message"}, 
    {1, "A segment of a layer 3 message"}, 
};

code2dict el_dict[] = { 
    {0, "Extension"}, 
    {1, "No Extension"}, 
};

struct  code2dict protocol_discriminator_[] = 
{
    {3, "call control; call related SS messages"}, 
    {5, "Mobility management messages "}, 
    {6, "Radio Resource management messages"}, 
    {8, "GPRS mobility management messages"}, 
    {10, "GPRS session management messages"}, 
};

struct  code2dict message_type_mm[] = 
{
    {1, "IMSI DETACH INDICATION"}, 
    {65, "IMSI DETACH INDICATION"}, 
    {129, "IMSI DETACH INDICATION"}, 
    {193, "IMSI DETACH INDICATION"}, 
    {2, "LOCATION UPDATING ACCEPT"}, 
    {66, "LOCATION UPDATING ACCEPT"}, 
    {130, "LOCATION UPDATING ACCEPT"}, 
    {194, "LOCATION UPDATING ACCEPT"}, 
    {4, "LOCATION UPDATING REJECT"}, 
    {68, "LOCATION UPDATING REJECT"}, 
    {132, "LOCATION UPDATING REJECT"}, 
    {196, "LOCATION UPDATING REJECT"}, 
    {8, "LOCATION UPDATING REQUEST"}, 
    {72, "LOCATION UPDATING REQUEST"}, 
    {136, "LOCATION UPDATING REQUEST"}, 
    {200, "LOCATION UPDATING REQUEST"}, 
    {17, "AUTHENTICATION REJECT"}, 
    {81, "AUTHENTICATION REJECT"}, 
    {145, "AUTHENTICATION REJECT"}, 
    {209, "AUTHENTICATION REJECT"}, 
    {18, "AUTHENTICATION REQUEST"}, 
    {82, "AUTHENTICATION REQUEST"}, 
    {146, "AUTHENTICATION REQUEST"}, 
    {210, "AUTHENTICATION REQUEST"}, 
    {20, "AUTHENTICATION RESPONSE"}, 
    {84, "AUTHENTICATION RESPONSE"}, 
    {148, "AUTHENTICATION RESPONSE"}, 
    {212, "AUTHENTICATION RESPONSE"}, 
    {28, "AUTHENTICATION FAILURE"}, 
    {92, "AUTHENTICATION FAILURE"}, 
    {156, "AUTHENTICATION FAILURE"}, 
    {220, "AUTHENTICATION FAILURE"}, 
    {24, "IDENTITY REQUEST"}, 
    {88, "IDENTITY REQUEST"}, 
    {152, "IDENTITY REQUEST"}, 
    {216, "IDENTITY REQUEST"}, 
    {25, "IDENTITY RESPONSE"}, 
    {89, "IDENTITY RESPONSE"}, 
    {153, "IDENTITY RESPONSE"}, 
    {217, "IDENTITY RESPONSE"}, 
    {26, "TMSI REALLOCATION COMMAND"}, 
    {90, "TMSI REALLOCATION COMMAND"}, 
    {154, "TMSI REALLOCATION COMMAND"}, 
    {218, "TMSI REALLOCATION COMMAND"}, 
    {27, "TMSI REALLOCATION COMPLETE"}, 
    {91, "TMSI REALLOCATION COMPLETE"}, 
    {155, "TMSI REALLOCATION COMPLETE"}, 
    {219, "TMSI REALLOCATION COMPLETE"}, 
    {33, "CM SERVICE ACCEPT"}, 
    {97, "CM SERVICE ACCEPT"}, 
    {161, "CM SERVICE ACCEPT"}, 
    {225, "CM SERVICE ACCEPT"}, 
    {34, "CM SERVICE REJECT"}, 
    {98, "CM SERVICE REJECT"}, 
    {162, "CM SERVICE REJECT"}, 
    {226, "CM SERVICE REJECT"}, 
    {35, "CM SERVICE ABORT"}, 
    {99, "CM SERVICE ABORT"}, 
    {163, "CM SERVICE ABORT"}, 
    {227, "CM SERVICE ABORT"}, 
    {36, "CM SERVICE REQUEST"}, 
    {100, "CM SERVICE REQUEST"}, 
    {164, "CM SERVICE REQUEST"}, 
    {228, "CM SERVICE REQUEST"}, 
    {37, "CM SERVICE PROMPT"}, 
    {101, "CM SERVICE PROMPT"}, 
    {165, "CM SERVICE PROMPT"}, 
    {229, "CM SERVICE PROMPT"}, 
    {38, "Reserved (see NOTE)"}, 
    {102, "Reserved (see NOTE)"}, 
    {166, "Reserved (see NOTE)"}, 
    {230, "Reserved (see NOTE)"}, 
    {40, "CM RE-ESTABLISHMENT REQUEST"}, 
    {104, "CM RE-ESTABLISHMENT REQUEST"}, 
    {168, "CM RE-ESTABLISHMENT REQUEST"}, 
    {232, "CM RE-ESTABLISHMENT REQUEST"}, 
    {41, "ABORT"}, 
    {105, "ABORT"}, 
    {169, "ABORT"}, 
    {233, "ABORT"}, 
    {48, "MM NULL"}, 
    {112, "MM NULL"}, 
    {176, "MM NULL"}, 
    {240, "MM NULL"}, 
    {49, "MM STATUS"}, 
    {113, "MM STATUS"}, 
    {177, "MM STATUS"}, 
    {241, "MM STATUS"}, 
    {50, "MM INFORMATION"}, 
    {114, "MM INFORMATION"}, 
    {178, "MM INFORMATION"}, 
    {242, "MM INFORMATION"}, 
};

struct  code2dict message_type_cc[] = 
{
    {1, "ALERTING"}, 
    {65, "ALERTING"}, 
    {129, "ALERTING"}, 
    {193, "ALERTING"}, 
    {8, "CALL CONFIRMED"}, 
    {72, "CALL CONFIRMED"}, 
    {136, "CALL CONFIRMED"}, 
    {200, "CALL CONFIRMED"}, 
    {2, "CALL PROCEEDING"}, 
    {66, "CALL PROCEEDING"}, 
    {130, "CALL PROCEEDING"}, 
    {194, "CALL PROCEEDING"}, 
    {7, "CONNECT"}, 
    {71, "CONNECT"}, 
    {135, "CONNECT"}, 
    {199, "CONNECT"}, 
    {15, "CONNECT ACKNOWLEDGE"}, 
    {79, "CONNECT ACKNOWLEDGE"}, 
    {143, "CONNECT ACKNOWLEDGE"}, 
    {207, "CONNECT ACKNOWLEDGE"}, 
    {14, "EMERGENCY SETUP"}, 
    {78, "EMERGENCY SETUP"}, 
    {142, "EMERGENCY SETUP"}, 
    {206, "EMERGENCY SETUP"}, 
    {3, "PROGRESS"}, 
    {67, "PROGRESS"}, 
    {131, "PROGRESS"}, 
    {195, "PROGRESS"}, 
    {4, "CC-ESTABLISHMENT"}, 
    {68, "CC-ESTABLISHMENT"}, 
    {132, "CC-ESTABLISHMENT"}, 
    {196, "CC-ESTABLISHMENT"}, 
    {6, "CC-ESTABLISHMENT CONFIRMED"}, 
    {70, "CC-ESTABLISHMENT CONFIRMED"}, 
    {134, "CC-ESTABLISHMENT CONFIRMED"}, 
    {198, "CC-ESTABLISHMENT CONFIRMED"}, 
    {11, "RECALL"}, 
    {75, "RECALL"}, 
    {139, "RECALL"}, 
    {203, "RECALL"}, 
    {9, "START CC"}, 
    {73, "START CC"}, 
    {137, "START CC"}, 
    {201, "START CC"}, 
    {5, "SETUP"}, 
    {69, "SETUP"}, 
    {133, "SETUP"}, 
    {197, "SETUP"}, 
    {23, "MODIFY"}, 
    {87, "MODIFY"}, 
    {151, "MODIFY"}, 
    {215, "MODIFY"}, 
    {31, "MODIFY COMPLETE"}, 
    {95, "MODIFY COMPLETE"}, 
    {159, "MODIFY COMPLETE"}, 
    {223, "MODIFY COMPLETE"}, 
    {19, "MODIFY REJECT"}, 
    {83, "MODIFY REJECT"}, 
    {147, "MODIFY REJECT"}, 
    {211, "MODIFY REJECT"}, 
    {16, "USER INFORMATION"}, 
    {80, "USER INFORMATION"}, 
    {144, "USER INFORMATION"}, 
    {208, "USER INFORMATION"}, 
    {24, "HOLD"}, 
    {88, "HOLD"}, 
    {152, "HOLD"}, 
    {216, "HOLD"}, 
    {25, "HOLD ACKNOWLEDGE"}, 
    {89, "HOLD ACKNOWLEDGE"}, 
    {153, "HOLD ACKNOWLEDGE"}, 
    {217, "HOLD ACKNOWLEDGE"}, 
    {26, "HOLD REJECT"}, 
    {90, "HOLD REJECT"}, 
    {154, "HOLD REJECT"}, 
    {218, "HOLD REJECT"}, 
    {28, "RETRIEVE"}, 
    {92, "RETRIEVE"}, 
    {156, "RETRIEVE"}, 
    {220, "RETRIEVE"}, 
    {29, "RETRIEVE ACKNOWLEDGE"}, 
    {93, "RETRIEVE ACKNOWLEDGE"}, 
    {157, "RETRIEVE ACKNOWLEDGE"}, 
    {221, "RETRIEVE ACKNOWLEDGE"}, 
    {30, "RETRIEVE REJECT"}, 
    {94, "RETRIEVE REJECT"}, 
    {158, "RETRIEVE REJECT"}, 
    {222, "RETRIEVE REJECT"}, 
    {37, "DISCONNECT"}, 
    {101, "DISCONNECT"}, 
    {165, "DISCONNECT"}, 
    {229, "DISCONNECT"}, 
    {45, "RELEASE"}, 
    {109, "RELEASE"}, 
    {173, "RELEASE"}, 
    {237, "RELEASE"}, 
    {42, "RELEASE COMPLETE"}, 
    {106, "RELEASE COMPLETE"}, 
    {170, "RELEASE COMPLETE"}, 
    {234, "RELEASE COMPLETE"}, 
    {57, "CONGESTION CONTROL"}, 
    {121, "CONGESTION CONTROL"}, 
    {185, "CONGESTION CONTROL"}, 
    {249, "CONGESTION CONTROL"}, 
    {62, "NOTIFY"}, 
    {126, "NOTIFY"}, 
    {190, "NOTIFY"}, 
    {254, "NOTIFY"}, 
    {61, "STATUS"}, 
    {125, "STATUS"}, 
    {189, "STATUS"}, 
    {253, "STATUS"}, 
    {52, "STATUS ENQUIRY"}, 
    {116, "STATUS ENQUIRY"}, 
    {180, "STATUS ENQUIRY"}, 
    {244, "STATUS ENQUIRY"}, 
    {53, "START DTMF"}, 
    {117, "START DTMF"}, 
    {181, "START DTMF"}, 
    {245, "START DTMF"}, 
    {49, "STOP DTMF"}, 
    {113, "STOP DTMF"}, 
    {177, "STOP DTMF"}, 
    {241, "STOP DTMF"}, 
    {50, "STOP DTMF ACKNOWLEDGE"}, 
    {114, "STOP DTMF ACKNOWLEDGE"}, 
    {178, "STOP DTMF ACKNOWLEDGE"}, 
    {242, "STOP DTMF ACKNOWLEDGE"}, 
    {54, "START DTMF ACKNOWLEDGE"}, 
    {118, "START DTMF ACKNOWLEDGE"}, 
    {182, "START DTMF ACKNOWLEDGE"}, 
    {246, "START DTMF ACKNOWLEDGE"}, 
    {55, "START DTMF REJECT"}, 
    {119, "START DTMF REJECT"}, 
    {183, "START DTMF REJECT"}, 
    {247, "START DTMF REJECT"}, 
    {58, "FACILITY"}, 
    {122, "FACILITY"}, 
    {186, "FACILITY"}, 
    {250, "FACILITY"}, 
};

struct  code2dict message_type_sm[] = 
{
    {65, "Activate PDP context request"}, 
    {66, "Activate PDP context accept"}, 
    {67, "Activate PDP context reject"}, 
    {68, "Request PDP context activation"}, 
    {69, "Request PDP context activation rej."}, 

    {70, "Deactivate PDP context request"}, 
    {71, "Deactivate PDP context accept"}, 
    {72, "Modify PDP context request(Network to MS direction)"}, 
    {73, "Modify PDP context accept (MS to network direction)"}, 
    {74, "Modify PDP context request(MS to network direction)"}, 
    {75, "Modify PDP context accept (Network to MS direction)"}, 
    {76, "Modify PDP context reject"}, 
    {77, "Activate secondary PDP context request"}, 
    {78, "Activate secondary PDP context accept"}, 
    {79, "Activate secondary PDP context reject"}, 

    {80, "Reserved: was allocated in earlier phases of the protocol"}, 
    {81, "Reserved: was allocated in earlier phases of the protocol"}, 
    {82, "Reserved: was allocated in earlier phases of the protocol"}, 
    {83, "Reserved: was allocated in earlier phases of the protocol"}, 
    {84, "Reserved: was allocated in earlier phases of the protocol"}, 
    {85, "SM Status"}, 
    {86, "Activate MBMS Context Request"}, 
    {87, "Activate MBMS Context Accept"}, 
    {88, "Activate MBMS Context Reject"}, 
    {89, "Request MBMS Context Activation"}, 
    {90, "Request MBMS Context Activation Reject"},
    {91, "Request Secondary PDP Context Activation"},
    {92, "Request Secondary PDP Context Activation Reject"},
    {93, "Notification"},
};

struct  code2dict message_type_gmm[] = 
{
    {1, "Attach request"}, 
    {2, "Attach accept"}, 
    {3, "Attach complete"},
    {4, "Attach reject"},
    {5, "Detach request"},
    {6, "Detach accept"},
    {8, "Routing area update request"},
    {9, "Routing area update accept"},

    {10, "Routing area update complete"}, 
    {11, "Routing area update reject"}, 
    {12, "Service Request"}, 
    {13, "Service Accept"}, 
    {14, "Service Reject"}, 
    {16, "P-TMSI reallocation command"}, 
    {17, "P-TMSI reallocation complete"}, 
    {18, "Authentication and ciphering req"}, 
    {19, "Authentication and ciphering resp"}, 
    {20, "Authentication and ciphering rej"}, 
    {28, "Authentication and ciphering failure"}, 
    {21, "Identity request"}, 
    {22, "Identity response"}, 
    {32, "GMM status"}, 
    {33, "GMM information"}, 
};

struct  code2dict message_type_rr[] = 
{
    {60, "Reserved (see Note)"}, 
    {59, "ADDITIONAL ASSIGNMENT"}, 
    {63, "IMMEDIATE ASSIGNMENT"}, 
    {57, "IMMEDIATE ASSIGNMENT EXTENDED"}, 
    {58, "IMMEDIATE ASSIGNMENT REJECT"}, 
    {53, "CIPHERING MODE COMMAND"}, 
    {50, "CIPHERING MODE COMPLETE"}, 
    {48, "CONFIGURATION CHANGE COMMAND"}, 
    {49, "CONFIGURATION CHANGE ACK."}, 
    {51, "CONFIGURATION CHANGE REJECT"}, 
    {46, "ASSIGNMENT COMMAND"}, 
    {41, "ASSIGNMENT COMPLETE"}, 
    {47, "ASSIGNMENT FAILURE"}, 
    {43, "HANDOVER COMMAND"}, 
    {44, "HANDOVER COMPLETE"}, 
    {40, "HANDOVER FAILURE"}, 
    {45, "PHYSICAL INFORMATION"}, 
    {8, "Reserved (see Note)"}, 
    {35, "Reserved (see Note)"}, 
    {13, "CHANNEL RELEASE"}, 
    {10, "PARTIAL RELEASE"}, 
    {15, "PARTIAL RELEASE COMPLETE"}, 
    {33, "PAGING REQUEST TYPE 1"}, 
    {34, "PAGING REQUEST TYPE 2"}, 
    {36, "PAGING REQUEST TYPE 3"}, 
    {39, "PAGING RESPONSE"}, 
    {32, "NOTIFICATION/NCH"}, 
    {37, "Reserved (see NOTE)"}, 
    {38, "NOTIFICATION/RESPONSE"}, 
    {11, "Reserved (see NOTE)"}, 
    {24, "SYSTEM INFORMATION TYPE 8"}, 
    {25, "SYSTEM INFORMATION TYPE 1"}, 
    {26, "SYSTEM INFORMATION TYPE 2"}, 
    {27, "SYSTEM INFORMATION TYPE 3"}, 
    {28, "SYSTEM INFORMATION TYPE 4"}, 
    {29, "SYSTEM INFORMATION TYPE 5"}, 
    {30, "SYSTEM INFORMATION TYPE 6"}, 
    {31, "SYSTEM INFORMATION TYPE 7"}, 
    {2, "SYSTEM INFORMATION TYPE 2bis"}, 
    {3, "SYSTEM INFORMATION TYPE 2ter"}, 
    {7, "SYSTEM INFORMATION TYPE 2quater"}, 
    {5, "SYSTEM INFORMATION TYPE 5bis"}, 
    {6, "SYSTEM INFORMATION TYPE 5ter"}, 
    {4, "SYSTEM INFORMATION TYPE 9"}, 
    {0, "SYSTEM INFORMATION TYPE 13"}, 
    {61, "SYSTEM INFORMATION TYPE 16"}, 
    {62, "SYSTEM INFORMATION TYPE 17"}, 
    {16, "CHANNEL MODE MODIFY"}, 
    {18, "RR STATUS"}, 
    {23, "CHANNEL MODE MODIFY ACKNOWLEDGE"}, 
    {20, "FREQUENCY REDEFINITION"}, 
    {21, "MEASUREMENT REPORT"}, 
    {22, "CLASSMARK CHANGE"}, 
    {19, "CLASSMARK ENQUIRY"}, 
    {54, "EXTENDED MEASUREMENT REPORT"}, 
    {55, "EXTENDED MEASUREMENT ORDER"}, 
    {52, "GPRS SUSPENSION REQUEST"}, 
    {22, "MBMS ANNOUNCEMENT"}, 
    {54, "SERVICE INFORMATION"}, 
    {9, "VGCS UPLINK GRANT"}, 
    {14, "UPLINK RELEASE"}, 
    {12, "Reserved (see NOTE)"}, 
    {42, "UPLINK BUSY"}, 
    {17, "TALKER INDICATION"}, 
    {56, "APPLICATION INFORMATION"}, 
    {1, "SYSTEM INFORMATION TYPE 14"}, 
    {67, "SYSTEM INFORMATION TYPE 15"}, 
    {64, "SYSTEM INFORMATION TYPE 18"}, 
    {65, "SYSTEM INFORMATION TYPE 19"}, 
    {66, "SYSTEM INFORMATION TYPE 20"}, 
    {68, "SYSTEM INFORMATION TYPE 13alt"}, 
    {69, "SYSTEM INFORMATION TYPE 2n"}, 
    {72, "DTM ASSIGNMENT FAILURE"}, 
    {73, "DTM REJECT"}, 
    {74, "DTM REQUEST"}, 
    {75, "PACKET ASSIGNMENT"}, 
    {76, "DTM ASSIGNMENT COMMAND"}, 
    {77, "DTM INFORMATION"}, 
    {78, "PACKET NOTIFICATION"}, 
    {96, "UTRAN CLASSMARK CHANGE"}, 
    {98, "CDMA 2000 CLASSMARK CHANGE"}, 
    {99, "INTER SYSTEM TO UTRAN HANDOVER COMMAND"}, 
    {100, "INTER SYSTEM TO CDMA2000 HANDOVER COMMAND"}, 
    {101, "GERAN IU MODE CLASSMARK CHANGE"}, 
};

struct  code2dict ciphering_key_s_key_sequence[] = 
{
    {0, "Possible values for the ciphering key sequence number "}, 
    {1, "Possible values for the ciphering key sequence number "}, 
    {2, "Possible values for the ciphering key sequence number "}, 
    {3, "Possible values for the ciphering key sequence number "}, 
    {4, "Possible values for the ciphering key sequence number "}, 
    {5, "Possible values for the ciphering key sequence number "}, 
    {6, "Possible values for the ciphering key sequence number "}, 
    {7, "Reserved "}, 
};


struct  code2dict cm_service_type_service_type[] = 
{
    {1, "Mobile originating call establishment or packet mode connection establishment "}, 
    {2, "Emergency call establishment "}, 
    {4, "Short message service "}, 
    {8, "Supplementary service activation "}, 
    {9, "Voice group call establishment "}, 
    {10, "Voice broadcast call establishment "}, 
    {11, "Location Services "}, 
};


struct  code2dict mobile_station_revision_level[] = 
{
    {0, "Reserved for GSM phase 1 "}, 
    {1, "Used by GSM phase 2 mobile stations "}, 
    {2, "Used by mobile stations supporting R99 or later versions of the protocol "}, 
    {3, "Reserved for future use If the network receives a revision level specified as 'reserved for future use', then it shall  use the highest revision level supported by the network."}, 
};

struct  code2dict mobile_station_es_ind[] = 
{
    {0, "Controlled Early Classmark Sending option is not implemented in the MS "}, 
    {1, "Controlled Early Classmark Sending option is implemented in the MS "}, 
};

struct  code2dict mobile_station_A51_algorithm_s[] = 
{
    {0, "encryption algorithm A5/1 available "}, 
    {1, "encryption algorithm A5/1 not available "}, 
};

struct  code2dict mobile_station_rf_power_c[] = 
{
    {0, "class 1 "}, 
    {1, "class 2 "}, 
    {2, "class 3 "}, 
    {3, "class 4 "}, 
    {4, "class 5 "}, 
    {5, "reserved "}, 
    {6, "reserved "}, 
    {7, "reserved "}, 
};

struct  code2dict mobile_station_ps_capability[] = 
{
    {0, "PS capability not present "}, 
    {1, "PS capability present "}, 
};

struct  code2dict mobile_station_sm_capability[] = 
{
    {0, "Mobile station does not support mobile terminated point to point SMS "}, 
    {1, "Mobile station supports mobile terminated point to point SMS "}, 
};

struct  code2dict mobile_station_vbs_notification_r[] = 
{
    {0, "no VBS capability or no notifications wanted "}, 
    {1, "VBS capability and notifications wanted "}, 
};

struct  code2dict mobile_station_vgcs_notification_r[] = 
{
    {0, "no VGCS capability or no notifications wanted "}, 
    {1, "VGCS capability and notifications wanted "}, 
};

struct  code2dict mobile_station_fc_frequency_c[] = 
{
    {0, "The MS does not support the E-GSM or R-GSM band "}, 
    {1, "The MS does support the E-GSM or R-GSM "}, 
};

struct  code2dict mobile_station_cm3[] = 
{
    {0, "The MS does not support any options that are indicated in CM3 "}, 
    {1, "The MS supports options that are indicated in classmark 3 IE "}, 
};

struct  code2dict mobile_station_lcs_va_c[] = 
{
    {0, "location request notification via CS domain not supported "}, 
    {1, "location request notification via CS domain supported "}, 
};

struct  code2dict mobile_station_ucs2_treatment[] = 
{
    {0, "the ME has a preference for the default alphabet. "}, 
    {1, "the ME has no preference between the use of the default alphabet and the use of UCS2. "}, 
};

struct  code2dict mobile_station_solsa[] = 
{
    {0, "The ME does not support SoLSA. "}, 
    {1, "The ME supports SoLSA. "}, 
};

struct  code2dict mobile_station_cmsp[] = 
{
    {0, "Network initiated MO CM connection request not supported. "}, 
    {1, "Network initiated MO CM connection request supported for at least one CM protocol. "}, 
};

struct  code2dict mobile_station_A53_algorithm_s[] = 
{
    {0, "encryption algorithm A5/3 not available "}, 
    {1, "encryption algorithm A5/3 available "}, 
};

struct  code2dict mobile_station_a52_algorithm_s[] = 
{
    {0, "encryption algorithm A5/2 not available "}, 
    {1, "Not used. This value was allocated in earlier versions of the protocol. "}, 
};


struct  code2dict mobile_identity_odd_even_i[] = 
{
    {0, "even number of identity digits and also when the TMSI/P-TMSI or TMGI and optional MBMS Session Identity is used "}, 
    {1, "odd number of identity digits "}, 
};


struct  code2dict mobile_identity_mcc_mnc_i[] = 
{
    {0, "MCC/MNC is not present "}, 
    {1, "MCC/MNC is present "}, 
};

struct  code2dict mobile_identity_mbms_session_i_i[] = 
{
    {0, "MBMS Session Identity is not present "}, 
    {1, "MBMS Session Identity is present "}, 
};


struct  code2dict priority_level_call_priority[] = 
{
    {0, "no priority applied "}, 
    {1, "call priority level 4 "}, 
    {2, "call priority level 3 "}, 
    {3, "call priority level 2 "}, 
    {4, "call priority level 1 "}, 
    {5, "call priority level 0 "}, 
    {6, "call priority level B "}, 
    {7, "call priority level A "}, 
};


struct  code2dict additional_update_p_csmt[] = 
{
    {0, "No additional information. "}, 
    {1, "CS fallback mobile terminating call "}, 
};

struct  code2dict additional_update_p_csmo[] = 
{
    {0, "No additional information. "}, 
    {1, "CS fallback mobile originating call "}, 
};


struct  code2dict device_properties_low_priority[] = 
{
    {0, "MS is not configured for NAS signalling low priority "}, 
    {1, "MS is configured for NAS signalling low priority "}, 
};

struct  code2dict page_mode_pm[] = 
{
    {0, "Normal paging."}, 
    {1, "Extended paging."}, 
    {2, "Paging reorganization."}, 
    {3, "Same as before."}, 
};

struct  code2dict immediate_assignment_dedicated_mode_or_tbf[] = 
{
    {0, "This message assigns a dedicated mode resource"}, 
    {2, "Not used"}, 
    {4, "Not used"}, 
    {6, "Not used"}, 
    {1, "This message assigns an uplink TBF or is the second message of two in a two-message assignment of an uplink or downlink TBF"}, 
    {3, "This message assigns a downlink TBF to the mobile station identified in the IA Rest Octets IE"}, 
    {5, "This message is the first message of two in a two-message assignment of an uplink TBF"}, 
    {7, "This message is the first message of two in a two-message assignment of a downlink TBF to the mobile station identified in the IA Rest Octets IE"},
};

//10.5.2.5

struct  code2dict channel_description_channel_type_t_o[] =
{
    {1, "TCH/F + ACCHs"},
    {2, "TCH/H + ACCHs"},
    {3, "TCH/H + ACCHs"},
    {4, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {5, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {6, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {7, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {8, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {9, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {10, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {11, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {12, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {13, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {14, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {15, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
};

struct  code2dict channel_description_h[] =
{
    {0, "Single RF channel"},
    {1, "RF hopping channel"},
};

struct  code2dict mobile_identity_type_identity[] = 
{
    {1, "IMSI"}, 
    {2, "IMEI"}, 
    {3, "IMEISV"}, 
    {4, "TMSI/P-TMSI/M-TMSI"}, 
    {5, "TMGI and optional MBMS Session Identity"}, 
    {0, "No Identity"}, 
};

struct  code2dict cipher_mode_s_algorithm_identifier[] = 
{
    {0, "cipher with algorithm A5/1"}, 
    {1, "cipher with algorithm A5/2"}, 
    {2, "cipher with algorithm A5/3"}, 
    {3, "cipher with algorithm A5/4"}, 
    {4, "cipher with algorithm A5/5"}, 
    {5, "cipher with algorithm A5/6"}, 
    {6, "cipher with algorithm A5/7"}, 
    {7, "reserved"}, 
};

struct  code2dict cipher_response_cr_c_r[] =
{
    {0, "IMEISV shall not be included"},
    {1, "IMEISV shall be included"},
};

struct  code2dict cipher_mode_s_sc[] = 
{
    {0, "No ciphering"}, 
    {1, "Start ciphering"}, 
};

struct  code2dict repeat_indicator_repeat_indication[] = 
{
    {1, "Circular for successive selection \"mode 1 alternate mode 2\""}, 
    {2, "Support of fallback ¨C mode 1 preferred, mode 2 selected if setup of mode 1 fails"},
    {3, "reserved: was allocated in earlier phases of the protocol"}, 
    {4, "Service change and fallback ¨C mode 1 alternate mode 2, mode 1 preferred"},
};

struct  code2dict bearer_capability_radio_channel_r[] =
{
    {0, "reserved"},
    {1, "full rate support only MS"},
    {2, "dual rate support MS/half rate preferred"},
    {3, "dual rate support MS/full rate preferred"},
};
struct  code2dict bearer_capability_information_transfer_c[] =
{
    {0, "speech"},
    {1, "unrestricted digital information"},
    {2, "3.1 kHz audio, ex PLMN"},
    {3, "facsimile group 3"},
    {4, "reserved"},
    {5, "Other ITC"},
    {6, "reserved"},
    {7, "reserved, to be used in the network"},
};

struct  code2dict bearer_capability_coding_standard[] =
{
    {0, "GSM standardized coding as described below"},
    {1, "reserved"},
};
struct  code2dict bearer_capability_transfer_mode[] =
{
    {0, "circuit mode"},
    {1, "packet mode"},
};

struct  code2dict bearer_capability_coding[] =
{
    {0, "octet used for extension of information transfer capability"},
    {1, "octet used for other extension of octet 3"},
};

struct  code2dict bearer_capability_ctm_text_t_i[] =
{
    {0, "CTM text telephony is not supported"},
    {1, "CTM text telephony is supported"},
};

struct  code2dict bearer_capability_speech_version_i[] =
{
    {0, "GSM full rate speech version 1"},
    {2, "GSM full rate speech version 2"},
    {4, "GSM full rate speech version 3"},
    {6, "GSM full rate speech version 4"},
    {8, "GSM full rate speech version 5"},
    {1, "GSM half rate speech version 1"},
    {5, "GSM half rate speech version 3"},
    {7, "GSM half rate speech version 4"},
    {11, "GSM half rate speech version 6"},
    {15, "no speech version supported for GERAN"},
    {14, "speech version tbd"},
    {13, "speech version tbd"},
    {12, "speech version tbd"},
    {10, "speech version tbd"},
    {9, "speech version tbd"},
    {3, "speech version tbd"},
};

struct  code2dict bearer_capability_compression_n_m[] =
{
    {0, "data compression not possible"},
    {1, "data compression possible"},
};

struct  code2dict bearer_capability_compression_m_n[] =
{
    {0, "data compression not allowed"},
    {1, "data compression allowed"},
};

struct  code2dict bearer_capability_structure[] =
{
    {0, "service data unit integrity"},
    {1, "reserved"},
    {2, "reserved"},
    {3, "unstructured"},
};

struct  code2dict bearer_capability_duplex_mode[] =
{
    {0, "half duplex"},
    {1, "full duplex"},
};

struct  code2dict bearer_capability_configuration[] =
{
    {0, "point-to-point"},
};

struct  code2dict bearer_capability_nirr[] =
{
    {0, "No meaning is associated with this value."},
    {1, "Data up to and including 4.8 kb/s, full rate, non-transparent, 6 kb/s radio interface rate is requested."},
};

struct  code2dict bearer_capability_establishment[] =
{
    {0, "demand"},
};  
    
struct  code2dict bearer_capability_access_identity[] =
{
    {0, "octet identifier"},
};

struct  code2dict bearer_capability_rate_adaption[] =
{   
    {0, "no rate adaption"},
    {1, "rate adaptation according to ITU-T Rec. V.110 [66] and ITU-T Rec. X.30 [65]"},
    {2, "flag stuffing according to ITU-T Rec. X.31 [66]"},
    {3, "Other rate adaption"},
};  
    
struct  code2dict bearer_capability_signalling_access_p[] =
{
    {1, "according to ITU-T Rec. Q.920 [49] and ITU-T Rec. Q.930 [50]"},
    {2, "reserved: was allocated in earlier phases of the protocol"},
    {3, "reserved: was allocated in earlier phases of the protocol"},
    {4, "reserved: was allocated in earlier phases of the protocol"},
    {5, "reserved: was allocated in earlier phases of the protocol"},
    {6, "reserved: was allocated in earlier phases of the protocol"},
};

struct  code2dict bearer_capability_other_itc[] =
{
    {0, "restricted digital information"},
};

struct  code2dict bearer_capability_other_rate_a[] =
{
    {0, "according to ITU-T Rec. V.120 [61]"},
    {1, "according to ITU-T Rec. H.223 [146] and ITU-T Rec. H.245 [119]"},
    {2, "PIAFS"},
};

struct  code2dict bearer_capability_rate_adaption_h[] =
{
    {0, "Rate adaption header not included"},
    {1, "Rate adaption header included"},
};

struct  code2dict bearer_capability_multiple_frame_e[] =
{
    {0, "Multiple frame establishment not supported, only UI frames allowed"},
    {1, "Multiple frame establishment supported"},
};

struct  code2dict bearer_capability_mode_operation[] =
{
    {0, "Bit transparent mode of operation"},
    {1, "Protocol sensitive mode of operation"},
};

struct  code2dict bearer_capability_logical_link_i[] =
{
    {0, "Default, LLI=256 only"},
    {1, "Full protocol negotiation"},
};

struct  code2dict bearer_capability_assignor_assignee[] =
{
    {0, "Message originator is \"default assignee\""},
    {1, "Message originator is \"assignor only\""},
};

struct  code2dict bearer_capability_inout_negotiation[] =
{
    {0, "Negotiation is done in-band using logical link zero"},
    {1, "Negotiation is done with USER INFORMATION messages on a temporarysignalling connection"},
};

struct  code2dict bearer_capability_layer_identity[] =
{
    {1, "octet identifier"},
};

struct  code2dict bearer_capability_user_information_l_p[] =
{
    {0, "default layer 1 protocol"},
};

struct  code2dict bearer_capability_synchronous_asynchronou[] =
{
    {0, "synchronous"},
    {1, "asynchronous"},
};

struct  code2dict bearer_capability_number_stop_b[] =
{
    {1, "bit"},
    {1, "2 bits"},
};

struct  code2dict bearer_capability_negotiation[] =
{
    {0, "in-band negotiation not possible"},
};

struct  code2dict bearer_capability_number_data_b_e_p[] =
{
    {0, "7 bits"},
    {1, "8 bits"},
};

struct  code2dict bearer_capability_user_rate[] =
{
    {1, "0.3 kbit/s according to ITU-T Rec. X.1 [142] and ITU-T Rec. V.110 [60]"},
    {2, "1.2 kbit/s according to ITU-T Rec. X.1 [142] and ITU-T Rec. V.110 [60]"},
    {3, "2.4 kbit/s according to ITU-T Rec. X.1 [142] and ITU-T Rec. V.110 [60]"},
    {4, "4.8 kbit/s according to ITU-T Rec. X.1 [142] and ITU-T Rec. V.110 [60]"},
    {5, "9.6 kbit/s according to ITU-T Rec. X.1 [142] and ITU-T Rec. V.110 [60]"},
    {0, "kbit/s transparent (non compliance with ITU-T Rec. X.1 [142] and ITU- T Rec. V.110 [60])"},
    {7, "reserved: was allocated in earlier phases of the protocol."},
};

struct  code2dict bearer_capability_intermediate_rate[] =
{
    {0, "reserved"},
    {1, "reserved"},
    {2, "8 kbit/s"},
    {3, "16 kbit/s"},
};

struct  code2dict bearer_capability_nic_tx[] =
{
    {0, "does not require to send data with network independent clock"},
    {1, "requires to send data with network independent clock"},
};

struct  code2dict bearer_capability_nic_rx[] =
{
    {0, "cannot accept data with network independent clock (i.e. sender does not support this optional procedure)"},
    {1, "can accept data with network independent clock (i.e. sender does support this optional procedure)"},
};

struct  code2dict bearer_capability_parity_information[] =
{
    {0, "odd"},
    {2, "even"},
    {3, "none"},
    {4, "forced to 0"},
    {5, "forced to 1"},
};

struct  code2dict bearer_capability_connection_element[] =
{
    {0, "transparent"},
    {1, "non transparent (RLP)"},
    {2, "both, transparent preferred"},
    {3, "both, non transparent preferred"},
};

struct  code2dict bearer_capability_modem_type[] =
{
    {0, "none"},
    {1, "according to ITU-T Rec. V.21 [54]"},
    {2, "according to ITU-T Rec. V.22 [55]"},
    {3, "according to ITU-T Rec. V.22 bis [56]"},
    {4, "reserved: was allocated in earlier phases of the protocol"},
    {5, "according to ITU-T Rec. V.26 ter [58]"},
    {6, "according to ITU-T Rec. V.32 [59]"},
    {7, "modem for undefined interface"},
    {8, "autobauding type 1"},
};

struct  code2dict bearer_capability_other_modem_type[] =
{
    {0, "no other modem type specified in this field"},
    {2, "according to ITU-T Rec. V.34 [148]"},
};

struct  code2dict bearer_capability_fixed_network_u_r[] =
{
    {0, "Fixed network user rate not applicable/No meaning is associated with this value."},
    {1, "9.6 kbit/s (according to ITU-T Rec. X.1 [142] and ITU-T Rec. V.110 [60])"},
    {2, "14.4 kbit/s (according to ITU-T Rec. X.1 [142] and V.110 [60])"},
    {3, "19.2 kbit/s (according to ITU-T Rec. X.1 [142] and V.110 [60])"},
    {4, "28.8 kbit/s (according to ITU-T Rec. X.1 [142] and V.110 [60])"},
    {5, "38.4 kbit/s (according to ITU-T Rec. X.1 [142] and V.110 [60])"},
    {6, "48.0 kbit/s (according to ITU-T Rec. X.1 [142] and V.110 [60] (synch) )"},
    {7, "56.0 kbit/s (according to ITU-T Rec. X.1 [142] and V.110 [60] (synch) /bit transparent)"},
    {8, "64.0 kbit/s bit transparent"},
    {9, "33.6 kbit/s bit transparent "},
    {10, "32.0 kbit/s (according to ITU-T Rec. I.460 [79])"},
    {11, "31.2 kbit/s (according to ITU-T Rec. V.34 [148] )"},
};

struct  code2dict bearer_capability_uimi[] =
{
    {0, "User initiated modification not allowed/applicable"},
    {1, "User initiated modification up to 1 TCH/F allowed/may be requested"},
    {2, "User initiated modification up to 2 TCH/F allowed/may be requested"},
    {3, "User initiated modification up to 3 TCH/F allowed/may be requested"},
    {4, "User initiated modification up to 4 TCH/F allowed/may be requested"},
};

struct  code2dict bearer_capability_layer2_identity[] =
{
    {2, "octet identifier"},
};

struct  code2dict bearer_capability_user_information_l2_p[] =
{
    {6, "reserved: was allocated in earlier phases of the protocol"},
    {8, "according to ISO/IEC 6429 [42], codeset 0 (DC1/DC3)"},
    {9, "reserved: was allocated but never used in earlier phases of the protocol"},
    {10, "videotex profile 1"},
    {12, "COPnoFlCt (Character oriented Protocol with no Flow Control mechanism)"},
    {13, "reserved: was allocated in earlier phases of the protocol"},
};

struct  code2dict ext_dict[] =
{
    {0, "extension"},
    {1, "no extension"},
};

struct  code2dict bearer_capability_asymmetry_indication[] =
{
    {0, "Channel coding symmetry preferred"},
    {1, "Downlink biased channel coding asymmetry is preferred"},
    {2, "Uplink biased channel coding asymmetry is preferred"},
    {3, "Unused, if received it shall be interpreted as \"Channel coding symmetry preferred\""},
};

struct  code2dict bearer_capability_maximum_number_o_t_c[] =
{
    {0, "1 TCH"},
    {1, "2 TCH"},
    {2, "3 TCH"},
    {3, "4 TCH"},
    {4, "5 TCH"},
    {5, "6 TCH"},
    {6, "7 TCH"},
    {7, "8 TCH"},
};

struct  code2dict bearer_capability_wanted_air_i_u_r[]=
{
    {1, "9.6 kbit/s"},
    {2, "14.4 kbit/s"},
    {3, "19.2 kbit/s"},
    {5, "28.8 kbit/s"},
    {6, "38.4 kbit/s"},
    {7, "43.2 kbit/s"},
    {8, "57.6 kbit/s"},
    {9, "interpreted by the network as 38.4 kbit/s in this version of the protocol"},
    {10, "interpreted by the network as 38.4 kbit/s in this version of the protocol"},
    {11, "interpreted by the network as 38.4 kbit/s in this version of the protocol"},
    {12, "interpreted by the network as 38.4 kbit/s in this version of the protocol"},
};
struct  code2dict reject_cause_reject_cause_v[] =
{
    {2, "IMSI unknown in HLR"},
    {3, "Illegal MS"},
    {4, "IMSI unknown in VLR"},
    {5, "IMEI not accepted"},
    {6, "Illegal ME"},
    {11, "PLMN not allowed"},
    {12, "Location Area not allowed"},
    {13, "Roaming not allowed in this location area"},
    {15, "No Suitable Cells In Location Area"},
    {17, "Network failure"},
    {20, "MAC failure"},
    {21, "Synch failure"},
    {22, "Congestion"},
    {23, "GSM authentication unacceptable"},
    {25, "Not authorized for this CSG"},
    {32, "Service option not supported"},
    {33, "Requested service option not subscribed"},
    {34, "Service option temporarily out of order"},
    {38, "Call cannot be identified"},
    {48, "retry upon entry into a new cell"},
    {63, "retry upon entry into a new cell"},
    {95, "Semantically incorrect message"},
    {96, "Invalid mandatory information"},
    {97, "Message type non-existent or not implemented"},
    {98, "Message type not compatible with the protocol state"},
    {99, "Information element non-existent or not implemented"},
    {100, "Conditional IE error"},
    {101, "Message not compatible with the protocol state"},
    {111, "Protocol error, unspecified"},
};
struct  code2dict mm_timer_timer_value[] =
{
    {0, "value is incremented in multiples of 2 seconds"},
    {1, "value is incremented in multiples of 1 minute"},
    {2, "value is incremented in multiples of decihours"},
    {7, "value indicates that the timer is deactivated."},
};

struct  code2dict lut[] =
{
    {0, "Normal location updating"},
    {1, "Periodic updating"},
    {2, "MSI attach"},
    {3, "Reserved"},
};
struct  code2dict for1[] =
{
    {0, "No follow-on request pending"},
    {1, "Follow-on request pending"},
};
struct  code2dict ms_network_fea_sup_extended_periodic_t[] =
{
    {0, "MS does not support the extended periodic timer in this domain"},
    {1, "MS supports the extended periodic timer in this domain"},
};

struct  code2dict progress_indicator_coding_standard[] =
{
    {0, "Standardized coding, as described in ITU-T Rec. Q.931"},
    {1, "Reserved for other international standards"},
    {2, "National standard"},
    {3, "Standard defined for the GSM PLMNS as described below"},
};

struct  code2dict progress_indicator_location[] =
{
    {0, "User"},
    {1, "Private network serving the local user"},
    {2, "Public network serving the local user"},
    {3, "transit network"},
    {4, "Public network serving the remote user"},
    {5, "Private network serving the remote user"},
    {7, "international network"},
    {10, "Network beyond interworking point"},
};

struct  code2dict progress_indicator_progress_description[] =
{
    {1, "Call is not end-to-end PLMN/ISDN, further call progress information may be available in-band"},
    {2, "Destination address in non-PLMN/ISDN"},
    {3, "Origination address in non-PLMN/ISDN"},
    {4, "Call has returned to the PLMN/ISDN"},
    {8, "In-band information or appropriate pattern now available"},
    {9, "In-band multimedia CAT available"},
    {32, "Call is end-to-end PLMN/ISDN"},
    {64, "Queueing"},
};

struct  code2dict network_call_c_c_mcs[] =
{
    {0, "This value indicates that the network does not support the multicall."},
    {1, "This value indicates that the network supports the multicall."},
}; 

struct  code2dict rr_cause_rr_cause_v[] = 
{
    {0, "Normal event"}, 
    {1, "Abnormal release, unspecified"}, 
    {2, "Abnormal release, channel unacceptable"}, 
    {3, "Abnormal release, timer expired"}, 
    {4, "Abnormal release, no activity on the radio path"}, 
    {5, "Preemptive release"}, 
    {6, "UTRAN configuration unknown"}, 
    {8, "Handover impossible, timing advance out of range"}, 
    {9, "Channel mode unacceptable"}, 
    {10, "Frequency not implemented"}, 
    {11, "Originator or talker leaving group call area"}, 
    {12, "Lower layer failure"}, 
    {65, "Call already cleared"}, 
    {95, "Semantically incorrect message"}, 
    {96, "Invalid mandatory information"}, 
    {97, "Message type non-existent or not implemented"}, 
    {98, "Message type not compatible with protocol state"}, 
    {100, "Conditional IE error"}, 
    {101, "No cell allocation available"}, 
    {111, "Protocol error unspecified"}, 
};

struct  code2dict user_user_user_user_p_d[] = 
{
    {0, "User specific protocol"}, 
    {1, "OSI high layer protocols"}, 
    {2, "X.244"}, 
    {3, "Reserved for system management convergence function"}, 
    {4, "IA5 characters"}, 
    {7, "rate adaption according to ITU-T Rec. V.120 [61]"}, 
    {8, "user-network call control messages according to ITU-T Rec. Q.931 [53]"}, 
    {16, "Reserved for other network layer or layer 3 protocols"}, 
    {17, "Reserved for other network layer or layer 3 protocols"}, 
    {18, "Reserved for other network layer or layer 3 protocols"}, 
    {19, "Reserved for other network layer or layer 3 protocols"}, 
    {20, "Reserved for other network layer or layer 3 protocols"}, 
    {21, "Reserved for other network layer or layer 3 protocols"}, 
    {22, "Reserved for other network layer or layer 3 protocols"}, 
    {23, "Reserved for other network layer or layer 3 protocols"}, 
    {24, "Reserved for other network layer or layer 3 protocols"}, 
    {25, "Reserved for other network layer or layer 3 protocols"}, 
    {26, "Reserved for other network layer or layer 3 protocols"}, 
    {27, "Reserved for other network layer or layer 3 protocols"}, 
    {28, "Reserved for other network layer or layer 3 protocols"}, 
    {29, "Reserved for other network layer or layer 3 protocols"}, 
    {30, "Reserved for other network layer or layer 3 protocols"}, 
    {31, "Reserved for other network layer or layer 3 protocols"}, 
    {32, "Reserved for other network layer or layer 3 protocols"}, 
    {33, "Reserved for other network layer or layer 3 protocols"}, 
    {34, "Reserved for other network layer or layer 3 protocols"}, 
    {35, "Reserved for other network layer or layer 3 protocols"}, 
    {36, "Reserved for other network layer or layer 3 protocols"}, 
    {37, "Reserved for other network layer or layer 3 protocols"}, 
    {38, "Reserved for other network layer or layer 3 protocols"}, 
    {39, "Reserved for other network layer or layer 3 protocols"}, 
    {40, "Reserved for other network layer or layer 3 protocols"}, 
    {41, "Reserved for other network layer or layer 3 protocols"}, 
    {42, "Reserved for other network layer or layer 3 protocols"}, 
    {43, "Reserved for other network layer or layer 3 protocols"}, 
    {44, "Reserved for other network layer or layer 3 protocols"}, 
    {45, "Reserved for other network layer or layer 3 protocols"}, 
    {46, "Reserved for other network layer or layer 3 protocols"}, 
    {47, "Reserved for other network layer or layer 3 protocols"}, 
    {48, "Reserved for other network layer or layer 3 protocols"}, 
    {49, "Reserved for other network layer or layer 3 protocols"}, 
    {50, "Reserved for other network layer or layer 3 protocols"}, 
    {51, "Reserved for other network layer or layer 3 protocols"}, 
    {52, "Reserved for other network layer or layer 3 protocols"}, 
    {53, "Reserved for other network layer or layer 3 protocols"}, 
    {54, "Reserved for other network layer or layer 3 protocols"}, 
    {55, "Reserved for other network layer or layer 3 protocols"}, 
    {56, "Reserved for other network layer or layer 3 protocols"}, 
    {57, "Reserved for other network layer or layer 3 protocols"}, 
    {58, "Reserved for other network layer or layer 3 protocols"}, 
    {59, "Reserved for other network layer or layer 3 protocols"}, 
    {60, "Reserved for other network layer or layer 3 protocols"}, 
    {61, "Reserved for other network layer or layer 3 protocols"}, 
    {62, "Reserved for other network layer or layer 3 protocols"}, 
    {63, "Reserved for other network layer or layer 3 protocols"}, 
    {64, "National use"}, 
    {65, "National use"}, 
    {66, "National use"}, 
    {67, "National use"}, 
    {68, "National use"}, 
    {69, "National use"}, 
    {70, "National use"}, 
    {71, "National use"}, 
    {72, "National use"}, 
    {73, "National use"}, 
    {74, "National use"}, 
    {75, "National use"}, 
    {76, "National use"}, 
    {77, "National use"}, 
    {78, "National use"}, 
    {79, "3GPP capability exchange protocol"}, 
    {80, "Reserved for other network layer or layer 3 protocols"}, 
    {81, "Reserved for other network layer or layer 3 protocols"}, 
    {82, "Reserved for other network layer or layer 3 protocols"}, 
    {83, "Reserved for other network layer or layer 3 protocols"}, 
    {84, "Reserved for other network layer or layer 3 protocols"}, 
    {85, "Reserved for other network layer or layer 3 protocols"}, 
    {86, "Reserved for other network layer or layer 3 protocols"}, 
    {87, "Reserved for other network layer or layer 3 protocols"}, 
    {88, "Reserved for other network layer or layer 3 protocols"}, 
    {89, "Reserved for other network layer or layer 3 protocols"}, 
    {90, "Reserved for other network layer or layer 3 protocols"}, 
    {91, "Reserved for other network layer or layer 3 protocols"}, 
    {92, "Reserved for other network layer or layer 3 protocols"}, 
    {93, "Reserved for other network layer or layer 3 protocols"}, 
    {94, "Reserved for other network layer or layer 3 protocols"}, 
    {95, "Reserved for other network layer or layer 3 protocols"}, 
    {96, "Reserved for other network layer or layer 3 protocols"}, 
    {97, "Reserved for other network layer or layer 3 protocols"}, 
    {98, "Reserved for other network layer or layer 3 protocols"}, 
    {99, "Reserved for other network layer or layer 3 protocols"}, 
    {100, "Reserved for other network layer or layer 3 protocols"}, 
    {101, "Reserved for other network layer or layer 3 protocols"}, 
    {102, "Reserved for other network layer or layer 3 protocols"}, 
    {103, "Reserved for other network layer or layer 3 protocols"}, 
    {104, "Reserved for other network layer or layer 3 protocols"}, 
    {105, "Reserved for other network layer or layer 3 protocols"}, 
    {106, "Reserved for other network layer or layer 3 protocols"}, 
    {107, "Reserved for other network layer or layer 3 protocols"}, 
    {108, "Reserved for other network layer or layer 3 protocols"}, 
    {109, "Reserved for other network layer or layer 3 protocols"}, 
    {110, "Reserved for other network layer or layer 3 protocols"}, 
    {111, "Reserved for other network layer or layer 3 protocols"}, 
    {112, "Reserved for other network layer or layer 3 protocols"}, 
    {113, "Reserved for other network layer or layer 3 protocols"}, 
    {114, "Reserved for other network layer or layer 3 protocols"}, 
    {115, "Reserved for other network layer or layer 3 protocols"}, 
    {116, "Reserved for other network layer or layer 3 protocols"}, 
    {117, "Reserved for other network layer or layer 3 protocols"}, 
    {118, "Reserved for other network layer or layer 3 protocols"}, 
    {119, "Reserved for other network layer or layer 3 protocols"}, 
    {120, "Reserved for other network layer or layer 3 protocols"}, 
    {121, "Reserved for other network layer or layer 3 protocols"}, 
    {122, "Reserved for other network layer or layer 3 protocols"}, 
    {123, "Reserved for other network layer or layer 3 protocols"}, 
    {124, "Reserved for other network layer or layer 3 protocols"}, 
    {125, "Reserved for other network layer or layer 3 protocols"}, 
    {126, "Reserved for other network layer or layer 3 protocols"}, 
    {127, "Reserved for other network layer or layer 3 protocols"}, 
    {128, "Reserved for other network layer or layer 3 protocols"}, 
    {129, "Reserved for other network layer or layer 3 protocols"}, 
    {130, "Reserved for other network layer or layer 3 protocols"}, 
    {131, "Reserved for other network layer or layer 3 protocols"}, 
    {132, "Reserved for other network layer or layer 3 protocols"}, 
    {133, "Reserved for other network layer or layer 3 protocols"}, 
    {134, "Reserved for other network layer or layer 3 protocols"}, 
    {135, "Reserved for other network layer or layer 3 protocols"}, 
    {136, "Reserved for other network layer or layer 3 protocols"}, 
    {137, "Reserved for other network layer or layer 3 protocols"}, 
    {138, "Reserved for other network layer or layer 3 protocols"}, 
    {139, "Reserved for other network layer or layer 3 protocols"}, 
    {140, "Reserved for other network layer or layer 3 protocols"}, 
    {141, "Reserved for other network layer or layer 3 protocols"}, 
    {142, "Reserved for other network layer or layer 3 protocols"}, 
    {143, "Reserved for other network layer or layer 3 protocols"}, 
    {144, "Reserved for other network layer or layer 3 protocols"}, 
    {145, "Reserved for other network layer or layer 3 protocols"}, 
    {146, "Reserved for other network layer or layer 3 protocols"}, 
    {147, "Reserved for other network layer or layer 3 protocols"}, 
    {148, "Reserved for other network layer or layer 3 protocols"}, 
    {149, "Reserved for other network layer or layer 3 protocols"}, 
    {150, "Reserved for other network layer or layer 3 protocols"}, 
    {151, "Reserved for other network layer or layer 3 protocols"}, 
    {152, "Reserved for other network layer or layer 3 protocols"}, 
    {153, "Reserved for other network layer or layer 3 protocols"}, 
    {154, "Reserved for other network layer or layer 3 protocols"}, 
    {155, "Reserved for other network layer or layer 3 protocols"}, 
    {156, "Reserved for other network layer or layer 3 protocols"}, 
    {157, "Reserved for other network layer or layer 3 protocols"}, 
    {158, "Reserved for other network layer or layer 3 protocols"}, 
    {159, "Reserved for other network layer or layer 3 protocols"}, 
    {160, "Reserved for other network layer or layer 3 protocols"}, 
    {161, "Reserved for other network layer or layer 3 protocols"}, 
    {162, "Reserved for other network layer or layer 3 protocols"}, 
    {163, "Reserved for other network layer or layer 3 protocols"}, 
    {164, "Reserved for other network layer or layer 3 protocols"}, 
    {165, "Reserved for other network layer or layer 3 protocols"}, 
    {166, "Reserved for other network layer or layer 3 protocols"}, 
    {167, "Reserved for other network layer or layer 3 protocols"}, 
    {168, "Reserved for other network layer or layer 3 protocols"}, 
    {169, "Reserved for other network layer or layer 3 protocols"}, 
    {170, "Reserved for other network layer or layer 3 protocols"}, 
    {171, "Reserved for other network layer or layer 3 protocols"}, 
    {172, "Reserved for other network layer or layer 3 protocols"}, 
    {173, "Reserved for other network layer or layer 3 protocols"}, 
    {174, "Reserved for other network layer or layer 3 protocols"}, 
    {175, "Reserved for other network layer or layer 3 protocols"}, 
    {176, "Reserved for other network layer or layer 3 protocols"}, 
    {177, "Reserved for other network layer or layer 3 protocols"}, 
    {178, "Reserved for other network layer or layer 3 protocols"}, 
    {179, "Reserved for other network layer or layer 3 protocols"}, 
    {180, "Reserved for other network layer or layer 3 protocols"}, 
    {181, "Reserved for other network layer or layer 3 protocols"}, 
    {182, "Reserved for other network layer or layer 3 protocols"}, 
    {183, "Reserved for other network layer or layer 3 protocols"}, 
    {184, "Reserved for other network layer or layer 3 protocols"}, 
    {185, "Reserved for other network layer or layer 3 protocols"}, 
    {186, "Reserved for other network layer or layer 3 protocols"}, 
    {187, "Reserved for other network layer or layer 3 protocols"}, 
    {188, "Reserved for other network layer or layer 3 protocols"}, 
    {189, "Reserved for other network layer or layer 3 protocols"}, 
    {190, "Reserved for other network layer or layer 3 protocols"}, 
    {191, "Reserved for other network layer or layer 3 protocols"}, 
    {192, "Reserved for other network layer or layer 3 protocols"}, 
    {193, "Reserved for other network layer or layer 3 protocols"}, 
    {194, "Reserved for other network layer or layer 3 protocols"}, 
    {195, "Reserved for other network layer or layer 3 protocols"}, 
    {196, "Reserved for other network layer or layer 3 protocols"}, 
    {197, "Reserved for other network layer or layer 3 protocols"}, 
    {198, "Reserved for other network layer or layer 3 protocols"}, 
    {199, "Reserved for other network layer or layer 3 protocols"}, 
    {200, "Reserved for other network layer or layer 3 protocols"}, 
    {201, "Reserved for other network layer or layer 3 protocols"}, 
    {202, "Reserved for other network layer or layer 3 protocols"}, 
    {203, "Reserved for other network layer or layer 3 protocols"}, 
    {204, "Reserved for other network layer or layer 3 protocols"}, 
    {205, "Reserved for other network layer or layer 3 protocols"}, 
    {206, "Reserved for other network layer or layer 3 protocols"}, 
    {207, "Reserved for other network layer or layer 3 protocols"}, 
    {208, "Reserved for other network layer or layer 3 protocols"}, 
    {209, "Reserved for other network layer or layer 3 protocols"}, 
    {210, "Reserved for other network layer or layer 3 protocols"}, 
    {211, "Reserved for other network layer or layer 3 protocols"}, 
    {212, "Reserved for other network layer or layer 3 protocols"}, 
    {213, "Reserved for other network layer or layer 3 protocols"}, 
    {214, "Reserved for other network layer or layer 3 protocols"}, 
    {215, "Reserved for other network layer or layer 3 protocols"}, 
    {216, "Reserved for other network layer or layer 3 protocols"}, 
    {217, "Reserved for other network layer or layer 3 protocols"}, 
    {218, "Reserved for other network layer or layer 3 protocols"}, 
    {219, "Reserved for other network layer or layer 3 protocols"}, 
    {220, "Reserved for other network layer or layer 3 protocols"}, 
    {221, "Reserved for other network layer or layer 3 protocols"}, 
    {222, "Reserved for other network layer or layer 3 protocols"}, 
    {223, "Reserved for other network layer or layer 3 protocols"}, 
    {224, "Reserved for other network layer or layer 3 protocols"}, 
    {225, "Reserved for other network layer or layer 3 protocols"}, 
    {226, "Reserved for other network layer or layer 3 protocols"}, 
    {227, "Reserved for other network layer or layer 3 protocols"}, 
    {228, "Reserved for other network layer or layer 3 protocols"}, 
    {229, "Reserved for other network layer or layer 3 protocols"}, 
    {230, "Reserved for other network layer or layer 3 protocols"}, 
    {231, "Reserved for other network layer or layer 3 protocols"}, 
    {232, "Reserved for other network layer or layer 3 protocols"}, 
    {233, "Reserved for other network layer or layer 3 protocols"}, 
    {234, "Reserved for other network layer or layer 3 protocols"}, 
    {235, "Reserved for other network layer or layer 3 protocols"}, 
    {236, "Reserved for other network layer or layer 3 protocols"}, 
    {237, "Reserved for other network layer or layer 3 protocols"}, 
    {238, "Reserved for other network layer or layer 3 protocols"}, 
    {239, "Reserved for other network layer or layer 3 protocols"}, 
    {240, "Reserved for other network layer or layer 3 protocols"}, 
    {241, "Reserved for other network layer or layer 3 protocols"}, 
    {242, "Reserved for other network layer or layer 3 protocols"}, 
    {243, "Reserved for other network layer or layer 3 protocols"}, 
    {244, "Reserved for other network layer or layer 3 protocols"}, 
    {245, "Reserved for other network layer or layer 3 protocols"}, 
    {246, "Reserved for other network layer or layer 3 protocols"}, 
    {247, "Reserved for other network layer or layer 3 protocols"}, 
    {248, "Reserved for other network layer or layer 3 protocols"}, 
    {249, "Reserved for other network layer or layer 3 protocols"}, 
    {250, "Reserved for other network layer or layer 3 protocols"}, 
    {251, "Reserved for other network layer or layer 3 protocols"}, 
    {252, "Reserved for other network layer or layer 3 protocols"}, 
    {253, "Reserved for other network layer or layer 3 protocols"}, 
    {254, "Reserved for other network layer or layer 3 protocols"}, 
};
struct  code2dict type_of_identity[] =
{
    {0, "reserved"},
    {1, "IMSI"},
    {2, "IMSI"},
    {3, "IMEISV"},
    {4, "TMSI"},
    {5, "P-TMSI, RAI, P-TMSI signature"},
    {6, "reserved"},
    {7, "reserved"},
};
struct  code2dict ptmsi_type_ptmsi_type[] = 
{
    {0, "Native P-TMSI"}, 
    {1, "Mapped P-TMSI"}, 
};
struct  code2dict pd_sapi_sapi[] = 
{
    {0, "SAPI 0"}, 
    {1, "reserved"}, 
    {2, "reserved"}, 
    {3, "SAPI 3"}, 
};

struct  code2dict frequency_list_1024f_f0[] = 
{
    {0, "ARFCN 0 is not a member of the set"}, 
    {1, "ARFCN 0 is a member of the set"}, 
};

struct  code2dict channel_mode_mode_field[] =
{
    {0, "signalling only"},
    {1, "speech full rate or half rate version 1"},
    {33, "speech full rate or half rate version 2"},
    {65, "speech full rate or half rate version 3"},
    {129, "speech full rate or half rate version 4"},
    {130, "speech full rate or half rate version 5"},
    {131, "speech full rate or half rate version 6"},
    {97, "data, 43.5 kbit/s (downlink)+14.5 kbps (uplink)"},
    {98, "data, 29.0 kbit/s (downlink)+14.5 kbps (uplink)"},
    {100, "data, 43.5 kbit/s (downlink)+29.0 kbps (uplink)"},
    {103, "data, 14.5 kbit/s (downlink)+43.5 kbps (uplink)"},
    {101, "data, 14.5 kbit/s (downlink)+29.0 kbps (uplink)"},
    {102, "data, 29.0 kbit/s (downlink)+43.5 kbps (uplink)"},
    {39, "data, 43.5 kbit/s radio interface rate"},
    {99, "data, 32.0 kbit/s radio interface rate"},
    {67, "data, 29.0 kbit/s radio interface rate"},
    {15, "data, 14.5 kbit/s radio interface rate"},
    {3, "data, 12.0 kbit/s radio interface rate"},
    {11, "data, 6.0 kbit/s radio interface rate"},
    {19, "data, 3.6 kbit/s radio interface rate"},
};

struct  code2dict measurement_results_dtx_used[] = 
{
    {0, "DTX was not used"}, 
    {1, "DTX was used"}, 
};

struct  code2dict measurement_results_meas_meas_valid[] = 
{
    {0, "The measurement results are valid"}, 
    {1, "the measurement results are not valid"}, 
};

struct  code2dict measurement_results_number_neighbour_c_m[] = 
{
    {0, "None"}, 
    {1, "1"}, 
    {2, "2"}, 
    {3, "3"}, 
    {4, "4"}, 
    {5, "5"}, 
    {6, "6"}, 
    {7, "Neighbour cell information not available for serving cell"}, 
};

struct  code2dict recommendation_dict[] = 
{
    {0, "Q.931"}, 
    {3, "X.21"}, 
    {4, "X.25"}, 
    {5, "Public land mobile networks, Q.1031/Q.1051"}, 
};


struct  code2dict allowed_actions_ccbs_activation[] = 
{
    {0, "Activation of CCBS not possible"}, 
    {1, "Activation of CCBS possible"}, 
};

struct  code2dict cprs_timer3_gprs_timer3_v[] = 
{
    {0, "value is incremented in multiples of 10 minutes"}, 
    {1, "value is incremented in multiples of 1 hour"}, 
    {2, "value is incremented in multiples of 10 hours"}, 
    {3, "value is incremented in multiples of 2 seconds"}, 
    {4, "value is incremented in multiples of 30 seconds"}, 
    {5, "value is incremented in multiples of 1 minute"}, 
    {6, "multiples of 1 hour in this version of the protocol"}, 
    {7, "value indicates that the timer is deactivated."}, 
};
struct code2dict digit_number[]=
{
    {0,"0"},     
    {1,"1"},     
    {2,"2"},     
    {3,"3"},     
    {4,"4"},     
    {5,"5"},     
    {6,"6"},     
    {7,"7"},     
    {8,"8"},     
    {9,"9"},     
    {10,"*"},     
    {11,"#"},     
    {12,"a"},     
    {13,"b"},     
    {14,"c"},     
    {15,"used as an endmark in the case of an odd number of number digits"}, 
};     


struct  code2dict signal_signal_value[] = 
{
    {0, "dial tone on"}, 
    {1, "ring back tone on"}, 
    {2, "intercept tone on"}, 
    {3, "network congestion tone on"}, 
    {4, "busy tone on"}, 
    {5, "confirm tone on"}, 
    {6, "answer tone on"}, 
    {7, "call waiting tone on"}, 
    {8, "off-hook warning tone on"}, 
    {63, "tones off"}, 
    {79, "alerting off"}, 
};

struct  code2dict channel_mode_2_mode_field[] = 
{
    {0, "signalling only"}, 
    {5, "speech half rate version 1"}, 
    {37, "speech half rate version 2"}, 
    {69, "speech half rate version 3"}, 
    {133, "speech half rate version 4"}, 
    {70, "speech half rate version 6"}, 
    {15, "data, 6.0 kbit/s radio interface rate"}, 
    {23, "data, 3.6 kbit/s radio interface rate"}, 
};


struct  code2dict multirate_configuration_info_amr_codec_m_bit8[] = 
{
    {0, "12,2 kbit/s codec rate is not part of the subset"}, 
    {1, "12,2 kbit/s codec rate is part of the subset"}, 
};

struct  code2dict multirate_configuration_info_amr_codec_m_bit7[] = 
{
    {0, "10,2 kbit/s codec rate is not part of the subset"}, 
    {1, "10,2 kbit/s codec rate is part of the subset"}, 
};

struct  code2dict multirate_configuration_info_amr_codec_m_bit6[] = 
{
    {0, "7,95 kbit/s codec rate is not part of the subset"}, 
    {1, "7,95 kbit/s codec rate is part of the subset"}, 
};

struct  code2dict multirate_configuration_info_amr_codec_m_bit5[] = 
{
    {0, "7,40 kbit/s codec rate is not part of the subset"}, 
    {1, "7,40 kbit/s codec rate is part of the subset"}, 
};

struct  code2dict multirate_configuration_info_amr_codec_m_bit4[] = 
{
    {0, "6,70 kbit/s codec rate is not part of the subset"}, 
    {1, "6,70 kbit/s codec rate is part of the subset"}, 
};

struct  code2dict multirate_configuration_info_amr_codec_m_bit3[] = 
{
    {0, "5,90 kbit/s codec rate is not part of the subset"}, 
    {1, "5,90 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit2[] = 
{
    {0, "5,15 kbit/s codec rate is not part of the subset"}, 
    {1, "5,15 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit1[] = 
{
    {0, "4,75 kbit/s codec rate is not part of the subset"}, 
    {1, "4,75 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit5_ext[] = 
{
    {0, "23,85 kbit/s codec rate is not part of the subset"}, 
    {1, "23,85 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit4_ext[] = 
{
    {0, "15,85 kbit/s codec rate is not part of the subset"}, 
    {1, "15,85 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit3_ext[] = 
{
    {0, "12,65 kbit/s codec rate is not part of the subset"}, 
    {1, "12,65 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit2_ext[] = 
{
    {0, "8,85 kbit/s codec rate is not part of the subset"}, 
    {1, "8,85 kbit/s codec rate is part of the subset"}, 
};
struct  code2dict multirate_configuration_info_amr_codec_m_bit1_ext[] = 
{
    {0, "6,60 kbit/s codec rate is not part of the subset"}, 
    {1, "6,60 kbit/s codec rate is part of the subset"}, 
};

struct  code2dict multirate_configuration_info_multirate_speech_v[] = 
{
    {1, "Adaptive Multirate speech version 1"}, 
    {2, "Adaptive Multirate speech version 2"}, 
};

struct  code2dict multirate_configuration_info_noise_suppression_c[] = 
{
    {0, "Noise Suppression can be used"}, 
    {1, "Noise Suppression shall be turned off"}, 
};

struct  code2dict multirate_configuration_info_initial_codec_m_i[] = 
{
    {0, "The initial codec mode is defined by the implicit rule provided in 3GPP TS 05.09"}, 
    {1, "The initial codec mode is defined by the Start Mode field"}, 
};


struct  code2dict power_command_epc_mode[] = 
{
    {0, "Channel(s) not in EPC mode"}, 
    {1, "Channel(s) in EPC mode"}, 
};

struct  code2dict power_command_fpc_epc0[] = 
{
    {0, "FPC not in use"}, 
    {1, "FPC in use"}, 
};

struct  code2dict power_command_fpc_epc1[] = 
{
    {0, "EPC not in use for uplink power control"}, 
    {1, "EPC in use for uplink power control"}, 
};

struct  code2dict called_party_b_n_type_number[] = 
{
    {0, "unknown"}, 
    {1, "international number"}, 
    {2, "national number"}, 
    {3, "network specific number"}, 
    {4, "dedicated access, short code"}, 
    {5, "reserved"}, 
    {6, "reserved"}, 
    {7, "reserved for extension"}, 
};

struct  code2dict called_party_b_n_numbering_plan_i[] = 
{
    {0, "unknown"}, 
    {1, "ISDN/telephony numbering plan"}, 
    {3, "data numbering plan"}, 
    {4, "telex numbering plan"}, 
    {8, "national numbering plan"}, 
    {9, "private numbering plan"}, 
    {11, "reserved for CTS"}, 
    {15, "reserved for extension"}, 
};

struct  code2dict calling_party_b_n_presentation_indicator[] =
{
    {0, "Presentation allowed"},
    {1, "Presentation restricted"},
    {2, "Number not available due to interworking"},
    {3, "Reserved"},
};

struct  code2dict calling_party_b_n_screening_indicator[] =
{
    {0, "Presentation allowed"},
    {1, "Presentation restricted"},
    {2, "Number not available due to interworking"},
    {3, "Reserved"},
};

struct  code2dict calling_party_s_type_subaddress[] =
{
    {0, "NSAP (see ITU-T Rec. X.213 [144]/ISO 8348 AD2)"},
    {1, "Reserved"},
    {2, "User specified"},
    {3, "Reserved"}, 
    {4, "Reserved"},
    {5, "Reserved"},
    {6, "Reserved"},
    {7, "Reserved"},
};

struct  code2dict calling_party_s_odd_even_i[] =
{
    {0, "even number of address signals"},
    {1, "odd number of address signals"},
};

struct  code2dict vgcs_target_m_i_group_cipher_k_n[] = 
{
    {0, "no ciphering"}, 
    {1, "cipher key number 1"}, 
    {2, "cipher key number 2"}, 
    {3, "cipher key number 3"}, 
    {4, "cipher key number 4"}, 
    {5, "cipher key number 5"}, 
    {6, "cipher key number 6"}, 
    {7, "cipher key number 7"}, 
    {8, "cipher key number 8"}, 
    {9, "cipher key number 9"}, 
    {10, "cipher key number A"}, 
    {11, "cipher key number B"}, 
    {12, "cipher key number C"}, 
    {13, "cipher key number D"}, 
    {14, "cipher key number E"}, 
    {15, "cipher key number F"}, 
};

struct  code2dict channel_release_group_cipher_k_n[] = 
{
    {0, "spare"}, 
    {1, "cipher key number 1"}, 
    {2, "cipher key number 2"}, 
    {3, "cipher key number 3"}, 
    {4, "cipher key number 4"}, 
    {5, "cipher key number 5"}, 
    {6, "cipher key number 6"}, 
    {7, "cipher key number 7"}, 
    {8, "cipher key number 8"}, 
    {9, "cipher key number 9"}, 
    {10, "cipher key number A"}, 
    {11, "cipher key number B"}, 
    {12, "cipher key number C"}, 
    {13, "cipher key number D"}, 
    {14, "cipher key number E"}, 
    {15, "cipher key number F"}, 
};


struct  code2dict channel_release_gprs_resumption_ack[] = 
{
    {0, "resumption of GPRS services not successfully acknowledged"}, 
    {1, "resumption of GPRS services successfully acknowledged"}, 
};
struct  code2dict call_control_c_dtmf[] =
{
    {0, "This value is reserved for earlier versions of the protocol."},
    {1, "This value indicates that the mobile station supports DTMF as specified in subclause 5.5.7 of the present document."},
};

struct  code2dict call_control_c_pcp[] = 
{
    {0, "This value is reserved for earlier versions of the protocol."}, 
    {1, "This value indicates that the mobile station supports DTMF as specified in subclause 5.5.7 of the present document."}, 
};

struct  code2dict call_control_c_enicm[] = 
{
    {0, "This value is reserved for earlier versions of the protocol."}, 
    {1, "This value indicates that the mobile station supports DTMF as specified in subclause 5.5.7 of the present document."}, 
};

struct  code2dict call_control_c_mcat[] = 
{
    {0, "This value indicates that the mobile station does not support Multimedia CAT."}, 
    {1, "This value indicates that the mobile station supports Multimedia CAT during the alerting phase of a mobile originated multimedia call establishment as specified in subclause 5.3.6.4 of the present document."},
};

struct  code2dict enhanced_dtm_r_i_ind[] = 
{
    {0, "the mobile station is not allowed to continue in packet transfer mode;"}, 
    {1, "the mobile station is allowed to continue in packet transfer mode."}, 
};

struct  code2dict alerting_pattern_n_alerting_pattern_v[] = 
{
    {0, "alerting pattern 1"}, 
    {1, "alerting pattern 2"}, 
    {2, "alerting pattern 3"}, 
    {4, "alerting pattern 5"}, 
    {5, "alerting pattern 6"}, 
    {6, "alerting pattern 7"}, 
    {7, "alerting pattern 8"}, 
    {8, "alerting pattern 9"}, 
};

struct  code2dict cause_no_c_cause_no_cli[] = 
{
    {0, "Unavailable"}, 
    {1, "Reject by user"}, 
    {2, "Interaction with other service"}, 
    {3, "Coin line/payphone"},
};
//liusai
/*
struct  code2dict vgcs_ciphering_p_cell_ind[] =
{
    {0, "Cell Identification not present"},
    {1, "Cell Identification present"},
};

struct  code2dict vgcs_ciphering_p_lac_ind[] =
{
    {0, "Location Area Identification not present"},
    {1, "Location Area Identification present"},
};

struct  code2dict vgcs_ciphering_p_rand_ind[] =
{
    {0, "VSTK_RAND not present"},
    {1, "VSTK_RAND present"},
};
*/
struct  code2dict dedicated_service_i_last_segment[] =
{
    {0, "mobile station shall not perform Service Information Sending procedure on new cell."},
    {1, "mobile station shall perform Service Information Sending procedure on new cell."},
};

struct  code2dict power_command_a_t_atc[] =
{
    {0, "Sending of Handover access is mandatory"},
    {1, "Sending of Handover access is optional"},
};

struct  code2dict synchronization_indication_nci[] =
{
    {0, "Out of range timing advance is ignored"},
    {1, "Out of range timing advance shall trigger a handover failure procedure"},
};

struct  code2dict synchronization_indication_rot[] =
{
    {0, "Mobile Time Difference IE shall not be included in the HANDOVER COMPLETE message"},
    {1, "Mobile Time Difference IE shall be included in the HANDOVER COMPLETE message"},
};

struct  code2dict synchronization_indication_si[] =
{
    {0, "Non-synchronized"},
    {1, "Synchronized"},
    {2, "Pre-synchronised"},
    {3, "Pseudo-synchronised"},
};

struct  code2dict cell_options_s_dtx_indicator2[] =
{
    {0, "The MS may use uplink discontinuous transmission on a TCH-F. The MS shall not use uplink discontinuous transmission on TCH-H."},
    {1, "The MS shall use uplink discontinuous transmission on a TCH-F. The MS shall not use uplink discontinuous transmission on TCH-H."},
    {2, "The MS shall not use uplink discontinuous transmission on a TCH-F. The MS shall not use uplink discontinuous transmission on TCH-H."},
    {3, "Note 4: The MS shall use uplink discontinuous transmission on a TCH-F. The MS may use uplink discontinuous transmission on TCH-H."},
    {4, "The MS may use uplink discontinuous transmission on a TCH-F. The MS may use uplink discontinuous transmission on TCH-H."},    
    {5, "The MS shall use uplink discontinuous transmission on a TCH-F. The MS shall use uplink discontinuous transmission on TCH-H."},
    {6, "The MS shall not use uplink discontinuous transmission on a TCH-F. The MS shall use uplink discontinuous transmission on TCH-H."},
    {7, "Note 4: The MS may use uplink discontinuous transmission on a TCH-F. The MS shall use uplink discontinuous transmission on TCH-H."},
};

struct  code2dict rach_control_p_cell_bar_access[] =
{
    {0, "The cell is not barred"},
    {1, "The cell is barred"},
};

struct  code2dict rach_control_p_re[] =
{
    {0, "Call Reestablishment allowed in the cell"},
    {1, "Call Reestablishment not allowed in the cell"},
};

struct  code2dict rach_control_p_ec[] =
{
    {0, "Emergency call allowed in the cell to all MSs"},
    {1, "Emergency call not allowed in the cell except for the MSs that belong to one of the classes between 11 to 15."},
};

struct  code2dict rach_control_p_max_retrans[] =
{
    {0, "Maximum 1 retransmission"},
    {1, "Maximum 2 retransmissions"},
    {2, "Maximum 4 retransmissions"},
    {3, "Maximum 7 retransmissions"},
};

struct  code2dict rach_control_p_tx_integer[] =
{
    {0, "3 slots used to spread transmission"},
    {1, "4 slots used to spread transmission"},
    {2, "5 slots used to spread transmission"},
    {3, "6 slots used to spread transmission"},
    {4, "7 slots used to spread transmission"},
    {5, "8 slots used to spread transmission"},
    {6, "9 slots used to spread transmission"},
    {30, "slots used to spread transmission"},
    {35, "slots used to spread transmission"},
    {9, "12 slots used to spread transmission"},
    {10, "14 slots used to spread transmission"},
    {11, "16 slots used to spread transmission"},
    {12, "20 slots used to spread transmission"},
    {13, "25 slots used to spread transmission"},
    {14, "32 slots used to spread transmission"},
    {15, "50 slots used to spread transmission"},
};

struct code2dict cell_selection_p_cell_reselect_h[] =
{
    {0, "0 dB RXLEV hysteresis for LA re-selection"},
    {1, "2 dB RXLEV hysteresis for LA re-selection"},
    {2, "4 dB RXLEV hysteresis for LA re-selection"},
    {3, "6 dB RXLEV hysteresis for LA re-selection"},
    {4, "8 dB RXLEV hysteresis for LA re-selection"},
    {5, "10 dB RXLEV hysteresis for LA re-selection"},
    {6, "12 dB RXLEV hysteresis for LA re-selection"},
    {7, "14 dB RXLEV hysteresis for LA re-selection"},
};

struct code2dict cell_selection_p_acs_t3[] =
{
    {0, "SI_type_3:System information type 16 and 17 are not broadcast on the BCCH."},
    {1, "System information type 16 and 17 are broadcast on the BCCH. A mobile station which does not support System information type 16 and 17 may consider this bit as 0"},
};

struct code2dict cell_selection_p_acs_t4[] =
{
    {0, "The SI 4 rest octets, if present, and SI 7 and SI 8 rest octets, if so indicated in the SI 4 rest octets shall be used to derive the value of PI and possibly C2 parameters and/or other parameters"},
    {1, "The value of PI and possibly C2 parameters and/or other parameters in a System information type 7 or type 8 message shall be used"},
};


struct code2dict cell_selection_p_neci[] =
{
    {0, "New establishment causes are not supported"},
    {1, "New establishment causes are supported"},
};

struct  code2dict cell_options_s_dtx_indicator1[] =
{
    {0, "The MSs may use uplink discontinuous transmission"},
    {1, "The MSs shall use uplink discontinuous transmission"},
    {2, "The MS shall not use uplink discontinuous transmission"},
    {3, "reserved"},
};

struct code2dict cell_options_radio_link_t[] =
{
    {0, "4"},
    {1, "8"},
    {2, "12"},
    {3, "16"},
    {4, "20"},
    {5, "24"},
    {6, "28"},
    {7, "32"},
    {8, "36"},
    {9, "40"},
    {10, "44"},
    {11, "48"},
    {12, "52"},
    {13, "56"},
    {14, "60"},
    {15, "64"},
};

struct code2dict control_channel_description_bs_pa_m[] =
{
    {0, "2 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {1, "3 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {2, "4 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {3, "5 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {4, "6 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {5, "7 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {6, "8 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
    {7, "9 multiframes period for transmission of PAGING REQUEST messages to the same paging subgroup"},
};

struct  code2dict cell_options_s_dynamic_arfcn_m_i[] =
{
    {0, "Dynamic ARFCN mapping is not used by the PLMN"},
    {1, "Dynamic ARFCN mapping is used by the PLMN"},
};

struct  code2dict cell_options_s_power_control_i[] =
{
    {0, "PWRC is not set"},
    {1, "PWRC is set"},
};

struct code2dict control_channel_description_att[] =
{
    {0, "MSs in the cell are not allowed to apply IMSI attach and detach procedure."},
    {1, "MSs in the cell shall apply IMSI attach and detach procedure."},
};

struct code2dict control_channel_description_ccch_conf[] =
{
    {0, "1 basic physical channel used for CCCH, not combined with SDCCHs"},
    {1, "1 basic physical channel used for CCCH, combined with SDCCHs"},
    {2, "2 basic physical channel used for CCCH, not combined with SDCCHs"},
    {3, "reserved"},
    {4, "3 basic physical channel used for CCCH, not combined with SDCCHs"},
    {5, "reserved"},
    {6, "4 basic physical channels used for CCCH, not combined with SDCCHs"},
    {7, "reserved"},
};

struct code2dict control_channel_description_cbq3[] =
{
    {0, "Iu mode not supported"},
    {1, "Iu mode capable MSs barred"},
    {2, "Iu mode supported, cell not barred"},
    {3, "Iu mode supported, cell not barred. The network shall not use this value."},
};


struct code2dict control_channel_description_mscr[] =
{
    {0, "MSC is Release '98 or older"},
    {1, "MSC is Release '99 onwards"},
};

struct code2dict control_channel_description_si22ind[]=
{
    {0, "SI22 is not broadcast."},
    {1, "SI22 is broadcast."},
};

struct  code2dict channel_description_channel_type_t_o_2[] =
{
    {1, "TCH/F + ACCHs"},
    {2, "TCH/H + ACCHs"},
    {3, "TCH/H + ACCHs"},
    {4, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {5, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {6, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {7, "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4)"},
    {8, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {9, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {10, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {11, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {12, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {13, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {14, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {15, "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8)"},
    {16, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms no additional timeslots"},
    {17, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n-1"},
    {18, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n+1, n-1"},
    {19, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n+1, n-1 and n-2"},
    {20, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n+1, n-1, n-2, and n-3"},
    {21, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n+1, n-1, n-2, n-3 and n-4"},
    {22, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n+1, n-1, n-2, n-3, n-4 and n-5"},
    {23, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN, and additional bidirectional TCH/Fs and SACCH/Ms at timeslot n+1, n-1, n-2, n-3, n-4, n-5 and n-6"},
    {24, "reserved"},
    {25, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN and additional unidirectional TCH/FDs and SACCH/MDs at other timeslots at timeslot n-1"},
    {26, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN and additional unidirectional TCH/FDs and SACCH/MDs at other timeslots at timeslot n+1, n-1"},
    {27, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN and additional unidirectional TCH/FDs and SACCH/MDs at other timeslots at timeslot n+1, n-1 and n-2"},
    {28, "reserved"},
    {29, "reserved"},
    {30, "TCH/F + FACCH/F and SACCH/M at the time slot indicated by TN and additional bidirectional TCH/F and SACCH/M at timeslot n+1 and unidirectional TCH/FD and SACCH/MD at timeslot n-1"},
};

//end liusai



struct  code2dict high_layer_c_coding_standard[] = 
{
    {0, "CCITT standardized coding, as described below"}, 
    {1, "ISO/IEC STANDARD"}, 
    {2, "NATIONAL STANDARD"}, 
    {3, "Standard defined for the network(either public or private)present on the network side of the interface"}, 
};

struct  code2dict high_layer_c_high_layer_c_i[] = 
{
    {1, "Telephony"}, 
    {4, "Facsimile group 2/3 (recommendation f.182[68])"}, 
    {33, "Facsimile group 4 class i (recommendation f.184[69])"}, 
    {36, "Teletex service, basic and mixed mode of operation(recommendation f.230[70]) and facsimile service group 4, classes ii and iii(recommendation f.184)"}, 
    {40, "Teletex service, basic and processable mode of operation(recommendation F.220[71])"}, 
    {49, "Teletex service, basic mode of operation(recommendation F.200[72])"}, 
    {50, "Syntax based Videotex(recommendation F.300[73] and T.102[74])"}, 
    {51, "International Videotex interworking via gateways or interworking units (recommendation F.300 and T.101[75])"}, 
    {53, "Teletex service (recommendation F.60[76])"}, 
    {56, "Message Handing Systems (MHS)(X.400-Series recommendation [77])"}, 
    {65, "OSI application (X.200-Series recommendation [78])"}, 
    {94, "Reserved for maintenance"}, 
    {95, "Reserved for management"}, 
    {96, "Audio visual (recommendation F.271 [79])"}, 
    {97, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {98, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {99, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {100, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {101, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {102, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {103, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {104, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {105, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {106, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {107, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {108, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {109, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {110, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {111, "Reserved for audiovisual service(F.700 - recommendation Series [80])"}, 
    {127, "Reserved"}, 
};

struct  code2dict high_layer_c_extended_high_l_c_i[] = 
{
    {1, "Telephony"}, 
    {4, "Facsimile group 2/3 (recommendation f.182)"}, 
    {33, "Facsimile group 4 class I (recommendation f.184)"}, 
    {36, "Teletex service, basic and mixed mode of operation(recommendation f.230) and facsimile service group 4, classes II and III(recommendation f.184)"}, 
    {40, "Teletex service, basic and processable mode of operation(recommendation F.220)"}, 
    {49, "Teletex service, basic mode of operation(recommendation F.200)"}, 
    {50, "Syntax based Videotex(recommendation F.300 and T.102)"}, 
    {51, "International Videotex interworking via gateways or interworking units (recommendation F.300 and T.101)"}, 
    {53, "Teletex service (recommendation F.60)"}, 
    {56, "Message Handing Systems (MHS)(X.400-Series recommendation)"}, 
    {65, "OSI application (X.200-Series recommendation)"}, 
    {94, "Not available for assignment"}, 
    {95, "Not available for assignment"}, 
    {96, "Audio visual (recommendation F.271)"}, 
    {97, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {98, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {99, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {100, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {101, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {102, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {103, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {104, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {105, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {106, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {107, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {108, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {109, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {110, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {111, "Reserved for audiovisual service(F.700 - Series recommendations)"}, 
    {127, "Reserved"}, 
};

struct  code2dict low_layer_co_coding_standard[] = 
{
    {0, "CCITT standardized coding, as described below"}, 
    {1, "ISO/IEC STANDARD"}, 
    {2, "NATIONAL STANDARD"}, 
    {3, "Standard defined for the network(either public or private)present on the network side of the interface"}, 
};

struct  code2dict low_layer_co_information_transfer_c[] = 
{
    {0, "Speech"}, 
    {8, "Unrestricted digital information"}, 
    {9, "Restricted digital information"}, 
    {16, "3.1kHz audio"}, 
    {17, "Unrestricted digital information with tones/announcements"}, 
    {24, "Video"}, 
};

struct  code2dict low_layer_co_negotiation_indicator[] = 
{
    {0, "Out-band negotiation not possible"}, 
    {1, "Out-band negotiation possible"}, 
};


struct  code2dict low_layer_co_transfer_mode[] = 
{
    {0, "Circuit mode"}, 
    {1, "Packet-mode"}, 
    {2, "Reserved"}, 
    {3, "Reserved"}, 
};

struct  code2dict low_layer_co_information_transfer_r[] = 
{
    {16, "64 kbit/s"}, 
    {17, "2*64 kbit"}, 
    {19, "384 kbit/s"}, 
    {21, "1536 kbit/s"}, 
    {23, "1920 kbit/s"}, 
    {24, "Multirate(64 kbit/s base rate)"}, 
};

struct  code2dict low_layer_co_user_information_l1_p[] = 
{
    {1, "CCITT standardized rate adaption V.110[7] and X.30[8]. This implies the present of octet 5a and optionally octets 5b, 5c and 5d as defined below."}, 
    {2, "Recommendation G.711[10]"}, 
    {3, "Recommendation G.711 A-law"}, 
    {4, "Recommendation G.721[11]32 kbit/s ADPCM and Recommendation I.460[15]"}, 
    {5, "Non-CCITT standardized rate adaption. This implies the presence of octet 5a and, optionally, octets 5b, 5c and 5d. The use of this code point indicates that the user rate specified in octet 5a is defined by the user. Additionally, octets 5b, 5c and 5d, if present, are defined consistent with the user specified rate adaption"}, 
    {8, "CCITT standardized rate adaption V.120[9]. This implies the presence of octets 5a and 5b as defined below, and optionally octets 5c and 5d"}, 
    {9, "CCITT standardized rate adaption X.31[14]HDLC flag stuffing"}, 
};

struct  code2dict low_layer_co_synchronous_asynchronous[] = 
{
    {0, "SYNCHRONOUS DATA"}, 
    {1, "ASYNCHRONOUS DATA"}, 
};

struct  code2dict low_layer_co_negotiation[] = 
{
    {0, "In_band negotiation not possible"}, 
    {1, "In_band negotiation possible"}, 
};

struct  code2dict low_layer_co_user_rate[] = 
{
    {0, "Rate is indicated by E-bits specified in Recommendation I.460 or may be negotiated in-band"}, 
    {1, "0.6 kbit/s recommendations v.6[16] and x.1[17]"}, 
    {2, "1.2 kbit/s Recommendation V.6"}, 
    {3, "2.4 kbit/s Recommendation V.6 and X.1"}, 
    {4, "3.6 kbit/s Recommendation V.6"}, 
    {5, "4.8 kbit/s Recommendation V.6 and X.1"}, 
    {6, "7.2 kbit/s Recommendation V.6"}, 
    {7, "8 kbit/s Recommendation I.460"}, 
    {8, "9.6 kbit/s Recommendation V.6 and X.1"}, 
    {9, "14.4 kbit/s Recommendation V.6"}, 
    {10, "16 kbit/s Recommendation I.460"}, 
    {11, "19.2 kbit/s Recommendation V.6"}, 
    {12, "32 kbit/s Recommendation I.460"}, 
    {14, "48 kbit/s Recommendation V.6 and X.1"}, 
    {15, "56 kbit/s Recommendation V.6"}, 
    {16, "64 kbit/s Recommendation X.1"}, 
    {21, "0.1345 kbit/s Recommendation X.1"}, 
    {22, "0.100 kbit/s Recommendation X.1"}, 
    {23, "0.075/1.2 kbit/s Recommendation V.6 and X.1"}, 
    {24, "1.2/0.075 kbit/s Recommendation V.6 and X.1"}, 
    {25, "0.050 kbit/s Recommendation V.6 and X.1"}, 
    {26, "0.075 kbit/s Recommendation V.6 and X.1"}, 
    {27, "0.110 kbit/s Recommendation V.6 and X.1"}, 
    {28, "0.150 kbit/s Recommendation V.6 and X.1"}, 
    {29, "0.200 kbit/s Recommendation V.6 and X.1"}, 
    {30, "0.300 kbit/s Recommendation V.6 and X.1"}, 
    {31, "12 kbit/s Recommendation V.6"}, 
};

struct  code2dict low_layer_co_intermediate_rate[] = 
{
    {0, "Not used"}, 
    {1, "8 kbit/s"}, 
    {2, "16 kbit/s"}, 
    {3, "32 kbit/s"}, 
};

struct  code2dict low_layer_co_nic_tx[] = 
{
    {0, "Not required to send data with network independent clock"}, 
    {1, "Required to send data with network independent clock"}, 
};

struct  code2dict low_layer_co_nic_rx[] = 
{
    {0, "Cannot accept data with Network Independent Clock (i.e. sender does not support this optional procedure)"}, 
    {1, "Can accept data with Network Independent Clock (i.e. sender does support this optional procedure)"}, 
};

struct  code2dict low_layer_co_flow_control_tx[] = 
{
    {0, "Not required to send data with flow control mechanism"}, 
    {1, "Required to send data with flow control mechanism"}, 
};

struct  code2dict low_layer_co_flow_control_rx[] = 
{
    {0, "Cannot accept data with Network Independent Clock (i.e. sender does not support this optional procedure)"}, 
    {1, "Can accept data with Network Independent Clock (i.e. sender does support this optional procedure)"}, 
};

struct  code2dict low_layer_co_rate_adaption_h[] = 
{
    {0, "Rate adaption header not included"}, 
    {1, "Rate adaption header included"}, 
};

struct  code2dict low_layer_co_multiple_frame_e_s_i_d_l[] = 
{
    {0, "Multiple frame establishment not supported. Only UI frames allowed"}, 
    {1, "Multiple frame establishment supported"}, 
};

struct  code2dict low_layer_co_mode_operation[] = 
{
    {0, "Bit transparent mode of operation"}, 
    {1, "Protocol sensitive mode of operation"}, 
};

struct  code2dict low_layer_co_logical_link_i_n[] = 
{
    {0, "DEFAULT, LLI= 256 Only"}, 
    {1, "Full protocol negotiation"}, 
};

struct  code2dict low_layer_co_assignor_assignee[] = 
{
    {0, "Message originator is \"default assignee\""}, 
    {1, "Message originator is \"assignor only\""}, 
};

struct  code2dict low_layer_co_in_band_o_b_n[] = 
{
    {0, "Negotiation is done with USER INFORMATION messages on a temporary signalling connection"}, 
    {1, "Negotiation is done in-band using logical link zero"}, 
};

struct  code2dict low_layer_co_number_stop_b[] = 
{
    {0, "Not used"}, 
    {1, "1 bit"}, 
    {2, "1.5 bits"}, 
    {3, "2 bits"}, 
};

struct  code2dict low_layer_co_number_data_b[] = 
{
    {0, "Not used"}, 
    {1, "5 bits"}, 
    {2, "7 bits"}, 
    {3, "8 bits"}, 
};

struct  code2dict low_layer_co_parity_information[] = 
{
    {0, "Odd"}, 
    {2, "Even"}, 
    {3, "None"}, 
    {4, "Forced to 0"}, 
    {5, "Forced to 1"}, 
};

struct  code2dict low_layer_co_duplex_mode[] = 
{
    {0, "Half duplex"}, 
    {1, "Full duplex"}, 
};

struct  code2dict low_layer_co_modem_type[] = 
{
    {0, "National use"}, 
    {1, "National use"}, 
    {2, "National use"}, 
    {3, "National use"}, 
    {4, "National use"}, 
    {5, "National use"}, 
    {17, "Recommendation V.21"}, 
    {18, "Recommendation V.22"}, 
    {19, "Recommendation V.22 bis"}, 
    {20, "Recommendation V.23"}, 
    {21, "Recommendation V.26"}, 
    {22, "Recommendation V.26 bis"}, 
    {23, "Recommendation V.26 ter"}, 
    {24, "Recommendation V.27"}, 
    {25, "Recommendation V.27 bis"}, 
    {26, "Recommendation V.27 ter"}, 
    {27, "Recommendation V.29"}, 
    {28, "Recommendation V.32"}, 
    {32, "National use"}, 
    {33, "National use"}, 
    {34, "National use"}, 
    {35, "National use"}, 
    {36, "National use"}, 
    {37, "National use"}, 
    {38, "National use"}, 
    {39, "National use"}, 
    {40, "National use"}, 
    {41, "National use"}, 
    {42, "National use"}, 
    {43, "National use"}, 
    {44, "National use"}, 
    {45, "National use"}, 
    {46, "National use"}, 
    {47, "National use"}, 
    {48, "User specified"}, 
    {49, "User specified"}, 
    {50, "User specified"}, 
    {51, "User specified"}, 
    {52, "User specified"}, 
    {53, "User specified"}, 
    {54, "User specified"}, 
    {55, "User specified"}, 
    {56, "User specified"}, 
    {57, "User specified"}, 
    {58, "User specified"}, 
    {59, "User specified"}, 
    {60, "User specified"}, 
    {61, "User specified"}, 
    {62, "User specified"}, 
    {63, "User specified"}, 
};

struct  code2dict low_layer_co_user_information_l2_p[] = 
{
    {1, "Basic mode ISO 1745[36]"}, 
    {2, "Recommendation Q.921(I.441)[3]"}, 
    {6, "Recommendation X.25[5],link layer"}, 
    {15, "Recommendation X.25 Multilink"}, 
    {8, "Extended LAPB; for half duplex operation"}, 
    {9, "HDLC ARM (ISO 4335)[38]"}, 
    {10, "HDLC NRM (ISO 4335)"}, 
    {11, "HDLC ABM (ISO 4335)"}, 
    {12, "LAN logical link control(ISO 8802/2)"}, 
    {13, "Recommendation X.75[40].Signal Link Procedure(SLP)"}, 
    {14, "Recommendation Q.922"}, 
    {15, "Core aspects of Recommendation Q.922"}, 
    {16, "User specified"}, 
    {17, "ISO 7776 DTE-DTE operation"}, 
};

struct  code2dict low_layer_co_mode_operation_6a[] = 
{
    {1, "Normal mode of operation"}, 
    {2, "Extended mode of operation"}, 
    {0, "Reserved"}, 
    {3, "Reserved"}, 
};

struct  code2dict low_layer_co_q933_use[] = 
{
    {0, "For use when the coding defined in Recommendation Q.933 is not used"}, 
    {1, "Reserved"}, 
    {2, "Reserved"}, 
    {3, "Reserved"}, 
};

struct  code2dict low_layer_co_user_information_l3_p[] = 
{
    {2, "Recommendation Q.931"}, 
    {6, "Recommendation X.25, packet layer"}, 
    {7, "ISO/IEC 8208[41](X.25 packet level protocol for data terminal equipment)"}, 
    {8, "CCITT Rec.X.223|ISO 8878[81](use of ISO/IEC 8208[41] and Recommendation X.25 to provide the OSI-CONS)"}, 
    {9, "ISO/IEC 8473[43](OSI connectionless mode protocol)"}, 
    {10, "Recommendation T.70[32] minimum network layer"}, 
    {11, "ISO/IEC TR 9577[82](Protocol identification in the network layer)"}, 
    {16, "User specified"}, 
};

struct  code2dict low_layer_co_mode_operation_7a[] = 
{
    {1, "Normal packet sequence numbering"}, 
    {2, "Extended packet sequence numbering"}, 
    {3, "Reserved"}, 
    {0, "Reserved"}, 
};

struct  code2dict low_layer_co_default_packet_s[] = 
{
    {4, "Default packet size 16 octets"}, 
    {5, "Default packet size 32 octets"}, 
    {6, "Default packet size 64 octets"}, 
    {7, "Default packet size 128 octets"}, 
    {8, "Default packet size 256 octets"}, 
    {9, "Default packet size 512 octets"}, 
    {10, "Default packet size 1024 octets"}, 
    {11, "Default packet size 2048 octets"}, 
    {12, "Default packet size 4096 octets"}, 
};
struct  code2dict secondary_ps_domain_tsc_set[] = 
{
    {0, "TSC set 1"}, 
    {1, "Indicates TSC set 2 for 8PSK, 16QAM and 32QAM modulation. ForGMSK modulation it indicates TSC set 3 "}, 
};
struct  code2dict primary_ps_domain_tsc_set[] = 
{
    {0, "TSC set 1"}, 
    {1, "Indicates TSC set 2 for 8PSK, 16QAM and 32QAM modulation. For GMSK modulation it indicates TSC set 3"}, 
};
struct  code2dict  nd_ps_domain_tsc_assigned[] = 
{
    {0, "A secondary TSC value is not assigned for the PS domain"}, 
    {1, "A secondary TSC value is assigned for the PS domain. The TSC value is indicated by the Secondary PS Domain TSC Value field and the corresponding TSC set is indicated by the Secondary PS Domain TSC Set field"}, 
};
struct  code2dict cs_domain_tsc_set[] = 
{
    {0, "TSC set 1"}, 
    {1, "TSC set 2"},
    {2, "TSC set 3"},
    {3, "TSC set 4"},
};

//liusai(9.1.* x6)

struct  code2dict ciphering_key_s_n_key_sequence[] = 
{
    {0, "Possible values for the ciphering key sequence number"}, 
    {1, "Possible values for the ciphering key sequence number"}, 
    {2, "Possible values for the ciphering key sequence number"}, 
    {3, "Possible values for the ciphering key sequence number"}, 
    {4, "Possible values for the ciphering key sequence number"}, 
    {5, "Possible values for the ciphering key sequence number"}, 
    {6, "Possible values for the ciphering key sequence number"}, 
    {7, "No key is available (MS to network);"}, 
};

struct  code2dict mobile_station_c2_revision_level[] =
{
    {0, "Reserved for GSM phase 1"},
    {1, "Used by GSM phase 2 mobile stations"},
    {2, "Used by mobile stations supporting R99 or later versions of the protocol"},
    {3, "Reserved for future use. If the network receives a revision level specified as 'reserved for future use', then it shall use the highest revision level supported by the network."},
};

struct  code2dict mobile_station_c2_es_ind[] =
{
    {0, "\"Controlled Early Classmark Sending\" option is not implemented in the MS"},
    {1, "\"Controlled Early Classmark Sending\" option is implemented in the MS"},
};

struct  code2dict mobile_station_c2_a51_algorithm_s[] =
{
    {0, "encryption algorithm A5/1 available"},
    {1, "encryption algorithm A5/1 not available"},
};

struct  code2dict mobile_station_c2_rf_power_c0[] =
{
    {0, "class 1"},
    {1, "class 2"},
    {2, "class 3"},
    {3, "class 4"},
    {4, "class 5"},
};

struct  code2dict mobile_station_c2_rf_power_c1[] =
{
    {0, "class 1"},
    {1, "class 2"},
    {2, "class 3"},
};

struct  code2dict mobile_station_c2_rf_power_c2[] =
{
    {7, "RF Power capability is irrelevant in this information element"},
};

struct  code2dict mobile_station_c2_ps_capability[] =
{
    {0, "PS capability not present"},
    {1, "PS capability present"},
};

struct  code2dict mobile_station_c2_ss_screening_ind[] =
{
    {0, "defined in 3GPP TS 24.080 [24]"},
    {1, "defined in 3GPP TS 24.080 [24]"},
    {2, "defined in 3GPP TS 24.080 [24]"},
    {3, "defined in 3GPP TS 24.080 [24]"},
};

struct  code2dict mobile_station_c2_sm_capability[] =
{
    {0, "Mobile station does not support mobile terminated point to point SMS"},
    {1, "Mobile station supports mobile terminated point to point SMS"},
};

struct  code2dict mobile_station_c2_vbs_notification_rec[] =
{
    {0, "no VBS capability or no notifications wanted"},
    {1, "VBS capability and notifications wanted"},
};

struct  code2dict mobile_station_c2_vgcs_notification_rec[] =
{
    {0, "no VGCS capability or no notifications wanted"},
    {1, "VGCS capability and notifications wanted"},
};

struct  code2dict mobile_station_c2_frequency_capability[] =
{
    {0, "The MS does not support the E-GSM or R-GSM band (For definition of frequency bands see 3GPP TS 45.005 [33])"},
    {1, "The MS does support the E-GSM or R-GSM (For definition of frequency bands see 3GPP TS 45.005 [33])"},
};

struct  code2dict mobile_station_c2_cm3[] =
{
    {0, "The MS does not support any options that are indicated in CM3"},
    {1, "The MS supports options that are indicated in classmark 3 IE"},
};

struct  code2dict mobile_station_c2_lcs_va_cap[] =
{
    {0, "location request notification via CS domain not supported"},
    {1, "location request notification via CS domain supported"},
};

struct  code2dict mobile_station_c2_ucs2_treatment[] =
{
    {0, "the ME has a preference for the default alphabet (defined in 3GPP TS 23.038 [8b]) over UCS2."},
    {1, "the ME has no preference between the use of the default alphabet and the use of UCS2."},
};

struct  code2dict mobile_station_c2_solas[] =
{
    {0, "The ME does not support SoLSA."},
    {1, "The ME supports SoLSA."},
};

struct  code2dict mobile_station_c2_cm_service_p[] =
{
    {0, "\"Network initiated MO CM connection request\" not supported."},
    {1, "\"Network initiated MO CM connection request\" supported for at least one CM protocol."},
};

struct  code2dict mobile_station_c2_a53_algorithm_sup[] =
{
    {0, "encryption algorithm A5/3 not available"},
    {1, "encryption algorithm A5/3 available"},
};

struct  code2dict mobile_station_c2_a52_algorithm_sup[] =
{
    {0, "encryption algorithm A5/2 not available"},
    {1, "Not used. This value was allocated in earlier versions of the protocol."},
};

struct code2dict ps_cause_ps_cause_v[] = 
{
    {0, "DTM multislot capabilities violated"},
    {1, "No uplink TBF"},
    {2, "Too many TBFs"},
    {3, "reserved"},
    {4, "reserved"},
    {5, "reserved"},
    {6, "reserved"},
    {7, "reserved"},
};

struct code2dict talker_priority_s_es[] = 
{
    {0, "Emergency mode not set"},
    {1, "Emergency mode set"},
};
 
struct code2dict talker_priority_s_uai[] = 
{
    {0, "Group Channel"},
    {1, "RACH Access"},
};

struct code2dict talker_priority_s_priority[] = 
{
    {0, "Normal Priority"},
    {1, "Privileged Priority"},
    {2, "Emergency Priority"},
    {3, "reserved for future use"},
    {4, "reserved for future use"},
    {5, "reserved for future use"},
    {6, "reserved for future use"},
    {7, "reserved for future use"},
};
 
//10.5.2.22a
struct  code2dict neighbour_cell_d[] =
{
    {0, "bit map 0"},
    {1, "bit map 0"},
    {2, "bit map 0"},
    {3, "bit map 0"},
    {4, "bit map 0"},
    {5, "bit map 0"},
    {6, "bit map 0"},
    {7, "bit map 0"},
    {8, "1024 range"},
    {9, "1024 range"},
    {10, "1024 range"},
    {11, "1024 range"},
    {12, "512 range"},
    {13, "256 range"},
    {14, "128 range"},
    {15, "variable bit map"},
};

struct code2dict neighbour_cell_d_e_i[]=
{
    {0, "The information element carries the complete BA"},
    {1, "The information element carries only a part of the BA"},
};

struct code2dict feature_indicator_cs_ir[]=
{
    {0, "An implicit reject is not indicated for the CS domain."},
    {1, "An implicit reject is indicated for the CS domain."},
};

struct code2dict feature_indicator_ps_ir[]=
{
    {0, "An implicit reject is not indicated for the PS domain."},
    {1, "An implicit reject is indicated for the PS domain."},
};

struct code2dict plmn_index_plmn_index[]= 
{
    {1, "001 - PLMN identity of the Common PLMN broadcast in SYSTEM INFORMATION TYPE 3/4"},
    {2, "010 - PLMN identity of the first Additional PLMN in the network sharing information broadcast in SYSTEM INFORMATION TYPE 22"},
    {3, "011 - PLMN identity of the second Additional PLMN in the network sharing information broadcast broadcast in SYSTEM INFORMATION TYPE 22"},
    {4, "100 - PLMN identity of the third Additional PLMN in the network sharing information broadcast in SYSTEM INFORMATION TYPE 22"},
    {5, "101 - PLMN identity of the fourth Additional PLMN in the network sharing information broadcast in SYSTEM INFORMATION TYPE 22"},
};

struct code2dict additional_update_parameters_csmo[]= 
{
    {0, "No additional information."},
    {1, "CS fallback mobile originating call"},
};

struct code2dict additional_update_parameters_csmt[]= 
{
    {0, "No additional information."},
    {1, "CS fallback mobile terminating call"},
};


//end liusai

struct code2dict descriptive_group_broadcast_call_reference_call_priority[]= 
{
    {0, "no priority applied"},
    {1, "call priority level 4"},
    {2, "call priority level 3"},
    {3, "call priority level 2"},
    {4, "call priority level 1"},
    {5, "call priority level 0"},
    {6, "call priority level B"},
    {7, "call priority level A"},
};

struct code2dict descriptive_group_broadcast_call_reference_ciphering_information[]= 
{
    {0, "no ciphering"},
    {1, "ciphering with cipher key number 1"},
    {2, "ciphering with cipher key number 2"},
    {3, "ciphering with cipher key number 3"},
    {4, "ciphering with cipher key number 4"},
    {5, "ciphering with cipher key number 5"},
    {6, "ciphering with cipher key number 6"},
    {7, "ciphering with cipher key number 7"},
    {8, "ciphering with cipher key number 8"},
    {9, "ciphering with cipher key number 9"},
    {10, "ciphering with cipher key number A"},
    {11, "ciphering with cipher key number B"},
    {12, "ciphering with cipher key number C"},
    {13, "ciphering with cipher key number D"},
    {14, "ciphering with cipher key number E"},
    {15, "ciphering with cipher key number F"},
};
struct code2dict network_name_add_ci[]= 
{
    {0, "The MS should not add the letters for the Country's Initials to the text string"},
    {1, "The MS should add the letters for the Country's Initials and a separator"},
}; 

struct code2dict network_name_number_of_s_b_i_l_o[]= 
{
    {0, "this field carries no information about the number of spare bits in octet n"},
    {1, "bit 8 is spare and set to \"0\" in octet n"},
    {2, "bits 7 and 8 are spare and set to \"0\" in octet n"},
    {3, "bits 6 to 8(inclusive) are spare and set to \"0\" in octet n"},
    {4, "bits 5 to 8(inclusive) are spare and set to \"0\" in octet n"},
    {5, "bits 4 to 8(inclusive) are spare and set to \"0\" in octet n"},
    {6, "bits 3 to 8(inclusive) are spare and set to \"0\" in octet n"},
    {7, "bits 2 to 8(inclusive) are spare and set to \"0\" in octet n"},
};

struct code2dict network_name_daylight_saving_t_v[]= 
{
    {0, "No adjustment for Daylight Saving Time"},
    {1, "+1 hour adjustment for Daylight Saving Time"},
    {2, "+2 hours adjustment for Daylight Saving Time"},
    {3, "Reserved"},
};

struct code2dict call_state_call_state_value[]= 
{
    {0, "UO - null"},
    {1, "U1 - call initiated"},
    {2, "U0.1- MM connection pending"},
    {3, "U3 - mobile originating call proceeding"},
    {4, "U4 - call delivered"},
    {6, "U6 - call present"},
    {7, "U7 - call received"},
    {8, "U8 - connect request"},
    {9, "U9 - mobile terminating call confirmed"},
    {10, "U10- active"},
    {11, "U11- disconnect request"},
    {12, "U12- disconnect indication"},
    {19, "U19- release request"},
    {26, "U26- mobile originating modify"},
    {27, "U27- mobile terminating modify"},
    {28, "N28- connect indication"},
    {34, "U0.2- CC prompt present"},
    {35, "U0.3- Wait for network information"},
    {36, "U0.4- CC-Establishment present"},
    {37, "U0.5- CC-Establishment confirmed"},
    {38, "U0.6- Recall presen"},
};
 
struct code2dict auxiliary_states_hold_auxiliary_state[]= 
{
    {0, "idle"},
    {1, "hold request"},
    {2, "call held"},
    {3, "retrieve request"},
};

struct code2dict auxiliary_states_multi_party_a_s[]= 
{
    {0, "idle"},
    {1, "MPTY request"},
    {2, "call in MPTY"},
    {3, "split request"},
};


struct code2dict gb_ns_pdu_type[]= 
{
    {0, "NS-UNITDATA"},
    {2 , "NS-RESET"},
    {3 , "NS-RESET-ACK"},
    {4 , "NS-BLOCK"},
    {5 , "NS-BLOCK-ACK"},
    {6 , "NS-UNBLOCK"},
    {7 , "NS-UNBLOCK-ACK"},
    {8 , "NS-STATUS"},
    {10 , "NS-ALIVE"},
    {11 , "NS-ALIVE-ACK"},
};


struct code2dict gb_cause[]= 
{
    {0, "Transit network failure"},
    {1, "O&M intervention"},
    {2, "Equipment failure"},
    {3, "NS-VC blocked"},
    {4, "NS-VC unknown"},
    {5, "BVCI unknown on that NSE"},
    {8, "Semantically incorrect PDU"},
    {10, "PDU not compatible with the protocol state"},
    {11, "Protocol error - unspecified"},
    {12, "Invalid essential IE"},
    {13, "Missing essential IE"},
};

struct code2dict gb_bssgp_pdu_type[]= 
{
    {0, "DL-UNITDATA"},
    {1, "UL-UNITDATA"},
    {2, "RA-CAPABILITY"},
    {3, "PTM-UNITDATA"},
    {6, "PAGING PS"},
    {7, "PAGING CS"},
    {8, "RA-CAPABILITY-UPDATE"},
    {9, "RA-CAPABILITY-UPDATE-ACK"},
    {10, "RADIO-STATUS"},
    {11, "SUSPEND"},
	{12, "SUSPEND-ACK"},
	{13, "SUSPEND-NACK"},
	{14, "RESUME"},
	{15, "RESUME-ACK"},
	{16, "RESUME-NACK"},
	{32, "BVC-BLOCK"},
	{33, "BVC-BLOCK-ACK"},
	{34, "BVC-RESET"},
	{35, "BVC-RESET-ACK"},
	{36, "BVC-UNBLOCK"},
	{37, "BVC-UNBLOCK-ACK"},
	{38, "FLOW-CONTROL-BVC"},
	{39, "FLOW-CONTROL-BVC-ACK"},
	{40, "FLOW-CONTROL-MS"},
	{41, "FLOW-CONTROL-MS-ACK"},
	{42, "FLUSH-LL"},
	{43, "FLUSH-LL-ACK"},
	{44, "LLC-DISCARDED"},
	{64, "SGSN-INVOKE-TRACE"},
	{65, "STATUS"},
	{80, "DOWNLOAD-BSS-PFC"},
	{81, "CREATE-BSS-PFC"},
	{82, "CREATE-BSS-PFC-ACK"},
	{83, "CREATE-BSS-PFC-NACK"},
	{84, "MODIFY-BSS-PFC"},
	{85, "MODIFY-BSS-PFC-ACK"},
	{86, "DELETE-BSS-PFC"},
	{87, "DELETE-BSS-PFC-ACK"},
};      

struct code2dict gb_precedence_dl[]= 
{
    {0, "High priority"},
    {1, "Normal priority"},
    {2, "Normal priority"},
    {3, "Reserved"},
    {4, "Reserved"},
};

struct code2dict gb_precedence_ul[]= 
{
    {0, "Radio priority 1"},
    {1, "Radio priority 2"},
    {2, "Radio priority 3"},
    {3, "Radio priority 4"},
    {4, "Radio Priority Unknown"},
};

struct code2dict gb_cn_specific_drx_cycle[]= 
{
    {0, "For Iu mode, CN Specific DRX cycle length coefficient not specified by the MS; For Iu mode, CN Specific DRX cycle length coefficient not specified by the MS"},
    {6, "CN Specific DRX cycle length coefficient 6 and T = 32"},
    {7, "CN Specific DRX cycle length coefficient 7 and T = 64"},
    {8, "CN Specific DRX cycle length coefficient 8 and T = 128"},
    {9, "CN Specific DRX cycle length coefficient 9 and T = 256"},
};

struct code2dict gb_non_drx_timer[]= 
{
    {0, "no non-DRX mode after transfer state"},
    {1, "max.  1 sec non-DRX mode after transfer state"},
    {2, "max.  2 sec non-DRX mode after transfer state"},
    {3, "max.  4 sec non-DRX mode after transfer state"},
    {4, "max.  8 sec non-DRX mode after transfer state"},
    {5, "max.  16 sec non-DRX mode after transfer state"},
    {6, "max.  32 sec non-DRX mode after transfer state"},
    {7, "max.  64 sec non-DRX mode after transfer state"},
};

struct code2dict gb_split_on_ccch[]= 
{
    {0, "Split pg cycle on CCCH is not supported by the mobile station"},
    {1, "Split pg cycle on CCCH is supported by the mobile station"},
};


struct code2dict gb_split_pg_cycle_code[]= 
{
    {65, "71"},
    {66, "72"},
    {67, "74"},
    {68, "75"},
    {69, "77"},
    {70, "79"},
    {71, "80"},
    {72, "83"},
    {73, "86"},
    {74, "88"},
    {75, "90"},
    {76, "92"},
    {77, "96"},
    {78, "101"},
    {79, "103"},
    {80, "107"},
    {81, "112"},
    {82, "116"},
    {83, "118"},
    {84, "128"},
    {85, "141"},
    {86, "144"},
    {87, "150"},
    {88, "160"},
    {89, "171"},
    {90, "176"},
    {91, "192"},
    {92, "214"},
    {93, "224"},
    {94, "235"},
    {95, "256"},
    {96, "288"},
    {97, "320"},
    {98, "352"},
};

struct code2dict gb_packet_flow_identifier_v[]= 
{
    {0, "Best Effort"},
    {1, "Signaling"},
    {2, "SMS"},
    {3, "TOM8"},
};
 
struct code2dict gb_service_utran_cco_v[]= 
{
    {0, "Network initiated cell change order procedure to UTRAN should be performed"},
    {1, "Network initiated cell change order procedure to UTRAN should not be performed"},
    {2, "Network initiated cell change order procedure to UTRAN shall not be performed"},
};


struct code2dict gb_guaranteed_bit_rate_f_u_e2[]= 
{
	{1, "The guaranteed bit rate is 256 Mbps + ((the binary coded value in 8 bits) * 4 Mbps)"},
	{61, "giving a range of values from 260 Mbps to 500 Mbps in 4 Mbps increments"},
	{62, "The guaranteed bit rate is 500 Mbps + ((the binary coded value in 8 bits - 00111101) * 10 Mbps)"},
	{161, "giving a range of values from 510 Mbps to 1500 Mbps in 10 Mbps increments."},
	{162, "The guaranteed bit rate is 1500 Mbps + ((the binary coded value in 8 bits - 10100001) * 100 Mbps)"},
	{246, "giving a range of values from 1600 Mbps to 10 Gbps in 100 Mbps increments"},
};


struct code2dict gb_maximum_bit_rate_f_u_e2[]= 
{
	{1, "The maximum bit rate is 256 Mbps + ((the binary coded value in 8 bits) * 4 Mbps)"},
	{61, "giving a range of values from 260 Mbps to 500 Mbps in 4 Mbps increments"},
	{62, "The maximum bit rate is 500 Mbps + ((the binary coded value in 8 bits - 00111101) * 10 Mbps)"},
	{161, "giving a range of values from 510 Mbps to 1500 Mbps in 10 Mbps increments"},
	{162, "The maximum bit rate is 1500 Mbps + ((the binary coded value in 8 bits - 10100001) * 100 Mbps)"},
	{246, "giving a range of values from 1600 Mbps to 10 Gbps in 100 Mbps increments"},
};


struct code2dict gb_guaranteed_bit_rate_f_u_e[]= 
{
	{1, "The guaranteed bit rate is 8600 kbps + ((the binary coded value in 8 bits) * 100 kbps)"},
	{74, "giving a range of values from 8700 kbps to 16000 kbps in 100 kbps increments"},
	{75, "The guaranteed bit rate is 16 Mbps + ((the binary coded value in 8 bits - 01001010) * 1 Mbps)"},
	{186, "giving a range of values from 17 Mbps to 128 Mbps in 1 Mbps increments"},
	{187, "The guaranteed bit rate is 128 Mbps + ((the binary coded value in 8 bits - 10111010) * 2 Mbps)"},
	{250, "giving a range of values from 130 Mbps to 256 Mbps in 2 Mbps increments"},
};


struct code2dict gb_maximum_bit_rate_f_u_e[]= 
{
	{1, "The maximum bit rate is 8600 kbps + ((the binary coded value in 8 bits) * 100 kbps)"},
	{74, "giving a range of values from 8700 kbps to 16000 kbps in 100 kbps increments"},
	{75, "The maximum bit rate is 16 Mbps + ((the binary coded value in 8 bits - 01001010) * 1 Mbps)"},
	{186, "giving a range of values from 17 Mbps to 128 Mbps in 1 Mbps increments."},
	{187, "The maximum bit rate is 128 Mbps + ((the binary coded value in 8 bits - 10111010) * 2 Mbps)"},
	{250, "giving a range of values from 130 Mbps to 256 Mbps in 2 Mbps increments"},
};


struct code2dict gb_maximum_bit_rate_f_u[]= 
{
	{1, "The maximum bit rate is binary coded in 8 bits, using a granularity of 1 kbps"},
	{63, "giving a range of values from 1 kbps to 63 kbps in 1 kbps increments"},
	{64, "The maximum bit rate is 64 kbps + ((the binary coded value in 8 bits –01000000) * 8 kbps)"},
	{127, "giving a range of values from 64 kbps to 568 kbps in 8 kbps increments"},
	{128, "The maximum bit rate is 576 kbps + ((the binary coded value in 8 bits –10000000) * 64 kbps)"},
	{254, "giving a range of values from 576 kbps to 8640 kbps in 64 kbps increments"},
	{255, "0kbps"},
};
struct code2dict gb_guaranteed_bit_rate_f_u[]= 
{
	{1, "The guaranteed bit rate is binary coded in 8 bits, using a granularity of 1 kbps"},
	{63, "giving a range of values from 1 kbps to 63 kbps in 1 kbps increments"},
	{64, "The guaranteed bit rate is 64 kbps + ((the binary coded value in 8 bits –01000000) * 8 kbps)"},
	{127, "giving a range of values from 64 kbps to 568 kbps in 8 kbps increments"},
	{128, "The guaranteed bit rate is 576 kbps + ((the binary coded value in 8 bits –10000000) * 64 kbps)"},
	{254, "giving a range of values from 576 kbps to 8640 kbps in 64 kbps increments"},
	{255, "0kbps"},

};
struct code2dict gb_signalling_indication[]= 
{
	{0, "Not optimised for signalling traffic"},
	{1, "Optimised for signalling traffic"},
};
struct code2dict gb_transfer_delay[]= 
{
	{1, "The Transfer delay is binary coded in 6 bits, using a granularity of 10 ms"},
	{63, "giving a range of values from 10 ms to 150 ms in 10 ms increments"},
	{64, "The transfer delay is 200 ms + ((the binary coded value in 6 bits – 010000) * 50 ms)"},
	{127, "giving a range of values from 200 ms to 950 ms in 50ms increments"},
	{128, "The transfer delay is 1000 ms + ((the binary coded value in 6 bits – 100000) * 100 ms)"},
	{254, "giving a range of values from 1000 ms to 4000 ms in 100ms increments"},
	{255, "Reserved"},
};
struct code2dict gb_traffic_handling_priority[]= 
{
	{1, "Priority level 1"},
	{2, "Priority level 2"},
	{3, "Priority level 3"},
};
struct code2dict gb_sdu_error_ratio[]= 
{
	{1, "1*(1/100)"},
	{2, "7*(1/1000)"},
	{3, "1*(1/1000)"},
	{4, "1*(1/10000)"},
	{5, "1*(1/100000)"},
	{6, "1*(1/1000000)"},
	{7, "1*(1/10)"},
	{15, "Reserved"},
};

struct code2dict gb_residual_ber[]= 
{
	{1, "5*(1/100)"},
	{2, "1*(1/100)"},
	{3, "5*(1/1000)"},
	{4, "4*(1/1000)"},
	{5, "1*(1/1000)"},
	{6, "1*(1/10000)"},
	{7, "1*(1/100000)"},
	{8, "1*(1/1000000)"},
	{9, "6*(1/100000000)"},
};

struct code2dict gb_maximum_sdu_size[]= 
{
	{151, "1502 octets"},
	{152, "1510 octets"},
	{153, "1520 octets"},
};

struct code2dict gb_traffic_class[]= 
{
	{1, "Conversational class"},
	{2, "Streaming class"},
	{3, "Interactive class"},
	{4, "Background class"},
	{7, "Reserved"},
};

struct code2dict gb_delivery_order[]= 
{
	{1, "With delivery order ('yes')"},
	{2, "Without delivery order ('no')"},
	{3, "Reserved"},
};

struct code2dict gb_delivery_of_erroneous_sdu[]= 
{
	{1, "No detect ('-')"},
	{2, "Erroneous SDUs are delivered ('yes')"},
	{3, "Erroneous SDUs are not delivered ('no')"},
	{7, "Reserved"},
};

struct code2dict gb_mean_throughput[]= 
{
	{1, "100 octet/h"},
	{2, "200 octet/h"},
	{3, "500 octet/h"},
	{4, "1000 octet/h"},
	{5, "2000 octet/h"},
	{6, "5000 octet/h"},
	{7, "10000 octet/h"},
	{8, "20000 octet/h"},
	{9, "50000 octet/h"},
	{10, "100000 octet/h"},
	{11, "200000 octet/h"},
	{12, "500000 octet/h"},
	{13, "1000000 octet/h"},
	{14, "2000000 octet/h"},
	{15, "5000000 octet/h"},
	{16, "10000000 octet/h"},
	{17, "20000000 octet/h"},
	{18, "50000000 octet/h"},
	{30, "Reserved"},
	{31, "Best effort"},
};

struct code2dict gb_peak_throughput[]= 
{
	{1, "Up to 1 000 octet/s"},
	{2, "Up to 2 000 octet/s"},
	{3, "Up to 4 000 octet/s"},
	{4, "Up to 8 000 octet/s"},
	{5, "Up to 16 000 octet/s"},
	{6, "Up to 32 000 octet/s"},
	{7, "Up to 64 000 octet/s"},
	{8, "Up to 128 000 octet/s"},
	{9, "Up to 256 000 octet/s"},
	{15, "Reserved"},
};

struct code2dict gb_precedence_class[]= 
{
	{1, "High priority"},
	{2, "Normal priority"},
	{3, "Low priority"},
	{7, "Reserved"},
};

struct code2dict gb_delay_class[]= 
{
	{1, "Delay class 1"},
	{2, "Delay class 2"},
	{3, "Delay class 3"},
	{4, "Delay class 4 (best effort)"},
	{7, "Reserved"},
};

struct code2dict gb_reliability_class[]= 
{
	{1, "Unused. If received, it shall be interpreted as '010'"},
	{2, "Unacknowledged GTP; Acknowledged LLC and RLC, Protected data"},
	{3, "Unacknowledged GTP and LLC; Acknowledged RLC, Protected data"},
	{4, "Unacknowledged GTP, LLC, and RLC, Protected data"},
	{5, "Unacknowledged GTP, LLC, and RLC, Unprotected data"},
	{7, "Reserved"},
};


struct code2dict gb_priority_level[]= 
{
	{0, "spare"},
	{1, "priority level 1 = highest priority"},
	{2, "priority level 2 = second highest priority"},
	{3, "priority level 3 = three highest priority"},
	{4, "priority level 4 = four highest priority"},
	{5, "priority level 5 = five highest priority"},
	{6, "priority level 6 = sex highest priority"},
	{7, "priority level 7 = seven highest priority"},
	{8, "priority level 8 = eight highest priority"},
	{9, "priority level 9 = nine highest priority"},
	{10, "priority level 10 = ten highest priority"},
	{11, "priority level 11 = eleven highest priority"},
	{12, "priority level 12 = twelve highest priority"},
	{13, "priority level 13 = thirteen highest priority"},
	{14, "priority level 14 = lowest priority"},
	{15, "priority not used"},
};

struct code2dict gb_cause_v[]= 
{
	{0, "Processor overload"},
	{1, "Equipment failure"},
	{2, "Transit network service failure"},
	{3, "Network service transmission capacity modified from zero kbps to greater than zero kbps"},
	{4, "Unknown MS"},
	{5, "BVCI unknown"},
	{6, "cell traffic congestion"},
	{7, "SGSN congestion"},
	{8, "O & M intervention"},
	{9, "BVCI-blocked"},
	{10, "PFC create failure"},
	{32, "Semantically incorrect PDU"},
	{33, "Invalid mandatory information"},
	{34, "Missing mandatory IE"},
	{35, "Missing conditional IE"},
	{36, "Unexpected conditional IE"},
	{37, "Conditional IE error"},
	{38, "PDU not compatible with the protocol state"},
	{39, "Protocol error - unspecified"},
	{40, "PDU not compatible with the feature set"},
};

struct code2dict gb_unit_value[]= 
{
	{0, "value is incremented in multiples of 2 seconds"},
	{1, "value is incremented in multiples of 1 minute"},
	{2, "value is incremented in multiples of decihours"},
	{7, "value indicates that the timer does not expire"},
};


struct code2dict gb_sapi[]= 
{
	{0, "Reserved"},
	{1, "GPRS Mobility Management"},
	{2, "Tunnelling of messages 2"},
	{3, "User data 3"},
	{4, "Reserved"},
	{5, "User data 5"},
	{6, "Reserved"},
	{7, "SMS"},
	{8, "Tunnelling of messages 8"},
	{9, "User data 9"},
	{10, "Reserved"},
	{11, "User data 11"},
	{12, "Reserved"},
	{13, "Reserved"},
	{14, "Reserved"},
	{15, "Reserved"},
};


struct code2dict gb_s1_s2[]= 
{
	{0, "RR"},
	{1, "ACK"},
	{2, "RNR"},
	{3, "SACK"},
};


struct code2dict gb_m1_m4[]= 
{
	{0, "NULL"},
	{1, "DM"},
	{4, "DISC"},
	{6, "UA"},
	{7, "SABM"},
	{8, "FRMR"},
	{11, "XID"},
};


struct code2dict gb_llc_xid_type[]= 
{
	{0, "Version (LLC version number)"},
	{1, "IOV-UI (ciphering Input offset value for UI frames), common for all SAPIs of a TLLI"},
	{2, "IOV-I (ciphering Input offset value for I frames), for the SAPI under negotiation"},
	{3, "T200 (retransmission time-out)"},
	{4, "N200 (maximum number of retransmissions)"},
	{5, "N201-U (maximum information field length for U and UI frames)"},
	{6, "N201-I (maximum information field length for I frames)"},
	{7, "mD (I frame buffer size in the downlink direction)"},
	{8, "mU (I frame buffer size in the uplink direction)"},
	{9, "kD (window size in the downlink direction)"},
	{10, "kU (window size in the uplink direction)"},
	{11, "Layer-3 Parameters"},
	{12, "Reset"},
};

#if 0
struct code2dict gb_[]= 
{
	{, ""},
};
#endif
