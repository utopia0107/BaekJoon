//
//  2792.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/28.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _792_h
#define _792_h
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int GetCountJealousy(vector<int> jewelrys, int maxNum)
{
    int cnt=0;
    //한 종류의 보석 갯수 보다 많으면 분배 할 수 없음.
    for(int i=0;i<jewelrys.size();i++)
    {
       cnt+=(int)ceil((double)jewelrys[i]/maxNum);
    }
    return cnt;
}

void solution()
{
    int N,M;
    cin>>N>>M;
    vector<int> jewelrys;
    jewelrys.resize(M);
    for(int i=0;i<M;i++)
    {
        cin>>jewelrys[i];
    }
    sort(jewelrys.begin(),jewelrys.end());
    int start=0,end=jewelrys[jewelrys.size()-1];
    int answer=jewelrys[jewelrys.size()-1];
    while(start<end)
    {
        int mid=(start+end)/2;
        if(GetCountJealousy(jewelrys,mid)<=N)
        {
            answer=end=mid;
        }
        //분배 불가능 mid 값이 커서(end 값이 커사)
        else
        {
            start=mid+1;
        }
        
    }
    cout<<answer;
}

#endif /* _792_h */
