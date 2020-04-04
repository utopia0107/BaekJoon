//
//  7576.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/04.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _576_h
#define _576_h
#include<iostream>
#include<queue>
using namespace  std;
int box[1000][1000];
bool visited[1000][1000];
int dir[4]={-1,0,1,0};
void solution()
{
    int w,h;
    cin>>w>>h;
    queue<pair<int,int>> tomatos;
    int tomatoCnt=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>box[i][j];
            if(box[i][j]==1) tomatos.push(make_pair(i,j));
            if(box[i][j]==0)tomatoCnt++;
        }
    }
    int day=0;
    int sizeCnt=tomatos.size();
    while(!tomatos.empty())
    {
        pair<int,int> pos= tomatos.front();
        tomatos.pop();
        sizeCnt--;
        if(box[pos.first][pos.second]==0)tomatoCnt--;
        box[pos.first][pos.second]=1;
        for(int i=0;i<4;i++)
        {
            pair<int,int> next=make_pair(pos.first+dir[i],pos.second+dir[(i+1)%4]);
            if(next.first>=0&&next.second>=0&&next.first<h&&next.second<w
               &&box[next.first][next.second]==0&&!visited[next.first][next.second])
            {
                visited[next.first][next.second]=true;
                tomatos.push(next);
            }
        }
          if(tomatoCnt==0)break;
        if(sizeCnt==0)
        {
            day++;
            sizeCnt=tomatos.size();
        }
     
    }
    if(tomatoCnt==0)cout<<day;
    else cout<<-1;
}

#endif /* _576_h */
