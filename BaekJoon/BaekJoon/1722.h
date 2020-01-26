//
//  1722.h
//  BaekJoon
//
//  Created by 정민수 on 25/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _722_h
#define _722_h
#include<iostream>
#include<vector>
using namespace std;
long long GetFactorial(int n)
{
    long long total=1;
    for(int i=2;i<=n;i++)
    {
        total*=i;
    }
    return total;
}
vector<int> GetPermutation(long long k, int size)
{
    vector<int> nums;
    for(int i=1;i<=size;i++)
    {
        nums.push_back(i);
    }
    vector<int> path;
    for(int i=size;i>0;i--)
    {
        long long total=GetFactorial(i-1);
        for(int j=1;j<=i;j++)
        {
            if(j*total>=k)
            {
                k-=(j-1)*total;
                path.push_back(nums[j-1]);
                nums.erase(nums.begin()+j-1);
                break;
            }
        }
    }
    return path;
}
int GetPermutationSequence(vector<int> permutation)
{
    int k=1;
    while(permutation.size()>0)
    {
        int sequence=0;
        for(int i=1;i<permutation.size();i++)
        {
            if(permutation[i]<permutation[0])sequence++;
        }
        long long num=GetFactorial(permutation.size()-1);
        k+=sequence*num;
        permutation.erase(permutation.begin());
    }
    return k;
}
void solution()
{
    int num,op;
    vector<int> path;

    cin>>num;
    cin>>op;
    switch (op) {
        case 1:
            long long k;
            cin>>k;
            path=GetPermutation(k,num);
            for(int i=0;i<path.size();i++)
            {
                cout<<path[i]<<" ";
            }
            break;
        case 2:
            vector<int> permutation;
            permutation.resize(num);
            for(int i=0;i<num;i++)
            {
                cin>>permutation[i];
            }
            cout<<GetPermutationSequence(permutation);
            break;
    }
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>data;
int num;
void FindeNumPer(long long order)
{
    long long digits=1;
    order-=1;
    for(int i=1;i<=num;i++)
    {
        data.push_back(i);
    }
    for(int i=1;i<num;i++)
    {
        digits*=i;
    }
    for(int i=num-1,j=1;i>=0;i--,j++)
    {
        long long cnt=order/digits;
        order=order-digits*cnt;
        
        printf("%d ",data[0+cnt]);
        if(i!=0)
        {
            data.erase(data.begin()+cnt);
            digits/=i;
        }
    }
    
    
    
   
    
}
void FindPerNum()
{
    long long total=1,sum=1;
    int cnt,k=0;
    for(int i=num-1;i>=0;i--,k++)
    {
        if(total==0)
            total=1;
        total=total*k;
        cnt=0;
        for(int j=i;j<num;j++)
        {
            if(data[i]>data[j])
            {
                //printf("%d %d\n",data[j],total);
                ++cnt;
            }
        }
        
        sum+=cnt*total;
    }
    printf("%lld",sum);
}
void solution()
{
    
    int op,temp=0,per=0;
    long long order;
    scanf("%d",&num);
    scanf("%d",&op);
    if(op==1)
    {
        scanf(" %lld",&order);
        FindeNumPer(order);
    }
    if(op==2)
    {
    for(int i=0;i<num;i++)
    {
        scanf(" %d",&temp);
        data.push_back(temp);
        
    }
        FindPerNum();
    }

   
}
 */
#endif /* _722_h */
