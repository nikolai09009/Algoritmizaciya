#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Edge {
    int begin;
    int end;
};

// Класс Node представляет вершину графа
class Node {
public:
    int id;     // Идентификатор вершины
    int state;  // 0 = не посещена, 1 = обнаружена, 2 = посещена

    Node(int id) : id(id), state(0) {} // Конструктор вершины с начальным состоянием
};

// Класс Graph представляет граф и методы для работы с ним
class Graph {
private:
    // Матрица смежности для представления графа
    int adjacencyMatrix[7][7] = {
        { 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0 }
    };
    vector<Node> nodes;   // Вектор вершин
    stack<Edge> edges;    // Стек рёбер для сохранения пути

public:
    // Конструктор графа, инициализирует вершины
    Graph() {
        for (int i = 0; i < 7; i++) {
            nodes.push_back(Node(i));
        }
    }

    // Метод BFS для обхода графа в ширину
    void BFS(int start, int target) {
        queue<int> Queue;
        Queue.push(start);
        nodes[start].state = 1; // помечаем начальную вершину как обнаруженную

        cout << "Обход в ширину, начиная с вершины " << start + 1 << ":\n";

        while (!Queue.empty()) {
            int nodeID = Queue.front();
            Queue.pop();
            nodes[nodeID].state = 2; // помечаем вершину как посещенную
            cout << nodeID + 1 << endl;

            for (int j = 0; j < 7; j++) {
                if (adjacencyMatrix[nodeID][j] == 1 && nodes[j].state == 0) {
                    Queue.push(j);
                    nodes[j].state = 1; // отмечаем как обнаруженную
                    edges.push({ nodeID, j }); // сохраняем ребро
                    if (j == target) break; // прерываем, если достигли цели
                }
            }
        }
    }

    // Метод для вывода пути от начальной вершины до целевой
    void printPath(int target) {
        cout << "Путь до вершины " << target + 1 << ":\n" << target + 1;
        while (!edges.empty()) {
            Edge e = edges.top();
            edges.pop();
            if (e.end == target) {
                target = e.begin;
                cout << " <- " << target + 1;
            }
        }
        cout << endl;
    }
};

int main() {
    system("chcp 1251"); // Устанавливаем кодировку для русских символов
    system("cls"); // Очищаем консоль

    Graph graph;
    int req;
    cout << "Введите номер целевой вершины (1-7): ";
    cin >> req;
    req--;

    graph.BFS(0, req); // Запуск BFS с вершины 0
    graph.printPath(req); // Вывод пути до целевой вершины

    cin.get();
    cin.get();
    return 0;
}

