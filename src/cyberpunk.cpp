#include "cyberpunk.hpp"

using namespace std;

bool sequenceInSequences(vector<string> sequence, vector<vector<string>> sequences){
    bool sequenceDuplicate = false;
    int k = 0;
    for (int i = 0 ; i < sequences.size() ; i++){
        k = 0;
        while (k < sequence.size() && sequence[k] == sequences[i][k]){
            k++;
        }
        if (k == sequence.size()){
            sequenceDuplicate = true;
            break;
        }
    }
    return sequenceDuplicate;
}

bool pairInPath(pair<int,int> curr_coordinates, vector<pair<int,int>> path){
    bool isIn = false;
    for (int i = 0 ; i < path.size() ; i++){
        if (curr_coordinates.first == path[i].first && curr_coordinates.second == path[i].second){
            isIn = true;
            break;
        }
    }
    return isIn;
}

vector<string> pathToSequence (const vector<pair<int,int>>& path, const vector<vector<string>>& matrix){
    vector<string> sequence;
    for (int i = 0 ; i < path.size() ; i++){
        int row = path[i].first;
        int col = path[i].second;
        sequence.emplace_back(matrix[row][col]);
    }
    return sequence;
}

int sequence_to_point(const vector<string>& sequence ,const vector<vector<string>>& sequences , const vector<int>& points){
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
                    if ((seq + l) >= sequence.size()){
                        valid = false;
                        break;
                    }
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

void next_choice(int curr_row, int curr_col, int row_matrix, int col_matrix, bool row_search, int buffer, vector<pair<int, int>>& path, int* curr_max_point, vector<pair<int,int>>& curr_max_combination, const vector<vector<string>>& sequence, const vector<int>& points, int max_points, const vector<vector<string>>& matrix, vector<vector<bool>>& hasVisited, int minSeqSize, vector<string>& sequence_temp) {
    if (row_search) {
        for (int next_col = 0; next_col < col_matrix; ++next_col) {
            if (next_col != curr_col && !hasVisited[curr_row][next_col]) {
                hasVisited[curr_row][next_col] = true;
                path.emplace_back(curr_row, next_col);
                sequence_temp.push_back(matrix[curr_row][next_col]);

                int temp_point = sequence_temp.size() >= minSeqSize ? sequence_to_point(sequence_temp, sequence, points) : 0;
                
                if (temp_point > *curr_max_point || (temp_point == *curr_max_point && path.size() < curr_max_combination.size())) {
                    *curr_max_point = temp_point;
                    curr_max_combination = path;
                }
                
                if (temp_point < max_points && path.size() != buffer && path.size() != row_matrix * col_matrix) {
                    next_choice(curr_row, next_col, row_matrix, col_matrix, !row_search, buffer, path, curr_max_point, curr_max_combination, sequence, points, max_points, matrix, hasVisited, minSeqSize, sequence_temp);
                }
                path.pop_back();
                sequence_temp.pop_back();
                hasVisited[curr_row][next_col] = false;
            }
        }
    } else {
        for (int next_row = 0; next_row < row_matrix; ++next_row) {
            if (next_row != curr_row && !hasVisited[next_row][curr_col]) {
                hasVisited[next_row][curr_col] = true;
                path.emplace_back(next_row, curr_col);
                sequence_temp.push_back(matrix[next_row][curr_col]);

                int temp_point = sequence_temp.size() >= minSeqSize ? sequence_to_point(sequence_temp, sequence, points) : 0;
                
                if (temp_point > *curr_max_point || (temp_point == *curr_max_point && path.size() < curr_max_combination.size())) {
                    *curr_max_point = temp_point;
                    curr_max_combination = path;
                }
                
                if (temp_point < max_points && path.size() != buffer && path.size() != row_matrix * col_matrix) {
                    next_choice(next_row, curr_col, row_matrix, col_matrix, !row_search, buffer, path, curr_max_point, curr_max_combination, sequence, points, max_points, matrix, hasVisited, minSeqSize, sequence_temp);
                }
                path.pop_back();
                sequence_temp.pop_back();
                hasVisited[next_row][curr_col] = false;
            }
        }
    }
}

void allCombinatations(const vector<vector<string>>& sequence, const vector<int>& points, const vector<vector<string>>& matrix, int* curr_max_point, vector <pair<int,int>>& curr_max_combination,int buffer){
    
    int row = matrix.size();
    int col = matrix[0].size();
    int max_points = 0;
    
     // records all paths that has been visited before, for testing purposes only
    
    for (int i  = 0 ; i < points.size(); i++){
        if (points[i] >= 0){
            max_points += points[i];
            }
    }
    // minimum sequence size : 
    int minSeqSize;
    for (int k = 0 ; k < sequence.size(); k++){
        if (k == 0){
            minSeqSize = sequence[0].size();
        }
        else{
            if (sequence[k].size() < minSeqSize){
                minSeqSize = sequence[k].size();
            }
        }
        if (minSeqSize == 2){
            break;
        }
    }

    vector<vector<bool>> hasVisited(row, vector<bool>(col, false));
    vector<string> sequence_temp;
    for (int top_col = 0 ; top_col < col ; ++top_col){
        hasVisited[0][top_col] = true;
        sequence_temp.emplace_back(matrix[0][top_col]);
        vector<pair<int, int>> path = {{0, top_col}};
        next_choice(0,top_col,row,col,false,buffer,path,curr_max_point,curr_max_combination,sequence,points,max_points,matrix,hasVisited, minSeqSize,sequence_temp);
        hasVisited[0][top_col] = false;
        sequence_temp.pop_back();
    }
}
