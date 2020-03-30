//
//  1476.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/30.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _476_h
#define _476_h
#include<iostream>
using namespace std;
void solution()
{
    int cnt=0,s,e,m;
    int S=0,E=0,M=0;
    cin>>e>>s>>m;
    while(S!=s||E!=e||M!=m)
    {
        E=E%15+1;
        S=S%28+1;
        M=M%19+1;
        cnt++;
    }
    cout<<cnt;
}

#endif /* _476_h */
