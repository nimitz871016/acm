//
//  main.cpp
//  3624
//  动态规划 赤裸的01背包问题。 这道题由@POJ 1014引出。
//  第一次学写01背包，开始各种问题，说明自己裸写代码的能力还很弱。写完了之后MLE，因为用了2维数组，浪费了空间。
//  改进后，使用一个1维数组。过了。
//  Created by Nimitz_007 on 16/8/23.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>
//#include "other.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    int n,m,w,d;
    int *f;
    while(scanf("%d%d",&n,&m)!=EOF){
        f = new int[m + 1];
        memset(f,0,sizeof(int) * (m + 1));
        for(int i = 0; i < n; i++){
            scanf("%d%d",&w,&d);
            for(int j = m; j >= w; j--){
                f[j] = max(f[j], f[j - w] + d);
            }
        }
        printf("%d\n",f[m]);
        free(f);
    }
    return 0;
}

//long mine(int n, int m, int *w, int *d) {
////    int n,m;
////    int *w,*d;
//    int *f;
////    while(scanf("%d%d",&n,&m)!=EOF){
////        w = (int *)malloc(sizeof(int)*n);
////        d = (int *)malloc(sizeof(int)*n);
//        f = new int[m + 1];
//    memset(f,0,sizeof(int) *(m + 1));
////        }
//        for(int i = 1; i <= n; i++){
//            for(int j = m; j >= w[i - 1]; j--){
//                f[j] = max(f[j], f[j - w[i - 1]] + d[i - 1]);
//            }
//        }
//    long result = f[m];
//    free(f);
//    return result;
//}
//
//int main(){
//    int count = 1;
//    int n,m,*d,*w;
//    long a;
//    int b;
//    while(true){
//        n = rand() % 3402 + 1;
//        m = rand() % 12880 + 1;
//        d = (int *)malloc(sizeof(int)*n);
//        w = (int *)malloc(sizeof(int)*n);
//        for(int i = 0; i < n; i++){
//            d[i] = rand() % 100 + 1;
//            w[i] = rand() % 400 + 1;
//        }
//        a = mine(n,m,w,d);
//        b = other(n,m,w,d);
//        if( a != b){
//            for(int i = 0; i < n; i++){
//                printf("%d %d\n",w[i],d[i]);
//            }
//            printf("mine = %ld, other = %d\n",a,b);
//            break;
//        }else{
//            printf("success count = %d\n",count++);
//        }
//        free(d);
//        free(w);
//    }
//    return 0;
//}

