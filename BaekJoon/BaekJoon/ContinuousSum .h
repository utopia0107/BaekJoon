//
//  ContinuousSum .h
//  BaekJoon
//
//  Created by 정민수 on 17/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef ContinuousSum__h
#define ContinuousSum__h
#include<iostream>
#include<vector>
using namespace std;
//start,last
vector<int> dp[100000];
void soultion()
{
    int n;
    vector<int> v;
    cin>>n;
    v.resize(n);
    int answer=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    answer=sum;
    dp[n-1].push_back(sum);
    
    //간격(start,last)
    for(int i=n-2;i>=0;i--)
    {
        vector<int> temp=dp[i+1];
        for(int j=0;j<temp.size()-1;j++)
        {
        }
        dp[i].push_back(temp[temp.size()-1]);
        //startIndex
        for(int j=0;j+i<n;j++)
        {
            //뒤에꺼 빼기
            if(dp[j][j+i-1]==0)
            {
                dp[j][j+i-1]=dp[j][j+i]-v[j+i];
                answer=max(answer,dp[j][j+i-1]);
            }
            //앞에꺼 빼기
            if(dp[j+1][j+i]==0)
            {
                dp[j+1][j+i]=dp[j][j+i]-v[j];
                answer=max(answer,dp[j+1][j+i]);
            }
        }
    }
 
    cout<<answer;
}

#endif /* ContinuousSum__h */
