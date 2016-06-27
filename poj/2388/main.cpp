//
//  main.cpp
//  2388
//  简单排序
//  Created by Nimitz_007 on 16/6/27.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main() {
    int N;
    long *a;
    scanf("%d",&N);
    a = (long *) malloc(sizeof(long) * N);
    for (int i = 0; i < N; i++) {
        scanf("%ld",&a[i]);
    }
    sort(a, a+N, cmp);
    printf("%ld\n",a[N / 2]);
    return 0;
}
