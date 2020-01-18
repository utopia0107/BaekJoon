//
//  BaseConversion2 .h
//  BaekJoon
//
//  Created by 정민수 on 18/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef BaseConversion2__h
#define BaseConversion2__h
#include<iostream>
#include<algorithm>
using namespace std;
void soultion()
{
    int num,base;
    cin>>num>>base;
    string str="";
    while(num>0)
    {
        str+=(num%base<10?num%base+'0':'A'+num%base-10);
        num/=base;
    }
    reverse(str.begin(),str.end());
    cout<<str;
}

#endif /* BaseConversion2__h */
