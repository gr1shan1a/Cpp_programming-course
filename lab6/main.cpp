#include <iostream>
#include <vector>
#include <algorithm>
#include "Classes/Train.h"
#include "Classes/quotes.h"

using namespace std;

// Функция для сравнения времени отправления
bool compareByDepartureTime(const Train& a, const Train& b) {
    return a.time < b.time;
}

int main() {
    int choice;
    cout << "1 - Train. 2 - Quotes";
    cin >> choice;
    switch (choice) {

        case 1: {
            cout << "Now we are working with train";
            vector<Train> trains;
            int n;
            cout << "Enter the number of trains: ";
            cin >> n;

            for (int i = 0; i < n; ++i) {
                string dest, time;
                int number;
                cout << "Enter destination, train number, and departure time: ";
                cin >> dest >> number >> time;
                trains.emplace_back(dest, number, time);
            }

            // Сортировка по времени отправления
            sort(trains.begin(), trains.end(), compareByDepartureTime);

            string searchDestination;
            cout << "Enter the destination to search for: ";
            cin >> searchDestination;

            bool found = false;
            for (const auto &train: trains) {
                if (train.getDestination() == searchDestination) {
                    cout << train;
                    found = true;
                }
            }

            if (!found) {
                cout << "No trains found for the destination: " << searchDestination << endl;
            }
        }

        case 2: {
            cout << "Now we are working with quotes";
            string filename;
            cout << "Enter the filename: ";
            cin >> filename;

            extractQuotes(filename);
        }


    }

    return 0;
}
