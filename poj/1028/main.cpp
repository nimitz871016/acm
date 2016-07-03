//
//  main.cpp
//  1028
//
//  Created by Nimitz_007 on 16/7/3.
//  Copyright © 2016年 Fujian Ruijie Networks Co., Ltd. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

typedef struct stringself{
    char text[70];
}stringself;

int main(void) {
    stack<stringself> forward;
    stack<stringself> backward;
    stringself curUrl,url;
    sprintf(curUrl.text, "http://www.acm.org/");
    char word[150];
    while (scanf("%s",word)!= EOF) {
        if (!strcmp(word, "QUIT")) {
            break;
        }else{
            if(!strcmp(word,"VISIT")){
                cin >> url.text;
            }
            if (!strcmp(word,"VISIT")) {
                backward.push(curUrl);
                curUrl = url;
                while (!forward.empty()) {
                    forward.pop();
                }
                cout<<curUrl.text<<endl;
            }else if(!strcmp(word, "BACK")){
                if (backward.empty()) {
                    cout << "Ignored" << endl;
                }else{
                    forward.push(curUrl);
                    curUrl = backward.top();
                    cout<<curUrl.text<<endl;
                    backward.pop();
                }
            }else if(!strcmp(word, "FORWARD")){
                if (forward.empty()) {
                    cout<<"Ignored"<<endl;
                }else{
                    backward.push(curUrl);
                    curUrl = forward.top();
                    cout<<curUrl.text<<endl;
                    forward.pop();
                }
            }
//            printf(" cururl: %s \n",curUrl.text);
        }
    }
    return 0;
}
