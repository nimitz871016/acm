//
//  main.cpp
//  2350
//  水题，没啥好说的了。
//  Created by Nimitz_007 on 16/7/22.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n,m,count,*a;
    double avg;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&m);
        a = (int *)malloc(sizeof(int)*m);
        avg = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d",&a[i]);
            avg += a[i];
        }
        avg = avg / m;
        count = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] > avg) {
                count++;
            }
        }
        printf("%.3f%%\n",count * 100.0 / m);
        free(a);
    }
    return 0;
}
