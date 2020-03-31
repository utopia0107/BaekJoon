//
//  15649.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5649_h
#define _5649_h
#include<iostream>
using namespace std;
int N,cnt,depth=0;
int path[8];
bool visited[8];
void DFS()
{
    if(depth==cnt)
    {
        for(int i=0;i<cnt;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            path[depth]=i+1;
            visited[i]=true;
            depth++;
            DFS();
            depth--;
            visited[i]=false;
        }
    }
}
void solution()
{
    cin>>N>>cnt;
    DFS();
}

#endif /* _5649_h */
