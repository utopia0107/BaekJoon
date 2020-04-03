//
//  14890.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/02.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4890_h
#define _4890_h
#include<iostream>
using namespace std;
int map[100][100];
int N,L;
//수평
bool SerachHorizon(int startIndex)
{
    bool blocks[100]={false,};
    int blockCnt=0;
    for(int i=0;i<N-1;i++)
    {
        if(blockCnt>0){
            if(blocks[i])return false;
            blocks[i]=true;
            blockCnt--;
        }
        if(map[startIndex][i]-1==map[startIndex][i+1])
        {
            if(blockCnt>0)return false;
            blockCnt+=L;
        }
        if(abs(map[startIndex][i]-map[startIndex][i+1])>1)return  false;
    }
    if(blockCnt>0)
    {
        if(blocks[N-1])return false;
        blocks[N-1]=true;
        blockCnt--;
    }
    if(blockCnt!=0)return false;
    
    for(int i=N-1;i>0;i--)
    {
        if(blockCnt>0){
            if(blocks[i])return false;
            blocks[i]=true;
            blockCnt--;
        }
        if(map[startIndex][i]==map[startIndex][i-1]+1)
        {
            if(blockCnt>0)return false;
            blockCnt+=L;
        }
        if(abs(map[startIndex][i]-map[startIndex][i-1])>1)return  false;
    }
    if(blockCnt>0)
    {
        if(blocks[0])return false;
        blocks[0]=true;
        blockCnt--;
    }
    return blockCnt==0;
}
//수직
bool SerachVertical(int startIndex)
{
    bool blocks[100]={false,};
    int blockCnt=0;
    for(int i=0;i<N-1;i++)
    {
        if(blockCnt>0){
            if(blocks[i])return false;
            blocks[i]=true;
            blockCnt--;
        }
        if(map[i][startIndex]-1==map[i+1][startIndex])
        {
            if(blockCnt>0)return false;
            blockCnt+=L;
        }
        if(abs(map[i][startIndex]-map[i+1][startIndex])>1)return  false;
    }
    if(blockCnt>0)
    {
        if(blocks[N-1])return false;
        blocks[N-1]=true;
        blockCnt--;
    }
    if(blockCnt!=0)return false;
    
    
    for(int i=N-1;i>0;i--)
    {
        if(blockCnt>0){
            if(blocks[i])return false;
            blocks[i]=true;
            blockCnt--;
        }
        if(map[i][startIndex]==map[i-1][startIndex]+1)
        {
            if(blockCnt>0)return false;
            blockCnt+=L;
        }
        if(abs(map[i][startIndex]-map[i-1][startIndex])>1)return  false;
    }
    if(blockCnt>0)
    {
        if(blocks[0])return false;
        blocks[0]=true;
        blockCnt--;
    }
    return blockCnt==0;
}
void solution()
{
    cin>>N>>L;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        if(SerachHorizon(i))
        {
            cnt++;
        }
        if(SerachVertical(i))
        {
            cnt++;
        }
    }
    cout<<cnt;
}

#endif /* _4890_h */
