#include <iostream>
#include <string>
#include <typeinfo> // class �̸� �������⸦ ���� ���̺귯��
#include <list>

using namespace std;

class Unit {
public:
	Unit() : Unit_Name(NULL), HP(0), ATK(0) {}
	Unit(string Unit_Name, int HP, int ATK) : Unit_Name(Unit_Name), HP(HP), ATK(ATK) { }

	virtual string Get_Unit_Name() { return Unit_Name; }
	virtual int Get_HP() { return HP; }
	virtual int Get_ATK() { return ATK; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // ü���� �����ͼ� �����ϴ� �Լ�
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // ü���� �����ͼ� �����ϴ� �Լ�

	virtual void Attack(string enemy_Tribe) { // �����ϴ� �Լ�
		cout << "�θ� Ŭ������ ���� �Լ��� ȣ��Ǹ� �ȵ˴ϴ�. �����Դϴ�." << endl;
	}

	virtual void Attacked() { // ���ݹ޴� �Լ�
		cout << "�θ� Ŭ������ ���� ���ϴ� �Լ��� ȣ��Ǹ� �ȵ˴ϴ�. �����Դϴ�." << endl;
	}


protected:
	string Unit_Name; // ���� �̸�
	int HP; // �� ������ ü��
	int ATK; // �� ������ ���ݷ�
};

class Zerg : public Unit {
public:
	Zerg() : Unit_Name(NULL), HP(0), ATK(0) {}
	Zerg(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Zerg::HP = HP;
		Zerg::ATK = ATK;
	}

	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // ü���� �����ͼ� �����ϴ� �Լ�
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // ü���� �����ͼ� �����ϴ� �Լ�

private:
	string Unit_Name; // ���� �̸�
	int HP; // ü��
	int ATK; // ���ݷ�
};

class Terran : public Unit {
public:
	Terran() : Unit_Name(NULL), HP(0), ATK(0) {}
	Terran(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Terran::HP = HP;
		Terran::ATK = ATK;
	}
	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // ü���� �����ͼ� �����ϴ� �Լ�
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // ü���� �����ͼ� �����ϴ� �Լ�
private:
	string Unit_Name; // ���� �̸�
	int HP; // ü��
	int ATK; // ���ݷ�
};

class Protoss : public Unit {
public:
	Protoss() : Unit_Name(NULL), HP(0), ATK(0) {}
	Protoss(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Protoss::HP = HP;
		Protoss::ATK = ATK;
	}
	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // ü���� �����ͼ� �����ϴ� �Լ�
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // ü���� �����ͼ� �����ϴ� �Լ�


private:
	string Unit_Name; // ���� �̸�
	int HP; // ü��
	int ATK; // ���ݷ�
};

class GameManager {
public:

private:

};

class Battle {
private:
	list<Unit>::iterator iter; // �ݺ��ڸ� ����ϱ� ���� �ݺ��� ���� ����
	string Battle_My_Unit_Name; // ��Ʋ�� �Ʊ� ���� ����
	string Battle_Enemy_Unit_Name; // ��Ʋ�� ���� ���� ����
	int My_ATK; // �Ʊ� ������ ������(���ݷ�)
	int My_HP; // �Ʊ� ������ ü��
	int Enemy_ATK; // �� ������ ������(���ݷ�)
	int Enemy_HP; // �� ������ ü��

public:
	void Fight(list<Unit>*& My_Units_list, list<Unit>*& Enemy_Units_list) {
		// 1. �ο�(����) ó�� // 2. �¸�/���º�/�й� �� ó��


#pragma region [1. �ο�(����) ó��]
	// 1) ��Ʋ�� �Ʊ� ���ֵ��� ���ݷ� �հ� ü���� ���� ���Ѵ�. 2) ��Ʋ�� ���� ������ ���ݷ��� �հ� ü���� ���� ���Ѵ�.
	// 3) ������ ���� �� �Ʊ� ü�� ó���Ѵ�. 4) �Ʊ��� ���� �� ���� ü�� ó���Ѵ�.
	// 5) ���� ����� ����Ѵ�.

		for (iter = My_Units_list->begin(); iter != My_Units_list->end(); iter++) {
			My_ATK = My_ATK + iter->Get_ATK(); // 1) �Ʊ� ������ ���ݷ��� �հ� ü���� ���� �޴´�.
			My_HP = My_HP + iter->Get_HP(); // �Ʊ� ���ֵ��� �� ���ݷ� : My_ATK , �Ʊ� ���ֵ��� �� HP : My_HP
		}

		for (iter = Enemy_Units_list->begin(); iter != Enemy_Units_list->end(); iter++) {
			Enemy_ATK = Enemy_ATK + iter->Get_ATK(); // 2) ��Ʋ�� ���� ������ ���ݷ��� �հ� ü���� ���� �޴´�.
			Enemy_HP = Enemy_HP + iter->Get_HP(); // ���� ���ֵ��� �� ���ݷ� : Enemy_ATK , �Ʊ� ���ֵ��� �� HP : Enemy_HP
		}
#pragma endregion

#pragma region [2. �¸�/���º�/�й� �� ó��]
		while (My_HP > 0 && Enemy_HP > 0) { // ��� ���� ���������� ���� ����
			My_HP = My_HP - Enemy_ATK; 	// 3) ������ ���� �� �Ʊ� ������ ü��/��� ó���Ѵ�.
			Enemy_HP = Enemy_HP - My_ATK; // 4) �Ʊ��� ���� �� ���� ü��/��� ó���Ѵ�.
		} // while�� ��
		cout << "------- �� �� �� �� -------" << endl;
		if (My_HP <= 0 && Enemy_HP > 0) {
			cout << "�Ʊ� ������ ����Ͽ����ϴ�." << endl;
			cout << "������ �¸��Ͽ����ϴ�." << endl;
		}
		else if (Enemy_HP <= 0 && My_HP > 0) {
			cout << "������ ������ ����Ͽ����ϴ�." << endl;
			cout << "�Ʊ��� �¸��Ͽ����ϴ�." << endl;
		}
		else {
			cout << "�� ���ֵ�� �Ʊ� ���ֵ� ��� ����Ͽ����ϴ�." << endl;
			cout << "���º��Դϴ�." << endl;
		}
		cout << "------------------------" << endl;

#pragma endregion
	} // Fight �޼����� ��
}; // Battle Ŭ������ ��

int main(void) {
Restart: // ������ ����� �� �� goto �Լ��� ���� Restart �� �̵� -> label ����
	string My_Tribe; // ���� ������ ����
	string enemy_Tribe; // ��� ���� (���� �������� �ϴ� ����)
	string Unit_Name; // �� ������ ���� �̸� 
	int individual; // ��ü��
	Battle b; // Battle Ŭ������ ��� ���� �� �Լ��� �����ϱ� ���� ��ü ����
	GameManager g; // GameManager Ŭ������ ��� ���� �� �Լ��� �����ϱ� ���� ��ü ����
	char Restart_Game_Select; // ������ ������� ������ Ȯ�� �޴� ����

#pragma region ��Ÿũ����Ʈ ���ֵ��� ��� ����Ʈ ����
	list<Unit>* My_Units_list = new list<Unit>; // �Ʊ� ���ֵ��� ���� ���Ḯ��Ʈ
	list<Unit>* Enemy_Units_list = new list<Unit>; // ���� ���ֵ��� ���� ���Ḯ��Ʈ
	list<Unit>::iterator iter; // ���Ḯ��Ʈ�� �����ϱ� ���� �ݺ��� ������ (������ �����ʹ� �ƴϰ� ������ó�� ����ϵ��� �Ǿ�����)
	int Set_HP; // <���� ���� ���� �� ���� ����> �ܰ迡�� �Է¹��� HP
	int Set_ATK; // <���� ���� ���� �� ���� ����> �ܰ迡�� �Է¹��� ATK
#pragma endregion

#pragma region <���� ���� ���� �� ���� ����>
	cout << "���� ������ �����Ͻÿ�(���ڿ� �Է�)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> My_Tribe;
	while (My_Tribe != "Zerg" && My_Tribe != "Terran" && My_Tribe != "Protoss") // ���� �̸��� ����� �Է��� ������ �ٽ� �Է¹ޱ�
	{
		cout << "�Ʊ� ���� �̸��� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "���� ������ �����Ͻÿ�(���ڿ� �Է�)" << endl;
		cout << "1. Zerg 2. Terran 3. Protoss" << endl;
		cin >> My_Tribe;
	}

	cout << "�Ʊ� ������ ��ü���� �Է��Ͻÿ� : "; cin >> individual;
	for (int i = 0; i < individual; i++) { // [�Ʊ�] ���� ���� �Է� ���� �� ����
		cout << "������ �̸�(����)�� �Է��ϼ��� : "; cin >> Unit_Name;
		cout << Unit_Name << "�� ü���� �Է��ϼ��� : "; cin >> Set_HP;
		cout << Unit_Name << "�� ���ݷ��� �Է��ϼ��� : "; cin >> Set_ATK;
		cout << "------- ���� ���� ��� �Ϸ�(�Ʊ�) -------" << endl;
		cout << "�̸�: " << Unit_Name << endl;
		cout << "HP: " << Set_HP << endl;
		cout << "ATK: " << Set_ATK << endl;
		cout << "-----------------------" << endl;
		My_Units_list->push_back(Unit(Unit_Name, Set_HP, Set_ATK));
	}
#pragma endregion

#pragma region <��� ���� ���� �� ���� ����>
	cout << "��� ������ �����Ͻÿ�(���ڿ� �Է�)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> enemy_Tribe;
	while (enemy_Tribe != "Zerg" && enemy_Tribe != "Terran" && enemy_Tribe != "Protoss") // ���� �̸��� ����� �Է��� ������ �ٽ� �Է¹ޱ�
	{
		cout << "���� ���� �̸��� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
		cout << "��� ������ �����Ͻÿ�(���ڿ� �Է�)" << endl;
		cout << "1. Zerg 2. Terran 3. Protoss" << endl;
		cin >> enemy_Tribe;
	}

	cout << "���� ������ ��ü���� �Է��Ͻÿ� : "; cin >> individual;
	for (int i = 0; i < individual; i++) { // [����] ���� ���� �Է� ���� �� ����
		cout << "������ �̸�(����)�� �Է��ϼ��� : "; cin >> Unit_Name;
		cout << Unit_Name << "�� ü���� �Է��ϼ��� : "; cin >> Set_HP;
		cout << Unit_Name << "�� ���ݷ��� �Է��ϼ��� : "; cin >> Set_ATK;
		cout << "------- ���� ���� ��� �Ϸ�(����) -------" << endl;
		cout << "�̸�: " << Unit_Name << endl;
		cout << "HP: " << Set_HP << endl;
		cout << "ATK: " << Set_ATK << endl;
		cout << "-----------------------" << endl;
		Enemy_Units_list->push_back(Unit(Unit_Name, Set_HP, Set_ATK));
	}
#pragma endregion

	b.Fight(My_Units_list, Enemy_Units_list); // Battle Ŭ������ Fight �Լ� ȣ�� (�ο� ��� ó��)
	cout << "�ٽ� �����Ͻðڽ��ϱ�? (Y/N) : "; cin >> Restart_Game_Select;

	if (Restart_Game_Select == 'Y') { // ���� �����
		cout << "���ο� ������ �����մϴ�." << endl;
		goto Restart;
	}
	else if (Restart_Game_Select == 'N') { // ���� ����
		cout << "������ �����մϴ�." << endl;
		exit(0);
	}

} // main �Լ��� ��