#ifndef __GB_APP_COMMON_H__
#define __GB_APP_COMMON_H__

#include "gb_fcs_check.h"
#include "nbe_common.h"

char _hex_buf[1024];
char _hex_desc_buf[4096];
char *_hex = NULL;
char *_hex_desc = NULL;

#define sndcp()\
{   \
    BEGIN_ELEMENT("sndcp", sndcp); \
\
	uint8_t snpdu_type;\
    B8_HEX(); \
    A_B8_BIT1(gbf, NSAPI, "NSAPI", 1, 4); \
    A_B8_BIT1(gbf, M, "More bit", 5, 5); \
    B8_BIT(snpdu_type, 6, 6); \
    char sn_pdu[64] = {0}; \
	if( snpdu_type == 0) \
	{ \
		sprintf(sn_pdu,  "SN-DATA PDU"); \
	} \
	else \
	{ \
		sprintf(sn_pdu,  "SN-UNITDATA PDU"); \
	} \
    A_B8_BIT2(gbf, T, "SN-PDU type", 6, 6, sn_pdu); \
    A_B8_BIT1(gbf, F, "First segment indicator", 7, 7); \
    A_B8_BIT1(gbf, X, "Spare", 8, 8); \
    SKIP(1);  \
    \
    B8_HEX(); \
    A_B8_BIT1(gbf, PCOMP, "Protocol compress coding", 1, 4); \
    A_B8_BIT1(gbf, DCOMP, "Data compression coding", 5, 8); \
    SKIP(1);  \
    \
    if( snpdu_type == 0) \
    { \
		SET_MSG_TYPE("SN-DATA PDU"); \
		SET_ELEMENT("SN-DATA PDU", SN_DATA_PDU); \
        B8_HEX(); \
        A_B8_BIT1(gbf, NPDU_NUM, "N-PDU number", 1, 8); \
        SKIP(1); \
\
        if(len - 3 > 0)\
        {\
            A_BN_BIT1(len - 3);\
        }\
    }\
    else\
    {\
		SET_MSG_TYPE("SN-UNITDATA PDU"); \
		SET_ELEMENT("SN-UNITDATA PDU", SN_UNITDATA_PDU); \
        B8_HEX(); \
        A_B8_BIT1(gbf, NPDU_NUM, "N-PDU number", 1, 4); \
        A_B8_BIT1(gbf, SEG_NUM, "Segment number", 5, 8); \
        SKIP(1);\
\
        B8_HEX();\
        A_B8_BIT1(gbf, NPDU_NUM, "N-PDU number continued", 1, 8); \
        SKIP(1); \
\
        if(len - 4 > 0)\
        {\
            A_BN_BIT1(len - 4);\
        }\
    }\
\
    END_ELEMENT();\
}

#define ip()\
{\
    BEGIN_ELEMENT("IP Layer", ip_layer); \
\
	int i;\
	uint8_t IHL;\
	uint32_t ip; \
	char *p; \
\
    B8_HEX();\
    A_B8_BIT1(gbf, Version, "Version", 5, 8);\
	B8_BIT(IHL, 1, 4);	\
    A_B8_BIT1(gbf, IHL, "IHL", 1, 4); \
    SKIP(1);\
\
    B8_HEX();\
    A_B8_BIT1(gbf, Type_Service, "Type Service", 1, 8); \
    SKIP(1);\
\
\
    HEX(2); \
    A_B16_BIT1(gbf, Total_Length, "Total Length", 1, 16); \
    SKIP(2);\
\
    HEX(2); \
    A_B16_BIT1(gbf, Identification, "Identification", 1, 16); \
    SKIP(2);\
\
    HEX(2); \
    A_B16_BIT1(gbf, Flags, "Reserved", 16, 16); \
    A_B16_BIT1(gbf, Flags, "DF", 15, 15); \
    A_B16_BIT1(gbf, Flags, "MF", 14, 14); \
    A_B16_BIT1(gbf, Fragment_Offset, "Fragment Offset", 1, 13); \
    SKIP(2);\
\
    B8_HEX();\
    A_B8_BIT1(gbf, Time_Live, "Time to Live", 1, 8); \
    SKIP(1);\
    \
    B8_HEX();\
    A_B8_BIT1(gbf, Protocol, "Protocol", 1, 8); \
    SKIP(1);\
\
    HEX(2); \
    A_B16_BIT1(gbf, Checksum, "Header Checksum", 1, 16); \
    SKIP(2);\
\
    HEX(4); \
    char userip[64] = {0}; \
    B32_BIT(ip, 1, 32); \
	p = &ip; \
	sprintf(userip, "%d.%d.%d.%d", p[3] & 0xff, p[2] & 0xff, p[1] & 0xff, p[0] & 0xff);	\
    A_B32_BIT2(gbf, userip, "userip", 1, 32, userip); \
    SKIP(4);\
\
    HEX(4); \
    char destip[64] = {0}; \
    B32_BIT(ip, 1, 32); \
	p = &ip; \
	sprintf(destip, "%d.%d.%d.%d", p[3] & 0xff, p[2] & 0xff, p[1] & 0xff, p[0] & 0xff);	\
    A_B32_BIT2(gbf, destip, "destip", 1, 32, destip); \
    SKIP(4);\
\
	if ((IHL * 4 - 20) > 0)\
	{\
    	HEX(4); \
    	A_B32_BIT1(gbf, Options, "Options", 9, 32); \
    	A_B32_BIT1(gbf, Padding, "Padding", 1, 8); \
    	SKIP(4);\
	}\
\
    if (len - (IHL * 4) > 0)\
    {\
        HEX(len - (IHL * 4)); \
        A_BN_BIT1(len - (IHL * 4));\
        SKIP(len - (IHL * 4));\
    }\
    END_ELEMENT(); \
}

