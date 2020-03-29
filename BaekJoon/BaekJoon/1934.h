//
//  1934.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _934_h
#define _934_h
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
    int t;
    int a,b;
    cin>>t;
    while (t--) {
        cin>>a>>b;
        cout<<a*b/gcd(a,b)<<"\n";
    }
}

#endif /* _934_h */
