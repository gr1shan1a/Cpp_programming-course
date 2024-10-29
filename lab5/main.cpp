// Класс Книжный магазин хранит данные о книгах, учебниках, канцелярии.
// - Для книг определено: Book
//          название,
//          автор,
//          год выпуска,
//          аннотация,
//          жанр,
//          объем страниц,
//          стоимость.
// - Для учебника определено:  StudentsBook
//          название,
//          автор,
//          год выпуска,
//          для какого учебного заведения предназначено,
//          год обучения,
//          объем страниц,
//          стоимость.
// - Для канцелярии определено:
//          тип канцелярии,
//          цвет,
//          назначение,
//          стоимость.


// по задачам
// 1) создать класс Keeper
// 2) add, delete производных объектов абстрактного класса
// 3) полное сохранение в файле
// 4) полное восстановление из файла


#include <iostream>
#include "BaseClass.h"
#include "Book.h"
#include "StudentsBook.h"
#include "Chancellery.h"
#include "Keeper.h"
using namespace std;

int main() {
    Keeper keeper;
    int c;
    do {
        printf("==========================================\n");
        printf("__________ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ:__________\n");
        printf(">> Введите '1' если вы хотите редактировать определенный набор\n");
        printf(">> Введите '2' для сохранения keeper\n");
        printf(">> Введите '3' для загрузки keeper из библиотеки имеющихся\n");
        printf(">> Введите '-1' для выхода из программы\n");
        cin >> c;
        switch (c) {
            case 1: {
                int c1;
                do {
                    printf(">> Введите '1' для добавления элемента\n");
                    printf(">> Введите '2' для удаления элемента\n");
                    printf(">> Введите '0' для возврата в главное меню\n");

                    cin >> c1;
                    switch (c1) {
                        case 1: {
                            int type;
                            printf("Выберите тип объекта для добавления:\n");
                            printf("Введите '1' - Книга\n");
                            printf("Введите '2' - Учебник\n");
                            printf("Введите '3' - Канцелярия\n");
                            cin >> type;
                            cin.ignore();  // Игнорировать символ новой строки

                            switch (type) {
                                case 1: {
                                    book *b = new book();
                                    b->addElement();
                                    keeper.add(b);
                                    keeper.setSize();
                                    break;
                                }
                                case 2: {
                                    StudentsBook *sb = new StudentsBook();
                                    sb->addElement();
                                    keeper.add(sb);
                                    keeper.setSize();
                                    break;
                                }
                                case 3: {
                                    Chancellery *ch = new Chancellery();
                                    ch->addElement();
                                    keeper.add(ch);
                                    keeper.setSize();
                                    break;
                                }
                                default:
                                    printf("Неверный выбор!\n");
                                    break;
                            }
                            break;
                        }
                        case 2: {
                            keeper.printAll();
                            printf("Введите индекс элемента для удаления: ");
                            int index;
                            cin >> index;
                            if (index >= 0 && index < keeper.getSize()) {
                                keeper.remove(index);
                            } else {
                                std::cout << "Такого индекса нет" << std::endl;
                            }


                            break;
                        }
                        case 0:
                            break;
                        default:
                            printf("Неверный ввод! Попробуйте снова.\n");
                            break;
                    }
                } while (c1 != 0);
                break;
            }
            case 2: {
                string filename;
                printf("Введите имя файла для сохранения: ");
                cin >> filename;
                keeper.saveToFile(filename);
                break;
            }
            case 3: {
                string filename;
                printf("Введите имя файла-keeper для загрузки: ");
                cin >> filename;
                keeper.loadFromFile(filename);
                break;
            }
            case -1:
                printf("Выход из программы...\n");
                break;
            default:
                printf("Неверный ввод! Попробуйте снова.\n");
                break;

        }
    } while (c != -1);

    return 0;
}
