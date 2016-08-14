//
//  main.cpp
//  1163
//  很简单的一道DP，开始一直没算清下标。还是得拿笔算啊。
//  Created by Nimitz_007 on 16/8/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    int *a,*s;
    while(scanf("%d",&n)!=EOF){
        int total = (1 + n) * n / 2;
        a = (int *)malloc(sizeof(int) * total);
        s = (int *)malloc(sizeof(int) * total);
        for(int i = 0; i < total; i++){
            scanf("%d",&a[i]);
        }
        s[0] = a[0];
        int result = s[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0){
                    s[i * (i + 1) / 2 + j] = s[i * (i - 1) / 2 + j] + a[i * (i + 1) / 2 + j];
                }else if(j == i){
                    s[i * (i + 1) / 2 + j] = s[i * (i - 1) / 2 + i - 1] + a[i * (i + 1) / 2 + j];
                }else{
                    s[i * (i + 1) / 2 + j] = max(s[(i - 1) * i / 2 + j],s[(i - 1) * i / 2 + j - 1]) + a[i * (i + 1) / 2 + j];
                }
                if(i == n - 1){
                    if(result < s[i * (i + 1) / 2 + j]){
                        result = s[i * (i + 1) / 2 + j];
                    }
                }
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
