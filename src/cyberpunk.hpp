#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <vector <pair<int,int>>> allCombinatations( const vector<vector<string>>& sequence, const vector<int>& points, const vector<vector<string>>& matrix, int* curr_max_point, vector <pair<int,int>>& curr_max_combination,int buffer);
    // find all possible combinations in a given matrix, restricted to the buffer with a certain patter (horizontal, vertical, horizontal, vertical, ...)
void next_choice(int curr_row, int curr_col, int row_matrix, int col_matrix, bool row_search,int buffer, vector<pair<int, int>>& path , int* curr_max_point, vector <pair<int,int>>& curr_max_combination,vector <vector <pair<int,int>>>& all_combinations, const vector<vector<string>>& sequence, const vector<int>& points , int max_points, const vector<vector<string>>& matrix,vector<vector<bool>> hasVisited, int minSeqSize);
    // find the possible next token to choose 


int sequence_to_point(const vector<string>& sequence ,const vector<vector<string>>& sequences , const vector<int>& points);
    // sum up points of a certain sequence
vector<string> pathToSequence (const vector<pair<int,int>>& path, const vector<vector<string>>& matrix);
    // change from path (vector<pair<int,int>>) into a sequence (vector<string>) 

bool pairInPath(pair<int,int> curr_coordinates, vector<pair<int,int>> path);
    // return true if pair in path, false if not

bool sequenceInSequences(vector<string> sequence, vector<vector<string>> sequences);