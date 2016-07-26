//
//  main.cpp
//  2389
//
//  Created by Nimitz_007 on 16/7/25.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

void bigMultiple(char *a,char *b,int *n){
    size_t la = strlen(a);
    size_t lb = strlen(b);
    int *result = (int *)malloc(sizeof(int)*(la + lb + 1));
    memset(result,0,sizeof(int)*(la + lb + 1));
    for (int j = 0; j < lb; j++){
        for(int k = 0; k < la; k++){
            result[j + k] += (a[la - k - 1] - '0') * (b[lb - j - 1] - '0');
        }
    }
    for(int i = 0; i < la + lb + 1; i++){
        result[i + 1] += result[i] / 10;
        result[i] = result[i] % 10;
    }
    int i = (int)(la + lb);
    while(result[i] == 0 && i >0){
        i--;
    }
    *n = i + 1;
    for(;i >= 0; i--){
        printf("%d",result[i]);
    }
    printf("\n");
    free(result);
}
int main() {
    char a[41],b[41];
    int n;
    while(scanf("%s%s",a,b)!=EOF){
        bigMultiple(a,b,&n);
    }
    return 0;
}
