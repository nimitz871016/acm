//
//  main.cpp
//  1068
//
//  Created by Nimitz_007 on 16/7/14.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n,size,num;
    int *a;
    scanf("%d",&n);
    stack<char> s;
    while (n--) {
        scanf("%d",&size);
        a = (int *)malloc(sizeof(int) * size);
        memset(a,0,sizeof(int) * size);
        int temp = 0;
        for (int i = 0; i < size; i++) {
            scanf("%d",&num);
            for (int j = 0; j < num - temp; j++) {
                s.push('(');
            }
            s.push(')');
            temp = num;
        }
        temp = size;
        while (!s.empty()) {
            if (s.top() == ')') {
                temp --;
            }else if(s.top() == '('){
                bool flag = false;
                bool flag1 = false;
                for (int i = temp; i < size; i++) {
                    while(a[i] < 0 && !flag){
                        i++;
                    }
                    flag = true;
                    if(a[i]>=0) a[i] ++;
                    if (!flag1) {
                        a[i] *= -1;
                        flag1 = true;
                    }
                }
            }
            s.pop();
        }
        for(int i = 0; i < size; i++){
            printf("%d ",-a[i]);
        }
        printf("\n");
        free(a);
    }
    return 0;
}
