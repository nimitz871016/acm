//
//  main.cpp
//  1657
//  水题还是写的太马虎了。
//  1.没注意象起点终点相同时的处理。
//  2.输出格式没注意，inf->Inf
//  Created by Nimitz_007 on 16/7/21.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n;
    char aa[3],bb[3];
    char a,b,c,d;
    scanf("%d",&n);
    while (n--) {
        scanf("%s%s",aa,bb);
        c = aa[0];
        d = bb[0];
        a = aa[1];
        b = bb[1];
        int wang = abs(d - c) < abs(b - a) ? abs(b - a) : abs(d - c) ;//尽量走斜，走到同行或同列
        int xiang = 0;//如果可以到达，则最多需要两步
        int queen = 0;//和王的规则一样，但是斜着走一步到达。
        int che = (d == c ? 0 : 1) + (b == a ? 0 : 1);//任何地点，两步到达
        bool flag = false;
        if ((c + a == d + b) || abs(c - a) == abs(d - b)) {
            if (c == d && a == b) {
                xiang = 0;
            }else{
                xiang = 1;
            }
        }else{
            if ((c - a) % 2 != (d - b) % 2) {
                flag = true;
            }
            xiang = 2;
        }
        queen = che < xiang ? che : xiang;
        printf("%d %d %d ",wang,queen,che);
        if (flag) {
            printf("Inf\n");
        }else{
            printf("%d\n",xiang);
        }
    }
    return 0;
}
