/*
#include <iostream>
#include <string>
#include <typeinfo> // class �̸� �������⸦ ���� ���̺귯��

// ������ ���� : ��ü�� ������ �޸� �Ҵ� ������ �����ְ� �ʹ�.
//�׷��� ���ݵ� �´� �͵� ���� �ʵ��� �ϰ� �ʹ�.
using namespace std;
int damage;

class Unit {

public:
	Unit(int HP, int ATK) : HP(HP), ATK(ATK) { }

	virtual void Set_damage() { damage = ATK; }
	virtual int Get_HP() { return HP; }

	virtual void Attack(string str_Fight_Tribe) {
		cout << "�θ� Ŭ������ ���� �Լ��� ȣ��Ǹ� �ȵ˴ϴ�. �����Դϴ�." << endl;
	}

	virtual void Attacked() {
		cout << "�θ� Ŭ������ ���� ���ϴ� �Լ��� ȣ��Ǹ� �ȵ˴ϴ�. �����Դϴ�." << endl;
	}

protected:
	int HP; // �� ������ ü��
	int ATK; // �� ������ ���ݷ�
};

class Zerg : public Unit {
public:
	Zerg(int HP, int ATK) : Unit(HP, ATK) {
		Zerg::HP = HP;
		Zerg::ATK = ATK;
	}

	void Set_damage() { damage = Zerg::ATK; }
	int Get_HP() { return HP; }

	void Attack(string str_Fight_Tribe) { // (����)�� ������ �� ����ϴ� �Լ�
		Attack_Zerg(str_Fight_Tribe);
	}

	void Attacked() { // (����)�� �ٸ� ���ֿ��� ���ݴ��� �� ����ϴ� �Լ�
		Attacked_Zerg();
		//if (HP <= 0) { delete this; } // ü���� 0�� �Ǹ� �޸� �Ҵ� ������ ���ְ� ����

	}

private:
	int HP; // ü��
	int ATK; // ���ݷ�
	void Attack_Zerg(string str_Fight_Tribe) { // Zerg ������ ������ ��� (�ٸ� ������ ������ ���)
		cout << "--------------------��--------------------��--------------------��--------------------��--------------------" << endl;
		cout << "Zerg�� ħ�� ��� " << str_Fight_Tribe << "���� " << ATK << "�� �������� ������." << endl;
	}

	void Attacked_Zerg() { // Zerg ������ �¾ƾ� �Ǵ� ��� (�ٸ� ���ֿ��� ���ݴ��� ���)
		if (Zerg::HP <= 0) // ü���� 0 ���϶��
		{
			cout << "�׷��� Zerg�� �̹� �׾��־� ������ �� ������." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// ü���� ���� �ִ� ���
			Zerg::HP = Zerg::HP - damage;
			cout << "Zerg�� ���� ü���� " << Zerg::HP << " �Դϴ�." << endl;
			if (Zerg::HP <= 0)
			{
				cout << "Zerg�� ����Ͽ���." << endl;
			}
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
};

class Terran : public Unit {
public:
	Terran(int HP, int ATK) : Unit(HP, ATK) {
		Terran::HP = HP;
		Terran::ATK = ATK;
	}
	int Get_HP() { return HP; }

	void Attack(string str_Fight_Tribe) {
		Attack_Terran(str_Fight_Tribe);
	}

	void Attacked() {
		Attacked_Terran();
	}

private:
	int HP; // ü��
	int ATK; // ���ݷ�
	void Attack_Terran(string str_Fight_Tribe) { // Terran ������ ������ ��� (�ٸ� ������ ������ ���)
		cout << "--------------------��--------------------��--------------------��--------------------��--------------------" << endl;
		cout << "Terran�� ���� ���� " << str_Fight_Tribe << "���� " << ATK << "�� �������� ������." << endl;
	}

	void Attacked_Terran() { // Terran ������ �¾ƾ� �Ǵ� ��� (�ٸ� ���ֿ��� ���ݴ��� ���)
		if (Terran::HP <= 0) // ü���� 0 ���϶��
		{
			cout << "�׷��� Terran�� �̹� �׾��־� ������ �� ������." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// ü���� ���� �ִ� ���
			Terran::HP = Terran::HP - damage;  // Unit::ATK ���� �ٲ����. ==> ���� ������ ATK
			cout << "Terran�� ���� ü���� " << Terran::HP << " �Դϴ�." << endl;
			if (Terran::HP <= 0)
			{
				cout << "Terran�� ����Ͽ���." << endl;
				//delete this;
			}
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
};

class Protoss : public Unit {
public:
	Protoss(int HP, int ATK) : Unit(HP, ATK) {
		Protoss::HP = HP;
		Protoss::ATK = ATK;
	}
	int Get_HP() { return HP; }

	void Attack(string str_Fight_Tribe) {
		Attack_Protoss(str_Fight_Tribe);
	}

	void Attacked() {
		Attacked_Protoss();
	}

private:
	int HP; // ü��
	int ATK; // ���ݷ�
	void Attack_Protoss(string str_Fight_Tribe) { // Protoss ������ ������ ��� (�ٸ� ������ ������ ���)
		cout << "--------------------��--------------------��--------------------��--------------------��--------------------" << endl;
		cout << "Protoss�� ���� ��ġ�⸦ �Ͽ� " << str_Fight_Tribe << "���� " << ATK << "�� �������� ������." << endl;
	}

	void Attacked_Protoss() { // Protoss ������ �¾ƾ� �Ǵ� ��� (�ٸ� ���ֿ��� ���ݴ��� ���)
		if (Protoss::HP <= 0) // ü���� 0 ���϶��
		{
			cout << "�׷��� Protoss�� �̹� �׾��־� ������ �� ������." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// ü���� ���� �ִ� ���
			Protoss::HP = Protoss::HP - damage;  // Unit::ATK ���� �ٲ����.
			cout << "Protoss�� ���� ü���� " << Protoss::HP << " �Դϴ�." << endl;
			if (Protoss::HP <= 0)
			{
				cout << "Protoss�� ����Ͽ���." << endl;
				//delete this;
			}
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
};

int main(void) {
	string My_Tribe; // ���� ������ ����
	string str_Fight_Tribe; // ���� ���� (���� �������� �ϴ� ����)
	Unit* MyUnit; // ���� ���� Ŭ������ ����Ű�� ������
	Unit* Fight_Tribe; // �´� ���� Ŭ������ ����Ű�� ������

#pragma region ��Ÿũ����Ʈ ������
	Zerg Zerg_(100, 20); // ���� : ü�� 100 ���ݷ� 20
	Terran Terran_(15, 60); // �׶� : ü�� 15 ���ݷ� 60
	Protoss Protoss_(70, 30); // �����佺 : ü�� 70 ���ݷ� 30
	//Unit* Protoss_ = new Protoss(70, 30);
#pragma endregion

	while (1) {

		cout << "� ������ �����Ͻðڽ��ϱ�?(���ڿ� �Է�)" << endl;
		cout << "1. Zerg 2. Terran 3. Protoss" << endl;
		cin >> My_Tribe;
		cout << "���� ������?" << endl;
		cout << "1. Zerg 2. Terran 3. Protoss" << endl;
		cin >> str_Fight_Tribe;

		if (My_Tribe.compare(str_Fight_Tribe) == 0) // ���� ������ ���� ������ ���ٸ� ���� ���
		{
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			cout << "���� ������ ���� �� �����ϴ�." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			continue;
		}

#pragma region ���� ���� ���ǹ� (���� ����)
		if (My_Tribe == "Zerg") // ���� ���� ������ �����ߴٸ�
		{
			MyUnit = &Zerg_;
			if ((Zerg_.Zerg::Get_HP()) <= 0) // ������ ���� ������ ü���� 0 ���϶��
			{
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				cout << "���״� �̹� �׾� �ֽ��ϴ�. �ٽ� �Է����ּ���." << endl;
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				continue;
			}
			MyUnit->Set_damage();
			MyUnit->Attack(str_Fight_Tribe);
		}

		if (My_Tribe == "Terran") // ���� �׶� ������ �����ߴٸ�
		{
			MyUnit = &Terran_;
			if ((Terran_.Terran::Get_HP()) <= 0) // ������ �׶� ������ ü���� 0 ���϶��
			{
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				cout << "�׶��� �̹� �׾� �ֽ��ϴ�. �ٽ� �Է����ּ���." << endl;
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				continue;
			}
			MyUnit->Set_damage();
			MyUnit->Attack(str_Fight_Tribe);
		}

		if (My_Tribe == "Protoss") // ���� ���� ������ �����ߴٸ�
		{
			MyUnit = &Protoss_;
			if ((Protoss_.Protoss::Get_HP()) <= 0) // ������ �����佺 ������ ü���� 0 ���϶��
			{
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				cout << "�����佺�� �̹� �׾� �ֽ��ϴ�. �ٽ� �Է����ּ���." << endl;
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				continue;
			}
			MyUnit->Set_damage();
			MyUnit->Attack(str_Fight_Tribe);
		}
#pragma endregion

#pragma region ���� ���� ���ǹ�
		if (str_Fight_Tribe == "Zerg") // ���� ������ ���� �����̶��
		{
			Fight_Tribe = &Zerg_;
			Fight_Tribe->Attacked();
			//if ((Fight_Tribe->Get_HP()) < 0)
				//delete Fight_Tribe;

		}

		if (str_Fight_Tribe == "Terran") // ���� ������ �׶� �����̶��
		{
			Fight_Tribe = &Terran_;
			Fight_Tribe->Attacked();
			//if ((Fight_Tribe->Get_HP()) < 0)
				//delete Fight_Tribe;
		}

		if (str_Fight_Tribe == "Protoss") // ���� ������ �׶� �����̶��
		{
			Fight_Tribe = &Protoss_;
			Fight_Tribe->Attacked();
			//if ((Fight_Tribe->Get_HP()) < 0) // Fight_Tribe->Get_HP �� ���������� �� ����������.
				//delete Fight_Tribe;
		}
#pragma endregion

	} // while���� ��
} // main �Լ��� ��

	/*class tribe; // �ڽ��� ������ ���� ( ����, �׶�, �����佺 )
	class with_fight; // �ο� ���� ( ����, �׶�, �����佺 )
	Unit* a1 = new Zerg();
	Unit* a2 = new Protoss();
	Unit* a3 = new Terran();

	// 1) ĳ���� ���� (������ �޴� ���� tribe)
	cout << "� ������ �����Ͻðڽ��ϱ�?(���ڿ� �Է�)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> tribe;

	// 2) �ο� ���� ���� (������ �޴� ���� with_fight)
	cout << "� ������ �ο�ðڽ��ϱ�?(���ڿ� �Է�)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> with_fight;

	if (tribe == "Zerg") { a1->Attack(); }
	if (tribe == "Protoss") { a2->Attack(); }
	if (tribe == "Terran") { a3->Attack(); }

	return 0;
	*/
