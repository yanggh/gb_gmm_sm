#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "nbe_pu_gb.h"
#include "nbe_pu_gbe.h"
#include "nbe_pu_gbf.h"

#if 0
MU_TEST(test_measurement_report) {
    int frame_length;

    uint8_t msg[] = {0x06, 0x15, 0x31, 0x31, 0x00, 0x4d, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e};
    frame_length = sizeof(msg);
 
    void *data_ctx = measurement_report_state_new(NULL);

    int dir = 0;
    measurement_report_set_param(data_ctx, 1, &dir, sizeof(dir));
    measurement_report_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = measurement_report_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("um_measurement_report: %s\n\n", json);
    measurement_report_state_free(data_ctx);
}

MU_TEST( test_unknown_signal) {

    int frame_length;
//16 06 03 00 A0 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    uint8_t msg[] = {0x16, 0x06, 0x03, 0x2A, 0xF4, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

    int pd = 1;
    int msg_type = 0;

    void *data_ctx = um_unknown_signal_state_new(NULL);
    um_unknown_signal_set_param(data_ctx, 1, &pd, sizeof(pd));
    um_unknown_signal_set_param(data_ctx, 1, &msg_type, sizeof(msg_type));
    um_unknown_signal_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = um_unknown_signal_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("um_unknown_siganl: %s\n\n", json);

}
#endif

MU_TEST( test_sndcp) 
{
    int frame_length;
//16 06 03 00 A0 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    uint8_t msg[] = {0x16, 0x06, 0x03, 0x2A, 0xF4, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

    int pd = 1;
    int msg_type = 0;

    void *data_ctx = sndcp_state_new(NULL);
    //sndcp_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    sndcp_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = sndcp_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("sndcp: %s\n\n", json);

}

MU_TEST( test_ip) 
{
    int frame_length;
//16 06 03 00 A0 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    uint8_t msg[] = {0x16, 0x06, 0x03, 0x2A, 0xF4, 0x42, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };


    void *data_ctx = ip_state_new(NULL);
    //sndcp_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    ip_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = ip_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("ip: %s\n\n", json);

}

MU_TEST( test_transport) 
{
    int length;
//16 06 03 00 A0 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    uint8_t msg[] = {0x16, 0x06, 0x03, 0x2A, 0xF4, 0x42, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

	length = sizeof(msg);

    void *data_ctx = transport_state_new(NULL);
    //sndcp_parse(data_ctx, msg, sizeof(msg), 1, NULL);
	int protocol = 17;
	//ICMP 1
	//IGMP 2
	//TCP 6
	//EGP 8
	//UDP 17
    transport_set_param(data_ctx, 1, &length, sizeof(length));
    transport_set_param(data_ctx, 2, &protocol, sizeof(protocol));
    transport_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = transport_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("transport: %s\n\n", json);

}

void remove_json(char *json)
{
	int i = 0;
	int j = 0;
    if (strlen(json) <= 0)
    {
        return;
    }
    while (i < strlen(json) - 3)
    {
        if (*(json + i) == '\\' && *(json + i + 1) == 'u' && *(json + i + 2) == '0' && *(json + i + 3) == '0')
        {
            i+=4;
        }
        else
        {
            *(json + j) = *(json + i);
            i++;
            j++;
        } 
    }
	while(i < strlen(json))
	{
    	*(json + j) = *(json + i);
    	i++;
    	j++;
	}
	*(json + j) = '\0';
}

MU_TEST( test_application) 
{
    int frame_length;
//16 06 03 00 A0 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    uint8_t msg11[] = {0x10, 0x02, 0x00, 0x52, 0x11, 0x00, 0x01, 0x00, 0x05, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
    uint8_t msg12[] = {0x10, 0x02, 0x00, 0x52, 0x11, 0x00, 0x13, 0x00, 0x0B, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
    uint8_t msg13[] = {0x10, 0x02, 0x00, 0x52, 0x01, 0x04, 0x11, 0x22, 
					 0x33, 0x44, 0x23, 0x04, 0x11, 0x22, 0x33, 0x44, 0x05, 0x02, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

    uint8_t msg14[] = {0x10, 0x02, 0x00, 0x52, 0x01, 0x04, 0x11, 0x22, 
					 0x33, 0x44, 0x23, 0x04, 0x11, 0x22, 0x33, 0x44, 0x13, 0x21, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

    uint8_t msg15[] = {0x10, 0x02, 0x00, 0x52, 0x01, 0x04, 0x11, 0x22, 
					 0x33, 0x44, 0x23, 0x04, 0x11, 0x22, 0x33, 0x44, 0x0F, 0x01, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
    uint8_t msg16[] = {0x10, 0x02, 0x00, 0x52, 0x01, 0x04, 0x11, 0x22, 
					 0x33, 0x44, 0x23, 0x04, 0x11, 0x22, 0x33, 0x44, 0x0F, 0x83, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
    uint8_t msg17[] = {0x10, 0x02, 0x00, 0x52, 0x01, 0x04, 0x11, 0x22, 
					 0x33, 0x44, 0x23, 0x04, 0x11, 0x22, 0x33, 0x44, 0x0F, 0x02, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
    uint8_t msg18[] = {0x10, 0x02, 0x00, 0x52, 0x01, 0x04, 0x11, 0x22, 
					 0x33, 0x44, 0x23, 0x04, 0x11, 0x22, 0x33, 0x44, 0x05, 0x80, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

    void *data_ctx = application_state_new(NULL);
    //sndcp_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    application_parse(data_ctx, msg18, sizeof(msg18), 1, NULL);
    nbe_pu_gb *data = application_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
	remove_json(json);
    printf("application: %s\n\n", json);

}

MU_TEST_SUITE( all_tests)
{
	//MU_RUN_TEST(test_unknown_signal);
    //MU_RUN_TEST(test_measurement_report);
    MU_RUN_TEST(test_sndcp);
    MU_RUN_TEST(test_ip);
    MU_RUN_TEST(test_transport);
    MU_RUN_TEST(test_application);
}

int main(int argc, char **argv) {
	MU_RUN_SUITE(all_tests);
	MU_REPORT();
	return 0;
}
