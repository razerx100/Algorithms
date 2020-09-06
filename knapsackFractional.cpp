#include<iostream>
using namespace std;
struct Value{
    int value;
    int old_pos;
};
void print_array(int size, Value* data){
    cout << data[0].value;
    for(int i = 1; i < size; i++){
        cout << ", " << data[i].value;
    }
    cout << "\n";
}
void sort_old_position(float* solutions, Value* weight, int size){
    float new_solutions[size];
    for(int i = 0; i < size; i++){
        new_solutions[weight[i].old_pos] = solutions[i];
    }
    for(int i = 0; i < size; i++){
        solutions[i] = new_solutions[i];
    }
}
void knapsack(int size, int objects_number, Value* weight, Value* profit){
    float solutions[objects_number], SIZE = size;
    for(int i = 0; i < objects_number; i++){
        solutions[i] = 0.0f;
    }
    int i;
    for(i = 0; i < objects_number; i++){
        if(weight[i].value > SIZE){
            break;
        }
        else{
            solutions[i] = 1.0f;
            SIZE -= weight[i].value;
        }
    }
    if(i <= objects_number){
        solutions[i] = SIZE / weight[i].value;
    }
    float sum_of_weight = 0.0, sum_of_profits = 0.0;
    for(int i = 0; i < objects_number; i++){
        sum_of_weight += solutions[i] * weight[i].value;
        sum_of_profits += solutions[i] * profit[i].value;
    }

    sort_old_position(solutions, weight, objects_number);
    cout << "Fractions : ";
    cout << solutions[0];
    for(int i = 1; i < objects_number; i++){
        cout << ", " << solutions[i];
    }
    cout << "\nSum of profits : " << sum_of_profits << "\n";
    cout << "Sum of weights : " << sum_of_weight << "\n";
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sort(int size, Value* data1, Value* data2){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            float first_comp = (float)data1[j].value / data2[j].value, second_comp = (float)data1[j + 1].value / data2[j + 1].value;
            if(first_comp < second_comp){
                swap(data1[j], data1[j + 1]);
                swap(data2[j], data2[j + 1]);
            }
        }
    }
}
void input_values(Value* data, int size){
    for(int i = 0; i < size; i++){
        cin >> data[i].value;
        data[i].old_pos = i;
    }
}
int main(){
    cout << "Write objects number : ";
    int number;
    cin >> number;
    cout << "Write knapsack weight limit : ";
    int limit;
    cin >> limit;
    Value p[number], w[number];
    cout << "Write profit values : ";
    input_values(p, number);
    cout << "Write weight values : ";
    input_values(w, number);
    cout << "Profits : ";
    print_array(number, p);
    cout << "Weights : ";
    print_array(number, w);
    sort(number, p, w);
    knapsack(limit, number, w, p);
    return 0;
}