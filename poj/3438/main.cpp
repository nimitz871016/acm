//
//  main.cpp
//  3438
//  水题
//  Created by Nimitz_007 on 16/7/31.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n, count;
    char c,pre;
    scanf("%d\n",&n);
    while(n--){
        count = 1;
        scanf("%c",&pre);
        while(scanf("%c",&c) && c != '\n'){
            if(c != pre){
                printf("%d%c",count,pre);
                pre = c;
                count = 1;
                continue;
            }else{
                count++;
            }
        }
        printf("%d%c\n",count,pre);
    }
    return 0;
}
