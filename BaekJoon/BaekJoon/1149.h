//
//  1149.h
//  BaekJoon
//
//  Created by 정민수 on 26/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _149_h
#define _149_h
#include<iostream>
#include<vector>
using namespace std;
int dp[3][1000];
void solution()
{
    int houseCnt;
    cin>>houseCnt;
    vector<vector<int>> rgbs;
    rgbs.resize(houseCnt);
    for(int i=0;i<houseCnt;i++)
    {
        rgbs[i].resize(3);
        for(int j=0;j<3;j++)
        {
            cin>>rgbs[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        dp[i][0]=rgbs[0][i];
    }
    for(int i=1;i<houseCnt;i++)
    {
        dp[0][i]=min(dp[1][i-1],dp[2][i-1])+rgbs[i][0];
        dp[1][i]=min(dp[0][i-1],dp[2][i-1])+rgbs[i][1];
        dp[2][i]=min(dp[0][i-1],dp[1][i-1])+rgbs[i][2];
    }
    int answer=1000000;
    for(int i=0;i<3;i++)
    {
        answer=min(answer,dp[i][houseCnt-1]);
    }
    cout<<answer;
}
#endif /* _149_h */
