//
//  main.c
//  maxAncestorDiff
//
//  Created by Chan Yong Lee on 23.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>


bool isNStraightHand(int* hand, int handSize, int W);
int findElement(int *arr, int size, int k);

int main(int argc, const char * argv[]) {
    int arr[9] = {1,2,3,6,2,3,4,7,8};
    
    bool tmp = isNStraightHand(arr, 9, 3);
    
    return 0;
}

bool isNStraightHand(int* hand, int handSize, int W){
    
    if(handSize % W != 0){
        return false;
    }
    
    for(int i = 0 ; i < handSize/W ; i++){
        
        int minInd = 0;
        for(int j = 0 ; j < handSize ; j++){
            if( *(hand + minInd) > *(hand + j)){
                minInd = j;
            }
        }
        
        int min = *(hand + minInd);
        int nextInd = findElement(hand, handSize, min + 1);
        int nextnextInd = findElement(hand, handSize, min + 2);
        if(nextInd != -1 && nextnextInd != -1){
            *(hand + minInd) = 2147483647;
            *(hand + nextInd) = 2147483647;
            *(hand + nextnextInd) = 2147483647;
        }
        else{
            return false;
        }
        
    }
    
    return true;
}


int findElement(int *arr, int size, int k){
    for(int i = 0 ; i < size; i++){
        if(*(arr + i) == k){
            return i;
        }
    }
    return -1;
}






