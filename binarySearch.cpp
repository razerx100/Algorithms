#include<iostream>
using namespace std;
class binarySearch{
    int **data;
    int *size;
    int recurs(int low, int high, int item);
    void print(int *location, int *check, int *item);
    public:
    binarySearch(int **data, int *size) : data(data) , size(size) { }
    void iterative(int *item);
    void recursive(int *item);
};
int main(){
    cout << "Array size : ";
    int size;
    cin >> size;
    int *data = new int(size);
    cout << "Array data : ";
    for(int i = 0; i < size; i++){
        cin >> data[i];
    }
    binarySearch bs = binarySearch(&data, &size);
    cout << "Item to find : ";
    int item;
    cin >> item;
    bs.iterative(&item);
    // bs.recursive(&item);
    return 0;
}
void binarySearch::iterative(int *item){
    int low = 0, high = *size - 1, mid;
    int location = -1;
    while(low <= high){
        mid = (low + high) / 2;
        location = ((mid - location) * ((*data)[mid] == *item)) + location;
        low = ((mid + 1 - low) * ((*data)[mid] < *item)) + low + ((high + 1 - low) * ((*data)[mid] == *item));
        high = ((mid - 1 - high) * ((*data)[mid] > *item)) + high;
    }
    int check = (-1 * (location + 1 == 0)) + 2;
    print(&location, &check, item);
}
void binarySearch::print(int *location, int *check, int *item){
    string ite = to_string(*item);
    string messages[] = {"", ite + " couldn't be found.", ite + " found at location " + to_string(*location)};
    cout << messages[*check];
}