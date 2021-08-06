// erl.cpp : Defines the entry point for the application.
//

#include <cstdint>
#include <iostream>
#include "Render.h"
#include "CxxProcess.h"


int unitLogin(int64_t SPID, int64_t unit, double x, double y) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}

int unitLogout(int64_t SPID, int64_t unit) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}

int unitMoveTo(int64_t SPID, int64_t unitId, double x, double y) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}

int setPlayerEyePos(int64_t SPID, int64_t playerId, double x, double y) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}

//初始化地图格子
int initMapGrid(int64_t SPID, int64_t playerId, double x, double y) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}

//初始化不可走区域
int initMapMoveableGrid(int64_t SPID, int64_t playerId, double x, double y) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}

//初始化城池点
int initCity(int64_t SPID, int64_t playerId, double x, double y) {
	CxxProcess *subProcess = (CxxProcess *) (SPID);
	return 0;
}


int init() {
	CxxProcess *subProcess = (CxxProcess *) malloc(sizeof(CxxProcess));
	subProcess->init();
	return 0;
}

int main() {
	int64_t subProcessId = init();
	auto *subProcess = (CxxProcess *) subProcessId;
	int kk = 15;

	std::string cmd = "";
	while (cmd != "quit") {
		std::cin >> cmd;
		if (cmd == "unitLogin") {
			unitLogin(subProcessId, kk, 0, 0);
		} else if (cmd == "unitLogout") {
			unitLogout(subProcessId, kk);
		} else if (cmd == "unitMoveTo") {
			unitLogout(subProcessId, kk);
		} else if (cmd == "setPlayerEyePos") {
			unitLogout(subProcessId, kk);
		} else if (cmd == "unitLogout") {
			unitLogout(subProcessId, kk);
		} else if (cmd == "unitLogout") {
			unitLogout(subProcessId, kk);
		} else if (cmd == "unitLogout") {
			unitLogout(subProcessId, kk);
		} else if (cmd == "unitLogout") {
			unitLogout(subProcessId, kk);
		}


	}
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return 0;
}