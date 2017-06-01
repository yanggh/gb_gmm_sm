#ifndef __UM_APP_COMMON_H__
#define __UM_APP_COMMON_H__

#include "um_fcs_check.h"

char _hex_buf[1024];
char _hex_desc_buf[4096];
char *_hex = NULL;
char *_hex_desc = NULL;

void datalink()
{    
    BEGIN_ELEMENT("datalink", datalink); 

    uint8_t flag = HdlcFcsCheck(len - 2, input + 1);

    if (flag == 0)
    {
    B8_HEX(); 
    A_B8_BIT1(c3f, f_start, "Flag", 1, 8); 
    SKIP(1);  

    B8_HEX(); 
    A_B8_BIT1(c3f, address, "address", 1, 8);
    APPEND_EXPLAIN("Addr"); 
    SKIP(1);  
    
    uint8_t frame_type;
    uint8_t msg_type;
    B8_HEX();
    B8_BIT(frame_type, 1, 1); 
    if( frame_type == 0) 
    { 
        /*I frame*/ 
        SET_FRAME_TYPE("HDLC:I"); 
        SET_MSG_TYPE("I"); 
        SET_ELEMENT("I", I); 
		
        A_B8_BIT1(c3f, Ns, "Ns", 2, 8); 
        APPEND_EXPLAIN("N(S)"); 
        SKIP(1); 
        B8_HEX();
        A_B8_BIT1(c3f, Nr, "Nr", 2, 8); 
        APPEND_EXPLAIN("N(R)"); 
        A_B8_BIT1(c3f, Pf, "Pf", 1, 1); 
        APPEND_EXPLAIN("Pf"); 
        SKIP(1);

        HEX(len - 7); 
        A_BN_BIT1(len - 7);
        SKIP(len - 7);
    }
    else
    { 
        B8_BIT(frame_type, 1, 2); 
        if (frame_type == 1) 
        { 
            /*S frame*/ 
            SET_FRAME_TYPE("HDLC:S");
            B8_BIT(msg_type, 3, 4);
            
            if ( msg_type == 0)
            {
                //SS=00 RR
                SET_MSG_TYPE("RR"); 
                SET_ELEMENT("RR", RR); 
            }
            else if (msg_type == 1)
            {
                //SS=10 RNR
                SET_MSG_TYPE("RNR"); 
                SET_ELEMENT("RNR", RNR);
            }
            else if (msg_type == 2)
            {
                //SS=01 REJ
                SET_MSG_TYPE("REJ"); 
                SET_ELEMENT("REJ", REJ); 
            } 
            else
            {
                //SS=11 SREJ
                SET_MSG_TYPE("SREJ"); 
                SET_ELEMENT("SREJ", SREJ); 
            }

            SKIP(1); 
            B8_HEX(); 
            A_B8_BIT1(c3f, Nr, "Nr", 2, 8); 
            APPEND_EXPLAIN("N(R)"); 
            A_B8_BIT1(c3f, Pf, "Pf", 1, 1); 
            APPEND_EXPLAIN("Pf"); 
            SKIP(1); 
        } 
        else 
        { 
            /*U frame*/
            SET_FRAME_TYPE("HDLC:U"); 
            uint8_t type1;
            uint8_t type2; 
            B8_BIT(type1, 3, 4);
            B8_BIT(type2, 6, 8);
            msg_type = type2 << 2 | type1;
            if ( msg_type == 0x0f)
            {
                //011P1111：SABME帧 0x0f
                SET_MSG_TYPE("SABME"); 
                SET_ELEMENT("SABME", SABME); 
            }
            else if ( msg_type == 0x08)
            {
                //010P0011：DISC帧  0x08
                SET_MSG_TYPE("DISC"); 
                SET_ELEMENT("DISC", DISC); 
            }
            else if ( msg_type == 0x00)
            {
                //000P0011：UI帧    0x00
                SET_MSG_TYPE("UI"); 
                SET_ELEMENT("UI", UI); 
            }
            if ( msg_type == 0x03)
            {
                //000F1111：DM帧    0x03
                SET_MSG_TYPE("DM"); 
                SET_ELEMENT("DM", DM); 
            }
            if ( msg_type == 0x0c)
            {
                //011F0011：UA帧    0x0c
                SET_MSG_TYPE("UA"); 
                SET_ELEMENT("UA", UA); 
            }
            if ( msg_type == 0x11)
            {
                //100F0111：FRMR帧  0x11
                SET_MSG_TYPE("FRMR"); 
                SET_ELEMENT("FRMR", FRMR); 
            }

            A_B8_BIT1(c3f, Pf, "Pf", 5, 5); 
            APPEND_EXPLAIN("Pf"); 
            SKIP(1); 
        }
    }

  
    HEX(2); 
    A_B8_VALUE(c3f, fcs, "fcs", flag); 
    SKIP(2); 

    B8_HEX();  
    A_B8_BIT1(c3f, f_end, "Flag", 1, 8); 
    SKIP(1);  
    }
    else
    {
        SET_FRAME_TYPE("HDLC");
        SET_MSG_TYPE("Unknown"); 
        A_B8_VALUE(c3f, fcs, "fcs", flag); 
    }

    END_ELEMENT(); 
}

void network()
{    
    BEGIN_ELEMENT("NPDU", NPDU); 
    SET_ELEMENT("Data", Data);

    uint16_t header;
    
    B16_BIT(header, 1, 16);

    if (header == 0x0180 || header == 0x0100)
    {
        HEX(2); 
        A_B16_BIT1(c3f, head, "head", 1, 16); 
        //SKIP(2);
    
        //HEX(len); 
        A_BN_BIT1(len);
        //SKIP(len);
    }
    else
    {
        SET_MSG_TYPE("Unknown"); 
    }


    END_ELEMENT(); 
}

