//
//  main.cpp
//  2141
//  水题，+个大小写的转换
//  Created by Nimitz_007 on 16/7/28.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    char a[27],c;
    while(scanf("%s\n",a)!=EOF){
        while(scanf("%c",&c) && c != '\n'){
            if(c != ' '){
                if(c >= 'A' && c <= 'Z'){
                    printf("%c", a[c - 'A'] - 32);
                }else{
                    printf("%c", a[c - 'a']);
                }
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
