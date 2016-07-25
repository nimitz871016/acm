//
//  main.cpp
//  2046
//
//  Created by Nimitz_007 on 16/6/28.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;


typedef struct Node{
    int x;
    int y;
}Node;
int a[4][8];
queue<Node> q;

void initArray(){
    //初始化
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 11 || a[i][j] == 21 || a[i][j] == 31|| a[i][j] == 41) {
                a[i][j] = 0;
                Node node;
                node.x = i;
                node.y = j;
                q.push(node);
            }
        }
    }
    a[0][0] = 11;
    a[1][0] = 21;
    a[2][0] = 31;
    a[3][0] = 41;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return;
}
Node find(int n){
    Node node;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if(a[i][j] == n){
                node.x = i;
                node.y = j;
                return node;
            }
        }
    }
    printf("cannot find:%d\n",n);
    return node;
}
void bfs(){
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if(a[node.x][node.y - 1] == 17 || a[node.x][node.y - 1] == 27 ||a[node.x][node.y - 1] == 37 ||a[node.x][node.y - 1] == 47 ){
            continue;
        }
        if(a[node.x][node.y - 1] == 0 ){
            q.push(node);//不符合再次进队
            continue;
        }
        printf("try to find:%d\n",a[node.x][node.y - 1] + 1);
        Node nextNode = find(a[node.x][node.y - 1] + 1);
        q.push(nextNode);
        a[node.x][node.y] = a[nextNode.x][nextNode.y];
        a[nextNode.x][nextNode.y] = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    while (n--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {
                scanf("%d",&a[i][j + 1]);
            }
        }
        initArray();
        bfs();
    }
    return 0;
}
