//
//  main.cpp
//  3980
//  水题，考验基本功，这题写的还可以。
//  Created by Nimitz_007 on 16/7/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
int mod(int a,int b){
    if (a < b) {
        return a;
    }else{
        return mod(a - a / b * b, b);
    }
}

int main(int argc, const char * argv[]) {
    int a,b;
    while (scanf("%d %d",&a,&b)!=EOF) {
        printf("%d\n",mod(a,b));
    }
    return 0;
}
