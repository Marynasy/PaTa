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
	void BeDamaged(int Damage);
	double GetAtk();//��ȡ��ǰ������
	double GetDef();//��ȡ��ǰ������
	int GetBaseAtkCoe();//��������ϵ��
	int GetExAtkCoe();//���⹥��ϵ��
	int GetFinalAtkCoe();//���չ���ϵ��
	int GetBaseDefCoe();//��������ϵ��
	int GetExDefCoe();//�������ϵ��
	int GetFinalDefCoe();//���չ���ϵ��
};
//��ҽ�ɫ

class Enemy
{
public:
	string Em_Name;
	int Em_Lv = 1;//Ĭ�ϵȼ�
	int Em_Exp = 0;//Ĭ�Ͼ���ֵ������ôҲ�о���ֵ����
	int Em_MaxHp = 100;//�������ֵ
	int Em_Hp = 100;//��������ֵ
	int Em_Atk = 10;//����������
	int Em_Def = 10;//����������
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
//¥��