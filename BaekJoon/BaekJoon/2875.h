//
//  2875.h
//  BaekJoon
//
//  Created by 정민수 on 27/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _875_h
#define _875_h
#include<iostream>
using namespace std;

void solution()
{
    int n,m,k;
    cin>>n>>m>>k;
    while(k>0)
    {
        k--;
        if(n>=m*2)
        {
            n--;
        }
        else{
            m--;
        }
    }
    cout<<min(n/2,m);
}

#endif /* _875_h */
