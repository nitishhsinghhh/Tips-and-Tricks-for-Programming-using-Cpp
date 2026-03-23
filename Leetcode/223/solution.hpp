/*
    Logic

    1. Area of A:
        areaA = (ax2 − ax1) × (ay2 − ay1)

    2. Area of B:
        areaB = (bx2 − bx1) × (by2 − by1)

    3. Overlap (intersection) width & height:
        w = max⁡(0, min⁡(ax2, bx2) − max⁡(ax1, bx1))
        h = max⁡(0, min⁡(ay2, by2) − max⁡(ay1, by1))

    4. Total union area:
        areaA + areaB − (w × h)
*/
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <algorithm>

using std::max;
using std::min;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);

        int overlapW = max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapH = max(0, min(ay2, by2) - max(ay1, by1));

        return areaA + areaB - (overlapW * overlapH);
    }
};

#endif