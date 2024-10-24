/*

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/
#include <bits/stdc++.h>
using namespace std;

class MostWater
{
public:
    int findMaximumArea(vector<int> &height)  /*   1,8,6,2,5,4,8,3,7 */
    {
        int low = 0;
        int high = height.size() - 1;
        int maxArea = 0;
        while (low < high)
        {
            int width = high - low;    
            int h = min(height[low], height[high]);
            int area = width * h;
            maxArea = max(maxArea, area); // (0,6) 

            if (height[low] < height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return maxArea;
    }
};

int main()
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    while (testcases--)
    {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        MostWater mt;

        int result = mt.findMaximumArea(height);
        cout << result;
    }
    return 0;
}