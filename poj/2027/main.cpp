//
//  main.cpp
//  2027
//  超级水题
//  Created by Nimitz_007 on 16/6/27.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,x,y;
    scanf("%d",&n);
    while (n--) {
        scanf("%d %d",&x,&y);
        if (x >= y) {
            printf("MMM BRAINS\n");
        }else{
            printf("NO BRAINS\n");
        }
    }
    return 0;
}
