//
//  14888.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/31.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4888_h
#define _4888_h
#include<iostream>
using namespace std;
int nums[11];
int minAnswer=1000000000,maxAnswer=-1000000000;
int operatorCnt[4];
 int cnt;
void DFS(int total, int index)
{
    if(index==cnt)
    {
        //cout<<total;
        minAnswer=min(minAnswer,total);
        maxAnswer=max(maxAnswer,total);
        return;
    }
    if(operatorCnt[0]>0)
    {
        operatorCnt[0]--;
        DFS(total+nums[index],index+1);
        operatorCnt[0]++;

    }
    if(operatorCnt[1]>0)
    {
        operatorCnt[1]--;
        DFS(total-nums[index],index+1);
        operatorCnt[1]++;


    }
    if(operatorCnt[2]>0)
    {
        operatorCnt[2]--;
        DFS(total*nums[index],index+1);
        operatorCnt[2]++;


    }
    if(operatorCnt[3]>0)
    {
        operatorCnt[3]--;
        DFS(total/nums[index],index+1);
        operatorCnt[3]++;

    }
}

void solution()
{
   
    cin>>cnt;
    for(int i=0;i<cnt;i++)
    {
        cin>>nums[i];
    }
    
    for(int i=0;i<4;i++)
    {
        cin>>operatorCnt[i];
    }
    DFS(nums[0],1);
    cout<<maxAnswer<<"\n"<<minAnswer;
}


#endif /* _4888_h */
