//
//  main.cpp
//  1844
//  水题，这题一念之差，对于偶数的情况的处理是对的，但是奇数的处理是错的，死不悔改，在原代码上改到AC。最后放出改进的方法。
//  Created by Nimitz_007 on 16/7/27.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>

//int main() {
//    long n,mm;
//    float m;
//    
//    while(scanf("%ld",&n)!=EOF){
//        m = (sqrt(1 + 8.0 * n) - 1) / 2;
//        mm = (long)ceilf(m);
//        if(m == mm || (mm * (mm + 1) / 2 - n) % 2 == 0){
//            printf("%ld\n",mm);
//        }else{
//            if(mm % 2 == 0){
//                printf("%ld\n",mm + 1);
//            }else{
//                printf("%ld\n",mm + 2);
//            }
//        }
//    }
//    return 0;
//}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i = 0;;i++){
            if(i * i + i < 2 * n) {
                continue;
            }else if((i * i + i - 2 * n) % 4 == 0){
                printf("%d\n",i);
                break;
            }else{
                printf("%d\n",i % 2 == 0 ? i + 1: i + 2);
                break;
            }
        }
        
    }
    return 0;
}
