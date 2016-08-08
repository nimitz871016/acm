//
//  main.cpp
//  1083
//  贪心，这道题暴露了而我对贪心法的不了解。我只是粗略的分析，认为贪心法可行。确实本题的正确解法是贪心法。但是在执行贪心之前需要先对数据进行个排序。这点我没有考虑到。本题使用贪心法正确性证明如下：
//  本题我的思路是：
//  1.对数据进行排序，这样从左边开始向右搜索。凡是相容的区域就纳入本次移动。
//  2.重复执行，直至所有移动完成。
//  不进行排序的问题在于：
//  对于有冲突的多个移动，可能在一次搜索中，一个都没有选中，造成最后要单独解决这些有冲突的移动（浪费额外的次数）
//  而从左开始，顺序搜索的好处是，对于有冲突的多个移动，每一次至少会选择其中的一个，纳入这一次的移动。
//  Created by Nimitz_007 on 16/8/6.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>

typedef struct Node{
    int start;
    int end;
    bool selected;
}Node;

bool compare(Node &a, Node &b){
    return a.start < b.start;
}

using namespace std;
int main(int argc, const char * argv[]) {
    int n,m,c,d;
    Node *a;
    bool b[201] = {false};
    scanf("%d",&n);
    while(n--){
        //memset(b,0,sizeof(bool)*200);
        scanf("%d",&m);
        a = new Node[m];
        for(int i = 0; i < m; i++){
            scanf("%d %d",&c, &d);
            c = (c + 1) /2;
            d = (d + 1) /2;
            if(d < c){
                a[i].start = d;
                a[i].end = c;
            }else{
                a[i].start = c;
                a[i].end = d;
            }
            a[i].selected = false;
        }
        int count = 0;
        int mm = m;
        sort(a,a + m,compare);
        while(mm != 0){
            memset(b,0,sizeof(bool)*201);
            int temp = 0;
            for(int i = 0; i < m; i++){
                if(!a[i].selected && (200 - temp) >= a[i].end - a[i].start + 1){
                    bool flag = true;
                    for(int j = a[i].start; j <= a[i].end; j++){
                        if(b[j]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        a[i].selected = true;
                        mm--;
                        temp += a[i].end - a[i].start + 1;
                        for(int j = a[i].start; j <= a[i].end; j++){
                            b[j] = true;
                        }
                    }
                }
            }
            count ++;
        }
        printf("%d\n",count * 10);
        delete(a);
    }
    return 0;
}
