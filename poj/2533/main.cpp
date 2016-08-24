//
//  main.cpp
//  2533
//  尝试排序后，转化为最长公共子序列失败，因为数据中有可能元素相同。
//  现在的解法是遍历前面的s[j],找到最大的，然后+1。感觉不是dp解法了。
//  TODO: 1.还有其他解法可以尝试。（线段树）
//        2.感觉非DP了。
//        3.本题代码直接提交3903，答案应该是对的，但是会超时。需要优化
//  觉得自己现在越来越懒，越依赖于对拍。关键，对拍还是和标程对拍。这样其实损害自己的能力.
//  Created by Nimitz_007 on 16/8/24.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int *a,*s;
    while(scanf("%d",&n)!=EOF){
        a = (int *)malloc(sizeof(int)*n);
        s = (int *)malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            s[i] = 1;
        }
        int result = 1;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >=0 ; j--){
                if(a[i] > a[j]){
                    int temp = s[j] + 1;
                    if(temp > s[i]){
                        s[i] = temp;
                    }
                }
            }
            if(result < s[i]){
                result = s[i];
            }
        }
//        for(int i = 0; i < n; i++){
//            printf("%d ",s[i]);
//        }
//        printf("\n");
        printf("%d\n",result);
        free(a);
        free(s);
    }
    return 0;
}


int mine(int n, int *a) {
    int *s;
        a = (int *)malloc(sizeof(int)*n);
        s = (int *)malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++){
            s[i] = 1;
        }
        int result = 1;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >=0 ; j--){
                if(a[i] > a[j]){
                    s[i] = s[j] + 1;
                    break;
                }
            }
            if(result < s[i]){
                result = s[i];
            }
        }
                for(int i = 0; i < n; i++){
                    printf("%d ",s[i]);
                }
                printf("\n");
        printf("%d\n",result);
//        free(a);
        free(s);
    return result;
}

//int main(){
//    int n;
//    int *a;
//    int count = 1;
//    while(1){
//        n = rand() % 10 + 1;
//        a = (int *)malloc(sizeof(int) * n);
//        for(int i = 0; i < n; i++){
//            a[i] = rand() % 100;
//        }
//        int aa = mine(n,a);
//        int bb = other(n,a);
//        if(aa != bb){
//            printf("mine = %d, other =  %d\n",aa,bb);
//            printf("%d\n",n);
//            for(int i = 0; i < n; i++){
//                printf("%d ",a[i]);
//            }
//            printf("\n");
//            break;
//        }else{
//            printf("success count = %d \n",count++);
//        }
//    }
//}
