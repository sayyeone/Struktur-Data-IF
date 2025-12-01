# Queue dengan Linked List - Dokumentasi Lengkap

## Definisi Queue

Queue adalah struktur data dengan prinsip **FIFO (First In, First Out)**. Elemen yang pertama masuk akan pertama keluar, seperti antrian di kasir.

## Struktur Node

```cpp
struct queue {
    int data;
    queue *next;
};
```

Setiap Node memiliki dua bagian:
```
┌──────┬──────┐
│ data │ next │
└──────┴──────┘
```
- `data`: menyimpan nilai integer
- `next`: pointer ke node berikutnya

---

## 1. createQueue() - Inisialisasi Queue

### Kode
```cpp
void createQueue() {
    frontNode = nullptr;
    rearNode = nullptr;
}
```

### Visualisasi
```
frontNode = NULL
rearNode = NULL
```

### Penjelasan
Fungsi ini menginisialisasi queue kosong dengan mengatur pointer `frontNode` (depan) dan `rearNode` (belakang) menjadi `nullptr`. Ini adalah langkah awal sebelum menggunakan queue.

---

## 2. isEmpty() - Pengecekan Queue Kosong

### Kode
```cpp
bool isEmpty() {
    return frontNode == nullptr;
}
```

### Visualisasi Kondisi Queue Kosong
```
frontNode = NULL
rearNode = NULL
return true
```

### Visualisasi Kondisi Queue Tidak Kosong
```
frontNode                    rearNode
    ↓                            ↓
┌────┬─────┐              ┌────┬──────┐
│ 10 │ ... │─────→ ... ───→│ 50 │ NULL │
└────┴─────┘              └────┴──────┘
return false
```

### Penjelasan
Fungsi ini mengecek apakah queue kosong dengan memeriksa apakah `frontNode == nullptr`. Jika `frontNode` menunjuk ke `nullptr`, maka queue kosong dan return `true`. Jika tidak, return `false`.

---

## 3. enqueue(int data) - Menambah Elemen ke Queue

### Kode
```cpp
void enqueue(int data) {
    queue *newNode = new queue();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        frontNode = newNode;
        rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}
```

---

### KASUS A: Enqueue(10) pada Queue KOSONG

#### Kondisi Awal
```
frontNode = NULL
rearNode = NULL
```

#### STEP 1: queue *newNode = new queue();

**Kode:**
```cpp
queue *newNode = new queue();
```

**Visualisasi:**
```
frontNode = NULL
rearNode = NULL


newNode
   ↓
┌────┬─────┐
│ ?? │ ??  │
└────┴─────┘
```

**Penjelasan:**
Alokasi memori baru di heap untuk node baru. Pointer `newNode` dibuat untuk menunjuk ke alamat memori yang baru dialokasikan. Isi dari node masih berupa nilai acak (sampah memori) karena belum diinisialisasi.

#### STEP 2: newNode->data = data;

**Kode:**
```cpp
newNode->data = data; // data = 10
```

**Visualisasi:**
```
frontNode = NULL
rearNode = NULL


newNode
   ↓
┌────┬─────┐
│ 10 │ ??  │
└────┴─────┘
```

**Penjelasan:**
Mengisi bagian `data` dari node baru dengan nilai 10 yang diterima dari parameter fungsi. Sekarang bagian `data` sudah memiliki nilai yang valid, tetapi bagian `next` masih berisi nilai acak.

#### STEP 3: newNode->next = nullptr;

**Kode:**
```cpp
newNode->next = nullptr;
```

**Visualisasi:**
```
frontNode = NULL
rearNode = NULL


newNode
   ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
```

**Penjelasan:**
Mengisi pointer `next` dengan `nullptr` karena node ini akan menjadi node terakhir dalam queue. Setiap node yang baru ditambahkan selalu menjadi node terakhir, sehingga `next`-nya harus `nullptr`.

#### STEP 4: if (isEmpty())

**Kode:**
```cpp
if (isEmpty()) // true, queue kosong
```

**Visualisasi:**
```
frontNode = NULL → isEmpty() = true
rearNode = NULL


newNode
   ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
```

**Penjelasan:**
Pengecekan apakah queue kosong. Karena `frontNode == nullptr`, maka kondisi `isEmpty()` return `true`, sehingga masuk ke blok if untuk kasus queue kosong.

#### STEP 5: frontNode = newNode;

**Kode:**
```cpp
frontNode = newNode;
```

**Visualisasi:**
```
frontNode
    ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘


rearNode = NULL
```

**Penjelasan:**
Karena queue kosong, node baru akan menjadi node pertama sekaligus node terakhir. Pointer `frontNode` diatur untuk menunjuk ke node baru.

#### STEP 6: rearNode = newNode;

**Kode:**
```cpp
rearNode = newNode;
```

**Visualisasi:**
```
frontNode
    ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
    ↑
rearNode
```

**Penjelasan:**
Pointer `rearNode` juga diatur untuk menunjuk ke node yang sama, karena pada queue yang hanya memiliki 1 elemen, `frontNode` dan `rearNode` menunjuk ke node yang sama.

**Hasil Akhir:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘
```

---

### KASUS B: Enqueue(20) pada Queue yang SUDAH ADA ISI

#### Kondisi Awal
Queue memiliki 1 elemen: 10
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘
```

#### STEP 1: queue *newNode = new queue();

**Kode:**
```cpp
queue *newNode = new queue();
```

**Visualisasi:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘


newNode
   ↓
