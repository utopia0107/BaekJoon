//
//  ROT13.h
//  BaekJoon
//
//  Created by 정민수 on 17/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef ROT13_h
#define ROT13_h
#include<iostream>
#include <string>
using namespace std;
void soultion()
{
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]=(str[i]-'a'+13)%26+'a';
        }else if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=(str[i]-'A'+13)%26+'A';
        }
    }
    cout<<str;
}

#endif /* ROT13_h */
