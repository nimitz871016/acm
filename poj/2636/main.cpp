//
//  main.cpp
//  2636
//  水题，简单模拟题
//  Created by Nimitz_007 on 16/7/21.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int &a, int &b){
    return a > b;
}

int main(int argc, const char * argv[]) {
    int n,m;
    int  *a;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&m);
        a = (int *)malloc(sizeof(int)*m);
        for (int i = 0; i < m; i++) {
            scanf("%d",&a[i]);
        }
        sort(a, a + m, compare);
        int i = 0,mm = m - 1;
        while (mm > 0) {
            mm -= a[i];
            i++;
        }
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += a[j];
        }
        sum += -mm;
        printf("%d\n",sum);
    }
    
    return 0;
}
