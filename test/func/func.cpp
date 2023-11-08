#include "../class/func.h"
/* 弃用代码
void StartMenu()
{
	cout << "***************************" << endl;
	cout << "*****   1、开始游戏   *****" << endl;
	cout << "*****   2、读取游戏   *****" << endl;
	cout << "*****   3、查看记录   *****" << endl;
	cout << "*****   0、退出游戏   *****" << endl;
	cout << "***************************" << endl;
}
*/


int DiffChoice()
{
	int Select = 0;
	cout << "1、是的" << endl;
	cout << "2、不，再想想" << endl;
	while(Select!=1&&Select!=2)
	{
		cin >> Select;
		switch (Select)
		{
		case 1:
			cout << "我明白了，那么，就让故事拉开帷幕吧。" << endl;
			break;
		case 2:
			cout << "想听的，是其他风格的故事吗？" << endl;
			break;
		default:
			cout << "我们的时间，很充裕，多思考一会儿，也无所谓呢。" << endl;
			system("pause>nul");
			cout << "如何，有决定了吗？" << endl;
			break;
		}
	}
	return Select;
}

void Player::CharaNameSet()
{
	int Select=0;
	while(Select!=1)
	{
		Select = 0;
		cin >> Pl_Name;
		cout << "他的名字是 " << Pl_Name << " ，没错吧？" << endl;
		cout << "1、是的。" << endl;
		cout << "2、不是。" << endl;
		while(Select!=2&&Select!=1)
		{
			cin >> Select;
			switch (Select)
			{
			case 1:
				break;
			case 2:
				cout << "不满意吗？" << endl;
				cout << "毕竟是主人公的姓名呢，多思量一会儿，也没问题呢。" << endl;
				system("pause>nul");
				cout << "………………" << endl;
				system("pause>nul");
				cout << "…………" << endl;
				system("pause>nul");
				cout << "……" << endl;
				system("pause>nul");
				cout << "想好了吗？" << endl;
				cout << "如果有新的想法的话，请告诉我吧。" << endl;
				break;
			default:
				cout << "在犹豫吗？" << endl;
				cout << "没关系，我的耐心很好，请好好思考吧。" << endl;
				system("pause>nul");
				cout << "………………" << endl;
				system("pause>nul");
				cout << "…………" << endl;
				system("pause>nul");
				cout << "……" << endl;
				system("pause>nul");
				cout << "如何？" << endl;
				cout << Pl_Name << "这个名字？" << endl;
				cout << "1、就决定是它了。" << endl;
				cout << "2、还是换一个吧。" << endl;
				break;
			}
		}
	}
	cout << "那么，属于" << Pl_Name << "的故事，即将开始。" << endl;
}

void Player::CharaDiffcultSet()
{	
	cout << "1、一场经典的冒险。（普通）" << endl;
	cout << "2、一场愉快的冒险。（简单）" << endl;
	cout << "3、一场史诗的冒险。（困难）" << endl;
	int Diff = 0;
	int Select = 0;
	while(Select!=1)
	{
		cin >> Diff;
		switch(Diff)
		{
		case 1:
			cout << "一场经典的冒险，从初出茅庐，到功成名就。" << endl;
			cout << "你想听的，是这样的故事吗？" << endl;
			Select = DiffChoice();
			break;
		case 2:
			cout << "一场愉快的冒险，所有的困难都能迎刃而解。" << endl;
			cout << "你想听的，是这样的故事吗？" << endl;
			Select = DiffChoice();
			break;
		case 3:
			cout << "一场史诗的冒险，弱小者从底端向上攀爬，历尽险阻，终于登上顶峰。" << endl;
			cout << "你想听的，是这样的故事吗？" << endl;
			Select = DiffChoice();
			break;
		default:
			cout << "一场经典的冒险，从初出茅庐，到功成名就。" << endl;
			cout << "你想听的，是这样的故事吗？" << endl;
			Select = DiffChoice();
			break;
		}
	}
	switch(Diff)
	{
		case 1:
			Pl_Difficult=Normal;
			break;
		case 2:
			Pl_Difficult=Easy;
			break;
		case 3:
			Pl_Difficult=Hard;
			break;
		default:
			Pl_Difficult=Normal;
	}
}


