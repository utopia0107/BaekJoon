//
//  3047.h
//  BaekJoon
//
//  Created by 정민수 on 23/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _047_h
#define _047_h
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
void soultion()
{
    vector<int> v;
    string str;
    v.resize(3);
    for(int i=0;i<3;i++)
    {
        cin>>v[i];
    }
    cin>>str;
    sort(v.begin(),v.end());
    map<char,int>map;
    for(int i=0;i<3;i++){
        map.insert(make_pair('A'+i,v[i]));
    }
    for(int i=0;i<3;i++)
    {
        cout<<map[str[i]]<<" ";
    }
}
#endif /* _047_h */
