#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <random>

void printMatrix(const vector<vector<string>> matrix);
void printSequences(vector<vector<string>> sequences, vector<int> points);
string removeNewLine(string line);
vector<string> stringSeperator(string sentence);
void display_menu(int* input);
void randomInput(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer);
void readFile(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer );


