//
// Created by LQYHE on 2020/12/16.
//

#include "authenservice.h"
#include "third-party/ebcppframework/third-party/libgo/coroutine.h"
#include "third-party/ebcppframework/ebnetwork/ebservermanager.h"
eb_tools::EBResult<> AuthenService::Start()
{


	//init http listen
	eb_tools::EBServerManager serverManager;
	std::shared_ptr<eb_tools::EBHostInfo> hostInfo(new eb_tools::EBHostInfo);
	hostInfo->SetIpDomain("127.0.0.1");
	hostInfo->SetPort(1234);
	hostInfo->SetPort("/");
	serverManager.AddListen(hostInfo,"demo_host",1,[=]())
	//start
	co_sched.Start();
	return eb_tools::EBResult<>();
}
