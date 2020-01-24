//
//  4963.h
//  BaekJoon
//
//  Created by 정민수 on 24/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _963_h
#define _963_h
#include<iostream>
#include<queue>

using namespace std;
bool visited[50][50];
int maps[50][50];
const pair<int,int> direction[8]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1} };
void soultion()
{
    int w,h,cnt;
    while (true)
    {
        cin>>w>>h;
        if(w==0&&h==0)break;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>maps[i][j];
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(maps[i][j]==1&&!visited[i][j])
                {
                    cnt++;
                    queue<pair<int,int>>q;
                    visited[i][j]=true;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        pair<int,int> index=q.front();
                        q.pop();
                        for(int k=0;k<8;k++)
                        {
                            pair<int,int> nextIndex;
                            nextIndex.first=index.first+direction[k].first;
                            nextIndex.second=index.second+direction[k].second;
                            if(nextIndex.first>=0&&nextIndex.first<h
                               &&nextIndex.second>=0&&nextIndex.second<w
                               &&maps[nextIndex.first][nextIndex.second]==1
                               &&!visited[nextIndex.first][nextIndex.second])
                            {
                                visited[nextIndex.first][nextIndex.second]=true;
                                q.push(nextIndex);
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";
        
        //Reset
        cnt=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                visited[i][j]=false;
            }
        }
    }
}

#endif /* _963_h */
