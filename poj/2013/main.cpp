//
//  main.cpp
//  2013
//  水题
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int i = 1,n;
    char **str;
    while (scanf("%d",&n) && n!=0) {
        str = new char*[n];
        for (int i = 0; i < n; i++) {
            str[i] = (char *)malloc(sizeof(char) * 26);
        }
        printf("SET %d\n",i++);
        for (int i = 0; i < n; i++) {
            scanf("%s",str[i]);
        }
        for (int i = 0; i < n ; i+= 2) {
            printf("%s\n",str[i]);
        }
        for (int i = n % 2 == 0 ? n - 1: n - 2; i >= 1; i-= 2) {
            printf("%s\n",str[i]);
        }
    }
    return 0;
}