#define transport(protocol)\
{\
    char msg_name[64];\
\
    BEGIN_ELEMENT("TRANSPORT Layer", transport_layer);\
\
    if (protocol == 1)\
    {\
        sprintf(msg_name, "ICMP");\
        SET_MSG_TYPE(msg_name);\
    }\
    else if (protocol == 2)\
    {\
        sprintf(msg_name, "IGMP");\
        SET_MSG_TYPE(msg_name);\
    }\
    else if (protocol == 6)\
    {\
        sprintf(msg_name, "TCP");\
        SET_MSG_TYPE(msg_name);\
        uint8_t data_offset;\
        \
        HEX(2); \
        A_B16_BIT1(gbf, srcport, "srcport", 1, 16);\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT1(gbf, dstport, "dstport", 1, 16);\
        SKIP(2);\
        HEX(4); \
        A_B32_BIT2(gbf, SequenceNum, "SequenceNum", 1, 32, "Sequence Number");\
        SKIP(4);\
        HEX(4); \
        A_B32_BIT2(gbf, AcknowledgmentNum, "AcknowledgmentNum", 1, 32, "Acknowledgment Number");\
        SKIP(4);\
        B8_BIT(data_offset, 1, 4); \
        HEX(2); \
        A_B16_BIT2(gbf, DataOffset, "DataOffset", 13, 16, "Data Offset");\
        A_B16_BIT2(gbf, Reserved, "Reserved", 7, 12, "Reserved");\
        A_B16_BIT2(gbf, URG, "URG", 6, 6, "URG");\
        A_B16_BIT2(gbf, ACK, "ACK", 5, 5, "ACK");\
        A_B16_BIT2(gbf, PSH, "PSH", 4, 4, "PSH");\
        A_B16_BIT2(gbf, PST, "PST", 3, 3, "PST");\
        A_B16_BIT2(gbf, SYN, "SYN", 2, 2, "SYN");\
        A_B16_BIT2(gbf, FIN, "FIN", 1, 1, "FIN");\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT2(gbf, Window, "Window", 1, 16, "Window");\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT2(gbf, Checksum, "Checksum", 1, 16, "Checksum");\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT2(gbf, UrgentPointer, "UrgentPointer", 1, 16, "Urgent Pointer");\
        SKIP(2);\
		if ((data_offset * 4 - 20) > 0)\
		{\
        	HEX(4); \
        	A_B32_BIT2(gbf, Options, "Options", 1, 32, "Options");\
        	SKIP(4);\
		}\
\
        if (len - data_offset * 4 > 0)\
        {\
            HEX(len - data_offset * 4); \
            A_BN_BIT1(len - data_offset * 4);\
            SKIP(len - data_offset * 4);\
        }\
    }\
    else if (protocol == 8)\
    {\
        sprintf(msg_name, "EGP");\
        SET_MSG_TYPE(msg_name);\
    }\
    else if (protocol == 17)\
    {\
        sprintf(msg_name, "UDP");\
        SET_MSG_TYPE(msg_name);\
        HEX(2); \
        A_B16_BIT1(gbf, SrcPort, "srcport", 1, 16);\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT1(gbf, DstPort, "dstport", 1, 16);\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT2(gbf, Length, "Length", 1, 16, "Length");\
        SKIP(2);\
        HEX(2); \
        A_B16_BIT2(gbf, Checksum, "Checksum", 1, 16, "Checksum");\
        SKIP(2);\
\
        if (len - 8 > 0)\
        {\
            HEX(len - 8); \
            A_BN_BIT1(len - 8);\
            SKIP(len - 8);\
        }\
    }\
    /*ICMP 1*/\
    /*IGMP 2*/\
    /*TCP 6*/\
    /*EGP 8*/\
    /*UDP 17*/\
    END_ELEMENT(); \
}

