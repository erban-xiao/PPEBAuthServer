//
// Created by qianyouliang on 2020/11/13.
//

#ifndef EB_EXCEPTION_EBDATA_H
#define EB_EXCEPTION_EBDATA_H

enum EBResultType
{
    em_json_parser,
    em_network,
};

enum EBJsonResult
{
    em_parse_no_node,
    em_parse_json_no_find_tar_node,
    em_parse_json_not_tar_type_node,
    em_parse_json_not_array_node,
    em_parse_json_not_string_node,
    em_parse_json_not_long_node,
    em_parse_json_array_index_overspill,
    em_parse_json_content_fail,
    em_parse_json_not_int_node,

};

enum EBNewworkResult
{
	em_network_init_fail,
	em_network_start_fail,
	em_network_err_port,
	em_network_conflict_port,
	em_network_empty_name,
	em_network_empty_callback,
};

#endif //EB_EXCEPTION_EBDATA_H
