//
//  MinMax.h
//  BaekJoon
//
//  Created by 정민수 on 17/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef MinMax_h
#define MinMax_h
#include<iostream>
using namespace std;
void soultion()
{
    int min=1000000,max=-1000000;
    int n;
    cin>>n;
    int num;
    while(n--)
    {
        cin>>num;
        if(min>num)min=num;
        if(max<num)max=num;
    }
    cout<<min<<" "<<max;
}

#endif /* MinMax_h */