//TAX输出的列车运行数据的数据帧
#define train_run_data()  \
{    \
    uint8_t checksum = 0;\
    int num;\
    checksum = CHECK_SUM(31);\
    RBE_BYTE(gbf, "本板地址", 1, "");\
    RBE_BYTE(gbf, "特征码", 1, "");\
    RBE_BYTE(gbf, "标志", 1, "");\
    RBE_BYTE(gbf, "版本号", 1, "");\
    RBE_BYTE(gbf, "保留", 1, "");\
    RBE_BYTE(gbf, "车站号", 1, "");\
    char trainnum[64] = {0}; \
    char ch; \
    for (i = 0, j = 0; i < 4; i++) \
    { \
        PBE(ch, 8); \
        if(ch >= 'A' && ch <= 'Z')\
        { \
            trainnum[j] = ch; \
            j++; \
        } \
        SKIP(1); \
    } \
    BACK(i); \
    RBE_BYTE(gbf, "车次种类标示符", 4, trainnum);\
    RBE_BYTE(gbf, "司机号", 1, "");\
    RBE_BYTE(gbf, "副司机号", 1, "");\
    RBE_BYTE(gbf, "保留", 2, "");\
    RBE_BYTE(gbf, "机车型号", 1, "");\
    RBE_BYTE(gbf, "实际交路号", 1, "");\
    RBE_BYTE(gbf, "保留", 11, "");\
    RBE_BYTE(gbf, "本_/_补_,_客_/_货", 1, "");\
    PBE(num, 24); \
    num = ntohl(num) >> 8; \
    memset(trainnum, 0x00, sizeof(trainnum)); \
	sprintf(trainnum , "%d", num); \
    RBE_BYTE(gbf, "车次数字部分", 3, trainnum);\
    char check[64] = {0}; \
    sprintf(check, "%x", checksum);\
    RBE_BYTE(gbf, "检查和_1", 1, "");\
    checksum = CHECK_SUM(39);\
    RBE_BYTE(gbf, "本板地址", 1, "");\
    RBE_BYTE(gbf, "特征码", 1, "");\
    RBE_BYTE(gbf, "检测单元代号", 1, "");\
    int year, month, day;\
    int hour, minute, second;\
    char cur[64] = {0};\
    PBE(num, 32);\
    year = (num &  0xFC000000) >> 26;\
    month = (num & 0x03C00000) >> 22;\
    day = (num &   0x003E0000) >> 17;\
    hour = (num &  0x0001F000) >> 12;\
    minute = (num &0x00000FC0) >> 6;\
    second = (num &0x0000003F) >> 0;\
    sprintf(cur, "20%02d/%02d/%02d %02d:%02d:%02d", year, month, day, hour, minute, second);\
    RBE_BYTE(gbf, "年，月，日，时，分，秒", 4, cur);\
    RBE_BYTE(gbf, "速度", 3, "");\
    RBE_BYTE(gbf, "机车信号", 1, "");\
    RBE_BYTE(gbf, "机车工况", 1, "");\
    RBE_BYTE(gbf, "信号机编号", 2, "");\
    RBE_BYTE(gbf, "信号机种类", 1, "");\
    int32_t INFO_KM;\
    PBE(num, 24);\
    if((num & 0x800000) == 0) \
    { \
        INFO_KM = 1; \
    } \
    else \
    { \
        INFO_KM = -1; \
    } \
    INFO_KM = INFO_KM * (num & 0x3FFFFF);\
    RBE_BYTE(gbf, "公里标", 3, "");\
    RBE_BYTE(gbf, "总重", 2, "");\
    RBE_BYTE(gbf, "计长", 2, "");\
    RBE_BYTE(gbf, "辆数", 1, "");\
    RBE_BYTE(gbf, "本_/_补_,_客_/_货", 1, "");\
    RBE_BYTE(gbf, "车次", 2, "");\
    RBE_BYTE(gbf, "区段号_(_交路号_)", 1, "");\
    RBE_BYTE(gbf, "车站号", 1, "");\
    RBE_BYTE(gbf, "司机号", 2, "");\
    RBE_BYTE(gbf, "副司机号", 2, "");\
    RBE_BYTE(gbf, "机车号", 2, "");\
    RBE_BYTE(gbf, "机车型号", 1, "");\
    RBE_BYTE(gbf, "列车管压力", 2, ""); \
    RBE_BYTE(gbf, "装置状态", 1, "");\
    RBE_BYTE(gbf, "保留", 1, "");\
    sprintf(check, "%x", checksum);\
    RBE_BYTE(gbf, "检查和_2", 1, "");\
}

#define longitude() \
{ \
    char Lng[64] = {0};\
    int degree = 0;\
    int minute = 0;\
    int num; \
    for(i = 0; i < 2; i++)\
    {\
        PBE(num, 8);\
        degree = degree * 10 + ((num & 0xF0) >> 4);\
        degree = degree * 10 + (num & 0x0F);\
        SKIP(1);\
    }\
    for(i = 0; i < 3; i++)\
    {\
        PBE(num, 8);\
        minute = minute * 10 + ((num & 0xF0) >> 4);\
        minute = minute * 10 + (num & 0x0F);\
        SKIP(1);\
    }\
    sprintf(Lng, "%d.%d_°", degree, minute);\
    BACK(5); \
    RBE_BYTE(gbf, "经度", 5, Lng);\
}

#define latitude() \
{ \
    char Lat[64] = {0};\
    int degree = 0;\
    int minute = 0;\
    int num; \
    for(i = 0; i < 1; i++)\
    {\
        PBE(num, 8);\
        degree = degree * 10 + ((num & 0xF0) >> 4);\
        degree = degree * 10 + (num & 0x0F);\
        SKIP(1);\
    }\
    for(i = 0; i < 3; i++)\
    {\
        PBE(num, 8);\
        minute = minute * 10 + ((num & 0xF0) >> 4);\
        minute = minute * 10 + (num & 0x0F);\
        SKIP(1);\
    }\
    sprintf(Lat, "%d.%d_°", degree, minute);\
    BACK(4); \
    RBE_BYTE(gbf, "纬度", 4, Lat);\
}

