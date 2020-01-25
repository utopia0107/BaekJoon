//
//  11047.h
//  BaekJoon
//
//  Created by 정민수 on 25/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1047_h
#define _1047_h
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solution()
{
    int coinTypeCnt, price;
    cin>>coinTypeCnt>>price;
    vector<int> coins;
    coins.resize(coinTypeCnt);
    for(int i=0;i<coinTypeCnt;i++)
    {
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end(),greater<int>());
    int coinCnt=0,index=0;
    while(price!=0)
    {
        if(price>=coins[index])
        {
            coinCnt+=price/coins[index];
            price%=coins[index];
        }
        index++;
    }
    cout<<coinCnt;
}

#endif /* _1047_h */
