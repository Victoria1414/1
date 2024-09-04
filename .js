function minDistance(N, M, table) {
    const distance = Array.from({ length: N }, () => Array(M).fill(Infinity));
    const queue = [];

    // Направления движения в 4 стороны
    const directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1]
    ];

    // Инициализация очереди и начальных расстояний
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < M; j++) {
        if (table[i][j] === 1) {
          queue.push([i, j]);
           distance[i][j] = 0;
            }
        }
    }

    // BFS
    while (queue.length > 0) {
     const [x, y] = queue.shift();

        for (const [dx, dy] of directions) {
          const newX = x + dx;
          const newY = y + dy;

          if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
            if (distance[newX][newY] > distance[x][y] + 1) {
              distance[newX][newY] = distance[x][y] + 1;
               queue.push([newX, newY]);
                }
            }
        }
    }

    return distance;
}

// Чтение входных данных с помощью стандартного ввода
const readline = require('readline');
 const rl = readline.createInterface({
   input: process.stdin,
    output: process.stdout
});

let input = [];
 rl.on('line', (line) => {
input.push(line);
 }).on('close', () => {
    const [N, M] = input[0].split(' ').map(Number);
     const table = input.slice(1).map(line => line.split(' ').map(Number));
     const result = minDistance(N, M, table);

    result.forEach(row => console.log(row.join(' ')));
});
