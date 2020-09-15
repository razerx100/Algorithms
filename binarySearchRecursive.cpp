#include<iostream>
using namespace std;
int binary_search(int* data, int start, int end, int item){
    int mid = (start + end) / 2;
    if(start > end){
        return - 1;
    }
    else if(data[mid] == item){
        return mid;
    }
    else if(data[mid] > item){
        return binary_search(data, start, mid - 1, item);
    }
    else{
        return binary_search(data, mid + 1, end, item);
    }
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
    int position = binary_search(data, 0, size - 1, item);
    if(position == -1){
        cout << "Item " << item << " couldn't be found.";
    }
    else{
        cout << "Item " << item << " is found at position " << position << ".";
    }
    return 0;
}