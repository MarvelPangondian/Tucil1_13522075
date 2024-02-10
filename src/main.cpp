#include <iostream>
#include <vector>
#include <chrono>
#include <chrono>
#include "cyberpunk.hpp"
#include "IO.hpp"
using namespace std;


int main(){

    int input = -1;
    while (input != 3){
        vector<vector<string>> sequences;
        vector<vector<string>> matrix;
        vector<int> points;
        int curr_max_point = -2147483640, buffer;
        vector <pair<int,int>> curr_max_combination;
        display_menu(&input);
        switch(input){
            case(1):
            {
                readFile(sequences ,matrix, points, &buffer);
                auto start = chrono::high_resolution_clock::now(); // start timer
                vector<vector<pair<int, int>>> allCombinations = allCombinatations(sequences,points,matrix,&curr_max_point,curr_max_combination,buffer);
                auto end = chrono::high_resolution_clock::now();// end timer
                auto elapsed = chrono::duration_cast<std::chrono::milliseconds>(end - start); 
                
                displayResult(curr_max_point,curr_max_combination,matrix,elapsed.count());
                break;
            }
            case(2):
            {
                randomInput(sequences ,matrix, points, &buffer);
                cout << endl;
                printMatrix(matrix);
                cout << endl;
                printSequences(sequences,points);
                cout << endl;
                auto start = chrono::high_resolution_clock::now(); // start timer
                vector<vector<pair<int, int>>> allCombinations = allCombinatations(sequences,points,matrix,&curr_max_point,curr_max_combination,buffer);
                auto end = chrono::high_resolution_clock::now();// end timer
                auto elapsed = chrono::duration_cast<std::chrono::milliseconds>(end - start); 
                displayResult(curr_max_point,curr_max_combination,matrix,elapsed.count());
                break;
            }
        }
            

    }

    return 0;
}