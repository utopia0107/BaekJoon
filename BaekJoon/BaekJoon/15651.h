//
//  15651.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5651_h
#define _5651_h
#include<iostream>
using namespace std;
int N,M;
int depth=0;
int path[7];
void DFS()
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
    for(int i=1;i<=N;i++)
    {
        path[depth]=i;
        depth++;
        DFS();
        depth--;
    }
}

void solution()
{
    cin>>N>>M;
    DFS();
}

#endif /* _5651_h */
