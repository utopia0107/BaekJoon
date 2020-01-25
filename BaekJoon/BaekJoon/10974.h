//
//  10974.h
//  BaekJoon
//
//  Created by 정민수 on 25/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _0974_h
#define _0974_h
#include<iostream>
#include<vector>
using namespace std;
bool visited[9];
vector<int> path;
int size;
void PrintAllpermutations()
{
    if(path.size()==size)
    {
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<size;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            path.push_back(i+1);
            PrintAllpermutations();
            path.erase(path.end()-1);
            visited[i]=false;
        }
    }
}

void solution()
{
    int n;
    cin>>n;
    size=n;
    PrintAllpermutations();
}

#endif /* _0974_h */
