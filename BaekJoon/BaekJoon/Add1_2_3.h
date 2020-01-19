//
//  Add1_2_3.h
//  BaekJoon
//
//  Created by 정민수 on 19/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Add1_2_3_h
#define Add1_2_3_h
#include<iostream>
using namespace std;
int dp[11];
void soultion()
{
    int t;
    int maxNum=3;
    cin>>t;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    while(t--)
    {
        int num;
        cin>>num;
        if(num>maxNum)
        {
            for(int i=maxNum+1;i<=num;i++)
            {
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            }
            maxNum=num;
        }
        cout<<dp[num]<<"\n";
    }
}


#endif /* Add1_2_3_h */
