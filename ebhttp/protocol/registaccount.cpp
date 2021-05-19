//
// Created by LQYHE on 2021/5/18.
//

#include <ebjsonparser/ebjsondom.h>
#include "registaccount.h"
void RegistAccount::FromProtocol(const std::string &path, const std::string &content)
{
	eb_tools::EBJsoNDom dom;
	dom.Parse(content);
	m_account = dom.GetSubNodeString("account");
	m_password = dom.GetSubNodeString("password");
	auto account_type = dom.GetSubNodeString("account-type");
	if(account_type == "tel")
	{
		m_account_type = AccountType::em_phone;
	}
	else if(account_type == "eml")
	{
		m_account_type = AccountType::em_email;
	}
	else
	{
		throw eb_tools::EBException(eb_tools::EBResult(em_reg_err_account_type,"err account-type:{0},only tel or eml is legal",account_type));
	}

}
std::string RegistAccount::ToProtocol()
{
	//https://blog.csdn.net/wmdkanh/article/details/105523102    发号器研究
	return std::string();
}
AccountType RegistAccount::GetAccountType() const
{
	return m_account_type;
}
void RegistAccount::SetAccountType(AccountType account_type)
{
	m_account_type = account_type;
}
const std::string &RegistAccount::GetAccount() const
{
	return m_account;
}
void RegistAccount::SetAccount(const std::string &account)
{
	m_account = account;
}
const std::string &RegistAccount::GetPassword() const
{
	return m_password;
}
void RegistAccount::SetPassword(const std::string &password)
{
	m_password = password;
}
const std::string &RegistAccount::GetSession() const
{
	return m_session;
}
void RegistAccount::SetSession(const std::string &session)
{
	m_session = session;
}
