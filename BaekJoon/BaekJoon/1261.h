//
//  1261.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/08.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _261_h
#define _261_h
#include<iostream>
using namespace std;
//true= empty, false = wall
bool map[100][100];
int visited[100][100]={100000,};
int width,height;
int answer=10000;
int direction[4]={-1,0,1,0};
void DFS(int y,int x,int destoryCnt)
{
    visited[y][x]=destoryCnt;
    if(y==height-1&&x==width-1)
    {
        answer=min(answer,destoryCnt);
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int nextX=x+direction[(i+1)%4],nextY=y+direction[i];
        
        if(nextX>=0&&nextY>=0&&nextX<width&&nextY<height)
       {
           if(map[nextY][nextX]&&visited[nextY][nextX]>destoryCnt)
           {
                DFS(nextY,nextX,destoryCnt);
           }else if(!map[nextY][nextX]&&visited[nextY][nextX]>destoryCnt+1)
           {
                DFS(nextY,nextX,destoryCnt+1);
           }
        }
    }
}

void solution()
{
    cin>>width>>height;
    for(int i=0;i<height;i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<width;j++)
        {
            map[i][j]=str[j]=='0';
            visited[i][j]=100000;
        }
    }
    DFS(0,0,0);
    cout<<answer;
}

#endif /* _261_h */
