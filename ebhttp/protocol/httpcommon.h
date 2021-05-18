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
	HttpCommon(const std::string &uri, const std::string &content);
	~HttpCommon();
	void SetFindReqHeaderCallback(std::function<std::string(const std::string&)> fnc){m_finc_req_header = fnc;}
	void SetResponse(std::function<void(const eb_tools::EBResult& result,const std::map<std::string,std::string> response_header_map,const std::string& content)>fnc){m_response_fnc = fnc;}
protected:
	eb_tools::EBResult m_result;
	std::map<std::string,std::string> m_res_header;
	std::string m_response;
private:
	std::string m_uri;
	std::string m_content;
	std::function<std::string(const std::string&)>m_finc_req_header;
	std::function<void(const eb_tools::EBResult& result,const std::map<std::string,std::string> response_header_map,const std::string& content)>m_response_fnc;

};


#endif //HTTPCOMMON_H
