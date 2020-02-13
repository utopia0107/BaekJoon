//
//  2661.h
//  BaekJoon
//
//  Created by 정민수 on 13/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _661_h
#define _661_h
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int data[80]={0,};

int num;
bool IsSame(int index)
{
    for (int i=1; i<=index/2; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (data[(index -1) - j] == data[(index - 1) - j - i])  {cnt++;}
        }
        if (cnt == i) {return true;}
    }
    return false;
}
void DFS(int index)
{
    if(IsSame(index))
    {
        return;
    }
    
    if(index==num)
    {
        for(int i=0;i<num;i++)
            printf("%d",data[i]);
        exit(0);
    }
  
    for(int i=1;i<4;i++)
    {
        data[index]=i;
        DFS(index+1);
    }
}

void solution()
{
    scanf("%d",&num);
    DFS(0);
}



#endif /* _661_h */
