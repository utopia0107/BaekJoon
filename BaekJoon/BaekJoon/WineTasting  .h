//
//  WineTasting  .h
//  BaekJoon
//
//  Created by 정민수 on 19/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef WineTasting___h
#define WineTasting___h
#include<iostream>
#include<vector>
using namespace std;
//행=>안마심,처음,연속
//열=> n번째 포도잔
int dp[3][10000];
void soultion()
{
    int n;
    vector<int> v;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    dp[1][0]=v[0];
    for(int i=1;i<n;i++)
    {
        //안 마심
        dp[0][i]=max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]));
        //처음 마심
        dp[1][i]=dp[0][i-1]+v[i];
        //연속 마심
        dp[2][i]=dp[1][i-1]+v[i];
    }
    cout<<max(dp[0][n-1],max(dp[1][n-1],dp[2][n-1]));
}

#endif /* WineTasting___h */