//确认和调车请求信息数据帧
void tbt3231_t7()  
{  
    int i;
    int j;
    char msg_name[64];
    sprintf(msg_name, "确认和调车请求信息数据帧");
    SET_MSG_TYPE(msg_name); 

    RBE_BYTE(gbf, "信息名称", 1, "");
    RBE_BYTE(gbf, "功能码", 1, "");
    int num;
    int year, month, day;
    int hour, minute, second;
    char date[64] = {0};
    char time[64] = {0};
    PBE(num, 24);
    year = num & 0xFF0000;
    month = num & 0x00FF00;
    day = num & 0x0000FF;
    sprintf(date, "20%d%d/%d%d/%d%d", year >> 4,year & 0x0F,month >> 4,month & 0x0F,day >> 4, day & 0x0F);
    RBE_BYTE(gbf, "年，月，日", 3, date);
    PBE(num, 24);
    hour = num & 0xFF0000;
    minute = num & 0x00FF00;
    second = num & 0x0000FF;
    sprintf(time, "%d%d:%d%d:%d%d", hour >> 4, hour & 0x0F,minute >> 4, minute & 0x0F, second >> 4,second & 0x0F);
    RBE_BYTE(gbf, "时，分，秒", 3, time);
    char trainnum[64] = {0};
    char ch;
    for (i = 0, j = 0; i < 4; i++)
    {
        PBE(ch, 8);
        if(isupper(ch))
        {
            trainnum[j] = ch;
            j++; 
        }
        SKIP(1);
    }
    PBE(num, 24);
    num = ntohl(num) >> 8;
	sprintf(trainnum + j, "%d", num);
    BACK(4);
    RBE_BYTE(gbf, "车次号", 7, trainnum);
    char trainno[64] = {0};
    for (i = 0; i < 8; i++)
    {
        PBE(trainno[i], 8);
        SKIP(1);
    }
    SKIP(-8);
    RBE_BYTE(gbf, "机车号", 8, trainno);
    RBE_BYTE(gbf, "发令处所编号", 1, "");
    char dispatch_cmd[64] = {0};
    for (i = 0; i < 6; i++)
    {
        PBE(dispatch_cmd[i], 8);
        SKIP(1);
    }
    SKIP(-6);
    RBE_BYTE(gbf, "调度命令信息编码", 6, dispatch_cmd);
    RBE_BYTE(gbf, "公里标", 3, "");
    longitude();
    latitude();
    RBE_BYTE(gbf, "发令处所编号", 1, "");
    RBE_BYTE(gbf, "预留", 4, "");
    RBE_BYTE(gbf, "包号", 1, "");
}

