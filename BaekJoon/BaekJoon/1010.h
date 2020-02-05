//
//  1010.h
//  BaekJoon
//
//  Created by 정민수 on 05/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _010_h
#define _010_h
#include<iostream>
using  namespace  std;
int dp[31][31];
void solution()
{
    int t;
    int n,m;
    cin>>t;
    for(int i=0;i<31;i++)
    {
        for(int j=0;j<31;j++)
        {
            dp[i][j]=-1;
        }
    }
    while(t--)
    {
        cin>>n>>m;
        if(dp[n][m]==-1)
        {
            if (n*2>m) {
                n=m-n;
            }
            long long num=1;
            for(int i=0;i<n;i++)
            {
                num*=(m-i);
            }
            for(int i=n;i>=2;i--)
            {
                num/=i;
            }
            dp[abs(m-n)][m]=dp[n][m] = num;
        }
        cout<<dp[n][m]<<"\n";
    }
}



#endif /* _010_h */
