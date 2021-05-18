//
// Created by LQYHE on 2020/12/15.
//

#include <iostream>
#include <queue>
#include "ebresult/ebresult.h"
#include "ebhttp/ebservermanager.h"
#include "libco/co_routine.h"


using namespace std;
struct stTask_t
{
	int id;
};
struct stEnv_t
{
	stCoCond_t* cond;
	queue<stTask_t*> task_queue;
};
void* Producer(void* args)
{
	co_enable_hook_sys();
	stEnv_t* env=  (stEnv_t*)args;
	int id = 0;
	while (true)
	{
		stTask_t* task = (stTask_t*)calloc(1, sizeof(stTask_t));
		task->id = id++;
		env->task_queue.push(task);
		printf("%s:%d produce task %d\n", __func__, __LINE__, task->id);
		co_cond_signal(env->cond);
		poll(NULL, 0, 1000);
	}
	return NULL;
}
void* Consumer(void* args)
{
	co_enable_hook_sys();
	stEnv_t* env = (stEnv_t*)args;
	while (true)
	{
		if (env->task_queue.empty())
		{
			co_cond_timedwait(env->cond, -1);
			continue;
		}
		stTask_t* task = env->task_queue.front();
		env->task_queue.pop();
		printf("%s:%d consume task %d\n", __func__, __LINE__, task->id);
		free(task);
	}
	return NULL;
}



int main(int argc, char *argv[])
{
#if 1
	EBServerManager server_manager;
	auto instance = server_manager.CreateServerListen(0,1234);
//	instance->AddListener("/echo",)
//	instance->AddListener()
//	instance->Start();
#else
	evpp::http::Server server_1(1);
	{
		std::vector<int> ports = { 1234};
		int thread_num = 2;
		server_1.RegisterHandler("/echo",
								 [](evpp::EventLoop* loop,
								  const evpp::http::ContextPtr& ctx,
								  const evpp::http::HTTPSendResponseCallback& cb) {
								   std::cout<<"get message"<<std::endl;
								   cb(ctx->body().ToString()); }
		);
		server_1.Init(ports);
		server_1.Start();
	}
	evpp::http::Server server_2(1);
	{
		std::vector<int> ports = {4321 };
		int thread_num = 2;
		server_2.RegisterHandler("/path",
								 [](evpp::EventLoop* loop,
								  const evpp::http::ContextPtr& ctx,
								  const evpp::http::HTTPSendResponseCallback& cb) {
								   std::cout<<"get message"<<std::endl;
								   cb(ctx->body().ToString()); }
		);
		server_2.Init(ports);
		server_2.Start();
	}
#endif

//	stEnv_t* env = new stEnv_t;
//	env->cond = co_cond_alloc();
//
//
//	stCoRoutine_t* consumer_routine;
//	co_create(&consumer_routine, NULL, Consumer, env);
//	co_resume(consumer_routine);
//
//	stCoRoutine_t* producer_routine;
//	co_create(&producer_routine, NULL, Producer, env);
//	co_resume(producer_routine);
//
//	co_eventloop(co_get_epoll_ct(), NULL, NULL);

	while (true)
	{
		usleep(1);
	}
	return 0;
}