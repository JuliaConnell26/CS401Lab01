#include <iostream>
#include <algorithm>

using namespace std;

//Structure to hold statistics on the array.
struct ArrayStats {
    double average;
    int max;
    int sum;
};

int ElementsProcessed = 0;

/*
Function: ArrayProcesser
Goal: Processes array and calculates the sum, max, and average, and tracks elements processed.
Input: Array and size
Output: Array struct with the sum, max, and average
*/
ArrayStats Arrayprocessor(int arr[], int size) {
    ArrayStats stats;
    stats.sum = 0;
    stats.max = arr[0];

    for (int i = 0; i < size; i++) {
        stats.sum += arr[i];
        if (arr[i] > stats.max) {
            stats.max = arr[i]; 
        }
    }
    stats.average = static_cast<double>(stats.sum) / size;
  
    ElementsProcessed += size;

    return stats;
}

/*
Function DisplayArray
Goal: Display Array
Input: Array and Array Size
*/
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; //Initializing Test Array
    int size = sizeof(arr) / sizeof(arr[0]); //Calculating the size
    
    cout << "Original array:" << endl;
    displayArray(arr, size); //Displaying Original Array

    ArrayStats stats = Arrayprocessor(arr, size); 

    //Displaying the max, sum, and average
    cout << "\nArray Stats:" << endl;         
    cout << "Max: " << stats.max << endl;     
    cout << "Sum: " << stats.sum << endl;
    cout << "Average: " << stats.average << endl;


    //Lambda to sort the array in descending order
    auto descendingSort = [](int a, int b) {
        return a > b;
    };

    // Usijng lambda with sort
    sort(arr, arr + size, descendingSort);

    cout << "\nDescending Order Array:" << endl;
    //Displaying the array in descending order
    displayArray(arr, size);

    //Displaying the elements processed
    cout << "\nElements Processed: " << ElementsProcessed << endl;

    return 0;
}
