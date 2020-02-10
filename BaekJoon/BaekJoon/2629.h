//
//  2629.h
//  BaekJoon
//
//  Created by 정민수 on 10/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _629_h
#define _629_h
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool dp[31][40001]={false,};
vector<int> weights;
vector<int> ansers;
int answer;
void DFS(int index,int weight)
{
    if(index>weights.size()||dp[index][weight])
    {
        return;
    }
    dp[index][weight]=true;
    
    DFS(index+1,weight+weights[index]);
    DFS(index+1,weight);
    DFS(index+1,abs(weight-weights[index]));
  
}

void solution() {
    int i;
    int temp;
    scanf("%d",&i);
    while (i--) {
        scanf(" %d",&temp);
        weights.push_back(temp);
    }
    scanf("%d",&i);
    while (i--) {
        scanf(" %d",&temp);
        ansers.push_back(temp);
    }
    DFS(0,0);
    for(int i=0;i<ansers.size();i++)
    {
       
         dp[weights.size()][ansers[i]]?printf("Y "):printf("N ");
    }


}



#endif /* _629_h */
