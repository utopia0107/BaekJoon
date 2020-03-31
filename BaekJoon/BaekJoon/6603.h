//
//  6603.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/30.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _603_h
#define _603_h
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> nums;
vector<int> path;
bool visiteds[13];
int depth=1;
void DFS(int index)
{
    if(depth==7)
    {
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=index+1;i<nums.size();i++)
    {
        if(!visiteds[i])
        {
            depth++;
            visiteds[i]=true;
            path.push_back(nums[i]);
            DFS(i);
            depth--;
            path.pop_back();
            visiteds[i]=false;
        }
    }
}
void solution()
{
    int n;
    while (true) {
        cin>>n;
        if(n==0)break;
        nums.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        DFS(-1);
        cout<<"\n";
    }
}

#endif /* _603_h */
