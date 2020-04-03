//
//  3190.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/03.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _190_h
#define _190_h
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool map[101][101];
void solution()
{
    int N;
    cin>>N;
    int appleCnt;
    cin>>appleCnt;
    while(appleCnt--)
    {
        int y,x;
        cin>>y>>x;
        map[y][x]=true;
    }
    int opCnt;
    queue<pair<int,char>> operators;
    cin>>opCnt;
    while (opCnt--) {
        int time;
        char dir;
        cin>>time>>dir;
        operators.push(make_pair(time,dir));
    }
    int curTime=0;
    // 0,1,2,3 => 상,우,하,좌
    int direction=1;
    int x=1,y=1;
    vector<pair<int,int>> snake;
    snake.push_back(make_pair(y, x));
    while(true)
    {
        curTime++;
        switch (direction) {
            //상
            case 0:
                y-=1;
                break;
            //우
            case 1:
                x+=1;
                break;
            //하
            case 2:
                y+=1;
                break;
            //좌
            case 3:
                x-=1;
                break;
        }
        int i;
        for(i=0;i<snake.size();i++)
        {
            if(snake[i].first==y&&
               snake[i].second==x)break;
        }
        if(x<1||y<1||x>N||y>N||i!=snake
            .size())break;
        if(map[y][x])
        {
            map[y][x]=false;
            snake.insert(snake.begin(), make_pair(y, x));
        }else
        {
            snake.erase(snake.end()-1);
            snake.insert(snake.begin(), make_pair(y, x));
        }
        if(!operators.empty()&&operators.front().first==curTime)
        {
            switch (operators.front().second) {
                //시계 방향
                case 'D':
                    direction=(direction+1)%4;
                    break;
                //반시계 방향
                case 'L':
                    direction=(direction+3)%4;
                    break;

            }
            operators.pop();
        }
    }
    cout<<curTime;
}

#endif /* _190_h */
