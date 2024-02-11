

// #include "IO.hpp"
#include "IO.hpp"
#include "cyberpunk.hpp"
using namespace std;

bool areTokensUnique(vector<string> tokens){
    for (int i = 0 ; i < tokens.size() ; i++){
        for (int k = i + 1; k < tokens.size() ; k++){
            if (tokens[i] == tokens[k]){
                return false;
            }
        }
    }
    return true;
}

void displayResult(int curr_max_point, vector <pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time){
    if (curr_max_point <= 0){
        cout << "Result: " << endl;
        cout << "No Solution" << endl;
        cout << endl;
        cout << time << "ms" << endl << endl;
        cout << "Apakah ingin menyimpan solusi? (y/n) : ";
        char input;
        cin >> input;
        if (input == 'y'){
            write_file(curr_max_point,curr_max_combination,matrix,time);
        }



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
        cout << "Sequence " << curr_row + 1 << "   : ";
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
    *input = 0;
    char clearBuff[80];
    do {

        cout << "input : " ;
         cin >> *input;
        if (cin.fail()){
            cout << "That's not an integer !" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
        }
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

bool randomInput(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer){
    cout << "=================================================================" << endl;
    int total_token, row, col, total_sequences,maximum_sequence_size;
    string token_temp;
    vector<string> tokens;

    try {
    cout << "Command Line Input" << endl;
    cout << "number of unique token     : ";
    cin >> total_token;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    bool unique = false;
    
    do {
        vector<string> tokensTemp;
        cout << "Enter all tokens           : ";
        string temp_token;
        for (int token = 0 ; token < total_token ; token++){
        cin >> temp_token;
        if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
        }
        tokensTemp.emplace_back(temp_token);
    }
    unique = areTokensUnique(tokensTemp);
    if (!unique){
        cout << "Please make sure all tokens are unique !" << endl;
    }
    else {
        tokens = tokensTemp;
    }
    } while (!unique);
    



    cout << "Buffer Size                : ";
    cin >> *buffer;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    cout << "Matrix Size (column row)   : ";
    cin >> col;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } 

    cin >> row;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } 

    cout << "Number of Sequences        : ";
    cin >> total_sequences;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } 
    cout << "Maximum sequence size      : ";
    cin >> maximum_sequence_size;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } 
    random_device rd;
    mt19937 engine(rd()); 
    uniform_int_distribution<int> dist(0, total_token-1);
    // generating matrix
    for (int curr_row = 0 ; curr_row < row; curr_row++){
        vector<string> aRow;
        for (int curr_col = 0 ; curr_col < col ; curr_col++){
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
    int repeats;

    for (int curr_sequence = 0 ; curr_sequence < total_sequences ; curr_sequence++){
        vector<string> aSeq1;
        repeats = 0;
        do {
        vector<string> aSeq;
        int random_size_sequence = dist2(engine2);
        for (int size = 0 ;size <  random_size_sequence; size++ ){
            int random_token_index = dist(engine);
            aSeq.emplace_back(tokens[random_token_index]);
        aSeq1 = aSeq;
        }
        repeats++;
        if (repeats > 100){
            cout << "Something Went Wrong !" << endl;
            cout << "With the current inputs, creating unique sequences is impossible !" << endl;
            return false;
        }
            } while (sequenceInSequences(aSeq1,sequences));
        
        sequences.emplace_back(aSeq1);
        points.emplace_back(dist3(engine3) * 5);
    }

    } catch(const runtime_error &e){
        cerr << "Caught a runtime error: " << e.what() << endl ;
        return false;
    }
    catch (...){
        cerr << "Something Went Wrong" << endl;
        return false;
    }
    return true;
}

bool readFile(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer ){
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

    try{
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
    catch (const std::runtime_error &e){
        cerr << "Caught a runtime error: " << e.what() << endl;
        return false;
    }
    catch (...){
        cerr << "Something went wrong" << endl;
        return false;
        }
    return true;
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

        if (curr_max_point <= 0){
            myFile << "No Solution\n";
            myFile << "\n";
            myFile << time <<"ms";
        }
        else{
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
        }
        myFile.close();
    }

}