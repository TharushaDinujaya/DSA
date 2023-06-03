#include<bits/stdc++.h>

using namespace std;

struct Street { // for store each street as a node
    int next_pole; // ending Pole
    int distance; // distance between two poles
    int current_pole; // strating pole

    Street(int a, int b, int c){ // initializing
        next_pole = a;
        distance = b;
        current_pole = c;
    }
};

Street ExtractMin(vector<Street> &Q){ 
    int n = Q.size();

    for(int j = 0; j < n; j++){ // arrange minimum weight street to the last
        if(Q[n - 1].distance > Q[j].distance ){ 
            Street temp = Q[j];
            Q[j] = Q[n - 1];
            Q[n - 1] = temp;
        }
    }

    Street pole = Q[n - 1];
    Q.pop_back();
    return pole;
}

vector<Street> primAlgorithm(vector<vector<int>>& graph, int start) {
    int n = graph.size();

    vector<Street> mst;
    vector<bool> visited(n, false); // for checking if the pole is visited or not

    vector<Street> Q;
    Q.push_back(Street(start, 0, start));

    while (!Q.empty()) {

        Street currentPole = ExtractMin(Q);
        
        int next_pole = currentPole.next_pole;

        if ( !visited[next_pole]){

            visited[next_pole] = true;
            int distance = currentPole.distance;

            if(distance != 0){ // no streets with zero distance
                mst.push_back(Street(next_pole, distance, currentPole.current_pole));
            }

            for(int i = 0; i < n; i++){
                if (graph[next_pole][i] != 0){ // if there is a street from considering Pole to other street
                    if(!visited[i]){ // if that pole is not visited before
                        Q.push_back(Street(i, graph[next_pole][i], next_pole));
                    }
                    
                }
            }
        }
    }
    return mst;
}

void print(vector<Street> arr){ // for printing purposes of MST
    cout << "Edge \t Distance" << endl;
    for(Street i : arr){
        cout << i.current_pole << " - "  << i.next_pole << " \t: " << i.distance <<endl;
    }
}

int main(){
    vector<vector<int>> graph { // adjacency matrix of given graph
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };
    vector<Street> arr = primAlgorithm(graph, 3); // get MST from Pole 3
    print(arr); //print MST
}