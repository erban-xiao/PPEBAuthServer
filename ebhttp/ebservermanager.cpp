//
// Created by LQYHE on 2021/5/12.
//

#include "ebservermanager.h"

using eb_tools::ResultCode;
//using eb_tools::EBResult;


//eb_tools::EBResult EBServerManager::AddListen(int thread_num, int port, const std::string &path, HttpRegHandle handle)
//{
//	if (thread_num <= 0)
//	{
//		return eb_tools::EBResult(ResultCode::em_result_err_thread, "err thread num:{0}", thread_num);
//	}
//
//	if (port <= 0)
//	{
//		return eb_tools::EBResult(ResultCode::em_result_err_port, "err port:{0}", port);
//	}
//
//	std::shared_ptr<EvppServer> evpp_server;
//	auto iter = m_server_map.find(port);
//	if (iter == m_server_map.end())
//	{
//		evpp_server = std::make_shared<EvppServer>(thread_num);
//	}
//	else
//	{
//		evpp_server = iter->second;
//	}
//
//
//	evpp_server->Init(port);
//	evpp_server->RegisterHandler(path,
//	                             handle);
//	if(evpp_server->Start())
//	{
//		printf("start port success:%d\n",port);
//	}
//	else
//	{
//		printf("start port fail:%d\n",port);
//	}
//
//	return eb_tools::EBResult();
//}


//bool EBServerManager::AddListen(int thread_num, int port, const std::string &path, const HttpRegHandle& handle)
//{
//	if (thread_num < 0)
//	{
//		return false;
//	}
//
//	if (port <= 0)
//	{
//		return false;
//	}
//
//	std::shared_ptr<EvppServer> evpp_server;
//	auto iter = m_server_map.find(port);
//	if (iter == m_server_map.end())
//	{
//		evpp_server = std::make_shared<EvppServer>(thread_num);
//		m_server_map.emplace(port,evpp_server);
//	}
//	else
//	{
//		evpp_server = iter->second;
//	}
//
//	evpp_server->Init(port);
//	evpp_server->RegisterHandler(path,
//	                             handle);
//	if(evpp_server->Start())
//	{
//		printf("start port success:%d\n",port);
//	}
//	else
//	{
//		printf("start port fail:%d\n",port);
//	}
//	return true;
//}
//
//bool EBServerManager::AddListen(int thread_num, int port, const std::map<std::string , HttpRegHandle>& handle_map )
//{
//
//	if (thread_num < 0)
//	{
//		return false;
//	}
//
//	if (port <= 0)
//	{
//		return false;
//	}
//
//	std::shared_ptr<EvppServer> evpp_server;
//	auto iter = m_server_map.find(port);
//	if (iter == m_server_map.end())
//	{
//		evpp_server = std::make_shared<EvppServer>(thread_num);
//		m_server_map.emplace(port,evpp_server);
//	}
//	else
//	{
//		evpp_server = iter->second;
//	}
//
//	evpp_server->Init(port);
//	for(const auto& iter : handle_map)
//	{
//		evpp_server->RegisterHandler(iter.first,iter.second);
//	}
//
//
//	return true;
//}
//template<typename req, typename res>
//bool EBServerManager::AddListen(int thread_num, int port, const std::map<std::string, EBServerManagerImp<req, res>> handle)
//{
//
//	return 0;
//}
//bool EBServerManager::Start()
//{
//
//	if(evpp_server->Start())
//	{
//		printf("start port success:%d\n",port);
//	}
//	else
//	{
//		printf("start port fail:%d\n",port);
//	}
//	return false;
//}
std::shared_ptr<EBServerInstance> EBServerManager::CreateServerListen(int thread_num, int port)
{
	std::shared_ptr<EBServerInstance> instance(new EBServerInstance(thread_num,port));
	return instance;
}
