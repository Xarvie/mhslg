//
// Created by ftp on 8/3/2021.
//

#include "MapMgr.h"
#include <crtdefs.h>
#include <process.h>

void MapMgr::init()
{
    std::thread* t = new std::thread([](){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    });


    workers.emplace_back(t);
}