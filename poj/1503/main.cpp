//
//  main.cpp
//  1503
//
//  Created by Nimitz_007 on 16/7/3.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string>

#define MAX_NUM 105

using namespace std;

/*
 * 翻转src
 */
void reverse(char* src,bool clearZero){
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
//void Add(const char * aNum, const char * bNum,char *result1){
//    size_t aLength = strlen(aNum);
//    size_t bLength = strlen(bNum);
//    char *result = (char *)malloc(sizeof(char)*MAX_NUM);
//    if (aLength > bLength) {
//        return Add(bNum, aNum,result);//a比b位数少
//    }
////    char *result = (char *) malloc (sizeof(MAX_NUM));
//    //这里假设aNum和bNum都是正常的10进制，即每位存储的数字不能超过9
//    for (size_t i = 0; i < bLength; i++) {
//        if (i < aLength) {
//            result[i] = aNum[i] + bNum[i] - '0';
//        }else{
//            result [i] = bNum[i];
//        }
//    }
//    result[bLength] = '\0';
//    for (size_t i = 0; i < bLength; i++) {
//        if (result[i] > 57) {
//            if (i != bLength - 1) {
//                result[i]-= 10;
//                result[i + 1]++;
//            }else{
//                result[i]-= 10;
////                result = (char *)realloc(result, sizeof(char));
//                result[i + 1] = 49;
//            }
//        }
//    }
//
//    memcpy(result1, result, strlen(result));
//    reverse(result1,false);
////    printf("%s + %s = %s\n",aNum,bNum,result);
////    return result;
//}


//
//int main() {
//    char *a,*b,*e;
//    a = (char *) malloc(sizeof(char)* MAX_NUM);
//    b = (char *) malloc(sizeof(char)* MAX_NUM);
//    e = (char *) malloc(sizeof(char)* MAX_NUM);
//    scanf("%s",a);
//    memcpy(e, a, strlen(a));
////    printf("%s",reverse(a));
//    if(!strcmp(a, "0")){
////        printf("%s",a);
//        return 0;
//    }else{
//        while(scanf("%s",b) && strcmp(b, "0")){
////            printf("%s + %s = ",a,b);
////            a = bigNumber_add(a,b);
//            reverse(a,true);
//            reverse(b,true);
//            Add(a, b, a);
//            memset(b, '\0', sizeof(char)*MAX_NUM);
//        }
//        int start = 0;
//        while (a[start] <= '0') {
//            start++;
//        }
//        if (start == strlen(a)) {
//            printf("0");
//        }
//        for (int i = start; i < strlen(a); i++)
//        {
//            printf("%d",a[i] - '0');
//        }
//        printf("\n");
//    }
//    return 0;
//}

char *Add(char *a, char * b){
    size_t n = strlen(a);
    size_t m = strlen(b);
    if (n > m) {
        return Add(b,a);
    }
    reverse(a,true);
    reverse(b,true);
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
    reverse(sum,true);
    return sum;
}

int main(){
    char a[MAX_NUM],*sum;
    sum = (char *)malloc(sizeof(char)*MAX_NUM);
    memset(sum, '\0', MAX_NUM);
    scanf("%s",a);
    if (!strcmp(a, "0")) {
        printf("\n");
        return 0;
    }
    for (int i = 0; i < strlen(a); i++) {
        sum[i] = a[i];
    }
//    while (scanf("%s",a)) {
    while(cin>>a){
        if (!strcmp(a, "0")) {
            break;
        }else{
            sum = Add(sum,a);
        }
        memset(a, '\0', MAX_NUM);
    }
    int i = 0;
    while (sum[i++] == '0');
    for (--i; i < strlen(sum); i++) {
        printf("%c",sum[i]);
    }
    printf("\n");
}

