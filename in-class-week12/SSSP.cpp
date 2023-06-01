#include<bits/stdc++.h>

using namespace std;

struct City { // this struct is to store cities
    int label;
    int distance;

    City(int l, int d){
        label = l;
        distance = d;
    }
};

City ExtractMin(vector<City> &Q){ // output the city with minimum distance from starting city
    int size = Q.size();
    for(int j = 0; j < size; j++){
        if(Q[size - 1].distance > Q[j].distance ){ // if minimum is in mid of the vector swap it with last element
            City temp = Q[j];
            Q[j] = Q[size - 1];
            Q[size - 1] = temp;
        }
    }
    City city = Q[size - 1];
    Q.pop_back();
    return city;
}

void Relax(int current_city, int neighbor_city, int distance, vector<int> &distances, vector<City> &Q){

    if(distances[current_city] + distance < distances[neighbor_city]){ // assign new distance if it is lower than previous one
        distances[neighbor_city] = distances[current_city] + distance;
        Q.push_back(City(neighbor_city, distances[neighbor_city]));
    }
}

vector<int> Dijkstra(int n, vector<vector<int>>& graph, int s) {

    vector<int> distances(n, INT16_MAX); // create distance vector with maximum value

    vector<City> Q; // tempory queue for store cities

    distances[s] = 0;
    Q.push_back(City(s, 0));

    while (!Q.empty()) {

        City city = ExtractMin(Q);
        int current_city = city.label;

        for (int i = 0; i < n; ++i) {
            if (graph[current_city][i] != 0) { // only check cities that connect with currrent city
                Relax(current_city, i, graph[current_city][i], distances, Q);
            }
        }
    }

    return distances;
}

int main(){

    vector<vector<int>> graph = { // given graph
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int n = 6;
    
    for(int i = 0; i < n; i++){
        float avg_distance = 0;
        vector<int> distances = Dijkstra(n, graph, i);
        for(int j = 0; j < n; j++){
            avg_distance += distances[j];
            cout << "Distance from city " << i << " to city " << j << " : " << distances[j] << endl;
        }
        cout << "Avarage Distance : " << avg_distance / (n-1) << endl << endl;
    } 
}