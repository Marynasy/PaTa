#include<iostream>
#include<string>
using namespace std;

class Skill
{

};
//技能，日后补充

class Player
{
public:
	string Pl_Name;//玩家角色的名字
	int Pl_Lv = 1;//初始等级
	int Pl_Exp = 0;//初期经验值
	int Pl_UExp = 95 + 5 * Pl_Lv;//升级所需经验
	int Pl_Point = 0;//属性点
	int Pl_BaseMaxHp = 100;//基础最大生命
	int Pl_ExMaxHp = 0;//额外的最大生命
	int Pl_MaxHp = Pl_BaseMaxHp + Pl_ExMaxHp;//实际最大生命
	int Pl_Hp = Pl_MaxHp;//当前的生命值，归0会导致游戏结束
	int Pl_BaseAtk = 10;//基础攻击力
	int Pl_ExAtk = 0;//额外攻击力
	int Pl_Atk = Pl_BaseAtk + Pl_ExAtk;//实际攻击力
	int Pl_BaseDef = 10;//基础防御力
	int Pl_ExDef = 0;//额外防御力
	int Pl_Def = Pl_BaseDef + Pl_ExDef;//实际防御力
	enum {Normal=1,Easy,Hard} Pl_Difficult = Normal;//通过枚举定义难度。
	void CharaNameSet();
	void CharaDiffcultSet();
	void StateMenu();
};
//玩家角色

class Enemy
{
public:
	string Em_Name;
	int Em_Lv;
	int Em_Exp;
	int Em_MaxHp;
	int Em_Hp;
	int Em_Atk;
	int Em_Def;
};

class EnemyBooks
{
	class Enemy enemyArrs[5];
	int Em_Num = 0;
};

class Floor
{
public:
	int FloorNum = 0;
};
//楼层