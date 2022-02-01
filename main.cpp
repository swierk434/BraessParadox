#include <iostream>
#include <iomanip>
#include "Road.h"
#include "Out.h"
#include "djikstra.cpp"

using namespace std;

int main()
{
    int n,m,l,i,j,v1,v2,d,type, car_number;
    double length, factor ;
    Road **A1,**A2;
    cin >> n >> m;
    cin >> l;

    Out *djikstra1;
    Out *djikstra2;

    A1 = new Road * [n];
    for(i = 0; i < n; i++){
       A1[i] = new Road [n];
    } 

    for(i = 0; i < m; i++){
        cin >> v1 >> v2 >> length >> factor >> type >> car_number;
        A1[v1][v2].length = length;
        A1[v2][v1].length = length;
        A1[v1][v2].type = type;
        A1[v2][v1].type = type;
        A1[v1][v2].car_number = car_number;
        A1[v2][v1].car_number = car_number;
        A1[v1][v2].factor = factor;
        A1[v2][v1].factor = factor;  
    }
    
    A2 = new Road * [n];
    for(i = 0; i < n; i++){
       A2[i] = new Road [n];
    } 

    for(i = 0; i < l; i++){
        cin >> v1 >> v2 >> length >> factor >> type >> car_number;
        A2[v1][v2].length = length;
        A2[v2][v1].length = length;
        A2[v1][v2].type = type;
        A2[v2][v1].type = type;
        A2[v1][v2].car_number = car_number;
        A2[v2][v1].car_number = car_number;
        A2[v1][v2].factor = factor;
        A2[v2][v1].factor = factor; 
    }
    /*
    for(i = 0; i < n; i++){
        cout << endl << setw(2) << i << ":";
        for(j = 0; j < n; j++) cout << setw(10) << A1[i][j].travel_time();
    }
    cout << endl << endl;
    for(i = 0; i < n; i++){
        cout << endl << setw(2) << i << ":";
        for(j = 0; j < n; j++) cout << setw(10)  << A2[i][j].travel_time();
    }
    cout << endl << endl;
    */
  //  for(int i = 0; i < 10000; i++){
        djikstra1 = new Out[n];
        djikstra2 = new Out[n];
        Djikstra(djikstra1, n, A1, 0);
        Djikstra(djikstra2, n, A2, 0);
        add_car_on_shortest_path(djikstra1, A1, 0, n-1);
        add_car_on_shortest_path(djikstra2, A2, 0, n-1);
        cout << i << " " << djikstra1[n-1].distance << " " << djikstra2[n-1].distance;
        cout << endl;
   // }
  
    for(int i = 0; i < n; i++){
        cout << endl << setw(2) << i << ":" << setw(4) << djikstra1[i].distance << setw(4) << djikstra1[i].prev;
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << endl << setw(2) << i << ":" << setw(4)  << djikstra2[i].distance << setw(4) << djikstra2[i].prev;
    }
     /*
    for(i = 0; i < n; i++){
        cout << endl << setw(2) << i << ":";
        for(j = 0; j < n; j++) cout << setw(8)  << A1[i][j].travel_time() << setw(4) << A1[i][j].car_number;
    }
    cout << endl << endl;
    
    for(i = 0; i < n; i++){
        cout << endl << setw(2) << i << ":";
        for(j = 0; j < n; j++) cout << setw(8) << A2[i][j].travel_time() << setw(4) << A2[i][j].car_number;
    }
    cout << endl << endl;
     */
    
   
   
    for(i = 0; i < n; i++){
        delete [] A1[i];
    } 
    delete [] A1;
    
    for(i = 0; i < n; i++){
        delete [] A2[i];
    }  
    delete [] A2;
  return 0;
}  