//调度命令信息数据格式
void tbt3231_t5()  
{  
    int i;
    int j;
	uint8_t cmdstate;
    char msg_name[64];
    sprintf(msg_name, "调度命令信息数据格式");
    SET_MSG_TYPE(msg_name); 

    struct code2dict gnm_dict[] = 
    {  
        {0x01, "调度命令"}, 
        {0x02, "路票"}, 
        {0x03, "绿色许可证"}, 
        {0x04, "红色许可证"}, 
        {0x05, "出站跟踪调车通知书"}, 
        {0x07, "列车进路预告信息"}, 
        {0x11, "调车作业通知单"}, 
        {0x12, "调车请求确认"}, 
        {0x20, "出入库检测"}, 
    };
    B8_HEX();
    A_B8_BIT3(gbf, gnm, "功能码", 1, 8, gnm_dict);
    SKIP(1);
   
    int num;
    int year, month, day;
    int hour, minute, second;
    char date[64] = {0};
    char time[64] = {0};
    PBE(num, 24);
    year = num & 0xFF0000;
    month = num & 0x00FF00;
    day = num & 0x0000FF;
    sprintf(date, "20%d%d/%d%d/%d%d", year >> 4,year & 0x0F,month >> 4,month & 0x0F,day >> 4, day & 0x0F);
    RBE_BYTE(gbf, "年，月，日", 3, date);
    PBE(num, 24);
    hour = num & 0xFF0000;
    minute = num & 0x00FF00;
    second = num & 0x0000FF;
    sprintf(time, "%d%d:%d%d:%d%d", hour >> 4, hour & 0x0F,minute >> 4, minute & 0x0F, second >> 4,second & 0x0F);
    RBE_BYTE(gbf, "时，分，秒", 3, time);
    PBE(num, 24);
    hour = num & 0xFF0000;
    minute = num & 0x00FF00;
    second = num & 0x0000FF;
    sprintf(time, "%d%d:%d%d:%d%d", hour >> 4, hour & 0x0F,minute >> 4, minute & 0x0F, second >> 4,second & 0x0F);
    RBE_BYTE(gbf, "时，分，秒", 3, time);

    char trainnum[64] = {0};
    char ch;
    for (i = 0, j = 0; i < 4; i++)
    {
        PBE(ch, 8);
        if(isupper(ch))
        {
            trainnum[j] = ch;
            j++;
        }
        SKIP(1);
    }
    PBE(num, 24);
    num = ntohl(num) >> 8;
	sprintf(trainnum + j, "%d", num);
    BACK(4);
    RBE_BYTE(gbf, "车次号", 7, trainnum);
    char trainno[64] = {0};
    for (i = 0; i < 8; i++)
    {
        PBE(trainno[i], 8);
        SKIP(1);
    }
    SKIP(-8);
    RBE_BYTE(gbf, "机车号", 8, trainno);
    RBE_BYTE(gbf, "发令处所编号", 1, "");
    char dispatch_cmd[64] = {0};
    for (i = 0; i < 6; i++)
    {
        PBE(dispatch_cmd[i], 8);
        SKIP(1);
    }
    SKIP(-6);
    RBE_BYTE(gbf, "调度命令信息编码", 6, dispatch_cmd);
    RBE_BYTE(gbf, "发令人姓名", 8, "");

	char desc[256] = {0};
    PBE(cmdstate, 8);
	struct code2dict cmdstate_dict[] = 
	{
		{0x01, "补机"},
		{0x02, "非新接收的命令"},
		{0x04, "预留"},
		{0x08, "预留"},
		{0x16, "预留"},
		{0x32, "打印"},
		{0x64, "预留"},
		{0x128, "签收"},
	};
	len = sizeof(cmdstate_dict) / sizeof(cmdstate_dict[0]); 
	for (i = 0; i < len; i++) 
	{ 
		if (cmdstate_dict[i].code == cmdstate ) 
		{ 
			memset(desc, 0x00, sizeof(desc));
			sprintf(desc, "%s", cmdstate_dict[i].str);
			break; 
		} 
	}
	if(i < len)
	{
        RBE_BYTE(gbf, "命令状态", 1, desc);
    }
    else
    {
        RBE_BYTE(gbf, "命令状态", 1, "");
    }

    RBE_BYTE(gbf, "发令处所编号", 1, "");
    RBE_BYTE(gbf, "预留", 4, "");
    RBE_BYTE(gbf, "总包数", 1, "");
    RBE_BYTE(gbf, "本包数", 1, "");
    uint32_t pos;
    POS(pos);
    RBE_BYTE(gbf, "调度命令信息正文", len - pos - 4, "");
}

//CTC/TDCS向CIR查询当前车次号信息的数据帧
void tbt3325_t18()  
{    
    int i;
    char msg_name[64];
    sprintf(msg_name, "CTC/TDCS_向_CIR_查询当前车次号信息的数据帧");
    SET_MSG_TYPE(msg_name); 

	uint8_t trainno_len;
    PBE(trainno_len, 8);
    RBE_BYTE(gbf, "机车号长度", 1, "");
    char trainno[64] = {0};
    for (i = 0; i < trainno_len; i++)
    {
        PBE(trainno[i], 8);
        SKIP(1);
    }
	BACK(trainno_len);
    RBE_BYTE(gbf, "机车号", 10, trainno);
}

//CIR向GROS发送当前GRIS IP地址更新响应的数据帧
void tbt3325_t17()  
{    
    int i;
    char msg_name[64];
    sprintf(msg_name, "CIR_向_GROS_发送当前_GRIS IP_地址更新响应的数据帧");
    SET_MSG_TYPE(msg_name); 

	uint8_t trainno_len;
    PBE(trainno_len, 8);
    RBE_BYTE(gbf, "机车号长度", 1, "");
    char trainno[64] = {0};
    for (i = 0; i < trainno_len; i++)
    {
        PBE(trainno[i], 8);
        SKIP(1);
    }
	BACK(trainno_len);
    RBE_BYTE(gbf, "机车号", 10, trainno);
    RBE_BYTE(gbf, "当前_GRIS IP_地址", 4, "");
}

//GROS向CIR发送当前GRIS IP地址的数据帧
void tbt3325_t16()  
{    
    int i;
    char msg_name[64];
    sprintf(msg_name, "GROS_向_CIR_发送当前_GRIS IP_地址的数据帧");
    SET_MSG_TYPE(msg_name); 

	uint8_t trainno_len;
    PBE(trainno_len, 8);
    RBE_BYTE(gbf, "机车号长度", 1, "");
    char trainno[64] = {0};
    for (i = 0; i < trainno_len; i++)
    {
        PBE(trainno[i], 8);
        SKIP(1);
    }
	BACK(trainno_len);
    RBE_BYTE(gbf, "机车号", 10, trainno);
    RBE_BYTE(gbf, "当前_GRIS IP_地址", 4, "");
}

