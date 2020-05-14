//
//  2206.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/08.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _206_h
#define _206_h
#include<iostream>
#include<queue>
using namespace std;
const int INF=2000000000;
void solution()
{
    int w,h;
    char map[1000][1000];
    //0=false, 1=true
    int visited[2][1000][1000]={0};
    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        cin.get();
        for(int j=0;j<w;j++)
        {
            map[i][j]=cin.get();
            visited[0][i][j]=visited[1][i][j]=0;
        }
    }
    
    //상,우,하,좌
    int dir[]={-1,0,1,0};
    queue<pair<int,int>> q;
    queue<bool> distory;
    q.push(make_pair(0,0));
    distory.push(false);
    visited[0][0][0]=1;
    while(!q.empty())
    {
        pair<int,int>  cur = q.front();
        bool isDistory=distory.front();
        
        if(cur.first+1==h&&cur.second+1==w)break;
        distory.pop();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            pair<int,int> next = make_pair(cur.first+dir[i], cur.second+dir[(i+1)%4]);
            if(next.first<0||next.second<0||next.first>=h||next.second>=w)continue;
            if(map[next.first][next.second]=='1'
               && isDistory==false)
            {
                visited[1][next.first][next.second]=visited[0][cur.first][cur.second]+1;
                q.push(next);
                distory.push(true);
            }
            else if(map[next.first][next.second]=='0'
                    && visited[isDistory?1:0][next.first][next.second]==0)
            {
                visited[isDistory?1:0][next.first][next.second]=visited[isDistory?1:0][cur.first][cur.second]+1;
                q.push(next);
                distory.push(isDistory);
            }
        }
    }
    
    int answer= !q.empty() ? visited[distory.front()?1:0][q.front().first][q.front().second]:-1;
    cout<<answer;
}

#endif /* _206_h */
