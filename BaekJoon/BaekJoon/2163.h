//
//  2163.h
//  BaekJoon
//
//  Created by 정민수 on 05/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _163_h
#define _163_h
#include<iostream>
#include<queue>
using namespace std;
void solution()
{
    int n,m;
    cin>>n>>m;
    int  cnt=0;
    queue<pair<int,int>>q;
    q.push(make_pair(n,m));
    while (!q.empty()) {
        pair<int,int> index=q.front();
        q.pop();
        if(index.first==1&&index.second==1)continue;
        if(index.first>1)
        {
            q.push(make_pair(index.first-1,index.second));
            q.push(make_pair(1,index.second));

        }else{
            q.push(make_pair(index.first,index.second-1));
            q.push(make_pair(index.first,1));
        }
        cnt++;
    }
    cout<<cnt;
}

#endif /* _163_h */
