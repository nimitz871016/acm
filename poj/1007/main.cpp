//
//  main.cpp
//  1007
//
//  Created by Nimitz_007 on 16/6/17.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct Node{
    int count;
    char *text;
}Node;

bool compare(const Node& aNode, const Node& bNode){
    return aNode.count < bNode.count;
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<Node> node;
    for (int i = 0; i < m; i++) {
        Node aNode;
        aNode.text = (char *)malloc (sizeof(char) * n);
        scanf("%s",aNode.text);
        int count = 0;
        
        for (int j = n - 2; j >= 0; j --) {
            for(int k = j + 1; k < n; k++){
                if(aNode.text[j] > aNode.text[k]){
                    count++;
                }
            }
        }
        aNode.count = count;
        node.push_back(aNode);
    }
    sort(node.begin(),node.end(),compare);
    vector<Node>::iterator it;
    for(it=node.begin();it!=node.end();it++)
        cout<<(*it).text<<endl;
    return 0;
}
