//
//  15666.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5666_h
#define _5666_h
#include<iostream>
#include<algorithm>
#include <set>
#include<string>
using namespace  std;
int nums[8];
int path[8];
int depth;
int N,M;
set<string> num_set;
void DFS(int index)
{
    if(depth==M)
    {
        string str;
        for(int i=0;i<M;i++)
        {
            str.append(to_string(path[i])+" ");
        }
        if(num_set.find(str)==num_set.end())
        {
            num_set.insert(str);
            cout<<str<<"\n";
        }
        return;
    }
    for(int i=index;i<N;i++)
    {
        path[depth]=nums[i];
        depth++;
        DFS(i);
        depth--;
    }
}

void solution()
{
    cin>>N>>M;
    for(int  i=0;i<N;i++)
    {
        cin>>nums[i];
    }
    sort(nums,nums+N);
    DFS(0);
}


#endif /* _5666_h */
