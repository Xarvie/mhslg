// erl.cpp : Defines the entry point for the application.
//

#include <cstdint>
#include <iostream>
#include "Render.h"
#include "Process.h"


int unitLogin(int64_t SPID, int64_t uid, double x, double y) {
	Process* subProcess = (Process*)(SPID);
	return 0;
}

int unitLogout(int64_t SPID, int64_t y) {
	Process* subProcess = (Process*)(SPID);
	return 0;
}

int init() {
	Process* subProcess = (Process*)malloc(sizeof (Process));
	subProcess->init();
	return 0;
}

int main(){
	int64_t subProcessId = init();

	int kk = 15;
	unitLogin(subProcessId, 15, 0, 0);

	return 0;
}