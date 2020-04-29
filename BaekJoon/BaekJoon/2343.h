//
//  2343.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _343_h
#define _343_h
#include<iostream>
#include<vector>
using namespace std;
int CheckMakeBlueRay(vector<int> lessons,int maxSize)
{
    int total=0;
    int cnt=1;
    for(int i=0;i<lessons.size();i++)
    {
        if(maxSize<lessons[i])return -1;
        if(total+lessons[i]>maxSize)
        {
            cnt++;
            total=0;
        }
        total+=lessons[i];
    }
    return cnt;
}
void solution()
{
    int N,M;
    cin>>N>>M;
    vector<int>lessons;
    lessons.resize(N);
    int maxNum=0;
    for(int i=0;i<N;i++)
    {
        cin>>lessons[i];
        maxNum=max(maxNum,lessons[i]);
    }
    
    int start=0,end=1'000'000'000;
    int answer=0;
    if(N==M)
    {
        answer=maxNum;
    }
    else
    {
        while(start<end)
        {
            int mid=(start+end)/2;
            int cnt=CheckMakeBlueRay(lessons,mid);
            if(cnt<0||cnt>M)
            {
                start=mid+1;
            }
            else if(cnt<=M)
            {
                end=mid;
            }
        }
        answer=start;
    }
    cout<<answer;
}

#endif /* _343_h */
