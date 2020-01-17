//
//  Bracket.h
//  BaekJoon
//
//  Created by 정민수 on 17/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Bracket_h
#define Bracket_h
#include<iostream>
using namespace std;
void soultion()
{
    int n;
    cin>>n;
    while(n--)
    {
        string barket;
        cin>>barket;
        int cnt=0, size=barket.size();
        int i;
        for(i=0;i<size;i++)
        {
            if(barket[i]=='(')
            {
                cnt++;
            }else{
                cnt--;
                if(cnt<0)
                {
                    cout<<"NO\n";
                    break;
                }
            }
        }
        if(i==size)
        {
            if(cnt==0)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

#endif /* Bracket_h */
