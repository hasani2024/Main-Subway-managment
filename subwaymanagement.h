#ifndef SUBWAYMANAGEMENT_H
#define SUBWAYMANAGEMENT_H

#include <QWidget>
#include <QString>
#include <QObject>
#include <QVector>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <QString>
#include <QColor>
#include <QListWidgetItem>



namespace Ui {
class SubwayManagement;
}

class SubwayManagement : public QWidget
{
    Q_OBJECT

public:
    explicit SubwayManagement(QWidget *parent = nullptr);
    ~SubwayManagement();

private slots:
    void on_pushButton_clicked();

public:
    Ui::SubwayManagement *ui;
};






using namespace std;

class Graph : public SubwayManagement{
public:
    struct Edge {
        QString start;
        QString end;
        QString color; // Store color as string
        int distance; // Distance between stations
        int cost;
        Edge(const QString& s, const QString& e, const QString& c, int d,int ct) : start(s), end(e), color(c), distance(d), cost(ct) {}
    };

private:
    unordered_map<QString, vector<Edge>> adjList;
    int colorChangeCost; // Cost for changing the color of the metro line

public:
//    Graph() : colorChangeCost(cost);// Constructor to initialize the color change cost
    Graph(int cost) : colorChangeCost(cost){}
    void addEdge(const QString& v, const QString& w, const QString& color, int distance,int ct) {
        adjList[v].push_back(Edge(v, w, color, distance,ct));
        adjList[w].push_back(Edge(w, v, color, distance,ct)); // Uncomment this line if the graph is undirected
    }




