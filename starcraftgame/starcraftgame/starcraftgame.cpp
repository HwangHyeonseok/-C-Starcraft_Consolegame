#include <iostream>
#include <string>
#include <typeinfo> // class 이름 가져오기를 위한 라이브러리

// 앞으로 과제 : 객체가 죽으면 메모리 할당 해제를 시켜주고 싶다.
//그래서 공격도 맞는 것도 되지 않도록 하고 싶다.
using namespace std;
int damage;

class Unit {

public: 
	Unit(int HP, int ATK) : HP(HP), ATK(ATK) { }

	virtual void Set_damage() { damage = ATK; }
	virtual int Get_HP() { return HP; }

	virtual void Attack(string str_Fight_Tribe) {
		cout << "부모 클래스의 공격 함수는 호출되면 안됩니다. 오류입니다." << endl;
	}

	virtual void Attacked() {
		cout << "부모 클래스의 공격 당하는 함수는 호출되면 안됩니다. 오류입니다." << endl;
	}

protected: 
	int HP; // 내 유닛의 체력
	int ATK; // 내 유닛의 공격력
};

class Zerg : public Unit {
public:
	Zerg(int HP, int ATK) : Unit(HP, ATK) { 
		Zerg::HP = HP;
		Zerg::ATK = ATK;
	}

	void Set_damage() { damage = Zerg::ATK; }
	int Get_HP() { return HP; }

	void Attack(string str_Fight_Tribe) { // (저그)가 공격할 때 사용하는 함수
		Attack_Zerg(str_Fight_Tribe);
	}

	void Attacked() { // (저그)가 다른 유닛에게 공격당할 때 사용하는 함수
		Attacked_Zerg();
		//if (HP <= 0) { delete this; } // 체력이 0이 되면 메모리 할당 해제를 해주고 싶음

	}

private:
	int HP; // 체력
	int ATK; // 공격력
	void Attack_Zerg(string str_Fight_Tribe) { // Zerg 유닛이 때리는 경우 (다른 유닛을 공격할 경우)
		cout << "--------------------전--------------------투--------------------로--------------------그--------------------" << endl;
		cout << "Zerg가 침을 뱉어 " << str_Fight_Tribe << "에게 " << ATK << "의 데미지를 입혔다." << endl;
	}

