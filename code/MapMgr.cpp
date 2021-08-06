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

void MapMgr::MapInitCell(){

}

//0不可走 1可走
int MapMgr::getGridTypeByPos(double x, double y){

}

//点所在城池
int MapMgr::getCityByPos(double x, double y){

}

//点是否可传送
int MapMgr::getTransferableByPos(double x, double y){

}

//创建战场区域  (单位移动优先判断战场区域，再判断单位相遇。)
int MapMgr::createBattleArea(int BattleId, double x, double y, double r){

}

//创建玩家视野
int MapMgr::createPlayerEye(int uid, double x, double y, double r){

}

int MapMgr::createAI(int uid, double x, double y, double r){

}

//退出战场进入地图。
void MapMgr::unitTransferToBattle(int BattleId, int uid){

}
void MapMgr::unitExitBattleToMap(int BattleId, int uid){

}