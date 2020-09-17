#include<iostream>
using namespace std;

void interchange(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int partition(int *data, int start, int end){
    int first_element = data[start], start_var = start + 1, end_var = end - 1;
    while(start_var < end_var) {
        while(data[start_var] < first_element){
            start_var++;
        }
        while(data[end_var] > first_element){
            end_var--;
        }
        if(start_var < end_var){
            interchange(data[start_var], data[end_var]);
        }
    }
    data[start] = data[end_var];
    data[end_var] = first_element;
    return end_var;
}

void qucik_sort(int* data, int start, int end){
    if(start < end){
        int partition_value = partition(data, start, end + 1);
        qucik_sort(data, start, partition_value - 1);
        qucik_sort(data, partition_value + 1, end);
    }
}

int main(){
    cout << "Write array size : ";
    int size;
    cin >> size;
    int data[size];
    cout << "Write the array items : ";
    for(int i = 0; i < size; i++){
        cin >> data[i];
    }
    qucik_sort(data, 0, size - 1);
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    return 0;
}