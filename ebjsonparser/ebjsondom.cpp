//
// Created by 二班 on 2020/11/9.
//

#include "ebjsondom.h"
using namespace eb_tools;
using std::string;
void EBJsoNDom::Parse(const std::string& content)
{
	m_doc.Parse(content.c_str());
	if (!m_doc.IsObject())
	{
		throw EBException(EBResult<>(em_json_parser,
			em_parse_json_content_fail,
			"parse json content fail,content is not json format,content : {0},detail : {1}",
			content,
			m_doc.GetParseError()));
	}
	if (m_doc.HasParseError())
	{
		throw EBException(EBResult<>(em_json_parser,
			em_parse_json_content_fail,
			"parse json content fail,content : {0},detail : {1}",
			content,
			m_doc.GetParseError()));
	}
}

EBJsonElement EBJsoNDom::FindSubNode(const string& key, bool permit_null_node /*= false*/)
{
	EBJsonElement element;
	if (!m_doc.IsObject())
	{
		throw EBException(EBResult<>(em_json_parser, em_parse_json_no_find_tar_node, "no find target node,key:{0}", key));
	}
	if (m_doc.HasMember(key.c_str()))
	{
		element.m_node = &m_doc[key.c_str()];
	}
	else
	{
		if (permit_null_node)
		{
			return element;
		}
		else
			throw EBException(EBResult<>(em_json_parser, em_parse_json_no_find_tar_node, "no find target node,key:{0}", key));
	}
	return element;
}

std::string EBJsoNDom::GetString()
{
	if (m_doc.IsString())
	{
		return m_doc.GetString();
	}
	else
	{
		throw EBException(
			EBResult<>(em_json_parser,
				em_parse_json_not_string_node,
				"the dom node is not a string node")
		);
	}
}

long EBJsoNDom::GetLong()
{
	if (m_doc.IsInt64())
	{
		return m_doc.GetInt64();
	}
	else
	{
		throw EBException(
			EBResult<>(
				em_json_parser,
				em_parse_json_not_long_node,
				"the dom node is not a long node"
			)
		);
	}
}

int EBJsoNDom::GetInt()
{
	if (m_doc.IsInt())
	{
		return m_doc.GetInt();
	}
	else
	{
		throw EBException(
			EBResult<>(
				em_json_parser,
				em_parse_json_not_int_node,
				"the dom node is not a int node"
			)
		);
	}
}

std::string EBJsoNDom::GetSubNodeString(const string& key, bool permit_null_node /*= false*/, const string& default_value /*= std::string()*/)
{
	try
	{
		if (m_doc.HasMember(key.c_str()))
		{
			auto node = &m_doc[key.c_str()];
			if (node->IsString())
			{
				return node->GetString();
			}
			else
			{
				throw EBException(
					EBResult<>(
						em_json_parser,
						em_parse_json_not_string_node,
						"sub node is not a string node"
					)
				);
			}
		}
		else
		{
			throw EBException(
				EBResult<>(
					em_json_parser,
					em_parse_json_no_find_tar_node,
					"no find tar sub node,key : {0}", key
				)
			);
		}
	}
	catch (EBException& e)
	{
		if (permit_null_node)
		{
			return default_value;
		}
		else
		{
			throw e;
		}
	}
}

long EBJsoNDom::GetSubNodeLong(const string& key, bool permit_null_node, const long& default_value)
{
	try
	{
		if (!m_doc.HasMember(key.c_str()))
		{
			throw EBException(
				EBResult<>(
					em_json_parser,
					em_parse_json_no_find_tar_node,
					"no find target node, key is : {0}", key
				)
			);
		}
		auto node = &m_doc[key.c_str()];
		if (!node->IsInt64())
		{
			throw EBException(
				EBResult<>(
					em_json_parser,
					em_parse_json_not_long_node,
					"node is not long type")
			);
		}
		else
		{
			return node->GetInt64();
		}
	}
	catch (EBException& e)
	{
		if (permit_null_node)
		{
			return default_value;
		}
		else
		{
			throw e;
		}
	}
}

int EBJsoNDom::GetSubNodeInt(const string& key, bool permit_null_node, const int& default_int)
{
	try
	{
		if (!m_doc.HasMember(key.c_str()))
		{
			throw EBException(
				EBResult<>(
					em_json_parser,
					em_parse_json_no_find_tar_node,
					"no find target node, key is : {0}", key
				)
			);
		}
		auto node = &m_doc[key.c_str()];
		if (!node->IsInt())
		{
			throw EBException(
				EBResult<>(
					em_json_parser,
					em_parse_json_not_long_node,
					"node is not long type")
			);
		}
		else
		{
			return node->GetInt();
		}
	}
	catch (EBException& e)
	{
		if (permit_null_node)
		{
			return default_int;
		}
		else
		{
			throw e;
		}
	}
}



