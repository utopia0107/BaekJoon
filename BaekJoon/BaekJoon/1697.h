//
//  1697.h
//  BaekJoon
//
//  Created by 정민수 on 23/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _697_h
#define _697_h
#include<iostream>
#include<queue>
using namespace std;
bool visited[100001];
const int MAX=100001;
int BFS(int start,int end)
{
    int time=0;
    int queueCnt=1;

    queue<int> q;
        visited[start]=true;
        q.push(start);
   
        while(!q.empty())
        {
            int position=q.front();
            q.pop();
            queueCnt--;
            if(position==end)
            {
                return time;
            }
            int num=position*2;
            if(num<MAX&&!visited[num])
            {
                q.push(num);
                visited[num]=true;
            }
            num=position+1;
            if(num<MAX&&!visited[num])
            {
                q.push(num);
                visited[num]=true;
            }
            num=position-1;
            if(num>=0&&!visited[num])
            {
                 q.push(num);
                visited[num]=true;
            }
            if(queueCnt==0)
            {
                queueCnt=q.size();
                time++;
            }
        }
    return time;
}
void soultion()
{
    int start, end;
    int time=0;
    cin>>start>>end;
    queue<int> q;
    visited[start]=true;
    q.push(start);
    if(start<end)
    {
        time=BFS(start,end);
    }else{
        time=start-end;
    }
    cout<<time;

}

#endif /* _697_h */
