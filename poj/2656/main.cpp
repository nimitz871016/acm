//
//  main.cpp
//  2656
//
//  Created by Nimitz_007 on 16/7/20.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,b,c;
    int *a;
    while (scanf("%d",&n) && n != 0) {
        a = (int *) malloc(sizeof(int)*n);
        for (int i = 0;i < n; i++) {
            scanf("%d%d",&b,&c);
            a[i] = b + c;
        }
        int temp = a[0];
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > temp) {
                temp = a[i];
                index = i;
            }
        }
        if (temp > 8) {
            printf("%d\n",index + 1);
        }else{
            printf("0\n");
        }
    }
    
    return 0;
}
