// erl.cpp : Defines the entry point for the application.
//

#include <cstdint>
#include <iostream>
#include "Render.h"
#include "CxxProcess.h"


int unitLogin(int64_t SPID, int64_t uid, double x, double y) {
	CxxProcess* subProcess = (CxxProcess*)(SPID);
	return 0;
}

int unitLogout(int64_t SPID, int64_t y) {
    CxxProcess* subProcess = (CxxProcess*)(SPID);
	return 0;
}

int init() {
    CxxProcess* subProcess = (CxxProcess*)malloc(sizeof (CxxProcess));
	subProcess->init();
	return 0;
}

int main(){
	int64_t subProcessId = init();

	int kk = 15;
	unitLogin(subProcessId, 15, 0, 0);

	return 0;
}