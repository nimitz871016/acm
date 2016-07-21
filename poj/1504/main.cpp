//
//  main.cpp
//  1504
//  水题，1503加了点变化，本质任然是大数加法，直接拿1503的代码改改就过了。
//  Created by Nimitz_007 on 16/7/21.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

#define MAX_NUM 100

void reverse(char* src){
    size_t length = strlen(src);
    int i;
    for (i = 0; i < length / 2; i++) {
        //        src[length - i - 1] = src[length - i - 1] + src[i];
        //        src[i] = src[length - i - 1] - src[i];
        //        src[length - i - 1] = src[length - i - 1] - src[i];
        src[length - i - 1] = src[length - i - 1] ^ src[i];
        src[i] = src[length - i - 1] ^ src[i];
        src[length - i - 1] = src[length - i - 1] ^ src[i];
    }
}

char *Add(char *a, char * b){
    size_t n = strlen(a);
    size_t m = strlen(b);
    if (n > m) {
        return Add(b,a);
    }
    reverse(a);
    reverse(b);
    char *sum = (char *)malloc(sizeof(char)*MAX_NUM);
    memset(sum, '\0', MAX_NUM);
    for (int i = 0; i < m; i++) {
        if (i < n) {
            sum[i] = a[i] + b[i] - '0';
        }else{
            sum[i] = b[i];
        }
    }
    for (size_t i = 0; i < m; i++) {
        if (sum[i] > '9') {
            if (i != m - 1) {
                sum[i]-= 10;
                sum[i + 1]++;
            }else{
                sum[i]-= 10;
                //                result = (char *)realloc(result, sizeof(char));
                sum[i + 1] = '1';
            }
        }
    }
    reverse(sum);
    return sum;
}

int main(int argc, const char * argv[]) {
    int n;
    char a[MAX_NUM],b[MAX_NUM],*sum;
    sum = (char *)malloc(sizeof(char)*MAX_NUM);
    memset(sum, '\0', MAX_NUM);
    scanf("%d",&n);
    while (n--) {
        scanf("%s%s",a,b);
        reverse(a);
        reverse(b);
        sum = Add(a,b);
        reverse(sum);
        int i = 0;
        while (sum[i++] == '0');
        for (--i; i < strlen(sum); i++) {
            printf("%c",sum[i]);
        }
        printf("\n");
    }
    

    return 0;
}
