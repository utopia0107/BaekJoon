//
//  10819.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/30.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _0819_h
#define _0819_h
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> path;
int n,answer=0,depth=0;
bool visiteds[8];
void DFS()
{
    if(depth==n)
    {
        int total=0;
        for(int i=0;i<n-1;i++)
        {
            total+=abs(path[i]-path[i+1]);
        }
        answer=max(answer,total);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(!visiteds[i])
        {
            visiteds[i]=true;
            depth++;
            path.push_back(v[i]);
            DFS();
            path.pop_back();
            depth--;
            visiteds[i]=false;
        }
    }
}
void solution()
{
  
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    DFS();
    cout<<answer;
}

#endif /* _0819_h */
