//
//  1912.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/22.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _912_h
#define _912_h
#include<iostream>
using namespace std;


void solution()
{
    int nums[100'000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int dp[100'000];
    dp[0]=nums[0];
    int answer=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        answer=max(answer,dp[i]);
    }
    cout<<answer;
}

#endif /* _912_h */
