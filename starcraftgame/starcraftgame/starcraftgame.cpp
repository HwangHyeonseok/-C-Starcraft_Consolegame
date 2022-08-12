#include <iostream>
#include <string>
#include <typeinfo> // class 이름 가져오기를 위한 라이브러리
#include <list>

using namespace std;

class Unit {
public:
	Unit() : Unit_Name(0), HP(0), ATK(0) {}
	Unit(string Unit_Name, int HP, int ATK) : Unit_Name(Unit_Name), HP(HP), ATK(ATK) { }

	//virtual void Set_Damage() { damage = ATK; }
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
	Zerg() : Unit_Name(0), HP(0), ATK(0) {}
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
	/*
	void Attack_Zerg(string enemy_Tribe) { // Zerg 유닛이 때리는 경우 (다른 유닛을 공격할 경우)
		cout << "--------------------전--------------------투--------------------로--------------------그--------------------" << endl;
		cout << "Zerg가 침을 뱉어 " << enemy_Tribe << "에게 " << ATK << "의 데미지를 입혔다." << endl;
	}

	void Attacked_Zerg() { // Zerg 유닛이 맞아야 되는 경우 (다른 유닛에게 공격당할 경우)
		if (Zerg::HP <= 0) // 체력이 0 이하라면
		{
			cout << "그러나 Zerg는 이미 죽어있어 공격할 수 없었다." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// 체력이 남아 있는 경우
			//Zerg::HP = Zerg::HP - damage;
			cout << "Zerg의 남은 체력은 " << Zerg::HP << " 입니다." << endl;
			if (Zerg::HP <= 0)
			{
				cout << "Zerg는 사망하였다." << endl;
			}
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
	*/
};

class Terran : public Unit {
public:
	Terran() : Unit_Name(0), HP(0), ATK(0) {}
	Terran(string Unit_Name, int HP, int ATK) : Unit(Unit_Name, HP, ATK) {
		Terran::HP = HP;
		Terran::ATK = ATK;
	}
	int Get_HP() { return HP; }
	virtual void Bring_HP(int HP_) { HP = HP_; } // 체력을 가져와서 변경하는 함수
	virtual void Bring_ATK(int ATK_) { ATK = ATK_; } // 체력을 가져와서 변경하는 함수
	/*
	void Attack(string enemy_Tribe) {
		Attack_Terran(enemy_Tribe);
	}

	void Attacked() {
		Attacked_Terran();
	}
	*/
private:
	string Unit_Name; // 유닛 이름
	int HP; // 체력
	int ATK; // 공격력
	/*
	void Attack_Terran(string enemy_Tribe) { // Terran 유닛이 때리는 경우 (다른 유닛을 공격할 경우)
		cout << "--------------------전--------------------투--------------------로--------------------그--------------------" << endl;
		cout << "Terran이 총을 쏴서 " << enemy_Tribe << "에게 " << ATK << "의 데미지를 입혔다." << endl;
	}

	void Attacked_Terran() { // Terran 유닛이 맞아야 되는 경우 (다른 유닛에게 공격당할 경우)
		if (Terran::HP <= 0) // 체력이 0 이하라면
		{
			cout << "그러나 Terran은 이미 죽어있어 공격할 수 없었다." << endl;
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
		else {// 체력이 남아 있는 경우
			//Terran::HP = Terran::HP - damage;  // Unit::ATK 값을 바꿔야함. ==> 저그 유닛의 ATK
			cout << "Terran의 남은 체력은 " << Terran::HP << " 입니다." << endl;
			if (Terran::HP <= 0)
			{
				cout << "Terran는 사망하였다." << endl;
				//delete this;
			}
			cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		}
	}
	*/
};

class Protoss : public Unit {
public:
	Protoss() : Unit_Name(0), HP(0), ATK(0) {}
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
	/*
	void Restart() {
		cout << "다시 시작하시겠습니까? (Y/N) : "; cin >> choose;

		if (choose = 'Y') { // 게임 재시작
			cout << "새로운 게임을 시작합니다." << endl;
		}
		else if (choose = 'N') { // 게임 종료
			cout << "게임을 종료합니다." << endl;
			exit(0);
		}
	}
	*/

private:
	//char Restart_Game_Select;
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
		// 1. 싸울 아군 유닛 선정 		// 2. 싸울 적군 유닛 선정
		// 3. 싸움(공격) 처리 // 4. 승리/무승부/패배 팀 처리