//GSM-R模式下CIR向GROS查询当前GRIS IP地址的数据帧
void tbt3325_t15()  
{  
    int i;
    char msg_name[64];
    sprintf(msg_name, "GSM-R_模式下_CIR_向_GROS_查询当前_GRIS IP_地址的数据帧");
    SET_MSG_TYPE(msg_name); 

	uint8_t trainno_len;
    PBE(trainno_len, 8);
    RBE_BYTE(gbf, "机车号长度", 1, "");
    char trainno[64] = {0};
    for (i = 0; i < trainno_len; i++)
    {
        PBE(trainno[i], 8);
        SKIP(1);
    }
	BACK(trainno_len);
    RBE_BYTE(gbf, "机车号", 10, trainno);
    RBE_BYTE(gbf, "位置区_ID", 2, "");
    RBE_BYTE(gbf, "小区_ID", 2, "");
    RBE_BYTE(gbf, "交路号", 2, "");
    RBE_BYTE(gbf, "公里标", 3, "");
    longitude();
    latitude();
    RBE_BYTE(gbf, "线路名称代码", 2, "");
    RBE_BYTE(gbf, "预留", 8, "");
}

//GSM-R模式下CIR发送车次号测试信息的数据帧
void tbt3325_t14()  
{    
    int i, j;
    int num;
    char msg_name[64];
    sprintf(msg_name, "GSM-R_模式下_CIR_发送车次号测试信息的数据帧");
    SET_MSG_TYPE(msg_name); 

    train_run_data();
    RBE_BYTE(gbf, "列车专用信息", 10, "0");
    RBE_BYTE(gbf, "CTC_专用域", 32, "");
    RBE_BYTE(gbf, "保留", 1, "");
    RBE_BYTE(gbf, "位置区_ID", 2, "");
    RBE_BYTE(gbf, "小区_ID", 2, "");
	char position_state[64] = {0};
    PBE(position_state[0], 8);
    RBE_BYTE(gbf, "定位状态", 1, position_state);
    longitude();
    latitude();
    int year, month, day;
    int hour, minute, second;
    char cur[64] = {0};
    PBE(num, 24);
    year = num & 0xFF0000;
    month = num & 0x00FF00;
    day = num & 0x0000FF;
    sprintf(cur, "20%d%d/%d%d/%d%d", year >> 4,year & 0x0F,month >> 4,month & 0x0F,day >> 4, day & 0x0F);
    PBE(num, 24);
    hour = num & 0xFF0000;
    minute = num & 0x00FF00;
    second = num & 0x0000FF;
    sprintf(cur + strlen(cur), " %d%d:%d%d:%d%d", hour >> 4, hour & 0x0F,minute >> 4, minute & 0x0F, second >> 4,second & 0x0F);
    RBE_BYTE(gbf, "当前时间", 6, cur);
}

//GSM-R模式下CIR发送车次号信息的数据帧
void tbt3325_t13()  
{    
    int i, j; 
    int num;
    char msg_name[64];
    sprintf(msg_name, "GSM-R_模式下_CIR_发送车次号信息的数据帧");
    SET_MSG_TYPE(msg_name);
    train_run_data();
    RBE_BYTE(gbf, "列车专用信息", 10, "");
    RBE_BYTE(gbf, "CTC_专用域", 32, "");
    RBE_BYTE(gbf, "预留", 1, "");
    RBE_BYTE(gbf, "位置区_ID", 2, "");
    RBE_BYTE(gbf, "小区_ID", 2, "");
	char position_state[64] = {0};
    PBE(position_state[0], 8);
    RBE_BYTE(gbf, "定位状态", 1, position_state);
    longitude();
    latitude();
    int year, month, day;
    int hour, minute, second;
    char cur[64] = {0};
    PBE(num, 24);
    year = num & 0xFF0000;
    month = num & 0x00FF00;
    day = num & 0x0000FF;
    sprintf(cur, "20%d%d/%d%d/%d%d", year >> 4,year & 0x0F,month >> 4,month & 0x0F,day >> 4, day & 0x0F);
    PBE(num, 24);
    hour = num & 0xFF0000;
    minute = num & 0x00FF00;
    second = num & 0x0000FF;
    sprintf(cur + strlen(cur), " %d%d:%d%d:%d%d", hour >> 4, hour & 0x0F,minute >> 4, minute & 0x0F, second >> 4,second & 0x0F);
    RBE_BYTE(gbf, "当前时间", 6, cur);
}

//D类编码器输出列车运行数据的数据帧
void tbt3325_t12()  
{   
    int i, j;
    char msg_name[64];
    sprintf(msg_name, "D_类编码器输出列车运行数据的数据帧");
    SET_MSG_TYPE(msg_name); 

    train_run_data();
}

//B类编码器输出车次号信息的数据帧
void tbt3325_t11()  
{   
    int i,j;
    char msg_name[64];
    sprintf(msg_name, "B_类编码器输出车次号信息的数据帧");
    SET_MSG_TYPE(msg_name);

    train_run_data();
}

