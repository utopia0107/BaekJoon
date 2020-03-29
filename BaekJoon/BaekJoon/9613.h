//
//  9613.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _613_h
#define _613_h
#include<iostream>
#include<vector>
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
    cin>>t;
    while (t--) {
        int n;
        long long sum=0;
        cin>>n;
        vector<int> v;
        v.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                sum+=gcd(v[i],v[j]);
            }
        }
        cout<<sum<<"\n";
    }
}

#endif /* _613_h */