		while ((!(My_Units_list->empty())) && (!(Enemy_Units_list->empty()))) { // 아군 유닛이 다 죽었거나, 적군 유닛이 다 죽었을 경우 배틀 중단
			// My_Units_list->empty() => 리스트가 비었으면 true, 리스트에 클래스가 있다면 false 반환
			// 그래서 ! 연산자로 true와 false 를 전환 (리스트가 비었으면 false)

#pragma region [1. 싸울 아군 유닛 선정]
			cout << "배틀할 아군 유닛 한 개를 선정하세요. " << endl;
			cout << "------ 배틀 가능한 아군 유닛 -------" << endl;
			for (iter = My_Units_list->begin(); iter != My_Units_list->end(); iter++) { // 살아 있는 아군 유닛의 정보를 가져온다.
				cout << "이름 : " << iter->Get_Unit_Name() << " ";
				cout << "HP : " << iter->Get_HP() << " ";
				cout << "ATK : " << iter->Get_ATK() << " " << endl;
			}
			cout << "-----------------------------------" << endl;
			cout << "배틀할 아군 유닛 : ";
			cin >> Battle_My_Unit_Name; cout << endl;
#pragma endregion

#pragma region [2. 싸울 적군 유닛 선정]
			cout << "배틀할 적군 유닛 한 개를 선정하세요. " << endl;
			cout << "------ 배틀 가능한 적군 유닛 -------" << endl;
			for (iter = Enemy_Units_list->begin(); iter != Enemy_Units_list->end(); iter++) { // 살아 있는 아군 유닛의 정보를 가져온다.
				cout << "이름 : " << iter->Get_Unit_Name() << " ";
				cout << "HP : " << iter->Get_HP() << " ";
				cout << "ATK : " << iter->Get_ATK() << " " << endl;
			}
			cout << "-----------------------------------" << endl;
			cout << "배틀할 적군 유닛 : ";
			cin >> Battle_Enemy_Unit_Name; cout << endl;
			cout << Battle_My_Unit_Name << " 와 " << Battle_Enemy_Unit_Name << " 가 싸움을 시작합니다." << endl;
#pragma endregion

#pragma region [3. 싸움(공격) 처리]
			// 1) 배틀할 아군 유닛의 공격력과 체력을 받는다. 2) 배틀할 적군 유닛의 공격력과 체력을 받는다.
			// 3) 적군과 전투 후 아군 체력 처리한다. 4) 아군과 전투 후 적군 체력 처리한다.
			// 5) 전투 결과를 출력한다.

			for (iter = My_Units_list->begin(); iter != My_Units_list->end(); iter++) {
				if (iter->Get_Unit_Name() == Battle_My_Unit_Name) // 배틀할 아군 유닛을 찾는다.
				{
					My_ATK = iter->Get_ATK(); // 1) 배틀할 아군 유닛의 공격력과 체력을 받는다.
					My_HP = iter->Get_HP();
				}
			}

			for (iter = Enemy_Units_list->begin(); iter != Enemy_Units_list->end(); iter++) {
				if (iter->Get_Unit_Name() == Battle_Enemy_Unit_Name) // 배틀할 아군 유닛을 찾는다.
				{
					Enemy_ATK = iter->Get_ATK(); // 2) 배틀할 적군 유닛의 공격력과 체력을 받는다.
					Enemy_HP = iter->Get_HP();
				}
			}

			for (iter = My_Units_list->begin(); iter != My_Units_list->end(); iter++) {
				if (iter->Get_Unit_Name() == Battle_My_Unit_Name) // 배틀할 아군 유닛을 찾는다.
				{
					My_HP = My_HP - Enemy_ATK; // 3) 적군과 전투 후 아군 유닛의 체력/사망 처리한다.
					iter->Bring_HP(My_HP);
					if (My_HP <= 0) { // 체력이 0이면
						cout << Battle_My_Unit_Name << " 이 죽었습니다." << endl;
						My_Units_list->erase(iter); // 배틀하다 죽은 유닛의 원소를 삭제해준다.
						break; // break; 을 해주지 않으면 계속 for 루프 조건 검사를 하기 때문에 오류가 발생한다.
					}
				}
			}

			for (iter = Enemy_Units_list->begin(); iter != Enemy_Units_list->end(); iter++) {
				if (iter->Get_Unit_Name() == Battle_Enemy_Unit_Name) // 배틀할 적군 유닛을 찾는다.
				{
					Enemy_HP = Enemy_HP - My_ATK; // 4) 아군과 전투 후 적군 체력/사망 처리한다.
					iter->Bring_HP(Enemy_HP);
					if (Enemy_HP <= 0) { // 체력이 0이면
						cout << Battle_Enemy_Unit_Name << " 이 죽었습니다." << endl;
						Enemy_Units_list->erase(iter); // 배틀하다 죽은 유닛의 원소를 삭제해준다.
						break; // break; 을 해주지 않으면 계속 for 루프 조건 검사를 하기 때문에 오류가 발생한다.
					}
				}
			}

			cout << "------- 전 투 결 과 -------" << endl;
			cout << Battle_My_Unit_Name << " 은 " << Battle_Enemy_Unit_Name << " 에게 " << My_ATK << " 만큼의 피해를 주었습니다." << endl;
			cout << Battle_Enemy_Unit_Name << " 은 " << Battle_My_Unit_Name << " 에게 " << Enemy_ATK << " 만큼의 피해를 주었습니다." << endl;
			cout << Battle_My_Unit_Name << " 의 체력은 " << My_HP << " 남았습니다." << endl;
			if (My_HP <= 0) { cout << Battle_My_Unit_Name << " 이 사망하였습니다." << endl; }
			cout << Battle_Enemy_Unit_Name << " 의 체력은 " << Enemy_HP << " 남았습니다." << endl;
			if (Enemy_HP <= 0) { cout << Battle_Enemy_Unit_Name << " 이 사망하였습니다." << endl; }
			cout << "------------------------" << endl;

#pragma endregion

#pragma region [4. 승리/무승부/패배 팀 처리]
			if ((My_Units_list->empty()) && (!(Enemy_Units_list->empty()))) // 아군 유닛 리스트에 생존한 유닛이 없으면 (적팀 유닛은 생존해있음)
			{
				cout << "----------전 투 종 료---------" << endl;
				cout << "아군의 유닛이 모두 죽었습니다. 적에게 패배하였습니다." << endl;
				cout << "----------------------" << endl;
			}
			else if ((!(My_Units_list->empty())) && (Enemy_Units_list->empty())) // 적군 유닛 리스트에 생존한 유닛이 없으면 (우리팀 유닛은 생존해있음)
			{
				cout << "----------전 투 종 료---------" << endl;
				cout << "적을 모두 처치하여 승리하였습니다." << endl;
				cout << "----------------------" << endl;
			}

			else if ((My_Units_list->empty()) && (Enemy_Units_list->empty())) // 아군, 적군 유닛 모두 동시에 사망한 경우 
			{
				cout << "----------전 투 종 료---------" << endl;
				cout << "적과 아군이 동시에 사망하였습니다. 무승부입니다." << endl;
				cout << "----------------------" << endl;
			}
#pragma endregion
		} // while(1) 의 끝
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
	/*
#pragma region [예외처리] 아군 종족과 적군 종족이 같은 경우 -> 오류 메시지 출력 후 재질문
	if (My_Tribe.compare(enemy_Tribe) == 0)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "같은 종족은 선택할 수 없습니다." << endl;
		cout << "유닛을 다시 선택해주세요." << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		for (iter = My_Units_list->begin(); iter != My_Units_list->end(); ) // 잘못 입력했던 모든 아군 유닛 정보을 제거 (적군 정보는 아직 입력되지 않았으므로 아군 유닛 정보만 제거하면 된다.)
		{
			My_Units_list->erase(iter++);
		}
		continue;
	}
#pragma endregion
*/

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
	//g.Restart(); // GameManager 클래스의 Restart 함수 호출 (다시 시작 여부 조사)
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

