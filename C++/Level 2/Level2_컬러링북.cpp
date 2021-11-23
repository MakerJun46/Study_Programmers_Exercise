#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[100][100];
vector<vector<int>> picture_Input;
map<int, int> pic_map;
int areaIndex = -1;
int height = 0;
int width = 0;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

void BFS(int y, int x, int color)
{
    if (visited[y][x])
        return;
    else if(picture_Input[y][x] == color)
    {
        visited[y][x] = true;
        pic_map[areaIndex]++;
        
        if (y < height - 1)
            BFS(y + 1, x, color);

        if (y != 0)
            BFS(y - 1, x, color);

        if (x < width - 1)
            BFS(y, x + 1, color);

        if (x != 0)
            BFS(y, x - 1, color);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    height = m;
    width = n;
    areaIndex = -1;

    visited[100][100] = { false, };

    for (int i = 0; i < picture.size(); i++)
    {
        vector<int> tmp;
        for (int j = 0; j < picture[i].size(); j++)
        {
            int tmp2 = picture[i][j];
            tmp.push_back(tmp2);
        }

        picture_Input.push_back(tmp);
    }

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (picture[y][x] && !visited[y][x]) // 새로운 영역
            {
                areaIndex++;
                BFS(y, x, picture[y][x]);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = areaIndex + 1;
    answer[1] = max_element(pic_map.begin(), pic_map.end(), cmp)->second;
    return answer;
}


void main()
{
    vector<vector<int>> picture =
    {
        {1, 1, 1, 0},
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 3},
        {0, 0, 0, 3}
    };

    //vector<int> answer = solution(6, 4, picture);

    //cout << answer[0] << " " << answer[1] <<endl;

    vector<int> ans;
    /*
    ans = solution(6, 4, 
        { { 1, 0, 0, 1 }, 
        { 1, 0, 0, 1 }, 
        { 1, 0, 0, 1 }, 
        { 1, 0, 0, 1 }, 
        { 1, 0, 0, 1 }, 
        { 1, 1, 1, 1 } });
    std::cout << ans[0] << " " << ans[1] << endl;
    */
    /*
    ans = solution(4, 4, 
        { { 1, 1, 1, 1 }, 
        { 1, 4, 1, 1 }, 
        { 1, 3, 2, 1 }, 
        { 1, 1, 1, 1 } });
    std::cout << ans[0] << " " << ans[1] << endl;
    */

    ans = solution(13, 16, {
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,1,1,1,1,2,1,1,1,1,2,1,1,1,1,0},
{0,1,1,1,2,1,2,1,1,2,1,2,1,1,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,3,3,3,1,1,1,1,1,1,3,3,3,1,0},
{0,1,1,1,1,1,3,1,1,3,1,1,1,1,1,0},
{0,0,1,1,1,1,1,3,3,1,1,1,1,1,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0}
        });
    std::cout << ans[0] << " " << ans[1] << endl;
}


