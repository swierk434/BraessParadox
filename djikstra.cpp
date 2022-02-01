#include <iostream>
#include "Road.h"
#include "Out.h"

using namespace std;

bool finished(bool *tab, int n){
    for(int x = 0; x < n; x++) {
        if (tab[x]==false) {
            return false;
        }
    }
    return true;
}

void Djikstra(Out *out , int n, Road **graph, int start){
    //cout << "start" << endl;
    bool *visited = new bool[n];
    int actual = start, index;
    double tmp, min = 0;
    for(int x = 0; x < n; x++){
        visited[x] = false;
    }
    out[actual].distance = 0;
    out[actual].prev = actual;
    //cout << "start" << endl;
    while(finished(visited, n)==false){
        tmp = 100000;
        index = actual;
        for(int x = 0; x < n; x++){
            if(graph[actual][x].travel_time() != -1 ){
                if(graph[actual][x].travel_time() + out[actual].distance < out[x].distance){
                    out[x].prev = actual;
                    out[x].distance = graph[actual][x].travel_time() + out[actual].distance;
                    //cout << out[x].prev << " " << out[x].distance << endl;
                }
            }
        }
        //for(int i = 0; i < n; i++){
        //cout << endl << setw(2) << i << ":" << setw(4) << out[i].distance << setw(4) << out[i].prev;
        //}
        visited[actual] = true;

        for(int x = 0; x < n; x++){
             if(out[x].distance < tmp && visited[x] == false){
                 tmp = out[x].distance;
                 index = x;
             }   
        }
        //cout << index << endl;
        actual = index;
    }
}

void add_car_on_shortest_path(Out *out, Road **graph, int start, int end){
    int tmp = end;
    while(tmp != start){
        //cout << tmp << " ";
        graph[tmp][out[tmp].prev].car_number++;
        graph[out[tmp].prev][tmp].car_number++;
        //cout << graph[out[tmp].prev][tmp].travel_time()  << "   ";
        tmp = out[tmp].prev;
    }

}