//
// Created by LQYHE on 2021/5/18.
//

#include "httpcommon.h"
HttpCommon::~HttpCommon()
{
	if(m_response_fnc)
	{
		m_response_fnc(m_result,m_res_header,m_response);
	}
}