//CIR发送的GPRS终端活动性检测数据帧格式
void tbt_t25()  
{   
	int i, j;	
    char msg_name[64];
    sprintf(msg_name, "CIR_发送的_GPRS_终端活动性检测数据帧格式");
    SET_MSG_TYPE(msg_name);

    RBE_BYTE(gbf, "序列号", 2, "");
	uint32_t num;
    char trainnum[64] = {0};
    char ch;
    for (i = 0, j = 0; i < 4; i++)
    {
        PBE(ch, 8);
        if(isupper(ch)) 
        {
            trainnum[j] = ch;
            j++; 
        } 
        SKIP(1);
    }
    PBE(num, 24);
    num = ntohl(num) >> 8;
	sprintf(trainnum + j, "%d", num);
    BACK(4);
	RBE_BYTE(gbf, "车次号", 7, trainnum);
	uint8_t no;
    char trainno[64] = {0};
    for (i = 0, j = 0; i < 4; i++)
    {
        PBE(no, 8);
		if (((no & 0xF0)>> 4) < 10)
		{
			sprintf(trainno + j, "%d", (no & 0xF0) >> 4);
            j++;
		}
		if ((no & 0x0F) < 10)
		{
			sprintf(trainno + j, "%d", no & 0x0F);
            j++;
		}
        SKIP(1);
    }
    BACK(4);
	RBE_BYTE(gbf, "机车号", 4, trainno);
	RBE_BYTE(gbf, "牵引状态", 1, "");
	RBE_BYTE(gbf, "位置区_ID", 2, "");
	RBE_BYTE(gbf, "小区_ID", 2, "");
	RBE_BYTE(gbf, "预留", 2, "");
}

//GRIS发送的GPRS终端活动性检测响应数据帧格式
void tbt_t26()  
{    
    char msg_name[64];
    sprintf(msg_name, "GRIS_发送的_GPRS_终端活动性检测响应数据帧格式");
    SET_MSG_TYPE(msg_name);

    RBE_BYTE(gbf, "序列号", 2, "");
    RBE_BYTE(gbf, "预留", 18, "");
}

