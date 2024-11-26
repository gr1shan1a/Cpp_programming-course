#include <iostream>
#include <vector>
#include <algorithm>
#include "Classes/Train.h"
#include "Classes/quotes.h"

using namespace std;

// Функция для сравнения времени отправления
bool compareByDepartureTime(const Train& a, const Train& b) {
    return a.getDepartureTime() < b.getDepartureTime();
}

int main() {
    int choice;
    cout << "1 - Train. 2 - Quotes: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            cout << "Now we are working with train" << endl;
            try {
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

                // Вывод отсортированного списка поездов
                cout << "\n\nSorted trains by departure time:" << endl;
                for (const auto& train : trains) {
                    cout << train;
                }
                cout << "\n\n";

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
            } catch (const invalid_argument &e) {
                cerr << "Exception: " << e.what() << endl;
            }
        }
        case 2: {
            cout << "Now we are working with quotes" << endl;
            string filename;
            cout << "Enter the filename: ";
            cin >> filename;

            extractQuotes(filename);
            break;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        cin >> choice;
    }

    return 0;
}
