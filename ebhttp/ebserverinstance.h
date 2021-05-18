//
// Created by LQYHE on 2021/5/18.
//

#ifndef EBSERVERINSTANCE_H
#define EBSERVERINSTANCE_H

#include <map>
#include <evpp/http/http_server.h>
#include "../ebresult/ebdata.h"
#include "../ebresult/ebresult.h"


typedef  evpp::http::Server EvppServer;
typedef std::function<void(evpp::EventLoop* loop,
                           const evpp::http::ContextPtr& ctx,
                           const evpp::http::HTTPSendResponseCallback& cb)> HttpRegHandle;



template<typename Req,typename Res>
class EBServerManagerImp
{
	friend class EBServerManager;
public:
	EBServerManagerImp():m_req(new Req),m_res(new Res){}
private:
	std::shared_ptr<Req> m_req;
	std::shared_ptr<Res> m_res;
};
class EBServerInstance
{
public:
	EBServerInstance(int thread_num,int port);
	int GetPort() const;
	void SetPort(int port);
	int GetThreadNum() const;
	void SetThreadNum(int thread_num);

	template<typename T>
	void AddListener(const std::string& path,std::function<void(std::shared_ptr<T>)>handle);
	bool Start();
private:
	int m_port = 0;
	int m_thread_num = 0;
	std::map<std::string,HttpRegHandle > m_handle_map;
	EvppServer m_evpp_server;
};
template<typename T>
void EBServerInstance::AddListener(const std::string &path, std::function<void( std::shared_ptr<T>)> handle)
{
	m_evpp_server.RegisterHandler(path,[handle](evpp::EventLoop* loop,
	                                           const evpp::http::ContextPtr& ctx,
	                                           const evpp::http::HTTPSendResponseCallback& cb){

		auto msg = std::make_shared<T>(ctx->original_uri());
		msg->SetFindReqHeaderCallback([ctx](const std::string& key)->std::string{
			return ctx->FindRequestHeader(key.c_str());
		});
		msg->SetResponse([ctx,cb](const eb_tools::EBResult& result,const std::map<std::string,std::string> response_header_map,const std::string& content){
			if(!result)
			{
				ctx->set_response_http_code(403);
				cb(result.What());
			}
			else
			{
				for(auto iter:response_header_map)
				{
					ctx->AddResponseHeader(iter.first,iter.second);
				}
				cb(content);
			}
		});
		handle(msg);
	});
}


#endif //EBSERVERINSTANCE_H
