//
//  10971.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/30.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _0971_h
#define _0971_h
#include<iostream>

using namespace std;
int citiys[10][10];
int N;
bool visisteds[10];
int answer=10000000;

void DFS(int startIndex,int curNode,int amount,int visitedCnt)
{
    if(visitedCnt==N&&startIndex==curNode)
    {
        answer=min(answer,amount);
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(citiys[curNode][i]!=0&&!visisteds[i])
        {
            visisteds[i]=true;
            DFS(startIndex,i,amount+citiys[curNode][i],visitedCnt+1);
            visisteds[i]=false;
        }
    }
}
void solution()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>citiys[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        DFS(i,i,0,0);
    }
    cout<<answer;
}

#endif /* _0971_h */
