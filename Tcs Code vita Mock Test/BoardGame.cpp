#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

struct State
{
    int x, y, steps;
};

int M, N;
vector<vector<int>> grid;
pair<int, int> source, destination, moveRule;
vector<vector<bool>> visited;

vector<pair<int, int>> getNextPositions(int x, int y)
{
    vector<pair<int, int>> nextPositions;
    nextPositions.push_back({x + moveRule.first, y + moveRule.second}); // forward
    nextPositions.push_back({x + moveRule.second, y - moveRule.first}); // right (90 degree clockwise)
    nextPositions.push_back({x - moveRule.second, y + moveRule.first}); // left (90 degree counter-clockwise)
    nextPositions.push_back({x - moveRule.first, y - moveRule.second}); // backward (180 degree)

    return nextPositions;
}

bool isValid(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N && grid[x][y] == 0 && !visited[x][y];
}

int bfs()
{

    queue<State> q;
    q.push({source.first, source.second, 0});
    visited[source.first][source.second] = true;

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        if (current.x == destination.first && current.y == destination.second)
            return current.steps;

        for (auto pos : getNextPositions(current.x, current.y))
        {
            int nx = pos.first;
            int ny = pos.second;

            if (isValid(nx, ny))
            {
                visited[nx][ny] = true;
                q.push({nx, ny, current.steps + 1});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> M >> N;
    grid.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    cin >> moveRule.first >> moveRule.second;
    int result = bfs();
    cout << result << endl;

    return 0;
}
