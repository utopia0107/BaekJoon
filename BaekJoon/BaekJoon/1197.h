//
//  1197.h
//  BaekJoon
//
//  Created by 정민수 on 2020/05/28.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _197_h
#define _197_h
#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;

void  solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V,E;
    cin>>V>>E;
    //cost,next
    vector<pair<int,int>> map[10'001];
    bool visited[10'001]={false,};
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        map[a].push_back(make_pair(c, b));
        map[b].push_back(make_pair(c, a));
    }
    //cost,next
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;
    long long total=0;
    int linkCnt=0;
    int curNode=1;
    visited[curNode]=true;
    for(int i=0;i<map[curNode].size();i++)
    {
        //cost,next
        pq.push(make_pair(map[curNode][i].first,map[curNode][i].second));
    }
    while(linkCnt+1!=V)
    {
        //cost,next
        pair<int,int> cur=pq.top();
        curNode=cur.second;
        pq.pop();
        if(!visited[curNode])
        {
            visited[curNode]=true;
            linkCnt++;
            total+=cur.first;
            for(int i=0;i<map[curNode].size();i++)
            {
                pq.push(make_pair(map[curNode][i].first,map[curNode][i].second));
            }
        }
    }
    cout<<total;
}

#endif /* _197_h */
