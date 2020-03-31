//
//  15652.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5652_h
#define _5652_h
#include<iostream>
using namespace std;
int N,M;
int depth=0;
int path[8];
void DFS(int index)
{
    if(depth==M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=index;i<=N;i++)
    {
        path[depth]=i;
        depth++;
        DFS(i);
        depth--;
    }
}

void solution()
{
    cin>>N>>M;
    DFS(1);
}
#endif /* _5652_h */
