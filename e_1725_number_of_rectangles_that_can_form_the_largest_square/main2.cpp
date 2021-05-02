class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLenght = 0;
        int count = 0;
        for (int i = 0; i < rectangles.size(); ++i) {
            int newMaxLenght = min(rectangles[i][0], rectangles[i][1]);
            
            if (newMaxLenght > maxLenght) {
                count = 1;
                maxLenght = newMaxLenght;
            } else if (newMaxLenght == maxLenght) {
                count++;
            }
        }
        return count;
    }
};
