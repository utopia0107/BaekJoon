//
//  CombinedDecomposition .h
//  BaekJoon
//
//  Created by 정민수 on 19/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef CombinedDecomposition__h
#define CombinedDecomposition__h
#include<iostream>
using namespace std;
//K(번째),N(숫자)
int dp[200][201];
void soultion()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=1;
    }
    for(int depth=1;depth<k;depth++)
    {
        for(int startNum=0;startNum<=n;startNum++)
        {
            for(int num=0;num<=startNum;num++)
            {
                dp[depth][startNum]+=dp[depth-1][startNum-num]*dp[0][num];
                dp[depth][startNum]%=1000000000;
            }
        }
    }
    cout<<dp[k-1][n];
}

#endif /* CombinedDecomposition__h */
