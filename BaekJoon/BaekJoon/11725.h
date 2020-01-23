//
//  11725.h
//  BaekJoon
//
//  Created by 정민수 on 23/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1725_h
#define _1725_h
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>nodeEdges;
vector<int> nodesParent;
bool visited[100001];
void DFS(int curNode)
{
    for(int i=0;i<nodeEdges[curNode].size();i++)
    {
        if(!visited[nodeEdges[curNode][i]])
        {
            visited[nodeEdges[curNode][i]]=true;
            nodesParent[nodeEdges[curNode][i]]=curNode;
            DFS(nodeEdges[curNode][i]);
        }
    }
}
void soultion()
{
    int nodeCnt;
    cin>>nodeCnt;
    nodeEdges.resize(nodeCnt+1);
    nodesParent.resize(nodeCnt+1);
    int nodeA,nodeB;
    for(int i=0;i<nodeCnt-1;i++)
    {
        cin>>nodeA>>nodeB;
        nodeEdges[nodeA].push_back(nodeB);
        nodeEdges[nodeB].push_back(nodeA);
    }
    DFS(1);
    for(int i=2;i<=nodeCnt;i++)
    {
        cout<<nodesParent[i]<<"\n";
    }
}

#endif /* _1725_h */
