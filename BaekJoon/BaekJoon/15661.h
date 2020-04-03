//
//  15661.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/03.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5661_h
#define _5661_h
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int abilitys[20][20];
int N;
int answer=1000000000;

int SynergyAbility(vector<int> team)
{
    int abilityAmount=0;
    for(int i=0;i<team.size()-1;i++)
    {
        for(int j=i;j<team.size();j++)
        {
            abilityAmount+=abilitys[team[i]][team[j]];
            abilityAmount+=abilitys[team[j]][team[i]];
        }
    }
    return  abilityAmount;
}
vector<int> pathA,pathB;
bool visited[20];

void DFS(int curIndex,int depth)
{
    if(depth==N)return;
    if(pathA.size()>0)
    {
        for(int i=0;i<N;i++)
        {
            if(!visited[i])pathB.push_back(i);
        }
        if(pathB.size()>0)answer=min(answer,abs(SynergyAbility(pathA)-SynergyAbility(pathB)));
        pathB.clear();
    }
    for(int i=curIndex;i<N;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            pathA.push_back(i);
            DFS(i,depth+1);
            pathA.pop_back();
            visited[i]=false;
        }
    }
}


void solution()
{
    cin>> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>abilitys[i][j];
        }
    }
    DFS(0,0);
    cout<<answer;
}

#endif /* _5661_h */