    string shortestPath(const QString& start, const QString& end) {
        string output;
        unordered_map<QString, bool> visited;
        unordered_map<QString, QString> parent;
        unordered_map<QString, QString> edgeColors; // Store color as string
        unordered_map<QString, int> distances;
        unordered_map<QString, int> colorChangeCount; // Store color change count for each node
        queue<QString> q;

        q.push(start);
        visited[start] = true;
        parent[start] = "";
        edgeColors[start] = adjList[start][0].color; // Set color of initial node as specified color
        distances[start] = 0; // Set initial distance to 0
        colorChangeCount[start] = 0; // Initialize color change count

        while (!q.empty()) {
            QString current = q.front();
            q.pop();

            if (current == end) {
                // Reconstruct path
                vector<QString> path;
                QString node = end;
                while (node != "") {
                    path.push_back(node);
                    node = parent[node];
                }
                reverse(path.begin(), path.end());
                int totalCost = 0;
                QString prevColor = edgeColors[path[0]]; // Previous color of the metro line
                int distance = 0;
                QString preHue = edgeColors[path[0]];
                // Print path along with edge colors and distances
                for (size_t i = 0; i < path.size() - 1; ++i) {
                    QString currentNode = path[i];
                    QString nextNode = path[i + 1];
                    QString edgeColor = edgeColors[currentNode]; // Get color as string
                    distance = distances[nextNode]; // Get distance
                    cout << "From " << currentNode.toStdString() << " (Color: " << edgeColor.toStdString() << ")";
                    output +="From " + currentNode.toStdString() + " (Color: " + edgeColor.toStdString() + ")";
                    if(preHue.toStdString() != edgeColor.toStdString()){
                        cout << ", Distance = " << distance << ", Time = " << distance * 1 + 8 << " minute , ";
                        output +=", Distance = " + to_string(distance) + ", Time = " +to_string(distance * 1 + 8 ) + " minute , ";
                        preHue =  edgeColor;
                    }
                    else{
                        cout << ", Distance = " << distance << ", Time = " << distance * 1 << " minute , ";
                        output +=", Distance = " + to_string(distance) + ", Time = " +to_string(distance * 1) + " minute , ";
                    }
                    cout << "to " << nextNode.toStdString() << endl;
                    output += "\n" + nextNode.toStdString();
                    // Check if the color changes
                    if (edgeColors[nextNode] != edgeColor) {
                        totalCost += colorChangeCost; // Add color change cost
                        prevColor = edgeColors[nextNode]; // Update previous color
                    }
                }

                // Calculate the total cost including color change cost and distance
                totalCost += distances[end] * 3267;
                cout << "Total Cost = " << totalCost - ((distance-1)*3267)<< " Tomans" << endl;
                output += "\nTotal Cost = " + to_string(totalCost - ((distance-1)*3267))+  " Tomans";
                QListWidgetItem* item = new QListWidgetItem();
                item->setText(QString::fromStdString(output));

                return output;

            }

            for (const auto& edge : adjList[current]) {
                if (!visited[edge.end]) {
                    visited[edge.end] = true;
                    q.push(edge.end);
                    parent[edge.end] = current;
                    edgeColors[edge.end] = edge.color;
                    distances[edge.end] = distances[current] + edge.distance; // Update distance
                    colorChangeCount[edge.end] = colorChangeCount[current]; // Inherit color change count
                    if (edgeColors[edge.end] != edgeColors[current]) {
                        colorChangeCount[edge.end]++; // Increment color change count if color changes
                    }
                }
            }
        }

        return {}; // If no path exists
    }





//    vector<QString> shortestPathWithMinimumCost(const QString& start, const QString& end) {
//        priority_queue<pair<int, QString>, vector<pair<int, QString>>, greater<pair<int, QString>>> pq;
//        unordered_map<QString, int> minCost; // Minimum cost to reach each node
//        unordered_map<QString, QString> parent; // Parent node for each node in the shortest path

//        pq.push({0, start}); // Start with zero cost to reach start node
//        minCost[start] = 0;

//        while (!pq.empty()) {
//            auto [cost, current] = pq.top();
//            pq.pop();

//            if (current == end) {
//                // Reconstruct path
//                vector<QString> path;
//                QString node = end;
//                while (node != "") {
//                    path.push_back(node);
//                    node = parent[node];
//                }
//                reverse(path.begin(), path.end());

//                // Output the path along with distances and total cost
//                cout << "Path: ";
//                int totalCost = 0;
//                QString prevColor;
//                for (size_t i = 0; i < path.size() - 1; ++i) {
//                    QString currentNode = path[i];
//                    QString nextNode = path[i + 1];
//                    int distance = getDistance(currentNode, nextNode);
//                    totalCost += distance; // Increment total cost with distance
//                    if (adjList[currentNode][0].color != prevColor && i > 0) {
//                        totalCost += colorChangeCost; // Add color change cost if color changes
//                    }
//                    prevColor = adjList[currentNode][0].color;
//                    cout << currentNode.toStdString() << " --(" << distance << " km)-> ";
//                }
//                cout << end.toStdString() << endl;
//                if (path.size() > 1) {
//                    totalCost = colorChangeCost; // Add color change cost for the last edge
//                }
//                cout << "Total Cost: " << totalCost << " Tomans" << endl;

//                return path;
//            }

//            for (const auto& edge : adjList[current]) {
//                int newCost = cost + edge.distance;
//                if (minCost.find(edge.end) == minCost.end() || newCost < minCost[edge.end]) {
//                    minCost[edge.end] = newCost;
//                    parent[edge.end] = current;
//                    pq.push({newCost, edge.end});
//                }
//            }
//        }

//        return {}; // If no path exists
//    }


    string minCostDijkstraWithPath(const QString& start, const QString& end) {
        unordered_map<QString, int> minCost; // Minimum cost to reach each node
        unordered_map<QString, QString> parent; // Parent node for each node in the shortest path
        priority_queue<pair<int, QString>, vector<pair<int, QString>>, greater<pair<int, QString>>> pq;

        // Initialize the cost of each node as infinity
        for (const auto& vertex : adjList) {
            minCost[vertex.first] = INT_MAX;
        }

        // Start with zero cost to reach start node
        minCost[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [cost, current] = pq.top();
            pq.pop();

            // If reached the end node, reconstruct the path and return it with the cost
            if (current == end) {
                string path;
                path += end.toStdString(); // Append the end node
                QString node = end;
                int totalCost = minCost[end]; // Initialize the total cost with the cost of the end node
                int counter = 0;
                while (node != start) {
                    counter++;
                    QString parentNode = parent[node];
                    int edgeCost = getEdgeCost(parentNode, node); // Get the cost of the edge
                    path = parentNode.toStdString() + " -> " + path; // Prepend each parent node to the path
                    node = parentNode;
                }
                return "Path: " + path + ", Total Cost: " + to_string(totalCost/counter);
            }

            // Iterate through adjacent nodes of the current node
            for (const auto& edge : adjList[current]) {
                int newCost = cost + edge.cost;
                if (newCost < minCost[edge.end]) {
                    minCost[edge.end] = newCost;
                    parent[edge.end] = current;
                    pq.push({newCost, edge.end});
                }
            }
        }

        return "No path found"; // If no path exists
    }


