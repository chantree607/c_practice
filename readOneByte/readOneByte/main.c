//
//  main.c
//  readOneByte
//
//  Created by Chan Yong Lee on 25.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>

void readOneByte(void* p, int byte);

int main(int argc, const char * argv[]) {
    
    int p[1] = {0x1234};
    
    readOneByte(p, 4);
    return 0;
}

void readOneByte(void* p, int byte){
    for(int i = 0 ; i < byte; i++){
        printf("%x \n", *(char *)p);
        p++;
    }
}
