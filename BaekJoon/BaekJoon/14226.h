//
//  14226.h
//  BaekJoon
//
//  Created by 정민수 on 2020/04/04.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _4226_h
#define _4226_h
#include<iostream>
#include<queue>
using namespace std;
bool visited[1001][1001];
void solution()
{
    int S;
    cin>>S;
    queue<int> emoticons;
    queue<int> clips;
    clips.push(-1);
    emoticons.push(1);
    int sizeCnt=1;
    int time=0;
    while(true)
    {
        int emoticon=emoticons.front();
        int clip=clips.front();
        emoticons.pop();
        clips.pop();
        if(emoticon==S)
        {
            break;
        }
        sizeCnt--;
        //붙여넣기
        if(clip!=-1
           &&emoticon+clip<=1000
           &&!visited[emoticon+clip][clip])
        {
            visited[emoticon+clip][clip]=true;
            emoticons.push(emoticon+clip);
            clips.push(clip);
        }
        //복사하기
        if(clip!=emoticon)
        {
            emoticons.push(emoticon);
            clips.push(emoticon);
        }
        //이모티콘 하나 삭제하기.
        if(emoticon>1
           &&!visited[emoticon-1][clip])
        {
            visited[emoticon-1][clip]=true;
            emoticons.push(emoticon-1);
            clips.push(clip);
        }
        
        if(sizeCnt==0)
        {
            sizeCnt=emoticons.size();
            time++;
        }
        
    }
      cout<<time;
}

#endif /* _4226_h */
