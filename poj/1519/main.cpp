//
//  main.cpp
//  1519
//  水题，啃爹，高精度题没提示，这不关键，叫我怎么判断你的位数呢，只好开个足够大的了。
//  Created by Nimitz_007 on 16/7/20.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>

int split1(int n){
    int *a;
    int num = 0;
    while (n / pow(10.0, num)){
        num++;
    }
    a = (int *) malloc(sizeof(int)*num);
    int temp = n;
    for (int i = 0; i < num; i++) {
        a[i] = temp / pow(10.0,num - i - 1);
        temp -= a[i] * pow(10.0,num - i - 1);
    }
    temp = 0;
    for (int i = 0; i < num; i++) {
        temp += a[i];
    }
    return temp;
}

int split(char *str){
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += str[i] - '0';
    }
    return sum;
}
int main(){
    char *str;
    int n;
    str = (char *)malloc(sizeof(char)*1000);
    while (scanf("%s",str) && strcmp(str,"0")) {
            n = split(str);
            do{
                n = split1(n);
            }while(n >= 10);
            printf("%d\n",n);
    }
    return 0;
}