#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;

    // Dynamically allocating memory for cost matrix
    int **cost = new int*[n];
    for (int i = 0; i < n; ++i) {
        cost[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cost[i][j] = 0; // Initializing all elements to 0
        }
    }

    cout << "\nEDGES :\n";
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        if (i >= 0 && i < n && j >= 0 && j < n) {
            cost[i][j] = 1;
            cost[j][i] = 1;
        } else {
            cout << "Invalid vertex! Please enter again." << endl;
            --k; // Decrementing k to re-ask for the same input
        }
    }

    cout << "The adjacency matrix of the graph is : " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        delete[] cost[i];
    }
    delete[] cost;

    return 0;
}
