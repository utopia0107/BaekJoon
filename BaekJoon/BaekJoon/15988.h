//
//  15988.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/22.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5988_h
#define _5988_h
#include<iostream>
using namespace std;
long long dp[1'000'001];
void solution()
{
    int t;
    int maxNum=3;
    cin>>t;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    while (t--)
    {
        int num;
        cin>>num;
        if(maxNum<num)
        {
            for(int i=maxNum+1;i<=num;i++)
            {
                dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
            }
        }
        cout<<dp[num]<<"\n";
    }
}

#endif /* _5988_h */
