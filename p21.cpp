#include<bits/stdc++.h>
using namespace std;

//brute
vector<vector<int>> rotatematrix(vector < vector < int >> & matrix){
    int n = matrix.size();
    vector<vector<int>> rotated(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n-1-i] = matrix[i][j];
        }
    }
    return rotated;
}

//optimal
vector<vector<int>> rotateMatrix(vector < vector < int >> & matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    
    return matrix;
}

int main(){
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = rotatematrix(arr);
    cout << "Rotated Image : " << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout <<endl;
    }
    return 0;
}