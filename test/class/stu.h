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
	void BeDamaged(int Damage);
	double GetAtk();//获取当前攻击力
	double GetDef();//获取当前防御力
	int GetBaseAtkCoe();//基础攻击系数
	int GetExAtkCoe();//额外攻击系数
	int GetFinalAtkCoe();//最终攻击系数
	int GetBaseDefCoe();//基础防御系数
	int GetExDefCoe();//额外防御系数
	int GetFinalDefCoe();//最终攻击系数
};
//玩家角色

class Enemy
{
public:
	string Em_Name;
	int Em_Lv = 1;//默认等级
	int Em_Exp = 0;//默认经验值？怪怎么也有经验值？？
	int Em_MaxHp = 100;//最大生命值
	int Em_Hp = 100;//现有生命值
	int Em_Atk = 10;//基础攻击力
	int Em_Def = 10;//基础防御力
	void BeDamaged(int Damage);
	double GetAtk();
	double GetDef();
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
	int TurnNum = 1;
	int FloorDmg = 0;
	int EnterFight(Player abs,Enemy E_abs);
	int PlTryAtk(Player abs, Enemy E_abs);
	int EmTryAtk(Player abs, Enemy E_abs);
};
//楼层