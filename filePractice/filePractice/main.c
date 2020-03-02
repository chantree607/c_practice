//
//  main.c
//  filePractice
//
//  Created by Chan Yong Lee on 27.02.20.
//  Copyright © 2020 Chan Yong Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    //writing a file
    /*
    FILE *fp;
    fp = fopen("a.txt", "w");
    
    if(fp == NULL){
        printf("Write Error \n");
        return 0;
    }
    
    fputs("Hello World \n", fp);
    
    fclose(fp);
    */
    
    //----------------------------------------------------------------
    //reading a file
    /*
    FILE *fp = fopen("a.txt", "r");
    
    char buf[20];
    
    if(fp == NULL){
        printf("Read Error \n");
        return 0;
    }
    
    fgets(buf, 20, fp);
    printf("%s \n", buf);
    fclose(fp);
    return 0;
    */
    
    //----------------------------------------------------------------
    //reversing the text in a file
    FILE* fpRead = fopen("a.txt", "r");
    if(fpRead == NULL){
        printf("Write Error \n");
        return 0;
    }
    //fseek(fpRead, 0, SEEK_END);
    
    FILE* fpWrite = fopen("b.txt", "w");
    if(fpWrite == NULL){
        printf("Write Error \n");
        return 0;
    }
    
    /*
    char c;
    int size = 0;
    while((c = fgetc(fpRead)) != EOF){
        size++;
        fputc(32, fpWrite);
        fputc(c, fpWrite);
        fseek(fpWrite, -2, SEEK_CUR);
        printf("%c", c);
    }
     */
    
    /*
    char* copySrc = (char*)malloc(sizeof(char)*size);
    char* copyDest = (char*)malloc(sizeof(char)*size);
    fpRead = fopen("a.txt", "r");
    for(int i = 0 ; i < size; i++){
        *(copySrc + i) = fgetc(fpRead);
        *(copyDest + size - i -1 ) = *(copySrc + i);
    }
    
    
    fputs(copyDest, fpWrite);
     */
}
