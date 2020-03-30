//
//  14500.h
//  BaekJoon
//
//  Created by 정민수 on 07/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4500_h
#define _4500_h
#include<iostream>
using namespace std;
int tileMap[500][500];
bool visiteds[500][500];
int answer=0;
int w,h;
void DFS(int x,int y, int total, int depth)
{
    if(depth==4)
    {
        answer=max(answer,total);
        return;
    }
    //상
    if(y>0
       &&!visiteds[y-1][x])
    {
        visiteds[y-1][x]=true;
        DFS(x,y-1,total+tileMap[y-1][x],depth+1);
        visiteds[y-1][x]=false;
    }
    //하
    if(y<h-1
       &&!visiteds[y+1][x])
    {
        visiteds[y+1][x]=true;
        DFS(x,y+1,total+tileMap[y+1][x],depth+1);
        visiteds[y+1][x]=false;
    }
    //좌
    if(x>0
       &&!visiteds[y][x-1])
    {
        visiteds[y][x-1]=true;
        DFS(x-1,y,total+tileMap[y][x-1],depth+1);
        visiteds[y][x-1]=false;
    }
    //우
    if(x<w-1
       &&!visiteds[y][x+1])
    {
        visiteds[y][x+1]=true;
        DFS(x+1,y,total+tileMap[y][x+1],depth+1);
        visiteds[y][x+1]=false;
    }
}
void solution()
{
    cin>>h>>w;
    
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            cin>>tileMap[y][x];
            visiteds[y][x]=false;
        }
    }
    
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            visiteds[y][x]=true;
            DFS(x,y,tileMap[y][x],1);
            visiteds[y][x]=false;

            //ㅗ
            if(x>0 && x<w-1 && y>0)
            {
                answer=max(answer,tileMap[y][x]+tileMap[y][x-1]+tileMap[y][x+1]+tileMap[y-1][x]);
            }
            //ㅜ
            if(x>0 && x<w-1 && y<h-1)
            {
                answer=max(answer,tileMap[y][x]+tileMap[y][x-1]+tileMap[y][x+1]+tileMap[y+1][x]);
            }
            //ㅏ
            if(y>0 && y<h-1 && x < w-1)
            {
                
                answer=max(answer,tileMap[y][x]+tileMap[y-1][x]+tileMap[y+1][x]+tileMap[y][x+1]);
            }
            //ㅓ
            if(y>0 && y<h-1 && x>0)
            {
                answer=max(answer,tileMap[y][x]+tileMap[y-1][x]+tileMap[y+1][x]+tileMap[y][x-1]);
            }
        }
    }
    
    cout<<answer;
}

/*
 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include<stack>
 using namespace std;
 int sizeX,sizeY;
 bool check[500][500];
 int data[500][500];
 int Max=0,depth=0,total=0;
 int cased[4]={1,0,-1,0};
 
 void DFS(int x,int y)
 {
 
 
 if(depth==4)
 {
 Max=max(Max,total);
 return;
 }
 for(int i=0;i<4;i++)
 {
 int temp_x=x+cased[i];
 int temp_y=y+cased[(i+1)%4];
 if(temp_x>=0&&temp_x<sizeX&&temp_y>=0&&temp_y<sizeY&&!check[temp_x][temp_y])
 {
 check[x][y]=true;
 total+=data[x][y];
 depth+=1;
 DFS(temp_x,temp_y);
 check[x][y]=false;
 depth--;
 total-=data[x][y];
 }
 }
 
 
 }
 void NotDFS(int x,int y)
 {
 int sum=0;
 int Min=1001;
 int cnt=0;
 for(int i=0;i<4;i++)
 {
 int temp_x=x+cased[i];
 int temp_y=y+cased[(i+1)%4];
 if(temp_x>=0&&temp_x<sizeX&&temp_y>=0&&temp_y<sizeY)
 {
 cnt++;
 Min=min(Min,data[temp_x][temp_y]);
 sum+=data[temp_x][temp_y];
 }
 }
 if(cnt==4)
 {
 Max=max(Max,sum+data[x][y]-Min);
 }
 if(cnt==3)
 {
 Max=max(Max,sum+data[x][y]);
 }
 }
 void solution() {
 scanf("%d %d",&sizeX,&sizeY);
 for(int i=0;i<sizeX;i++)
 {
 for(int j=0;j<sizeY;j++)
 {
 scanf(" %d",&data[i][j]);
 }
 }
 
 for(int i=0;i<sizeX;i++)
 {
 for(int j=0;j<sizeY;j++)
 {
 DFS(i,j);
 NotDFS(i, j);
 }
 }
 printf("%d",Max);
 
 }
 */


#endif /* _4500_h */
