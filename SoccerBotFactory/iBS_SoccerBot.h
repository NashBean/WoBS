//
//  iBS_SoccerBot.h
//
//
//  Created by nash on 5/12/16.
//  Copyright 2016 iBean Software.
//  All rights reserved.
//

#ifndef iBS_SoccerBot_h
#define iBS_SoccerBot_h

#include <vector>
#include "iBS_BotBase.h"

struct SoccerGameTick// one turn
{
    
};

class SoccerGameGrid : public ibsGameGrid
{
    
};

struct SBP_UserSettings 
{
    
};

struct SBP_Stats 
{
    bool zoneaware;

    int armor;
    int battery_power;
    int speed;
    int kick_power; // ball kicker 
    int headbutt_power; // 
    int CPU_speed;
    int pinalty_countdown;
    
    
    SBP_Stats()
    {
        armor = 20;
        battery_power = 100;
        speed = 40;
        kick_power = 20;
        headbutt_power = 10;
        CPU_speed = 10;
    };
};

class SoccerBot : private ibsBotBase 
{
    SBP_Stats stats;
    SoccerBot(){ibsBotBase();};
    
public:
    
};

class SoccerBotPlayer : public SoccerBot
{
    SBP_UserSettings user;
public:
};

class SoccerBotCoatch : public SoccerBot
{
    std::vector<SoccerBotPlayer*> players; 
    
public:
    
    
};

#endif // iBS_iBS_SoccerBot_h
