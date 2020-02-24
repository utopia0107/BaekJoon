//
//  1654.h
//  BaekJoon
//
//  Created by 정민수 on 24/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _654_h
#define _654_h
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> lens;

void solution()
{
    long long len_cnt,need_cnt,temp,cur_cnt;
    long long left,right,mid,Max=0;
    left=1;
    cin>>len_cnt>>need_cnt;
    for(int i=0;i<len_cnt;i++)
    {
        cin>>temp;
        lens.push_back(temp);
    }
    sort(lens.begin(), lens.end());
    right=lens[len_cnt-1];
    
    while (left<=right)
    {
        cur_cnt=0;
        mid=(left+right)/2;
        for(int i=0;i<len_cnt;i++)
        {
            cur_cnt+=lens[i]/mid;
        }
        if(cur_cnt<need_cnt)
        {
            right=mid-1;
        }
        else
        {
            Max=max(Max,mid);
            left=mid+1;
        }
    }
    cout<<Max;
}



#endif /* _654_h */
