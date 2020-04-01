//
//  11724.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/01.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1724_h
#define _1724_h
#include<iostream>
#include<vector>
using namespace  std;
vector<int> edges[1001];
bool visited[1001];
void DFS(int curNode)
{
    for(int i=0;i<edges[curNode].size();i++)
    {
        int nextNode=edges[curNode][i];
        if(!visited[nextNode])
        {
            visited[nextNode]=true;
            DFS(nextNode);
        }
    }
}
void solution()
{
    int N,M;
    int connectCnt=0;

    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            connectCnt++;
            DFS(i);
        }
    }
    cout<<connectCnt++;
}

#endif /* _1724_h */
