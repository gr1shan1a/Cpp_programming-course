#include <iostream>
#include <string>
#include "Magazine.h"
#include "Textbook.h"
#include "Book.h"

using namespace std;

void printMenu() {
    cout << "\nChoose an option:\n"
         << "1. Magazine\n"
         << "2. Textbook\n"
         << "3. Book\n"
         << "4. Exit\n"
         << "> ";
}

void printMenu1() {
    cout << "\nChoose an option:\n"
         << "1. Data from input_file\n"
         << "2. Data from input_stream\n"
         << "3. Exit\n"
         << "> ";
}

void printMenu2() {
    cout << "\nChoose an option:\n"
         << "1. Print to output_file\n"
         << "2. Print to output_stream\n"
         << "3. Exit\n"
         << "> ";
}

int main() {
    int choice1;
    do {
        printMenu1();
        cin >> choice1;
        cout << "===============================\n";


        // выбор метода ввода
        switch (choice1) {

            case 1: {
                std::ifstream inputFile("/Users/macbook/CLionProjects/lab3/input.txt");
                if (!inputFile.is_open()) {
                    std::cerr << "Error opening input file." << std::endl;
                    return 1;
                }

                std::string type, name, publisher, annotation, subject, author;
                int year, numPages, issueNumber, Nomer_pechati, grade;

                while (inputFile >> type) {
                    if (type == "Magazine") {
                        inputFile.ignore();
                        getline(inputFile, name);
                        inputFile >> year >> publisher >> numPages;
                        inputFile.ignore();
                        getline(inputFile, annotation);
                        inputFile >> issueNumber >> Nomer_pechati;

                        Magazine magazine(name, year, publisher, numPages, annotation, issueNumber);
                        int choice_print;
                        printMenu2();
                        cin >> choice_print;
                        switch (choice_print) {

                            case 1: {
                                ofstream outputFile("Magazine_Fr_IS.txt");
                                magazine.printToFile(outputFile);
                                break;
                            }

                            case 2: {
                                magazine.print();
                                break;
                            }
                            case 3:
                                cout << "Exit successful!\n";
                                break;
                        }

                        break;
                    } else if (type == "Textbook") {
                        inputFile.ignore();
                        getline(inputFile, name);
                        inputFile >> year >> publisher >> numPages;
                        inputFile.ignore();
                        getline(inputFile, annotation);
                        inputFile >> subject >> grade;

                        Textbook textbook(name, year, publisher, numPages, annotation, subject, grade);
                        int choice_print;
                        printMenu2();
                        cin >> choice_print;
                        switch (choice_print) {

                            case 1: {
                                ofstream outputFile("Textbook_Fr_IS.txt");
                                textbook.printToFile(outputFile);
                                break;
                            }

                            case 2: {
                                textbook.print();
                                break;
                            }
                            case 3:
                                cout << "Exit successful!\n";
                                break;
                        }
                        break;
                    } else if (type == "Book") {
                        inputFile.ignore();
                        getline(inputFile, name);
                        inputFile >> year >> publisher >> numPages;
                        inputFile.ignore();
                        getline(inputFile, annotation);
                        inputFile >> author;

                        Book book(name, year, publisher, numPages, annotation, author);
                        int choice_print;
                        printMenu2();
                        cin >> choice_print;

                        switch (choice_print) {

                            case 1: {
                                ofstream outputFile("Book_Fr_IS.txt");
                                book.printToFile(outputFile);
                                break;
                            }

                            case 2: {
                                book.print();
                                break;
                            }
                            case 3:
                                cout << "Exit successful!\n";
                                break;
                        }
                        break;
                    } else {
                        cerr << "Invalid type in input file: " << type << endl;
                    }
                }
                break;
            }
            // с клавиатуры
            case 2:
                int choice;
                do {
                    printMenu();
                    cin >> choice;
                    cout << "===============================\n";

                    switch (choice) {
                        case 1: {
                            ofstream outputFile("Magazine.txt");
                            string name, publisher, annotation;
                            int year, numPages, issueNumber;

                            cout << "Enter the name: ";
                            cin.ignore();
                            getline(cin, name);

                            cout << "Enter the year: ";
                            cin >> year;

                            cout << "Enter the publisher: ";
                            cin.ignore();
                            getline(cin, publisher);

                            cout << "Enter the number of pages: ";
                            cin >> numPages;

                            cout << "Enter the annotation: ";
                            cin.ignore();
                            getline(cin, annotation);

                            cout << "Enter the issue number: ";
                            cin >> issueNumber;

                            cout << "\n===============================\n\n";

                            Magazine magazine(name, year, publisher, numPages, annotation, issueNumber);
                            magazine.print();
                            magazine.printToFile(outputFile);
                            cout << "\n===============================\n";
                            break;
                            outputFile.close();
                        }
                        case 2: {
                            ofstream outputFile("Textbook.txt");
                            string name, publisher, annotation, subject;
                            int year, numPages, grade;

                            cout << "Enter the name: ";
                            cin.ignore();
                            getline(cin, name);

                            cout << "Enter the year: ";
                            cin >> year;

                            cout << "Enter the publisher: ";
                            cin.ignore();
                            getline(cin, publisher);

                            cout << "Enter the number of pages: ";
                            cin >> numPages;

                            cout << "Enter the annotation: ";
                            cin.ignore();
                            getline(cin, annotation);

                            cout << "Enter the subject: ";
                            getline(cin, subject);

                            cout << "Enter the grade: ";
                            cin >> grade;

                            cout << "\n===============================\n\n";

                            Textbook textbook(name, year, publisher, numPages, annotation, subject, grade);
                            textbook.print();
                            textbook.printToFile(outputFile);
                            cout << "\n===============================\n";
                            break;
                            outputFile.close();
                        }
                        case 3: {
                            ofstream outputFile("Book.txt");
                            string name, publisher, annotation, author;
                            int year, numPages;

                            cout << "Enter the name: ";
                            cin.ignore();
                            getline(cin, name);

                            cout << "Enter the year: ";
                            cin >> year;

                            cout << "Enter the publisher: ";
                            cin.ignore();
                            getline(cin, publisher);

                            cout << "Enter the number of pages: ";
                            cin >> numPages;

                            cout << "Enter the annotation: ";
                            cin.ignore();
                            getline(cin, annotation);

                            cout << "Enter the author: ";
                            getline(cin, author);

                            cout << "\n===============================\n\n";

                            Book book(name, year, publisher, numPages, annotation, author);
                            book.print();
                            book.printToFile(outputFile);
                            cout << "\n===============================\n";
                            break;
                            outputFile.close();
                        }
                        case 4:
                            cout << "Exit successful!\n";
                            break;
                        default:
                            cout << "Invalid option. Try again.\n";
                            break;
                    }
                } while (choice != 4);
            case 3:
                cout << "Exit successful!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
                break;
        }
    } while (choice1 != 3);
    return 0;
}
