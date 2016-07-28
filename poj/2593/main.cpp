//
//  main.cpp
//  2593
//  两段最大子段和.这道题，第一次AC的结果是错的。是数据不够严谨。题意是要求两段的最大连续子段和，而第一次AC的程序实际上是最大子段和。
//  代表数据:
//    6
//    3 3 -3 4 -2 1
//    10 √, 11×
//  修改后，再次AC，但是时间变长了。现在不知道那些神人是怎么做到60ms+的AC了。
//  Created by Nimitz_007 on 16/7/27.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

long max(long a,int b){
    return a > b ? a : b;
}

void reverse(int *a,int length){
    int i;
    for (i = 0; i < length / 2; i++) {
        a[length - i - 1] = a[length - i - 1] ^ a[i];
        a[i] = a[length - i - 1] ^ a[i];
        a[length - i - 1] = a[length - i - 1] ^ a[i];
    }
}

/**
 *  最大子段和
 *
 *  @param a     数组a
 *  @param start 起始位置
 *  @param end   终止位置
 *
 *  @return <#return value description#>
 */

long *maxSubString(int *a, int start,int end){
    long *s = (long *)malloc(sizeof(long)* (end - start + 1));
    long *s1 = (long *)malloc(sizeof(long) * (end - start + 1));
    memset(s,0,sizeof(long) * (end - start + 1));
    memset(s1,0,sizeof(long) * (end - start + 1));
    s[0] = a[0];
    s1[0] = a[0];
    long result = a[0];
    for(int i = start + 1; i <= end; i++){
        if(s[i - 1] > 0){
            s[i] = max(s[i - 1] + a[i], a[i]);
        }else{
            s[i] = max(s[i - 1],a[i]);
        }
        if(s[i] > result){
            s1[i] = s[i];
            result = s1[i];
        }else{
            s1[i] = result;
        }
    }
    free(s);
    return s1;
}

int main() {
    int *a, n;
    long sum;
    long *s1,*s2;
    while(scanf("%d",&n) && n != 0){
        a = (int *)malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        s1 = maxSubString(a,0,n - 1);
        reverse(a,n);
        s2 = maxSubString(a, 0, n - 1);
        sum = s1[0] + s2[n - 2];
        for (int i = 0; i < n - 1; i++){
            long temp1 = s1[i] + s2[n - i - 2];
            if(sum < temp1){
                sum = temp1;
            }
        }
        printf("%ld\n",sum);
//        free(a);
        free(s1);
        free(s2);
    }
    
    return 0;
}
