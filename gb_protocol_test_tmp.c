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
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

    uint8_t msg0521[] = {
                     0x10, 0x02, 0x00, 0x97, 0x01, 0x04, 0x0a, 0x0d, 
                     0x0a, 0x72, 0x23, 0x04, 0x0a, 0x0d, 0x01, 0x46, 
                     0x05, 0x21, 0x38, 0x00, 0x67, 0x10, 0x10, 0x00, 
                     0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00, 
                     0x00, 0x01, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 
                     0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x47, 0x04, 
                     0x01, 0xea, 0x39, 0xc0, 0x01, 0x02, 0xf1, 0x0e, 
                     0x45, 0x00, 0x50, 0x05, 0x06, 0x05, 0x1d, 0x00, 
                     0x01, 0x7f, 0x96, 0x98, 0xb0, 0x04, 0xbc, 0x01, 
                     0x15, 0x40, 0x47, 0x04, 0x01, 0x01, 0xec, 0x0a, 
                     0x77, 0x33, 0xcc, 0x01, 0xef, 0x50, 0x00, 0x81, 
                     0x00, 0x55, 0x00, 0x05, 0x00, 0x01, 0x00, 0x01, 
                     0x00, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                     0xff, 0xff, 0xff, 0xff, 0xde, 0x21, 0xf4, 0xff, 
                     0xf3, 0x41, 0x01, 0x16, 0x26, 0x60, 0x54, 0x39, 
                     0x54, 0x00, 0x16, 0x17, 0x04, 0x07, 0x15, 0x04, 
                     0x09, 0x26, 0xf8, 0x10, 0x03};


    void *data_ctx = application_state_new(NULL);
    //sndcp_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    application_parse(data_ctx, msg0521, sizeof(msg0521), 1, NULL);
    nbe_pu_gb *data = application_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
	remove_json(json);
    printf("application: %s\n\n", json);

}

MU_TEST(test_attach_request) {
    int frame_length;

uint8_t msg[] ={0x08, 0x01, 0x01, 0xe4, 0x61, 0x0d, 0x01, 0x05, 0xf4, 0xc5, 0x00, 0x64, 0xaa, 0x64, 0xf0, 0x02, 0x21, 0xf4, 0x04, 0x09, 0x14, 0xd3, 0x03, 0x30, 0xd4, 0xa9, 0xcc, 0x49, 0x61};
    frame_length = sizeof(msg);
 
    void *data_ctx = attach_request_state_new(NULL);

    int dir = 1;
    attach_request_set_param(data_ctx, 1, &dir, sizeof(dir));
    attach_request_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = attach_request_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("attach_request: %s\n\n", json);
    attach_request_state_free(data_ctx);
}

MU_TEST(test_authentication_and_ciphering_request) {
    int frame_length;

uint8_t msg[] = {0x08, 0x12, 0x00, 0x10, 0x21, 0xcf, 0x02, 0x27, 0xc2, 0x88, 0x1f, 0x87, 0x40, 0x57, 0x75, 0x10, 0x10, 0x37, 0x0f, 0xc4, 0xf3, 0x81};
    frame_length = sizeof(msg);
 
    void *data_ctx = authentication_and_ciphering_request_state_new(NULL);

    int dir = 0;
    authentication_and_ciphering_request_set_param(data_ctx, 1, &dir, sizeof(dir));
    authentication_and_ciphering_request_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = authentication_and_ciphering_request_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("authentication_and_ciphering_request: %s\n\n", json);
    authentication_and_ciphering_request_state_free(data_ctx);
}

MU_TEST(test_activate_pdp_context_request) {
    int frame_length;

    uint8_t msg[] = {0x0a, 0x41, 0x05, 0x0b, 0x03, 0x00, 0x00, 0x00, 0x02, 0x01, 0x21, 0x28, 0x08, 0x04, 0x47, 0x52, 0x49, 0x53, 0x02, 0x42, 0x4a, 0x27, 0x2d, 0x80, 0xc0, 0x23, 0x16, 0x01, 0x01, 0x00, 0x16, 0x08, 0x32, 0x33, 0x39, 0x30, 0x30, 0x33, 0x36, 0x37, 0x08, 0x32, 0x33, 0x39, 0x30, 0x30, 0x33, 0x36, 0x37, 0x80, 0x21, 0x10, 0x01, 0x01, 0x00, 0x10, 0x81, 0x06, 0x00, 0x00, 0x00, 0x00, 0x83, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x21, 0x08, 0x01, 0x01, 0x00, 0x08, 0x01, 0x04, 0x05, 0xdc};
    frame_length = sizeof(msg);
 
    void *data_ctx = activate_pdp_context_request_state_new(NULL);

    int dir = 0;
    activate_pdp_context_request_set_param(data_ctx, 1, &dir, sizeof(dir));
    activate_pdp_context_request_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = activate_pdp_context_request_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("activate_pdp_context_request: %s\n\n", json);
    activate_pdp_context_request_state_free(data_ctx);
}

MU_TEST(test_activate_pdp_context_accept) {
    int frame_length;

    uint8_t msg[] = {0x8a, 0x42, 0x0b, 0x03, 0x0b, 0x41, 0x1f, 0x02, 0x2b, 0x06, 0x01, 0x21, 0x0a, 0x0d, 0x09, 0xed, 0x27, 0x14, 0x80, 0x80, 0x21, 0x10, 0x04, 0x01, 0x00, 0x10, 0x81, 0x06, 0x00, 0x00, 0x00, 0x00, 0x83, 0x06, 0x00, 0x00, 0x00, 0x00};
    frame_length = sizeof(msg);
 
    void *data_ctx = activate_pdp_context_accept_state_new(NULL);

    int dir = 0;
    activate_pdp_context_accept_set_param(data_ctx, 1, &dir, sizeof(dir));
    activate_pdp_context_accept_parse(data_ctx, msg, sizeof(msg), 1, NULL);
    nbe_pu_gb *data = activate_pdp_context_accept_get_userdata(data_ctx);
    char *json = nbe_json_write((nbe_pu*)data);
    printf("activate_pdp_context_accept: %s\n\n", json);
    activate_pdp_context_accept_state_free(data_ctx);
}

MU_TEST_SUITE( all_tests)
{
	//MU_RUN_TEST(test_unknown_signal);
    //MU_RUN_TEST(test_measurement_report);
    //MU_RUN_TEST(test_sndcp);
    //MU_RUN_TEST(test_ip);
    //MU_RUN_TEST(test_transport);
    //MU_RUN_TEST(test_application);
    //MU_RUN_TEST(test_attach_request);
    //MU_RUN_TEST(test_authentication_and_ciphering_request);
    //MU_RUN_TEST(test_activate_pdp_context_accept);
    MU_RUN_TEST(test_activate_pdp_context_request);
}

int main(int argc, char **argv) {
	MU_RUN_SUITE(all_tests);
	MU_REPORT();
	return 0;
}
