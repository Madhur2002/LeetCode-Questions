class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<int>prev = points[0];
        
        int count = 1;
        
        for(int i=1; i<n; i++){
            int currentStartingPoint = points[i][0];
            int currentEndingPoint = points[i][1];
            
            int prevStartingPoint = prev[0];
            int prevEndingPoint = prev[1];
            
            if(currentStartingPoint > prevEndingPoint){
                count++;
                prev = points[i];
            }else{
                prev[0] = max(currentStartingPoint, prevStartingPoint);
                prev[1] = min(currentEndingPoint, prevEndingPoint);
            }
        }
        return count;
    }
};