//
//  2178.h
//  BaekJoon
//
//  Created by 정민수 on 24/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _178_h
#define _178_h
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int visited[100][100];
//상,하,좌,우
const int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void soultion()
{
    vector<vector<int>> maps;
    int height,width;
    
    cin>>height>>width;
    maps.resize(height);
    for(int i=0;i<height;i++)
    {
        string str;
        cin>>str;
        maps[i].resize(width);
        for(int j=0;j<width;j++)
        {
            maps[i][j]= str[j]=='1'?1:0;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    int depth=1;
    int queueSize=1;
    visited[0][0]=true;
    while(!q.empty())
    {
        pair<int,int> index=q.front();
        q.pop();
        queueSize--;
        if(index.first==height-1&&index.second==width-1)break;
        
        for(int i=0;i<4;i++)
        {
            pair<int,int> nextIndex;
            nextIndex.first= direction[i][0]+index.first;
            nextIndex.second= direction[i][1]+index.second;
            if(nextIndex.first>=0&&nextIndex.first<height
               &&nextIndex.second>=0&&nextIndex.second<width
               &&maps[nextIndex.first][nextIndex.second]==1
               &&!visited[nextIndex.first][nextIndex.second])
            {
                visited[nextIndex.first][nextIndex.second]=true;
                q.push(nextIndex);
                
            }
        }
        
        if(queueSize==0)
        {
            queueSize=q.size();
            depth++;
        }
    }
    cout<<depth;
}


#endif /* _178_h */
