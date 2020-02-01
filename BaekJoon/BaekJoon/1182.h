//
//  1182.h
//  BaekJoon
//
//  Created by 정민수 on 01/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _182_h
#define _182_h
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int targetNum;
int answerCnt;
void DFS(int num, int index, int depth, vector<int>path)
{
    if(depth!=0 && num==targetNum)
    {
        answerCnt++;
    }
    depth++;
    for(int i=index;i<v.size();i++)
    {
        DFS(num+v[i],i+1,depth,path);
    }
}
void solution()
{
    int n;
    cin>>n>>targetNum;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> path;
    DFS(0,0,0,path);
    cout<<answerCnt;
}

#endif /* _182_h */
