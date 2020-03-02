//
//  main.cpp
//  reference
//
//  Created by Chan Yong Lee on 27.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <iostream>

void change_val(int& val);

int main(int argc, const char * argv[]) {
    /*
    int p = 5;
    std::cout << p << std::endl;
    change_val(p);
    std::cout << p << std::endl;
    return 0;
    */
    
    //what is reference?
    /*
    int a = 10;
    int &ref = a;
    printf("a의 값은 : %d \n", a);
    printf("ref의 값은 : %d \n", ref);
    printf("a의 주소값은 : %p \n",&a);
    printf("ref의 주소값은 : %p \n",&ref);
    printf("이말은 즉슨, ref는 그냥 완전히 a랑 같게 쓰인다. 즉 a를 다른이름으로 부르는것 뿐이다 \n");
     */
    
    //reference of an array
    int arr[3] = {1,2,3};
    int (&ref)[3] = arr;
    
    ref[0] = 10;
    
    for(int i = 0 ; i < 3 ; i++){
        printf("%d \n", arr[i]);
    }
    
    //포인터의 레퍼런스는 가능할까?
    //그게 가능하면 배열과도 연관지을수 있을까?
    
    
    return 0;
    
}

void change_val(int& val){
    val = 3;

}
