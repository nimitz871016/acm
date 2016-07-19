//
//  main.cpp
//  2109
//  http://blog.csdn.net/code_pang/article/details/8263971
//  Created by Nimitz_007 on 16/7/18.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

int main() {
    double n, p;
    while(scanf("%lf%lf", &n, &p) != EOF)
    {
        printf("%.0lf\n", pow(p, 1/n));
    }
    return 0;
}
