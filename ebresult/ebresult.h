//
// Created by LQYHE on 2021/5/7.
//

#pragma once

#include <string>
#include <utility>
#include <functional>
#include "fmt/format.h"
#define EBResult_EX( code, message, args...) eb_tools::EBResult<decltype(type),decltype(code)>(__FILE__,__func__,__LINE__,code,message,##args)
namespace eb_tools
{
class EBResult
{
public:
	EBResult();
	EBResult(int code);
	EBResult(int code, const std::string &message);
	template<typename ...Args>
	EBResult(int code, const std::string &fmt, const Args &...args);
	EBResult(const std::string &file_name,
	         const std::string &func_name,
	         int line,
	         int code,
	         const std::string &message);
	template<typename ...Args>
	EBResult(const std::string &file_name,
	         const std::string &func_name,
	         int line,
	         int code,
	         const std::string &fmt,
	         const Args &... args);
	EBResult(const EBResult &result);
	EBResult(EBResult &result);

	EBResult(EBResult &pre_result, int code);
	EBResult(EBResult &pre_result, int code, const std::string &message);
	template<typename ...Args>
	EBResult(EBResult &pre_result, int code, const std::string &fmt, const Args &...args);
	EBResult(EBResult &pre_result, const std::string &file_name,
	         const std::string &func_name,
	         int line,
	         int code,
	         const std::string &message);
	template<typename ...Args>
	EBResult(EBResult &pre_result, const std::string &file_name,
	         const std::string &func_name,
	         int line,
	         int code,
	         const std::string &fmt,
	         const Args &... args);
	EBResult(EBResult &pre_result, const EBResult &result);
public:

	void SetResultCode(int code);
	EBResult &WithResultCode(int code);
	int GetResultCode();

	void SetResultMessage(const std::string &message);
	EBResult &WithResultMessage(const std::string &message);
	template<typename ...Args>
	void SetResultMessage(const std::string &fmt, const Args &... args);
	template<typename ...Args>
	EBResult &WithResultMessage(const std::string &fmt, const Args &... args);
	std::string GetResultMessage();

	void SetResultFilename(const std::string &file_name);
	EBResult &WithResultFilename(const std::string &file_name);
	std::string GetResultFilename();

	void SetResultFuncname(const std::string &func_name);
	EBResult &WithResultFuncname(const std::string &func_name);
	std::string GetResultFuncname();

	void SetResultLine(int line);
	EBResult &WithResultLine(int line);
	int GetResultLine();

public:
	bool operator==(int code);
	bool operator==(const EBResult &result);
	EBResult &operator=(EBResult &&result);
	EBResult &operator=(const EBResult &result);
	explicit operator bool();

public:
	std::string What();
	static std::string
	DefaultMessageFormatter(int code, const std::string &message, int line, const std::string &file_name, const std::string &func_name, bool success);

private:
	void CopyImpl(const EBResult &result);
private:
	int m_result_code = 0;
	std::string m_message;
	int m_line = 0;
	std::string m_file_name;
	std::string m_func_name;
	bool m_success = true;
	std::shared_ptr<EBResult> m_pre_result = nullptr;
	std::function<std::string(int code, const std::string &message, int line, const std::string &file_name, const std::string &func_name, bool success)>
		m_func = DefaultMessageFormatter;
};
}

template<typename... Args>
eb_tools::EBResult::EBResult(eb_tools::EBResult &pre_result,
                             int code,
                             const std::string &fmt,
                             const Args &... args)
	:
	EBResult(code, fmt, args...)
{
	m_pre_result = std::make_shared<eb_tools::EBResult>(std::move(pre_result));
}

template<typename... Args>
eb_tools::EBResult::EBResult(eb_tools::EBResult &pre_result,
                             const std::string &file_name,
                             const std::string &func_name,
                             int line,

                             int code,
                             const std::string &fmt,
                             const Args &... args)
	:
	EBResult(file_name, func_name, line,  code, fmt, args...)
{
	m_pre_result = std::make_shared<eb_tools::EBResult>(std::move(pre_result));
}

template<typename... Args>
eb_tools::EBResult::EBResult(int code, const std::string &fmt, const Args &... args)
	:
	EBResult(code)
{
	m_message = fmt::format(fmt, args...);
}

template<typename... Args>
eb_tools::EBResult::EBResult(const std::string &file_name,
                             const std::string &func_name,
                             int line,
                             int code,
                             const std::string &fmt,
                             const Args &... args)
	:
	EBResult(code, nullptr)
{
	m_file_name = file_name;
	m_func_name = func_name;
	m_line = line;
	m_message = fmt::format(fmt, args...);
}

template<typename... Args>
void eb_tools::EBResult::SetResultMessage(const std::string &fmt, const Args &... args)
{
	m_message = fmt::format(fmt, args...);
}



template<typename... Args>
eb_tools::EBResult &eb_tools::EBResult::WithResultMessage(const std::string &fmt, const Args &... args)
{
	m_message = fmt::format(fmt, args...);
	return *this;
}
