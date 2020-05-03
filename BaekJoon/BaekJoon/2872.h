//
//  2872.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/29.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _872_h
#define _872_h
#include<iostream>
#include<algorithm>
using  namespace std;
int books[300000];
void solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>books[i];
    }
    int cnt=N;
    for (int i = N - 1; i >= 0; i--)
    {
        if (books[i] == cnt)
        {
            cnt--;
        }
    }
    cout<<cnt;
}


#endif /* _872_h */
