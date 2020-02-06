//
//  1759.h
//  BaekJoon
//
//  Created by 정민수 on 06/02/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _759_h
#define _759_h
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check[16]; // 버튼이 망가져 있으면 true, 아니면 false
vector<char> data;
char consonants[]={'a','e','i','o','u'};
 int L,C;
char str[16];
bool CheckConsonant(char abc)
{
    for(int i=0;i<5;i++)
    {
        if(abc==consonants[i])
            return true;
    }
    return false;
}
void permutation(int pre_index,int cnt,int consonant,int vowel)
{
    if(cnt==L)
    {
        if(consonant>=1&&vowel>=2)
        printf("%s\n",str);
        return;
    }
    for(int i=0;i<data.size();i++)
    {
        if(check[i]==false&&i>pre_index)
        {
            check[i]=true;
            CheckConsonant(data[i])?consonant++:vowel++;
            str[cnt]=data[i];
            permutation(i,cnt+1,consonant,vowel);
            CheckConsonant(data[i])?consonant--:vowel--;
            check[i]=false;
        }
    }
 
    
}
void solution() {
   
    char temp;
    scanf("%d %d",&L,&C);
    
    for(int i=0;i<C;i++)
    {
        scanf(" %c",&temp);
        data.push_back(temp);
    }
    sort(data.begin(),data.end());
 
    permutation(-1,0,0,0);
}



#endif /* _759_h */
