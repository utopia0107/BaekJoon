//
//  15650.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5650_h
#define _5650_h
#include<iostream>
using namespace std;
int N,cnt;
int depth=0;
bool visited[8];
int path[8];
void DFS(int index)
{
    if(depth==cnt)
    {
        for(int i=0;i<cnt;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=index+1;i<N;i++)
    {
        if(!visited[i])
        {
            path[depth]=i+1;
            visited[i]=true;
            depth++;
            DFS(i);
            depth--;
            visited[i]=false;
        }
    }
}

void solution()
{
    cin>>N>>cnt;
    DFS(-1);
}

#endif /* _5650_h */
