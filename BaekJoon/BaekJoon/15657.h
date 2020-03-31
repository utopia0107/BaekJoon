//
//  15657.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5657_h
#define _5657_h
#include<iostream>
#include<algorithm>
using namespace  std;
int nums[8];
int path[8];
bool visited[8];
int depth;
int N,M;
void  DFS(int index)
{
    if(depth==M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=index;i<N;i++)
    {
        path[depth]=nums[i];
        visited[i]=true;
        depth++;
        DFS(i);
        depth--;
        visited[i]=false;
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


#endif /* _5657_h */
