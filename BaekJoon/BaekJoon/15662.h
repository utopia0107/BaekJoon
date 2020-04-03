//
//  15662.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/02.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5662_h
#define _5662_h
#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
int gearCnt;
bool gears[1000][8];
bool visited[1000];
bool CheckGear(int left,int right)
{
    if(left>=0&&right<gearCnt)return gears[left][2]!=gears[right][6];
    else return false;
}
//N=false,S=true
void RotateGear(int index,int direction)
{
   visited[index]=true;
    //시계방향
    if(direction==1)
    {
        bool temp=gears[index][7];
        for(int i=7;i>0;i--)
        {
            gears[index][i]=gears[index][i-1];
        }
        gears[index][0] =temp;
    }else if(direction==-1)
    {
        bool temp=gears[index][0];
        for(int i=0;i<7;i++)
        {
            gears[index][i]=gears[index][i+1];
        }
        gears[index][7] =temp;
    }
}

void solution()
{
    string magnet="";
    cin>>gearCnt;
    for(int i=0;i<gearCnt;i++)
    {
        cin>>magnet;
        for(int  j=0;j<magnet.length();j++)
        {
            gears[i][j]=magnet[j]=='1';
        }
    }
    int k;
    cin>>k;
    while(k--)
    {
        int index,direction;
        cin>>index>>direction;
        index--;
        memset(visited,false,sizeof(visited));
        queue<pair<int,int>> q;
        q.push(make_pair(index, direction));
        while(!q.empty())
        {
            index=q.front().first;
            direction=q.front().second;
            q.pop();
            if(visited[index])continue;
            visited[index]=true;

            if(CheckGear(index,index+1))
            {
                q.push(make_pair(index+1, direction*-1));
            }
            if(CheckGear(index-1,index))
            {
                q.push(make_pair(index-1, direction*-1));
            }
            RotateGear(index,direction);
        }
    }
    int answer=0;
    for(int i=0;i<gearCnt;i++)
    {
        if(gears[i][0])answer++;
    }
    cout<<answer;
}

#endif /* _5662_h */
