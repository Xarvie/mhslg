//
// Created by ftp on 8/2/2021.
//
#include <iostream>
#include "Process.h"
#include "Render.h"
#include "MapMgr.h"

 void Process::init()
{
	render = new Render;
	render->RenderInit();
	mapMgr = (MapMgr*)malloc(sizeof(MapMgr));
	mapMgr->
	std::cout << "Process(" << (void*)this << ").Process.init()" << std::endl;
}

void Process::destory(){
	std::cout << "Process(" << (void*)this << ").Process.destory()" << std::endl;
}