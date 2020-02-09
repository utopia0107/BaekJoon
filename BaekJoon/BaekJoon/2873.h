//
//  2873.h
//  BaekJoon
//
//  Created by 정민수 on 02/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//
//킵....
#ifndef _873_h
#define _873_h
#include<iostream>
#include<vector>
using namespace std;
int width,height;
bool visisted[1000][1000];
int pleasureAmount=0;

//상,하,좌,우
int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int maps[1000][1000];
string directionWords[4]={"U","D","L","R"};
string PATH;
void DFS(int x,int y,string preDirection)
{
    PATH+=preDirection;
    visisted[y][x]=true;
    cout<<y<<","<<x<<"\n";
    if(preDirection.compare("U")==0)
    {
        
        if(x+direction[2][1]>=0&&!visisted[y][x+direction[2][1]]) DFS(x+direction[2][1],y,"L");
        else if(x+direction[3][1]<width && !visisted[y][x+direction[3][1]]) DFS(x+direction[3][1],y,"R");
        else if(y+direction[0][0]>=0 && !visisted[y+direction[0][0]][x]) DFS(x,y+direction[0][0],"U");
        
    }
    else if(preDirection.compare("D")==0)
    {
     
        if(x+direction[2][1]>=0&&!visisted[y][x+direction[2][1]]) DFS(x+direction[2][1],y,"L");
        else if(x+direction[3][1]<width && !visisted[y][x+direction[3][1]]) DFS(x+direction[3][1],y,"R");
        else if(y+direction[1][0]<height && !visisted[y+direction[1][0]][x]) DFS(x,y+direction[1][0],"D");

    }else if(preDirection.compare("L")==0)
    {
        if(x+direction[2][1]>=0&&!visisted[y][x+direction[2][1]])
        {
            if(!visisted[y][x+direction[2][1]])DFS(x+direction[2][1],y,"L");
        }
        else
        {
            if(y+direction[1][0]>=0)
            {
                if(!visisted[y+direction[0][0]][x])DFS(x,y+direction[0][0],"U");
            }else if(y+direction[1][0]<height)
            {
                if(!visisted[y+direction[1][0]][x])DFS(x,y+direction[1][0],"D");
            }
        }
        
    }else if(preDirection.compare("R")==0)
    {
        if(x+direction[3][1]<width&&!visisted[y][x+direction[3][1]])
        {
            DFS(x+direction[3][1],y,"R");
        }
        else 
        {
            if(y+direction[0][0]>=0)
            {
                if(!visisted[y+direction[0][0]][x]) DFS(x,y+direction[0][0],"U");
            }else if(y+direction[1][0]<height)
            {
                if(!visisted[y+direction[1][0]][x])DFS(x,y+direction[1][0],"D");
            }
        }
    }
}
void solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>height>>width;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            cin>>maps[i][j];
        }
    }
    //짝짝
    if(width%2==0&&height%2==0)
    {
        pair<int,int> index=make_pair(1, 1);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(i%2==0)
                {
                    if(j%2!=0)
                    {
                        if(maps[index.first][index.second]>maps[i][j])
                        {
                            index.first=i;
                            index.second=j;
                        }
                    }
                }
                else
                {
                    if(j%2==0)
                    {
                        if(maps[index.first][index.second]>maps[i][j])
                        {
                            index.first=i;
                            index.second=j;
                        }
                    }
                }
            }
        }
        visisted[0][0]=true;
        cout<<index.first<<","<<index.second<<"\n";
        visisted[index.first][index.second]=true;
        DFS(0,0,"R");
    }
    else if(width%2!=0&&height%2==0)
    {
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height-1;j++)
            {
                PATH+=i%2==0?"D":"U";
            }
            if(i+1!=width)PATH+="R";
        }
    }
    //홀
    else if(height%2!=0)
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width-1;j++)
            {
                PATH+=i%2==0?"R":"L";
            }
            if(i+1!=height)PATH+="D";
        }
    }

    cout<<PATH<<"\n";
}

#endif /* _873_h */
