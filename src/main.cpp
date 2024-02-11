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
                if (! readFile(sequences ,matrix, points, &buffer)){
                    break;
                }
                auto start = chrono::high_resolution_clock::now(); // start timer
                allCombinatations(sequences,points,matrix,&curr_max_point,curr_max_combination,buffer);
                auto end = chrono::high_resolution_clock::now();// end timer
                auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start); 
                
                displayResult(curr_max_point,curr_max_combination,matrix,elapsed.count());
                break;
            }
            case(2):
            {
                if (! randomInput(sequences ,matrix, points, &buffer)){
                    break;
                }
                cout << endl;
                printMatrix(matrix);
                cout << endl;
                printSequences(sequences,points);
                cout << endl;
                auto start = chrono::high_resolution_clock::now(); // start timer
                allCombinatations(sequences,points,matrix,&curr_max_point,curr_max_combination,buffer);
                auto end = chrono::high_resolution_clock::now();// end timer
                auto elapsed = chrono::duration_cast<std::chrono::milliseconds>(end - start); 
                displayResult(curr_max_point,curr_max_combination,matrix,elapsed.count());
                break;
            }
        }
            

    }

    return 0;
}