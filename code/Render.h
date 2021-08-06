//
// Created by ftp on 8/2/2021.
//

#ifndef MHSLG_MAP_RENDER_H
#define MHSLG_MAP_RENDER_H

#include <thread>

class Render {
public:
	int RenderInit(void);
	std::thread* th;
	bool running;
};


#endif //MHSLG_MAP_RENDER_H
