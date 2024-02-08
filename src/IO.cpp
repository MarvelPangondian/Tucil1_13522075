

// #include "IO.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;


void printMatrix(const vector<vector<string>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    cout << "Matrix : " << endl;
    for (int curr_row = 0 ; curr_row < row ; curr_row++){
        for (int curr_col = 0 ; curr_col < col; curr_col++){
            cout << matrix[curr_row][curr_col] << " ";
        }
        cout << endl;
    }
}

void printSequences(vector<vector<string>> sequences, vector<int> points){
    int rowseq = sequences.size();
    
    for (int curr_row = 0 ; curr_row < rowseq ; curr_row++){
        cout << "Sequence " << curr_row + 1 << ": ";
        for (int curr_col = 0 ; curr_col < sequences[curr_row].size(); curr_col++){
            cout << sequences[curr_row][curr_col] << " ";
        }
        cout << endl;
        cout << "Point " << curr_row +1 << " : " << points[curr_row] << endl;

    }

}

string removeNewLine(string line){
    while(line[line.size()-1] == '\n' ||line[line.size()-1] == '\r' ){
            line = line.substr(0,line.size()-1);
        }
        // line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    return line;

}

vector<string> stringSeperator(string sentence){
    string token;
    istringstream iss(sentence); 
    vector<string> result; 
    while (iss >> token) { 
        result.push_back(token);
    }


    return result;
}

void display_menu(){
    cout << "=================================================================" << endl;
    cout << "INPUT OPTIONS : " << endl;
    cout << "1.Command Line" << endl;
    cout << "2.Text file" << endl;
    bool valid = false;
    int input;
    do {

        
        
        cout << "input : " ;
        cin >> input;
        if (input == 1){
            valid = true;
        }
        else if (input == 2){
            valid = true;

        }
        else {
            cout << "Please enter the correct input type !" << endl;
        }
    }while (!valid);

    switch(input){
        case(1):

            break;
        case (2) : 
            cout << "you choose 2 ! ";
            break;

    }
}

void randomInput(){
    cout << "=================================================================" << endl;
    int total_token, buffer, row, col, total_sequences;
    string token_temp;
    vector<string> tokens;
    cout << "Command Line Input" << endl;
    cout << "number of unique token     : ";
    cin >> total_token;
    cout << "Enter all tokens           : ";
    cin >> token_temp; 
    tokens = stringSeperator(token_temp);

    cout << "Buffer Size                : ";
    cin >> buffer;
    cout << "Matrix Size (row column)   : ";
    cin >> row;
    cin >> col; 
    cout << "Number of Sequences        : ";
    cin >> total_sequences;
}

void readFile(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer ){
    cout << "=================================================================" << endl;
    string fileNameTemp;
    cout << "Enter File Name : ";
    cin >> fileNameTemp;
    string fileName = "test/";
    fileName.append(fileNameTemp);
    ifstream file(fileName);

    while (!file) {
        cout << "File doesn't exist!, make sure the file is in the test folde and the working folder is correct !" << endl;
        
        // Close the previously attempted file (good practice, though not strictly necessary here)
        file.close();
        
        cout << "Enter File Name : ";
        cin >> fileNameTemp;
        fileName = "test/";
        fileName.append(fileNameTemp);
        
        // Correctly reopen the file with the updated fileName
        file.open(fileName);
    }

    fstream myFile;
    int row,col,total_sequence;
    vector<string>row_col ;
    vector<string> aRow;
    myFile.open(fileName,ios::in);
    if (myFile.is_open()){
        string line;
        getline(myFile,line);
        line = removeNewLine(line);
        *buffer = stoi(line);
        getline(myFile,line);
        row_col = stringSeperator(line);
        col = stoi(removeNewLine(row_col[0]));
        row = stoi(removeNewLine(row_col[1]));
        for (int i = 0 ; i < row; i++){
            getline(myFile,line);
            aRow = stringSeperator(line);
            matrix.emplace_back(aRow);
        }
        getline(myFile,line);
        total_sequence = stoi(removeNewLine(line));
        for (int k = 0 ; k < total_sequence ; k++){
            vector<string> aSequence;
            int point;
            getline(myFile,line);
            aSequence = stringSeperator(line);
            sequences.push_back(aSequence);
            getline(myFile,line);
            points.push_back(stoi(removeNewLine(line)));


        }
        myFile.close();
        

    }
}

int main(){
    vector<vector<string>> sequences;
    vector<vector<string>> matrix;
    vector<int> points;
    int curr_max_point = -1, buffer;
    vector <pair<int,int>> curr_max_combination;
    readFile(sequences ,matrix, points, &buffer );
    cout << buffer; cout << endl;
    
    // vector<vector<string>> sequences = {{"1C","55","55"}, {"1C","55"}, {"55","BD","E9","1C"}};
    // vector<vector<string>> matrix = {
    //     {"1C","1C","55","E9","55"},
    //     {"1C","1C","E9","55","55"},
    //     {"BD","55","55","1C","BD"},
    //     {"1C","E9","55","BD","BD"},
    //     {"55","1C","55","E9","55"}
    // };
    // vector<int> points = {15,20,30};
    printMatrix(matrix);
    printSequences(sequences,points);
    cout << endl;
    


    
    
}