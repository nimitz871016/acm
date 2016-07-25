//
//  main.cpp
//  1517
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
    long a[7] = {6,24,120,720,5040,40320,362880};
    double sum = 2.5;
    for (int i = 3; i <= 9; i++) {
        sum += 1.0 / a[i - 3];
        printf("%d %.9f\n",i,sum);
    }
    return 0;
}
