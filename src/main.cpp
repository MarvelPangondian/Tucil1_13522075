#include <iostream>
#include "cyberpunk.hpp"
#include "IO.hpp"
#include <vector>
using namespace std;



int main(){
    // vector<int> k1(10);
    // vector<string> tokens = {"1","2","3","4","5","6","7","8","9","10","11","12"};
    // vector<vector<string>> sequences = {{"BD", "E9","1C"}, {"BD","7A","BD"}, {"BD","1C","BD","55"}};
    // vector<vector<string>> matrix = {
    //     {"7A","55","E9","E9","1C","55"},
    //     {"55","7A","1C","7A","E9","55"},
    //     {"55","1C","1C","55","E9","BD"},
    //     {"BD","1C","7A","1C","55","BD"},
    //     {"BD","55","BD","7A","1C","1C"},
    //     {"1C","55","55","7A","55","7A"}
    // };

    // // vector<vector<string>> sequences = {{"1C","55","55"}, {"1C","55"}, {"55","BD","E9","1C"}};
    // // vector<vector<string>> matrix = {
    // //     {"1C","1C","55","E9","55"},
    // //     {"1C","1C","E9","55","55"},
    // //     {"BD","55","55","1C","BD"},
    // //     {"1C","E9","55","BD","BD"},
    // //     {"55","1C","55","E9","55"}
    // // };
    // vector<int> points = {15,20,30};
    // vector<vector<pair<int, int>>> all_combo;
    // vector <pair<int,int>> curr_max_combination;
    // int curr_max_point = -1;
    // all_combo = allCombinatations(sequences,points,matrix,&curr_max_point,curr_max_combination,7);
    // cout << "point : " << curr_max_point << endl;
    // vector<string> sequence = pathToSequence(curr_max_combination,matrix);
    // printSequence(sequence);
    // printPath(curr_max_combination);


    // // printCombinations(all_combo,matrix);
    vector<vector<string>> sequences;
    vector<vector<string>> matrix;
    vector<int> points;
    int curr_max_point = -1, buffer;
    vector <pair<int,int>> curr_max_combination;
    return 0;
}