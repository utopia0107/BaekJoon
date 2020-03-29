//
//  2609.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _609_h
#define _609_h
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    int n=0;
    if(a<b){
        a+=b;
        b=a-b;
        a-=b;
    }
    while(b!=0)
    {
        n=a%b;
        a=b;
        b=n;
    }
    return a;
}
void solution()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n"<<a*b/gcd(a,b);
    
}

#endif /* _609_h */
