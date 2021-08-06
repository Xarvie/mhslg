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
	//地图划分cell
	void MapInitCell();

	//0不可走 1可走
	int getGridTypeByPos(double x, double y);

	//点所在城池
	int getCityByPos(double x, double y);

	//点是否可传送
	int getTransferableByPos(double x, double y);

	//创建战场区域  (单位移动优先判断战场区域，再判断单位相遇。)
	int createBattleArea(int BattleId, double x, double y, double r);

	//创建玩家视野
	int createPlayerEye(int uid, double x, double y, double r);

	int createAI(int uid, double x, double y, double r);

	//退出战场进入地图。
	void unitTransferToBattle(int BattleId, int uid);
	void unitExitBattleToMap(int BattleId, int uid);
	//进入战场退出地图。

	//消息广播 战场区 玩家单位 AI位置
	//void moveBroadcast();

//
//	移动后callback
//	单位相遇callback
//	单位进入战场callback

	std::vector<std::thread*> workers;
};




#endif //MHSLG_MAP_MAPMGR_H
