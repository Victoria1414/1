#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Структура для хранения координат клетки
struct Cell {
  int x, y;
   Cell(int x, int y) : x(x), y(y) {}
};

int main() {
  int N, M;
   cin >> N >> M;
    
     vector<vector<int>> table(N, vector<int>(M));
     vector<vector<int>> distance(N, vector<int>(M, INT_MAX));
      queue<Cell> q;
    
    // Чтение таблицы и инициализация очереди для BFS
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> table[i][j];
         if (table[i][j] == 1) {
                q.push(Cell(i, j));
                distance[i][j] = 0;
            }
        }
    }
    
    // Векторы для движения в четырёх направлениях
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    // BFS для нахождения минимальных расстояний
    while (!q.empty()) {
      Cell current = q.front();
       q.pop();
        
        for (int i = 0; i < 4; ++i) {
          int newX = current.x + dx[i];
          int newY = current.y + dy[i];
            
            if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
              if (distance[newX][newY] > distance[current.x][current.y] + 1) {
                    distance[newX][newY] = distance[current.x][current.y] + 1;
                    q.push(Cell(newX, newY));
                }
            }
        }
    }
    
    // Вывод результата
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
         cout << distance[i][j] << " ";
         }
         cout << endl;
    }
    
    return 0;
}
