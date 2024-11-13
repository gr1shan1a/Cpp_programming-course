#include "../Classes/quotes.h"

using namespace std;

void extractQuotes(const string& filename) {
    ifstream file("/Users/macbook/CLionProjects/Cpp_programming-course/lab6/Resources/" + filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    bool insideQuotes = false;
    string quote;
    int cnt = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            if (word.find('"') != string::npos) {
                if (!insideQuotes) {
                    insideQuotes = true;
                    quote = word.substr(word.find('"') + 1) + " ";
                } else {
                    insideQuotes = false;
                    quote += word.substr(0, word.find('"'));
                    cnt++;
                    cout << cnt << ". " << quote << endl;
                    quote.clear();
                }
            } else if (insideQuotes) {
                quote += word + " ";
            }
        }
    }

    file.close();
}
