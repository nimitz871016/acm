//
//  main.cpp
//  1159
//  动态规划。
//  这道题很曲折。最开始，只知道是一道动态规划题。于是尝试写方程。后来发现应该是应用原串与逆序串之间的某个关系来得出。
//  于是，想到了最长公共子串。但是是错的。实际上应该是最长公共子序列。最后这两个的动规代码都实现了。
//  另外由于本题的数据量，还用到了滚动数组。Get！
//  Created by Nimitz_007 on 16/8/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
char str[5001],temp[5001];

typedef struct LCSInfo{
    int starta; //start index of a;
    int startb; //start index of b;
    int length; //LCS length
    char *a;   //original a;
    char *b;   //original b;
}LCSInfo;


void reverse(){
    size_t len = strlen(str);
    memset(temp,'\0',5001);
    for(int i = len - 1,j = 0; i >= 0; i--,j++){
        temp[j] = str[i];
    }
}

int LCS(char*a, char *b){
    size_t lena = strlen(a);
    size_t lenb = strlen(b);
    LCSInfo info;
    info.a = a;
    info.b = b;
    short **s,result = 0;
    s = new short*[2];
    for(int i = 0; i < 2; i++){
        s[i] = new short[lenb + 1];
    }
//    memset(s,0,sizeof(int) * (lena + 1) * (lenb + 1));
    for(int i = 0; i < 2; i++){
        for(int j = 0;j <= lenb; j++){
            s[i][j] = 0;
        }
    }
    for(int i = 1; i <= lena; i++){
        for(int j = 1; j <= lenb; j++){
            if(a[i - 1] == b[j - 1]){
                s[i % 2][j] = s[(i - 1) %2][j - 1] + 1;
            }else{
                s[i % 2][j] = max(s[(i - 1) % 2][j],s[i % 2][j - 1]);
            }
        }
    }
    result = s[lena % 2][lenb];
    delete(s);
    return result;
}

int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF){
//        s = (int *)malloc(sizeof(int) * n);
        scanf("%s",str);
        reverse();
        printf("%d\n",strlen(str) - LCS(str,temp));
    }
    return 0;
}
