#include "../class/func.h"
/* ���ô���
void StartMenu()
{
	cout << "***************************" << endl;
	cout << "*****   1����ʼ��Ϸ   *****" << endl;
	cout << "*****   2����ȡ��Ϸ   *****" << endl;
	cout << "*****   3���鿴��¼   *****" << endl;
	cout << "*****   0���˳���Ϸ   *****" << endl;
	cout << "***************************" << endl;
}
*/


int DiffChoice()
{
	int Select = 0;
	cout << "1���ǵ�" << endl;
	cout << "2������������" << endl;
	while(Select!=1&&Select!=2)
	{
		cin >> Select;
		switch (Select)
		{
		case 1:
			cout << "�������ˣ���ô�����ù��������Ļ�ɡ�" << endl;
			break;
		case 2:
			cout << "�����ģ����������Ĺ�����" << endl;
			break;
		default:
			cout << "���ǵ�ʱ�䣬�ܳ�ԣ����˼��һ�����Ҳ����ν�ء�" << endl;
			system("pause>nul");
			cout << "��Σ��о�������" << endl;
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
		cout << "���������� " << Pl_Name << " ��û��ɣ�" << endl;
		cout << "1���ǵġ�" << endl;
		cout << "2�����ǡ�" << endl;
		while(Select!=2&&Select!=1)
		{
			cin >> Select;
			switch (Select)
			{
			case 1:
				break;
			case 2:
				cout << "��������" << endl;
				cout << "�Ͼ������˹��������أ���˼��һ�����Ҳû�����ء�" << endl;
				system("pause>nul");
				cout << "������������" << endl;
				system("pause>nul");
				cout << "��������" << endl;
				system("pause>nul");
				cout << "����" << endl;
				system("pause>nul");
				cout << "�������" << endl;
				cout << "������µ��뷨�Ļ���������Ұɡ�" << endl;
				break;
			default:
				cout << "����ԥ��" << endl;
				cout << "û��ϵ���ҵ����ĺܺã���ú�˼���ɡ�" << endl;
				system("pause>nul");
				cout << "������������" << endl;
				system("pause>nul");
				cout << "��������" << endl;
				system("pause>nul");
				cout << "����" << endl;
				system("pause>nul");
				cout << "��Σ�" << endl;
				cout << Pl_Name << "������֣�" << endl;
				cout << "1���;��������ˡ�" << endl;
				cout << "2�����ǻ�һ���ɡ�" << endl;
				break;
			}
		}
	}
	cout << "��ô������" << Pl_Name << "�Ĺ��£�������ʼ��" << endl;
}

void Player::CharaDiffcultSet()
{	
	cout << "1��һ�������ð�ա�����ͨ��" << endl;
	cout << "2��һ������ð�ա����򵥣�" << endl;
	cout << "3��һ��ʷʫ��ð�ա������ѣ�" << endl;
	int Diff = 0;
	int Select = 0;
	while(Select!=1)
	{
		cin >> Diff;
		switch(Diff)
		{
		case 1:
			cout << "һ�������ð�գ��ӳ���é®�����������͡�" << endl;
			cout << "�������ģ��������Ĺ�����" << endl;
			Select = DiffChoice();
			break;
		case 2:
			cout << "һ������ð�գ����е����Ѷ���ӭ�ж��⡣" << endl;
			cout << "�������ģ��������Ĺ�����" << endl;
			Select = DiffChoice();
			break;
		case 3:
			cout << "һ��ʷʫ��ð�գ���С�ߴӵ׶������������������裬���ڵ��϶��塣" << endl;
			cout << "�������ģ��������Ĺ�����" << endl;
			Select = DiffChoice();
			break;
		default:
			cout << "һ�������ð�գ��ӳ���é®�����������͡�" << endl;
			cout << "�������ģ��������Ĺ�����" << endl;
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
	cout << "ð�������գ�" << Pl_Name << endl;
	cout << "�ȼ���" << Pl_Lv << endl;
	cout << "���������" << Pl_MaxHp << endl;
	cout << "��������" << Pl_Atk << endl;
	cout << "��������" << Pl_Def << endl;
	switch (Pl_Difficult)
	{
	case 1:
		cout << "��ǰ�Ѷȣ���ͨ" << endl;
		break;
	case 2:
		cout << "��ǰ�Ѷȣ���" << endl;
		break;
	case 3:
		cout << "��ǰ�Ѷȣ�����" << endl;
		break;
	default:
		break;
	}
}

void GameMenu(Player* abs, Floor* F_abs)
{
	cout << "��ǰ�Ĳ���Ϊ��" << F_abs->FloorNum << endl;
	cout << "��ǰ��ð����״̬Ϊ" << endl;
	cout << abs->Pl_Name << "\t" << "�ȼ���" << abs->Pl_Lv << "\t"<< "����ֵ��" << abs->Pl_Exp << "\t" << "�������辭�飺" << abs->Pl_UExp << endl;
	cout << "����ֵ��" << abs->Pl_Hp << "/" << abs->Pl_MaxHp << "\t" << "��������" << abs->Pl_Atk << "\t"<< "��������" << abs->Pl_Def << endl;
	switch (abs->Pl_Difficult)
	{
	case 1:
		cout << "��ǰ�Ѷȣ���ͨ" << endl;
		break;
	case 2:
		cout << "��ǰ�Ѷȣ���" << endl;
		break;
	case 3:
		cout << "��ǰ�Ѷȣ�����" << endl;
		break;
	default:
		break;
	}
	cout << endl << endl;
	cout << "������������ô���أ�" << endl;
	cout << "1��ǰ��" << endl;
	cout << "2���˵�" << endl;
	cout << "3���������˵�" << endl;
}

/* ��������
void StateMenu(Player* abs , Floor* F_abs)
{
	cout << "ð�������գ�" << abs->Pl_Name << endl;
	cout << "�ȼ���" << abs->Pl_Lv << endl;
	cout << "���������" << abs->Pl_MaxHp << endl;
	cout << "��������" << abs->Pl_Atk << endl;
	cout << "��������" << abs->Pl_Def << endl;
	switch (F_abs->Difficult)
	{
	case 1:
		cout << "��ǰ�Ѷȣ���" << endl;
		break;
	case 2:
		cout << "��ǰ�Ѷȣ���ͨ" << endl;
		break;
	case 3:
		cout << "��ǰ�Ѷȣ�����" << endl;
		break;
	default:
		break;
	}

}

void GameMenu(Player* abs, Floor* F_abs)
{
	cout << "��ǰ�Ĳ���Ϊ��" << F_abs->FloorNum << endl;
	cout << "��ǰ��ð����״̬Ϊ" << endl;
	cout << abs->Pl_Name << "\t" << "�ȼ���" << abs->Pl_Lv << "\t"<< "����ֵ��" << abs->Pl_Exp << "\t" << "�������辭�飺" << abs->Pl_UExp << endl;
	cout << "����ֵ��" << abs->Pl_Hp << "/" << abs->Pl_MaxHp << "\t" << "��������" << abs->Pl_Atk << "\t"<< "��������" << abs->Pl_Def << endl;
	if (F_abs->Difficult == 1)
	{
		cout << "��ǰ�Ѷȣ���" << endl;
	}
	else if (F_abs->Difficult == 2)
	{
		cout << "��ǰ�Ѷȣ���ͨ" << endl;
	}
	else
	{
		cout << "��ǰ�Ѷȣ�����" << endl;
	}

	cout << endl << endl;
	cout << "������������ô���أ�" << endl;
	cout << "1��ǰ��" << endl;
	cout << "2���˵�" << endl;
	cout << "3���������˵�" << endl;

}
*/
/*  ���ô���
void GameStart(Player* abs)
{
	cout << "��ʼ�����µ����" << endl;
	cout << "�͸�����һ�������ڣ�������Ϊ������µ����˹������ɡ�" << endl;
Flag_Name:
	cin >> abs->Pl_Name;
	cout << "���������� " << abs->Pl_Name << " ��û��ɣ�" << endl;
	cout << "1���ǵġ�" << endl;
	cout << "2�����ǡ�" << endl;
	int Select = 0;
Flag_NameSelect:
	cin >> Select;
	switch (Select)
	{
	case 1:
		cout << "��ô������" << abs->Pl_Name << "�Ĺ��£�������ʼ��" << endl;
		break;
	case 2:
		cout << "��������" << endl;
		cout << "�Ͼ������˹��������أ���˼��һ�����Ҳû�����ء�" << endl;
		system("pause>nul");
		cout << "������������" << endl;
		system("pause>nul");
		cout << "��������" << endl;
		system("pause>nul");
		cout << "����" << endl;
		system("pause>nul");
		cout << "�������" << endl;
		cout << "������µ��뷨�Ļ���������Ұɡ�" << endl;
		goto Flag_Name;
		break;
	default:
		cout << "����ԥ��" << endl;
		cout << "û��ϵ���ҵ����ĺܺã���ú�˼���ɡ�" << endl;
		system("pause>nul");
		cout << "������������" << endl;
		system("pause>nul");
		cout << "��������" << endl;
		system("pause>nul");
		cout << "����" << endl;
		system("pause>nul");
		cout << "��Σ�" << endl;
		cout << abs->Pl_Name << "������֣�" << endl;
		cout << "1���;��������ˡ�" << endl;
		cout << "2�����ǻ�һ���ɡ�" << endl;
		goto Flag_NameSelect;
		break;
	}
}

void DiffcultStart(Player* abs, Floor* F_abs)
{
	cout << abs->Pl_Name <<"����" << abs->Pl_Name << "����" << endl;
	cout << "��������֡�" << endl;
	cout << "�ǣ���ε�ð�գ������������Ļ����أ�" << endl;

	Flag_DifficultSelect:
	cout << "1��һ�������ð�ա�����ͨ��" << endl;
	cout << "2��һ������ð�ա����򵥣�" << endl;
	cout << "3��һ��ʷʫ��ð�ա������ѣ�" << endl;

	int Select = 0;
	int Select2 = 0;
	cin >> Select;

	switch(Select)
	{
	case 1:
		cout << "һ�������ð�գ��ӳ���é®�����������͡�" << endl;
		cout << "�������ģ��������Ĺ�����" << endl;
	Flag_Confirm1:
		cout << "1���ǵ�" << endl;
		cout << "2������������" << endl;
		cin >> Select2;
		switch (Select2)
		{
		case 1:
			cout << "�������ˣ���ô�����ù��������Ļ�ɡ�" << endl;
			F_abs->Difficult = 2;
			break;
		case 2:
			cout << "�����ģ����������Ĺ�����" << endl;
			goto Flag_DifficultSelect;
			break;
		default:
			cout << "���ǵ�ʱ�䣬�ܳ�ԣ����˼��һ�����Ҳ����ν�ء�" << endl;
			system("pause>nul");
			cout << "��Σ��о�������" << endl;
			goto Flag_Confirm1;
			break;
		}
		break;
	case 2:
		cout << "һ������ð�գ����е����Ѷ���ӭ�ж��⡣" << endl;
		cout << "�������ģ��������Ĺ�����" << endl;
	Flag_Confirm2:
		cout << "1���ǵ�" << endl;
		cout << "2������������" << endl;
		cin >> Select2;
		switch (Select2)
		{
		case 1:
			cout << "�������ˣ���ô�����ù��������Ļ�ɡ�" << endl;
			F_abs->Difficult = 1;
			break;
		case 2:
			cout << "�����ģ����������Ĺ�����" << endl;
			goto Flag_DifficultSelect;
			break;
		default:
			cout << "���ǵ�ʱ�䣬�ܳ�ԣ����˼��һ�����Ҳ����ν�ء�" << endl;
			system("pause>nul");
			cout << "��Σ��о�������" << endl;
			goto Flag_Confirm2;
			break;
		}
		break;
	case 3:
		cout << "һ��ʷʫ��ð�գ���С�ߴӵ׶������������������裬���ڵ��϶��塣" << endl;
		cout << "�������ģ��������Ĺ�����" << endl;
	Flag_Confirm3:
		cout << "1���ǵ�" << endl;
		cout << "2������������" << endl;
		cin >> Select2;
		switch (Select2)
		{
		case 1:
			cout << "�������ˣ���ô�����ù��������Ļ�ɡ�" << endl;
			F_abs->Difficult = 3;
			break;
		case 2:
			cout << "�����ģ����������Ĺ�����" << endl;
			goto Flag_DifficultSelect;
			break;
		default:
			cout << "���ǵ�ʱ�䣬�ܳ�ԣ����˼��һ�����Ҳ����ν�ء�" << endl;
			system("pause>nul");
			cout << "��Σ��о�������" << endl;
			goto Flag_Confirm3;
			break;
		}
	default:
		break;
	}
}
*/