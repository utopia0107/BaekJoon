//
//  1463.h
//  BaekJoon
//
//  Created by 정민수 on 03/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _463_h
#define _463_h
#include<iostream>
#include<queue>
using namespace std;
void solution()
{

    int n,depth=0,queueSize=1;
    cin>>n;
    queue<int>  q;
    q.push(n);
    
    while(!q.empty())
    {
        int num=q.front();
        if(num==1)break;
        queueSize--;
        q.pop();
        if(num%3==0)q.push(num/3);
        if(num%2==0)q.push(num/2);
        q.push(num-1);
        if(queueSize==0)
        {
            depth++;
            queueSize=q.size();
        }
    }
    
    cout<<depth;
}


#endif /* _463_h */
