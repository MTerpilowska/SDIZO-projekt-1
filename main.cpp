#include <iostream>
#include <windows.h>
#include <iomanip>
#include <random>

#include "Array.h"
#include "BST.h"
#include "Heap.h"
#include "List.h"

using namespace std;

//-------------------------------------------------------------------------
long long int read_QPC()
{
LARGE_INTEGER count;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&count);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return((long long int)count.QuadPart);
}
//-------------------------------------------------------------------------

Array tablica;
BST bst;
Heap kopiec;
List lista;

void ArrayOption()
{
    int value = 0;
    int index = 0;
    int number = 0;

    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000000);

    while(true)
    {
        cout << "\nMENU - TABLICA: \n1. Dodaj element na poczatek \n2. Dodaj element na koniec \n3. Dodaj element na zadana pozycje \n4. Usun element z poczatku \n5. Usun element z konca \n6. Usun element z zadanej pozycji \n7. Wypelnij tablice losowymi elementami \n8. Wyswietl tablice \n9. Wroc do menu struktur \n";
        cin >> number;

        switch(number)
        {
            case 0:
                return;
                break;
            case 1: // Dodaj element na poczatek
                cout << "Wprowadz element: ";
                cin >> value;
                start = read_QPC();
                tablica.addToFront(value);
                elapsed = read_QPC() - start;
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 2: // Dodaj element na koniec
                cout << "Wprowadz element: ";
                cin >> value;
                start = read_QPC();
                tablica.addToBack(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 3: // Dodaj element na zadana pozycje
                cout << "Wprowadz element: ";
                cin >> value;
                cout << "Wprowadz pozycje: ";
                cin >> index;
                start = read_QPC();
                tablica.addToIndex(value, index);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 4: // Usun element z poczatku
                start = read_QPC();
                tablica.removeFromFront();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 5: // Usun element z konca
                start = read_QPC();
                tablica.removeFromBack();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 6: // Usun element z zadanej pozycji
                cout << "Wprowadz indeks: ";
                cin >> index;
                start = read_QPC();
                tablica.removeFromIndex(index);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 7: // Wypelnij tablice losowymi elementami
                cout << "Wprowadz liczbe elementow do wstawienia: ";
                cin >> value;
                start = read_QPC();
                for(int i=0;i<value;i++) tablica.addToBack(dist(gen));
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 8: // Wyswietl tablice
                start = read_QPC();
                tablica.display();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 9: // Wroc do menu struktur
                return;
                break;
        }
    }
}

