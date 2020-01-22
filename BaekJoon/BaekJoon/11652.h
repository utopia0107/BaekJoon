//
//  11652.h
//  BaekJoon
//
//  Created by 정민수 on 21/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1652_h
#define _1652_h
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
void soultion()
{
    long long n,num;
    map<long long,int> m;
    cin>>n;
    while(n--)
    {
        cin>>num;
        if(m.find(num)==m.end())
        {
            m.insert(make_pair(num,0));
        }
        m[num]++;
    }
    map<long long,int>::iterator iter;
    pair<long long,int> answer;
    for(iter=m.begin();iter!=m.end();iter++)
    {
        if(answer.second<(*iter).second)
        {
             answer.first=(*iter).first;
             answer.second=(*iter).second;
        }else if(answer.second==(*iter).second
                 &&answer.first>(*iter).first)
        {
            answer.first=(*iter).first;
        }
    }
    cout<<answer.first;
}

#endif /* _1652_h */
