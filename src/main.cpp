#include <iostream>
#include "cyberpunk.hpp"
#include <vector>
using namespace std;



int main(){
    vector<string> tokens = {"1","2","3","4","5","6","7","8","9","10","11","12"};
    vector<vector<string>> sequences = {{"BD", "E9","1C"}, {"BD","7A","BD"}, {"BD","1C","BD","55"}};
    vector<int> points = {15,20,30};
    vector<vector<string>> matrix = {
        {"7A","55","E9","E9","1C","55"},
        {"55","7A","1C","7A","E9","55"},
        {"55","1C","1C","55","E9","BD"},
        {"BD","1C","7A","1C","55","BD"},
        {"BD","55","BD","7A","1C","1C"},
        {"1C","55","55","7A","55","7A"}
    };
    vector<vector<pair<int, int>>> all_combo;
    vector <pair<int,int>> curr_max_combination;
    int curr_max_point = -1;
    all_combo = allCombinatations(sequences,points,matrix,&curr_max_point,curr_max_combination,7);
    cout << all_combo.size();
    vector<string> sequence = {"7A", "BD", "7A", "BD" ,"1C" ,"BD", "55"};
    int total_points = sequence_to_point(sequence,sequences,points);
    cout << endl << total_points << endl;
    // printCombinations(all_combo,matrix);
    
    return 0;
}