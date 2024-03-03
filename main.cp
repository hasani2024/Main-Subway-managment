//#include "mainwindow.h"
//#include "subwaymanagement.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
////    MainWindow w;
////    w.show();

//    Graph g;

//    // Add edges
//    g.addEdge("Gholhak", "Mirdamad",QColor(Qt::red));
//    g.addEdge("Mirdamad", "Shahid Haghani",QColor(Qt::red));
//    g.addEdge("Shahid Haghani","Shahid Beheshti",QColor(Qt::red));
//    g.addEdge("Shahid Beheshti","Shahid Mofatteh",QColor(Qt::red));
//    g.addEdge("Shahid Mofatteh","Haftom-e Tir",QColor(Qt::red));
//    g.addEdge("Shahid Beheshti", "Merza-ye Shirazi",QColor(Qt::blue));
//    g.addEdge("Merza-ye Shirazi", "Meydan-e Jahad",QColor(Qt::blue));


//    QString start = "Gholhak";
//    QString end = "Merza-ye Shirazi";

//    vector<QString> path = g.shortestPath(start, end);
//    if (!path.empty()) {
//        cout << "Shortest path from " << start.toStdString() << " to " << end.toStdString() << ": ";
//        for (size_t i = 0; i < path.size(); ++i) {
//            cout << path[i].toStdString() ;
//            if (i < path.size() - 1) {
//                cout << " -> ";
//            }
//        }
//        cout << endl;
//    } else {
//        cout << "No path exists between " << start.toStdString() << " and " << end.toStdString() << endl;
//    }





//    return a.exec();
//}














//#include <iostream>
//#include <queue>
//#include <vector>
//#include <unordered_map>
//#include <QString>
//#include <QColor>

//using namespace std;

//class Graph {
//public:
//    struct Edge {
//        QString start;
//        QString end;
//        QString color; // Store color as string
//        int distance; // Distance between stations

//        Edge(const QString& s, const QString& e, const QString& c, int d) : start(s), end(e), color(c), distance(d) {}
//    };

//private:
//    unordered_map<QString, vector<Edge>> adjList;

//public:
//    void addEdge(const QString& v, const QString& w, const QString& color, int distance) {
//        adjList[v].push_back(Edge(v, w, color, distance));
//        adjList[w].push_back(Edge(w, v, color, distance)); // Uncomment this line if the graph is undirected
//    }

//    vector<QString> shortestPath(const QString& start, const QString& end) {
//        unordered_map<QString, bool> visited;
//        unordered_map<QString, QString> parent;
//        unordered_map<QString, QString> edgeColors; // Store color as string
//        unordered_map<QString, int> distances;
//        queue<QString> q;

//        q.push(start);
//        visited[start] = true;
//        parent[start] = "";
//        edgeColors[start] = adjList[start][0].color; // Set color of initial node as specified color
//        distances[start] = 0; // Set initial distance to 0

//        while (!q.empty()) {
//            QString current = q.front();
//            q.pop();

//            if (current == end) {
//                // Reconstruct path
//                vector<QString> path;
//                QString node = end;
//                while (node != "") {
//                    path.push_back(node);
//                    node = parent[node];
//                }
//                reverse(path.begin(), path.end());
//                int distance = 0;
//                // Print path along with edge colors and distances
//                for (size_t i = 0; i < path.size() - 1; ++i) {
//                    QString currentNode = path[i];
//                    QString nextNode = path[i + 1];
//                    QString edgeColor = edgeColors[currentNode]; // Get color as string
//                    distance = distances[nextNode]; // Get distance
//                    cout << "From " << currentNode.toStdString() << " (Color: " << edgeColor.toStdString() << ")";
//                    cout << ", Distance = " << distance << ", " <<" , Time = " <<distance*1 << " min , ";
//                    cout << "to " << nextNode.toStdString() << endl;
//                }

//                return path;
//            }

//            for (const auto& edge : adjList[current]) {
//                if (!visited[edge.end]) {
//                    visited[edge.end] = true;
//                    q.push(edge.end);
//                    parent[edge.end] = current;
//                    edgeColors[edge.end] = edge.color;
//                    distances[edge.end] = distances[current] + edge.distance; // Update distance
//                }
//            }
//        }

//        return {}; // If no path exists
//    }
//};
//int main() {
//    Graph g;

//    // Add edges with colors
//    g.addEdge("Gholhak", "Mirdamad","red",4);
//    g.addEdge("Mirdamad", "Shahid Haghani","red",5);
//    g.addEdge("Shahid Haghani","Shahid Beheshti","red",7);
//    g.addEdge("Shahid Beheshti","Shahid Mofatteh","red",2);
//    g.addEdge("Shahid Mofatteh","Haftom-e Tir","red",2);
//    g.addEdge("Shahid Beheshti", "Merza-ye Shirazi","blue",1);
//    g.addEdge("Merza-ye Shirazi", "Meydan-e Jahad","blue",2);

//    QString start = "Gholhak";
//    QString end = "Meydan-e Jahad";

//    vector<QString> path = g.shortestPath(start, end);
//    if (!path.empty()) {
//        cout << "Shortest path from " << start.toStdString() << " to " << end.toStdString() << ": ";
//        for (size_t i = 0; i < path.size(); ++i) {
//            cout << path[i].toStdString();
//            if (i < path.size() - 1) {
//                cout << " -> ";
//            }
//        }
//        cout << endl;
//    } else {
//        cout << "No path exists between " << start.toStdString() << " and " << end.toStdString() << endl;
//    }

//    return 0;
//}












#include "mainwindow.h"
#include "subwaymanagement.h"
#include <QApplication>




int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Graph g;

    // Add edges with colors
    g.addEdge("Gholhak", "Mirdamad","red",4);
    g.addEdge("Mirdamad", "Shahid Haghani","red",5);
    g.addEdge("Shahid Haghani","Shahid Beheshti","red",7);
    g.addEdge("Shahid Beheshti","Shahid Mofatteh","red",2);
    g.addEdge("Shahid Mofatteh","Haftom-e Tir","red",2);
    g.addEdge("Shahid Beheshti", "Merza-ye Shirazi","blue",1);
    g.addEdge("Merza-ye Shirazi", "Meydan-e Jahad","blue",2);

    QString start = "Mirdamad";
    QString end = "Meydan-e Jahad";

    vector<QString> path = g.shortestPath(start, end);
    if (!path.empty()) {
        cout << "Shortest path from " << start.toStdString() << " to " << end.toStdString() << ": ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i].toStdString();
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl <<endl;
    } else {
        cout << "No path exists between " << start.toStdString() << " and " << end.toStdString() << endl;
    }

    return a.exec();
}







