//
//  16953.h
//  BaekJoon
//
//  Created by 정민수 on 2020/06/15.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _6953_h
#define _6953_h
#include<iostream>
#include<queue>
using namespace std;
void solution()
{
    long long a,b;
    cin>>a>>b;
    queue<long long> q;
    q.push(a);
    int level=1;
    int qSize=1;
    while(!q.empty())
    {
        long long num=q.front();
        q.pop();
        qSize--;
        if(num==b)
        {
            cout<<level;
            return ;
        }
        if(num*2<=b)
        {
            q.push(num*2);
        }
        if(num*10+1<=b)
        {
            q.push(num*10+1);
        }
        if(qSize==0)
        {
            qSize=q.size();
            level++;
        }
        
    }
    cout<<"-1";
}

#endif /* _6953_h */
