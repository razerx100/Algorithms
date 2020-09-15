#include<iostream>
using namespace std;
int binary_search(int* data, int size, int item){
    int start = 0, end = size - 1, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(data[mid] == item){
            return mid;
        }
        else if(data[mid] > item){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}
int main(){
    cout << "Write the array size : ";
    int size;
    cin >> size;
    int data[size];
    cout << "Write values : ";
    for(int i = 0; i < size; i++){
        cin >> data[i];
    }
    cout << "Write the wanted item : ";
    int item;
    cin >> item;
    int position = binary_search(data, size, item);
    if(position == -1){
        cout << "Item " << item << " couldn't be found.";
    }
    else{
        cout << "Item " << item << " is found at position " << position << ".";
    }
    return 0;
}