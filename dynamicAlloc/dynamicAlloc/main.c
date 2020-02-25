//
//  main.c
//  dynamicAlloc
//
//  Created by Chan Yong Lee on 25.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int *arr = (int*)malloc(sizeof(int)*10);
    for(int i = 0 ; i < 10 ; i++){
        arr[i] = i+1;
        printf("%d \n", arr[i]);
    }
    
    int **parr = (int**)malloc(sizeof(int*)*3);
    for(int i = 0 ; i < 3; i++){
        parr[i] = (int*)malloc(sizeof(int)*3);
    }
    for(int i = 0 ; i < 9 ; i++){
        
    }
    return 0;
}
