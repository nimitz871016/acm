//
//  main.cpp
//  1003
//
//  Created by Nimitz_007 on 16/6/16.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    
    float a = 0;
    while (scanf("%f",&a)!=EOF && a > 1e-6) {
        float sum = 0;
        int i = 2;
        while (sum < a) {
            sum+= 1.0 /i;
            i++;
        }
        printf("%d card(s)\n",i-2);
    }
    return 0;
}
