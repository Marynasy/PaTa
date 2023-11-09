#include<iostream>
#include<string>
#include<ctime>
#include ".\class\func.h"
using namespace std;


int main()
{
	Player Pc;
	Floor F_Pc;
	Enemy Chimera;
	Chimera.Em_Name = "奇美拉";
	//enum {start=1,load,log,exit=0} StartSelect = start;
	enum {menu=1,load,fight,exit=0} Mode = fight;
	int Select = 1;
	while(Select != 0 || Mode !=0)
	{
		system("cls");
		cout << "testcode==0" << endl;
		switch (Mode)	
		{
		case 1:
			cout << "***************************" << endl;
			cout << "*****   1、开始游戏   *****" << endl;
			cout << "*****   2、读取游戏   *****" << endl;
			cout << "*****   3、查看记录   *****" << endl;
			cout << "*****   0、退出游戏   *****" << endl;
			cout << "***************************" << endl;
			cin >> Select;
			//StartSelect = Select;
			switch (Select)
			{
			case 1:
				cout << "开始叙述新的物语。" << endl;
				cout << "就跟以往一样，观众，由你来为这个故事的主人公赋名吧。" << endl;
				Pc.CharaNameSet();
				cout << Pc.Pl_Name <<"……" << Pc.Pl_Name << "……" << endl;
				cout << "不错的名字。" << endl;
				cout << "那，这次的冒险，又有着怎样的基调呢？" << endl;
				Pc.CharaDiffcultSet();
				cout << "冒险即将开始，在最后，请确认冒险者的能力吧。" << endl;
				Pc.StateMenu();
				system("pause>nul");
				system("cls");
				break;
			case 2:
				cout << "要读取哪个记录？" << endl;
				cout << "目前只是个摆设。" << endl;
				Mode = menu;
				system("pause>nul");
				break;
			case 3:
				cout << "要查看哪个记录？" << endl;
				cout << "目前只是个摆设。" << endl;
				Mode = menu;
				system("pause>nul");
				break;
			case 0:
				cout << "冒险迎来结束" << endl;
				system("pause>nul");
				Mode = exit;
				return 0;
				break;
			default:
				break;
			}
			break;
		case 2:
			int GameSelect;
			int GameSelect2;
			do
			{
				GameMenu(&Pc, &F_Pc);
				cin >> GameSelect;
				switch (GameSelect)
				{
				case 1:
					F_Pc.FloorNum++;
					system("cls");
					break;
				case 2:
					cout << "目前只是装饰品" << endl;
					system("cls");
					break;
				case 3:
					cout << "确定要返回主菜单吗？" << endl;
					cout << "未保存的数据将消失（虽然目前根本没有存档功能" << endl;
					cout << "1、确定" << endl;
					cout << "2、取消" << endl;
					cin >> GameSelect2;
					switch (GameSelect2)
					{
					case 1:
						Mode = menu;
						break;
					case 2:
						break;
					default:
						break;
					}
					break;
				default:
					system("cls");
					break;
				}
			} while (F_Pc.FloorNum < 10);
			system("cls");
			cout << "恭喜通关！" << endl;
			system("pause>nul");
			Mode = menu;
			break;
		case 3:
			cout << "******测试战斗******" << endl;
			system("pause>nul");
			Pc.Pl_Name = "玛丽";
			Pc.Pl_ExAtk = 1;
			F_Pc.FloorNum = 1;
			F_Pc.EnterFight(Pc, Chimera);
			Pc.BeDamaged(F_Pc.FloorDmg);
			cout << "******剩余HP:"<< Pc.Pl_Hp << "******"<< endl;
			system("pause>nul");
			break;
		default:
			break;
		}
		cout << "testcode==1" << endl;
		system("pause>nul");
	}
	cout << "冒险迎来结束" << endl;
	system("pause>nul");
	return 0;
}