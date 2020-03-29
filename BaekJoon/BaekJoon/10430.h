//
//  10430.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _0430_h
#define _0430_h
#include<iostream>
using namespace std;

void solution()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a+b)%c<<"\n"<<((a%c)+(b%c))%c<<"\n"<<(a*b)%c<<"\n"<<((a%c)*(b%c))%c;
    
}
#endif /* _0430_h */
