//
//  iBS_BotBase.h
//
//
//  Created by nash on 5/12/16.
//  Copyright 2016 iBean Software.
//  All rights reserved.
//

#ifndef iBS_BotBase_h
#define iBS_BotBase_h
#include <iostream>
#include <vector>

struct ibsPosition
{
        int x, y;
        ibsPosition(){x=y=0;};
        ibsPosition(int ax, int ay){x=ax;y=ay;};
        //    Position(const  Position& a){x=a.x;y=a.y;};
        ~ibsPosition(){};
        
        bool operator ==(ibsPosition& other)
        {
            if(x == other.x && y == other.y)
                return true;
            return false;
        };
        
        bool operator !=(ibsPosition& other)
        {
            if(x == other.x && y == other.y)
                return false;
            return true;
        };
        
        void set(int px, int py){x=px;y=py;}; 
        void set(ibsPosition& a){x=a.x;y=a.y;}; 
        
        int find_distance(int px, int py)
        {
            int   result=0;
            if (x>px) result+=x-px;
            else if(x<px) result+=px-x;
            if (y>py) result+=y-py;
            else if(y<py) result+=py-y;
            return result;
        };
        
        int is_neighbour(int px, int py) 
        {
            if (px == x  &&  py == y)
                return false;
            else if (abs(px-x) == 1 && abs(py-y) == 0)
                return 2;
            else if (abs(px-x) == 0 && abs(py-y) == 1)
                return 1;
            else if (((px-x) > 0 && (py-y) > 0) ||
                     ((px-x) < 0 && (py-y) < 0))
                return 3;
            else if (((px-x) > 0 && (py-y) < 0) ||
                     ((px-x) < 0 && (py-y) > 0))
                return 4;
            else return 0;
            
            return false;
        };
        
        int is_neighbour(ibsPosition& p)
        {
            return is_neighbour(p.x, p.y);
        };
        
   
private:
    
};
// -----------------------------------------------
#define GRID_COL 10 // change width here
#define GRID_ROW 10 // change hight here

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


class ibsBotBase 
{
    ibsPosition CP; // Current Position;
    
    
public:
    
};



#endif // iBS_iBS_BotBase_h