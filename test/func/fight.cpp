#include "../class/fight.h"

int Player::GetBaseAtkCoe()
{
  int BaseAtkCoe = 100;
  return BaseAtkCoe;
}

int Player::GetExAtkCoe()
{
  int BaseAtkCoe = 100;
  return BaseAtkCoe;
}

int Player::GetFinalAtkCoe()
{
  int BaseAtkCoe = 100;
  return BaseAtkCoe;
}

int Player::GetBaseDefCoe()
{
  int BaseAtkCoe = 100;
  return BaseAtkCoe;
}

int Player::GetExDefCoe()
{
  int BaseAtkCoe = 100;
  return BaseAtkCoe;
}

int Player::GetFinalDefCoe()
{
  int BaseAtkCoe = 100;
  return BaseAtkCoe;
}

double Player::GetAtk()
{
  double Attack;
  int BaseAtkCoe = GetBaseAtkCoe();//Ŀǰû��
  int ExAtkCoe = GetExAtkCoe();//Ŀǰû��
  int FinalAtkCoe = GetFinalAtkCoe();//Ŀǰû��
  Attack = (Pl_BaseAtk*BaseAtkCoe + Pl_ExAtk*ExAtkCoe)*FinalAtkCoe/10000;
  return Attack;
}


double Player::GetDef()
{
  double Defence;
  int BaseDefCoe = GetBaseDefCoe();//Ŀǰû��
  int ExDefCoe = GetExDefCoe();//Ŀǰû��
  int FinalDefCoe = GetFinalDefCoe();//Ŀǰû��
  Defence = (Pl_BaseDef*BaseDefCoe + Pl_ExDef*ExDefCoe)*FinalDefCoe/10000;
  return Defence;
}

void Player::BeDamaged(int Damage)
{
  this->Pl_Hp = Pl_Hp-Damage;
}


double Enemy::GetAtk()
{
  double Attack;
  Attack = Em_Atk;
  return Attack;
}


double Enemy::GetDef()
{
  double Defence;
  Defence = Em_Def;
  return Defence;
}

void Enemy::BeDamaged(int Damage)
{
  this->Em_Hp = Em_Hp-Damage;
}

int Floor::PlTryAtk(Player abs,Enemy E_abs)
{
  int Attack = (int)abs.GetAtk();
  int Defence = (int)E_abs.GetDef();  
  int Damage = 0;
  if(TurnNum >= 5)
  {
    Damage = Attack-Defence+(TurnNum-4)*10;
  }
  else
  {
    Damage = Attack-Defence;
  }
  if(Damage>0)
  {
	  cout << abs.Pl_Name << "��" << E_abs.Em_Name <<  "�����" << Damage << "���˺���" << endl;
    return Damage;
  }
  else
  {
	  cout << "û������˺���" << endl;
    return 0;
  }
}

int Floor::EmTryAtk(Player abs,Enemy E_abs)
{
  int Attack = (int)E_abs.GetAtk();
  int Defence = (int)abs.GetDef();
  int Damage = 0;
  if(TurnNum >= 5)
  {
    Damage = Attack-Defence+(TurnNum-4)*10;
  }
  else
  {
    Damage = Attack-Defence;
  }
  if(Damage>0)
  {
	  cout << E_abs.Em_Name << "��" << abs.Pl_Name <<  "�����" << Damage << "���˺���" << endl;
    return Damage;
  }
  else
  {
	  cout << "û������˺���" << endl;
    return 0;
  }
}

int Floor::EnterFight(Player abs,Enemy E_abs)
{
  int P_Hp=abs.Pl_Hp;
  int E_Hp=E_abs.Em_Hp;
  cout << "ս����ʼ��"  << endl;
	cout << abs.Pl_Name << "��HP:" << abs.Pl_Hp << endl;
  cout << E_abs.Em_Name << "��HP:" << E_abs.Em_Hp << endl;
  cout << E_abs.Em_Name  << "��Atk:" << E_abs.Em_Atk << endl;
  cout << E_abs.Em_Name << "��Def:" << E_abs.Em_Def << endl;
  while(P_Hp>0 && E_Hp>0)
  {
    cout << "�غ���:"<< TurnNum  << endl;
	  cout << abs.Pl_Name << "��HP:" << P_Hp << endl;
    cout << E_abs.Em_Name << "��HP:" << E_Hp << endl;
    cout << abs.Pl_Name << "����������" << endl;
    E_Hp=E_Hp-PlTryAtk(abs, E_abs);
		system("pause>nul");
    if(E_Hp<=0)
    {
      FloorDmg = abs.Pl_Hp-P_Hp;
      cout << "ս��ʤ����"  << endl;
      return FloorDmg;
    }
    cout << E_abs.Em_Name << "����������" << endl;
    P_Hp=P_Hp-EmTryAtk(abs, E_abs);
		system("pause>nul");
    if(P_Hp<=0)
    {
      FloorDmg = abs.Pl_Hp;
      cout << "ս��ʧ�ܡ�"  << endl;
      return FloorDmg;
    }
    TurnNum = TurnNum+1;
  }
}
