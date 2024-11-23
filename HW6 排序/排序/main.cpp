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
//øÏÀŸ≈≈–Ú
//class Solution {
//private:
//    void Qsort(vector<int>& nums,int low,int high)
//    {
//        if (low < high) {
//            int pivotloc = Partition(nums, low, high);
//            Qsort(nums, low, pivotloc - 1);
//            Qsort(nums, pivotloc + 1, high);
//        }
//    }
//    int Partition(vector<int>& nums, int low, int high)
//    {
//        int pivotkey = nums[low];
//        while (low < high) {
//            while (low < high && nums[high] >= pivotkey)//œ»“∆∂Øhigh
//                high--;
//            nums[low] = nums[high];
//            while (low < high && nums[low] <= pivotkey)
//                low++;
//            nums[high] = nums[low];
//        }
//        nums[low] = pivotkey;
//        return low;
//    }
//public:
//    std::vector<int> mySort(std::vector<int>& nums) {
//        Qsort(nums, 0, nums.size() - 1);
//        return nums;
//    }
//};
 

//œ£∂˚≈≈–Ú
class Solution {
private:
    void ShellInsert(vector<int>&nums, int gap)
    {
        for (int i = gap; i < nums.size(); i++) {
            if (nums[i] < nums[i - gap]) {
                int a = nums[i];
                int j;
                for (j = i - gap; j >= 0 && a < nums[j]; j -= gap)
                    nums[j + gap] = nums[j];
                nums[j + gap] = a;
            }
        }
    }
    void ShellSort(vector<int>&nums, int dlta[], int t)
    {
        for (int k = 0; k < t; k++) {
            ShellInsert(nums, dlta[k]);
        }
    }
public:
    std::vector<int> mySort(std::vector<int>& nums) {
        int dlta[] = { 5,3,1 };
        ShellSort(nums, dlta, sizeof(dlta) / sizeof(int));
        return nums;
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
    std::vector<int> after_sort(s.mySort(nums));
    std::cout << after_sort[0];
    for (int i = 1; i < n; i++) {
        std::cout << ' ' << after_sort[i];
    }
    std::cout << std::endl;
    return 0;
}