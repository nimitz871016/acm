//
//  main.cpp
//  1579
//  水题，看题意是要递归转非递归，实际上就弄了数组保存中间状态就好了。
//  最后被条件判断顺序小坑了一下
//  Created by Nimitz_007 on 16/7/21.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int w[21][21][21];
int cal(int a,int b, int c){
    if (a<=0 || b<=0 || c<=0){
        return 1;
    }else if (w[a][b][c] != 0) {
        return w[a][b][c];
    }else if(a < b && b < c){
        return cal(a,b,c-1) + cal(a,b-1,c-1) - cal(a,b-1,c);
    }else{
        return cal (a-1,b,c) + cal(a - 1, b - 1, c) + cal(a - 1,b, c - 1) - cal(a - 1,b - 1, c - 1);
    }
}
int main() {
    int a,b,c,ans;
    memset(w, 0, sizeof(w));
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                w[i][j][k] = cal(i,j,k);
            }
        }
    }
    while (scanf("%d%d%d",&a,&b,&c)!=EOF) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }else{
            if ( a<=0 || b<=0 || c<=0) {
                ans = 1;
            }else if(a > 20 || b > 20 || c > 20) {
                ans = cal(20, 20, 20);
            }else{
                ans = cal(a,b, c);
            }
        }
        printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
    }
    return 0;
}
