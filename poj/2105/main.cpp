//
//  main.cpp
//  2105
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,b[8] = {128,64,32,16,8,4,2,1};
    char addr[33];
    memset(addr, 0, 32);
    scanf("%d",&n);
    while (n--) {
        scanf("%s",addr);
        for (int i = 0; i < 4; i++) {
            int num = 0;
            for(int j = 0; j < 8; j++){
                num += (addr[i * 8 + j] - '0') * b[j];
            }
            printf("%d",num);
            if(i != 3) printf(".");
        }
        printf("\n");
    }
    return 0;
}
