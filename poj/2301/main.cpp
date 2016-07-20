//
//  main.cpp
//  2301
//  水题，注意结果只能是整数，要注意出现小数的情况是impossiable的
//  Created by Nimitz_007 on 16/7/20.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,a,b;
    scanf("%d",&n);
    while (n--) {
        scanf("%d%d",&a,&b);
        if ((a >= b)) {
            if (a %2 == b %2){
                printf("%d %d\n",(a + b)/2,(a - b) /2);
            }else{
                printf("impossible\n");
            }
        }else{
            printf("impossible\n");
        }
    }
    return 0;
}
