//
//  1931.h
//  BaekJoon
//
//  Created by 정민수 on 26/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _931_h
#define _931_h
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solution()
{
    int conferenceCnt;
    cin>>conferenceCnt;
    vector<pair<int,int>> conferences;
    conferences.resize(conferenceCnt);
    for(int i=0;i<conferenceCnt;i++)
    {
        cin>>conferences[i].second>>conferences[i].first;
    }
    sort(conferences.begin(),conferences.end());
    int curTime=0;
    int possibleCnt=0;
    for(int i=0;i<conferenceCnt;i++)
    {
        if(conferences[i].second>=curTime)
        {
            curTime=conferences[i].first;
            possibleCnt++;
        }
    }
    cout<<possibleCnt;
}

#endif /* _931_h */
