#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "objects.h"
#include <vector>

vector<objects> inventory;
void Receive_Object(objects &a){inventory.push_back(a);}
bool Find_Object(objects &a)
{
    for(int i=0;i<inventory.size();i++)
        {
            if(inventory[i].object_code==a.object_code){return 1;}
        }
        return 0;
}


#endif // INVENTORY_H_INCLUDED
