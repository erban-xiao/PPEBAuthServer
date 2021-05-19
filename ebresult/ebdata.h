//
// Created by qianyouliang on 2020/11/13.
//

#ifndef EB_EXCEPTION_EBDATA_H
#define EB_EXCEPTION_EBDATA_H

namespace eb_tools
{
enum ResultCode
{
	em_result_success = 0,
	//network
	em_result_err_thread,
	em_result_err_port,

	//json
	em_parse_no_node,
	em_json_parse_content_fail,
	em_json_no_find_tar_node,
	em_json_not_string_node,
	em_json_not_long_node,
	em_json_not_int_node,
	em_json_not_array_node,
	em_json_array_index_overspill,
	em_json_no_node,
	em_json_not_tar_type_node,

	//protocol
	em_reg_err_account_type,
};
}

#endif //EB_EXCEPTION_EBDATA_H
