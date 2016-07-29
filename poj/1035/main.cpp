//
//  main.cpp
//  1035
//  水题，本来最多2A的，第一次是因为没有匹配到应该直接冒号+直接回车。
//  结果没看清楚题目，字典最多10000个，看成50个了。
//  Created by Nimitz_007 on 16/7/29.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>

char a[10001][20];
using namespace std;
int replace(char *a, char *b){
    size_t la = strlen(a);
    size_t lb = strlen(b);
    if(la != lb){
        return 0;//不能替换
    }else{
        bool flag = false;
        bool flag1 = true;
        for(int i = 0; i < la; i++){
            if(a[i] != b[i] && !flag){
                flag = true;
            }else if(a[i] != b[i] && flag){
                flag1 = false;
                break;
            }
        }
        if(!flag){
            return 2;
        }else if(flag1){
            return 1;
        }
    }
    return 0;
}

int insert(char *a, char *b){
    size_t la = strlen(a);
    size_t lb = strlen(b);
    if(la - lb != 1 && la - lb != -1){
        return 0;
    }else if(la > lb){
        return insert(b,a);
    }else{
        bool flag = false;
        bool flag1 = true;
        for(int i = 0,j = 0; i < la; i++,j++){
            if(a[i] == b[j]){
                continue;
            }else {
                if(a[i] != b[j] && !flag){
                    i--;
                    flag = true;
                }else{
                    flag1 = false;
                    break;
                }
            }
        }
        if(!flag1){
            return false;
        }else{
            return true;
        }
    }
}

int main(int argc, const char * argv[]) {
    char b[17];
    int count = 0;
    vector<char *> rep;
    while(scanf("%s",a[count]) && strcmp(a[count],"#")){
        count++;
    }
    while(scanf("%s",b) && strcmp(b,"#")){
        bool flag = false;
        for(int i = 0;i < count; i++){
            int result = replace(b,a[i]);
            if(result == 2){
                printf("%s is correct\n",b);
                flag = true;
                break;
            }else if(result == 1){
                rep.push_back(a[i]);
            }
            int result1 = insert(b,a[i]);
            if(result1 == 1){
                rep.push_back(a[i]);
            }
        }
        if(!flag){
            if(rep.size() > 0){
                printf("%s: ",b);
                for(int i = 0; i < rep.size() - 1;i++){
                    printf("%s ",rep[i]);
                }
                printf("%s\n",rep[rep.size() - 1]);
            }else{
                printf("%s:\n",b);
            }
        }
        memset(b,0,17);
        rep.clear();
    }
    return 0;
}
