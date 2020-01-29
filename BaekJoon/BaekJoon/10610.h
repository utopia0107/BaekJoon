//
//  10610.h
//  BaekJoon
//
//  Created by 정민수 on 29/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _0610_h
#define _0610_h
#include<iostream>
using namespace std;
int numCnt[10];
void solution()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
       numCnt[str[i]-'0']++;
    }
    if(numCnt[0]==0)
    {
        cout<<"-1";
    }else{
        int total=0;
        for(int i=9;i>=0;i--)
        {
            int cnt=numCnt[i];
            while (cnt!=0) {
                cnt--;
                total=total*10+i;
                total%=3;
            }
        }
        if(total==0)
        {
            for(int i=9;i>=0;i--)
            {
                  while (numCnt[i]!=0) {
                      numCnt[i]--;
                      cout<<i;
                  }
            }
        }
        else{
             cout<<"-1";
        }
    }
    
}
#endif /* _0610_h */