//Transport-Selector (T-selector)
void transport_selector(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, transport_selectorid, "Transport-Selector code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, transport_selectorlen, "Transport-Selector len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, transport_selectorvalue, "Transport-Selector value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//TPDU size
void tpdu_size(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, tpdu_sizeid, "TPDU size code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, tpdu_sizelen, "TPDU size len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, tpdu_sizevalue, "TPDU size value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}


//Preferred maximum TPDU size
void prefer_maxi_tpdu_size(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, prefer_maxi_tpdu_sizeid, "Preferred maximum TPDU size code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, prefer_maxi_tpdu_sizelen, "Preferred maximum TPDU size len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, prefer_maxi_tpdu_sizevalue, "Preferred maximum TPDU size value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Version number
void version_number(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, version_numberid, "Version number code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, version_numberlen, "Version number len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, version_numbervalue, "Version number value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Protection parameters
void protection_param(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, protection_paramid, "Protection parameters code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, protection_paramlen, "Protection parameters len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, protection_paramvalue, "Protection parameters value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Checksum
void checksum(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, checksumid, "Checksum code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, checksumlen, "Checksum len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, checksumvalue, "Checksum value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}


//Additional option selection
void additional_option_selection(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, additional_option_selectionid, "Additional option selection code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, additional_option_selectionlen, "Additional option selection len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, additional_option_selectionvalue, "Additional option selection value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Alternative protocol class
void alternative_proto_class(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;
    
    HEX(1); A_B8_BIT1(c3f, alternative_proto_classid, "Alternative protocol class code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, alternative_proto_classlen, "Alternative protocol class len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, alternative_proto_classvalue, "Alternative protocol class value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Acknowledgement time
void acknowledgement_time(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, acknowledgement_timeid, "Acknowledgement time code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, acknowledgement_timelen, "Acknowledgement time len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, acknowledgement_timevalue, "Acknowledgement time value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Throughput
void throughput(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, throughputid, "Throughput code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, throughputlen, "Throughput len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, throughputvalue, "Throughput value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Residual error rate
void residual_rerror_rate(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, residual_rerror_rateid, "Residual error rate code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, residual_rerror_ratelen, "Residual error rate len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, residual_rerror_ratevalue, "Residual error rate value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Priority
void priority(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, priorityid, "Priority code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, prioritylen, "Priority len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, priorityvalue, "Priority value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Transit delay
void transit_delay(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, transit_delayid, "Transit delay code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, transit_delaylen, "Transit delay len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, transit_delayvalue, "Transit delay value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Reassignment time
void reassignment_time(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, reassignment_timeid, "Reassignment time code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, reassignment_timelen, "Reassignment time len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, reassignment_timevalue, "Reassignment time value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Inactivity timer
void inactivity_timer(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, inactivity_timerid, "Inactivity timer code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, inactivity_timerlen, "Inactivity timer len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, inactivity_timervalue, "Inactivity timer value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}



//Invalid TPDU
void invalid_tpdu(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, invalid_tpduid, "Invalid TPDU code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, invalid_tpdulen, "Invalid TPDU len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, invalid_tpduvalue, "Invalid TPDU value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Subsequence number
void subsequence_number(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, subsequence_numberid, "Subsequence number code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, subsequence_numberlen, "Subsequence number len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, subsequence_numbervalue, "Subsequence number value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Flow control confirmation
void flow_control_confirmation(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, flow_control_confirmationid, "Flow control confirmation code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, flow_control_confirmationlen, "Flow control confirmation len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, flow_control_confirmationvalue, "Flow control confirmation value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Selective acknowledgement
void selective_acknowledgement(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, selective_acknowledgementid, "Selective acknowledgement code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, selective_acknowledgementlen, "Selective acknowledgement len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, selective_acknowledgementvalue, "Selective acknowledgement value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Additional information
void additional_information(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, additional_informationid, "Additional information code", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, additional_informationlen, "Additional information len", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, additional_informationvalue, "Additional information value", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

//Default
void default_param(uint8_t *pleft)
{
    uint8_t paramid;
    uint8_t paramlen;

    HEX(1); A_B8_BIT1(c3f, paramid, "paramid", 1, 8); SKIP(1); 
    B8_BIT(paramlen, 1, 8);
    HEX(1); A_B8_BIT1(c3f, paramlen, "paramlen", 1, 8); SKIP(1); 
    HEX(paramlen); A_B16_BIT1(c3f, paramvalue, "paramvalue", 1, 16); 
    SKIP(paramlen);
    *pleft -= (paramlen + 2);
}

void transport(uint32_t len)
{
    BEGIN_ELEMENT("TPDU", TPDU);
    
    uint8_t LI;
    uint8_t left;
    uint8_t pre_left;
    uint8_t type;

    uint8_t paramid;
    uint8_t paramlen;

    HEX(1);
    B8_BIT(LI, 1, 8); 
    A_B8_BIT1(c3f, LI, "LI", 1, 8);
    SKIP(1); 
  
    left = LI; 
 
    HEX(1); 
    B8_BIT(type, 5, 8); 
    A_B8_BIT1(c3f, type, "type", 5, 8);
    
    if(type == 14) 
    {
        //1110 CR
        SET_MSG_TYPE("CR"); 
        SET_ELEMENT("CR", CR);

        A_B8_BIT1(c3f, cdt, "cdt", 1, 4); 
        APPEND_EXPLAIN("cdt"); 
        SKIP(1);
 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(2); 
        A_B16_BIT1(c3f, src_ref, "src_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B8_BIT1(c3f, class_option, "class_option", 1, 8); 
        SKIP(1); 
        
        left = LI - 6;

        pre_left = left;
        while(left > 0)
        {
            B8_BIT(paramid, 1, 8);
            printf("paramid 0x%x\n",paramid);
    
            switch (paramid)
            {
                case 0xc1:
                { 
                    transport_selector(&left);
                    break;
                } 
                case 0xc0:
                { 
                    tpdu_size(&left);
                    break;
                } 
                case 0xf0:
                { 
                    prefer_maxi_tpdu_size(&left);
                    break;
                } 
                case 0xc4:
                { 
                    version_number(&left);
                    break;
                } 
                case 0xc5:
                { 
                    protection_param(&left);
                    break;
                } 
                case 0xc3:
                { 
                    checksum(&left);
                    break;
                } 
                case 0xc6:
                { 
                    additional_option_selection(&left);
                    break;
                } 
                case 0xc7:
                { 
                    alternative_proto_class(&left);
                    break;
                } 
                case 0x85:
                { 
                    acknowledgement_time(&left);
                    break;
                } 
                case 0x89:
                { 
                    throughput(&left);
                    break;
                } 
                case 0x86:
                { 
                    residual_rerror_rate(&left);
                    break;
                } 
                case 0x87:
                { 
                    priority(&left);
                    break;
                } 
                case 0x88:
                { 
                    transit_delay(&left);
                    break;
                } 
                case 0x8b:
                { 
                    reassignment_time(&left);
                    break;
                } 
                case 0xf2:
                { 
                    inactivity_timer(&left);
                    break;
                }
                default:
                {
                    default_param(&left);
                    break;
                }
            }
            if (pre_left == left)
            {
                break;
            }
            else
            {
                pre_left = left;
            }
        }

        SKIP(left);

        HEX(len - LI - 1); 
        A_BN_BIT1(len - LI - 1);
        SKIP(len - LI - 1);
    } 
    else if(type == 13) 
    { 
        //1101 CC
        SET_MSG_TYPE("CC"); 
        SET_ELEMENT("CC", CC);

        A_B8_BIT1(c3f, cdt, "cdt", 1, 4); 
        APPEND_EXPLAIN("cdt"); 
        SKIP(1); 

        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(2); 
        A_B16_BIT1(c3f, src_ref, "src_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B8_BIT1(c3f, class_option, "class_option", 1, 8); 
        SKIP(1); 

        left = LI - 6;    

        pre_left = left;
        while(left > 0)
        {
            B8_BIT(paramid, 1, 8);
            printf("paramid 0x%x\n",paramid);
    
            switch (paramid)
            {
                case 0xc1:
                { 
                    transport_selector(&left);
                    break;
                } 
                case 0xc0:
                { 
                    tpdu_size(&left);
                    break;
                } 
                case 0xf0:
                { 
                    prefer_maxi_tpdu_size(&left);
                    break;
                } 
                case 0xc4:
                { 
                    version_number(&left);
                    break;
                } 
                case 0xc5:
                { 
                    protection_param(&left);
                    break;
                } 
                case 0xc3:
                { 
                    checksum(&left);
                    break;
                } 
                case 0xc6:
                { 
                    additional_option_selection(&left);
                    break;
                } 
                case 0xc7:
                { 
                    alternative_proto_class(&left);
                    break;
                } 
                case 0x85:
                { 
                    acknowledgement_time(&left);
                    break;
                } 
                case 0x89:
                { 
                    throughput(&left);
                    break;
                } 
                case 0x86:
                { 
                    residual_rerror_rate(&left);
                    break;
                } 
                case 0x87:
                { 
                    priority(&left);
                    break;
                } 
                case 0x88:
                { 
                    transit_delay(&left);
                    break;
                } 
                case 0x8b:
                { 
                    reassignment_time(&left);
                    break;
                } 
                case 0xf2:
                { 
                    inactivity_timer(&left);
                    break;
                }
                default:
                {
                    default_param(&left);
                    break;
                }
            }
            if (pre_left == left)
            {
                break;
            }
            else
            {
                pre_left = left;
            }
        }


    
        SKIP(left);

        HEX(len - LI - 1); 
        A_BN_BIT1(len - LI - 1);
        SKIP(len - LI - 1);
    } 
    else if(type == 15) 
    {
        //1111 DT
        SET_MSG_TYPE("DT"); 
        SET_ELEMENT("DT", DT);

        A_B8_BIT1(c3f, roa, "roa", 1, 1); 
        SKIP(1);
 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B8_BIT1(c3f, Nr, "Nr", 1, 7); 
        APPEND_EXPLAIN("nr"); 
        A_B8_BIT1(c3f, Eot, "Eot", 8, 8); 
        SKIP(1); 
       
        left = LI - 4;

        pre_left = left;
        while(left > 0)
        {
            B8_BIT(paramid, 1, 8);
            if (paramid == 0xc3)
            { 
                checksum(&left);
            } 
    
            B8_BIT(paramid, 1, 8);
            if (paramid == 0x90)
            { 
                HEX(1); A_B8_BIT1(c3f, paramid, "paramid", 1, 8); SKIP(1); 
                B8_BIT(paramlen, 1, 8);
                HEX(1); A_B8_BIT1(c3f, paramlen, "paramlen", 1, 8); SKIP(1); 
                HEX(paramlen); A_B16_BIT1(c3f, paramvalue, "paramvalue", 1, 16); 
                SKIP(paramlen);
                left -= (paramlen + 2);
            }
            
            if (pre_left == left)
            {
                break;
            }
            else
            {
                pre_left = left;
            }
 
        }
 
        SKIP(left);

        HEX(len - LI - 1); 
        A_BN_BIT1(len - LI - 1);
        SKIP(len - LI - 1);
    } 
    else if(type == 6) 
    {
        //0110 AK
        SET_MSG_TYPE("AK"); 
        SET_ELEMENT("AK", AK);

        A_B8_BIT1(c3f, cdt, "cdt", 1, 4); 
        APPEND_EXPLAIN("cdt"); 
        SKIP(1);
 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2); 

        HEX(1); 
        A_B8_BIT1(c3f, YrTuNr, "YrTuNr", 1, 8); 
        APPEND_EXPLAIN("YrTuNr"); 
        SKIP(1);
 
        left = LI - 4;

        pre_left = left;
        while (left > 0)
        {
        B8_BIT(paramid, 1, 8);
        switch(paramid)
        {
            case 0xc3:
            { 
                checksum(&left);
                break;
            } 
            case 0x8a:
            { 
                subsequence_number(&left);
                break;
            }
            case 0x8c:
            { 
                flow_control_confirmation(&left);
                break;
            } 
            case 0x8f:
            { 
                selective_acknowledgement(&left);
                break;
            }
            default:
            { 
                default_param(&left);
                break;
            }
        }
        if (pre_left == left)
        {
            break;
        }
        else
        {
            pre_left = left;
        }
        } 

    } 
    else if(type == 8) 
    {
        //1000 DR
        SET_MSG_TYPE("DR"); 
        SET_ELEMENT("DR", DR);
        SKIP(1);
 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(2); 
        A_B16_BIT1(c3f, src_ref, "src_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B8_BIT1(c3f, reason, "reason", 1, 8); 
        APPEND_EXPLAIN("reason"); 
        SKIP(1); 
       
        left = LI - 6;

        pre_left = left;
        while(left > 0)
        {
        B8_BIT(paramid, 1, 8);
        switch(paramid)
        {
            case 0xe0:
            { 
                additional_information(&left);
                break;
            } 
            case 0xc3:
            { 
                checksum(&left);
                break;
            }
            default:
            { 
                default_param(&left);
                break;
            }
        } 
        if (pre_left == left)
        {
            break;
        }
        else
        {
            pre_left = left;
        }
        }
 
        SKIP(left);

        HEX(len - LI - 1); 
        A_BN_BIT1(len - LI - 1);
        SKIP(len - LI - 1);
    } 
    else if(type == 12) 
    {
        //1100 DC
        SET_MSG_TYPE("DC"); 
        SET_ELEMENT("DC", DC);
        SKIP(1);
 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(2); 
        A_B16_BIT1(c3f, src_ref, "src_ref", 1, 16); 
        SKIP(2);
        
        left = LI - 5;

        B8_BIT(paramid, 1, 8);
        if (paramid == 0xc3)
        { 
            checksum(&left);
        } 
    } 
    else if(type == 7) 
    {
        //0111 ER
        SET_MSG_TYPE("ER"); 
        SET_ELEMENT("ER", ER);
        SKIP(1); 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B16_BIT1(c3f, reject_cause, "reject_cause", 1, 8); 
        SKIP(1);
 
        left = LI - 4;

        B8_BIT(paramid, 1, 8);
        if (paramid == 0xc1)
        { 
            invalid_tpdu(&left);
        } 

        B8_BIT(paramid, 1, 8);
        if (paramid == 0xc3)
        { 
            checksum(&left);
        } 

    } 
    else if(type == 1) 
    {
        //0001 0000 ED 
        SET_MSG_TYPE("ED"); 
        SET_ELEMENT("ED", ED);
        SKIP(1);
 
        HEX(2); 
        A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B16_BIT1(c3f, EdTpduNr, "EdTpduNr", 1, 7); 
        A_B16_BIT1(c3f, Eot, "Eot", 8, 8); 
        SKIP(1); 
       
        left = LI - 4;
        
        B8_BIT(paramid, 1, 8);
        if (paramid == 0xc3)
        { 
            checksum(&left);
        } 
 
        SKIP(left);

        HEX(len - LI - 1); 
        A_BN_BIT1(len - LI - 1);
        SKIP(len - LI - 1);
    } 
    else if(type == 2) 
    {
        //0010 0000 EA
        SET_MSG_TYPE("EA"); 
        SET_ELEMENT("EA", EA);
        SKIP(1); 

        HEX(2);
		A_B16_BIT1(c3f, dst_ref, "dst_ref", 1, 16); 
        SKIP(2);
 
        HEX(1); 
        A_B16_BIT1(c3f, YrEdtuNr, "YrEdtuNr", 1, 8); 
        SKIP(1);
 
        left = LI - 4;

        B8_BIT(paramid, 1, 8);
        if (paramid == 0xc3)
        { 
            checksum(&left);
        } 
    }
    else
    {
        //0101 Unknown
        SET_MSG_TYPE("Unknown"); 
        SET_ELEMENT("Unknown", Unknown);
    } 
#if 0
    //T_selector
    //Parameter code: 1100 0001
    //Parameter length:
    //Parameter value:
    B8_BIT(paramid, 1, 8);
    if (paramid == 0xc1)
    { 
        HEX(1); A_B8_BIT1(c3f, paramid, "paramid", 1, 8); SKIP(1); 
        B8_BIT(paramlen, 1, 8);
        HEX(1); A_B8_BIT1(c3f, paramlen, "paramlen", 1, 8); SKIP(1); 
        A_B8_BIT2(c3f, fcs, "fcs", 1, 16, fcs_buf);
        HEX(paramlen); A_B16_BIT1(c3f, paramvalue = b8(); 
        SKIP(paramlen);
        left -= (paramlen + 2);
    }
 
#endif
 
    END_ELEMENT(); 
}

void secure() 
{
    BEGIN_ELEMENT("SaPDU", SaPDU);
    int length;
    uint8_t mti;
 
    HEX(1); 
    A_B8_BIT1(c3f, ety, "ety", 6, 8);
    B8_BIT(mti, 2, 5); 
    A_B8_BIT1(c3f, mti, "mti", 2, 5); 
    A_B8_BIT1(c3f, direction, "direction", 1, 1);
    SKIP(1);

    if (mti == 1)
    { 
        //AU1
        SET_MSG_TYPE("AU1"); 
        SET_ELEMENT("AU1", AU1);
        HEX(3); 
        A_B24_BIT1(c3f, ctcs, "ctcs", 1, 24); 
        SKIP(3); 
        HEX(1); 
        A_B8_BIT1(c3f, SAF, "SAF", 1, 8); 
        SKIP(1); 
        HEX(8); 
        A_B64_BIT1(c3f, RB, "RB", 1, 64); 
        SKIP(8);
    }
    else if(mti == 2)
    {
        //AU2 
        SET_MSG_TYPE("AU2"); 
        SET_ELEMENT("AU2", AU2);
        HEX(3); 
        A_B24_BIT1(c3f, ctcs, "ctcs", 1, 24); 
        SKIP(3); 
        HEX(1); 
        A_B8_BIT1(c3f, SAF, "SAF", 1, 8); 
        SKIP(1); 
        HEX(8); 
        A_B64_BIT1(c3f, RA, "RA", 1, 64); 
        SKIP(8);
        HEX(8); 
        A_B64_BIT1(c3f, mac, "mac", 1, 64);
        SKIP(8);
    }
    else if(mti == 3)
    { 
        //AU3 
        SET_MSG_TYPE("AU3"); 
        SET_ELEMENT("AU3", AU3);
#if 0
        HEX(3); 
        A_B24_BIT1(c3f, ctcs, "ctcs", 1, 24); 
        SKIP(3); 
        HEX(1); 
        A_B8_BIT1(c3f, SAF, "SAF", 1, 8); 
        SKIP(1); 
        HEX(8); 
        A_B64_BIT1(c3f, RB, "RB", 1, 64); 
        SKIP(8);
#endif
        HEX(8); 
        A_B64_BIT1(c3f, mac, "mac", 1, 64);
        SKIP(8);
    }
    else if(mti == 9)
    {
        //AR
        SET_MSG_TYPE("AR"); 
        SET_ELEMENT("AR", AR);
#if 0
        HEX(3); 
        A_B8_BIT1(c3f, ctcs, "ctcs", 9, 32); 
        SKIP(3); 
        HEX(1); 
        A_B8_BIT1(c3f, SAF, "SAF", 1, 8); 
        SKIP(1); 
        HEX(8); 
        A_B64_BIT1(c3f, RA, "RA", 1, 64); 
        SKIP(8);
#endif
        HEX(8); 
        A_B64_BIT1(c3f, mac, "mac", 1, 64);
        SKIP(8);
    }
    else if(mti == 5)
    {
        //DT
        SET_MSG_TYPE("DT"); 
        SET_ELEMENT("DT", DT);
        
        HEX(len - 9); 
        A_BN_BIT1(len - 9);
        SKIP(len - 9);

        HEX(8); 
        A_B64_BIT1(c3f, mac, "mac", 1, 64);
        SKIP(8);
    }
    else if(mti == 8)
    {
        //DI
        SET_MSG_TYPE("DI"); 
        SET_ELEMENT("DI", DI);
        HEX(1); 
        A_B8_BIT1(c3f, release_reason,"release_reason", 1, 8); 
        SKIP(1); 
        HEX(1); 
        A_B8_BIT1(c3f, surelease_reason, "surelease_reason", 1, 8); 
        SKIP(1);
    }
    else
    {
        //Unknown 
        SET_MSG_TYPE("Unknown");
        SET_ELEMENT("Unknown", Unknown);
    }
    END_ELEMENT(); 
}

#define PKT0()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, NID_LRBG, 24);  \
    RBE(c3f, D_LRBG, 15);  \
    RBE(c3f, Q_DIRLRBG, 2);  \
    RBE(c3f, Q_DLRBG, 2);  \
    RBE(c3f, L_DOUBTOVER, 15);  \
    RBE(c3f, L_DOUBTUNDER, 15);  \
    RBE(c3f, Q_LENGTH, 2);  \
    RBE(c3f, V_TRAIN, 7);  \
    RBE(c3f, Q_DIRTRAIN, 2);  \
    RBE(c3f, M_MODE, 4);  \
    RBE(c3f, M_LEVEL, 3);  \
    uint64_t M_LEVEL; \
    M_LEVEL = MYVAR(c3f)->f; \
 \
    if (M_LEVEL == 1)  \
    RBE(c3f, NID_STM, 8);  \
}

#define PKT1()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, NID_LRBG, 24);  \
    RBE(c3f, NID_PRVBG, 24);  \
    RBE(c3f, D_LRBG, 15);  \
    RBE(c3f, Q_DIRLRBG, 2);  \
    RBE(c3f, Q_DLRBG, 2);  \
    RBE(c3f, L_DOUBTOVER, 15);  \
    RBE(c3f, L_DOUBTUNDER, 15);  \
    RBE(c3f, Q_LENGTH, 2);  \
    RBE(c3f, V_TRAIN, 7);  \
    RBE(c3f, Q_DIRTRAIN, 2);  \
    RBE(c3f, M_MODE, 4);  \
    RBE(c3f, M_LEVEL, 3); \
    uint64_t M_LEVEL; \
    M_LEVEL = MYVAR(c3f)->f; \
  \
    if (M_LEVEL == 1)  \
    RBE(c3f, NID_STM, 8);  \
}

#define PKT3()  \
{     \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_VALIDNV, 15);  \
    RBE(c3f, N_ITER, 5); \
    uint64_t N_ITER; \
    N_ITER =  (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER; i++)  \
    {  \
        RBE(c3f, NID_C, 10);  \
    }  \
    RBE(c3f, V_NVSHUNT, 7);  \
    RBE(c3f, V_NVSTFF, 7);  \
    RBE(c3f, V_NVONSIGHT, 7);  \
    RBE(c3f, V_NVUNFIT, 7);  \
    RBE(c3f, V_NVREL, 7);  \
    RBE(c3f, D_NVROLL, 15);  \
    RBE(c3f, Q_NVSRBKTRG, 1);  \
    RBE(c3f, Q_NVEMRRLS, 1);  \
    RBE(c3f, V_NVALLOWOVTRP, 7);  \
    RBE(c3f, V_NVSUPOVTRP, 7);  \
    RBE(c3f, D_NVOVTRP, 15);  \
    RBE(c3f, T_NVOVTRP, 8);  \
    RBE(c3f, D_NVPOTRP, 15);  \
    RBE(c3f, M_NVCONTACT, 2);  \
    RBE(c3f, T_NVCONTACT, 8);  \
    RBE(c3f, M_NVDERUN, 1);  \
    RBE(c3f, D_NVSTFF, 15);  \
    RBE(c3f, Q_NVDRIVER_ADHES, 1);  \
}

#define PKT4()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, M_ERROR, 8);  \
}

#define PKT11()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, NID_OPERATIONAL, 32);  \
    RBE(c3f, NC_TRAIN, 15);  \
    RBE(c3f, L_TRAIN, 12);  \
    RBE(c3f, V_MAXTRAIN, 7);  \
    RBE(c3f, M_LOADINGGAUGE, 8);  \
    RBE(c3f, M_AXLELOAD, 7);  \
    RBE(c3f, M_AIRTIGHT, 2);  \
    RBE(c3f, N_ITER, 5);  \
    RBE(c3f, N_ITER1, 5); \
    uint64_t N_ITER1; \
    N_ITER1 =  (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER1; i++)  \
    {  \
        RBE(c3f, NID_STM, 8);  \
    }  \
}

#define PKT5()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_LINK, 15);  \
    RBE(c3f, Q_NEWCOUNTRY, 1);  \
    uint64_t Q_NEWCOUNTRY; \
    Q_NEWCOUNTRY = MYVAR(c3f)->f; \
 \
    if (Q_NEWCOUNTRY == 1)  \
    RBE(c3f, NID_C, 10);  \
    RBE(c3f, NID_BG, 14);  \
    RBE(c3f, Q_LINKORIENTATION, 1);  \
    RBE(c3f, Q_LINKREACTION, 2);  \
    RBE(c3f, Q_LOCACC, 6);  \
    RBE(c3f, N_ITER, 5); \
    uint64_t N_ITER; \
    N_ITER = (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER; i++)  \
    {  \
        RBE(c3f, D_LINK, 15);  \
        RBE(c3f, Q_NEWCOUNTRY, 1); \
        Q_NEWCOUNTRY = MYVAR(c3f)->f; \
        if (Q_NEWCOUNTRY == 1)  \
        RBE(c3f, NID_C, 10);  \
        RBE(c3f, NID_BG, 14);  \
        RBE(c3f, Q_LINKORIENTATION, 1);  \
        RBE(c3f, Q_LINKREACTION, 2);  \
        RBE(c3f, Q_LOCACC, 6);  \
    }  \
}

#define PKT15()   \
{    \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, V_LOA, 7);  \
    RBE(c3f, T_LOA, 10);  \
    RBE(c3f, N_ITER, 5);  \
    RBE(c3f, L_ENDSECTION, 15);  \
    RBE(c3f, Q_SECTIONTIMER, 1);  \
    RBE(c3f, Q_ENDTIMER, 1);  \
    RBE(c3f, Q_DANGERPOINT, 1);  \
    RBE(c3f, D_DP, 15);  \
    RBE(c3f, V_RELEASEDP, 7);  \
    RBE(c3f, Q_OVERLAP, 1);  \
    RBE(c3f, D_STARTOL, 15);  \
    RBE(c3f, T_OL, 10);  \
    RBE(c3f, D_OL, 15);  \
    RBE(c3f, V_RELEASEOL, 7);  \
}

#define PKT21()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_GRADIENT, 15);  \
    RBE(c3f, Q_GDIR, 1);  \
    RBE(c3f, G_A, 8);  \
    RBE(c3f, N_ITER, 5); \
    uint64_t N_ITER; \
    N_ITER =  (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER; i++)  \
    {  \
        RBE(c3f, D_GRADIENT, 15);  \
        RBE(c3f, Q_GDIR, 1);  \
        RBE(c3f, G_A, 8);  \
    }  \
}

#define PKT27()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_STATIC, 15);  \
    RBE(c3f, V_STATIC, 7);  \
    RBE(c3f, Q_FRONT, 1);  \
    RBE(c3f, N_ITER, 5);  \
    RBE(c3f, N_ITER1, 5);  \
    uint64_t N_ITER1; \
    N_ITER1 = (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER1; i++)  \
    {  \
        RBE(c3f, D_STATIC, 15);  \
        RBE(c3f, V_STATIC, 7);  \
        RBE(c3f, Q_FRONT, 1);  \
        RBE(c3f, N_ITER, 5);  \
    }  \
}

#define PKT41()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_LEVELTR, 15);  \
    RBE(c3f, M_LEVELTR, 3);  \
    uint64_t M_LEVELTR; \
    M_LEVELTR = MYVAR(c3f)->f; \
 \
    if (M_LEVELTR == 1)  \
    RBE(c3f, NID_STM, 8);  \
    RBE(c3f, L_ACKLEVELTR, 15);  \
    RBE(c3f, N_ITER, 5); \
    uint64_t  N_ITER; \
    N_ITER = (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER; i++)  \
    {  \
        RBE(c3f, M_LEVELTR, 3);  \
        M_LEVELTR = MYVAR(c3f)->f; \
        if (M_LEVELTR == 1)  \
        RBE(c3f, NID_STM, 8);  \
        RBE(c3f, L_ACKLEVELTR, 15);  \
    }  \
}

#define PKT42()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_RBC, 1);  \
    RBE(c3f, NID_C, 10);  \
    RBE(c3f, NID_RBC, 14);  \
    RBE(c3f, NID_RADIO, 64);  \
    RBE(c3f, Q_SLEEPSESSION, 1);  \
}

#define PKT57()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, T_MAR, 8);  \
    RBE(c3f, T_TIMEOUTRQST, 10);  \
    RBE(c3f, T_CYCRQST, 8);  \
}

#define PKT58()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, T_CYCLOC, 8);  \
    RBE(c3f, D_CYCLOC, 15);  \
    RBE(c3f, M_LOC, 3);  \
    RBE(c3f, N_ITER, 5);  \
    END_ELEMENT();  \
}

#define PKT65()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, NID_TSR, 8);  \
    RBE(c3f, D_TSR, 15);  \
    RBE(c3f, L_TSR, 15);  \
    RBE(c3f, Q_FRONT, 1);  \
    RBE(c3f, V_TSR, 7);  \
}

#define PKT66()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, NID_TSR, 8);  \
}

#define PKT68()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, Q_TRACKINIT, 1); \
    uint64_t Q_TRACKINIT; \
    Q_TRACKINIT =  MYVAR(c3f)->f; \
 \
    if (Q_TRACKINIT == 1)  \
    RBE(c3f, D_TRACKINIT, 15);  \
    if (Q_TRACKINIT == 0)  \
    RBE(c3f, D_TRACKCOND, 15);  \
    if (Q_TRACKINIT == 0)  \
    RBE(c3f, L_TRACKCOND, 15);  \
    if (Q_TRACKINIT == 0)  \
    RBE(c3f, M_TRACKCOND, 4);  \
    if (Q_TRACKINIT == 0)  \
    {  \
    RBE(c3f, N_ITER, 5); \
    uint64_t N_ITER; \
    N_ITER = (MYVAR(c3f))->f; \
    int i; \
    for(i= 0; i < N_ITER; i++)  \
    {  \
        RBE(c3f, D_TRACKCOND, 15);  \
        RBE(c3f, L_TRACKCOND, 15);  \
        RBE(c3f, M_TRACKCOND, 4);  \
    } \
    } \
}

#define PKT72()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, Q_TEXTCLASS, 2);  \
    RBE(c3f, Q_TEXTDISPLAY, 1);  \
    RBE(c3f, D_TEXTDISPLAY, 15);  \
    RBE(c3f, M_MODETEXTDISPLAY, 4);  \
    RBE(c3f, M_LEVELTEXTDISPLAY, 3);  \
    RBE(c3f, L_TEXTDISPLAY, 15);  \
    RBE(c3f, T_TEXTDISPLAY, 10);  \
    RBE(c3f, M_MODETEXTDISPLAY1, 4);  \
    RBE(c3f, M_LEVELTEXTDISPLAY1, 3);  \
    RBE(c3f, Q_TEXTCONFIRM, 2);  \
    RBE(c3f, L_TEXT, 8);  \
    RBE(c3f, X_TEXT, 8);  \
}

#define PKT80()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_MAMODE, 15);  \
    RBE(c3f, M_MAMODE, 2);  \
    RBE(c3f, V_MAMODE, 7);  \
    RBE(c3f, L_MAMODE, 15);  \
    RBE(c3f, L_ACKMAMODE, 15);  \
    RBE(c3f, N_ITER, 5); \
    uint64_t N_ITER; \
    N_ITER = (MYVAR(c3f))->f; \
 \
    int i; \
    for(i= 0; i < N_ITER; i++) \
    {  \
        RBE(c3f, D_MAMODE, 15);  \
        RBE(c3f, M_MAMODE, 2);  \
        RBE(c3f, V_MAMODE, 7);  \
        RBE(c3f, L_MAMODE, 15);  \
        RBE(c3f, L_ACKMAMODE, 15);  \
    }  \
}

#define PKT131()   \
{      \
    RBE(c3f, NID_PACKET, 8);  \
    RBE(c3f, Q_DIR, 2);  \
    RBE(c3f, L_PACKET, 13);  \
    RBE(c3f, Q_SCALE, 2);  \
    RBE(c3f, D_RBCTR, 15);  \
    RBE(c3f, NID_C, 10);  \
    RBE(c3f, NID_RBC, 14);  \
    RBE(c3f, NID_RADIO, 64);  \
    RBE(c3f, Q_SLEEPSESSION, 1);  \
}

void msg129()  
{     
    char msg_name[64];
    sprintf(msg_name, "M129 Validated Train Data");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M129", M129); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10);  
    RBE(c3f, T_TRAIN, 32);  
    RBE(c3f, NID_ENGINE, 24); 
    
    int b;

    PBE(b, 8); 
    if (b == 0) {  
        PKT0(); 
    }  
    else { 
        PKT1(); 
    } 

    PBE(b, 8); 
    if (b == 11) {  
        PKT11(); 
    }  
    END_ELEMENT(); 
}

void msg130()
{     
    char msg_name[64];
    sprintf(msg_name, "M130 Request for Shunting");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M130", M130); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 

    int b;

    PBE(b, 8); 
    if (b == 0) { 
        PKT0(); 
    }  
    else {  
        PKT1(); 
    } 
    END_ELEMENT(); 
}

void msg132()  
{      
    char msg_name[64];
    sprintf(msg_name, "M132 MA Request");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M132", M132); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    RBE(c3f, Q_TRACKDEL, 1); 

    int b;
    PBE(b, 8);
    if (b == 0) { 
        PKT0();
    } 
    else { 
        PKT1();
    }
    END_ELEMENT(); 
}

void msg136()  
{    
    char msg_name[64];
    sprintf(msg_name, "M136 Train Position Report");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M136", M136); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 

    int b;
    PBE(b, 8);
    if (b == 0) { 
        PKT0();
    } 
    else { 
        PKT1();
    }

    PBE(b, 8);
    if (b == 4) { 
        PKT4();
    } 
    END_ELEMENT(); 
}

void msg146()  
{     
    char msg_name[64];
    sprintf(msg_name, "M146 Acknowledgement");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M146", M146); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    RBE(c3f, T_TRAIN1, 32); 
    END_ELEMENT(); 
}

void msg147()  
{     
    char msg_name[64];
    sprintf(msg_name, "M147 Acknowledgement of Emergency Stop");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M147", M147); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    RBE(c3f, NID_EM, 4); 
    RBE(c3f, Q_EMERGENCYSTOP, 2); 

    int b;
    PBE(b, 8);
    if (b == 0) { 
        PKT0();
    } 
    else { 
        PKT1();
    }
    END_ELEMENT(); 
}

void msg150()  
{    
    char msg_name[64];
    sprintf(msg_name, "M150 End of Mission");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M150", M150); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 

    int b;
    PBE(b, 8);
    if (b == 0) { 
        PKT0();
    } 
    else { 
        PKT1();
    }
    END_ELEMENT(); 
}

void msg154()  
{     
    char msg_name[64];
    sprintf(msg_name, "M154 No compatible version");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M154", M154); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    END_ELEMENT(); 
}

void msg155()  
{     
    char msg_name[64];
    sprintf(msg_name, "M155 Initiation of a communication session");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M155", M155); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    END_ELEMENT(); 
}

void msg156()  
{    
    char msg_name[64];
    sprintf(msg_name, "M156 Termination of a communication session");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M156", M156); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    END_ELEMENT(); 
}

void msg157()  
{     
    char msg_name[64];
    sprintf(msg_name, "M157 SoM Position Report");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M157", M157); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    RBE(c3f, Q_STATUS, 2); 

    int b;
    PBE(b, 8);
    if (b == 0) { 
        PKT0();
    } 
    else { 
        PKT1();
    }

    PBE(b, 8);
    if (b == 4) { 
        PKT4();
    } 
    END_ELEMENT(); 
}

void msg159()  
{     
    char msg_name[64];
    sprintf(msg_name, "M159 Session established");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M159", M159); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, NID_ENGINE, 24); 
    END_ELEMENT(); 
}

void msg3()  
{    
    char msg_name[64];
    sprintf(msg_name, "M3 Movement Authority");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M3", M3); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 

    int b;
    PBE(b, 8);
    if (b == 15) { 
        PKT15();
    } 

    PBE(b, 8);
    if (b == 5) { 
        PKT5();
    } 

    PBE(b, 8);
    if (b == 21) { 
        PKT21();
    } 

    PBE(b, 8);
    if (b == 3) { 
        PKT3();
    } 

    PBE(b, 8);
    if (b == 41) { 
        PKT41();
    } 

    PBE(b, 8);
    if (b == 65) { 
        PKT65();
    } 

    PBE(b, 8);
    if (b == 68) { 
        PKT68();
    } 

    PBE(b, 8);
    if (b == 80) { 
        PKT80();
    } 
    END_ELEMENT(); 
}

void msg6()  
{     
    char msg_name[64];
    sprintf(msg_name, "M6 Recognition of exit from TRIP mode");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M6", M6); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    END_ELEMENT(); 
}

void msg8()  
{    
    char msg_name[64];
    sprintf(msg_name, "M8 Acknowledgement of Train Data");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M8", M8); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, T_TRAIN1, 32); 
    END_ELEMENT(); 
}

void msg15()  
{    
    char msg_name[64];
    sprintf(msg_name, "M15 Conditional Emergency Stop");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M15", M15); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, NID_EM, 4); 
    RBE(c3f, Q_SCALE, 2); 
    RBE(c3f, Q_DIR, 2); 
    RBE(c3f, D_EMERGENCYSTOP, 15); 
    END_ELEMENT(); 
}

void msg16()  
{    
    char msg_name[64];
    sprintf(msg_name, "M16 Unconditional Emergency Stop");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M16", M16); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, NID_EM, 4); 
    END_ELEMENT(); 
}

void msg18()  
{    
    char msg_name[64];
    sprintf(msg_name, "M18 Revocation of Emergency Stop");
    SET_MSG_TYPE(msg_name); 

    BEGIN_ELEMENT("M18", M18); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, NID_EM, 4); 
    END_ELEMENT(); 
}

void msg24()  
{    
    char msg_name[64];
    sprintf(msg_name, "M24 General message");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M24", M24); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 

    int b;
    PBE(b, 8);
    if (b == 3) { 
        PKT3();
    } 

    PBE(b, 8);
    if (b == 41) { 
        PKT41();
    } 

    PBE(b, 8);
    if (b == 42) { 
        PKT42();
    } 

    PBE(b, 8);
    if (b == 57) { 
        PKT57();
    } 

    PBE(b, 8);
    if (b == 58) { 
        PKT58();
    } 

    PBE(b, 8);
    if (b == 65) { 
        PKT65();
    } 

    PBE(b, 8);
    if (b == 66) { 
        PKT66();
    } 

    PBE(b, 8);
    if (b == 72) { 
        PKT72();
    } 

    PBE(b, 8);
    if (b == 131) { 
        PKT131();
    } 
    END_ELEMENT(); 
}

void msg27()  
{    
    char msg_name[64];
    sprintf(msg_name, "M27 SH Refused");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M27", M27); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, T_TRAIN1, 32); 
    END_ELEMENT(); 
}

void msg28()  
{    
    char msg_name[64];
    sprintf(msg_name, "M28 SH Authorised");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M28", M28); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, T_TRAIN1, 32); 
    END_ELEMENT(); 
}

void msg32()  
{     
    char msg_name[64];
    sprintf(msg_name, "M32 Configuration Determination");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M32", M32); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, M_VERSION, 7); 
    END_ELEMENT(); 
}

void msg33()  
{    
    char msg_name[64];
    sprintf(msg_name, "M33 MA with Shifted Location Reference");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M33", M33); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, Q_SCALE, 2); 
    RBE(c3f, D_REF, 16); 

    int b;
    PBE(b, 8);
    if (b == 15) { 
        PKT15();
    } 

    PBE(b, 8);
    if (b == 5) { 
        PKT5();
    } 

    PBE(b, 8);
    if (b == 21) { 
        PKT21();
    } 

    PBE(b, 8);
    if (b == 27) { 
        PKT27();
    } 

    PBE(b, 8);
    if (b == 41) { 
        PKT41();
    } 

    PBE(b, 8);
    if (b == 65) { 
        PKT65();
    } 

    PBE(b, 8);
    if (b == 68) { 
        PKT68();
    } 

    PBE(b, 8);
    if (b == 80) { 
        PKT80();
    } 
    END_ELEMENT(); 
}

void msg39()  
{    
    char msg_name[64];
    sprintf(msg_name, "M39 Acknowledgement of termination of a communication session");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M39", M39); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    END_ELEMENT(); 
}

void msg41()  
{      
    char msg_name[64];
    sprintf(msg_name, "M41 Train Accepted");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M41", M41); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    END_ELEMENT(); 
}

void msg45()  
{      
    char msg_name[64];
    sprintf(msg_name, "M45 Assignment of coordinate system");
    SET_MSG_TYPE(msg_name);

    BEGIN_ELEMENT("M45", M45); 
    RBE(c3f, NID_MESSAGE, 8); 
    RBE(c3f, L_MESSAGE, 10); 
    RBE(c3f, T_TRAIN, 32); 
    RBE(c3f, M_ACK, 1); 
    RBE(c3f, NID_LRBG, 24); 
    RBE(c3f, Q_ORIENTATION, 1); 
    END_ELEMENT(); 
}

void msgUnknown()  
{      
    char msg_name[64];
    sprintf(msg_name, "Unknown");
    SET_MSG_TYPE(msg_name);
}

#endif
