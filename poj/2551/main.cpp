//
//  main.cpp
//  2551
//  水题，找到规律就很简单啦。分解 11111 = 10*1111 + 1，递进搜索，避免高精度运算
//  Created by Nimitz_007 on 16/7/31.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

int digitOfNum(long num){
    int count = 1;
    while(num >= pow(10.0,count)){
        count++;
    }
    return count;
}

int mod10e(long num,int n){
    return true;
}

int main(int argc, const char * argv[]) {
    int n;
    int count = 0;
    int pre;
    while(scanf("%d",&n)!=EOF){
        count = digitOfNum(n);
        pre = 0;
        for(int i = 0; i < count; i++){
            pre += pow(10.0,i);
        }
        while(true){
            pre = ((10 % n)*pre)%n + 1;
            if( pre % n == 0){
                break;
            }else{
                count ++;
                continue;
            }
        }
        printf("%d\n",count + 1);
    }
    
    return 0;
}