┌────┬─────┐
│ ?? │ ??  │
└────┴─────┘
```

**Penjelasan:**
Alokasi memori baru untuk node baru yang akan ditambahkan ke queue.

#### STEP 2: newNode->data = data;

**Kode:**
```cpp
newNode->data = data; // data = 20
```

**Visualisasi:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘


newNode
   ↓
┌────┬─────┐
│ 20 │ ??  │
└────┴─────┘
```

**Penjelasan:**
Mengisi bagian `data` dari node baru dengan nilai 20.

#### STEP 3: newNode->next = nullptr;

**Kode:**
```cpp
newNode->next = nullptr;
```

**Visualisasi:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘


newNode
   ↓
┌────┬──────┐
│ 20 │ NULL │
└────┴──────┘
```

**Penjelasan:**
Mengisi pointer `next` dengan `nullptr` karena node ini akan menjadi node terakhir.

#### STEP 4: if (isEmpty())

**Kode:**
```cpp
if (isEmpty()) // false, queue ada isi
```

**Visualisasi:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │  → isEmpty() = false
   └────┴──────┘


newNode
   ↓
┌────┬──────┐
│ 20 │ NULL │
└────┴──────┘
```

**Penjelasan:**
Pengecekan apakah queue kosong. Karena `frontNode != nullptr`, maka kondisi `isEmpty()` return `false`, sehingga masuk ke blok else untuk kasus queue sudah ada isi.

#### STEP 5: rearNode->next = newNode;

**Kode:**
```cpp
rearNode->next = newNode;
```

**Visualisasi:**
```
frontNode, rearNode
       ↓
   ┌────┬─────┐      newNode
   │ 10 │  •──┼────→   ↓
   └────┴─────┘      ┌────┬──────┐
                     │ 20 │ NULL │
                     └────┴──────┘
```

**Penjelasan:**
Menghubungkan node terakhir yang ada (node [10]) dengan node baru (node [20]). Sekarang `rearNode->next` menunjuk ke node baru, membentuk linked list: 10 → 20 → NULL.

#### STEP 6: rearNode = newNode;

**Kode:**
```cpp
rearNode = newNode;
```

**Visualisasi:**
```
frontNode                rearNode
    ↓                        ↓
┌────┬─────┐            ┌────┬──────┐
│ 10 │  •──┼───────────→│ 20 │ NULL │
└────┴─────┘            └────┴──────┘
```

**Penjelasan:**
Update pointer `rearNode` agar menunjuk ke node baru. Sekarang node berisi 20 menjadi elemen paling belakang dari queue. Operasi enqueue selesai.

---

### Simulasi Lengkap: 5x Enqueue Berturut-turut

#### Enqueue(10) - Elemen Pertama
**Kondisi Awal:**
```
frontNode = NULL
rearNode = NULL
```

**Hasil:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘
```

#### Enqueue(20) - Elemen Kedua
**Kondisi Awal:**
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 10 │ NULL │
   └────┴──────┘
```

**Hasil:**
```
frontNode                rearNode
    ↓                        ↓
┌────┬─────┐            ┌────┬──────┐
│ 10 │  •──┼───────────→│ 20 │ NULL │
└────┴─────┘            └────┴──────┘
```

#### Enqueue(30) - Elemen Ketiga
**Kondisi Awal:**
```
frontNode                rearNode
    ↓                        ↓
┌────┬─────┐            ┌────┬──────┐
│ 10 │  •──┼───────────→│ 20 │ NULL │
└────┴─────┘            └────┴──────┘
```

**Proses:**
```cpp
rearNode->next = newNode; // 20->next = node[30]
rearNode = newNode;       // rearNode = node[30]
```

**Hasil:**
```
frontNode                              rearNode
    ↓                                      ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
│ 10 │  •──┼─────→│ 20 │  •──┼─────→│ 30 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴──────┘
```

#### Enqueue(40) - Elemen Keempat
**Kondisi Awal:**
```
frontNode                              rearNode
    ↓                                      ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
│ 10 │  •──┼─────→│ 20 │  •──┼─────→│ 30 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Proses:**
```cpp
rearNode->next = newNode; // 30->next = node[40]
rearNode = newNode;       // rearNode = node[40]
```

**Hasil:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 10 │  •──┼─────→│ 20 │  •──┼─────→│ 30 │  •──┼─→│ 40 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

#### Enqueue(50) - Elemen Kelima
**Kondisi Awal:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 10 │  •──┼─────→│ 20 │  •──┼─────→│ 30 │  •──┼─→│ 40 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Proses:**
```cpp
rearNode->next = newNode; // 40->next = node[50]
rearNode = newNode;       // rearNode = node[50]
```

**Hasil:**
```
frontNode                                                          rearNode
    ↓                                                                  ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

---

## 4. dequeue() - Menghapus Elemen dari Depan

### Kode
```cpp
void dequeue() {
    if (isEmpty()) {
        cout << "Queue masih kosong! \n";
        return;
    }

    queue *temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode == nullptr)
        rearNode = nullptr;

    delete temp;
}
```

### Visualisasi Lengkap: Dequeue() pada Queue dengan 5 Elemen

#### Kondisi Awal
```
frontNode                                                          rearNode
    ↓                                                                  ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

#### STEP 1: if (isEmpty())

**Kode:**
```cpp
if (isEmpty()) {
    cout << "Queue masih kosong! \n";
    return;
}
```

**Visualisasi:**
```
frontNode                                                          rearNode
    ↓                                                                  ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘

