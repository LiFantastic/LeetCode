/*============================================================
Problem: Max Points on a Line
==============================================================
Given n points on a 2D plane, find the maximum number of points 
that lie on the same straight line.
============================================================*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
		unordered_map<float,int> k2nums;
		int maxNum = 0;
		for (int i=0; i<points.size(); i++) {
			k2nums.clear();
			int duplicate = 1;
			for (int j=i+1; j<points.size(); j++) {
				if (points[i].x==points[j].x && points[i].y==points[j].y) {
					duplicate++;
					continue;
				}
				float k = points[i].x==points[j].x ? INT_MAX : (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
				k2nums[k]++;
			}
			for (auto it=k2nums.begin(); it!=k2nums.end(); it++)
				maxNum = max(maxNum, it->second+duplicate);
				
			maxNum = max(maxNum, duplicate);
		}
		return maxNum;
    }
};