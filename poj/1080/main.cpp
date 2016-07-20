//
//  main.cpp
//  1080
//  简单DP，值得纪念的一题。
//  Created by Nimitz_007 on 16/7/20.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>


using namespace std;

int table[5][5] = {5,-1,-2,-1,-3,-1,5,-3,-2,-4,-2,-3,5,-2,-2,-1,-2,-2,5,-1,-3,-4,-2,-1,-9999};

int cal(char a,char b){
    int i,j;
    switch (a) {
        case 'A':
            i = 0;
            break;
        case 'C':
            i = 1;
            break;
        case 'G':
            i = 2;
            break;
        case 'T':
            i = 3;
            break;
        default:
            i = 4;
            break;
    }
    switch (b) {
        case 'A':
            j = 0;
            break;
        case 'C':
            j = 1;
            break;
        case 'G':
            j = 2;
            break;
        case 'T':
            j = 3;
            break;
        default:
            j = 4;
            break;
    }
    return table[i][j];
}

int max(int a,int b,int c){
    if (a >= b && a >= c) {
        return a;
    }else if(b >= a && b >= c){
        return b;
    }else{
        return c;
    }
}

int main() {
    int n,numa,numb;
    char *a,*b;
    int **f;
    
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&numa);
        a = (char *)malloc(sizeof(char)*numa);
        scanf("%s",a);
        scanf("%d",&numb);
        b = (char *)malloc(sizeof(char)*numb);
        scanf("%s",b);
//        *f = (int *)malloc(sizeof(int)*numa);
        f = new int*[numa + 1];
        for (int i = 0; i <= numa; i++) {
//            f = (int **)malloc(sizeof(int)*numb);
            f[i] = new int[numb + 1];
        }
        
        for (int i = 0; i <= numa; i++) {
            for (int j = 0; j <= numb; j++) {
                f[i][j] = 0;
            }
        }
        f[0][0] = 0;
        for (int i = 0; i <= numa; i++) {
            for (int j = 0; j <= numb; j++) {
                if (i == 0 && j==0) {
                    continue;
                }
                int temp1 = -9999,temp2 = -9999,temp3 = -9999;
                if (i >= 1) {
                    temp3 = f[i - 1][j] + cal(a[i - 1],'-');
                }
                if (j >= 1) {
                    temp2 = f[i][j - 1] + cal('-',b[j - 1]);
                }
                if(i >= 1 && j >= 1){
                    temp1 = f[i - 1][j - 1] + cal(a[i - 1],b[j - 1]);
                }
                f[i][j] = max(temp1,temp2,temp3);
            }
        }
//        for (int i = 0; i <= numa; i++) {
//            for (int j = 0; j <= numb; j++) {
//                printf("%d ",f[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",f[numa][numb]);
    }
    
    return 0;
}
