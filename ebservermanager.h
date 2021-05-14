//
// Created by LQYHE on 2021/5/12.
//

#ifndef EBSERVERMANAGER_H
#define EBSERVERMANAGER_H


#include <evpp/http/http_server.h>
#include "ebresult/ebdata.h"
#include "ebresult/ebresult.h"

typedef  evpp::http::Server EvppServer;

typedef std::function<void(evpp::EventLoop* loop,
                           const evpp::http::ContextPtr& ctx,
                           const evpp::http::HTTPSendResponseCallback& cb)> HttpRegHandle;
class EBServerManager
{
public:
	explicit EBServerManager();
//	eb_tools::EBResult AddListen(int thread_num,int port,const std::string& path,HttpRegHandle handle);
	bool AddListen(int thread_num,int port,const std::string& path,const HttpRegHandle& handle);
private:
	std::map<int,std::shared_ptr<EvppServer>> m_server_map;
};


#endif //EBSERVERMANAGER_H