	void Attacked_Zerg() { // Zerg 유닛이 맞아야 되는 경우 (다른 유닛에게 공격당할 경우)
		if (Zerg::HP <= 0) // 체력이 0 이하라면
		{
			cout << "그러나 Zerg는 이미 죽어있어 공격할 수 없었다." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		} 
		else {// 체력이 남아 있는 경우
			Zerg::HP = Zerg::HP - damage; 
			cout << "Zerg의 남은 체력은 " << Zerg::HP << " 입니다." << endl;
			if (Zerg::HP <= 0)
			{
				cout << "Zerg는 사망하였다." << endl;
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
	int HP; // 체력
	int ATK; // 공격력
	void Attack_Terran(string str_Fight_Tribe) { // Terran 유닛이 때리는 경우 (다른 유닛을 공격할 경우)
		cout << "--------------------전--------------------투--------------------로--------------------그--------------------" << endl;
		cout << "Terran이 총을 쏴서 " << str_Fight_Tribe << "에게 " << ATK << "의 데미지를 입혔다." << endl;
	}

	void Attacked_Terran() { // Terran 유닛이 맞아야 되는 경우 (다른 유닛에게 공격당할 경우)
		if (Terran::HP <= 0) // 체력이 0 이하라면
		{
			cout << "그러나 Terran은 이미 죽어있어 공격할 수 없었다." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// 체력이 남아 있는 경우
			Terran::HP = Terran::HP - damage;  // Unit::ATK 값을 바꿔야함. ==> 저그 유닛의 ATK
			cout << "Terran의 남은 체력은 " << Terran::HP << " 입니다." << endl;
			if (Terran::HP <= 0)
			{
				cout << "Terran는 사망하였다." << endl;
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
	int HP; // 체력
	int ATK; // 공격력
	void Attack_Protoss(string str_Fight_Tribe) { // Protoss 유닛이 때리는 경우 (다른 유닛을 공격할 경우)
		cout << "--------------------전--------------------투--------------------로--------------------그--------------------" << endl;
		cout << "Protoss가 몸통 박치기를 하여 " << str_Fight_Tribe << "에게 " << ATK << "의 데미지를 입혔다." << endl;
	}

	void Attacked_Protoss() { // Protoss 유닛이 맞아야 되는 경우 (다른 유닛에게 공격당할 경우)
		if (Protoss::HP <= 0) // 체력이 0 이하라면
		{
			cout << "그러나 Protoss은 이미 죽어있어 공격할 수 없었다." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// 체력이 남아 있는 경우
			Protoss::HP = Protoss::HP - damage;  // Unit::ATK 값을 바꿔야함.
			cout << "Protoss의 남은 체력은 " << Protoss::HP << " 입니다." << endl;
			if (Protoss::HP <= 0)
			{
				cout << "Protoss는 사망하였다." << endl;
				//delete this;
			}
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
};

int main(void) {
	string My_Tribe; // 내가 선택한 종족
	string str_Fight_Tribe; // 맞을 종족 (내가 때리고자 하는 종족)
	Unit* MyUnit; // 나의 종족 클래스를 가르키는 포인터
	Unit *Fight_Tribe; // 맞는 종족 클래스를 가르키는 포인터

#pragma region 스타크래프트 종족들
	Zerg Zerg_(100, 20); // 저그 : 체력 100 공격력 20
	Terran Terran_(15, 60); // 테란 : 체력 15 공격력 60
	Protoss Protoss_(70, 30) ; // 프로토스 : 체력 70 공격력 30
	//Unit* Protoss_ = new Protoss(70, 30);
#pragma endregion

	while(1) {

	cout << "어떤 종족을 선택하시겠습니까?(문자열 입력)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> My_Tribe;
	cout << "때릴 종족은?" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> str_Fight_Tribe;

	if (My_Tribe.compare(str_Fight_Tribe) == 0) // 때릴 종족과 맞을 종족이 같다면 오류 출력
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "같은 종족은 때릴 수 없습니다." << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		continue;
	}

#pragma region 때릴 종족 조건문 (나의 종족)
	if (My_Tribe == "Zerg") // 내가 저그 종족을 선택했다면
	{
		MyUnit = &Zerg_;
		if ((Zerg_.Zerg::Get_HP()) <= 0) // 선택한 저그 종족의 체력이 0 이하라면
		{
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			cout << "저그는 이미 죽어 있습니다. 다시 입력해주세요." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			continue;
		}
		MyUnit->Set_damage();
		MyUnit->Attack(str_Fight_Tribe);
	}

	if (My_Tribe == "Terran") // 내가 테란 종족을 선택했다면
	{
		MyUnit = &Terran_;
		if ((Terran_.Terran::Get_HP()) <= 0) // 선택한 테란 종족의 체력이 0 이하라면
		{
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			cout << "테란은 이미 죽어 있습니다. 다시 입력해주세요." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			continue;
		}
		MyUnit->Set_damage();
		MyUnit->Attack(str_Fight_Tribe);
	}

	if (My_Tribe == "Protoss") // 내가 저그 종족을 선택했다면
	{
		MyUnit = &Protoss_;
		if ((Protoss_.Protoss::Get_HP()) <= 0) // 선택한 프로토스 종족의 체력이 0 이하라면
		{
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			cout << "프로토스는 이미 죽어 있습니다. 다시 입력해주세요." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
			continue;
		}
		MyUnit->Set_damage();
		MyUnit->Attack(str_Fight_Tribe);
	}
#pragma endregion

#pragma region 맞을 종족 조건문
	if (str_Fight_Tribe == "Zerg") // 맞을 종족이 저그 종족이라면
	{
		Fight_Tribe = &Zerg_;
		Fight_Tribe->Attacked();
		//if ((Fight_Tribe->Get_HP()) < 0)
			//delete Fight_Tribe;

	}

	if (str_Fight_Tribe == "Terran") // 맞을 종족이 테란 종족이라면
	{
		Fight_Tribe = &Terran_;
		Fight_Tribe->Attacked();
		//if ((Fight_Tribe->Get_HP()) < 0)
			//delete Fight_Tribe;
	}

	if (str_Fight_Tribe == "Protoss") // 맞을 종족이 테란 종족이라면
	{
		Fight_Tribe = &Protoss_;
		Fight_Tribe->Attacked();
		//if ((Fight_Tribe->Get_HP()) < 0) // Fight_Tribe->Get_HP 는 정상적으로 잘 가져와진다.
			//delete Fight_Tribe;
	}
#pragma endregion

	} // while문의 끝
} // main 함수의 끝

	/*class tribe; // 자신이 선택한 종족 ( 저그, 테란, 프로토스 )
	class with_fight; // 싸울 종족 ( 저그, 테란, 프로토스 )
	Unit* a1 = new Zerg();
	Unit* a2 = new Protoss();
	Unit* a3 = new Terran();

	// 1) 캐릭터 선택 (선택을 받는 변수 tribe)
	cout << "어떤 종족을 선택하시겠습니까?(문자열 입력)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> tribe;

	// 2) 싸울 종족 선택 (선택을 받는 변수 with_fight)
	cout << "어떤 종족과 싸우시겠습니까?(문자열 입력)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> with_fight;

	if (tribe == "Zerg") { a1->Attack(); }
	if (tribe == "Protoss") { a2->Attack(); }
	if (tribe == "Terran") { a3->Attack(); }

	return 0;
	*/