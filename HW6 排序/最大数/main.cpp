#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            long long int al = 1, bl = 1;
        while (al <= a)
            al *= 10;
        while (bl <= b)
            bl *= 10;
        return a * bl + b > b * al + a;
            });
        string s;
        for (auto i : nums)
            s = s + to_string(i);
        return s;
    }
};


int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    Solution s;
    std::cout << s.largestNumber(nums) << std::endl;
    return 0;
}