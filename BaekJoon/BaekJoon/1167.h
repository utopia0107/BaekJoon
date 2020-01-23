//
//  1167.h
//  BaekJoon
//
//  Created by 정민수 on 23/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _167_h
#define _167_h
#include<iostream>
#include<vector>
using namespace std;
vector<vector<pair<int,int>>> nodeEdges;
int weightVisited[100001]={-1,};
void GetMaxWeight(int node)
{
    for(int i=0;i<nodeEdges[node].size();i++)
    {
        int nextNode=nodeEdges[node][i].first;
        if(weightVisited[nextNode]==-1)
        {
            weightVisited[nextNode]=weightVisited[node]+nodeEdges[node][i].second;
            GetMaxWeight(nextNode);
        }
    }

}
void soultion()
{
    int n;
    cin>>n;
    nodeEdges.resize(n+1);
    for(int i=0;i<n;i++)
    {
        int node,linkNode,weight;
        cin>>node;
        while(true)
        {
            cin>>linkNode;
            if(linkNode==-1)break;
            cin>>weight;
            nodeEdges[node].push_back(make_pair(linkNode,weight));
        }
    }
    pair<int,int> index;
    int maxWeight=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<nodeEdges[i].size();j++)
        {
            if(maxWeight<nodeEdges[i][j].second)
            {
                index.first=i;
                index.second=j;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        weightVisited[i]=-1;
    }
    weightVisited[1]=0;
    GetMaxWeight(1);
    int farNode=0;
    for(int i=1;i<=n;i++)
    {
        if(weightVisited[farNode]<weightVisited[i])
        {
            farNode=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        weightVisited[i]=-1;
    }
    weightVisited[farNode]=0;
    GetMaxWeight(farNode);
    int answer=0;
    for(int i=1;i<=n;i++)
    {
        answer=max(answer,weightVisited[i]);
    }
    cout<<answer;
}
#endif /* _167_h */
