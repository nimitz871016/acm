//
//  main.cpp
//  2509
//  水题，中了个坑翻discuss才过。
//  没加上余数，这样如果不整除的话，实际上把上一次没能兑换的雪茄给无视了。
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF) {
        int count = a;
        do{
            int tempn = a / b;
            count += tempn;
            a = tempn + a % b;
        }while(a >= b);
        printf("%d\n",count);
    }
    return 0;
}