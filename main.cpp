//
// Created by LQYHE on 2020/12/15.
//

#include <iostream>
#include "authenservice.h"

int main(int argc, char* argv[])
{
    std::cout<<"argc : "<<argc << std::endl;
    for(int i = 0; i< argc;++i)
    {
        std::cout<<"argv["<<i<<"] : "<<argv[i]<<std::endl;
    }

	AuthenService authenService;
    authenService.Start();
    return 0;
}