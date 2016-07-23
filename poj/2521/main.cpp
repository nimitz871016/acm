//
//  main.cpp
//  2521
//  水的都不想写了
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,m,p,c;
    while (scanf("%d %d %d %d",&n,&m,&p,&c)) {
        if (n == 0 && m == 0 && p ==0 && c == 0) {
            break;
        }
        printf("%d\n",p - m + n);
    }
    return 0;
}
