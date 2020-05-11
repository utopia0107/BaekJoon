//
//  11660.h
//  BaekJoon
//
//  Created by 정민수 on 2020/05/11.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _1660_h
#define _1660_h
#include<iostream>
// 1 2 3 4

// 3 5 7 -1
// 6 9 -1
// 10 -1
using namespace std;

void solution()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nums[1025][1025];
    int sums[1025][1025];
    int n,m;
    cin>>n>>m;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)sums[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>nums[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sums[i][j]=sums[i][j-1]+nums[i][j];
        }
    }

    while(m--)
    {
        pair<int,int> start,end;
        cin>>start.first>>start.second>>end.first>>end.second;
        int total=0;
        for(int i=start.first;i<=end.first;i++)
        {
            if(i!=end.first)
            {
                total+=sums[i][end.second] - sums[i][start.second-1];
            }else
            {
                total+=sums[i][end.second] - sums[i][start.second-1];
            }

        }
        cout<<total<<"\n";
    }
}

#endif /* _1660_h */
