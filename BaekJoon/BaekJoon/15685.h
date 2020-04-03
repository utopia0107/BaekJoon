//
//  15685.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/03.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _5685_h
#define _5685_h
#include<iostream>
#include<vector>
using namespace std;
//(x,y)
vector<pair<int,int>> paths[20];
bool map[101][101];
vector<int> GetDirections(vector<pair<int,int>> path)
{
    vector<int> directions;
    for(int i=path.size()-1;i>0;i--)
    {
        if(path[i].second==path[i-1].second-1)
        {
            directions.push_back(3);
        }
        else if(path[i].second==path[i-1].second+1)
        {
            directions.push_back(1);
        }
        else if(path[i].first==path[i-1].first+1)
        {
            directions.push_back(2);
        }
        else if(path[i].first==path[i-1].first-1)
        {
            directions.push_back(0);
        }
    }
    return directions;
}
pair<int,int> ChangePosDirection(int x, int y, int d)
{
    switch (d) {
            //우
        case 0:
            return make_pair(x+1, y);
            break;
        case 1:
            return make_pair(x, y-1);
            break;
        case 2:
            return make_pair(x-1, y);
            break;
        case 3:
            return make_pair(x, y+1);
            break;
    }
    return make_pair(0, 0);
}

void DragonCurve(int x,int y,int d,int n)
{
    if(paths[n].size()==0)
    {
        paths[n].push_back(make_pair(x, y));
        pair<int,int> pos=ChangePosDirection(x, y, d);
        if(pos.first>=0&&pos.second>=0
            &&pos.first<=100&&pos.second<=100)
        {
            paths[n].push_back(pos);
        }
    }
    else
    {
        vector<int> directions= GetDirections(paths[n]);
        for(int i=0;i<directions.size();i++)
        {
            int last=paths[n].size()-1;
            pair<int,int>pos=ChangePosDirection(paths[n][last].first, paths[n][last].second,(directions[i]+3)%4);
            if(pos.first>=0&&pos.second>=0
               &&pos.first<=100&&pos.second<=100)
            {
                paths[n].push_back(pos);
            }
        }
    }
}

void solution()
{
    int N;
    cin>>N;
    while(N--)
    {
        int x,y,g,d;
        cin>>x>>y>>d>>g;
        do
        {
            DragonCurve(x,y,d,N);
        }while(g--);
        for(int i=0;i<paths[N].size();i++)
        {
            map[paths[N][i].second][paths[N][i].first]=true;
        }
    }
    int cnt=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(map[i][j]&&map[i+1][j]&&map[i][j+1]&&map[i+1][j+1])cnt++;
        }
    }
    cout<<cnt;
}

#endif /* _5685_h */
