//
// Created by LQYHE on 2021/5/18.
//

#include "ebserverinstance.h"
int EBServerInstance::GetPort() const
{
	return m_port;
}
void EBServerInstance::SetPort(int port)
{
	m_port = port;
}
int EBServerInstance::GetThreadNum() const
{
	return m_thread_num;
}
void EBServerInstance::SetThreadNum(int thread_num)
{
	m_thread_num = thread_num;
}

bool EBServerInstance::Start()
{
	m_evpp_server.Init(m_port);
	m_evpp_server.Start();
	return true;
}
EBServerInstance::EBServerInstance(int thread_num, int port): m_evpp_server(thread_num),m_thread_num(thread_num),m_port(port)
{
}
