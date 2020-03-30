//
//  9095.h
//  BaekJoon
//
//  Created by 정민수 on 2020/03/30.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _095_h
#define _095_h
#include<iostream>
using namespace std;
int DFS(int n)
{
    if(n==0){return 1;}
    if(n<0){return 0;}
    
    return DFS(n-1)+DFS(n-2)+DFS(n-3);
    
}
void solution()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<DFS(n)<<"\n";
        
    }
    
}

#endif /* _095_h */
