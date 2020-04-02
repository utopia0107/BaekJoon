//
//  14891.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/02.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4891_h
#define _4891_h
#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
bool gears[4][8];
bool visited[4];
bool CheckGear(int left,int right)
{
    if(left>=0&&right<4)return gears[left][2]!=gears[right][6];
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
    for(int i=0;i<4;i++)
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
    for(int i=0;i<4;i++)
    {
        if(gears[i][0])answer+=pow(2,i);
    }
    cout<<answer;
}

#endif /* _4891_h */
