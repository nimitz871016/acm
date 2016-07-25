//
//  main.cpp
//  2017
//
//  Created by Nimitz_007 on 16/7/3.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n;
    int speed,hours;
    int preTime,total;
    while (scanf("%d",&n) && n != -1) {
        total = 0;
        preTime = 0;
        for (int i = 0 ; i < n; i++) {
            scanf("%d %d",&speed,&hours);
            total += speed * (hours - preTime);
            preTime = hours;
        }
        printf("%d miles\n",total);
    }
    return 0;
}
