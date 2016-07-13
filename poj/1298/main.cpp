//
//  main.cpp
//  1298
//
//  Created by Nimitz_007 on 16/7/13.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    char *str,*result;
    str = (char *)malloc(sizeof(char)*200);
    result = (char *)malloc(sizeof(char)*200);
    memset(str,0,200);
    memset(result,0,200);
    bool flag = false;
    while(scanf("%s",str) && strcmp(str,"ENDOFINPUT")){
        if(!strcmp(str,"START")){
            continue;
        }
        if(!strcmp(str,"END")){
            flag = false;
            printf("\n");
            continue;
        }else if(strcmp(str, "END") && flag){
            printf(" ");
        }
        for(int i = 0; i < strlen(str); i++){
            flag = true;
            if(str[i] <= 'Z' && str[i] >= 'A'){
                printf("%c",(str[i] - 'A' + 21)%26 + 'A');
            }else{
                printf("%c",str[i]);
            }
        }
    }
    return 0;
}
