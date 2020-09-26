#include<iostream>
using namespace std;
void maxMin(int* data, int start, int end, int& max, int& min){
    if(start == end)
        max = min = data[start];
    else if(start == end - 1){
        if(data[start] < data[end]){
            max = data[end];
            min = data[start];
        }
        else{
            max = data[start];
            min = data[end];
        }
    }
    else{
        int mid = (start + end) / 2;
        maxMin(data, start, mid, max, min);
        int max1, min1;
        maxMin(data, mid + 1, end, max1, min1);
        if(max < max1)
            max = max1;
        if(min > min1)
            min = min1;
    }
}
int main(){
    cout << "Write the size of array : ";
    int size;
    cin >> size;
    int data[size];
    cout << "Write the elements : ";
    for(int i = 0; i < size; i++)
        cin >> data[i];
    int max, min;
    maxMin(data, 0, size - 1, max, min);
    cout << "Maximum number is " << max << " and minimum number is " << min << ".";
    return 0;
}