    int getEdgeCost(const QString& from, const QString& to) {
        for (const auto& edge : adjList[from]) {
            if (edge.end == to) {
                return edge.cost;
            }
        }
        return INT_MAX; // If no direct edge found
    }


    int getDistance(const QString& from, const QString& to) {
        for (const auto& edge : adjList[from]) {
            if (edge.end == to) {
                return edge.distance;
            }
        }
        return -1; // If no direct edge found
    }

};



//    vector<QString> shortestPath(const QString& start, const QString& end) {
//        string output;
//        unordered_map<QString, bool> visited;
//        unordered_map<QString, QString> parent;
//        unordered_map<QString, QString> edgeColors; // Store color as string
//        unordered_map<QString, int> distances;
//        unordered_map<QString, int> colorChangeCount; // Store color change count for each node
//        queue<QString> q;

//        q.push(start);
//        visited[start] = true;
//        parent[start] = "";
//        edgeColors[start] = adjList[start][0].color; // Set color of initial node as specified color
//        distances[start] = 0; // Set initial distance to 0
//        colorChangeCount[start] = 0; // Initialize color change count

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
//                int totalCost = 0;
//                QString prevColor = edgeColors[path[0]]; // Previous color of the metro line
//                int distance = 0;
//                QString preHue = edgeColors[path[0]];
//                // Print path along with edge colors and distances
//                for (size_t i = 0; i < path.size() - 1; ++i) {
//                    QString currentNode = path[i];
//                    QString nextNode = path[i + 1];
//                    QString edgeColor = edgeColors[currentNode]; // Get color as string
//                    distance = distances[nextNode]; // Get distance
//                    cout << "From " << currentNode.toStdString() << " (Color: " << edgeColor.toStdString() << ")";
//                    output +="From " + currentNode.toStdString() + " (Color: " + edgeColor.toStdString() + ")";
//                    if(preHue.toStdString() != edgeColor.toStdString()){
//                        cout << ", Distance = " << distance << ", Time = " << distance * 1 + 8 << " minute , ";
//                        output +=", Distance = " + to_string(distance) + ", Time = " +to_string(distance * 1 + 8 ) + " minute , ";
//                        preHue =  edgeColor;
//                    }
//                    else{
//                        cout << ", Distance = " << distance << ", Time = " << distance * 1 << " minute , ";
//                        output +=", Distance = " + to_string(distance) + ", Time = " +to_string(distance * 1) + " minute , ";
//                    }
//                    cout << "to " << nextNode.toStdString() << endl;
//                    output += "\n" + nextNode.toStdString();
//                    // Check if the color changes
//                    if (edgeColors[nextNode] != edgeColor) {
//                        totalCost += colorChangeCost; // Add color change cost
//                        prevColor = edgeColors[nextNode]; // Update previous color
//                    }
//                }

//                // Calculate the total cost including color change cost and distance
//                totalCost += distances[end] * 3267;
//                cout << "Total Cost = " << totalCost - ((distance-1)*3267)<< " Tomans" << endl;
//                output += "\nTotal Cost = " + to_string(totalCost) + to_string((distance-1)*3267)+  " Tomans";
//                QListWidgetItem* item = new QListWidgetItem();
//                item->setText(QString::fromStdString(output));

//                return path;

//            }

//            for (const auto& edge : adjList[current]) {
//                if (!visited[edge.end]) {
//                    visited[edge.end] = true;
//                    q.push(edge.end);
//                    parent[edge.end] = current;
//                    edgeColors[edge.end] = edge.color;
//                    distances[edge.end] = distances[current] + edge.distance; // Update distance
//                    colorChangeCount[edge.end] = colorChangeCount[current]; // Inherit color change count
//                    if (edgeColors[edge.end] != edgeColors[current]) {
//                        colorChangeCount[edge.end]++; // Increment color change count if color changes
//                    }
//                }
//            }
//        }

//        return {}; // If no path exists
//    }



#endif // SUBWAYMANAGEMENT_H
