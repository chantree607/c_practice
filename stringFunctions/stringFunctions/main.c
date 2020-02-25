//
//  main.c
//  stringFunctions
//
//  Created by Chan Yong Lee on 22.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>

int countChars(char* str);
char* mergeStr(char* str1, char* str2);
char* copyStr(char* str);
int compareStr(char* str1, char* str2);

int main(int argc, const char * argv[]) {
    
    int t = countChars("hello world");
    
    char* merge = mergeStr("hello", "world");
    
    char* copiedStr= copyStr("lee chan yong");
    
    int compare = compareStr("lee chan yong", "le chan yong");
    
    return 0;
}


int countChars(char* str){
    
    int counter = 0;
    //char* tmpAddr = str;
    
    /*
    while(*(tmpAddr+counter)){
        counter++;
    }
     */
    //if a string was given to this function, than it is a array of chars
    //so we can get chars using index
    while(str[counter]){
        counter++;
    }
        
    return counter;
}

char* copyStr(char* str){
    int counter = 0;
    while(str[counter]){
        counter++;
    }
    
    char res[counter];
    
    for(int i = 0 ; i < counter ; i++){
        res[i] = str[i];
    }
    
    return res;
}

char* mergeStr(char* str1, char* str2){
    
    int counter1 = 0;
    while(str1[counter1]){
        counter1++;
    }
    
    int counter2 = 0;
    while(str2[counter2]){
        counter2++;
    }
    
    char resStr[counter1 + counter2];
    
    for(int i = 0 ; i < counter1 ; i++){
        resStr[i] = str1[i];
    }
    for(int i = 0 ; i < counter2 ; i++){
        resStr[counter1 + i]  = str2[i];
    }
    
    return resStr;
}

int compareStr(char* str1, char* str2){
    
    int counter = 0;
    
    while(str1[counter]){
        if(str1[counter] != str2[counter]){
            return 0;
        }
        if(str1[counter] == 0 && str2[counter] != 0){
            return 0;
        }
        if(str2[counter] == 0 && str1[counter] != 0){
            return 0;
        }
        
        counter++;
    }
    
    return 1;
}

