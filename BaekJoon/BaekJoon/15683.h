//
//  15683.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/03.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5683_h
#define _5683_h
#include<iostream>
#include<vector>
using namespace std;
int map[8][8];
vector<pair<int,int>> emptys;
//카메라 종류,상태,pos(y,x);
vector<pair<pair<int,int>,pair<int,int>>> cameras;
int N,M,answer=64;

void ResetMap()
{
    for(int i=0;i<emptys.size();i++)
    {
        map[emptys[i].first][emptys[i].second]=0;
    }
}
int GetCountBlindSpot()
{
    int cnt=0;
    for(int i=0;i<emptys.size();i++)
    {
        if(map[emptys[i].first][emptys[i].second]==0)cnt++;
    }
    return cnt;
}

void DrawLine(int y,int x, int direction)
{
    switch (direction) {
            //상
        case 0:
            while(y>0&&map[y][x]!=6)
            {
                y--;
                if(map[y][x]==0)map[y][x]=-1;
            }
            break;
            //우
        case 1:
            while(x<M-1&&map[y][x]!=6)
            {
                x++;
                if(map[y][x]==0)map[y][x]=-1;
            }
            break;
            //하
        case 2:
            while(y<N-1&&map[y][x]!=6)
            {
                y++;
                if(map[y][x]==0)map[y][x]=-1;
            }
            break;
            //좌
        case 3:
            while(x>0&&map[y][x]!=6)
            {
                x--;
                if(map[y][x]==0)map[y][x]=-1;
            }
            break;
    }
}
void DrawCameraSurveillanceArea(int index)
{
    switch (cameras[index].first.first) {
        case 1:
            DrawLine(cameras[index].second.first, cameras[index].second.second,cameras[index].first.second);
            break;
        case 2:
            DrawLine(cameras[index].second.first, cameras[index].second.second,cameras[index].first.second);
            DrawLine(cameras[index].second.first, cameras[index].second.second,(cameras[index].first.second+2)%4);
            break;
        case 3:
            DrawLine(cameras[index].second.first, cameras[index].second.second,cameras[index].first.second);
            DrawLine(cameras[index].second.first, cameras[index].second.second,(cameras[index].first.second+1)%4);
            break;
        case 4:
            DrawLine(cameras[index].second.first, cameras[index].second.second,cameras[index].first.second);
            DrawLine(cameras[index].second.first, cameras[index].second.second,(cameras[index].first.second+1)%4);
            DrawLine(cameras[index].second.first, cameras[index].second.second,(cameras[index].first.second+2)%4);
            break;
        case 5:
            DrawLine(cameras[index].second.first, cameras[index].second.second,0);
            DrawLine(cameras[index].second.first, cameras[index].second.second,1);
            DrawLine(cameras[index].second.first, cameras[index].second.second,2);
            DrawLine(cameras[index].second.first, cameras[index].second.second,3);
            break;
    }
}
bool ChangeNextState(int index)
{
    switch (cameras[index].first.first) {
        case 1:
        case 3:
        case 4:
            cameras[index].first.second++;
            return cameras[index].first.second<4;
            break;
        case 2:
            cameras[index].first.second++;
            return cameras[index].first.second<2;
            break;
        case 5:
            return false;
            break;
    }
    return  false;
}

void DFS(int index)
{
    if(index==cameras.size())
    {
        for(int i=0;i<cameras.size();i++)
        {
            DrawCameraSurveillanceArea(i);
        }
        answer=min(answer,GetCountBlindSpot());
        ResetMap();
        return;
    }
    else
    {
        while(true)
        {
            DFS(index+1);
            cameras[index+1].first.second=0;
            if(!ChangeNextState(index))break;
        }
    }
}
void solution()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==0)emptys.push_back(make_pair(i,j));
            else if(map[i][j]<6)cameras.push_back(make_pair(make_pair(map[i][j], 0),make_pair(i, j)));
        }
    }
    DFS(0);
    cout<<answer;
    
}

#endif /* _5683_h */
