//
// Created by LQYHE on 2021/5/18.
//

#ifndef REGISTACCOUNT_H
#define REGISTACCOUNT_H


#include "httpcommon.h"
enum AccountType
{
	em_email,
	em_phone
};
class RegistAccount: public HttpCommon
{
public:
	RegistAccount(const std::string &uri, const std::string &content);;
private:
	AccountType m_account_type;
	std::string m_account;
	std::string m_password;
};


#endif //REGISTACCOUNT_H
