//
//  main.c
//  pointerPractice
//
//  Created by Chan Yong Lee on 23.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    int (*arrPointer)[10] = &arr; //말그대로 크기 10의 배열을 가리키는 포인터
    int* pa = &arr; //정확히 말하면 안됨. 크기 10의 배열을 가리키는 포인터에 할당해야함
    int* ap = arr; //됨. sizeof나 &랑 같이 쓰인게 아니라서, 배열의 이름이 배열의 첫번째 원소를 나타내는 포인터가됨
    /*
    int* parr = &a[0];
    
    for(int i = 0 ; i < 10 ; i++){
        printf("arr[%d]의 주소값 : %p ", i, &a[i]);
        printf("(parr + %d) 의 값 : %p ", i, parr+i);
    }
     */
    
    printf("arr의 정체 : %p \n", arr);
    printf("\n");
    printf("arr[0]의 주소값: %p \n", &arr[0]);
    printf("\n");
    //아래와 같이 배열의 이름이 & 연산자와 같이 쓰일때에는, 배열의 이름이 배열의 첫번째 원소를 가리키는 포인터의 역할로 쓰이지 않는다
    //즉 &arr은 arr 자체의 주소가 되는 것이다.
    //아마 arr의 시작점이 arr[0]의 시작점과 같아서, &arr과 arr, 그리고 &arr[0] 셋 다 같은 값을 취하는 것 같다.
    //(씹어먹는 C 에서는, arr 자체가 메모리에 어떠한 공간에 존재하지 않아서 라고 한다)
    //(arr는 일종의 형식일 뿐이다 - 어떤 연산자와 쓰이냐에 따라서 그 의미가 달라지니까)
    //그러나 &arr과 arr은, 가지고 있는 값은 같으나, 데이터타입이 다르다
    //&arr은 말그대로 크기 10짜리 배열을 가리키는 포인터이고
    //arr은 (sizeof나 &가 쓰이지 않았으므로) &arr[0], 즉 int를 가리키는 포인터와 같다.
    //즉, &arr과 arr이 같은 값을 가지고 있더라도, 서로 데이터타입에서 다르며, 각 변수를 이용해서 arr의 원소에 접근하는 방법도 다르다.
    //&arr은 arr의 주소값을 가지고 있으므로, *(&arr)을 해야 arr를 얻을수 있다.
    printf("&arr의 값 %p \n", &arr);
    printf("\n");
    printf("arrPointer의 값 %p \n", arrPointer);
    printf("\n");
    printf("&arrPointer의 값 %p \n", &arrPointer);
    printf("\n");
    printf("*arrPointer의 값 %p \n", *arrPointer);
    printf("\n");
    printf("**arrPointer의 값: %d \n", **arrPointer);
    printf("*(*arrPointer + 1)의 값: %d \n", *(*arrPointer+1));
    printf("(*arrPointer)[1]의 값: %d \n", (*arrPointer)[1]);
    printf("*(*arrPointer + 2)의 값: %d \n", *(*arrPointer+2));
    printf("*(*arrPointer + 3)의 값: %d \n", *(*arrPointer+3));
    printf("*(*arrPointer + 4)의 값: %d \n", *(*arrPointer+4));
    printf("*(*arrPointer + 5)의 값: %d \n", *(*arrPointer+5));
    printf("*(*arrPointer + 6)의 값: %d \n", *(*arrPointer+6));
    printf("\n");
    printf("arr + 1 의 값 %p \n", arr + 1);
    printf("\n");
    printf("&arr + 1 의 값 %p \n", &arr + 1);
    printf("\n");
    printf("*arr 의 값 : %d \n", *arr);
    printf("\n");
    printf("*(&arr) 의 값 : %p \n", *(&arr));
    printf("\n");
    printf("sizeof(arr)의 값 : %d \n", sizeof(arr));
    printf("\n");
    printf("sizeof(arrPointer)의 값 : %d \n", sizeof(arrPointer));
    printf("\n");
    
    //---------------------------------------------------------------------------------------------------
    
    int dArr[2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,0,1,2}},{{3,4,5,6},{7,8,9,0},{1,2,3,4}}};
    int (*dParr)[3][4] = dArr;
    int (*dParr1)[3][4] = dArr+1;
    return 0;
}
