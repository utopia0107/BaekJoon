//
//  9019.h
//  BaekJoon
//
//  Created by 정민수 on 09/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _019_h
#define _019_h
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int origin;
int convers;
bool check[10000];
int D(int num)
{
    return num*2%10000;
}
int S(int num)
{
    if(num==0)
        num=9999;
    else
        num-=1;
    return  num;
}
int L(int num)
{
    if(num==0)return 0;
    int first=num/1000;
    int last=num%1000;

    return last*10+first;
    
}
int R(int num)
{
    if(num==0)return 0;
    int last=num%10;
    return num/10+last*1000;
}
void BFS()
{
    queue<string> q;
    queue<int> num_q;
    q.push("");
    num_q.push(origin);
    
    string op;
    int num;
    int cnt=0;
    while (!q.empty())
    {
        op=q.front();
        num=num_q.front();
        cnt++;
       
        q.pop();
        num_q.pop();
        if(num==convers)
        {
            cout<<op+"\n";
            return;
        }
   
                if(!check[D(num)])
                {
                    check[D(num)]=true;
                    num_q.push(D(num));
                    q.push(op+"D");
                }
      
                if(!check[S(num)])
                {
                    check[S(num)]=true;
                    num_q.push(S(num));
                    q.push(op+"S");
                }
 
                if(!check[L(num)])
                {
                    check[L(num)]=true;
                    num_q.push(L(num));
                    q.push(op+"L");
                };

                if(!check[R(num)])
                {
                    check[R(num)]=true;
                    num_q.push(R(num));
                    q.push(op+"R");
                }
        
        
    }
    
}

void solution() {
    int repeatCnt;
    scanf("%d",&repeatCnt);

    while (repeatCnt--) {
        scanf("%d %d",&origin,&convers);
        BFS();
        memset(check, false, sizeof(check));
      
        
    }

    
}



#endif /* _019_h */
