//
//  main.cpp
//  1565
//
//  Created by Nimitz_007 on 16/7/29.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    char str[32];
    long sum;
    while(scanf("%s",str) && strcmp(str,"0")){
        sum = 0;
        size_t length = strlen(str);
        for(int i = 0;i < length; i++){
            sum += (pow(2.0,(int)length - i) - 1) * (str[i] - '0');
        }
        printf("%ld\n",sum);
    }
    return 0;
}
