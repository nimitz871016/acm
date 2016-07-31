//
//  main.cpp
//  2909
//  水题，汗死，被2^15c次方吓住，还以为是10^15，汗死。
//  打个表，这道题水的很，和2262无差别
//  Created by Nimitz_007 on 16/7/31.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

bool a[32769] = {0};
int main() {
    int i,j;
    long n;
    for(i=2;i < sqrt(32769.0);i++)
    {
        if(!a[i])
        {
            for(j=i*i;j<32769;j+=i)
            {
                a[j]=1;
            }
        }
    }
    while(scanf("%ld",&n) && n != 0){
        int count = 0;
        for(int i = 2; i <= n / 2; i++){
            if(a[i] == false && a[n - i] == false){
                count ++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
