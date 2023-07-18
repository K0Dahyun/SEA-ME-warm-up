#ifndef TRACK_H
#define TRACK_H

#include <vector>

class Track
{
public:
    Track();
    bool isPointin(float point_x, float point_y);
    int getNormalAngle(float point_x, float point_y);
    bool check;
    
private:
    std::vector<std::vector<int>> track_info;
};


#endif // TRACK_H
