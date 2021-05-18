//
// Created by LQYHE on 2021/5/12.
//

#ifndef EBSERVERMANAGER_H
#define EBSERVERMANAGER_H



#include "ebserverinstance.h"




class EBServerManager
{
public:
	std::shared_ptr<EBServerInstance> CreateServerListen(int thread_num,int port);


private:
	std::map<int,std::shared_ptr<EBServerInstance>> m_server_map;
};


#endif //EBSERVERMANAGER_H
