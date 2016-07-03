//
//  main.cpp
//  1046
//
//  Created by Nimitz_007 on 16/7/2.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int r;
    int g;
    int b;
}Node;

int distance(const Node a,const Node b){
    return (a.r - b.r)*(a.r - b.r) + (a.g - b.g)*(a.g - b.g) + (a.b - b.b)*(a.b - b.b);
}
int main() {
    Node *nodes;
    Node target;
    Node tempNode;
    int i;
    int dist = 99999;
    nodes = (Node *)malloc(sizeof(Node)*16);
    for (i = 0; i < 16; i++ ) {
        scanf("%d %d %d",&target.r,&target.g,&target.b);
        nodes[i] = target;
    }
    while (scanf("%d %d %d", &target.r,&target.g,&target.b)!=EOF) {
        if(target.r == -1 && target.g == -1 && target.b == -1){
            break;
        }
        dist = 99999;
        for (i = 0; i < 16; i++) {
            int tempDist = distance(target, nodes[i]);
            if (dist > tempDist) {
                dist = tempDist;
                tempNode = nodes[i];
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",target.r,target.g,target.b,tempNode.r,tempNode.g,tempNode.b);
    }
    return 0;
}
