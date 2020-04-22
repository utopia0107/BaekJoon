//
//  16194.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/22.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _6194_h
#define _6194_h
#include<iostream>
using namespace std;
int N;
int num[1001];
void solution()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            num[i]=min(num[i],num[i-j]+num[j]);
        }
    }
    cout<<num[N];
}

#endif /* _6194_h */
