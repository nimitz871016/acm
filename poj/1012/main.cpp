//
//  main.cpp
//  1012
//
//  i=1 ,k=2
//i=2 ,k=7
//i=3 ,k=5
//i=4 ,k=30
//i=5 ,k=169
//i=6 ,k=441
//i=7 ,k=1872
//i=8 ,k=7632
//i=9 ,k=1740
//i=10 ,k=93313
//i=11 ,k=459901
//  Created by Nimitz_007 on 16/6/22.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <vector>

//using namespace std;
//int main() {
//    int *data;
//    int l,i,ii,nn = 0;
//    bool flag = false;
//    long k;
//    for (i = 1; i < 14; i++) {
//        ii = i * 2;
//        k = i;
//        nn = 0;
//        flag = false;
//        data = (int *)malloc(sizeof(int) * ii);
//        while (true) {
//            for (int n = i + 1; n <= 2 * i; n++) {
//                k = 2 * i * nn + n;
//                int start = 0;
//                int count = 0;
//                for (int l = 0; l < ii; l++) {
//                    data[l]=0;
//                }
//                while(count != ii){
//                    for (l = 0; l < k; ) {
//                        if (data[(start + l) % ii] == 0) {
//                            l++;
//                        }else{
//                            start++;
//                        }
//                    }
//                    int index = (start + l - 1) % ii;
//                    if (index < i && count < i ) {
//                        break;//不符合
//                    }
//                    data[index] = -1;
//                    start = index + 1;
//                    //                printf("%d\n",start);
//                    count++;
//                }
//                if (count == ii) {
//                    printf("i=%d ,k=%ld\n",i,k);
//                    flag = true;
//                    break;
//                }else{
//                    if(k % 10000 == 0){
//                        printf("%ld\n",k);
//                    }
//                    k++;
//                }
//            }
//            if (flag) {
//                break;
//            }
//            nn++;
//        }
//    }
//}

//int main(){
//    int i,nn = 0,k = 1;
//    bool flag = true;
//    for (i = 1; i < 15; i++ ) {
//        nn = 0;
//        while (true) {
//            for (int n = i + 1; n <= 2 * i; n++) {
//                k = 2 * i * nn + n;
//                flag = true;
//                int left = 1;
//                for (int l = 0; l < i; l++) {
//                    left = (k + left - 1) % (i * 2 - l);
//                    if (left <= i && left !=0) {
//                        //非法
//                        flag = false;
//                        break;
//                    }
//                    if (left == 0) {
//                        left = i * 2 - l;
//                    }
//                }
//                if (flag) {
//                    //成了
//                    break;
//                }
//            }
//            if (flag) {
//                break;
//            }
//            nn++;
//        }
//        printf("i=%d,k=%d\n",i,k);
//        nn = 0;
//    }
//    return 0;
//}

int main(){
    int n;
    long result[14] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
    while (scanf("%d",&n) && n != 0) {
        printf("%ld\n",result[n - 1]);
    }
}