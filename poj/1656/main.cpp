//
//  main.cpp
//  1656
//
//  Created by Nimitz_007 on 16/7/31.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    int x,y,l;
    bool grid[101][101] = {0};
    char a[6];
    scanf("%d",&n);
    while(n--){
        scanf("%s%d%d%d",a,&x,&y,&l);
        if(!strcmp(a,"WHITE")){
            for(int i = x; i <= x + l - 1; i++){
                for (int j = y; j <= y + l - 1; j++){
                    grid[i][j] = false;
                }
            }
        }else if(!strcmp(a,"BLACK")){
            for(int i = x; i <= x + l - 1; i++){
                for (int j = y; j <= y + l - 1; j++){
                    grid[i][j] = true;
                }
            }
        }else if(!strcmp(a,"TEST")){
            int count = 0;
            for(int i = x; i <= x + l - 1; i++){
                for (int j = y; j <= y + l - 1; j++){
                    if (grid[i][j] == true){
                        count++;
                    }
                }
            }
            printf("%d\n",count);
        }
    }
    
    return 0;
}