void Player::StateMenu()
{
	cout << "冒险者名姓：" << Pl_Name << endl;
	cout << "等级：" << Pl_Lv << endl;
	cout << "最大生命：" << Pl_MaxHp << endl;
	cout << "攻击力：" << Pl_Atk << endl;
	cout << "防御力：" << Pl_Def << endl;
	switch (Pl_Difficult)
	{
	case 1:
		cout << "当前难度：普通" << endl;
		break;
	case 2:
		cout << "当前难度：简单" << endl;
		break;
	case 3:
		cout << "当前难度：困难" << endl;
		break;
	default:
		break;
	}
}

void GameMenu(Player* abs, Floor* F_abs)
{
	cout << "当前的层数为：" << F_abs->FloorNum << endl;
	cout << "当前的冒险者状态为" << endl;
	cout << abs->Pl_Name << "\t" << "等级：" << abs->Pl_Lv << "\t"<< "经验值：" << abs->Pl_Exp << "\t" << "升级所需经验：" << abs->Pl_UExp << endl;
	cout << "生命值：" << abs->Pl_Hp << "/" << abs->Pl_MaxHp << "\t" << "攻击力：" << abs->Pl_Atk << "\t"<< "防御力：" << abs->Pl_Def << endl;
	switch (abs->Pl_Difficult)
	{
	case 1:
		cout << "当前难度：普通" << endl;
		break;
	case 2:
		cout << "当前难度：简单" << endl;
		break;
	case 3:
		cout << "当前难度：困难" << endl;
		break;
	default:
		break;
	}
	cout << endl << endl;
	cout << "接下来，该怎么做呢？" << endl;
	cout << "1、前进" << endl;
	cout << "2、菜单" << endl;
	cout << "3、返回主菜单" << endl;
}

