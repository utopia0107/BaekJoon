//
//  11659.h
//  BaekJoon
//
//  Created by 정민수 on 2020/05/11.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1659_h
#define _1659_h
#include<iostream>
using namespace std;
//Prefix Sum 구간 합
void solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int nums[100'001];
    int sums[100'001]={0,};
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>nums[i];
    }
    for(int i=1;i<=N;i++)
    {
        sums[i]=sums[i-1]+nums[i];
    }
    
    while(M--)
    {
        int start,end;
        cin>>start>>end;
        cout<<sums[end]-sums[start-1]<<"\n";
    }
}

#endif /* _1659_h */
