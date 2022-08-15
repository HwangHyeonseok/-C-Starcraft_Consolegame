#include <iostream>
#include <string>
#include <typeinfo> // class 이름 가져오기를 위한 라이브러리
#include <list>

using namespace std;

class Unit {
public:
	Unit() : Unit_Name(NULL), HP(0), ATK(0) {}
	Unit(string Unit_Name, int HP, int ATK) : Unit_Name(Unit_Name), HP(HP), ATK(ATK) { }

	virtual string Get_Unit_Name() { return Unit_Name; }
	virtual int Get_HP() { return HP; }
	virtual int Get_ATK() { return ATK; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // 체력을 가져와서 변경하는 함수
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // 체력을 가져와서 변경하는 함수

	virtual void Attack(string enemy_Tribe) { // 공격하는 함수
		cout << "부모 클래스의 공격 함수는 호출되면 안됩니다. 오류입니다." << endl;
	}

	virtual void Attacked() { // 공격받는 함수
		cout << "부모 클래스의 공격 당하는 함수는 호출되면 안됩니다. 오류입니다." << endl;
	}


protected:
	string Unit_Name; // 유닛 이름
	int HP; // 내 유닛의 체력
	int ATK; // 내 유닛의 공격력
};

class Zerg : public Unit {
public:
	Zerg() : Unit_Name(NULL), HP(0), ATK(0) {}
	Zerg(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Zerg::HP = HP;
		Zerg::ATK = ATK;
	}

	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // 체력을 가져와서 변경하는 함수
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // 체력을 가져와서 변경하는 함수

private:
	string Unit_Name; // 유닛 이름
	int HP; // 체력
	int ATK; // 공격력
};

class Terran : public Unit {
public:
	Terran() : Unit_Name(NULL), HP(0), ATK(0) {}
	Terran(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Terran::HP = HP;
		Terran::ATK = ATK;
	}
	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // 체력을 가져와서 변경하는 함수
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // 체력을 가져와서 변경하는 함수
private:
	string Unit_Name; // 유닛 이름
	int HP; // 체력
	int ATK; // 공격력
};

class Protoss : public Unit {
public:
	Protoss() : Unit_Name(NULL), HP(0), ATK(0) {}
	Protoss(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Protoss::HP = HP;
		Protoss::ATK = ATK;
	}
	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // 체력을 가져와서 변경하는 함수
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // 체력을 가져와서 변경하는 함수


private:
	string Unit_Name; // 유닛 이름
	int HP; // 체력
	int ATK; // 공격력
};

class GameManager {
public:

private:

};

class Battle {
private:
	list<Unit>::iterator iter; // 반복자를 사용하기 위한 반복자 변수 선언
	string Battle_My_Unit_Name; // 배틀할 아군 유닛 선정
	string Battle_Enemy_Unit_Name; // 배틀할 적군 유닛 선정
	int My_ATK; // 아군 유닛의 데미지(공격력)
	int My_HP; // 아군 유닛의 체력
	int Enemy_ATK; // 적 유닛의 데미지(공격력)
	int Enemy_HP; // 적 유닛의 체력

public:
	void Fight(list<Unit>*& My_Units_list, list<Unit>*& Enemy_Units_list) {
		// 1. 싸움(공격) 처리 // 2. 승리/무승부/패배 팀 처리


#pragma region [1. 싸움(공격) 처리]
	// 1) 배틀할 아군 유닛들의 공격력 합과 체력의 합을 구한다. 2) 배틀할 적군 유닛의 공격력의 합과 체력의 합을 구한다.
	// 3) 적군과 전투 후 아군 체력 처리한다. 4) 아군과 전투 후 적군 체력 처리한다.
	// 5) 전투 결과를 출력한다.

		for (iter = My_Units_list->begin(); iter != My_Units_list->end(); iter++) {
			My_ATK = My_ATK + iter->Get_ATK(); // 1) 아군 유닛의 공격력의 합과 체력의 합을 받는다.
			My_HP = My_HP + iter->Get_HP(); // 아군 유닛들의 총 공격력 : My_ATK , 아군 유닛들의 총 HP : My_HP
		}

		for (iter = Enemy_Units_list->begin(); iter != Enemy_Units_list->end(); iter++) {
			Enemy_ATK = Enemy_ATK + iter->Get_ATK(); // 2) 배틀할 적군 유닛의 공격력의 합과 체력의 합을 받는다.
			Enemy_HP = Enemy_HP + iter->Get_HP(); // 적군 유닛들의 총 공격력 : Enemy_ATK , 아군 유닛들의 총 HP : Enemy_HP
		}
#pragma endregion

#pragma region [2. 승리/무승부/패배 팀 처리]
		while (My_HP > 0 && Enemy_HP > 0) { // 어느 팀이 죽을때까지 전투 연산
			My_HP = My_HP - Enemy_ATK; 	// 3) 적군과 전투 후 아군 유닛의 체력/사망 처리한다.
			Enemy_HP = Enemy_HP - My_ATK; // 4) 아군과 전투 후 적군 체력/사망 처리한다.
		} // while의 끝
		cout << "------- 전 투 결 과 -------" << endl;
		if (My_HP <= 0 && Enemy_HP > 0) {
			cout << "아군 유닛이 사망하였습니다." << endl;
			cout << "적군이 승리하였습니다." << endl;
		}
		else if (Enemy_HP <= 0 && My_HP > 0) {
			cout << "적군이 유닛이 사망하였습니다." << endl;
			cout << "아군이 승리하였습니다." << endl;
		}
		else {
			cout << "적 유닛들과 아군 유닛들 모두 사망하였습니다." << endl;
			cout << "무승부입니다." << endl;
		}
		cout << "------------------------" << endl;

#pragma endregion
	} // Fight 메서드의 끝
}; // Battle 클래스의 끝

int main(void) {
Restart: // 게임을 재시작 할 때 goto 함수를 통해 Restart 로 이동 -> label 지정
	string My_Tribe; // 내가 선택한 종족
	string enemy_Tribe; // 상대 종족 (내가 때리고자 하는 종족)
	string Unit_Name; // 각 종족의 유닛 이름 
	int individual; // 개체수
	Battle b; // Battle 클래스의 멤버 변수 및 함수에 접근하기 위한 객체 생성
	GameManager g; // GameManager 클래스의 멤버 변수 및 함수에 접근하기 위한 객체 생성
	char Restart_Game_Select; // 게임을 재시작할 것인지 확인 받는 변수

#pragma region 스타크래프트 유닛들을 담는 리스트 변수
	list<Unit>* My_Units_list = new list<Unit>; // 아군 유닛들을 담은 연결리스트
	list<Unit>* Enemy_Units_list = new list<Unit>; // 적군 유닛들을 담은 연결리스트
	list<Unit>::iterator iter; // 연결리스트에 접근하기 위한 반복자 포인터 (실제로 포인터는 아니고 포인터처럼 사용하도록 되어있음)
	int Set_HP; // <나의 종족 선택 및 유닛 생성> 단계에서 입력받은 HP
	int Set_ATK; // <나의 종족 선택 및 유닛 생성> 단계에서 입력받은 ATK
#pragma endregion

#pragma region <나의 종족 선택 및 유닛 생성>
	cout << "나의 종족을 선택하시오(문자열 입력)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> My_Tribe;
	while (My_Tribe != "Zerg" && My_Tribe != "Terran" && My_Tribe != "Protoss") // 종족 이름을 제대로 입력할 때까지 다시 입력받기
	{
		cout << "아군 종족 이름을 잘못 입력하셨습니다. 다시 입력해주세요." << endl;
		cout << "나의 종족을 선택하시오(문자열 입력)" << endl;
		cout << "1. Zerg 2. Terran 3. Protoss" << endl;
		cin >> My_Tribe;
	}

	cout << "아군 유닛의 개체수를 입력하시오 : "; cin >> individual;
	for (int i = 0; i < individual; i++) { // [아군] 유닛 정보 입력 받은 후 삽입
		cout << "유닛의 이름(별명)을 입력하세요 : "; cin >> Unit_Name;
		cout << Unit_Name << "의 체력을 입력하세요 : "; cin >> Set_HP;
		cout << Unit_Name << "의 공격력을 입력하세요 : "; cin >> Set_ATK;
		cout << "------- 유닛 정보 등록 완료(아군) -------" << endl;
		cout << "이름: " << Unit_Name << endl;
		cout << "HP: " << Set_HP << endl;
		cout << "ATK: " << Set_ATK << endl;
		cout << "-----------------------" << endl;
		My_Units_list->push_back(Unit(Unit_Name, Set_HP, Set_ATK));
	}
#pragma endregion

#pragma region <상대 종족 선택 및 유닛 생성>
	cout << "상대 종족을 선택하시오(문자열 입력)" << endl;
	cout << "1. Zerg 2. Terran 3. Protoss" << endl;
	cin >> enemy_Tribe;
	while (enemy_Tribe != "Zerg" && enemy_Tribe != "Terran" && enemy_Tribe != "Protoss") // 종족 이름을 제대로 입력할 때까지 다시 입력받기
	{
		cout << "적군 종족 이름을 잘못 입력하셨습니다. 다시 입력해주세요." << endl;
		cout << "상대 종족을 선택하시오(문자열 입력)" << endl;
		cout << "1. Zerg 2. Terran 3. Protoss" << endl;
		cin >> enemy_Tribe;
	}

	cout << "적군 유닛의 개체수를 입력하시오 : "; cin >> individual;
	for (int i = 0; i < individual; i++) { // [적군] 유닛 정보 입력 받은 후 삽입
		cout << "유닛의 이름(별명)을 입력하세요 : "; cin >> Unit_Name;
		cout << Unit_Name << "의 체력을 입력하세요 : "; cin >> Set_HP;
		cout << Unit_Name << "의 공격력을 입력하세요 : "; cin >> Set_ATK;
		cout << "------- 유닛 정보 등록 완료(적군) -------" << endl;
		cout << "이름: " << Unit_Name << endl;
		cout << "HP: " << Set_HP << endl;
		cout << "ATK: " << Set_ATK << endl;
		cout << "-----------------------" << endl;
		Enemy_Units_list->push_back(Unit(Unit_Name, Set_HP, Set_ATK));
	}
#pragma endregion

	b.Fight(My_Units_list, Enemy_Units_list); // Battle 클래스의 Fight 함수 호출 (싸움 결과 처리)
	cout << "다시 시작하시겠습니까? (Y/N) : "; cin >> Restart_Game_Select;

	if (Restart_Game_Select == 'Y') { // 게임 재시작
		cout << "새로운 게임을 시작합니다." << endl;
		goto Restart;
	}
	else if (Restart_Game_Select == 'N') { // 게임 종료
		cout << "게임을 종료합니다." << endl;
		exit(0);
	}

} // main 함수의 끝