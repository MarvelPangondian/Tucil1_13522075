#include "cyberpunk.hpp"

int main(){
    vector<string> r = {"7A", "BD", "1C", "BD", "E9", "7A", "1C", "E9", "55"};
    vector< vector<string>> sequences = {{"1C", "BD", "E9"}, {"7A", "BD", "1C"}, {"7A", "1C" ,"E9","55"}};
    // cout << sequenceInSequences(r,sequences);
    vector<int> point  = {15,45,50};
    int total = sequence_to_point(r,sequences,point);
    cout << total;
    return 0;
}

