#include <iostream>
#include <string>
#include <queue>
#include "input.h"

using namespace std;

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {
    // Write your code here
    priority_queue<string> p_que;
    string argument= "hi", name, priority, final;

    while (argument != "") {
        argument = input("What do you want to do? ");
        if (argument == "") {
            return 0;
        }
        if (argument == "add"){
            name = input("Name: ");
            priority = input("Priority: ");
            if (priority.length() == 1) {
                priority = "0" + priority;
            }
            final = priority + " - " + name;
            p_que.push(final);
        }
        else if (argument == "take") {
            if (p_que.size() == 0){
                cout << "There are no more people in line" << endl;
            }
            else {
                cout << p_que.top() << endl;
                p_que.pop();
            }
        }
        else {
            cout << argument << " isn't a valid operation" << endl;
        }
    }
    return 0;
}
