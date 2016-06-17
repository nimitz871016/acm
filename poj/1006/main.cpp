//
//  main.cpp
//  1006
//  http://poj.org/problem?id=1006
//
//  Created by Nimitz_007 on 16/6/16.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int p,e,i,d;
    int count = 1;
    while (scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF) {
        if(p == -1 && e == -1 && i == -1 & d == -1) {
            break;
        }
        //中国剩余定理
        i = i % 33;
        for(; i % 28 != e % 28; i += 33);
        for(; i % 23 != p % 23; i += 924);
        if (i == 0){//题目要求，如果是当天要追溯到下一个出现的时间。
            printf("Case %d: the next triple peak occurs in %d days.\n",count,23*28*33-d);
        }else{
            while (i-d < 0) {
                i+=23*28*33; //避免出现负的天数
            }
            printf("Case %d: the next triple peak occurs in %d days.\n",count,i-d);
        }
        count++;
    }
    
}
