//
//  main.cpp
//  1477
//  水题，太不应该了，格式改了3次
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n,*a;
    int j = 1;
    while (scanf("%d",&n) && n != 0) {
        a = (int *)malloc(sizeof(int)*n);
        int avg = 0;
        for (int i = 0 ; i < n; i++) {
            scanf("%d",&a[i]);
            avg += a[i];
        }
        avg /= n;
        int steps = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < avg) {
                steps += avg - a[i];
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",j++,steps);
    }
    return 0;
}
