//
//  main.c
//  mainCalculator
//
//  Created by Chan Yong Lee on 25.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int firstCounter = 0;
    while(*(argv[1])){
        firstCounter++;
        argv[1]++;
    }
    int secondCounter = 0;
    while(*(argv[3])){
        secondCounter++;
        argv[3]++;
    }
    
    argv[1] -= firstCounter;
    argv[3] -= secondCounter;
    
    int first = 0;
    for(int i = 0 ; i < firstCounter ; i++){
        first += (*(argv[1] + i) - 48)*(int)(pow(10,(double)(firstCounter - i -1)));
        //printf("%d \n", (*(argv[1] + i) - 48)*(int)(pow(10,(double)(firstCounter - i -1))));
    }
    int second = 0;
    for(int i = 0 ; i < secondCounter ; i++){
        second += (*(argv[3] + i) - 48)*(int)(pow(10,(double)(secondCounter - i -1)));
        //printf("%d \n", (*(argv[3] + i) - 48)*(int)(pow(10,(double)(secondCounter - i -1))));
    }
    
    
    int res = first + second;
    
    printf("%d \n", res);
     

    return 0;
}
