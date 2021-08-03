//
// Created by ftp on 8/3/2021.
//

#ifndef MHSLG_MAP_MAPMGR_H
#define MHSLG_MAP_MAPMGR_H

#include <vector>
#include <thread>

class MapMgr {
public:
	MapMgr() = delete;
	~MapMgr() = delete;

	void init();
	std::vector<std::thread*> workers;
};


#endif //MHSLG_MAP_MAPMGR_H
