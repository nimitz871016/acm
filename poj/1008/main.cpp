//
//  main.cpp
//  1008
//  本应该是很简单的题，却WA数次，最后看了讨论才知道问题在哪。
//  关键测试数据4. uayet 259
//  正解是 13 ahau 364
//  而不是13 ahau 365
//  Created by Nimitz_007 on 16/6/17.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
int main() {
    int n,i;
    int d,year;
    char *month;
    char *result_month;
    char h_month[19][7] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    char z_month[20][9] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    scanf("%d",&n);
    printf("%d\n",n);
    while (n--) {
        result_month = (char *)malloc(sizeof(char)*9);
        month = (char *)malloc(sizeof(char)*7);
        scanf("%d. %s %d",&d,month,&year);
        for (i = 0; i < 19; i++) {
            if (!strcmp(h_month[i], month)) {
                break;
            }
        }
        int total = year * 365 + i * 20 + d + 1;
        year = total % 260 == 0 ? total / 260 - 1:(total) / 260;
        int day = total % 260 % 13 == 0 ? 13 : total % 260 % 13;
        result_month = z_month[int(total % 260) % 20 - 1 == -1? 19: int(total % 260) % 20 - 1];
        printf("%d %s %d\n",day,result_month,year);
    }
    return 0;
}
