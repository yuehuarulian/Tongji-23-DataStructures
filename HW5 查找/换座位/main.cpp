/**
 * @file    template.cpp
 * @name    p138模板程序
 * @date    2022-11-20
*/

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


/********************************/
/*     以下是可能需要修改的代码     */
/********************************/
class Solution {
public:
    int solve(std::vector<vector<std::string>>& old_chart, std::vector<std::vector<std::string>>& new_chart) {
        // 在这里填写你的代码逻辑
        int n = old_chart.size();
        int m = old_chart[0].size();
        int count = 0;
        map<string, pair<int, int>> MAP;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                MAP[new_chart[i][j]] = make_pair(i, j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (old_chart[i][j] != new_chart[i][j]) {
                    int x = MAP[old_chart[i][j]].first;
                    int y = MAP[old_chart[i][j]].second;
                    swap(old_chart[i][j], old_chart[x][y]);
                    count++;
                }
            }
        }
        return count;
    }
};
/********************************/
/*     以上是可能需要修改的代码     */
/********************************/

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::string>> old_chart(n, std::vector<std::string>(m));
    std::vector<std::vector<std::string>> new_chart(n, std::vector<std::string>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> old_chart[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> new_chart[i][j];
        }
    }

    Solution s;
    std::cout << s.solve(old_chart, new_chart) << std::endl;
    return true;
}
