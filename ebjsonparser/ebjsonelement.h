//
// Created by 二班 on 2020/11/9.
//

#ifndef EBJSONELEMENT_H
#define EBJSONELEMENT_H

#include <string>
#include <ebresult/ebdata.h>
#include <ebresult/ebresult.h>
#include <ebexception/ebexception.h>
#include "third-party/rapidjson/document.h"
namespace eb_tools
{
class EBJsonElement
{
    friend class EBJsoNDom;

public:
    //Get one node
    EBJsonElement FindSubNode(const std::string &key, bool permit_null_node = false);

    // analysis array
    size_t GetArrayCount();

    //Get sub node value
    //there is has problem about get std::string
    template<typename T>
    T GetSubNodeValue(const std::string &key, bool permit_null_node = false, const T &default_value = T());

    std::string GetSubNodeString(const std::string &key, bool permit_null_node = false,
                                 const std::string &default_value = std::string());

    long GetSubNodeLong(const std::string &key, bool permit_null_node = false, const long &default_value = 0);

    int GetSubNodeInt(const std::string &key, bool permit_null_node = false, const int &default_int = 0);

    //Get node value
    template<typename T>
    T Get();

public:
    EBJsonElement operator[](size_t index);

    EBJsonElement operator[](size_t index) const;

    explicit operator bool() const noexcept
    { return m_node != nullptr; }

private:
    rapidjson::Value *m_node = nullptr;
};

template<typename T>
T EBJsonElement::GetSubNodeValue(const std::string &key, bool permit_null_node, const T &default_value)
{
    try {
        if (!m_node) {
            throw EBException(
                EBResult<>(
                    em_json_parser,
                    em_parse_no_node,
                    "not find cur node"
                )
            );
        }
        if (!m_node->HasMember(key.c_str())) {
            throw EBException(
                EBResult<>(
                    em_json_parser,
                    em_parse_json_no_find_tar_node,
                    "no find target node, key is : {0}", key
                )
            );
        }
        auto node = &(*m_node)[key.c_str()];
        if (!node->Is<T>()) {
            throw EBException(
                EBResult<>(
                    em_json_parser,
                    em_parse_json_not_tar_type_node,
                    "node is not target type :{0}", typeid(T).name())
            );
        }
        return m_node->Get<T>();
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

template<typename T>
T EBJsonElement::Get()
{
    if (!m_node) {
        throw EBException(
            EBResult<>(
                em_json_parser,
                em_parse_no_node,
                "not find cur node"
            )
        );
    }
    if (!m_node->Is<T>()) {
        throw EBException(
            EBResult<>(
                em_json_parser,
                em_parse_json_not_tar_type_node,
                "node is not target type :{0}", typeid(T).name())
        );
    }
    return m_node->Get<T>();
}

}
#endif //EBJSONELEMENT_H
