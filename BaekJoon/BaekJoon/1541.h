//
//  1541.h
//  BaekJoon
//
//  Created by 정민수 on 28/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _541_h
#define _541_h
#include <iostream>
#include <string>
using namespace std;

void solution()
{
    string str;
    string temp="";
    bool bMinuse=false;
    int total=0;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='+')
        {
            total+= bMinuse?-stoi(temp):stoi(temp);
            temp.clear();
        }
        else if(str[i]=='-')
        {
            total+= bMinuse?-stoi(temp):stoi(temp);
            temp.clear();
            bMinuse=true;
           

        }
        //숫자인 경우
        else{
            temp+=str[i];
        }
    }
    total+= bMinuse?-stoi(temp):stoi(temp);
    cout<<total;
}

#endif /* _541_h */
