//
//  11723.h
//  BaekJoon
//
//  Created by 정민수 on 31/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1723_h
#define _1723_h
#include<iostream>
#include<string>
using namespace std;
void solution()
{
    //입출력 속도를 높이기 위함, 안하면 시간 초과 됩니다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int commandCnt;
    bool checks[21];
    cin>>commandCnt;
    string command;
    int num;
    while (commandCnt--) {
        cin>>command;
        if(command.compare("add")==0)
        {
            cin>>num;
            checks[num]=true;
        }
        else if(command.compare("remove")==0)
        {
            cin>>num;
            checks[num]=false;
        }
        else if(command.compare("check")==0)
        {
            cin>>num;
            if(checks[num])cout<<"1\n";
            else cout<<"0\n";
        }
        else if(command.compare("all")==0)
        {
            for(int i=1;i<=20;i++)
            {
                checks[i]=true;
            }
        }
        else if(command.compare("toggle")==0)
        {
            cin>>num;
            if(checks[num])checks[num]=false;
            else checks[num]=true;
        }
        else if(command.compare("empty")==0)
        {
            for(int i=1;i<=20;i++)
            {
                checks[i]=false;
            }
        }
    }
}

#endif /* _1723_h */
