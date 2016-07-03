//
//  main.cpp
//  2000
//
//  Created by Nimitz_007 on 16/7/2.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

int main() {
    int n;
    int sum[101];
    for (int i = 1; i <= 100; i++) {
        sum[i] = i * i;
    }
    while (scanf("%d",&n) && n) {
        int k = floor(0.5*(sqrt(8 * n +1) -1));
        int left = n - (k * k + k) * 0.5;
        int total = 0;
        for (int i = 0; i < k; i++) {
            total += sum[i+1];
        }
        printf("%d %d\n",n, sum[k] + left * (k + 1));
    }
    return 0;
}
