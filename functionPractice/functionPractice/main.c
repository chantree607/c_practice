//
//  main.c
//  functionPractice
//
//  Created by Chan Yong Lee on 23.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>

void descendingSort(int *arr, int size);
void manipulate2dArray(int (*arr)[3], int size);

int main(int argc, const char * argv[]) {
        
    int arr[10];
    
    for(int i = 0 ; i < 10 ; i++){
        printf("please enter a number : \n");
        scanf("%d", &arr[i]);
    }
    
    descendingSort(arr, 10);
    
    for(int i = 0 ; i < 10 ; i++){
        printf("%d \n", arr[i]);
    }
    
    return 0;
}

void descendingSort(int *arr, int size){
    
    int swapped = 1;
    
    while(swapped){
        swapped = 0;
        for(int i = 1 ; i < 10 ; i++){
            if(*(arr + i - 1) < *(arr + i)){
                int tmp = *(arr + i);
                *(arr + i) = *(arr + i - 1);
                *(arr + i - 1) = tmp;
                swapped = 1;
            }
        }
    }
    

}
