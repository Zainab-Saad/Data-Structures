#include<iostream>
using namespace std;
# define V 5
bool isCycleDetected(int endVertex, int visitedVertices[V]){
    for(int i = 0; i < V; i++){
        if (visitedVertices[i] == endVertex)
            return true;
    }
    return false;
}

int** primsMST(int vertices[V], int edges[V][V]){
    // takes as input the vertices and edges array
    int minCost = 0;
    int** edgesMST = new int*[V];
    int visitedVerticesIndexes[V];
    bool visitedEdges[V][V];

    // initialize the values in the declared arrays
    for(int i = 0; i < V; i++){
        visitedVerticesIndexes[i] = -1;
        edgesMST[i] = new int[V];
        for(int j = 0; j < V; j++){
            edgesMST[i][j] = 0;
            visitedEdges[i][j] = false;
        }
    }

    // pick any random vertex to start from
    visitedVerticesIndexes[0] = 0;

    // run a loop to find V-1 edges of the MST

    for(int count = 0; count < V-1; count++){
        int x = 0, j = 0, min = INT_MAX, index1, index2;
        // find the minimum edge in this loop by looping through all the vertices present in the MST
        while(visitedVerticesIndexes[x] != -1){
            
            // for each vertex in MST try to find the min edge connecting to any other vertex but not forming cycle
            for(j = 0; j < V; j++){
                if(visitedVerticesIndexes[x] == 1 && count == 3){
                    cout<<"hello"<<endl;
                    cout<<(edges[visitedVerticesIndexes[x]][j] != 0)<<endl;
                    cout<<!visitedEdges[visitedVerticesIndexes[x]][j]<<endl;
                    cout<<(edges[visitedVerticesIndexes[x]][j] <= min)<<endl;
                    cout<<!isCycleDetected(j, visitedVerticesIndexes)<<endl;
                }
                if(
                edges[visitedVerticesIndexes[x]][j] != 0 // edge exists
                && !visitedEdges[visitedVerticesIndexes[x]][j] // edge not traversed already
                && edges[visitedVerticesIndexes[x]][j] <= min
                && !isCycleDetected(j, visitedVerticesIndexes)
                )
                {
                    min = edges[visitedVerticesIndexes[x]][j];
                    index1 = visitedVerticesIndexes[x];
                    index2 = j;
                }
            }
            // minimum edge to be included in MST in this iteration found
            x++;
        }
        minCost += min;
        visitedVerticesIndexes[x] = index2;
        visitedEdges[index1][index2] = visitedEdges[index2][index1] = true;
        edgesMST[index1][index2] = edgesMST[index2][index1] = min;
    }
    cout<<minCost<<endl;
    return edgesMST;
}


int main()
{
    int vertices[V] = {1, 2, 3, 4, 5};
    int edges[V][V] = {
                {0, 2, 1, 3, 3},
                {2, 0, 2, 1, 5},
                {1, 2, 0, 3, 0},
                {3, 1, 3, 0, 4},
                {3, 5, 0, 4, 0}
                };
    int** MST = primsMST(vertices, edges);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout<<MST[i][j]<<" ";
        }
        cout<<endl;
    }       
    return 0;
}