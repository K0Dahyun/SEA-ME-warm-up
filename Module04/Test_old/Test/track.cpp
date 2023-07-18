#include "track.h"

Track::Track() 
{
track_info = {
            {0, 20, 330, 75},
            {0, 75, 95, 620},
            {0, 620, 540, 680},
            {430, 155, 540, 620},
            {230, 155, 430, 290},
            {230, 75, 330, 155}
        };
}

/*
bool Track::isPointin(int point_x, int point_y) 
{
    for(int i = 0; i<track_info.size(); i++) {
        if(track_info[i][0] <= point_x && track_info[i][2] >= point_x && track_info[i][1] <= point_y && track_info[i][3] >= point_y) {
            check = true;
            break;
        }
        else
            check = false;
    }

    return check;
}
*/

bool Track::isPointin(float point_x, float point_y) {
    for(int i = 0; i < track_info.size(); i++) {
        if(track_info[i][0] <= point_x && track_info[i][2] >= point_x && track_info[i][1] <= point_y && track_info[i][3] >= point_y) {
            return true;
        }
    }
    return false;
}

int Track::getNormalAngle(float point_x, float point_y) {
    for(int i = 0; i < track_info.size(); i++) {
        if(track_info[i][0] <= point_x && track_info[i][2] >= point_x && track_info[i][1] <= point_y && track_info[i][3] >= point_y) {
            return track_info[i][4];
        }
    }
    return -1;
}