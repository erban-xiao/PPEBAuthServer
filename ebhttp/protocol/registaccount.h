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
	void FromProtocol(const std::string& path,const std::string& content);
	std::string ToProtocol();
public://request
	AccountType GetAccountType() const;
	void SetAccountType(AccountType account_type);
	const std::string &GetAccount() const;
	void SetAccount(const std::string &account);
	const std::string &GetPassword() const;
	void SetPassword(const std::string &password);
private:
	AccountType m_account_type;
	std::string m_account;
	std::string m_password;
public://response
	const std::string &GetSession() const;
	void SetSession(const std::string &session);
private:
	std::string m_session;
};


#endif //REGISTACCOUNT_H
