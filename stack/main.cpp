#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    int pilihan, data;

    createStack();

    do
    {
        cout << "\n========== MENU STACK ==========\n";
        cout << "1. Push data\n";
        cout << "2. Pop data\n";
        cout << "3. Peek (lihat top)\n";
        cout << "4. Display all\n";
        cout << "5. Size stack\n";
        cout << "6. Clear stack\n";
        cout << "7. Search data\n";
        cout << "8. Replace top\n";
        cout << "9. Lihat bottom (data paling bawah)\n";
        cout << "0. Exit\n";
        cout << "================================\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            displayAll();
            break;

        case 5:
            cout << "Jumlah elemen = " << size() << endl;
            break;

        case 6:
            clear();
            cout << "Stack berhasil dikosongkan!\n";
            break;

        case 7:
        {
            cout << "Masukkan data yang dicari: ";
            cin >> data;
            int pos = search(data);

            if (pos != 0)
            {
                cout << "Data ditemukan di urutan ke " << pos << "\n";
            }
            else
            {
                cout << "Data tidak ditemukan.\n";
            }
        }
        break;

        case 8:
            cout << "Masukkan data baru untuk top: ";
            cin >> data;
            replaceTop(data);
            break;

        case 9:
            cout << "Data paling bawah = " << bottom() << endl;
            break;

        case 0:
            cout << "Keluar program...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
