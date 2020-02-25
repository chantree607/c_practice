//
//  main.c
//  stringPractice
//
//  Created by Chan Yong Lee on 24.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    char sentence1[5] = {'c', 'h', 'a', 'n', '\0'};
    char sentence2[5] = {'c', 'h', 'a', 'n', 0};
    char sentence3[5] = {'c', 'h', 'a', 'n', (char)NULL};
    
    printf("%s \n", sentence1);
    printf("%s \n", sentence2);
    printf("%s \n", sentence3);
    return 0;
    */
    
    /*
    int a;
    char c;
    char str[30];
    
    printf("숫자를 입력하세요 : \n");
    scanf("%d", &a );
    
    fflush(stdin);
    
    printf("문자를 입력하세요 : \n");
    scanf("%c", &c );
    
    printf("단어를 입력하세요 : \n");
    scanf("%s", str );
    
    printf("%d \n", a);
    printf("%c \n", c);
    printf("%s \n", str);
     */
    
    //string pratcic - string as a char pointer
    //even though we don't declare string as a array, a null-string will be declared and initialized
    char *str = "sentence";
    while(*str != 0){
        printf("%c", *str);
        str++;
    }
}
