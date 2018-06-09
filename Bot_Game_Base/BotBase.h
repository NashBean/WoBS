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
        ibsPosition(Position const& a){x=a.x;y=a.y;};
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
struct ibsRow 
{
    std::vector<uint_fast32_t> col;
    ibsRow():col(0){};
    ibsRow(size_t sz):col(sz){};
    ibsRow(std::vector<uint_fast32_t> nc):col(nc.size()){};
    
    ibsRow& operator=(ibsRow const& nr)
    { 
        col.resize(nr.col.size());
        for(size_t c=0; c<col.size(); c++) 
            col[c] = nr.col[c];
        return *this;
    };
};

struct ibsGrid
{
    ibsGrid():row(0){};
    ibsGrid(size_t row_sz, size_t col_sz)
    {
        row.reserve(row_sz);
        for(size_t r=0; r<row_sz; ++r) 
        {
            row.push_back(ibsRow(col_sz));
        }
    };
    
 
    std::vector<ibsRow> row;   
};



class ibsBotBase 
{
    ibsPosition CP; // Current Position;
    
    
public:
    
};



#endif // iBS_iBS_BotBase_h
