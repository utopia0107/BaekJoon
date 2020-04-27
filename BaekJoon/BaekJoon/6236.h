//
//  6236.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/27.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _236_h
#define _236_h
#include <iostream>
#include <vector>
using namespace std;

int GetCountWithdraw(vector<int> v, int money)
{
    int curMoney=0;
    int withdrawCnt=0;
   
    for(int i=0;i<v.size();i++)
    {
        if(money <v[i])return 100000;
        if(curMoney<v[i])
        {
            curMoney=money;
            withdrawCnt++;
        }
        curMoney-=v[i];
        
    }
    return withdrawCnt;
}
void  solution()
{
    int N,M;
       cin>>N>>M;
       vector<int> v;
       v.resize(N);
       int total=0;
    int minNum=10000;
       for(int i=0;i<N;i++)
       {
           cin>>v[i];
           total+=v[i];
           minNum=min(minNum,v[i]);
       }
       int start=minNum,end=total;
       int answer=0;
       while(start<=end)
       {
           int mid=(start+end)/2;
           int cnt=GetCountWithdraw(v, mid);
           if(M>=cnt)
           {
               end=mid-1;
               answer=mid;
           }else
           {
               start=mid+1;
           }
       }
       cout<<answer;
}

#endif /* _236_h */
