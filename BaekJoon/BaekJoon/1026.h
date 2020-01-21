//
//  1026.h
//  BaekJoon
//
//  Created by 정민수 on 21/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _026_h
#define _026_h
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void soultion()
{
    int size;
    cin>>size;
    vector<int> nums1,nums2;
    nums1.resize(size);
    nums2.resize(size);
    for(int i=0;i<size;i++)
    {
        cin>>nums1[i];
    }
    for(int i=0;i<size;i++)
    {
        cin>>nums2[i];
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end(),greater<int>());
    int minTotal=0;
    for(int i=0;i<size;i++)
    {
        minTotal+=nums1[i]*nums2[i];
    }
    cout<<minTotal;
}

#endif /* _026_h */