/* 暂且弃用
void StateMenu(Player* abs , Floor* F_abs)
{
	cout << "冒险者名姓：" << abs->Pl_Name << endl;
	cout << "等级：" << abs->Pl_Lv << endl;
	cout << "最大生命：" << abs->Pl_MaxHp << endl;
	cout << "攻击力：" << abs->Pl_Atk << endl;
	cout << "防御力：" << abs->Pl_Def << endl;
	switch (F_abs->Difficult)
	{
	case 1:
		cout << "当前难度：简单" << endl;
		break;
	case 2:
		cout << "当前难度：普通" << endl;
		break;
	case 3:
		cout << "当前难度：困难" << endl;
		break;
	default:
		break;
	}

}

void GameMenu(Player* abs, Floor* F_abs)
{
	cout << "当前的层数为：" << F_abs->FloorNum << endl;
	cout << "当前的冒险者状态为" << endl;
	cout << abs->Pl_Name << "\t" << "等级：" << abs->Pl_Lv << "\t"<< "经验值：" << abs->Pl_Exp << "\t" << "升级所需经验：" << abs->Pl_UExp << endl;
	cout << "生命值：" << abs->Pl_Hp << "/" << abs->Pl_MaxHp << "\t" << "攻击力：" << abs->Pl_Atk << "\t"<< "防御力：" << abs->Pl_Def << endl;
	if (F_abs->Difficult == 1)
	{
		cout << "当前难度：简单" << endl;
	}
	else if (F_abs->Difficult == 2)
	{
		cout << "当前难度：普通" << endl;
	}
	else
	{
		cout << "当前难度：困难" << endl;
	}

	cout << endl << endl;
	cout << "接下来，该怎么做呢？" << endl;
	cout << "1、前进" << endl;
	cout << "2、菜单" << endl;
	cout << "3、返回主菜单" << endl;

}
*/
/*  弃用代码
void GameStart(Player* abs)
{
	cout << "开始叙述新的物语。" << endl;
	cout << "就跟以往一样，观众，由你来为这个故事的主人公赋名吧。" << endl;
Flag_Name:
	cin >> abs->Pl_Name;
	cout << "他的名字是 " << abs->Pl_Name << " ，没错吧？" << endl;
	cout << "1、是的。" << endl;
	cout << "2、不是。" << endl;
	int Select = 0;
Flag_NameSelect:
	cin >> Select;
	switch (Select)
	{
	case 1:
		cout << "那么，属于" << abs->Pl_Name << "的故事，即将开始。" << endl;
		break;
	case 2:
		cout << "不满意吗？" << endl;
		cout << "毕竟是主人公的姓名呢，多思量一会儿，也没问题呢。" << endl;
		system("pause>nul");
		cout << "………………" << endl;
		system("pause>nul");
		cout << "…………" << endl;
		system("pause>nul");
		cout << "……" << endl;
		system("pause>nul");
		cout << "想好了吗？" << endl;
		cout << "如果有新的想法的话，请告诉我吧。" << endl;
		goto Flag_Name;
		break;
	default:
		cout << "在犹豫吗？" << endl;
		cout << "没关系，我的耐心很好，请好好思考吧。" << endl;
		system("pause>nul");
		cout << "………………" << endl;
		system("pause>nul");
		cout << "…………" << endl;
		system("pause>nul");
		cout << "……" << endl;
		system("pause>nul");
		cout << "如何？" << endl;
		cout << abs->Pl_Name << "这个名字？" << endl;
		cout << "1、就决定是它了。" << endl;
		cout << "2、还是换一个吧。" << endl;
		goto Flag_NameSelect;
		break;
	}
}

void DiffcultStart(Player* abs, Floor* F_abs)
{
	cout << abs->Pl_Name <<"……" << abs->Pl_Name << "……" << endl;
	cout << "不错的名字。" << endl;
	cout << "那，这次的冒险，又有着怎样的基调呢？" << endl;

	Flag_DifficultSelect:
	cout << "1、一场经典的冒险。（普通）" << endl;
	cout << "2、一场愉快的冒险。（简单）" << endl;
	cout << "3、一场史诗的冒险。（困难）" << endl;

	int Select = 0;
	int Select2 = 0;
	cin >> Select;

	switch(Select)
	{
	case 1:
		cout << "一场经典的冒险，从初出茅庐，到功成名就。" << endl;
		cout << "你想听的，是这样的故事吗？" << endl;
	Flag_Confirm1:
		cout << "1、是的" << endl;
		cout << "2、不，再想想" << endl;
		cin >> Select2;
		switch (Select2)
		{
		case 1:
			cout << "我明白了，那么，就让故事拉开帷幕吧。" << endl;
			F_abs->Difficult = 2;
			break;
		case 2:
			cout << "想听的，是其他风格的故事吗？" << endl;
			goto Flag_DifficultSelect;
			break;
		default:
			cout << "我们的时间，很充裕，多思考一会儿，也无所谓呢。" << endl;
			system("pause>nul");
			cout << "如何，有决定了吗？" << endl;
			goto Flag_Confirm1;
			break;
		}
		break;
	case 2:
		cout << "一场愉快的冒险，所有的困难都能迎刃而解。" << endl;
		cout << "你想听的，是这样的故事吗？" << endl;
	Flag_Confirm2:
		cout << "1、是的" << endl;
		cout << "2、不，再想想" << endl;
		cin >> Select2;
		switch (Select2)
		{
		case 1:
			cout << "我明白了，那么，就让故事拉开帷幕吧。" << endl;
			F_abs->Difficult = 1;
			break;
		case 2:
			cout << "想听的，是其他风格的故事吗？" << endl;
			goto Flag_DifficultSelect;
			break;
		default:
			cout << "我们的时间，很充裕，多思考一会儿，也无所谓呢。" << endl;
			system("pause>nul");
			cout << "如何，有决定了吗？" << endl;
			goto Flag_Confirm2;
			break;
		}
		break;
	case 3:
		cout << "一场史诗的冒险，弱小者从底端向上攀爬，历尽险阻，终于登上顶峰。" << endl;
		cout << "你想听的，是这样的故事吗？" << endl;
	Flag_Confirm3:
		cout << "1、是的" << endl;
		cout << "2、不，再想想" << endl;
		cin >> Select2;
		switch (Select2)
		{
		case 1:
			cout << "我明白了，那么，就让故事拉开帷幕吧。" << endl;
			F_abs->Difficult = 3;
			break;
		case 2:
			cout << "想听的，是其他风格的故事吗？" << endl;
			goto Flag_DifficultSelect;
			break;
		default:
			cout << "我们的时间，很充裕，多思考一会儿，也无所谓呢。" << endl;
			system("pause>nul");
			cout << "如何，有决定了吗？" << endl;
			goto Flag_Confirm3;
			break;
		}
	default:
		break;
	}
}
*/