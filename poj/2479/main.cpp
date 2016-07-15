//
//  main.cpp
//  2479
//
//  Created by Nimitz_007 on 16/7/3.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

void maxSubArray(int *a,int *sumarray,int num){
    sumarray[0] = a[0];
    int sum = a[0];
    for (int i = 1; i < num; i++) {
        if (sum > 0) {//TODO: 讨论区有讨论全负的情况，这段代码没问题，那么他们有问题的原因是？
            sum += a[i];
        }else{
            sum = a[i];
        }
        sumarray[i] = sum > sumarray[i - 1] ? sum : sumarray[i - 1];
    }
}
int main() {
    int n,num;
    int *positive;
    int *negative;
    int *p_s;
    int *n_s;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&num);
        positive = (int *) malloc(sizeof(int) * num);
        negative = (int *) malloc(sizeof(int) * num);
        p_s = (int *) malloc(sizeof(int) * num);
        n_s = (int *) malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            scanf("%d",&positive[i]);
            negative[num - i - 1] = positive [i];
        }
        //对正向负向数组分别做连续最大子数组
        maxSubArray(positive,p_s,num);
        maxSubArray(negative,n_s,num);
        int max = -10001;
        for (int i = 0; i < num - 1; i++) {
//            printf("%d %d\n",p_s[i],n_s[num - i - 2]);
            if (p_s[i] + n_s[num - i - 2] > max) {
                max = p_s[i] + n_s[num - i - 2];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
