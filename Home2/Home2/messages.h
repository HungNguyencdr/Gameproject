#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
using namespace std;
struct messages_box
{
    bool ring;
    vector<string>content;
    messages_box(){};
    void WatchContent()
    {
        for(int i=0;i<content.size();i++)
        {
            cerr<<content[i]<<endl;
        }
    }
};
vector<messages_box> all_messages_box;


#endif // MESSAGES_H_INCLUDED
