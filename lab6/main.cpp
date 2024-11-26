#include <iostream>
#include <vector>
#include <algorithm>
#include "Classes/Train.h"
#include "Classes/quotes.h"

using namespace std;

bool compareByDepartureTime(const Train& a, const Train& b) {
    return a.getDepartureTime() < b.getDepartureTime();
}

int main() {
    int choice;
    do {
        printf("==========================================\n");
        printf("__________ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ:__________\n");
        cout << "1 - Train. 2 - Quotes: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Now we are working with train" << endl;
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

                sort(trains.begin(), trains.end(), compareByDepartureTime);

                int ch;
                cout << "1. Добавить новый поезд" << endl;
                cout << "2. Редактировать поезд" << endl;
                cout << "3. Удалить поезд" << endl;
                cout << "4. Показать все поезда" << endl;
                cout << "5. Поиск поездов по пункту назначения" << endl;
                cout << "6. Выход" << endl;
                cout << "Введите ваш выбор: ";


                cin >> ch;
                do {
                switch (ch) {

                        case 1: {
                            string dest, time;
                            int number;
                            cout << "Введите пункт назначения, номер поезда и время отправления: ";
                            cin >> dest >> number >> time;
                            trains.emplace_back(dest, number, time);
                            break;
                        }
                        case 2: {
                            int index;
                            cout << "Введите индекс поезда для редактирования: ";
                            cin >> index;
                            if (index >= 0 && index < trains.size()) {
                                string dest, time;
                                int number;
                                cout << "Введите новый пункт назначения, номер поезда и время отправления: ";
                                cin >> dest >> number >> time;
                                trains[index].setDest(dest);
                                trains[index].setNumber(number);
                                trains[index].setTime(time);
                            } else {
                                cout << "Неверный индекс" << endl;
                            }
                            break;
                        }
                        case 3: {
                            int index;
                            cout << "Введите индекс поезда для удаления: ";
                            cin >> index;
                            if (index >= 0 && index < trains.size()) {
                                trains.erase(trains.begin() + index);
                            } else {
                                cout << "Неверный индекс" << endl;
                            }
                            break;
                        }
                        case 4: {
                            // Сортировка по времени отправления
                            sort(trains.begin(), trains.end(), compareByDepartureTime);
                            // список поездов
                            cout << "Отсортированный список поездов по времени отправления:" << endl;
                            for (const auto &train: trains) {
                                cout << train;
                            }
                            break;
                        }
                        case 5: {
                            string searchDestination;
                            cout << "Введите пункт назначения: ";
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


                            cout << "";
                        }
                        default:
                            "Input incorrect";

                    }
                    cin >> ch;
                } while (ch != 0);
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

        }
    } while (choice != 0);

    return 0;
}
