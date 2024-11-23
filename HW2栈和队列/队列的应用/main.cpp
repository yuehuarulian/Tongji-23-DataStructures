#include <iostream>
using namespace std;

bool dfs(bool* map, const int row, const int col, int loc)//����һ��Ȼ��ȫ����0
{
    if (map[loc] != true)
        return false;
    map[loc] = false;
    bool bo = false;

    int x = loc / col, y = loc % col, dir = 0;
    if (x > 0)
    {
        bo |= dfs(map, row, col, loc - col);
        dir++;
    }
    if (x < row - 1)
    {
        bo |= dfs(map, row, col, loc + col);
        dir++;
    }
    if (y > 0)
    {
        bo |= dfs(map, row, col, loc - 1);
        dir++;
    }
    if (y < col - 1)
    {
        bo |= dfs(map, row, col, loc + 1);
        dir++;
    }
    bo |= dir == 4;
    return bo;
};
int solution(bool* map, int row, int col)
{
    int ans = 0;
    for (int i = 0; i < row * col; i++)
        if (map[i] == 1 && dfs(map, row, col, i) == true)
            ans++;
    return ans;
}


int main()
{
    int row, col;
    cin >> row >> col;
    bool* map = new bool[row * col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> map[i * col + j];
    }

    int ans = solution(map, row, col);
    delete map;
    cout << ans << endl;
    return 0;
}