#define PRINT printf("%d : 0x%x,0x%x\n", __LINE__, type, cmd);
void application()  
{   
    uint16_t frame_start;
	uint8_t type;
	uint8_t cmd;
	uint8_t head_len = 8;
	uint8_t ip_len;
	char *p;
	uint32_t ip;
	uint8_t port;
	int i;
	int len;
	char desc[256] = {0};
    BEGIN_ELEMENT("APP Layer", app_layer);
    PBE(frame_start, 16);
    if (frame_start == 0x1002)
    {
        //printf("frame_start : %x\n", frame_start);
        RBE_BYTE(gbf, "帧起始", 2, "");
        RBE_BYTE(gbf, "信息长度", 2, "");
		//源端口和目的端口
    	struct code2dict port_dict[] = 
    	{
			{0x00, "（本机全部端口）"},
			{0x01, "（主机）"},
			{0x02, "（两个_MMI_）"},
			{0x03, "（_MMI1_）"},
			{0x04, "（_MMI2_）"},
			{0x05, "（_450MHz_机车电台）"},
			{0x06, "（卫星定位数据端口）"},
			{0x07, "（记录转接单元）"},
			{0x3F, "（_CIR_维护端口）"},
			{0x11, "（机车数据采集编码器）"},
			{0x13, "（_800MHz_车载电台）"},
			{0x15, "（_DMS_）"},
			{0x41, "（_LBJ_数据管理器）"},
			{0x21, "（_CIR_检测服务器）"},
			{0x23, "（_TDCS/CTC_系统_GSM-R_通信服务器）"},
			{0x26, "（列车尾部安全防护装置主机）"},
			{0x27, "（_GRIS/GROS_服务器）"},
			{0x31, "（_CIR _出入库检测设备）"},
			{0x37, "（_M-GRIS_）"},
		};	
		len = sizeof(port_dict) / sizeof(port_dict[0]); 
        PBE(port, 8);
		for (i = 0; i < len; i++) 
		{ 
			if (port_dict[i].code == port) 
			{
				memset(desc, 0x00, sizeof(desc));
				sprintf(desc, "%d_%s", port, port_dict[i].str);
				break; 
			} 
		}
		if(i < len)
		{
        	RBE_BYTE(gbf, "源端口代码", 1, desc);
		}
		else
		{
        	RBE_BYTE(gbf, "源端口代码", 1, "");
		}

        PBE(ip_len, 8);
        RBE_BYTE(gbf, "源通信地址长度", 1, "");
	    if(ip_len > 0)
	    {
    		char srcip[64] = {0}; 
    		PBE(ip, 32); 
			p = &ip; 
			sprintf(srcip, "%d.%d.%d.%d", p[3] & 0xff, p[2] & 0xff, p[1] & 0xff, p[0] & 0xff);	
        	RBE_BYTE(gbf, "源通信地址", 4, srcip);
	    }
		
		len = sizeof(port_dict) / sizeof(port_dict[0]); 
        PBE(port, 8);
		for (i = 0; i < len; i++) 
		{ 
			if (port_dict[i].code == port) 
			{ 
				memset(desc, 0x00, sizeof(desc));
				sprintf(desc, "%d_%s", port, port_dict[i].str);
				break; 
			} 
		}
		if(i < len)
		{
        	RBE_BYTE(gbf, "目的端口代码", 1, desc);
		}
		else
		{
        	RBE_BYTE(gbf, "目的端口代码", 1, "");
		}
        PBE(ip_len, 8);
        RBE_BYTE(gbf, "目的通信地址长度", 1, "");
	    if(ip_len > 0)
	    {
    		char dstip[64] = {0}; 
    		PBE(ip, 32); 
			p = &ip; 
			sprintf(dstip, "%d.%d.%d.%d", p[3] & 0xff, p[2] & 0xff, p[1] & 0xff, p[0] & 0xff);	
        	RBE_BYTE(gbf, "目的通信地址", 4, dstip);
	    }
        PBE(type, 8);
    	struct code2dict datatype_dict[] = 
    	{
			{0x00, "（记录业务）"},
			{0x01, "（维护）"},
			{0x02, "（公共信息）"},
			{0x03, "（调度通信）"},
			{0x04, "（列尾风压）"},
			{0x05, "（无线车次号）"},
			{0x06, "（调度命令）"},
			{0x07, "（列车停稳_/_启动）"},
			{0x0B, "（_800MHz_车载电台）"},
			{0x0C, "（_DMS_）"},
			{0x0E, "（_M-GRIS IP_地址查询_/_更新_/_响应信息）"},
			{0x0F, "（_GRIS IP_地址查询_/_更新_/_响应信息）"},
			{0x13, "（出入库检测）"},
			{0xF1, "（_GPRS_终端活动性检测信息）"},
    	};
		int len = sizeof(datatype_dict) / sizeof(datatype_dict[0]); 
		for (i = 0; i < len; i++) 
		{ 
			if (datatype_dict[i].code == type) 
			{ 
				memset(desc, 0x00, sizeof(desc));
				sprintf(desc, "%d_%s", type, datatype_dict[i].str);
				break; 
			} 
		}
		if(i < len)
		{
        	RBE_BYTE(gbf, "业务类型", 1, desc);
		}
		else 
		{
        	RBE_BYTE(gbf, "业务类型", 1, "");
		}
        PBE(cmd, 8);
		struct code2dict commandcode_dict[] = 
		{
			{0x00, "（发送广播信息）"},
			{0x01, ""},
			{0x02, "（列车停稳信息）"},
			{0x20, "（调度命令信息）"},
			{0x51, "（自动确认，手动签收，出入库检测请求信息）"},
			{0x53, "（调车请求信息）"},
			{0x80, ""},
			{0x81, "（_CIR_查询的响应）"},
			{0x83, "（_GRIS_触发）"},
			{0x21, "（车次号信息）"},
			{0x03, "（列车启动信息）"},
			{0xF0, "（系统控制信息）"},/*0xF0~0xFF*/
		};
		len = sizeof(commandcode_dict) / sizeof(commandcode_dict[0]); 
		for (i = 0; i < len; i++) 
		{ 
			if (commandcode_dict[i].code == cmd || commandcode_dict[i].code == (cmd & 0xF0)) 
			{ 
				memset(desc, 0x00, sizeof(desc));
				sprintf(desc, "%d_%s", cmd, commandcode_dict[i].str);
				break; 
			} 
		}
		if(i < len)
		{
        	RBE_BYTE(gbf, "命令", 1, desc);
		}
		else
		{
        	RBE_BYTE(gbf, "命令", 1, "");
		}

	    if (type == 0x06 && cmd == 0x20)
	    {
	    	//PRINT;
	    	tbt3231_t5();
	    }
	    else if (type == 0x06 && (cmd == 0x51 || cmd == 0x53))
	    {
	    	//PRINT;
	    	tbt3231_t7();
	    }
	    else if (type == 0x05 && cmd == 0x00)
	    {
	    	//PRINT;
	    	tbt3325_t11(); 
	    }
	    else if (type == 0x0B && cmd == 0x00)
	    {
	    	//PRINT;
	    	tbt3325_t12(); 
	    }
	    else if (((type&0x05) == 0x05) && (cmd == 0x02 || cmd == 0x03 || cmd == 0x21))
	    {
	    	//PRINT;
	    	tbt3325_t13(); 
	    }
	    else if (type == 0x13 && cmd == 0x21)
	    {
	    	//PRINT;
	    	tbt3325_t14(); 
	    }
	    else if (type == 0x0F && cmd == 0x01)
	    {
	    	//PRINT;
	    	tbt3325_t15(); 
	    }
	    else if (type == 0x0F && (cmd == 0x81 || cmd == 0x83))
	    {
	    	//PRINT;
	    	tbt3325_t16(); 
	    }
	    else if (type == 0x0F && cmd == 0x02)
	    {
	    	//PRINT;
	    	tbt3325_t17(); 
	    }
	    else if (type == 0x05 && cmd == 0x80)
	    {
	    	//PRINT;
	    	tbt3325_t18();
	    }
	    else if (type == 0xF1 && cmd == 0x01)
	    {
	    	//PRINT;
	    	tbt_t25();
	    }
	    else if (type == 0xF1 && cmd == 0x02)
	    {
	    	//PRINT;
	    	tbt_t26();
	    }
        
        uint8_t flag = HdlcFcsCheck(len - 4, input + 2);
        HEX(2); 
        A_B8_VALUE(gbf, fcs, "CRC_校验", flag); 
        SKIP(2); 
        RBE_BYTE(gbf, "帧结束", 2, "");
    }
    END_ELEMENT(); 
}

#endif
