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
  int BaseAtkCoe = GetBaseAtkCoe();//目前没用
  int ExAtkCoe = GetExAtkCoe();//目前没用
  int FinalAtkCoe = GetFinalAtkCoe();//目前没用
  Attack = (Pl_BaseAtk*BaseAtkCoe + Pl_ExAtk*ExAtkCoe)*FinalAtkCoe/10000;
  return Attack;
}


double Player::GetDef()
{
  double Defence;
  int BaseDefCoe = GetBaseDefCoe();//目前没用
  int ExDefCoe = GetExDefCoe();//目前没用
  int FinalDefCoe = GetFinalDefCoe();//目前没用
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
	  cout << abs.Pl_Name << "对" << E_abs.Em_Name <<  "造成了" << Damage << "点伤害！" << endl;
    return Damage;
  }
  else
  {
	  cout << "没有造成伤害！" << endl;
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
	  cout << E_abs.Em_Name << "对" << abs.Pl_Name <<  "造成了" << Damage << "点伤害！" << endl;
    return Damage;
  }
  else
  {
	  cout << "没有造成伤害！" << endl;
    return 0;
  }
}

int Floor::EnterFight(Player abs,Enemy E_abs)
{
  int P_Hp=abs.Pl_Hp;
  int E_Hp=E_abs.Em_Hp;
  cout << "战斗开始。"  << endl;
	cout << abs.Pl_Name << "的HP:" << abs.Pl_Hp << endl;
  cout << E_abs.Em_Name << "的HP:" << E_abs.Em_Hp << endl;
  cout << E_abs.Em_Name  << "的Atk:" << E_abs.Em_Atk << endl;
  cout << E_abs.Em_Name << "的Def:" << E_abs.Em_Def << endl;
  while(P_Hp>0 && E_Hp>0)
  {
    cout << "回合数:"<< TurnNum  << endl;
	  cout << abs.Pl_Name << "的HP:" << P_Hp << endl;
    cout << E_abs.Em_Name << "的HP:" << E_Hp << endl;
    cout << abs.Pl_Name << "发动攻击！" << endl;
    E_Hp=E_Hp-PlTryAtk(abs, E_abs);
		system("pause>nul");
    if(E_Hp<=0)
    {
      FloorDmg = abs.Pl_Hp-P_Hp;
      cout << "战斗胜利。"  << endl;
      return FloorDmg;
    }
    cout << E_abs.Em_Name << "发动攻击！" << endl;
    P_Hp=P_Hp-EmTryAtk(abs, E_abs);
		system("pause>nul");
    if(P_Hp<=0)
    {
      FloorDmg = abs.Pl_Hp;
      cout << "战斗失败。"  << endl;
      return FloorDmg;
    }
    TurnNum = TurnNum+1;
  }
}
