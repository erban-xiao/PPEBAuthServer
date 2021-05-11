//
// Created by LQYHE on 2021/5/11.
//

#include <vector>
#include <unistd.h>
#include "evpp/http/http_server.h"
int main(int argc,char* argv[])
{
	std::vector<int> ports = { 9009, 23456, 23457 };
	int thread_num = 2;
	evpp::http::Server server(thread_num);
	server.RegisterHandler("/echo",
	                       [](evpp::EventLoop* loop,
	                          const evpp::http::ContextPtr& ctx,
	                          const evpp::http::HTTPSendResponseCallback& cb) {
		                       cb(ctx->body().ToString()); }
	);
	server.Init(ports);
	server.Start();
	while (!server.IsStopped()) {
		usleep(1);
	}
	return 0;
}