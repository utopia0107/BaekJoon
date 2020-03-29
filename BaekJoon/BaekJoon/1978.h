//
//  1978.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _978_h
#define _978_h
#include<iostream>
using namespace std;

bool visited[1000];
bool checks[1000];
void  solution()
{
    for(int i=2;i<=1000;i++)
    {
        if(!visited[i])
        {
            checks[i]=true;
            for(int j=i;j<=1000;j+=i)
            {
                visited[j]=true;
            }
        }
    }
    int t,num,answer=0;
    cin>>t;
    while(t--)
    {
        cin>>num;
        if(checks[num])answer++;
    }
    cout<<answer;
}

#endif /* _978_h */
