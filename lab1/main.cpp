#include <iostream>
#include "Queue.h"
#include "ProtectedQueue.h"
#include "PrivateQueue.h"
#include "PublicQueue.h"

using namespace std;

int main() {
    cout << "Введите номер в соответствии с каким классом собираетесь работать"<< endl;
    cout << "1 - publicQueue"<< endl;
    cout << "2 - protectedQueue"<< endl;
    cout << "3 - privateQueue"<< endl;
    int c;
    cin >> c;

    Queue queue;
    PublicQueue que(&queue);
    ProtectedQueue que1(&queue);
    PrivateQueue que2(&queue);


    switch (c) {
        case 1:
            que.print();
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            return 1;
    }



    cout << "Введите команды через пробел\n\tInfo:\n" << endl;
    cout << "1 – Добавление элемента очереди" << endl;
    cout << "2 – Извлечение элемента очереди" << endl;
    cout << "3 – Вывод очереди на экран" << endl;
    cout << "4 – Вычисление требуемого значения(Нахождение последнего элемента, меньшего среднего гармонического)" << endl;
    cout << "5 – Создание копии очереди" << endl;
    cout << "6 – Слияние оригинальной очереди с копией и вывод результата на экран" << endl;
    cout << "7 – Выход из программы" << endl;


    cout << "команда: ";
    cin >> c;
    int numb;

    while (c != 7) {

        switch (c) {
            case 1:
                cin >> numb;
                queue.push(numb);
                break;
            case 2:
                queue.pop();
                break;
            case 3:
                queue.print();
                break;
            case 4:

                queue.findElement();
                break;
            case 5:
                queue.copy();
                break;
            case 6:

                queue.mergeWithCopy();
                break;

            default: cout << "Введите другую команду:" << endl;

        }

        cout << "команда: ";
        cin >> c;
    }

    return 0;
}
