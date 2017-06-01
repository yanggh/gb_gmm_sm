#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
//#include "nbe_pu_gb_public.h"
//#include "nbp_gb_head.h"
//#include "nbe_pu_l2_msg.h"
#include "nbp_fr_layer.h"
//#include "nbe_pu_channel_req.h"
//#include "nbp_channel_req.h"
#include "nbe_pu_gb.h"
#include "nbe_pu_gbe.h"
#include "nbe_pu_gbf.h"


#if 0
MU_TEST(test_gb_head)
{
#if 1
char msg_head[] = "\xFF\x7E"
            "\x22\x00"
            "\x00\x58\xcf\xab\x79\x07\xce\x53" 
            "\x00"
            "\x00"
            "\x00"
            "\x00\x36\x2c\x16"
            "\x00\x01\x03\x08\x00\x75\x51\x01\x01\x53\x02\x49\x10"
            "\xd5\xe4";
#endif

	int rec = -1;
	void *ctx = gb_head_state_new(NULL);
	rec = gb_head_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("gb_head_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu_gb_public *gbh = gb_head_get_userdata(ctx);
	mu_assert(gbh, "userdata should not be null");

	//int frame_head = nbe_gb_public_get_frame_head(gbh);
	//int frame_len = nbe_gb_public_get_frame_len(gbh);
	//long long collect_time = nbe_gb_public_get_collect_time(gbh);
	//int time_slot  = nbe_gb_public_get_time_slot(gbh);
	//int data_len  = nbe_gb_public_get_data_len(gbh);
	//int data_pos  = nbe_gb_public_get_data_pos(gbh);

    char *gb_head_json = nbe_json_write((nbe_pu*)gbh);
    printf("gb_head json: %s\n\n", gb_head_json);

	gb_head_state_free(ctx);
}
#endif

MU_TEST(test_gb_fr_layer) 
{
#if 1
	//char msg_head[] = {0x04, 0x41, 0x00, 0x00};
	char msg_head[] = {0x00, 0x01, 0x03, 0x08, 0x00, 0x75, 0x51, 0x01, 0x00, 0x53, 0x02, 0x65, 0x00};
#endif
	int rec = -1;
	void *ctx = fr_layer_state_new(NULL);
    int data_len = 4;
    int dir = 0;
	fr_layer_set_param(ctx, 1, &data_len, sizeof(data_len));
	//fr_layer_set_param(ctx, 2, &dir, sizeof(dir));
	rec = fr_layer_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("fr_layer_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu_fr_msg *frMsg = fr_layer_get_userdata(ctx);
	mu_assert(frMsg, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)frMsg);
    printf("fr json: %s\n", json);
	fr_layer_state_free(ctx);
}

MU_TEST(test_gb_ns_alive) 
{
#if 1
	char msg_head[] = {0x0A};
#endif
	int rec = -1;
    int data_len = 1;
	void *ctx = ns_alive_state_new(NULL);
	ns_alive_set_param(ctx, 1, &data_len, sizeof(data_len));
	rec = ns_alive_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("ns_alive_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = ns_alive_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("fr json: %s\n", json);
	ns_alive_state_free(ctx);
}

MU_TEST(test_gb_ns_status) 
{
#if 1
	//char msg_head[] = {0x08, 0x00, 0x03, 0x03};
	char msg_head[] = {0x08, 0x00, 0x03, 0x00, 0x11};
#endif
	int rec = -1;
    int data_len = 5;
	void *ctx = ns_status_state_new(NULL);
	ns_status_set_param(ctx, 1, &data_len, sizeof(data_len));
	rec = ns_status_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("ns_status_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = ns_status_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("ns_status json: %s\n", json);
	ns_status_state_free(ctx);
}

MU_TEST(test_gb_flush_ll_ack) 
{
#if 1
	//char msg_head[] = {0x08, 0x00, 0x03, 0x03};
	char msg_head[] = {0x2b, 0x1f, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03};
#endif
	int rec = -1;
    int data_len = 15;
	void *ctx = flush_ll_ack_state_new(NULL);
	flush_ll_ack_set_param(ctx, 1, &data_len, sizeof(data_len));
	rec = flush_ll_ack_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("flush_ll_ack_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = flush_ll_ack_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("ns_status json: %s\n", json);
	flush_ll_ack_state_free(ctx);
}

MU_TEST(test_gb_flow_control_bvc) 
{
#if 1
	//char msg_head[] = {0x08, 0x00, 0x03, 0x03};
	char msg_head[] = {0x26, 0x1e, 0x01, 0x01, 0x05, 0x02, 0x03, 0x04, 0x03, 0x02, 0x01, 0x03, 0x01, 0x02, 0x03, 0x01, 0x1c, 0x02, 0x01, 0x02, 0x3c, 0x01, 0x00, 0x06, 0x02, 0x01, 0x02};
#endif
	int rec = -1;
    int data_len = 29;
	void *ctx = flow_control_bvc_state_new(NULL);
	flow_control_bvc_set_param(ctx, 1, &data_len, sizeof(data_len));
	rec = flow_control_bvc_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("flow_control_bvc_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = flow_control_bvc_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("ns_status json: %s\n", json);
	flow_control_bvc_state_free(ctx);
}

MU_TEST(test_gb_flow_control_ms_ack) 
{
#if 1
	//char msg_head[] = {0x08, 0x00, 0x03, 0x03};
	char msg_head[] = {0x29, 0x1f, 0x84, 0xc0, 0x02, 0x80, 0x00, 0x1e, 0x81, 0xbe};
#endif
	int rec = -1;
    int data_len = 10;
	void *ctx = flow_control_ms_ack_state_new(NULL);
	flow_control_ms_ack_set_param(ctx, 1, &data_len, sizeof(data_len));
	rec = flow_control_ms_ack_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("flow_control_ms_ack_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = flow_control_ms_ack_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("flow_control_ms_ack json: %s\n", json);
	flow_control_ms_ack_state_free(ctx);
}

MU_TEST(test_gb_llc_layer) 
{
#if 1
	//char msg_head[] = {0x01, 0x1f, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03}; //I
	//char msg_head[] = {0x01, 0xc0, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03}; //UI
	//char msg_head[] = {0x01, 0xe8, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03};   //U
	char msg_head[] = {0x41, 0xc0, 0x3d, 0xda, 0x43, 0x21, 0x9b, 0x33, 0x6c};   //UI
#endif
	int rec = -1;
    int data_len = 15;
	int dir = 0;
	void *ctx = llc_layer_state_new(NULL);
	llc_layer_set_param(ctx, 1, &data_len, sizeof(data_len));
	llc_layer_set_param(ctx, 2, &dir, sizeof(dir));
	rec = llc_layer_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("llc_layer_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = llc_layer_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("llc layer json: %s\n", json);
	llc_layer_state_free(ctx);
}

MU_TEST(test_gb_ul_unitdata) 
{
#if 1
	//char msg_head[] = {0x01, 0x1f, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03}; //I
	//char msg_head[] = {0x01, 0xc0, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03}; //UI
	char msg_head[] = {0x01, 0xc0, 0x02, 0x80, 0x00, 0x00, 0x0b, 0x04, 0x08, 0x88, 0x64, 0xf0, 0x02, 0x21, 0x10, 0x00, 0x90, 0x03, 0x00, 0x05, 0x0e, 0x00, 0x5a, 0x01, 0xc0, 0x15, 0x3a, 0x41, 0x05, 0x03, 0x0c, 0x23, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x8d, 0x28, 0x06, 0x05, 0x63, 0x6d, 0x6e, 0x65, 0x74, 0x27, 0x36, 0x80, 0x80, 0x21, 0x10, 0x01, 0x01, 0x00, 0x10, 0x81, 0x06, 0x00, 0x00, 0x00, 0x00, 0x83, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x23, 0x10, 0x01, 0x01, 0x00, 0x10, 0x05, 0x63, 0x6d, 0x6e, 0x65, 0x74, 0x05, 0x63, 0x6d, 0x6e, 0x65, 0x74, 0x00, 0x03, 0x00, 0x00, 0x05, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x10, 0x00, 0x5e, 0x02, 0x5c};
#endif
	int rec = -1;
    int data_len = 113;
	int dir = 0;
	void *ctx = ul_unitdata_state_new(NULL);
	ul_unitdata_set_param(ctx, 1, &data_len, sizeof(data_len));
	ul_unitdata_set_param(ctx, 2, &dir, sizeof(dir));
	rec = ul_unitdata_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("ul_unitdata_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = ul_unitdata_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("json: %s\n", json);
	ul_unitdata_state_free(ctx);
}

MU_TEST(test_gb_dl_unitdata) 
{
#if 1
	//char msg_head[] = {0x01, 0x1f, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03}; //I
	//char msg_head[] = {0x01, 0xc0, 0x04, 0x00, 0x01, 0x02, 0x03, 0x0c, 0x01, 0x00, 0x25, 0x03, 0x0a, 0x01, 0x03}; //UI
	char msg_head[] ={0x00, 0xc0, 0x02, 0x80, 0x00, 0x00, 0x00, 0x20, 0x16, 0x82, 0x02, 0x58, 0x13, 0x9d, 0x1a, 0x13, 0x02, 0x2b, 0x25, 0x96, 0x46, 0x00, 0x00, 0x00, 0x08, 0x13, 0x6e, 0x50, 0xc8, 0xc0, 0x00, 0x00, 0x01, 0x02, 0xed, 0xe2, 0x19, 0x18, 0x00, 0x00, 0x00, 0x20, 0x00, 0x0a, 0x82, 0x08, 0x03, 0x0d, 0x88, 0x49, 0x06, 0x02, 0x08, 0x91, 0x09, 0x00, 0x45, 0x00, 0x81, 0x00, 0x0e, 0x00, 0x09, 0x41, 0xc0, 0x3d, 0xda, 0x43, 0x21, 0x9b, 0x33, 0x6c};
#endif
	int rec = -1;
    int data_len = 72;
	int dir = 0;
	void *ctx = dl_unitdata_state_new(NULL);
	dl_unitdata_set_param(ctx, 1, &data_len, sizeof(data_len));
	dl_unitdata_set_param(ctx, 2, &dir, sizeof(dir));
	rec = dl_unitdata_parse(ctx, msg_head, sizeof(msg_head), 1, NULL);
	if(rec < 0)
	{
		printf("dl_unitdata_parse failed!!! return value: %d\n", rec);
		return;	
	}
	nbe_pu *pu = dl_unitdata_get_userdata(ctx);
	mu_assert(pu, "userdata should not be null");
	char *json = nbe_json_write((nbe_pu*)pu);
    printf("json: %s\n", json);
	dl_unitdata_state_free(ctx);
}

MU_TEST_SUITE( all_tests)
{
	//MU_RUN_TEST(test_gb_head);
	//MU_RUN_TEST(test_gb_fr_layer);
	MU_RUN_TEST(test_gb_llc_layer);
	//MU_RUN_TEST(test_gb_ns_alive);
	//MU_RUN_TEST(test_gb_ns_status);
	//MU_RUN_TEST(test_gb_flush_ll_ack);
	//MU_RUN_TEST(test_gb_flow_control_bvc);
	//MU_RUN_TEST(test_gb_flow_control_ms_ack);
	//MU_RUN_TEST(test_gb_ul_unitdata);
	//MU_RUN_TEST(test_gb_dl_unitdata);
}

int main(int argc, char **argv) {
    MU_RUN_SUITE(all_tests);
    MU_REPORT();
    return 0;
}