Pengecekan: frontNode == NULL? → false
Queue tidak kosong, lanjut ke step berikutnya
```

**Penjelasan:**
Sebelum melakukan operasi dequeue, harus dicek terlebih dahulu apakah queue kosong. Jika `frontNode == nullptr`, maka queue kosong dan fungsi akan berhenti dengan `return`. Keyword `return` pada void function berfungsi untuk menghentikan eksekusi fungsi.

#### STEP 2: queue *temp = frontNode;

**Kode:**
```cpp
queue *temp = frontNode;
```

**Visualisasi:**
```
frontNode, temp                                                    rearNode
    ↓                                                                  ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

**Penjelasan:**
Menyimpan alamat node yang akan dihapus ke pointer sementara `temp`. Pointer `temp` dan `frontNode` sekarang menunjuk ke node yang sama, yaitu node berisi 10. Langkah ini penting karena setelah `frontNode` dipindahkan, kita masih membutuhkan referensi ke node yang akan dihapus untuk operasi `delete`.

#### STEP 3: frontNode = frontNode->next;

**Kode:**
```cpp
frontNode = frontNode->next;
```

**Visualisasi Sebelum:**
```
frontNode, temp                                                    rearNode
    ↓                                                                  ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

**Visualisasi Sesudah:**
```
    temp          frontNode                                         rearNode
     ↓                ↓                                                 ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

**Penjelasan:**
Memindahkan pointer `frontNode` ke node berikutnya. `frontNode` yang tadinya menunjuk ke node berisi 10, sekarang menunjuk ke node berisi 20. Node berisi 10 masih ada di memori, hanya saja `frontNode` tidak lagi menunjuk ke sana. Pointer `temp` masih menyimpan alamat node berisi 10 yang akan dihapus.

#### STEP 4: if (frontNode == nullptr)

**Kode:**
```cpp
if (frontNode == nullptr)
    rearNode = nullptr;
```

**Visualisasi:**
```
    temp          frontNode                                         rearNode
     ↓                ↓                                                 ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘

Pengecekan: frontNode == NULL? → false
Kondisi tidak terpenuhi, skip blok if
```

**Penjelasan:**
Pengecekan khusus untuk kasus ketika queue hanya memiliki 1 elemen. Jika setelah `frontNode` dipindahkan ternyata `frontNode` menjadi `nullptr`, artinya queue sekarang kosong, maka `rearNode` juga harus di-set ke `nullptr`. Dalam kasus ini, queue masih memiliki 4 elemen, jadi kondisi ini tidak terpenuhi.

#### STEP 5: delete temp;

**Kode:**
```cpp
delete temp;
```

**Visualisasi Sebelum Delete:**
```
    temp          frontNode                                         rearNode
     ↓                ↓                                                 ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

**Visualisasi Sesudah Delete:**
```
   ╔════╗         frontNode                                         rearNode
   ║ XX ║              ↓                                                 ↓
   ╚════╝         ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
  (DIHAPUS!)      │ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
                  └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
```

**Visualisasi Hasil Akhir:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Penjelasan:**
Operasi `delete temp` benar-benar menghapus node dari memori dan mengembalikan memori tersebut ke sistem operasi. Setelah di-delete, node berisi 10 tidak lagi ada. Queue sekarang memiliki 4 elemen: 20, 30, 40, 50.

---

### Mengapa Perlu Pointer temp?

#### Cara Yang Salah
```cpp
// JANGAN SEPERTI INI!
frontNode = frontNode->next;  // Pindah frontNode dulu
delete frontNode;             // ERROR! Menghapus node yang salah!
```

**Visualisasi Cara Salah:**
```
STEP 1: frontNode = frontNode->next
    
              frontNode                                         rearNode
                  ↓                                                 ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘
    ↑
(Node ini yang seharusnya dihapus!)

STEP 2: delete frontNode
              ╔════╗
              ║ XX ║          ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
┌────┬─────┐  ╚════╝          │ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
│ 10 │  •──┼──→ (SALAH!)      └────┴─────┘   └────┴─────┘   └────┴──────┘
└────┴─────┘
    ↑
(Node ini tidak terhapus, MEMORY LEAK!)
```

#### Cara Yang Benar
```cpp
// BENAR!
queue *temp = frontNode;  // Simpan alamat node yang mau dihapus
frontNode = frontNode->next;  // Pindahkan frontNode
delete temp;  // Hapus node yang benar
```

**Visualisasi Cara Benar:**
```
STEP 1: queue *temp = frontNode (Simpan alamat)

frontNode, temp                                                    rearNode
    ↓                                                                  ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘

STEP 2: frontNode = frontNode->next (Pindah frontNode)

    temp          frontNode                                         rearNode
     ↓                ↓                                                 ↓
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
│ 10 │  •──┼──→│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
└────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴──────┘

STEP 3: delete temp (Hapus node yang benar)

   ╔════╗         frontNode                                         rearNode
   ║ XX ║              ↓                                                 ↓
   ╚════╝         ┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ┌────┬──────┐
  (BENAR!)        │ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→│ 50 │ NULL │
                  └────┴─────┘   └────┴─────┘   └────┴─────┘   └────┴



---

## 5. peekFront() - Melihat Elemen Depan

### Kode
```cpp
int peekFront() {
    if (isEmpty()) {
        cout << "Queue masih kosong! \n";
        return -1;
    }
    return frontNode->data;
}
```

### Visualisasi: Queue dengan 4 Elemen

**Kondisi Queue:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Proses peekFront():**
```cpp
if (isEmpty())         // false, queue tidak kosong
return frontNode->data;  // return 20
```

