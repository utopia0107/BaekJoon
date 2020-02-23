//
//  2512.h
//  BaekJoon
//
//  Created by 정민수 on 23/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _512_h
#define _512_h
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> budgets;

void solution()
{
    long long budget_cnt,totalBudget,temp,cur_budget;
    long long left,right=0,mid,Max=0;
    left=0;
    cin>>budget_cnt;
    for(int i=0;i<budget_cnt;i++)
    {
        cin>>temp;
        budgets.push_back(temp);
    }
    cin>>totalBudget;
    sort(budgets.begin(), budgets.end());
    for(int i=0;i<budget_cnt;i++)
    {
        right+=budgets[i];
    }
    
    if(totalBudget>=right)
    {
        cout<<budgets[budget_cnt-1];
    }
    else
    {
        while (left<=right)
        {
            cur_budget=0;
            mid=(left+right)/2;
            for(int i=0;i<budget_cnt;i++)
            {
                cur_budget+= budgets[i]<=mid?budgets[i]:mid;
            }
            if(cur_budget<=totalBudget)
            {
                left=mid+1;
                Max=max(Max,mid);
            }
            else
            {
                right=mid-1;
            }
        }
        cout<<Max;
    }
    
}



#endif /* _512_h */
