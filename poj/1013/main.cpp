//
//  main.cpp
//  1013
//  简单题，主要是模拟情况，之前两次提交，一次是答案是错误。第二次是没有看清题意，每一次不一定称重4个硬币。
//  Created by Nimitz_007 on 16/8/5.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

void init(bool aa[],char c[]){
    for(int i = 0 ; i < strlen(c); i ++)
        aa[c[i] - 'A'] = true;
}
void even(int a[],bool aa[],char c[]){
    for(int i = 0; i < strlen(c); i ++){
        a[c[i] - 'A'] = 0;
        aa[c[i] - 'A'] = true;
    }
}
void up(int a[],bool aa[],char c[],char d[]){
    for(int i = 0; i < strlen(c); i++){
        if(aa[c[i] - 'A']){
            a[c[i] - 'A'] = 0;
        }else{
            a[c[i] - 'A'] ++;
        }
    }
    for(int i = 0; i < strlen(d); i++){
        if(aa[d[i] - 'A']){
            a[d[i] - 'A'] = 0;
        }else{
            a[d[i] - 'A'] --;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n,count;
    int a[12] = {0};
    bool aa[12] = {0};
    char b[5],c[5],d[5];
    scanf("%d",&n);
    while(n--){
        memset(a,0,sizeof(int)*12);
        memset(aa,0,sizeof(bool)*12);
        for(int i = 0; i < 12; i++){
            a[i] = 0;
        }
        count = 0;
        for(int i = 0; i < 3; i++){
            scanf("%s %s %s",b,c,d);
            if(!strcmp(d,"even")){
                count ++;
                even(a,aa,b);
                even(a,aa,c);
            }else if(!strcmp(d,"up")){
                up(a,aa,b,c);
            }else{
                up(a,aa,c,b);
            }
        }
        int result = 0;
        int index = 0;
        for(int i = 0; i < 12; i++){
            if(abs(a[i]) > abs(result)){
                result = a[i];
                index = i;
            }
        }
        if(result < 0){
            printf("%c is the counterfeit coin and it is light.\n",index + 'A');

        }else{
            printf("%c is the counterfeit coin and it is heavy.\n",index + 'A');
        }

    }
    return 0;
}
