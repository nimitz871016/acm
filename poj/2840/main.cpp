//
//  main.cpp
//  2840
//  水题
//  Created by Nimitz_007 on 16/7/25.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    int a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d:%d",&a,&b);
        if(b != 0){
            printf("0\n");
            continue;
        }else{
            if(a>= 0 && a <= 12){
                printf("%d\n",a + 12);
            }else{
                printf("%d\n",a - 12);
            }
        }
    }
    return 0;
}
