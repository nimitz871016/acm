//
//  main.cpp
//  2390
//
//  Created by Nimitz_007 on 16/7/20.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

int main() {
    int r,m,y;
    double sum = 0;
    while (scanf("%d%d%d",&r,&m,&y)!=EOF) {
        sum = m;
        for (int i = 0; i < y; i++) {
            sum = (1.0 * r / 100 + 1) * sum;
        }
        printf("%d\n",(int)floor(sum));
    }
    return 0;
}
