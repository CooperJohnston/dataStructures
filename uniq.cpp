
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <iterator>

using namespace std;

int main(int argc, char const* argv[]) {
    string filename;
    vector<string> lines, duplicates;
    std::string line;

    if (argc == 2){
        filename = argv[1];
        //cout << filename << " is the file I have." << endl;
        ifstream ifp(filename);
        //cout << "I have now opened it." << endl;
        while (getline(ifp,line)) {
            //cout << line << " is the line for you." << endl;
            if (find(lines.begin(), lines.end(), line) == lines.end()) {
                //cout << line << " is in the duplicates!" << endl;
                lines.push_back(line);
            }
        }
        ifp.close();
        //cout << "I have now closed it." << endl;
        vector<string>::iterator itr;
        for(itr = lines.begin(); itr != lines.end(); itr++){
            //cout << *itr << " Is the item in lines." << endl;
            cout << *itr << endl;
        }


    }
    else {

        //cout << filename << " is what you gave me." << endl;

        while (cin) {
            getline(cin, line);
            if (line != "") {

                if (find(lines.begin(), lines.end(), line) == lines.end()) {
                    // cout << line << " is in the duplicates!" << endl;
                    lines.push_back(line);
                }

            }
        }
        vector<string>::iterator itr;
        for(itr = lines.begin(); itr != lines.end(); itr++){
            //cout << *itr << " Is the item in lines." << endl;
            cout << *itr << endl;
        }}


    return 0;
    }


