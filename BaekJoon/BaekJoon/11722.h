//
//  11722.h
//  BaekJoon
//
//  Created by 정민수 on 20/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1722_h
#define _1722_h
#include<iostream>
using namespace std;
int nums[1000];
int dp[1000];
void soultion()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(nums[j]>nums[i])dp[i]=max(dp[i],dp[j]);
        }
        dp[i]++;
    }
    int answer=0;
    for(int i=0;i<n;i++)
    {
        answer=max(answer,dp[i]);
    }
    cout<<answer;
}

#endif /* _1722_h */
