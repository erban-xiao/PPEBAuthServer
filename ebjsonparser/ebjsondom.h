//
// Created by 二班 on 2020/11/9.
//

#ifndef EBJsoNDom_H
#define EBJsoNDom_H

#include <../ebexception/ebexception.h>
#include "rapidjson/document.h"
#include "ebjsonelement.h"
#include "../ebresult/ebresult.h"
#include "../ebresult/ebdata.h"
namespace eb_tools
{
	class EBJsoNDom
	{
	public:
		void Parse(const std::string& content);

		//Get one node
		EBJsonElement FindSubNode(const std::string& key, bool permit_null_node = false);

		//Get sub node value
		template<typename T>
		T GetSubNodeValue(const std::string& key, bool permit_null_node = false, const T& default_value = T());
		std::string GetSubNodeString(const std::string& key,
			bool permit_null_node = false,
			const std::string& default_value = std::string());
		long GetSubNodeLong(const std::string& key, bool permit_null_node = false, const long& default_value = 0);
		int GetSubNodeInt(const std::string& key, bool permit_null_node = false, const int& default_int = 0);
		//Get node value
		std::string GetString();
		long GetLong();
		int GetInt();
		template<typename T>
		T Get();

	private:
		rapidjson::Document m_doc;
	};
}

using namespace eb_tools;
template<typename T>
T EBJsoNDom::GetSubNodeValue(const std::string& key, bool permit_null_node, const T& default_value)
{
	try
	{
		if (m_doc.HasMember(key.c_str()))
		{
			auto node = &m_doc[key.c_str()];
			if (node->Is<T>())
			{
				return node->Get<T>();
			}
			else
			{
				throw EBException(
					EBResult(
						em_json_not_tar_type_node,
						"node is not target type :{0}", typeid(T))
				);
			}
		}
		else
		{
			throw EBException(
				EBResult(
					em_json_no_find_tar_node,
					"no find target node, key is : {0}", key
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

template<typename T>
T EBJsoNDom::Get()
{
	if (!m_doc.Is<T>())
	{
		throw EBException(
			EBResult(
				em_json_not_tar_type_node,
				"the dom node is not tar type node, type :{0}", typeid(T)
			)
		);
	}
	return m_doc.Get<T>();
}

#endif //EBJsoNDom_H
