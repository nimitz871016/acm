//
//  main.cpp
//  3673
//
//  Created by Nimitz_007 on 16/7/19.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    char a[10],b[10];
    int sum = 0;
    while (scanf("%s %s",a,b)!=EOF) {
        sum = 0;
        for (int i = 0; i < strlen(a); i++) {
            for (int j = 0; j < strlen(b); j++) {
                sum += (a[i] - '0') * (b[j] - '0');
            }
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
