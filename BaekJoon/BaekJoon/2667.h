//
//  2667.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/04.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _667_h
#define _667_h
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int map[25][25];
bool visited[25][25];
int dir[4]={-1,0,1,0};
//-1,0
//0,1
//1,0
//0,-1
pair<int,int> Serach(int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j]==1)return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}
void solution()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string str;
        cin>>str; for(int j=0;j<N;j++)
        {
            if(str[j]=='1')
            {
                map[i][j]=1;
            }else
            {
                map[i][j]=0;
            }
        }
    }
    vector<int> cnts;
    while(true)
    {
        queue<pair<int,int>> q;
        q.push(Serach(N));
        if(q.front().first!=-1)
        {
            map[q.front().first][q.front().second]=0;
            int cnt=0;
            while(!q.empty())
            {
                pair<int,int> pos= q.front();
                q.pop();
                cnt++;
                for(int i=0;i<4;i++)
                {
                    pair<int,int> nextPos=make_pair(pos.first+dir[i],pos.second+dir[(i+1)%4]);
                    if(nextPos.first>=0&&nextPos.second>=0&&nextPos.first<N&&nextPos.second<N
                       &&map[nextPos.first][nextPos.second]==1)
                    {
                        map[nextPos.first][nextPos.second]=0;
                        q.push(nextPos);
                    }
                }
            }
            cnts.push_back(cnt);
        }else break;
    }
    sort(cnts.begin(),cnts.end());
    cout<<cnts.size()<<"\n";
    for(int i=0;i<cnts.size();i++)
    {
        cout<<cnts[i]<<"\n";
    }
}
#endif /* _667_h */