**Hasil:**
```
Output: 20

Queue tetap:
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
(Tidak ada perubahan)
```

### Penjelasan
Fungsi `peekFront()` hanya melihat nilai elemen paling depan tanpa menghapusnya. Fungsi ini mengakses `frontNode->data` untuk mendapatkan nilai, tetapi tidak mengubah struktur queue sama sekali.

---

## 6. peekRear() - Melihat Elemen Belakang

### Kode
```cpp
int peekRear() {
    if (isEmpty()) {
        cout << "Queue masih kosong!\n";
        return -1;
    }
    return rearNode->data;
}
```

### Visualisasi: Queue dengan 4 Elemen

**Kondisi Queue:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Proses peekRear():**
```cpp
if (isEmpty())        // false, queue tidak kosong
return rearNode->data;  // return 50
```

**Hasil:**
```
Output: 50

Queue tetap:
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
(Tidak ada perubahan)
```

### Perbedaan: peekFront() vs peekRear()

#### peekFront() - Lihat Depan
```cpp
peekFront();  // Langsung akses frontNode->data
```
```
frontNode ← LIHAT INI                                rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

peekFront() → return 20
⏱️ Kompleksitas: O(1) - konstan
```

#### peekRear() - Lihat Belakang
```cpp
peekRear();  // Langsung akses rearNode->data
```
```
frontNode                                            rearNode ← LIHAT INI
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

peekRear() → return 50
⏱️ Kompleksitas: O(1) - konstan
```

### Penjelasan
Kedua fungsi peek ini sangat efisien karena kita memiliki pointer `frontNode` dan `rearNode`. Kita bisa langsung akses elemen depan dan belakang tanpa perlu traversal. Ini adalah keuntungan dari implementasi queue dengan dua pointer.

---

## 7. displayAll() - Tampilkan Semua Elemen

### Kode
```cpp
void displayAll() {
    if (isEmpty()) {
        cout << "Queue masih kosong! \n";
        return;
    }
    
    queue *temp = frontNode;
    cout << "Isi node dari depan -> belakang: \n";
    while (temp != nullptr) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}
```

### Visualisasi: Traversal Queue

**Kondisi Queue:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Iterasi 1:**
```cpp
queue *temp = frontNode;  // temp menunjuk ke node [20]
```
```
frontNode, temp                                      rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

cout << temp->data << "\n";  // Output: "20"
temp = temp->next;           // temp pindah ke node [30]
```

**Iterasi 2:**
```cpp
// temp sekarang menunjuk ke node [30]
```
```
frontNode          temp                              rearNode
    ↓               ↓                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

cout << temp->data << "\n";  // Output: "30"
temp = temp->next;           // temp pindah ke node [40]
```

**Iterasi 3:**
```cpp
// temp sekarang menunjuk ke node [40]
```
```
frontNode                       temp                 rearNode
    ↓                            ↓                       ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

cout << temp->data << "\n";  // Output: "40"
temp = temp->next;           // temp pindah ke node [50]
```

**Iterasi 4:**
```cpp
// temp sekarang menunjuk ke node [50]
```
```
frontNode                                            rearNode, temp
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

cout << temp->data << "\n";  // Output: "50"
temp = temp->next;           // temp = NULL
```

**Iterasi 5:**
```cpp
// temp = NULL, keluar dari loop
```
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
                                                              ↓
                                                         temp = NULL
                                                       (Loop berhenti)

Output lengkap: 
"Isi node dari depan -> belakang:
20
30
40
50"
```

### Penjelasan
Fungsi `displayAll()` menggunakan pointer sementara `temp` untuk melakukan traversal dari `frontNode` sampai `nullptr`. Pointer `temp` bergerak dari node ke node mengikuti pointer `next`, mencetak nilai `data` di setiap node. Queue sendiri tidak berubah karena hanya operasi pembacaan.

---

## 8. clearQueue() - Hapus Semua Elemen

### Kode
```cpp
void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}
```

### Visualisasi: Clear Queue dengan 4 Elemen

**Kondisi Awal:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Iterasi 1: dequeue() - Hapus 20**
```cpp
while (!isEmpty())  // true (queue ada isi)
    dequeue();      // hapus elemen depan
```
```
frontNode                              rearNode
    ↓                                      ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
│ 30 │  •──┼─────→│ 40 │  •──┼─────→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Iterasi 2: dequeue() - Hapus 30**
```cpp
while (!isEmpty())  // true (masih ada isi)
    dequeue();      // hapus elemen depan
```
```
frontNode                rearNode
    ↓                        ↓
┌────┬─────┐            ┌────┬──────┐
│ 40 │  •──┼───────────→│ 50 │ NULL │
└────┴─────┘            └────┴──────┘
```

**Iterasi 3: dequeue() - Hapus 40**
```cpp
while (!isEmpty())  // true (masih ada 2 elemen)
    dequeue();      // hapus elemen depan
```
```
frontNode, rearNode
       ↓
   ┌────┬──────┐
   │ 50 │ NULL │
   └────┴──────┘
```

**Iterasi 4: dequeue() - Hapus 50**
```cpp
while (!isEmpty())  // true (masih ada 1 elemen)
    dequeue();      // hapus elemen terakhir
```
```
frontNode = NULL
rearNode = NULL
(Queue kosong)
```

**Iterasi 5: Cek kondisi**
```cpp
while (!isEmpty())  // false (queue kosong)
    // Loop berhenti
```

