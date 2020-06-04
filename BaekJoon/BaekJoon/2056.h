//
//  2056.h
//  BaekJoon
//
//  Created by 정민수 on 2020/06/03.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _056_h
#define _056_h
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void Update(int time,priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>* jobs)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq=*jobs;
    while(!(jobs->empty()))
    {jobs->pop();
    }
    while (!pq.empty()) {
        pair<int,int> cur=pq.top();
        cur.first-=time;
        jobs->push(cur);
        pq.pop();
    }
    
}
void solution()
{
    int n,size,index;
    cin>>n;
    vector<pair<int,vector<int>>> v;
    int counter[10001]={0,};
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        cin>>size;
        v[i].second.resize(size);
        for(int j=0;j<size;j++)
        {
            cin>>index;
            v[index-1].second.push_back(i);
            counter[i+1]++;
        }
    }
    int time=0;
    //남은 시간, 인덱스
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> jobs;
    for(int i=1;i<=n;i++)
    {
        if(counter[i]==0)jobs.push(make_pair(v[i-1].first,i-1));
    }
    while(!jobs.empty())
    {
        pair<int,int> cur=jobs.top();
        jobs.pop();
        Update(cur.first,&jobs);
        time+=cur.first;
        for(int i=0;i<v[cur.second].second.size();i++)
        {
            if(--counter[v[cur.second].second[i]+1]==0)
            {
                jobs.push(make_pair(v[v[cur.second].second[i]].first,v[cur.second].second[i]));
            }
        }
    }
    cout<<time;
}

#endif /* _056_h */
