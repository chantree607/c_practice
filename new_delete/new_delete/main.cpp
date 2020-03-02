//
//  main.cpp
//  new_delete
//
//  Created by Chan Yong Lee on 28.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>

typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
}Animal;

void create_animal(Animal* animal);
void show_stat(Animal* animal);
void play(Animal *animal);
void one_day_pass(Animal* animal);

int main(int argc, const char * argv[]) {
    
    //basic example
    /*
    int* p = new int;
    *p = 10;
    std::cout << *p;
    delete p;
    return 0;
     */
    
    //allocating array using new
    /*
    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    
    int *list = new int[arr_size];
    for(int i = 0 ; i < arr_size ; i++){
        std::cin >> list[i];
    }
    for(int i = 0 ; i < arr_size ; i++){
        std::cout << i << "th element of list: " << list[i] << std::endl;
    }
    
    delete[] list;
    return 0;
     */
    Animal *list[10];
    int index = 0;
    
    while(1){
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기" << std::endl;
        std::cout << "3. 상태보기" << std::endl;
        std::cout << "4. 종료" << std::endl;
        
        int input;
        std::cin >> input;
        
        if(input == 4){
            break;
        }
        switch (input) {
            case 1:
                if(index > 9){
                    printf("no more animal can be added");
                }
                else{
                    list[index] = new Animal;
                    create_animal(list[index]);
                    index++;
                }
                break;
            
            case 2:
                int play_with;
                std::cout << "index of the animal: ";
                std::cin >> play_with;
                if(play_with > index){
                    std::cout << "there is no animal with given index" <<std::endl;
                }
                else{
                    play(list[play_with]);
                }
                break;
                
            case 3:
                int stat;
                std::cout << "index of the animal: ";
                std::cin >> stat;
                if(stat > index){
                    std::cout << "there is no animal with given index" <<std::endl;
                }
                else{
                    show_stat(list[stat]);
                }
                break;
                
            default:
                break;
        }
        for(int i = 0 ; i < index ; i++){
            one_day_pass(list[i]);
        }
    }
    
    for(int i = 0; i< index ; i++){
        delete list[i];
    }
}

void create_animal(Animal* animal){
    std::cout << "what is the name of the animal? : ";
    std::cin >> animal->name;
    
    std::cout << "what is the age of the animal? : ";
    std::cin >> animal->age;
    
    animal->clean = 100;
    animal->food = 100;
    animal->health = 100;
}

void show_stat(Animal* animal){
    std::cout << "name : " << animal->name << std::endl;
    std::cout << "age : " << animal->age << std::endl;
    std::cout << "clean : " << animal->clean << std::endl;
    std::cout << "food : " << animal->food << std::endl;
    std::cout << "health : " << animal->health << std::endl;
}

void play(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal* animal){
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}
