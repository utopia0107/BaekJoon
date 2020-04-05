//
//  11726.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/05.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1726_h
#define _1726_h
#include<iostream>
using namespace std;
int dp[1001];
void solution()
{
    int n;
    dp[1]=1;
    dp[2]=2;
    cin>>n;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=10007;
    }
    cout<<dp[n];
    
}

#endif /* _1726_h */