**Hasil Akhir:**
```
frontNode = NULL
rearNode = NULL
Queue berhasil dikosongkan!
```

### Penjelasan
Fungsi `clearQueue()` menggunakan loop untuk memanggil `dequeue()` secara berulang sampai queue kosong. Setiap iterasi, elemen depan dihapus sampai `isEmpty()` return `true`. Ini adalah cara yang aman dan efisien untuk mengosongkan queue karena memanfaatkan fungsi `dequeue()` yang sudah memiliki mekanisme penghapusan yang benar.

---

## 9. isFull() - Cek Queue Penuh

### Kode
```cpp
bool isFull() {
    return false;
}
```

### Visualisasi
```
Queue dengan Linked List: TIDAK PERNAH PENUH!
(Selama ada memori tersedia)

return false
```

### Penjelasan
Berbeda dengan queue yang diimplementasikan dengan array (yang memiliki ukuran tetap), queue dengan linked list bersifat dinamis. Queue bisa terus bertambah selama masih ada memori yang tersedia di sistem. Oleh karena itu, fungsi ini selalu return `false`.

**Perbandingan:**
```
Queue Array (Fixed Size):
MAX_SIZE = 5
┌────┬────┬────┬────┬────┐
│ 20 │ 30 │ 40 │ 50 │ 60 │ ← PENUH! isFull() = true
└────┴────┴────┴────┴────┘

Queue Linked List (Dynamic):
┌────┬─────┐   ┌────┬─────┐   ┌────┬─────┐   ... → ∞
│ 20 │  •──┼──→│ 30 │  •──┼──→│ 40 │  •──┼──→
└────┴─────┘   └────┴─────┘   └────┴─────┘
                    ↑
              TIDAK PERNAH PENUH! isFull() = false
```

---

## 10. currentSize() - Hitung Jumlah Elemen

### Kode
```cpp
int currentSize() {
    int count = 0;
    queue *temp = frontNode;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
```

### Visualisasi: Menghitung Elemen

**Kondisi Queue:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Iterasi 1:**
```cpp
int count = 0;
queue *temp = frontNode;  // temp → node [20]
```
```
frontNode, temp                                      rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

count++;              // count = 1
temp = temp->next;    // temp pindah ke [30]
```

**Iterasi 2:**
```
frontNode          temp                              rearNode
    ↓               ↓                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

count++;              // count = 2
temp = temp->next;    // temp pindah ke [40]
```

**Iterasi 3:**
```
frontNode                       temp                 rearNode
    ↓                            ↓                       ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

count++;              // count = 3
temp = temp->next;    // temp pindah ke [50]
```

**Iterasi 4:**
```
frontNode                                            rearNode, temp
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

count++;              // count = 4
temp = temp->next;    // temp = NULL
```

**Iterasi 5:**
```
temp = NULL → Loop berhenti

return count;  // return 4
```

### Penjelasan
Fungsi `currentSize()` bekerja dengan cara traversal dari `frontNode` sampai `nullptr`, sambil menghitung berapa kali loop berjalan. Setiap kali menemukan node, variabel `count` ditambah 1. Ketika `temp` mencapai `nullptr`, loop berhenti dan function mengembalikan nilai `count`.

---

## 11. search(int value) - Cari Elemen

### Kode
```cpp
int search(int value) {
    queue *temp = frontNode;
    int indeks = 1;
    while (temp != nullptr) {
        if (temp->data == value)
            return indeks;
        temp = temp->next;
        indeks++;
    }
    return 0; // tidak ditemukan
}
```

### Visualisasi: Mencari Nilai 40

**Kondisi Queue:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Iterasi 1: Cek node [20]**
```cpp
queue *temp = frontNode;
int indeks = 1;
```
```
frontNode, temp [indeks=1]                           rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

if (temp->data == 40)  // 20 == 40? false
temp = temp->next;     // pindah ke [30]
indeks++;              // indeks = 2
```

**Iterasi 2: Cek node [30]**
```
frontNode          temp [indeks=2]                   rearNode
    ↓               ↓                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

if (temp->data == 40)  // 30 == 40? false
temp = temp->next;     // pindah ke [40]
indeks++;              // indeks = 3
```

**Iterasi 3: Cek node [40]**
```
frontNode                       temp [indeks=3]      rearNode
    ↓                            ↓                       ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

if (temp->data == 40)  // 40 == 40? TRUE!
return indeks;         // return 3 (DITEMUKAN!)
```

**Hasil:**
```
search(40) → return 3
Nilai 40 ditemukan di posisi ke-3 dari depan
```

### Contoh:isasi
```
frontNode = NULL
rearNode = NULL
```

### Penjelasan
Fungsi ini menginisialisasi queue kosong dengan mengatur pointer `frontNode` (depan) dan `rearNode` (belakang) menjadi `nullptr`. Ini adalah langkah awal sebelum menggunakan queue.

---

## 11. search(int value) - Cari Elemen

### Kode
```cpp
int search(int value) {
    queue *temp = frontNode;
    int indeks = 1;
    while (temp != nullptr) {
        if (temp->data == value)
            return indeks;
        temp = temp->next;
        indeks++;
    }
    return 0; // tidak ditemukan
}
```

### Visualisasi: Mencari Nilai 40

**Kondisi Queue:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Iterasi 1: Cek node [20]**
```cpp
queue *temp = frontNode;
int indeks = 1;
```
```
frontNode, temp [indeks=1]                           rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

if (temp->data == 40)  // 20 == 40? false
temp = temp->next;     // pindah ke [30]
indeks++;              // indeks = 2
```

