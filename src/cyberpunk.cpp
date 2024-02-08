#include "cyberpunk.hpp"
using namespace std;




void next_choice(int curr_row, int curr_col, int row_matrix, int col_matrix, bool row_search,int buffer, vector<pair<int, int>>& path , int* curr_max_point, vector <vector <pair<int,int>>>& curr_max_combination,vector <vector <pair<int,int>>>& all_combinations ){
    if (row_search){
        for (int next_col = 0 ; next_col < col_matrix ; ++next_col){
            if (next_col != curr_col){
                vector<pair<int, int>> new_path = path;
                new_path.emplace_back(curr_row,next_col);
                if (new_path.size() == buffer){
                    all_combinations.push_back(new_path);
                }
                else{
                    next_choice(curr_row,next_col,row_matrix,col_matrix,!row_search,buffer,new_path,curr_max_point,curr_max_combination,all_combinations);
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
                    next_choice(next_row,curr_col,row_matrix,col_matrix,!row_search,buffer,new_path,curr_max_point,curr_max_combination,all_combinations);
                }
            }
        }
    }
}
vector <vector <pair<int,int>>> allCombinatations(vector<vector<string>> matrix, int* curr_max_point, vector <vector <pair<int,int>>>& curr_max_combination,int buffer){
    int row = matrix.size();
    int col = matrix[0].size();
    vector <vector <pair<int,int>>> all_combinations;
    for (int top_col = 0 ; top_col < col ; ++top_col){
        vector<pair<int, int>> path = {{0, top_col}};
        next_choice(0,top_col,row,col,false,buffer,path,curr_max_point,curr_max_combination,all_combinations);
    }
    return all_combinations;
    
    
}