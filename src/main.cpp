#include <iostream>
#include <vector>
using namespace std;



int main(){
    vector<string> tokens = {"BD","E9","1C","7A","55"};
    vector<vector<string>> sequence = {{"BD", "E9","1C"}, {"BD","7A","BD"}, {"BD","1C","BD","55"}};
    vector<int> point = {15,20,30};
    vector<vector<string>> matrix = {{"7A","55","E9","E9","1C","55"}, {"55","7A","1C","7A","E9","55"} };
    cout << "hello" << endl;
    return 0;
}