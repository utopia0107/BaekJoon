//
//  2110.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _110_h
#define _110_h
#include<iostream>
#include<vector>
using namespace std;

bool  CheckRouterInstallation(vector<int> homes,int minDistance, int cnt)
{
    int curRouterInex=0;
    cnt--;
    for(int i=1;i<homes.size();i++)
    {
        if(homes[i]-homes[curRouterInex]>=minDistance)
        {
            cnt--;
            curRouterInex=i;
        }
    }
    return  cnt<=0;
}

void solution()
{
    int N,C;
    cin>>N>>C;
    vector<int> homes;
    homes.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>homes[i];
    }
    sort(homes.begin(),homes.end());
    int  start =0,end=1'000'000'000;
    int answer=0;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(!CheckRouterInstallation(homes,mid,C))
        {
            end=mid;
        }else
        {
            answer=mid;
            start=mid+1;
        }
        
    }
    cout<<answer;
}

#endif /* _110_h */
