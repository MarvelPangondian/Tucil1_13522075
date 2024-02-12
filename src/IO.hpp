#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
using namespace std;

bool areTokensUnique(vector<string> tokens);
    // check if all tokens are unique
void displayResult(int curr_max_point, vector<pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time);
    // Display final result
void printPath(vector<pair<int, int>> path);
    // display path (coordinates of each token in said path)
void printSequence(vector<string> sequence);
    // Display sequence 
void printMatrix(const vector<vector<string>> matrix);
    // Display matrix
void printSequences(vector<vector<string>> sequences, vector<int> points);
    // Display sequences and each of their points
string removeNewLine(string line);
    // remove new line in a string
vector<string> stringSeperator(string sentence);
    // Seperate string with " " as the delimeter
void display_menu(int* input);
    // Display menui (options the user can choose)
bool randomInput(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer);
    // Menu if user wants to automatically create matrix, sequences, and points
bool readFile(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer );
    // read .txt file
void write_file(int curr_max_point, vector <pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time);
    // write results to a txt file

