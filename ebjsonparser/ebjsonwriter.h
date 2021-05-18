//
// Created by 二班 on 2020/11/9.
//

#ifndef EBJSONWRITER_H
#define EBJSONWRITER_H


#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
namespace eb_tools {
    class EBJsonWriter {
    public:
        EBJsonWriter() : m_buffer(), m_writer(m_buffer) {}

        void StartObject() { m_writer.StartObject(); }

        void EndObject() { m_writer.EndObject(); }

        void StartArray() { m_writer.StartArray(); }

        void EndArray() { m_writer.EndArray(); }

        void InsertInt(const std::string &key, int value) {
            m_writer.Key(key.c_str());
            m_writer.Int(value);
        }

        void InsertLong(const std::string &key, long value) {
            m_writer.Key(key.c_str());
            m_writer.Int64(value);
        }

        void InsertString(const std::string &key, const std::string &value) {
            m_writer.Key(key.c_str());
            m_writer.String(value.c_str());
        }

        void InsertString(const std::string &value) { m_writer.String(value.c_str()); }

        void InsertBoolen(const std::string &key, bool value) {
            m_writer.Key(key.c_str());
            m_writer.Bool(value);
        }

        void InsertInt(int value) { m_writer.Int(value); }

        void InsertUint(unsigned int value) { m_writer.Uint(value); }

        void InsertLong(long value) { m_writer.Int64(value); }

        void InsertULong(unsigned long value) { m_writer.Uint64(value); }

        void InsertKey(const std::string &key) { m_writer.Key(key.c_str()); }

        std::string GetString() { return m_buffer.GetString(); }

    private:
        rapidjson::StringBuffer m_buffer{};
        rapidjson::Writer<rapidjson::StringBuffer> m_writer{};
    };

}
#endif //EBJSONWRITER_H
