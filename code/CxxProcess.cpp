//
// Created by ftp on 8/2/2021.
//
#include <iostream>
#include "CxxProcess.h"
#include "Render.h"
#include "MapMgr.h"

 void CxxProcess::init()
{
	render = new Render;
	render->RenderInit();
	mapMgr = (MapMgr*)malloc(sizeof(MapMgr));

	std::cout << "Process(" << (void*)this << ").Process.init()" << std::endl;
}

void CxxProcess::destory(){
	std::cout << "Process(" << (void*)this << ").Process.destory()" << std::endl;
}