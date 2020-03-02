//
//  main.cpp
//  starcraft
//
//  Created by Chan Yong Lee on 28.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>
#include <string.h>

class Marine{
    
    static int total_marine_num;
    const static int i = 0;
    
    int hp;
    int coord_x, coord_y;
    const int default_damage;
    bool is_dead;
    //char* name;
    
public:
    //default constructor
    Marine();
    Marine(int x, int y, int damage);
    //Marine(int x, int y, const char* marine_name);
    ~Marine();
    
    //returns damage
    int attack();
    
    Marine& be_attacked(int damage_earn);
    
    //new position
    void move(int x, int y);
    
    void show_status();
    static void show_total_marine();
};

class Photon_Cannon{
private:
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    
    char *name;
    
public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon& pc);
    ~Photon_Cannon();
    
    void show_status();
};

int Marine::total_marine_num= 0;

Marine::Marine()
: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false){
    total_marine_num++;
}

//member variable로 const인 variable이 있으면, 무조건 초기화리스트로 생성사를 작성해야 하나보다. 왜냐하면 const variable은 declare과 동시에 initilaization이 되야 되는데, 그역할을 초기화리스트가 담당한다.
Marine::Marine(int x, int y, int damage)
: coord_x(x), coord_y(y), hp(50), default_damage(damage), is_dead(false){
    total_marine_num++;
}

//그럼 내가 밑에 코멘트처리 한 부분과 같이 string은 어떻게? 나중에 어차피 string 라이브러리 써서 크게 상관없나?
/*
Marine::Marine(int x, int y, const char* marine_name){
    //+1 because of null string
    name = new char[strlen(marine_name) + 1];
    //위와 같이 생성자 내부에서 동적할당한 메모리는 그냥 인스턴스를 delete한다고 사라지지 않나보다
    //그래서 소멸자(destructor)에서 직접 제거해줘야한다.
    strcpy(name, marine_name);
    hp = 50;
    coord_x = x;
    coord_y = y;
    default_damage = 5;
    is_dead = false;
}
 */
int Marine::attack(){
    return default_damage;
}
Marine& Marine::be_attacked(int damage_earn){
    hp -= default_damage;
    if(hp <= 0){
        is_dead = true;
    }
    
    return *this;
}
void Marine::show_status() {
  std::cout << " *** Marine : " << /*name <<*/ " ***" << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}
Marine::~Marine() {
  //std::cout << name << " 의 소멸자 호출 ! " << std::endl;
    /*
  if (name != NULL) {
    delete[] name;
  }
     */
    total_marine_num--;
     
}

void Marine::show_total_marine(){
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
    
Photon_Cannon::Photon_Cannon(int x, int y) {
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = NULL;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = new char[strlen(cannon_name) + 1];
  strcpy(name, cannon_name);
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    std::cout<<"복사생성자 호출"<<std::endl;
    hp = pc.hp;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    shield = pc.shield;
    
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
    
    
}
Photon_Cannon::~Photon_Cannon() {
  // 0 이 아닌 값은 if 문에서 true 로 처리되므로
  // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
  // if(name != 0) 과 동일한 의미를 가질 수 있다.

  // 참고로 if 문 다음에 문장이 1 개만 온다면
  // 중괄호를 생략 가능하다.

  if (name) delete[] name;
}
void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

void create_marine(){
    Marine marine3(10,10,4);
    marine3.show_status();
}

int main(int argc, const char * argv[]) {
    
    
    Marine* marines[100];
    
    marines[0] = new Marine(2, 3, 5);
    marines[0]->show_status();
    
    marines[1] = new Marine(1, 5, 10);
    marines[1]->show_status();
    
    create_marine();
    

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
    marines[1]->be_attacked(marines[0]->attack()).be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();
    
    delete marines[0];
    delete marines[1];
    
    Marine::show_total_marine();
    
    /*
      Photon_Cannon pc1(3, 3, "Cannon");
      Photon_Cannon pc2 = pc1;

      pc1.show_status();
      pc2.show_status();
    */
    
    return 0;
}
