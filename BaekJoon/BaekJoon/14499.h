//
//  14499.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/02.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4499_h
#define _4499_h
#include<iostream>
using namespace std;
int map[20][20];
//left,right;
int dice[4][3];

void solution()
{
    int M,N;
    int x,y;
    int k;
    cin>>N>>M>>y>>x>>k;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
        }
    }
    while (k--) {
        int op;
        bool isMove=false;
        cin>>op;
        switch (op) {
                //Right
            case 1:
                if(x<M-1)
                {
                    int temp=dice[1][0];
                    dice[1][0]=dice[3][1];
                    dice[3][1]=dice[1][2];
                    dice[1][2]=dice[1][1];
                    dice[1][1]=temp;
                    x+=1;
                    isMove=true;
                    if(map[y][x]==0)
                    {
                        map[y][x]=dice[3][1];
                    }else
                    {
                        dice[3][1]=map[y][x];
                        map[y][x]=0;
                    }
                }
                break;
                //Left
            case 2:
                if(x>0)
                {
                    
                    int temp=dice[1][0];
                    dice[1][0]=dice[1][1];
                    dice[1][1]=dice[1][2];
                    dice[1][2]=dice[3][1];
                    dice[3][1]=temp;
                    x-=1;
                    isMove=true;
                    if(map[y][x]==0)
                    {
                        map[y][x]=dice[3][1];
                    }else
                    {
                        dice[3][1]=map[y][x];
                        map[y][x]=0;
                    }
                }
                break;
                //Up
            case 3:
                if(y>0)
                {
                    int temp=dice[0][1];
                    for(int i=0;i<3;i++)
                    {
                        dice[i][1]=dice[i+1][1];
                    }
                    dice[3][1]=temp;
                    y-=1;
                    isMove=true;
                    if(map[y][x]==0)
                    {
                        map[y][x]=dice[3][1];
                    }else
                    {
                        dice[3][1]=map[y][x];
                        map[y][x]=0;
                    }
                }
                break;
                //Down
            case 4:
                if(y<N-1)
                {
                    int temp=dice[3][1];
                    for(int i=3;i>0;i--)
                    {
                        dice[i][1]=dice[i-1][1];
                    }
                    dice[0][1]=temp;
                    y+=1;
                    isMove=true;
                    if(map[y][x]==0)
                    {
                        map[y][x]=dice[3][1];
                    }else
                    {
                        dice[3][1]=map[y][x];
                        map[y][x]=0;
                    }
                }
                break;
        }
        if(isMove)cout<<dice[1][1]<<"\n";
    }
}

#endif /* _4499_h */
