//
//  Combination0Count .h
//  BaekJoon
//
//  Created by 정민수 on 17/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Combination0Count__h
#define Combination0Count__h
#include<iostream>
using namespace std;

int GetCountDivisor(long long num,int divisor)
{
    int cnt=0;
    for(long long i=divisor;i<=num;i*=divisor)
    {
        cnt+=num/i;
    }
    return cnt;
}
void soultion()
{
    long long a,b;
    cin>>a>>b;
    cout<<min(GetCountDivisor(a,5)-GetCountDivisor(a-b,5)-GetCountDivisor(b,5)
              ,GetCountDivisor(a,2)-GetCountDivisor(a-b,2)-GetCountDivisor(b,2));
}

#endif /* Combination0Count__h */
