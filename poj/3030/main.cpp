//
//  main.cpp
//  3030
//
//  Created by Nimitz_007 on 16/7/19.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main() {
    int n,r,e,c;
    scanf("%d",&n);
    while (n--) {
        scanf("%d%d%d",&r,&e,&c);
        if (r + c < e) {
            printf("advertise\n");
        }else if(r + c == e){
            printf("does not matter\n");
        }else{
            printf("do not advertise\n");
        }
    }
    return 0;
}
