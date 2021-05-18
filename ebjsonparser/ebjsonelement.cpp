//
// Created by 二班 on 2020/11/9.
//

#include "ebjsonelement.h"
#include "../ebresult/ebdata.h"
#include "../ebresult/ebresult.h"
#include "../ebexception/ebexception.h"
using namespace eb_tools;
EBJsonElement EBJsonElement::FindSubNode(const std::string &key, bool permit_null_node)
{
    EBJsonElement element;
    if (!m_node) {
        throw EBException(
            EBResult(
	            em_parse_no_node,
                "not find cur node"
            )
        );
    }
    if (m_node->IsObject() && m_node->HasMember(key.c_str())) {
        element.m_node = &(*m_node)[key.c_str()];
    }
    else {
        if (permit_null_node) {
        }
        else {
            throw EBException(
                EBResult(
                    em_json_no_find_tar_node,
                    "not find target sub node ,key: {0}", key
                )
            );
        }
    }
    return element;
}

size_t EBJsonElement::GetArrayCount()
{
    if (!m_node) {
        throw EBException(
            EBResult(
                em_parse_no_node,
                "not find cur node"
            )
        );
    }
    if (!m_node->IsArray()) {
        throw EBException(
            EBResult(
	            em_json_not_array_node,
	            "json node not array node"
            )
        );
    }
    return m_node->Size();
}

std::string EBJsonElement::GetSubNodeString(const std::string &key, bool permit_null_node, const std::string &default_value)
{

    try {
        if (!m_node) {
            throw EBException(
                EBResult(
                    em_parse_no_node,
                    "no find cur node"
                )
            );
        }
        if (!m_node->HasMember(key.c_str())) {
            throw EBException(
                EBResult(
	                em_json_no_find_tar_node,
	                "no find target node, key is : {0}", key
                )
            );
        }
        auto node = &(*m_node)[key.c_str()];
        if (!node->IsString()) {
            throw EBException(
                EBResult(
	                em_json_not_string_node,
	                "node is not string type")
            );
        }
        else {
            return node->GetString();
        }
    }
    catch (EBException &e) {
        if (permit_null_node) {
            return default_value;
        }
        else {
            throw e;
        }

    }
}

long EBJsonElement::GetSubNodeLong(const std::string &key, bool permit_null_node, const long &default_value)
{
    try {
        if (!m_node) {
            throw EBException(
                EBResult(
                    em_parse_no_node,
                    "no find cur node"
                )
            );
        }
        if (!m_node->HasMember(key.c_str())) {
            throw EBException(
                EBResult(
	                em_json_no_find_tar_node,
	                "no find target node, key is : {0}", key
                )
            );
        }
        auto node = &(*m_node)[key.c_str()];
        if (!node->IsInt64()) {
            throw EBException(
                EBResult(
	                em_json_not_long_node,
	                "node is not long type")
            );
        }
        else {
            return node->GetInt64();
        }
    }
    catch (EBException &e) {
        if (permit_null_node) {
            return default_value;
        }
        else {
            throw e;
        }
    }
}

int EBJsonElement::GetSubNodeInt(const std::string &key, bool permit_null_node, const int &default_value)
{
    try {
        if (!m_node) {
            throw EBException(
                EBResult(
                    em_parse_no_node,
                    "no find cur node"
                )
            );
        }
        if (!m_node->HasMember(key.c_str())) {
            throw EBException(
                EBResult(
	                em_json_no_find_tar_node,
	                "no find target node, key is : {0}", key
                )
            );
        }
        auto node = &(*m_node)[key.c_str()];
        if (!node->IsInt()) {
            throw EBException(
                EBResult(
	                em_json_not_long_node,
	                "node is not long type")
            );
        }
        else {
            return node->GetInt();
        }
    }
    catch (EBException &e) {
        if (permit_null_node) {
            return default_value;
        }
        else {
            throw e;
        }
    }
}
EBJsonElement EBJsonElement::operator[](size_t index)
{
    if (!m_node) {
        throw EBException(
            EBResult(
                em_parse_no_node,
                "not find cur node"
            )
        );
    }
    if (!m_node->IsArray()) {
        throw EBException(
            EBResult(
	            em_json_not_array_node,
	            "json node not array node"
            )
        );
    }
    if (index >= m_node->Size()) {
        throw EBException(
            EBResult(
	            em_json_array_index_overspill,
	            "index over spill,size is : {0},index is {0}", m_node->Size(), index
            )
        );
    }
    EBJsonElement element;
    element.m_node = &(*m_node)[index];
    return element;
}
EBJsonElement EBJsonElement::operator[](size_t index) const
{
    if (!m_node) {
        throw EBException(
            EBResult(
                em_parse_no_node,
                "not find cur node"
            )
        );
    }
    if (!m_node->IsArray()) {
        throw EBException(
            EBResult(
	            em_json_not_array_node,
	            "json node not array node"
            )
        );
    }
    if (index >= m_node->Size()) {
        throw EBException(
            EBResult(
	            em_json_array_index_overspill,
	            "index over spill,size is : {0},index is {0}", m_node->Size(), index
            )
        );
    }
    EBJsonElement element;
    element.m_node = &(*m_node)[index];
    return element;
}
