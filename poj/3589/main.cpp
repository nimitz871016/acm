//
//  main.cpp
//  3589
//  水题，记录一个问题，当要接收4个字符的时候，数组长度最好多开一个。因为只开刚好的话，第一个如本例中a，就会有问题，a[0]会变成'\0'!
//  Created by Nimitz_007 on 16/7/31.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n,c,d;
    char a[5],b[5];
    scanf("%d\n",&n);
    while(n--){
        memset(a,0,5);
        memset(b,0,5);
        scanf("%s %s",a,b);
        c = d = 0;
        for(int i = 0; i < 4; i++){
            if(a[i] == b[i]){
                c++;
            }
        }
        for (int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(a[i] == b[j]){
                    d++;
                }
            }
        }
        printf("%dA%dB\n",c,d - c);
    }
    return 0;
}
