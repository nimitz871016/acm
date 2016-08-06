//
//  main.cpp
//  1019
//  思考题，要想想思路。我有一个缺点，总是不想清楚，就下手。完全靠OJ来判定。这样不好。虽然这道题1A，但是还是有要反思的地方。
//  Created by Nimitz_007 on 16/8/6.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <math.h>

#define MAX_NUM 10000

long positionOfNum(long num,long pos,int digits){
    int i;
    for(i = 0; i < pos - 1; i++){
//        printf("%f",pow(10.0,digits - i - 1));
        num -= num/(long)pow(10.0,digits - i - 1) * pow(10.0,digits - i - 1);
    }
    printf("%ld\n",num/(long)pow(10.0,digits - i - 1));
    return num/(long)pow(10.0,digits - i - 1);
}

int digitOfNum(long num){
    int count = 1;
    while(num >= pow(10.0,count)){
        count++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int n;
    long num;
    scanf("%d",&n);
    while(n--){
        scanf("%ld",&num);
        long pres = 0,curs;
        long pred = 0,curd = 0;
        int i = 1;
        while(true){
            //        s[i] = s[i - 1] + digitOfNum(i);
            //        d[i] = d[i - 1] + s[i];
            curs = pres + digitOfNum(i);
            if(num - curd <= curs){
                break;
            }else{
                curd = pred + curs;
                pres = curs;
                pred = curd;
                i++;
            }
        }
        long temp = num - curd;
        for(long l = 1; l <= i; l++){
            temp -= digitOfNum(l);
            if(temp <= 0){
                positionOfNum(l,temp + digitOfNum(l),digitOfNum(l));
                break;
            }
        }
    }
    return 0;
}
