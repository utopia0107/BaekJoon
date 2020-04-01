//
//  1707.h
//  BaekJoon
//
//  Created by 정민수 on 30/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _707_h
#define _707_h
#include<iostream>
#include<vector>
using namespace std;
vector<int> edges[20001];
int nodesDepth[20001];
bool visited[20001];
bool isBinaryGrahp=true;
void DFS(int curNode,int depth)
{
    nodesDepth[curNode]=depth;
    for(int i=0;i<edges[curNode].size();i++)
    {
        int nextNode=edges[curNode][i];
        if(!visited[nextNode])
        {
            visited[nextNode]=true;
            DFS(nextNode,depth+1);
        }
    }
}
void solution()
{
    int k;
    cin>>k;
    while(k--)
    {
        int V,E;
        cin>>V>>E;
        for(int i=0;i<E;i++)
        {
            int node1,node2;
            cin>>node1>>node2;
            edges[node1].push_back(node2);
            edges[node2].push_back(node1);
        }
        for(int i=1;i<=V;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                DFS(i,0);
            }
        }
        for(int i=1;i<=V;i++)
        {
            for(int j=0;j< edges[i].size();j++)
            {
                if(nodesDepth[i]%2==nodesDepth[edges[i][j]]%2)
                {
                    isBinaryGrahp=false;
                    break;
                }
            }
            if(!isBinaryGrahp)break;
        }
        if(isBinaryGrahp)cout<<"YES\n";
        else cout<<"NO\n";
        //reset
        for(int i=1;i<=V;i++)
        {
            nodesDepth[i]=0;
            visited[i]=false;
            edges[i].clear();
        }
        isBinaryGrahp=true;
    }
}
#endif /* _707_h */
