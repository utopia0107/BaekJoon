//
//  2007.h
//  BaekJoon
//
//  Created by 정민수 on 17/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _007_h
#define _007_h
#include<iostream>
using namespace std;
string days[]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
void soultion()
{
    int month,day;
    int total=0;
    cin>>month>>day;
    for(int i=0;i<month-1;i++)
    {
        total+=months[i];
    }
    cout<<days[(total+day)%7];
    
}

#endif /* _007_h */
