//
// Created by ftp on 8/2/2021.
//

#ifndef MHSLG_MAP_PROCESS_H
#define MHSLG_MAP_PROCESS_H

class Render;
class MapMgr;
class Process {
public:
	Process() = delete;
	~Process() = delete;
	void init();
	void destory();
public:
	int a;
	int b;
	Render* render;
	MapMgr* mapMgr;
};


#endif //MHSLG_MAP_PROCESS_H
