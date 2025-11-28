#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    createQueue();

    int pilihan, data, value;

    do
    {
        cout << "===========MENU QUEUE =========\n";
        cout << "1. Enqueue (Tambah Data)\n";
        cout << "2. Dequeue (Hapus Data Depan)\n";
        cout << "3. Peek Front\n";
        cout << "4. Peek Rear\n";
        cout << "5. Tampilkan Semua Data\n";
        cout << "6. Clear Queue\n";
        cout << "7. Current Size\n";
        cout << "8. Cari Data\n";
        cout << "9. Replace Front (Ganti data depan)\n";
        cout << "10. Replace Rear (Ganti data belakang)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            cout << "Data di Front: " << peekFront() << endl;
            break;

        case 4:
            cout << "Data di Rear: " << peekRear() << endl;
            break;

        case 5:
            displayAll();
            break;

        case 6:
            clearQueue();
            cout << "Queue berhasil dikosongkan!\n";
            break;

        case 7:
            cout << "Jumlah node dalam queue = " << currentSize() << endl;
            break;

        case 8:
        {
            cout << "Masukkan angka yang dicari: ";
            cin >> value;
            int pos = search(value);

            if (pos != 0)
                cout << "Data ditemukan di urutan ke: " << pos << "\n";
            else
                cout << "Data tidak ditemukan.\n";
        }
        break;

        case 9:
        {
            cout << "Masukkan nilai baru untuk FRONT: ";
            cin >> value;
            replaceFront(value);
        }
        break;

        case 10:
        {
            cout << "Masukkan nilai baru untuk REAR: ";
            cin >> value;
            replaceRear(value);
        }
        break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
