-- Generated by nbec  on Sat May 27 04:19:05 2017

--nbe custom type
-- custom type and funcs for nbe_pgtype
CREATE FUNCTION libnbe_data_version() 
  RETURNS cstring
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION nbe_pu_list_count(d nbe_pu) 
  RETURNS integer
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION nbe_pu_list_get_element(d nbe_pu, idx integer) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_frame_head(nbe_pu) 
  RETURNS int4
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_frame_len(nbe_pu) 
  RETURNS int4
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_collect_time_s(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_collect_time_ms(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_board_num(nbe_pu) 
  RETURNS int2
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_port_num(nbe_pu) 
  RETURNS int2
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_time_slot(nbe_pu) 
  RETURNS int2
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_data_num(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_parse_time(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_data_len(nbe_pu) 
  RETURNS int4
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_data_pos(nbe_pu) 
  RETURNS int2
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_public_ip(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_layer(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_frame_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_signal_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_raw(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_raw_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_next_pos(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_next_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fr_msg_elements(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_layer(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_frame_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_signal_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_raw(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_raw_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_next_pos(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_next_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_data(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_data_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gb_elements(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbe_element_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbe_element_desc(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbe_fields(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbf_f_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbf_f_id(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbf_f(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbf_f_bin(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbf_f_hex(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION gbf_f_desc(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_gb_layer(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_frame_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_signal_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_raw(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_raw_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_next_pos(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_next_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_data(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_data_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION sndcp_elements(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_gb_layer(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_frame_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_signal_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_raw(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_raw_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_next_pos(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_next_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_data(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_data_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION ip_elements(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_gb_layer(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_frame_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_signal_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_raw(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_raw_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_next_pos(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_next_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_data(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_data_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION transport_elements(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_gb_layer(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_frame_type(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_signal_name(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_raw(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_raw_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_next_pos(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_next_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_data(nbe_pu) 
  RETURNS TEXT
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_data_len(nbe_pu) 
  RETURNS int8
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION application_elements(nbe_pu) 
  RETURNS nbe_pu
  AS 'MODULE_PATHNAME'
  LANGUAGE C IMMUTABLE STRICT;
