//
//  main.cpp
//  2262
//  考察素数的求法。这里用了两种方法。
//  1. 逐个判断某个数是否是素数。用的逻辑是
//     a)2的倍数，不是
//     b)只判断是否是奇数的倍数，判断区间到sqrt(待求数)
//  2. 反向，将合数标记出来，则没有标记的是素数。（代码中的方法）。这种方法速度较快！
//  TODO:应该还有更好的方法。目前内存使用太多了
//  Created by Nimitz_007 on 16/6/27.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include <string.h>

int main(){
    bool a[1000000] = {0};
    int n,i,j;
    for(i=2;i < sqrt(1000000.0);i++)
    {
        if(!a[i])
        {
            for(j=i*i;j<1000000;j+=i)
            {
                a[j]=1;
            }
        }
    }
    while(scanf("%d",&n) && n){
        for (i = 3; i <= n / 2; i+= 2) {
            if(a[i] == 0 && a[ n-i ] == 0){
                //got it
                printf("%d = %d + %d\n",n,i,n - i);
                break;
            }
        }
    }
    return 0;
}


//int main() {
//
//    int n;
//    int count = 0;
//    bool flag = true;
//    scanf("%d",&n);
//    for (int i = 2; i < n; i++) {
//        flag = true;
//        if (i % 2 == 0) {
//            continue;
//        }else{
//            for (int k = 3; k <= sqrt(i); k += 2) {
//                if (i % k == 0) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag == true) {
////                printf("%d,",i);
//                count ++;
//                if (count % 10 == 0) {
////                    printf("\\ \n");
//                }
//            }
//        }
//    }
//    printf("count = %d\n",count);
//    return 0;
//}


