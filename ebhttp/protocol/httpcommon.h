//
// Created by LQYHE on 2021/5/18.
//

#ifndef HTTPCOMMON_H
#define HTTPCOMMON_H

#include <string>
#include <functional>
#include <map>
#include "../ebresult/ebresult.h"
class HttpCommon
{
public:
	~HttpCommon();
	void SetFindReqHeaderCallback(std::function<std::string(const std::string&)> fnc){m_finc_req_header = fnc;}
	void SetResponse(std::function<void(const eb_tools::EBResult& result,const std::map<std::string,std::string> response_header_map)>fnc){m_response_fnc = fnc;}
protected:
	eb_tools::EBResult m_result;
	std::map<std::string,std::string> m_res_header;
private:
	std::function<std::string(const std::string&)>m_finc_req_header;
	std::function<void(const eb_tools::EBResult& result,const std::map<std::string,std::string> response_header_map)>m_response_fnc;

};


#endif //HTTPCOMMON_H
