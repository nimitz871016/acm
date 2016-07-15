//
//  main.cpp
//  1658
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,a,b,c,d,e;
    scanf("%d",&n);
    while (n--) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if (b - a == c - b && d - c == c - b) {
            e = d + d - c;
        }else{
            e = d * d / c;
        }
        printf("%d %d %d %d %d\n",a,b,c,d,e);
    }
    return 0;
}
