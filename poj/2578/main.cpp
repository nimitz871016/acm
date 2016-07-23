//
//  main.cpp
//  2578
//  水题
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main () {
    int i,j,k;
    while(scanf("%d%d%d",&i,&j,&k)!=EOF){
        if(i <= 168){
            printf("CRASH %d\n",i);
            continue;
        }else if(j <= 168){
            printf("CRASH %d\n",j);
            continue;
        }else if(k <= 168){
            printf("CRASH %d\n",k);
            continue;
        }
        printf("NO CRASH\n");
    }
    return 0;
}
