//
//  6588.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _588_h
#define _588_h
#include<iostream>
#include<vector>
using namespace std;

bool visited[1000001];
bool checks[1000001];
vector<int>v;

void solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=2;i<=1000000;i++)
       {
           if(!visited[i])
           {
               v.push_back(i);
               checks[i]=true;
               for(int j=i;j<=1000000;j+=i)
               {
                   visited[j]=true;
               }
           }
       }
    int lenght=v.size();
    while (true)
    {
        int  num=0;
        bool isAnswer=false;
        cin>>num;
        if(num==0)break;
        for(int i=0;i<lenght;i++)
        {
            if(v[i]>num/2)break;
            if(checks[num-v[i]])
            {
                cout<<num<<" = "<<v[i]<<" + "<<num-v[i]<<"\n";
                isAnswer=true;
                break;
            }
        }
        if(!isAnswer)
        {
            cout<<"Goldbach's conjecture is wrong.";
        }
    }
}

#endif /* _588_h */
