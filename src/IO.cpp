

// #include "IO.hpp"
#include "IO.hpp"
#include "cyberpunk.hpp"
using namespace std;

bool areTokensUnique(vector<string> tokens)
// To make sure all tokens are unique
{
    // KAMUS LOKAL
    int i, k;

    // ALGORITMA
    for (i = 0 ; i < tokens.size() ; i++){
        for (k = i + 1; k < tokens.size() ; k++){
            if (tokens[i] == tokens[k]){
                return false;
            }
        }
    }
    return true;
}

void displayResult(int curr_max_point, vector <pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time)
// Function to display final result
{
    // KAMUS LOKAL
    char input;
    vector<string> sequence;

    // ALGORITMA
    cout << "============================= RESULT ============================" << endl;
    if (curr_max_point <= 0){
        cout << "No Solution" << endl;
        cout << endl;
        cout << time << "ms" << endl << endl;
        cout << "Apakah ingin menyimpan solusi? (y/n) : ";
        cin >> input;
        if (input == 'y'){
            write_file(curr_max_point,curr_max_combination,matrix,time);
        }
    }
    else{
        cout << "Result: " << endl;
        cout << curr_max_point << endl;
        sequence = pathToSequence(curr_max_combination,matrix);
        printSequence(sequence);
        printPath(curr_max_combination);
        cout << endl;
        cout << time << "ms" << endl << endl;
        cout << "Apakah ingin menyimpan solusi? (y/n) : ";
        cin >> input;
        if (input == 'y'){
            write_file(curr_max_point,curr_max_combination,matrix,time);
        }
    }
}
void printPath(vector<pair<int, int>> path)
// Function to print path (coordinate)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    cout << "Coordinates (col,row): " << endl;
    for (i = 0 ; i < path.size() ; i++){
        cout << path[i].second  + 1 << ", " << path[i].first  + 1 << endl;
    }
}
void printSequence(vector<string> sequence)
// Function to print sequence
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    cout << "Optimal Sequence : ";
    for (i = 0 ; i < sequence.size() ; i++){
        cout << sequence[i] << " ";

    }
    cout << endl;
}
void printMatrix(const vector<vector<string>> matrix)
// Function to print matrix
{
    // KAMUS LOKAL
    int row = matrix.size();
    int col = matrix[0].size();
    int curr_row, curr_col;

    // ALGORITMA
    for (curr_row = 0 ; curr_row < row ; curr_row++){
        for (curr_col = 0 ; curr_col < col; curr_col++){
            cout << matrix[curr_row][curr_col] << " ";
        }
        cout << endl;
    }
}

void printSequences(vector<vector<string>> sequences, vector<int> points)
// Print each sequence in sequences
{
    // KAMUS LOKAL
    int rowseq = sequences.size();
    int curr_row, curr_col;

    // ALGORITMA
    for (curr_row = 0 ; curr_row < rowseq ; curr_row++){
        cout << "Sequence " << curr_row + 1 << "   : ";
        for (curr_col = 0 ; curr_col < sequences[curr_row].size(); curr_col++){
            cout << sequences[curr_row][curr_col] << " ";
        }
        cout << endl;
        cout << "Point " << curr_row +1 << " : " << points[curr_row] << endl;
    }

}

string removeNewLine(string line)
// Function to remove new line in a string
{
    // KAMUS LOKAL

    // ALGORITMA
    while(line[line.size()-1] == '\n' ||line[line.size()-1] == '\r' ){
            line = line.substr(0,line.size()-1);
        }
    return line;
}

vector<string> stringSeperator(string sentence)
// Function to seperate string with " " as delimeter
{
    // KAMUS LOKAL
    string token;
    istringstream iss(sentence); 
    vector<string> result; 

    // ALGORITMA
    while (iss >> token) { 
        result.push_back(token);
    }
    return result;
}


void display_menu(int* input)
// Function to display menu
{
    // KAMUS LOKAL
    char clearBuff[80];
    bool valid = false;

    // ALGORITMA
    cout << "=========================== MAIN MENU ===========================" << endl;
    cout << "INPUT OPTIONS : " << endl;
    cout << "1.Text file" << endl;
    cout << "2.Command Line" << endl;
    cout << "3.Exit" << endl;
    *input = 0;
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
            cout << "Enter the correct input!" << endl;
        }
    }while (!valid);
}

