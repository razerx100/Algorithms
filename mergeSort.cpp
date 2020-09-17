#include<iostream>
using namespace std;
void merge(int* data, int low, int mid, int high){
    int secondary_array_position = low, primary_array_low_position = low, primary_array_high_position = mid + 1;
    int secondary_array[high + 1];
    while((primary_array_low_position <= mid) and (primary_array_high_position <= high)){
        if(data[primary_array_low_position] <= data[primary_array_high_position]){
            secondary_array[secondary_array_position] = data[primary_array_low_position];
            primary_array_low_position++;
        }
        else{
            secondary_array[secondary_array_position] = data[primary_array_high_position];
            primary_array_high_position++;
        }
        secondary_array_position++;
    }
    if(primary_array_low_position > mid){
        for(int i = primary_array_high_position; i <= high; i++){
            secondary_array[secondary_array_position] = data[i];
            secondary_array_position++;
        }
    }
    else{
        for(int i = primary_array_low_position; i <= mid; i++){
            secondary_array[secondary_array_position] = data[i];
            secondary_array_position++;
        }
    }
    for(int i = low; i <= high; i++){
        data[i] = secondary_array[i];
    }
}
void merge_sort(int* data, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        merge_sort(data, low, mid);
        merge_sort(data, mid + 1, high);
        merge(data, low, mid, high);
    }
}
int main(){
    cout << "Write the array size : ";
    int size;
    cin >> size;
    int data[size];
    cout << "Write the array elements : ";
    for(int i = 0; i < size; i++){
        cin >> data[i];
    }
    merge_sort(data, 0, size - 1);
    cout << "Sorted array : ";
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    return 0;
}