//
//  14502.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/03.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4502_h
#define _4502_h
#include<iostream>
#include<vector>
using namespace std;
int map[8][8];
int N,M;
int cnts[3];
int answer=0;
vector<pair<int,int>> emptys;
vector<pair<int,int>> virus;
vector<pair<int,int>> walls;
vector<pair<int,int>> moveWalls;

bool visited[64];
void Reset()
{
    for(int i=0;i<emptys.size();i++)
    {
        map[emptys[i].first][emptys[i].second]=0;
    }
    for(int i=0;i<walls.size();i++)
    {
        map[walls[i].first][walls[i].second]=1;
    }
    
}
void SpreadVirus(int y, int x)
{
    if(map[y][x]==2||map[y][x]==0)map[y][x]=2;
    else return;
    //상
    if(y>0&&map[y-1][x]==0)
    {
        SpreadVirus(y-1, x);
    }
    //하
    if(y<N-1&&map[y+1][x]==0)
    {
        SpreadVirus(y+1, x);
    }
    //좌
    if(x>0&&map[y][x-1]==0)
    {
        SpreadVirus(y, x-1);
    }
    //우
    if(x<M-1&&map[y][x+1]==0)
    {
        SpreadVirus(y, x+1);
    }
}
int GetSafetyArea()
{
    int cnt=0;
    for(int i=0;i<emptys.size();i++)
    {
        if(map[emptys[i].first][emptys[i].second]==0)
        {
            cnt++;
        }
    }
    return cnt;
}
void DFS(int curIndex,int depth)
{
    if(depth==3)
    {
        for(int i=0;i<moveWalls.size();i++)
        {
            map[moveWalls[i].first][moveWalls[i].second]=1;
        }
        for(int i=0;i<virus.size();i++)
        {
            SpreadVirus(virus[i].first, virus[i].second);
        }
        answer=max(answer, GetSafetyArea());
        Reset();
        return;
    }
    for(int i=curIndex+1;i<emptys.size();i++)
    {
        if(!visited[curIndex])
        {
            visited[curIndex]=true;
            moveWalls.push_back(emptys[i]);
            DFS(i,depth+1);
            moveWalls.pop_back();
            visited[curIndex]=false;
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
            switch (map[i][j])
            {
                case 0:
                    emptys.push_back(make_pair(i, j));
                    break;
                case 1:
                    walls.push_back(make_pair(i, j));
                case 2:
                    virus.push_back(make_pair(i, j));
                    break;
            }
        }
    }
    answer=0;
    DFS(-1,0);
    
    cout<<answer;
}


#endif /* _4502_h */