bool randomInput(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer){

    // KAMUS LOKAL
    int total_token, row, col, total_sequences,maximum_sequence_size;
    string token_temp;
    vector<string> tokens;
    bool unique = false;

    // ALGORITMA
    cout << "========================== COMMAND LINE =========================" << endl;
    try {
    cout << "Command Line Input" << endl;
    cout << "number of unique tokens    : ";
    cin >> total_token;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    if (total_token <= 0 ){
        cout << "Please input a number above 0" << endl;
        return false;
    }
    
    
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
    if (*buffer <= 0 ){
        cout << "Please input a number above 0" << endl;
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
    if (col <= 0 ){
        cout << "Please input a number above 0" << endl;
        return false;
    }

    cin >> row;
    if (cin.fail()){
        cout << "Something Went Wrong !" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } 
    if (row <= 0 ){
        cout << "Please input a number above 0" << endl;
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
    if (total_sequences <= 0 ){
        cout << "Please input a number above 0" << endl;
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
    if (maximum_sequence_size < 2 ){
        cout << "Please input a number above or equal 2" << endl;
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
    uniform_int_distribution<int> dist3(50, 1000);
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
        points.emplace_back(dist3(engine3));
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

bool readFile(vector<vector<string>>& sequences ,vector<vector<string>>& matrix, vector<int>& points, int* buffer )
// Function to read file
{
    // KAMUS LOKAL
    string fileNameTemp, line;
    string fileName = "test/";
    fstream myFile;
    int row,col,total_sequence, k, point, curr_row, curr_col;
    vector<string>row_col ;
    vector<string> aRow, aSequence;
    
  // ALGORITMA
    cout << "=========================== TEXT FILE ===========================" << endl;
    cout << "Enter File Name : ";
    cin >> fileNameTemp;
    fileName.append(fileNameTemp);
    ifstream file(fileName);
    

    while (!file) {
        cout << "File doesn't exist!, make sure the file is in the test folder and the working folder is correct !" << endl << endl;
        file.close();
        cout << "Enter File Name : ";
        cin >> fileNameTemp;
        fileName = "test/";
        fileName.append(fileNameTemp);
        file.open(fileName);
    }
    file.close();

    try{
        myFile.open(fileName,ios::in);
    if (myFile.is_open()){
        getline(myFile,line);
        line = removeNewLine(line);
        *buffer = stoi(line);
        getline(myFile,line);
        row_col = stringSeperator(line);
        col = stoi(removeNewLine(row_col[0]));
        row = stoi(removeNewLine(row_col[1]));
        for (curr_row  = 0 ; curr_row < row; curr_row++){
            getline(myFile,line);
            aRow = stringSeperator(line);
            if (aRow.size() != col){
                cout << "Something is wrong with the matrix in the .txt file" << endl;
                return false;
            }
            matrix.emplace_back(aRow);
        }
        getline(myFile,line);
        total_sequence = stoi(removeNewLine(line));
        for (k = 0 ; k < total_sequence ; k++){
            point;
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

void write_file(int curr_max_point, vector <pair<int,int>> curr_max_combination, vector<vector<string>> matrix, int time)
// Write result to a .txt file
{
    // KAMUS LOKAL 
    string fileNameTemp;
    string fileName = "test/";
    vector<string> sequence;
    int i, k;

    // ALGORTIMA
    cout << "=================================================================" << endl;
    cout << "SAVE SOLUTION" << endl;
    cout << "File Name (With extension) : ";
    cin >> fileNameTemp;
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
            sequence = pathToSequence(curr_max_combination,matrix);
            for(i = 0 ; i < sequence.size(); i++){
                myFile << sequence[i] << " ";
            }
            myFile << "\n";
            for (k = 0 ; k < curr_max_combination.size() ; k++){
                myFile << curr_max_combination[k].second +1 << ", " << curr_max_combination[k].first + 1;
                myFile << "\n";
            }
            myFile << "\n";
            myFile << time <<"ms";
        }
        myFile.close();
    }
}