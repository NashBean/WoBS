//
//  BotGameBase.h
//
//
//  Created by nash on 5/16/16.
//  Copyright 2016 iBean Software.
//  All rights reserved.
//
#include "BotBase.h"
#ifndef iBS_BotGameBase_h
#define iBS_BotGameBase_h

class ibsGameGrid2 : public ibsGrid
{
    ibsGameGrid2():this(50, 100){};
    
};

// ibsGrid grid;//init todo
// uint_fast32_t value = grid.row[y].col[x];

#define GRID_COL 100 // change width here
#define GRID_ROW 50 // change hight here

struct ibsGameGrid 
{
    
    int ref[GRID_COL][GRID_ROW];
    
	ibsGameGrid(){zero();};
	~ibsGameGrid(){};
	
	void scan_state()
	{
    	for(int	a=0; a<GRID_ROW; ++a) 
        	for(int	b=0; b<GRID_COL; ++b) 
            {
            	std::cin >> ref[a][b];
                
            }
	};
	
	bool in_bounds(ibsPosition&	p)
	{
		if(p.x < 0 || p.y < 0)	return false;
		else if(p.x >= GRID_COL || p.y >= GRID_ROW)	return false;
		return	true;
	};
    
	
	bool is_corner(ibsPosition&	p)
	{
		if(p.x == 0 && p.y == 0)	return true;
		else if(p.x == 0 && p.y == GRID_ROW-1)	return true;
		else if(p.x == GRID_COL-1 && p.y == 0)	return true;
		else if(p.x == GRID_COL-1 && p.y == GRID_ROW-1)	return true;
		return	false;
	};
	
	bool is_edge(ibsPosition&	p)
	{
		if(p.x == 0 || p.y == 0)	return true;
		else if(p.x == GRID_COL-1 || p.y == GRID_ROW-1)	return true;
		return	false;
	};
    
    bool isOpen(ibsPosition& p)
    {
        if(in_bounds(p))
            if(ref[p.x][p.y]==0) return true;
        return false;
    };
        
    void start_game()// for testing
    {
        ref[5][5]=1;
        ref[6][6]=1;
        ref[7][7]=1;
        ref[8][8]=1;
        ref[5][4]=1;
        ref[6][4]=1;
        //ref[3][9]=1;
        
        ref[4][5]=2;
        ref[7][3]=2;
        ref[4][4]=2;
        ref[9][9]=2;
        ref[4][3]=2;
        ref[4][6]=2;
        
        //ref[9][3]=2;
        //ref[9][6]=2;
    };   
    void zero()
    {
        for(int	a=0; a<GRID_COL; ++a) 
        	for(int	b=0; b<GRID_ROW; ++b) 
            	ref[a][b]=0;
        
    };   
    
    
public:
    
};


#endif // iBS_BotGameBase_h
