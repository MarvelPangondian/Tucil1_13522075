#include <iostream>
#include <string>
#include <vector>
using namespace std;

void next_choice(int curr_row, int curr_col, int row_matrix, int col_matrix, bool row_search,int buffer, vector<pair<int, int>>& path , int* curr_max_point, vector <vector <pair<int,int>>>& curr_max_combination,vector <vector <pair<int,int>>>& all_combinations );

vector <vector <pair<int,int>>> allCombinatations(vector<vector<string>> matrix, int* curr_max_point, vector <vector <pair<int,int>>>& curr_max_combination,int buffer);


