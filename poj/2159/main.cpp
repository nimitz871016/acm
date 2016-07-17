//
//  main.cpp
//  2159
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int &a,const int &b){
    return a > b;
}

int main() {
    char str[101],str1[101];
    int a[26],b[26];
    memset(str, 0, 101);
    memset(str1, 0, 101);
    while(scanf("%s%s",str,str1)!=EOF){
        memset(a, 0, sizeof(int)*26);
        memset(b, 0, sizeof(int)*26);
        for (int i = 0; i < strlen(str); i++) {
            a[str[i] - 'A']++;
        }
        for (int i = 0; i < strlen(str1); i++) {
            b[str1[i] - 'A']++;
        }
        sort(a, a + 26, compare);
        sort(b, b + 26, compare);
        bool flag = false;
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}
