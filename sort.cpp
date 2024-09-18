#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> insertionSort (vector<string> array, int N) {
    int i, j;
    string key;
    for (i = 1; i < N; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j + 1] = key;

    }
    return array;
}



int main(int argc, char const* argv[]) {
    // Write your code here
    vector<string> words;
    string loine= "void";
    if (argc > 1) {
        //string loine;
        string filename = argv[1];
        ifstream ipf(filename);
        while (!ipf.eof()) {
            getline(ipf, loine);
            words.push_back(loine);
        }
        int n = words.size();
        words = insertionSort(words, n);
        for( int i = 0; i < words.size(); i++){
            if (words[i]!= "")
            {cout  << words[i] << endl;}
        }
    }
    else if (argc == 1) {
        while (loine != "") {
            getline(cin, loine);
            words.push_back(loine);
        }
        int n = words.size();
        words = insertionSort(words, n);
        for( int i = 0; i < words.size(); i++){
            if (words[i]!= "")
            {cout  << words[i] << endl;}
        }
    }
    return 0;
}
