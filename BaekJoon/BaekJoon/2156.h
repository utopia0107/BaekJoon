//
//  2156.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/05.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _156_h
#define _156_h
#include<iostream>
using namespace std;
int dp[3][10001];
int wines[10001];
void solution()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>wines[i];
    
    dp[1][1]=wines[1];
    for(int i=2;i<=n;i++)
    {
        //안마심
        dp[0][i]=max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]));
        //첫 잔 마심
        dp[1][i]=dp[0][i-1]+wines[i];
        //연속 마심
        dp[2][i]=dp[1][i-1]+wines[i];
    }
    
    cout<<max(dp[0][n],max(dp[1][n],dp[2][n]));
}

#endif /* _156_h */
