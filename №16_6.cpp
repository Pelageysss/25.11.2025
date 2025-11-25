#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> maze(N, vector<char>(M));
    Point start, exit;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'P') {
                start = {i, j};
            } else if (maze[i][j] == 'E') {
                exit = {i, j};
            }
        }
    }
    vector<vector<int>> dist(N, vector<int>(M, -1));
    vector<vector<int>> pdfCount(N, vector<int>(M, 0));
    queue<Point> q;
    q.push(start);
    dist[start.x][start.y] = 0;
    pdfCount[start.x][start.y] = (maze[start.x][start.y] == 'P') ? 1 : 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '1') {
                int newDist = dist[current.x][current.y] + 1;
                int newPdfCount = pdfCount[current.x][current.y] + (maze[nx][ny] == 'P' ? 1 : 0);
                if (dist[nx][ny] == -1 || newDist < dist[nx][ny] || 
                    (newDist == dist[nx][ny] && newPdfCount > pdfCount[nx][ny])) {
                    dist[nx][ny] = newDist;
                    pdfCount[nx][ny] = newPdfCount;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << pdfCount[exit.x][exit.y] << endl;
    return 0;
}
