//
//  1707.h
//  BaekJoon
//
//  Created by 정민수 on 30/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _707_h
#define _707_h
#include<iostream>
#include<vector>
using namespace std;
vector<int> v[20001];
int visitedCnt[20001];
bool bBinaryTree=true;

void DFS(int index,int case_num){
    if(visitedCnt[index]==0){
        visitedCnt[index]=case_num;
    }
    for(int i=0;i<v[index].size();i++){
        if(visitedCnt[v[index][i]]==0) {
            DFS(v[index][i],case_num*-1);
        }else if(case_num*-1 != visitedCnt[v[index][i]]){
            bBinaryTree=false;
            return;
        }
    }
}
void solution()
{
    int t;
    int vertex1,vertex2;
    int vertexCnt,edgeCnt;
    cin>>t;
    while(t--)
    {
        cin>>vertexCnt>>edgeCnt;
        for(int i=0;i<edgeCnt;i++)
        {
            cin>>vertex1>>vertex2;
            v[vertex1].push_back(vertex2);
            v[vertex2].push_back(vertex1);
        }
        for(int i=1;i<=vertexCnt;i++)
        {
            if(visitedCnt[i]==0)
            {
                DFS(i,1);
            }
        }
        if(bBinaryTree)  cout<<"YES\n";
        else cout<<"NO\n";
        
        bBinaryTree=true;
        for(int i=0;i<=vertexCnt;i++)
        {
            v[i].clear();
            visitedCnt[i]=0;
        }
    }
}

#endif /* _707_h */
