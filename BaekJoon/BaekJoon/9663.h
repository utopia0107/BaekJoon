//
//  9663.h
//  BaekJoon
//
//  Created by 정민수 on 01/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _663_h
#define _663_h
#include<iostream>
#include<vector>
using namespace std;
int queenCnt;
int answerCnt;
vector<pair<int,int>> queenIndexs;
void GetCountPlaceableQueen(int depth)
{
    if(depth==queenCnt)
    {
        answerCnt++;
        return ;
    }
    for(int i=0;i<queenCnt;i++)
    {
        //x,y
        pair<int,int> index=make_pair(depth,i);
        bool check=true;
        for(int j=0;j<queenIndexs.size();j++)
        {
            if(index.second==queenIndexs[j].second//y축이 같은 경우 제외
            ||abs(index.first-queenIndexs[j].first)==abs(index.second-queenIndexs[j].second)
               )
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            queenIndexs.push_back(index);
            GetCountPlaceableQueen(depth+1);
            queenIndexs.pop_back();
        }
    }
}
void solution()
{
    cin>>queenCnt;
    GetCountPlaceableQueen(0);
    cout<<answerCnt;
}

#endif /* _663_h */
