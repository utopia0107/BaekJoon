//
//  1991.h
//  BaekJoon
//
//  Created by 정민수 on 22/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _991_h
#define _991_h
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const string Alphabets="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//left,right
vector<pair<int,int>> nodeEdges;
void GetPreorderPath(char node,string* path)
{
    (*path)+=(Alphabets[node]);
    if(nodeEdges[node].first!=-1)GetPreorderPath(nodeEdges[node].first,path);
    if(nodeEdges[node].second!=-1)GetPreorderPath(nodeEdges[node].second,path);
}
void GetInorderPath(char node,string* path)
{
    if(nodeEdges[node].first!=-1)
    {
        GetInorderPath(nodeEdges[node].first,path);
    }
    (*path)+=(Alphabets[node]);
    if(nodeEdges[node].second!=-1)
    {
        GetInorderPath(nodeEdges[node].second,path);
    }
    return ;
}
void GetPostorderPath(char node,string* path)
{
    if(nodeEdges[node].first!=-1)GetPostorderPath(nodeEdges[node].first,path);
    if(nodeEdges[node].second!=-1)GetPostorderPath(nodeEdges[node].second,path);
    (*path)+=(Alphabets[node]);
}

void soultion()
{
    int n;
    cin>>n;
    nodeEdges.resize(n);
    char parent,child1,child2;
    for(int i=0;i<n;i++)
    {
        cin>>parent>>child1>>child2;
        nodeEdges[parent-'A'].first=child1=='.'?-1:(child1-'A');
        nodeEdges[parent-'A'].second=child2=='.'?-1:(child2-'A');
    }

    string path="";
    GetPreorderPath(0,&path);
    cout<<path<<"\n";

    path="";
    GetInorderPath(0,&path);
    cout<<path<<"\n";

    path="";
    GetPostorderPath(0,&path);
    cout<<path<<"\n";
}

#endif /* _991_h */
