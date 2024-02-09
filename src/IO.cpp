

// #include "IO.hpp"
#include "IO.hpp"
#include <vector>
#include "cyberpunk.hpp"
using namespace std;


void displayResult(int curr_max_point, vector <pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time){
    if (curr_max_point == 0){
        cout << "No Possible Sequences" << endl;
    }
    else{
        cout << "Result: " << endl;
        cout << curr_max_point << endl;
        vector<string> sequence = pathToSequence(curr_max_combination,matrix);
        printSequence(sequence);
        printPath(curr_max_combination);
        cout << endl;
        cout << time << "ms" << endl << endl;
        cout << "Apakah ingin menyimpan solusi? (y/n) : ";
        char input;
        cin >> input;
        if (input == 'y'){
            write_file(curr_max_point,curr_max_combination,matrix,time);
        }

    }


}
void printPath(vector<pair<int, int>> path){
    cout << "Coordinates (col,row): " << endl;
    for (int i = 0 ; i < path.size() ; i++){
        cout << path[i].second  + 1 << ", " << path[i].first  + 1 << endl;
    }
}
void printSequence(vector<string> sequence){
    cout << "Optimal Sequence : ";
    for (int i = 0 ; i < sequence.size() ; i++){
        cout << sequence[i] << " ";

    }
    cout << endl;
}
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


void display_menu(int* input){
    cout << "=================================================================" << endl;
    cout << "INPUT OPTIONS : " << endl;
    cout << "1.Text file" << endl;
    cout << "2.Command Line" << endl;
    cout << "3.Exit" << endl;
    bool valid = false;
    do {
        cout << "input : " ;
        cin >> *input;
        if (*input == 1){
            valid = true;
        }
        else if (*input == 2){
            valid = true;
        }
        else if (*input == 3){
            valid = true;
        }
        else {
            cout << "Please enter the correct input type !" << endl;
        }
    }while (!valid);
}

void randomInput(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer){
    cout << "=================================================================" << endl;
    int total_token, row, col, total_sequences,maximum_sequence_size;
    string token_temp;
    vector<string> tokens;
    cout << "Command Line Input" << endl;
    cout << "number of unique token     : ";
    cin >> total_token;
    cout << "Enter all tokens           : ";
    getline(std::cin, token_temp);
    getline(std::cin, token_temp);
    tokens = stringSeperator(token_temp);

    cout << "Buffer Size                : ";
    cin >> *buffer;
    cout << "Matrix Size (row column)   : ";
    cin >> row;
    cin >> col; 
    cout << "Number of Sequences        : ";
    cin >> total_sequences;
    cout << "Maximum sequence size      : ";
    cin >> maximum_sequence_size;
    random_device rd;
    mt19937 engine(rd()); 
    uniform_int_distribution<int> dist(0, total_token-1);
    // generating matrix
    for (int curr_row = 0 ; curr_row < row; curr_row++){
        vector<string> aRow;
        for (int curr_col = 0 ; curr_col < col ; curr_col++){
            // int randNum = randomNumberGenerator(0,total_token-1);
            // cout << "RANDOM NUMBER : " << randNum << endl;
            aRow.emplace_back(tokens[dist(engine)]);
        }
        matrix.emplace_back(aRow);
        
    }


    // generating sequence and points
    random_device rd2;
    mt19937 engine2(rd2()); 
    uniform_int_distribution<int> dist2(2, maximum_sequence_size);

    random_device rd3;
    mt19937 engine3(rd3()); 
    uniform_int_distribution<int> dist3(3, 10);

    for (int curr_sequence = 0 ; curr_sequence < total_sequences ; curr_sequence++){
        vector<string> aSeq;
        int random_size_sequence = dist2(engine2);
        for (int size = 0 ;size <  random_size_sequence; size++ ){
            int random_token_index = dist(engine);
            aSeq.emplace_back(tokens[random_token_index]);
        }
        sequences.emplace_back(aSeq);
        points.emplace_back(dist3(engine3) * 5);
    }
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
        file.close();
        cout << "Enter File Name : ";
        cin >> fileNameTemp;
        fileName = "test/";
        fileName.append(fileNameTemp);
        file.open(fileName);
    }
    file.close();

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

void write_file(int curr_max_point, vector <pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time){
    cout << "=================================================================" << endl;
    cout << "SAVE SOLUTION" << endl;
    cout << "File Name (With extension) : ";
    string fileNameTemp;
    cin >> fileNameTemp;
    string fileName = "test/";
    fileName.append(fileNameTemp);
    ifstream file(fileName);
    while (file) {
        cout << "File already exist, please rename the file !" << endl;
        file.close();
        cout << "File Name (With extension) : ";
        cin >> fileNameTemp;
        fileName = "test/";
        fileName.append(fileNameTemp);
        file.open(fileName);
    }
    file.close();
    fstream myFile;
    myFile.open(fileName,ios::out);
    if (myFile.is_open()){
        myFile << curr_max_point << "\n";
        vector<string> sequence = pathToSequence(curr_max_combination,matrix);
        for(int i = 0 ; i < sequence.size(); i++){
            myFile << sequence[i] << " ";
        }
        myFile << "\n";
        for (int k = 0 ; k < curr_max_combination.size() ; k++){
            myFile << curr_max_combination[k].second +1 << ", " << curr_max_combination[k].first + 1;
            myFile << "\n";
        }
        myFile << "\n";
        myFile << time <<"ms";
        myFile.close();
    }

}