void ListOption()
{
    int value = 0;
    int index = 0;
    int number = 0;

    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000000);

    while(true)
    {
        cout << "\nMENU - LISTA: \n1. Dodaj element na poczatek \n2. Dodaj element na koniec \n3. Dodaj element na zadana pozycje \n4. Usun element z poczatku \n5. Usun element z konca \n6. Usun element z zadanej pozycji \n7. Wypelnij liste losowymi elementami \n8. Wyswietl liste \n9. Wroc do menu struktur \n";
        cin >> number;

        switch(number)
        {
            case 0:
                return;
                break;
            case 1: // Dodaj element na poczatek
                cout << "Wprowadz element: ";
                cin >> value;
                start = read_QPC();
                lista.addToFront(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 2: // Dodaj element na koniec
                cout << "Wprowadz element: ";
                cin >> value;
                start = read_QPC();
                lista.addToBack(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 3: // Dodaj element na zadana pozycje
                cout << "Wprowadz element: ";
                cin >> value;
                cout << "Wprowadz pozycje: ";
                cin >> index;
                start = read_QPC();
                lista.addToIndex(value, index);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 4: // Usun element z poczatku
                start = read_QPC();
                lista.removeFromFront();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 5: // Usun element z konca
                start = read_QPC();
                lista.removeFromBack();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 6: // Usun element z zadanej pozycji
                cout << "Wprowadz indeks: ";
                cin >> index;
                start = read_QPC();
                lista.removeFromIndex(index);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 7: // Wypelnij tablice losowymi elementami
                cout << "Wprowadz liczbe elementow do wstawienia: ";
                cin >> value;
                start = read_QPC();
                for(int i=0;i<value;i++) lista.addToBack(dist(gen));
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 8: // Wyswietl tablice
                start = read_QPC();
                lista.display();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 9: // Wroc do menu struktur
                return;
                break;
        }
    }
}

void HeapOption()
{
    int value = 0;
    int index = 0;
    int number = 0;

    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000000);

    while(true)
    {
        cout << "\nMENU - KOPIEC: \n1. Dodaj element  \n2. Usun element  \n3. Utworz w dol (algorytm Floyda)  \n4. Utworz w gore (algorytm Floyda) \n5. Wypelnij kopiec losowymi elementami \n6. Wyswietl kopiec jako tablice \n7. Wyswietl kopiec jako drzewo \n8. Wroc do menu struktur \n";
        cin >> number;

        switch(number)
        {
            case 0:
                return;
                break;
            case 1: // Dodaj element
                cout << "Wprowadz element: ";
                cin >> value;
                start = read_QPC();
                kopiec.add(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 2: // Usun element
                start = read_QPC();
                kopiec.deleteFromTop();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 3: // Utworz w dol
                start = read_QPC();
                kopiec.createDown();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 4: // utworz w gore
                start = read_QPC();
                kopiec.createUp();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 5: // Wypelnij kopiec losowymi elementami
                cout << "Wprowadz liczbe elementow do wstawienia: ";
                cin >> value;
                start = read_QPC();
                for(int i=0;i<value;i++) kopiec.add(dist(gen));
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 6: // Wyswietl kopiec jako tablice
                start = read_QPC();
                kopiec.display();
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 7: // Wyswietl kopiec jako drzewo
                start = read_QPC();
                kopiec.display2();
                cout << "\nTime [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 8: // Wroc do menu struktur
                return;
                break;
        }
    }
}

void BSTOption()
{
    int value = 0;
    int index = 0;
    int number = 0;
    BSTItem *node = new BSTItem();

    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000000);

    while(true)
    {
        cout << "\nMENU - BST: \n1. Dodaj element  \n2. Wyswietl INORDER  \n3. Wyswietl PREORDER  \n4. Wyswietl POSTORDER \n5. Usun po kluczu \n6. Wyszukaj iteracyjnie \n7. Wyszukaj rekurencyjnie \n8. Wypelnij drzewo losowymi elementami \n9. Wroc do menu struktur \n";
        cin >> number;

        switch(number)
        {
            case 0:
                return;
                break;
            case 1: // Dodaj element
                cout << "Wprowadz element: ";
                cin >> value;
                start = read_QPC();
                bst.createAndInsert(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 2: // INORDER
                start = read_QPC();
                bst.displayInorder();
                cout << "\nTime [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 3: // PREORDER
                start = read_QPC();
                bst.displayPreorder();
                cout << "\nTime [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 4: // POSTORDER
                start = read_QPC();
                bst.displayPostorder();
                cout << "\nTime [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 5: // Usun po kluczu
                cout << "Wprowadz klucz: ";
                cin >> value;
                start = read_QPC();
                bst.delete1(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 6: // Wyszukaj iteracyjnie
                cout << "Wprowadz wartosc do wyszukania: ";
                cin >> value;
                start = read_QPC();
                bst.searchIT(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 7: // Wyszukaj rekurencyjnie
                cout << "Wprowadz wartosc do wyszukania: ";
                cin >> value;
                start = read_QPC();
                bst.searchREC(value);
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 8: // Wypelnij losowymi elementami
                cout << "Wprowadz liczbe elementow do wstawienia: ";
                cin >> value;
                start = read_QPC();
                for(int i=0;i<value;i++) bst.createAndInsert(dist(gen));
                cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
                frequency << endl;
                cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
                frequency << endl;
                cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
                frequency << endl << endl;
                break;
            case 9: // Wroc do menu struktur
                return;
                break;
        }
    }
}

int main()
{
    int option = 0;

    while(true)
    {
        cout << "\nMENU STRUKTUR: \n1. Tablica dynamiczna \n2. Lista dwukierunkowa \n3. Kopiec binarny \n4. Drzewo BST \n";
        cin >> option;

        switch(option)
        {
            case 0:
                return 0;
                break;
            case 1:
                ArrayOption();
                break;
            case 2:
                ListOption();
                break;
            case 3:
                HeapOption();
                break;
            case 4:
                BSTOption();
                break;
            default:
                break;
        }
    }




/*
    List lista;
    lista.addToFront(10);
    lista.addToFront(11);
    lista.addToFront(12);
    lista.display();
    lista.addToIndex(7,2);
    lista.display();
    lista.removeFromFront();
    lista.display();
    lista.removeFromIndex(2);
    lista.display();*/


/*
    Array tab;
    tab.addToFront(0);
    tab.addToFront(1);
    tab.addToFront(2);
    tab.addToBack(-1);
    tab.addToIndex(7, 2);
    tab.display();
    tab.removeFromIndex(0);
    tab.display();*/

/*
    int tab[] = {7, 5, 9, 6, 7, 8, 10, 1, 11};
    Heap kopiec=Heap(tab,9);
    kopiec.display();
    kopiec.createDown();
    kopiec.display2();*/
/*
    for(int i =0;i<40;i++)kopiec.add(i*2);
    kopiec.display();
    kopiec.deleteFromTop();
    kopiec.display();
    kopiec.display2();*/
    return 0;
}