**Iterasi 2: Cek node [30]**
```
frontNode          temp [indeks=2]                   rearNode
    ↓               ↓                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

if (temp->data == 40)  // 30 == 40? false
temp = temp->next;     // pindah ke [40]
indeks++;              // indeks = 3
```

**Iterasi 3: Cek node [40]**
```
frontNode                       temp [indeks=3]      rearNode
    ↓                            ↓                       ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

if (temp->data == 40)  // 40 == 40? TRUE!
return indeks;         // return 3 (DITEMUKAN!)
```

**Hasil:**
```
search(40) → return 3
Nilai 40 ditemukan di posisi ke-3 dari depan
```

### Contoh: Mencari Nilai Yang Tidak Ada

**Mencari nilai 99:**
```cpp
search(99);
```

**Iterasi 1: Cek [20]**
```
temp → [20]
if (20 == 99) → false
indeks = 2, temp → [30]
```

**Iterasi 2: Cek [30]**
```
temp → [30]
if (30 == 99) → false
indeks = 3, temp → [40]
```

**Iterasi 3: Cek [40]**
```
temp → [40]
if (40 == 99) → false
indeks = 4, temp → [50]
```

**Iterasi 4: Cek [50]**
```
temp → [50]
if (50 == 99) → false
indeks = 5, temp → NULL
```

**Iterasi 5:**
```
temp = NULL → Loop berhenti
return 0;  // TIDAK DITEMUKAN
```

**Hasil:**
```
search(99) → return 0
Nilai 99 tidak ditemukan dalam queue
```

### Penjelasan
Fungsi `search()` melakukan linear search dari depan ke belakang. Setiap node dicek apakah `data`-nya sama dengan nilai yang dicari. Jika ditemukan, langsung return posisinya (dimulai dari 1). Jika sampai akhir queue tidak ditemukan, return 0 sebagai tanda "tidak ada".

---

## 12. replaceFront(int value) - Ganti Nilai Depan

### Kode
```cpp
void replaceFront(int value) {
    if (isEmpty()) {
        cout << "Queue masih kosong!\n";
        return;
    }
    frontNode->data = value;
}
```

### Visualisasi: Replace Front dengan Nilai 99

**Kondisi Awal:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 20 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Proses: replaceFront(99)**
```cpp
if (isEmpty())       // false, queue ada isi
frontNode->data = 99;  // ubah data di node depan
```

**Kondisi Sesudah:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 99 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
    ↑
BERUBAH!
```

### Perbandingan: replaceFront() vs dequeue() + enqueue()

#### Cara 1: Menggunakan replaceFront() ✅
```cpp
replaceFront(99);  // Langsung ganti nilai
```
```
SEBELUM:  20 → 30 → 40 → 50
SESUDAH:  99 → 30 → 40 → 50

✅ Cepat (1 operasi)
✅ Efisien (tidak alokasi memori baru)
✅ Struktur queue tetap sama
```

#### Cara 2: Menggunakan dequeue() + enqueue() ❌
```cpp
dequeue();    // Hapus 20
enqueue(99);  // Tambah 99 di belakang
```
```
SEBELUM:  20 → 30 → 40 → 50
dequeue():     30 → 40 → 50 (hapus node [20])
enqueue():     30 → 40 → 50 → 99 (99 di belakang, SALAH!)

❌ Lambat (2 operasi)
❌ Tidak efisien (delete + alokasi memori)
❌ Posisi salah (99 di belakang, bukan depan!)
```

### Penjelasan
Fungsi `replaceFront()` mengubah nilai elemen paling depan tanpa mengubah struktur queue. Ini lebih efisien daripada menghapus dan menambah node baru karena hanya mengubah field `data` tanpa operasi memori yang mahal.

---

## 13. replaceRear(int value) - Ganti Nilai Belakang

### Kode
```cpp
void replaceRear(int value) {
    if (isEmpty()) {
        cout << "Queue masih kosong!\n";
        return;
    }
    rearNode->data = value;
}
```

### Visualisasi: Replace Rear dengan Nilai 88

**Kondisi Awal:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 99 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
```

**Proses: replaceRear(88)**
```cpp
if (isEmpty())      // false, queue ada isi
rearNode->data = 88;  // ubah data di node belakang
```

**Kondisi Sesudah:**
```
frontNode                                            rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 99 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 88 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘
                                                        ↑
                                                    BERUBAH!
```

### Perbandingan: replaceFront() vs replaceRear()

#### replaceFront() - Ganti Depan
```cpp
replaceFront(99);  // Langsung ubah frontNode->data
```
```
frontNode ← UBAH INI                                 rearNode
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 99 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 50 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

⏱️ Kompleksitas: O(1) - konstan
```

#### replaceRear() - Ganti Belakang
```cpp
replaceRear(88);  // Langsung ubah rearNode->data
```
```
frontNode                                            rearNode ← UBAH INI
    ↓                                                    ↓
┌────┬─────┐      ┌────┬─────┐      ┌────┬─────┐  ┌────┬──────┐
│ 99 │  •──┼─────→│ 30 │  •──┼─────→│ 40 │  •──┼─→│ 88 │ NULL │
└────┴─────┘      └────┴─────┘      └────┴─────┘  └────┴──────┘

⏱️ Kompleksitas: O(1) - konstan
```

