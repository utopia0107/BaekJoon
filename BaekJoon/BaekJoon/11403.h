//
//  11403.h
//  BaekJoon
//
//  Created by 정민수 on 24/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1403_h
#define _1403_h
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool visited[100];
vector<vector<int>> map;
vector<vector<int>> edges;
int startNode;
void DFS(int curNode)
{
    for(int i=0;i<edges[curNode].size();i++)
    {
         if(!visited[edges[curNode][i]])
         {
             map[startNode][edges[curNode][i]]=1;
             visited[edges[curNode][i]]=true;
             DFS(edges[curNode][i]);
         }
    }
}

void soultion()
{
   
    int size;
    cin>>size;
    edges.resize(size);
    map.resize(size);
    
    for(int i=0;i<size;i++)
    {
        map[i].resize(size);
        for(int j=0;j<size;j++)
        {
            int linkState;
            cin>>linkState;
            if(linkState==1)edges[i].push_back(j);
            map[i][j]=0;
        }
    }
    for(int i=0;i<size;i++)
    {
        memset(visited,false,sizeof(visited));
        startNode=i;
        DFS(i);
    }
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }    
}

#endif /* _1403_h */
