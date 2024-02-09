#include "cyberpunk.hpp"

int main(){
    vector<string> r = {"AB","AC","ABCD"};
    vector< vector<string>> sequences = {{"AB","ABC","ABCD"}, {"AB"}};
    cout << sequenceInSequences(r,sequences);
    return 0;
}

