//
//  main.cpp
//  1543
//  水题，妈的格式错了，还以为Triple中三个元素中有空格，我勒个擦。
//  另外不用pow，直接连乘更快 63ms - > 16ms
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

int pow(int n){
    return n * n * n;
}

int main(int argc, const char * argv[]) {
    int N ;
    while(scanf("%d",&N)!=EOF){
        for(int l = 2; l <= N; l ++){
            for (int i = 2; i < l - 1; i++) {
                for(int j = i ; pow(j) < pow(l) - pow(i); j++){
                    for(int k = j; pow(k) <= pow(l) - pow(i) - pow(j);k++){
                        if(pow(l) - pow(i) - pow(j) - pow(k) == 0){
                            printf("Cube = %d, Triple = (%d,%d,%d)\n",l,i,j,k);
                        }
                        
                    }
                }
            }
        }
    }
    return 0;
}
