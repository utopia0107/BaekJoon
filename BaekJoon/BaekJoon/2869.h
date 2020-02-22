//
//  2869.h
//  BaekJoon
//
//  Created by 정민수 on 22/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _869_h
#define _869_h
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solution()
{
    int up,down,hight,cur_h=0,day=0;
    int left=0,right=0,Min=1000000000+1;
    cin>>up>>down>>hight;
    right=hight/(up-down)+1;

    while (left<=right)
    {
        //중앙값
        day=(left+right)/2;
        cur_h=day*(up-down)+up;
        if(hight<=cur_h)
        {
            Min = min(Min,day+1);
            right=day-1;
        }
        else
        {
            left=day+1;
        }
    }
    cout<<Min;
}



#endif /* _869_h */
