//
// Created by qianyouliang on 2020/11/13.
//

#ifndef EB_EXCEPTION_EBEXCEPTION_H
#define EB_EXCEPTION_EBEXCEPTION_H


#include <exception>
#include <memory>
#include "../ebresult/ebresult.h"
namespace eb_tools {
    class EBException : public std::exception {
    public:
        EBException(const EBResult &result) {m_eb_result = std::make_shared<EBResult>(result);}
        std::string what()  _GLIBCXX_USE_NOEXCEPT  {return m_eb_result->What();}
        std::shared_ptr<EBResult> GetResult(){return m_eb_result;}
    private:
        std::shared_ptr<EBResult> m_eb_result;
    };
}
#endif //EB_EXCEPTION_EBEXCEPTION_H
