//
// Created by LQYHE on 2021/5/14.
//

#include "ebresult.h"


eb_tools::EBResult::EBResult()
	: m_result_code(0)
{
}

eb_tools::EBResult::EBResult(int code)
	:
	m_result_code(code),
	m_success(false)
{

}

eb_tools::EBResult::EBResult(int code, const std::string &message)
	:
	m_result_code(code),
	m_message(message),
	m_success(false)
{
}

eb_tools::EBResult::EBResult(
	const std::string &file_name,
	const std::string &func_name,
	int line,
	int code,
	const std::string &message)
	:
	EBResult(code, message)
{
	m_file_name = file_name;
	m_func_name = func_name;
	m_line = line;
}


eb_tools::EBResult::EBResult(const eb_tools::EBResult &result)
{
	CopyImpl(result);
}

eb_tools::EBResult::EBResult(eb_tools::EBResult &result)
{
	CopyImpl(result);
}

void eb_tools::EBResult::CopyImpl(const EBResult &result)
{
	m_result_code = result.m_result_code;
	m_message = result.m_message;
	m_file_name = result.m_file_name;
	m_func_name = result.m_func_name;
	m_line = result.m_line;
}

eb_tools::EBResult::EBResult(eb_tools::EBResult &pre_result, int code)
	:
	EBResult(code)
{
	m_pre_result = std::make_shared<eb_tools::EBResult>(std::move(pre_result));
}

eb_tools::EBResult::EBResult(eb_tools::EBResult &pre_result, int code, const std::string &message)
	:
	EBResult(code, message)
{
	m_pre_result = std::make_shared<eb_tools::EBResult>(std::move(pre_result));
}



eb_tools::EBResult::EBResult(eb_tools::EBResult &pre_result,
                             const std::string &file_name,
                             const std::string &func_name,
                             int line,

                             int code,
                             const std::string &message)
	:
	EBResult(file_name, func_name, line,  code, message)
{
	m_pre_result = std::make_shared<eb_tools::EBResult>(std::move(pre_result));
}



eb_tools::EBResult::EBResult(eb_tools::EBResult &pre_result, const eb_tools::EBResult &result)
	:
	EBResult(result)
{
	m_pre_result = std::make_shared<eb_tools::EBResult>(std::move(pre_result));
}


void eb_tools::EBResult::SetResultCode(int code)
{
	m_result_code = code;
}

eb_tools::EBResult &eb_tools::EBResult::WithResultCode(int code)
{
	m_result_code = code;
	return *this;
}

int eb_tools::EBResult::GetResultCode()
{
	return m_result_code;
}

void eb_tools::EBResult::SetResultMessage(const std::string &message)
{
	m_message = message;
}

eb_tools::EBResult &eb_tools::EBResult::WithResultMessage(const std::string &message)
{
	m_message = message;
	return *this;
}

std::string eb_tools::EBResult::GetResultMessage()
{
	return m_message;
}

void eb_tools::EBResult::SetResultFilename(const std::string &file_name)
{
	m_file_name = file_name;
}

eb_tools::EBResult &eb_tools::EBResult::WithResultFilename(const std::string &file_name)
{
	m_file_name = file_name;
	return *this;
}

std::string eb_tools::EBResult::GetResultFilename()
{
	return m_file_name;
}

void eb_tools::EBResult::SetResultFuncname(const std::string &func_name)
{
	m_func_name = func_name;
}

eb_tools::EBResult &eb_tools::EBResult::WithResultFuncname(const std::string &func_name)
{
	m_func_name = func_name;
	return *this;
}

std::string eb_tools::EBResult::GetResultFuncname()
{
	return m_func_name;
}

void eb_tools::EBResult::SetResultLine(int line)
{
	m_line = line;
}

eb_tools::EBResult &eb_tools::EBResult::WithResultLine(int line)
{
	m_line = line;
	return *this;
}

int eb_tools::EBResult::GetResultLine()
{
	return m_line;
}

bool eb_tools::EBResult::operator==(int code)
{
	return m_result_code == code;
}

bool eb_tools::EBResult::operator==(const eb_tools::EBResult &result)
{
	return (this->m_success == result.m_success &&  this->m_result_code == result.m_result_code);
}

eb_tools::EBResult &eb_tools::EBResult::operator=(eb_tools::EBResult &&result)
{
	if (result.m_success)
	{
		this->m_success = result.m_success;
	}
	else
	{
		this->m_result_code = result.m_result_code;
		result.m_result_code = int();
		this->m_message = std::move(result.m_message);
		this->m_file_name = std::move(result.m_file_name);
		this->m_func_name = std::move(result.m_func_name);
		this->m_line = result.m_line;
		result.m_line = 0;
	}
	return *this;
}

eb_tools::EBResult &eb_tools::EBResult::operator=(const eb_tools::EBResult &result)
{
	if (result.m_success)
	{
		this->m_success = result.m_success;
	}
	else
	{
		this->m_result_code = result.m_result_code;
		this->m_message = result.m_message;
		this->m_file_name = result.m_file_name;
		this->m_func_name = result.m_func_name;
		this->m_line = result.m_line;
	}
	return *this;
}

eb_tools::EBResult::operator bool()
{
	return m_success;
}

std::string eb_tools::EBResult::What()
{
	if (m_success)
	{
		return "Success";
	}
	else
	{
		std::string result;
		if (m_pre_result)
		{
			result = m_pre_result->What();
		}
		return result + m_func(m_result_code, m_message, m_line, m_file_name, m_func_name, m_success);
	}
}

std::string eb_tools::EBResult::DefaultMessageFormatter(
	int code,
	const std::string &message,
	int line,
	const std::string &file_name,
	const std::string &func_name,
	bool success)
{
	if (success)
	{
		return fmt::format("result is success");
	}
	else
	{
		std::string format = fmt::format(
			"result is fail \n"
			"code is      : {0} \n"
			"message is   : {1} \n"
			"file_name is : {2} \n"
			"func_name is : {3} \n"
			"line is      : {4} \n",

			code,
			message,
			file_name,
			func_name,
			line);
		return format;
	}
}


