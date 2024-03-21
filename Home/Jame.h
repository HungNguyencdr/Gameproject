#ifndef JAME_H_INCLUDED
#define JAME_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "CT_IN4.h"
using namespace std;
CT_IN4 Jame;
    Jame.walking_Frame_I=0;
    Jame.frame=8;
    Jame.Walk_Right="image\\Jame\\Jame_Move_Right.png";
    Jame.Walk_Left="image\\Jame\\Jame_Move_Left.png";
    const Jame_Standing="image\\Jame\\Jame_2.png";

int JameRect[][4]={
    {0,0,122,272},
    {122,0,122,272},
    {244,0,122,272},
    {366,0,122,272},
    {488,0,122,272},
    {610,0,122,272},
    {732,0,122,272},
    {854,0,122,272},
}


#endif // JAME_H_INCLUDED
