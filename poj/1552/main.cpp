//
//  main.cpp
//  1552
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& aNode, const int& bNode){
    return aNode < bNode;
}

int main() {
    vector<int> single;
    int num;
    while (scanf("%d",&num) && num != -1) {
        if (num != 0) {
            single.push_back(num);
            single.push_back(num * 2);
        }else{
            
            vector<int>::iterator it;
            sort(single.begin(),single.end(),compare);
            int pre = *single.begin();
            int result = 0;
            for(it=single.begin()+1;it!=single.end();it++){
                if (*it == pre) {
                    result ++;
                }
                pre = *it;
            }
            single.clear();
            printf("%d\n",result);
        }
    }
    return 0;
}
