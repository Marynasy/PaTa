#include<iostream>
#include<string>
using namespace std;

class Skill
{

};
//���ܣ��պ󲹳�

class Player
{
public:
	string Pl_Name;//��ҽ�ɫ������
	int Pl_Lv = 1;//��ʼ�ȼ�
	int Pl_Exp = 0;//���ھ���ֵ
	int Pl_UExp = 95 + 5 * Pl_Lv;//�������辭��
	int Pl_Point = 0;//���Ե�
	int Pl_BaseMaxHp = 100;//�����������
	int Pl_ExMaxHp = 0;//������������
	int Pl_MaxHp = Pl_BaseMaxHp + Pl_ExMaxHp;//ʵ���������
	int Pl_Hp = Pl_MaxHp;//��ǰ������ֵ����0�ᵼ����Ϸ����
	int Pl_BaseAtk = 10;//����������
	int Pl_ExAtk = 0;//���⹥����
	int Pl_Atk = Pl_BaseAtk + Pl_ExAtk;//ʵ�ʹ�����
	int Pl_BaseDef = 10;//����������
	int Pl_ExDef = 0;//���������
	int Pl_Def = Pl_BaseDef + Pl_ExDef;//ʵ�ʷ�����
	enum {Normal=1,Easy,Hard} Pl_Difficult = Normal;//ͨ��ö�ٶ����Ѷȡ�
	void CharaNameSet();
	void CharaDiffcultSet();
	void StateMenu();
};
//��ҽ�ɫ

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
//¥��