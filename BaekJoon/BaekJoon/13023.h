//
//  13023.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/01.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _3023_h
#define _3023_h
#include<iostream>
#include<vector>
using namespace std;
bool visited[2000];
vector<int> edges[2000];
int answer=0;
void DFS(int curNode,int depth)
{
    if(depth==4)
    {
        answer=1;
        return;
    }
    for(int i=0;i<edges[curNode].size();i++)
    {
        int nextNode=edges[curNode][i];
        if(!visited[nextNode])
        {
            visited[nextNode]=true;
            DFS(nextNode,depth+1);
            visited[nextNode]=false;
        }
    }
}
void solution()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    for(int i=0;i<N;i++)
    {
        if(answer==1)break;
        visited[i]=true;
        DFS(i,0);
        visited[i]=false;
    }
    cout<<answer;
}

#endif /* _3023_h */
