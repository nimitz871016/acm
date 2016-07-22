//
//  main.cpp
//  1922
//  水题
//  1. 遍历数组取最小的值，被测试数据暗算了。因为这次的数组中有“非法”的数据，所以初始化的时候不能直接拿第一位的数据做为起始比较数据。
//     随便取了个9999和99999结果就被暗算了。注意!
//  2. 这道题一开始想错了，想去模拟每一次换车的过程。而实际上我们只需要关心最快完成4.5公里的合法（出发时间大等于0）的车手就行了。
//  Created by Nimitz_007 on 16/7/21.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct Node{
    double v;
    double time;
    double totalTime;
}Node;

bool compare(const Node& a, const Node& b){
    return a.totalTime < b.totalTime;
}

int main(){
    int n;
    Node *node;
    
    while (scanf("%d",&n) && n) {
        node = (Node *)malloc(sizeof(Node)*n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf",&node[i].v,&node[i].time);
        }
        for (int i = 0; i < n; i++) {
            node[i].totalTime = 4.5 / node[i].v *3600 + node[i].time;
        }
        sort(node,node + n,compare);
        int i = 0;
        while (node[i].time < 0) {
            i++;
        }
        double elapseTime = node[i].totalTime;
        for (; i < n; i++) {
            if (node[i].time > 0 && node[i].totalTime < elapseTime) {
                elapseTime = node[i].totalTime;
            }
        }
        printf("%d\n",(int)ceil(elapseTime));
        free(node);
    }
    return 0;
}