//
//  main.cpp
//  3094
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    char str;
    int sum = 0,index = 1;
    while (scanf("%c",&str) && str != '#') {
        if (str != '\n') {
            sum += index * (str == ' ' ? 0 : str - 'A' + 1);
            index ++;
        }else{
            printf("%d\n",sum);
            index = 1;
            sum = 0;
        }
    }
    return 0;
}
