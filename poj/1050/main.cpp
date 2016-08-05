//
//  main.cpp
//  1050
//  一开始想错了，以为可以DP，后面发现其实就是暴力搜索。不过这题没有做到最佳解法。
//  Created by Nimitz_007 on 16/8/2.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int f[101][101],a[101][101];
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF){
        int tempSum;
        for(int i = 1; i <= n; i++){
            tempSum = 0;
            for(int j = 1; j <= n; j++){
                scanf("%d",&a[i][j]);
                tempSum += a[i][j];
                f[i][j] = f[i - 1][j] + tempSum;
            }
        }
        int result = f[0][0];
        int temp;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = i; k <= n; k++){
                    for(int l = j; l <= n; l++){
                        temp = f[k][l] - f[k][j - 1] - f[i - 1][l] + f[i - 1][j - 1];
                        if(result < temp){
                            result = temp ;
                        }
                    }
                }
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
