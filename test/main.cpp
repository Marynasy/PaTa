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
	Chimera.Em_Name = "������";
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
			cout << "*****   1����ʼ��Ϸ   *****" << endl;
			cout << "*****   2����ȡ��Ϸ   *****" << endl;
			cout << "*****   3���鿴��¼   *****" << endl;
			cout << "*****   0���˳���Ϸ   *****" << endl;
			cout << "***************************" << endl;
			cin >> Select;
			//StartSelect = Select;
			switch (Select)
			{
			case 1:
				cout << "��ʼ�����µ����" << endl;
				cout << "�͸�����һ�������ڣ�������Ϊ������µ����˹������ɡ�" << endl;
				Pc.CharaNameSet();
				cout << Pc.Pl_Name <<"����" << Pc.Pl_Name << "����" << endl;
				cout << "��������֡�" << endl;
				cout << "�ǣ���ε�ð�գ������������Ļ����أ�" << endl;
				Pc.CharaDiffcultSet();
				cout << "ð�ռ�����ʼ���������ȷ��ð���ߵ������ɡ�" << endl;
				Pc.StateMenu();
				system("pause>nul");
				system("cls");
				break;
			case 2:
				cout << "Ҫ��ȡ�ĸ���¼��" << endl;
				cout << "Ŀǰֻ�Ǹ����衣" << endl;
				Mode = menu;
				system("pause>nul");
				break;
			case 3:
				cout << "Ҫ�鿴�ĸ���¼��" << endl;
				cout << "Ŀǰֻ�Ǹ����衣" << endl;
				Mode = menu;
				system("pause>nul");
				break;
			case 0:
				cout << "ð��ӭ������" << endl;
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
					cout << "Ŀǰֻ��װ��Ʒ" << endl;
					system("cls");
					break;
				case 3:
					cout << "ȷ��Ҫ�������˵���" << endl;
					cout << "δ��������ݽ���ʧ����ȻĿǰ����û�д浵����" << endl;
					cout << "1��ȷ��" << endl;
					cout << "2��ȡ��" << endl;
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
			cout << "��ϲͨ�أ�" << endl;
			system("pause>nul");
			Mode = menu;
			break;
		case 3:
			cout << "******����ս��******" << endl;
			system("pause>nul");
			Pc.Pl_Name = "����";
			Pc.Pl_ExAtk = 1;
			F_Pc.FloorNum = 1;
			F_Pc.EnterFight(Pc, Chimera);
			Pc.BeDamaged(F_Pc.FloorDmg);
			cout << "******ʣ��HP:"<< Pc.Pl_Hp << "******"<< endl;
			system("pause>nul");
			break;
		default:
			break;
		}
		cout << "testcode==1" << endl;
		system("pause>nul");
	}
	cout << "ð��ӭ������" << endl;
	system("pause>nul");
	return 0;
}