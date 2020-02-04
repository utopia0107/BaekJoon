//
//  14501.h
//  BaekJoon
//
//  Created by 정민수 on 03/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4501_h
#define _4501_h
#include<iostream>
using namespace std;
//현재 날짜,교육기간.
int dp[15][15];
//day,money
int fireMap[15][2];
void solution()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>fireMap[i][0]>>fireMap[i][1];
    }
    for(int i=0;i<=n;i++)
    {
        int maxNum=0;
        for(int j=i;j>=0;j--)
        {
            for(int k=j;k<i;k++)
            {
                maxNum=max(dp[j][k-j],maxNum);
            }
        }
        dp[i][0]=maxNum;
        dp[i][fireMap[i][0]-1]=maxNum+fireMap[i][1];

    }
    cout<<dp[n][0];
}

#endif /* _4501_h */
