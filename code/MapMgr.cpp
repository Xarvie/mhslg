//
// Created by ftp on 8/3/2021.
//

#include "MapMgr.h"

void MapMgr::init()
{
	workers.emplace_back(
			[](){
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
			);
}