### Penjelasan
Kedua fungsi replace ini sangat efisien karena kita memiliki pointer `frontNode` dan `rearNode`. Kita bisa langsung akses dan mengubah elemen depan dan belakang tanpa perlu traversal. Ini adalah keuntungan besar dari implementasi queue dengan dua pointer dibandingkan dengan implementasi yang hanya memiliki satu pointer.

---

## 📊 Tabel Ringkasan Kompleksitas Waktu

| Operasi | Kompleksitas | Penjelasan |
|---------|-------------|------------|
| `createQueue()` | O(1) | Hanya set 2 pointer ke NULL |
| `isEmpty()` | O(1) | Hanya cek 1 kondisi |
| `enqueue()` | O(1) | Insert di rear, tidak perlu traversal |
| `dequeue()` | O(1) | Delete dari front, tidak perlu traversal |
| `peekFront()` | O(1) | Akses langsung ke frontNode |
| `peekRear()` | O(1) | Akses langsung ke rearNode |
| `displayAll()` | O(n) | Harus print semua node |
| `clearQueue()` | O(n) | Harus dequeue semua node |
| `isFull()` | O(1) | Selalu return false |
| `currentSize()` | O(n) | Harus hitung semua node |
| `search()` | O(n) | Worst case: cek semua node |
| `replaceFront()` | O(1) | Hanya ubah 1 field di depan |
| `replaceRear()` | O(1) | Hanya ubah 1 field di belakang |

**Keterangan:**
- **O(1)** = Constant time, sangat cepat, tidak terpengaruh ukuran queue
- **O(n)** = Linear time, waktu bertambah sebanding dengan jumlah elemen

---

## 🎯 Keuntungan Queue dengan Linked List

### ✅ Kelebihan

1. **Ukuran Dinamis**
   ```
   Tidak ada batasan ukuran seperti array
   Queue bisa tumbuh sesuai kebutuhan (selama ada memori)
   ```

2. **Efisiensi Enqueue/Dequeue**
   ```
   Operasi enqueue dan dequeue O(1) - sangat cepat
   Tidak perlu shift elemen seperti di array
   ```

3. **Tidak Ada Memory Waste**
   ```
   Hanya alokasi memori sesuai kebutuhan
   Tidak ada space kosong yang terbuang
   ```

4. **Akses Depan dan Belakang O(1)**
   ```
   Dengan 2 pointer (frontNode & rearNode)
   Bisa akses kedua ujung dengan cepat
   ```

### ❌ Kekurangan

1. **Extra Memory untuk Pointer**
   ```
   Setiap node butuh extra space untuk pointer next
   Node: [data | next] = 4 bytes + 8 bytes (64-bit) = 12 bytes
   ```

2. **Tidak Bisa Random Access**
   ```
   Tidak bisa langsung akses elemen tengah
   Harus traversal dari front
   ```

3. **Cache Locality Buruk**
   ```
   Node tersebar di memori, tidak bersebelahan
   Array lebih baik untuk cache performance
   ```

---

## 💡 Kapan Menggunakan Queue?

### Use Cases Queue

1. **Task Scheduling / Job Queue**
   ```
   Print Queue:
   [Doc1] → [Doc2] → [Doc3]
   ↑ front           ↑ rear
   
   Doc1 dicetak dulu (FIFO)
   ```

2. **BFS (Breadth-First Search)**
   ```
   Graph Traversal:
   Queue: [A]
   Queue: [B, C]
   Queue: [C, D, E]
   ...
   ```

3. **Message Queue**
   ```
   Sistem Chat:
   [Msg1] → [Msg2] → [Msg3]
   
   Pesan diproses sesuai urutan masuk
   ```

4. **Buffer untuk Streaming**
   ```
   Video Buffer:
   [Frame1] → [Frame2] → [Frame3]
   
   Frame dimainkan sesuai urutan
   ```

5. **Customer Service Queue**
   ```
   Antrian Pelanggan:
   [Customer1] → [Customer2] → [Customer3]
   
   Pelanggan dilayani sesuai urutan datang
   ```

---

## 🧪 Contoh Program Lengkap

