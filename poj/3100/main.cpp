//
//  main.cpp
//  3100
//
//  Created by Nimitz_007 on 16/7/25.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int b,n;
    while(scanf("%d%d",&b,&n)!=EOF){
        if(b == 0 && n == 0){
            break;
        }else{
            double ans = pow(b * 1.0,1.0 / n);
            if( abs(pow(floor(ans),n) - b) > abs(b - pow(ceil(ans),n))){
                ans = ceil(ans);
            }else{
                ans = floor(ans);
            }
            printf("%d\n", int(ans));
        }
    }
    
    return 0;
}
