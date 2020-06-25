//
//  1647.h
//  BaekJoon
//
//  Created by 정민수 on 2020/06/06.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _647_h
#define _647_h
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GetParent(int (&parent)[100'001],int x)
{
    if(parent[x]==x)return x;
    return parent[x]=GetParent(parent, parent[x]);
}
void UnionParent(int (&parent)[100'001],int a,int b)
{
    
    a=GetParent(parent, a);
    b=GetParent(parent, b);
    if(a<b)parent[b]=a;
    else parent[a]=b;
}

void solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int nodeCnt, edgeCnt;
    vector<pair<int,pair<int,int>>> costs;
    int parents [100'001];
    cin>>nodeCnt>>edgeCnt;
    for(int i=0;i<edgeCnt;i++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        costs.push_back({cost,{a,b}});
    }
    sort(costs.begin(),costs.end());
    int totalCost=0;
    int cnt=0;
    for(int i=1;i<=nodeCnt;i++)
    {
        parents[i]=i;
    }
    for(int i=0;i<costs.size();i++)
    {
        if(GetParent(parents,costs[i].second.first)!=GetParent(parents, costs[i].second.second))
       {
           totalCost+=costs[i].first;
           UnionParent(parents,costs[i].second.first,costs[i].second.second);
           cnt++;
           if(cnt==nodeCnt-2)break;
       }
    }
    cout<<totalCost;
}

#endif /* _647_h */
