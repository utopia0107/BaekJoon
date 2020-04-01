//
//  1260.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/01.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _260_h
#define _260_h
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> edges[1001];
bool visited[1001];
int N,M;
void DFS(int curNode)
{

    visited[curNode]=true;
    cout<<curNode<<" ";
    for(int i=0;i<edges[curNode].size();i++)
    {
        int nextNode=edges[curNode][i];
        if(!visited[nextNode])
        {
             DFS(nextNode);
        }
    }
}
void BFS(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode]=true;
    while (!q.empty())
    {
        int curNode=q.front();
        q.pop();
        cout<<curNode<<" ";
        for(int i=0;i<edges[curNode].size();i++)
        {
            int nextNode=edges[curNode][i];
            if(!visited[nextNode])
            {
                visited[nextNode]=true;
                q.push(nextNode);
            }
        }
    }
}
void solution()
{
    int startNode;
    cin>>N>>M>>startNode;
    for(int i=0;i<M;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    for(int i=1;i<=N;i++)
    {
        sort(edges[i].begin(),edges[i].end());
    }
    visited[startNode]=true;
    DFS(startNode);
    cout<<"\n";
    for(int i=1;i<=N;i++)
    {
        visited[i]=false;
    }
    BFS(startNode);
}

#endif /* _260_h */
