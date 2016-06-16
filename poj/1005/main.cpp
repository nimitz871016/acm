//
//  main.cpp
//  1005
//
//  Created by Nimitz_007 on 16/6/16.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#define PI 3.1415926
int main() {
    int count;
    float x,y;
    scanf("%d",&count);
    for(int i = 0; i < count; i++){
        int year = 0;
        float square = 0;
        scanf("%f %f",&x,&y);
        while(1){
            //根据计算圆的半径
            float radius = square / PI;
            if (x*x + y*y < radius) {
                break;
            }else{
                year++;
                square+=100;
            }
        }
        printf("Property %d: This property will begin eroding in year %d.\n",i + 1,year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
