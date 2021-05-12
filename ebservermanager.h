//
// Created by LQYHE on 2021/5/12.
//

#ifndef EBSERVERMANAGER_H
#define EBSERVERMANAGER_H


#include <evpp/http/http_server.h>
#include "ebresult/ebresult.h"
using eb_tools::EBResult;

class EBServerManager
{
public:
	explicit EBServerManager(int thread_num);
	EBResult Init();
private:
	evpp::http::Server m_server;
	int m_thread_num = 0;
};


#endif //EBSERVERMANAGER_H
