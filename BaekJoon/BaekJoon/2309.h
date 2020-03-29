//
//  2309.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _309_h
#define _309_h
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool visiteds[9];
int heights[9];
vector<int> path;

void DFS(int num,int depth)
{
    if(num<0||depth>7)return;
    if(num==0&&depth==7)
    {
        if(path.size()==0)
        {
            for(int i=0;i<9;i++)
            {
                if(visiteds[i])path.push_back(heights[i]);
            }
        }
        return;
    }
    for(int i=0;i<9;i++)
    {
        if(!visiteds[i])
        {
            visiteds[i]=true;
            DFS(num-heights[i],depth+1);
            visiteds[i]=false;
        }
    }
}
void solution()
{
    for(int i=0;i<9;i++)
    {
        cin>>heights[i];
    }
    DFS(100,0);
    sort(path.begin(),path.end());
    for(int i=0;i<7;i++)
    {
        cout<<path[i]<<"\n";
    }
}

#endif /* _309_h */
