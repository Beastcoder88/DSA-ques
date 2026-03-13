#include<bits/stdc++.h>
using namespace std;

// brute
int Largest(int arr[],int n){
    sort(arr,arr+n);
    return arr[n-1];
}

// optimal
int largest(int arr[],int n){
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>largest){
            largest = arr[i];
        } 
    }
    return largest;
}

//brute
int secondlargest(int arr[],int n){
    sort(arr,arr+n);
    int l = arr[n-1],p;
    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i]!=l){
            p = arr[i];
            break;
        }
    }
    return p;
}

//optimal
int secondmax(int arr[],int n) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int secondsmallest(int arr[],int n){
    int smallest = INT_MAX;
    int secondmin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<smallest){
            secondmin = smallest; 
            smallest = arr[i];
        }
        else if(arr[i]<secondmin && arr[i] != smallest){
            secondmin = arr[i];
        }
    }
    return secondmin;
}


int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<Largest(a,n);
    cout<<endl;  
    cout<<secondlargest(a,n);
    cout<<endl; 
    cout<<secondsmallest(a,n);
    return 0;
}