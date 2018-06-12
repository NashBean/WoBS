/
//  main.cpp
//  Bot_Soccer_Game
//
//  Created by nash on 5/16/16.
//  Copyright 2016 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include "iBS_SoccerBot.h"

void GameLoop();
    
int main (int argc, const char * argv[])
{
    
    GameLoop();
    return 0;
}

void GameLoop()
{
    SoccerGameGrid field;
    SoccerBotPlayer player[2];
    SoccerBotCoatch team[2];
    bool exit_flag = false;
    //flip coin
    do{
        StartKickOff(int kicker);
        if(Out_of_Bounds) StartSideThrough(int througher, ibsPosition location);
        if(Corner_Kick) StartCornerKick(int kicker, ibsPosition location);
        if(Score) {BumpScore(int team); if(Win) {ShowWinner(int winner); Stop_Game=true;} else StartKickOff(int kicker);}
        if(Stop_Game) exit_flag = true;
    }while(!exit_flag);
};
