//
//  Make_1 .h
//  BaekJoon
//
//  Created by 정민수 on 15/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Make_1__h
#define Make_1__h
#include<iostream>
using namespace std;
int counters[1000001];
const int INF=2147438647;
void MakeOne(int num,int cnt)
{
    counters[num]=min(counters[num],cnt);
    if(num==1||counters[num]!=cnt){
        return;
    }
    if(num%3==0)
    {
        MakeOne(num/3,cnt+1);
    }
    if(num%2==0)
    {
        MakeOne(num/2,cnt+1);
    }
     MakeOne(num-1,cnt+1);
        
}
void soultion()
{
    int num;
    for(int i=0;i<1000001;i++)
    {
        counters[i]=INF;
    }
    cin>>num;
    MakeOne(num,0);
    cout<<counters[1];
    
}

#endif /* Make_1__h */
