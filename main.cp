



#include "mainwindow.h"
#include "subwaymanagement.h"
#include <QApplication>

void Menu(){

    Graph g(3267);

    // Add edges with colors
    g.addEdge("Tajrish","Gheytariyeh","red",2, 3267);
    g.addEdge("Gheytariyeh","Gholhak","red",3, 3267);
    g.addEdge("Gholhak", "Mirdamad","red",4, 3267);
    g.addEdge("Mirdamad", "Shahid Haghani","red",5, 3267);
    g.addEdge("Shahid Haghani","Shahid Beheshti","red",7, 3267);
    g.addEdge("Shahid Beheshti","Shahid Mofatteh","red",2, 3267);
    g.addEdge("Shahid Mofatteh","Haftom-e Tir","red",2, 3267);

    g.addEdge("Haftom-e Tir","Taleghani","red",2, 3267);
    g.addEdge("Taleghani","Darvazeh Dowlat","red",1, 3267);
    g.addEdge("Darvazeh Dowlat ","Panzdah-e Khordad ","red",4, 3267);
    g.addEdge("Panzdah-e Khordad","Shoush","red",6, 3267);
    g.addEdge("Shoush","Jonoub Terminal","red",3, 3267);
    g.addEdge("Jonoub Terminal","Shahr-e Rey","red",9, 3267);
    g.addEdge("Shahr-e Rey","Kahrizak","red",13, 3267);

    g.addEdge("Gha'em Aghdasiyeh","Aghdasiyeh","blue",4, 3267);
    g.addEdge("Aghdasiyeh","Shahid Zeynoddin","blue",10, 3267);
    g.addEdge("Shahid Zeynoddin","Shahid Ghodousi","blue",5, 3267);
    g.addEdge("Shahid Ghodousi","Sohrevardi","blue",2, 3267);
    g.addEdge("Sohrevardi","Shahid Beheshti","blue",1, 3267);
    g.addEdge("Shahid Beheshti","Merza-ye Shirazi","blue",3, 3267);
    g.addEdge("Merza-ye Shirazi","Meydan-e Jahad","blue",2, 3267);
    g.addEdge("Meydan-e Jahad","Meydan-e Hazrat-e ValiAsr","blue",1, 3267);
    g.addEdge("Meydan-e Hazrat-e ValiAsr","Teatr-e Shahr","blue",2, 3267);
    g.addEdge("Teatr-e Shahr","Moniriyeh","blue",4, 3267);
    g.addEdge("Moniriyeh","Mahdiyeh","blue",3, 3267);
    g.addEdge("Mahdiyeh","Rahahan","blue",1, 3267);
    g.addEdge("Rahahan","Javadiyeh","blue",2, 3267);
    g.addEdge("Javadiyeh","Zamzam","blue",2, 3267);
    g.addEdge("Zamzam","Azadegan","blue",8, 3267);

    g.addEdge("Shahid Kolahdouz","Nirou Havaei","yellow",7, 3267);
    g.addEdge("Nirou Havaei","Nabard","yellow",1, 3267);
    g.addEdge("Nabard","Pirouzi","yellow",1, 3267);
    g.addEdge("Pirouzi","Ebn-e Sina","yellow",3, 3267);
    g.addEdge("Ebn-e Sina","Meydan-e Shohada","yellow",1, 3267);
    g.addEdge("Meydan-e Shohada","Darvazeh Shemiran","yellow",2, 3267);
    g.addEdge("Darvazeh Shemiran","Darvazeh Dowlat","yellow",2, 3267);
    g.addEdge("Darvazeh Dowlat","Ferdowsi","yellow",1, 3267);
    g.addEdge("Ferdowsi","Teatr-e Shahr","yellow",1, 3267);
    g.addEdge("Teatr-e Shahr","Meydan-e Enghelab-e Eslami","yellow",3, 3267);
    g.addEdge("Meydan-e Enghelab-e Eslami","Towhid","yellow",1, 3267);
    g.addEdge("Towhid","Shademan","yellow",2, 3267);
    g.addEdge("Shademan","Ostad Mo'in","yellow",4, 3267);
    g.addEdge("Ostad Mo'in","Meydan-e Azadi","yellow",2, 3267);
    g.addEdge("Meydan-e Azadi","Eram-e Sabz","yellow",6, 3267);
    g.addEdge("Eram-e Sabz","Allameh Jafari","yellow",5, 3267);
    g.addEdge("Allameh Jafari","Kashani","yellow",4, 3267);
    g.addEdge("Kashani","Chaharbagh","yellow",5, 3267);

    g.addEdge("Haram-e Hazrat-e Abdolazim","Shahid Rezaei","purple",10, 3267);
    g.addEdge("Shahid Rezaei","Meydan-e Shohada","purple",6, 3267);
    g.addEdge("Meydan-e Shohada","Emam Hossein","purple",2, 3267);
    g.addEdge("Emam Hossein","Haftom-e Tir","purple",5, 3267);
    g.addEdge("Haftom-e Tir","Meydan-e Hazrat-e ValiAsr","purple",2, 3267);
    g.addEdge("Meydan-e Hazrat-e ValiAsr","Boostan-e laleh","purple",2, 3267);
    g.addEdge("Boostan-e laleh","Yadegar-e Emam","purple",8, 3267);
    g.addEdge("Yadegar-e Emam","Kashani","purple",6, 3267);
    g.addEdge("Kashani","Kouhsar","purple",10, 3267);


    Graph busGraph(2250);
    busGraph.addEdge("Khajeh Abdollah-e Ansari","Gha'em","green",12, 2250);
    busGraph.addEdge("Gha'em","Pirouzi","green",19, 2250);
    busGraph.addEdge("Pirouzi","Shahid Rezaei","green",8, 2250);
    busGraph.addEdge("Shahid Rezaei","Payaneh Javanmard","green",8, 2250);

    busGraph.addEdge("Shahid Sadr","Tajrish","grey",4, 2250);
    busGraph.addEdge("Tajrish","Mirdamad","grey",8, 2250);
    busGraph.addEdge("Mirdamad","Meydan-e Hazrat-e ValiAsr","grey",11, 2250);
    busGraph.addEdge("Meydan-e Hazrat-e ValiAsr","Rahahan","grey",8, 2250);
    busGraph.addEdge("Rahahan","Shahrak-e Shari'ati","grey",5, 2250);

    busGraph.addEdge("Tehran Pars","Ebn-e Sina","green",10, 2250);
    busGraph.addEdge("Ebn-e Sina","Emam Hossein","green",4, 2250);
    busGraph.addEdge("Emam Hossein","Darvazeh Dowlat","green",2, 2250);
    busGraph.addEdge("Darvazeh Dowlat","Ferdowsi","green",1, 2250);
    busGraph.addEdge("Ferdowsi","Meydan-e Enghelab-e Eslami","green",3, 2250);
    busGraph.addEdge("Meydan-e Enghelab-e Eslami","Ostad Mo'in","green",4, 2250);
    busGraph.addEdge("Ostad Mo'in","Meydan-e Azadi","green",4, 2250);
    busGraph.addEdge("Meydan-e Azadi","Bimeh","green",3, 2250);


    QString start = "Mirdamad";
    QString end = "Moniriyeh";

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




}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);




    return a.exec();
}







