#include "cyberpunk.hpp"
using namespace std;


void printCombinations(const vector<vector<pair<int, int>>>& combinations, const vector<vector<string>>& matrix) {
    for (const auto& combo : combinations) {
        for (const auto& p : combo) {
            cout << matrix[p.first][p.second] << " ";
        }
        cout << endl;
    }
}

vector<string> pathToSequence (vector<pair<int,int>> path, vector<vector<string>> matrix){
    vector<string> sequence;
    path.shrink_to_fit();
    for (int i = 0 ; i < path.size() ; i++){
        int row = path[i].first;
        int col = path[i].second;
        sequence.emplace_back(matrix[row][col]);
    }
    return sequence;

    
}

int sequence_to_point(vector<string> sequence ,vector<vector<string>> sequences , vector<int> points){
    int has_visited[points.size()];
    int total_points = 0;
    for (int i  = 0 ; i < points.size() ; i++){
        has_visited[i] = 0;
    }
    for (int seq = 0 ; seq < sequence.size(); seq++){
        for (int k = 0 ; k < points.size() ; k++){
            if (sequence[seq] == sequences[k][0] && ! has_visited[k]){
                bool valid = true;
                for (int l = 1 ; l < sequences[k].size(); l++){
                    if (sequence[seq + l] != sequences[k][l]){
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    total_points += points[k];
                    has_visited[k] = 1;
                }
            }
        }
    }
    return total_points;
}



void next_choice(int curr_row, int curr_col, int row_matrix, int col_matrix, bool row_search,int buffer, vector<pair<int, int>>& path , int* curr_max_point, vector <pair<int,int>>& curr_max_combination,vector <vector <pair<int,int>>>& all_combinations, const vector<vector<string>> sequence, const vector<int> points ){
    if (row_search){
        for (int next_col = 0 ; next_col < col_matrix ; ++next_col){
            if (next_col != curr_col){
                vector<pair<int, int>> new_path = path;
                new_path.emplace_back(curr_row,next_col);
                if (new_path.size() == buffer){
                    all_combinations.push_back(new_path);
                }
                else{
                    next_choice(curr_row,next_col,row_matrix,col_matrix,!row_search,buffer,new_path,curr_max_point,curr_max_combination,all_combinations,sequence,points);
                }
            }
        }
    }
    else{
        for (int next_row = 0 ; next_row < row_matrix ; ++next_row){
            if (next_row != curr_row){
                vector<pair<int, int>> new_path = path;
                new_path.emplace_back(next_row,curr_col);
                if (new_path.size() == buffer){
                    all_combinations.push_back(new_path);
                }
                else{
                    next_choice(next_row,curr_col,row_matrix,col_matrix,!row_search,buffer,new_path,curr_max_point,curr_max_combination,all_combinations,sequence,points);
                }
            }
        }
    }
}
vector <vector <pair<int,int>>> allCombinatations( vector<vector<string>> sequence,vector<int> points,vector<vector<string>> matrix, int* curr_max_point, vector <pair<int,int>>& curr_max_combination,int buffer){
    int row = matrix.size();
    int col = matrix[0].size();
    vector <vector <pair<int,int>>> all_combinations;
    for (int top_col = 0 ; top_col < col ; ++top_col){
        vector<pair<int, int>> path = {{0, top_col}};
        next_choice(0,top_col,row,col,false,buffer,path,curr_max_point,curr_max_combination,all_combinations,sequence,points);
    }
    return all_combinations;  
}

int count_points();