```cpp
#include <iostream>
using namespace std;

struct queue {
    int data;
    queue *next;
};

queue *frontNode = nullptr;
queue *rearNode = nullptr;

// ===== FUNGSI-FUNGSI QUEUE =====

void createQueue() {
    frontNode = nullptr;
    rearNode = nullptr;
}

bool isEmpty() {
    return frontNode == nullptr;
}

void enqueue(int data) {
    queue *newNode = new queue();
    newNode->data = data;
    newNode->next = nullptr;
    
    if (isEmpty()) {
        frontNode = newNode;
        rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    cout << "✅ Enqueue " << data << " berhasil!\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "❌ Queue kosong!\n";
        return;
    }
    
    queue *temp = frontNode;
    int removedData = frontNode->data;
    frontNode = frontNode->next;
    
    if (frontNode == nullptr)
        rearNode = nullptr;
    
    delete temp;
    cout << "✅ Dequeue " << removedData << " berhasil!\n";
}

int peekFront() {
    if (isEmpty()) {
        cout << "❌ Queue kosong!\n";
        return -1;
    }
    return frontNode->data;
}

int peekRear() {
    if (isEmpty()) {
        cout << "❌ Queue kosong!\n";
        return -1;
    }
    return rearNode->data;
}

void displayAll() {
    if (isEmpty()) {
        cout << "❌ Queue kosong!\n";
        return;
    }
    
    queue *temp = frontNode;
    cout << "\n📋 Isi Queue (depan → belakang):\n";
    cout << "┌─────┐\n";
    while (temp != nullptr) {
        cout << "│ " << temp->data << "   │";
        if (temp == frontNode) cout << " ← front";
        if (temp == rearNode) cout << " ← rear";
        cout << "\n";
        temp = temp->next;
    }
    cout << "└─────┘\n";
}

void clearQueue() {
    while (!isEmpty()) {
        dequeue();
    }
    cout << "✅ Queue berhasil dikosongkan!\n";
}

bool isFull() {
    return false;
}

int currentSize() {
    int count = 0;
    queue *temp = frontNode;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int search(int value) {
    queue *temp = frontNode;
    int indeks = 1;
    while (temp != nullptr) {
        if (temp->data == value)
            return indeks;
        temp = temp->next;
        indeks++;
    }
    return 0;
}

void replaceFront(int value) {
    if (isEmpty()) {
        cout << "❌ Queue kosong!\n";
        return;
    }
    int oldValue = frontNode->data;
    frontNode->data = value;
    cout << "✅ Front berhasil diganti: " << oldValue << " → " << value << "\n";
}

void replaceRear(int value) {
    if (isEmpty()) {
        cout << "❌ Queue kosong!\n";
        return;
    }
    int oldValue = rearNode->data;
    rearNode->data = value;
    cout << "✅ Rear berhasil diganti: " << oldValue << " → " << value << "\n";
}

// ===== MAIN PROGRAM =====

int main() {
    createQueue();
    
    cout << "\n========== DEMO QUEUE ==========\n\n";
    
    // Enqueue beberapa elemen
    cout << "--- ENQUEUE OPERATION ---\n";
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    // Display queue
    displayAll();
    
    // Peek front dan rear
    cout << "\n--- PEEK OPERATION ---\n";
    cout << "🔝 Front = " << peekFront() << "\n";
    cout << "🔻 Rear = " << peekRear() << "\n";
    
    // Size
    cout << "\n--- SIZE OPERATION ---\n";
    cout << "📊 Ukuran queue: " << currentSize() << " elemen\n";
    
    // Search
    cout << "\n--- SEARCH OPERATION ---\n";
    int cari = 30;
    int hasil = search(cari);
    if (hasil != 0)
        cout << "🔍 Nilai " << cari << " ditemukan di posisi " << hasil << "\n";
    else
        cout << "❌ Nilai " << cari << " tidak ditemukan\n";
    
    // Replace front dan rear
    cout << "\n--- REPLACE OPERATION ---\n";
    replaceFront(99);
    replaceRear(88);
    displayAll();
    
    // Dequeue beberapa elemen
    cout << "\n--- DEQUEUE OPERATION ---\n";
    dequeue();
    dequeue();
    displayAll();
    
    // Clear queue
    cout << "\n--- CLEAR OPERATION ---\n";
    clearQueue();
    displayAll();
    
    cout << "\n========== DEMO SELESAI ==========\n";
    
    return 0;
}
```

### Output Program:

```
========== DEMO QUEUE ==========

--- ENQUEUE OPERATION ---
✅ Enqueue 10 berhasil!
✅ Enqueue 20 berhasil!
✅ Enqueue 30 berhasil!
✅ Enqueue 40 berhasil!
✅ Enqueue 50 berhasil!

📋 Isi Queue (depan → belakang):
┌─────┐
│ 10   │ ← front
│ 20   │
│ 30   │
│ 40   │
│ 50   │ ← rear
└─────┘

--- PEEK OPERATION ---
🔝 Front = 10
🔻 Rear = 50

--- SIZE OPERATION ---
📊 Ukuran queue: 5 elemen

--- SEARCH OPERATION ---
🔍 Nilai 30 ditemukan di posisi 3

--- REPLACE OPERATION ---
✅ Front berhasil diganti: 10 → 99
✅ Rear berhasil diganti: 50 → 88

📋 Isi Queue (depan → belakang):
┌─────┐
│ 99   │ ← front
│ 20   │
│ 30   │
│ 40   │
│ 88   │ ← rear
└─────┘

--- DEQUEUE OPERATION ---
✅ Dequeue 99 berhasil!
✅ Dequeue 20 berhasil!

📋 Isi Queue (depan → belakang):
┌─────┐
│ 30   │ ← front
│ 40   │
│ 88   │ ← rear
└─────┘

--- CLEAR OPERATION ---
✅ Dequeue 30 berhasil!
✅ Dequeue 40 berhasil!
✅ Dequeue 88 berhasil!
✅ Queue berhasil dikosongkan!
❌ Queue kosong!

========== DEMO SELESAI ==========
```

---

## 🎓 Kesimpulan

### Konsep Penting Queue

1. **FIFO (First In, First Out)**
   - Elemen pertama masuk = pertama keluar
   - Seperti antrian di kasir

2. **Dua Pointer Penting**
   - `frontNode` = menunjuk ke elemen paling depan (untuk dequeue)
   - `rearNode` = menunjuk ke elemen paling belakang (untuk enqueue)

3. **Operasi Utama**
   - `enqueue()` = tambah di belakang (O(1))
   - `dequeue()` = hapus dari depan (O(1))
   - `peekFront()` = lihat yang paling depan (O(1))
   - `peekRear()` = lihat yang paling belakang (O(1))

4. **Memory Management**
   - Selalu `delete` node yang tidak terpakai
   - Gunakan pointer sementara (`temp`)
   - Jangan lupa set `rearNode = nullptr` saat queue kosong!
---
