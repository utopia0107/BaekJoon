//
//  2805.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/27.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _805_h
#define _805_h
#include<iostream>
#include<vector>
using namespace std;
void solution()
{
     ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> tree;
    tree.resize(N);
    int maxH=0;
    for(int i=0;i<N;i++)
    {
        cin>>tree[i];
       maxH=max(maxH,tree[i]);
    }
    int start=0,end=maxH;
    while(start<end)
    {
        int mid=(start+end)/2;
        long long length=0;
        for(int i=0;i<N;i++)
        {
            if(tree[i]>mid)length+=tree[i]-mid;
        }
        //자른 나무가 가져가야할 나무 보다 많을떄
        if(length>=M)
        {
            start=mid;
        }
        //자른 나무가 가져가야할 나무 보다 적을때
        else if(length<M)
        {
            //end의 수치를 내려야한다.
            //언제까지? length>=M일때 까지...
            end=mid;
        }
        if(mid==(start+end)/2)break;
    }
    cout<<start;
}

#endif /* _805_h */
