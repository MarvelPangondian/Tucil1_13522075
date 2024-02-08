#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <random>
using namespace std;

void displayResult(int curr_max_point, vector<pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time);
void printPath(vector<pair<int, int>> path);
void printSequence(vector<string> sequence);
void printMatrix(const vector<vector<string>> matrix);
void printSequences(vector<vector<string>> sequences, vector<int> points);
string removeNewLine(string line);
vector<string> stringSeperator(string sentence);
void display_menu(int* input);
void randomInput(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer);
void readFile(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer );


