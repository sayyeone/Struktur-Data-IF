# Stack dengan Linked List - Dokumentasi Lengkap

## Definisi Stack

Stack adalah struktur data dengan prinsip **LIFO (Last In, First Out)**. Elemen yang terakhir masuk akan pertama keluar, seperti tumpukan piring.

## Struktur Node

```cpp
struct Node {
    int data;
    Node *next;
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

## 1. createStack() - Inisialisasi Stack

### Kode
```cpp
void createStack() {
    top = nullptr;
}
```

### Visualisasi
```
top = NULL
```

### Penjelasan
Fungsi ini menginisialisasi stack kosong dengan mengatur pointer `top` menjadi `nullptr`. Ini adalah langkah awal sebelum menggunakan stack.

---

## 2. isEmpty() - Pengecekan Stack Kosong

### Kode
```cpp
bool isEmpty() {
    return top == nullptr;
}
```

### Visualisasi Kondisi Stack Kosong
```
top = NULL
return true
```

### Visualisasi Kondisi Stack Tidak Kosong
```
top
 ↓
┌────┬─────┐
│ 10 │ ... │
└────┴─────┘
return false
```

### Penjelasan
Fungsi ini mengecek apakah stack kosong dengan memeriksa apakah `top == nullptr`. Jika `top` menunjuk ke `nullptr`, maka stack kosong dan return `true`. Jika tidak, return `false`.

---

## 3. push(int data) - Menambah Elemen ke Stack

### Kode
```cpp
void push(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
```

### Visualisasi Lengkap: Push(50) pada Stack yang Sudah Ada Isi

#### Kondisi Awal
Stack memiliki 2 elemen: 30 dan 20
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘
```

#### STEP 1: Node *newNode = new Node();

**Kode:**
```cpp
Node *newNode = new Node();
```

**Visualisasi:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘


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
newNode->data = data; // data = 50
```

**Visualisasi:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘


                       newNode
                          ↓
                       ┌────┬─────┐
                       │ 50 │ ??  │
                       └────┴─────┘
```

**Penjelasan:**
Mengisi bagian `data` dari node baru dengan nilai 50 yang diterima dari parameter fungsi. Sekarang bagian `data` sudah memiliki nilai yang valid, tetapi bagian `next` masih berisi nilai acak.

#### STEP 3: newNode->next = top;

**Kode:**
```cpp
newNode->next = top;
```

**Visualisasi:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘
       ↑
       │
       │              newNode
       │                 ↓
       │              ┌────┬─────┐
       └──────────────┼─•  │ 50  │
                      └─────┴────┘
```

**Penjelasan:**
Menghubungkan node baru dengan stack yang sudah ada. `newNode->next` diisi dengan alamat yang ditunjuk oleh `top`, yaitu node berisi 30. Sekarang node baru sudah terhubung dengan linked list yang ada, membentuk rantai: newNode → 30 → 20 → NULL.

#### STEP 4: top = newNode;

**Kode:**
```cpp
top = newNode;
```

**Visualisasi:**
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Penjelasan:**
Update pointer `top` agar menunjuk ke node baru. Sekarang node berisi 50 menjadi elemen paling atas dari stack. Operasi push selesai, stack memiliki 3 elemen dengan urutan 50, 30, 20 dari atas ke bawah.

---

### Contoh Kasus: Push dari Stack Kosong

#### Push(10) - Elemen Pertama

**Kondisi Awal:**
```
top = NULL
```

**STEP 1: Node *newNode = new Node();**
```cpp
Node *newNode = new Node();
```
```
top = NULL


newNode
   ↓
┌────┬─────┐
│ ?? │ ??  │
└────┴─────┘
```

**STEP 2: newNode->data = data;**
```cpp
newNode->data = 10;
```
```
top = NULL


newNode
   ↓
┌────┬─────┐
│ 10 │ ??  │
└────┴─────┘
```

**STEP 3: newNode->next = top;**
```cpp
newNode->next = top; // top = NULL
```
```
newNode
   ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
```
Karena `top` adalah `NULL`, maka `newNode->next` juga menjadi `NULL`. Ini menandakan bahwa node ini adalah elemen terakhir dalam linked list.

**STEP 4: top = newNode;**
```cpp
top = newNode;
```
```
top
 ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
```

#### Push(20) - Elemen Kedua

**Kondisi Awal:**
```
top
 ↓
┌────┬──────┐
│ 10 │ NULL │
└────┴──────┘
```

**STEP 1: Node *newNode = new Node();**
```cpp
Node *newNode = new Node();
```
```
top
 ↓
┌────┬──────┐        newNode
│ 10 │ NULL │           ↓
└────┴──────┘        ┌────┬─────┐
                     │ ?? │ ??  │
                     └────┴─────┘
```

**STEP 2: newNode->data = data;**
```cpp
newNode->data = 20;
```
```
top
 ↓
┌────┬──────┐        newNode
│ 10 │ NULL │           ↓
└────┴──────┘        ┌────┬─────┐
                     │ 20 │ ??  │
                     └────┴─────┘
```

**STEP 3: newNode->next = top;**
```cpp
newNode->next = top;
```
```
top
 ↓
┌────┬──────┐        newNode
│ 10 │ NULL │           ↓
└────┴──────┘        ┌────┬─────┐
  ↑                  │ 20 │  •──┼─┐
  │                  └────┴─────┘ │
  └────────────────────────────────┘
```
Sekarang `newNode->next` menunjuk ke node yang berisi 10.

**STEP 4: top = newNode;**
```cpp
top = newNode;
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 20 │  •──┼─────→│ 10 │ NULL │
     └────┴─────┘      └────┴──────┘
```

#### Push(30) - Elemen Ketiga

**Kondisi Awal:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 20 │  •──┼─────→│ 10 │ NULL │
     └────┴─────┘      └────┴──────┘
```

**STEP 1: Node *newNode = new Node();**
```cpp
Node *newNode = new Node();
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 20 │  •──┼─────→│ 10 │ NULL │
     └────┴─────┘      └────┴──────┘

                       newNode
                          ↓
                       ┌────┬─────┐
                       │ ?? │ ??  │
                       └────┴─────┘
```

**STEP 2: newNode->data = data;**
```cpp
newNode->data = 30;
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 20 │  •──┼─────→│ 10 │ NULL │
     └────┴─────┘      └────┴──────┘

                       newNode
                          ↓
                       ┌────┬─────┐
                       │ 30 │ ??  │
                       └────┴─────┘
```

**STEP 3: newNode->next = top;**
```cpp
newNode->next = top;
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 20 │  •──┼─────→│ 10 │ NULL │
     └────┴─────┘      └────┴──────┘
       ↑
       │
       │              newNode
       │                 ↓
       │              ┌────┬─────┐
       └──────────────┼─•  │ 30  │
                      └─────┴────┘
```

**STEP 4: top = newNode;**
```cpp
top = newNode;
```
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 30 │  •──┼─────→│ 20 │  •──┼─────→│ 10 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
```

---

## 4. pop() - Menghapus Elemen Teratas

### Kode
```cpp
void pop() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return;
    }
    
    Node *oldTop = top;
    top = top->next;
    delete oldTop;
}
```

### Visualisasi Lengkap: Pop() pada Stack dengan 3 Elemen

#### Kondisi Awal
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
```

#### STEP 1: if (isEmpty())

**Kode:**
```cpp
if (isEmpty()) {
    cout << "Stack kosong!\n";
    return;
}
```

**Visualisasi:**
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘

Pengecekan: top == NULL? → false
Stack tidak kosong, lanjut ke step berikutnya
```

**Penjelasan:**
Sebelum melakukan operasi pop, harus dicek terlebih dahulu apakah stack kosong. Jika `top == nullptr`, maka stack kosong dan fungsi akan berhenti dengan `return`. Keyword `return` pada void function berfungsi untuk menghentikan eksekusi fungsi, bukan mengembalikan nilai. Tanpa `return`, program akan melanjutkan ke baris kode berikutnya yang bisa menyebabkan error karena mencoba mengakses node yang tidak ada.

#### STEP 2: Node *oldTop = top;

**Kode:**
```cpp
Node *oldTop = top;
```

**Visualisasi:**
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
               ↑
            oldTop
```

**Penjelasan:**
Menyimpan alamat node yang akan dihapus ke pointer sementara `oldTop`. Pointer `oldTop` dan `top` sekarang menunjuk ke node yang sama, yaitu node berisi 50. Langkah ini penting karena setelah `top` dipindahkan, kita masih membutuhkan referensi ke node yang akan dihapus untuk operasi `delete`.

#### STEP 3: top = top->next;

**Kode:**
```cpp
top = top->next;
```

**Visualisasi Sebelum:**
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
               ↑
            oldTop
```

**Visualisasi Sesudah:**
```
                               top
                                ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
               ↑
            oldTop
```

**Penjelasan:**
Memindahkan pointer `top` ke node berikutnya. `top` yang tadinya menunjuk ke node berisi 50, sekarang menunjuk ke node berisi 30. Node berisi 50 masih ada di memori, hanya saja `top` tidak lagi menunjuk ke sana. Pointer `oldTop` masih menyimpan alamat node berisi 50 yang akan dihapus.

#### STEP 4: delete oldTop;

**Kode:**
```cpp
delete oldTop;
```

**Visualisasi Sebelum Delete:**
```
                               top
                                ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
               ↑
            oldTop
```

**Visualisasi Sesudah Delete:**
```
                               top
                                ↓
            ╔════╗             ┌────┬─────┐      ┌────┬──────┐
            ║ XX ║             │ 30 │  •──┼─────→│ 20 │ NULL │
            ╚════╝             └────┴─────┘      └────┴──────┘
         (DIHAPUS!)
```

**Visualisasi Hasil Akhir:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘
```

**Penjelasan:**
Operasi `delete oldTop` benar-benar menghapus node dari memori dan mengembalikan memori tersebut ke sistem operasi. Setelah di-delete, node berisi 50 tidak lagi ada. Stack sekarang hanya memiliki 2 elemen: 30 dan 20.

---

### Mengapa Perlu Pointer oldTop?

#### Cara Yang Salah
```cpp
// JANGAN SEPERTI INI!
delete top;        // Hapus node yang ditunjuk top
top = top->next;   // ERROR! top sudah dihapus, tidak bisa akses next
```

**Visualisasi Cara Salah:**
```
STEP 1: delete top
              top
               ↓
            ╔════╗             ┌────┬─────┐      ┌────┬──────┐
            ║ XX ║             │ 30 │  •──┼─────→│ 20 │ NULL │
            ╚════╝             └────┴─────┘      └────┴──────┘
         (DIHAPUS!)

STEP 2: top = top->next
ERROR! top menunjuk ke memori yang sudah dihapus
Tidak bisa mengakses top->next karena node sudah tidak ada
```

#### Cara Yang Benar
```cpp
// BENAR!
Node *oldTop = top;   // Simpan alamat dulu
top = top->next;      // Pindahkan top
delete oldTop;        // Baru hapus
```

**Visualisasi Cara Benar:**
```
STEP 1: Node *oldTop = top (Simpan alamat)
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
               ↑
            oldTop

STEP 2: top = top->next (Pindah dulu)
                               top
                                ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
               ↑
            oldTop

STEP 3: delete oldTop (Baru hapus)
                               top
                                ↓
            ╔════╗             ┌────┬─────┐      ┌────┬──────┐
            ║ XX ║             │ 30 │  •──┼─────→│ 20 │ NULL │
            ╚════╝             └────┴─────┘      └────┴──────┘
```

**Penjelasan:**
Pointer `oldTop` diperlukan untuk menyimpan alamat node yang akan dihapus sebelum `top` dipindahkan. Jika kita langsung `delete top` terlebih dahulu, maka kita tidak bisa mengakses `top->next` karena node tersebut sudah dihapus dari memori. Dengan menggunakan `oldTop`, kita bisa memindahkan `top` terlebih dahulu ke node berikutnya, baru kemudian menghapus node lama melalui pointer `oldTop`.

---

### Simulasi Lengkap: 3x Pop Berturut-turut

#### Stack Awal
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
```

#### Pop() Pertama - Hapus 50

**Proses:**
```cpp
Node *oldTop = top;   // oldTop → node [50]
top = top->next;      // top → node [30]
delete oldTop;        // hapus node [50]
```

**Hasil:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘
```

#### Pop() Kedua - Hapus 30

**Proses:**
```cpp
Node *oldTop = top;   // oldTop → node [30]
top = top->next;      // top → node [20]
delete oldTop;        // hapus node [30]
```

**Hasil:**
```
top
 ↓
┌────┬──────┐
│ 20 │ NULL │
└────┴──────┘
```

#### Pop() Ketiga - Hapus 20

**Proses:**
```cpp
Node *oldTop = top;   // oldTop → node [20]
top = top->next;      // top → NULL
delete oldTop;        // hapus node [20]
```

**Hasil:**
```
top = NULL
(Stack kosong)
```

---

## 5. peek() - Melihat Elemen Teratas

### Kode
```cpp
void peek() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Top = " << top->data << endl;
}
```

### Visualisasi: Stack dengan 3 Elemen

**Kondisi Stack:**
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Proses peek():**
```cpp
if (isEmpty())        // false, stack tidak kosong
cout << top->data;    // Output: 50
```

**Hasil:**
```
Output: "Top = 50"

Stack tetap:
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
(Tidak ada perubahan)
```

### Penjelasan
Fungsi `peek()` hanya melihat nilai elemen teratas tanpa menghapusnya. Fungsi ini mengakses `top->data` untuk mendapatkan nilai, tetapi tidak mengubah struktur stack sama sekali.

---

## 6. displayAll() - Tampilkan Semua Elemen

### Kode
```cpp
void displayAll() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return;
    }
    
    Node *temp = top;
    cout << "Isi Stack (atas → bawah):\n";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
```

### Visualisasi: Traversal Stack

**Kondisi Stack:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Iterasi 1:**
```cpp
Node *temp = top;  // temp menunjuk ke node [50]
```
```
       top
        ↓
       temp
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘

cout << temp->data << " ";  // Output: "50 "
temp = temp->next;          // temp pindah ke node [30]
```

**Iterasi 2:**
```cpp
// temp sekarang menunjuk ke node [30]
```
```
       top
        ↓
     ┌────┬─────┐       temp
     │ 50 │  •──┼─────→   ↓
     └────┴─────┘      ┌────┬─────┐      ┌────┬──────┐
                       │ 30 │  •──┼─────→│ 20 │ NULL │
                       └────┴─────┘      └────┴──────┘

cout << temp->data << " ";  // Output: "30 "
temp = temp->next;          // temp pindah ke node [20]
```

**Iterasi 3:**
```cpp
// temp sekarang menunjuk ke node [20]
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐       temp
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→   ↓
     └────┴─────┘      └────┴─────┘      ┌────┬──────┐
                                          │ 20 │ NULL │
                                          └────┴──────┘

cout << temp->data << " ";  // Output: "20 "
temp = temp->next;          // temp = NULL
```

**Iterasi 4:**
```cpp
// temp = NULL, keluar dari loop
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
                                                  ↓
                                                temp = NULL
                                                (Loop berhenti)

Output lengkap: "Isi Stack (atas → bawah):
50 30 20"
```

### Penjelasan
Fungsi `displayAll()` menggunakan pointer sementara `temp` untuk melakukan traversal dari `top` sampai `nullptr`. Pointer `temp` bergerak dari node ke node mengikuti pointer `next`, mencetak nilai `data` di setiap node. Stack sendiri tidak berubah karena hanya operasi pembacaan.

---

## 7. size() - Hitung Jumlah Elemen

### Kode
```cpp
int size() {
    int count = 0;
    Node *temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
```

### Visualisasi: Menghitung Elemen

**Kondisi Stack:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Iterasi 1:**
```cpp
int count = 0;
Node *temp = top;  // temp → node [50]
```
```
       top
        ↓
       temp
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘

count++;              // count = 1
temp = temp->next;    // temp pindah ke [30]
```

**Iterasi 2:**
```
       top
        ↓
     ┌────┬─────┐       temp
     │ 50 │  •──┼─────→   ↓
     └────┴─────┘      ┌────┬─────┐      ┌────┬──────┐
                       │ 30 │  •──┼─────→│ 20 │ NULL │
                       └────┴─────┘      └────┴──────┘

count++;              // count = 2
temp = temp->next;    // temp pindah ke [20]
```

**Iterasi 3:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐       temp
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→   ↓
     └────┴─────┘      └────┴─────┘      ┌────┬──────┐
                                          │ 20 │ NULL │
                                          └────┴──────┘

count++;              // count = 3
temp = temp->next;    // temp = NULL
```

**Iterasi 4:**
```
temp = NULL → Loop berhenti

return count;  // return 3
```

### Penjelasan
Fungsi `size()` bekerja dengan cara traversal (jalan-jalan) dari `top` sampai `nullptr`, sambil menghitung berapa kali loop berjalan. Setiap kali menemukan node, variabel `count` ditambah 1. Ketika `temp` mencapai `nullptr`, loop berhenti dan function mengembalikan nilai `count`.

---

## 8. clear() - Hapus Semua Elemen

### Kode
```cpp
void clear() {
    while (!isEmpty()) {
        pop();
    }
}
```

### Visualisasi: Clear Stack dengan 3 Elemen

**Kondisi Awal:**
```
              top
               ↓
            ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
            │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
            └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Iterasi 1: pop() - Hapus 50**
```cpp
while (!isEmpty())  // true (stack ada isi)
    pop();          // hapus elemen teratas
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬──────┐
     │ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴──────┘
```

**Iterasi 2: pop() - Hapus 30**
```cpp
while (!isEmpty())  // true (masih ada isi)
    pop();          // hapus elemen teratas
```
```
top
 ↓
┌────┬──────┐
│ 20 │ NULL │
└────┴──────┘
```

**Iterasi 3: pop() - Hapus 20**
```cpp
while (!isEmpty())  // true (masih ada 1 elemen)
    pop();          // hapus elemen terakhir
```
```
top = NULL
(Stack kosong)
```

**Iterasi 4: Cek kondisi**
```cpp
while (!isEmpty())  // false (stack kosong)
    // Loop berhenti
```

**Hasil Akhir:**
```
top = NULL
Stack berhasil dikosongkan!
```

### Penjelasan
Fungsi `clear()` menggunakan loop untuk memanggil `pop()` secara berulang sampai stack kosong. Setiap iterasi, elemen teratas dihapus sampai `isEmpty()` return `true`. Ini adalah cara yang aman dan efisien untuk mengosongkan stack karena memanfaatkan fungsi `pop()` yang sudah memiliki mekanisme penghapusan yang benar.

---

## 9. search(int value) - Cari Elemen

### Kode
```cpp
int search(int value) {
    Node *temp = top;
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

### Visualisasi: Mencari Nilai 30

**Kondisi Stack:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Iterasi 1: Cek node [50]**
```cpp
Node *temp = top;
int indeks = 1;
```
```
       top
        ↓
       temp [indeks=1]
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘

if (temp->data == 30)  // 50 == 30? false
temp = temp->next;     // pindah ke [30]
indeks++;              // indeks = 2
```

**Iterasi 2: Cek node [30]**
```
       top
        ↓
     ┌────┬─────┐      temp [indeks=2]
     │ 50 │  •──┼─────→   ↓
     └────┴─────┘      ┌────┬─────┐      ┌────┬──────┐
                       │ 30 │  •──┼─────→│ 20 │ NULL │
                       └────┴─────┘      └────┴──────┘

if (temp->data == 30)  // 30 == 30? TRUE!
return indeks;         // return 2 (DITEMUKAN!)
```

**Hasil:**
```
search(30) → return 2
Nilai 30 ditemukan di posisi ke-2 dari atas
```

### Contoh: Mencari Nilai Yang Tidak Ada

**Mencari nilai 99:**
```cpp
search(99);
```

**Iterasi 1: Cek [50]**
```
temp → [50]
if (50 == 99) → false
indeks = 2, temp → [30]
```

**Iterasi 2: Cek [30]**
```
temp → [30]
if (30 == 99) → false
indeks = 3, temp → [20]
```

**Iterasi 3: Cek [20]**
```
temp → [20]
if (20 == 99) → false
indeks = 4, temp → NULL
```

**Iterasi 4:**
```
temp = NULL → Loop berhenti
return 0;  // TIDAK DITEMUKAN
```

**Hasil:**
```
search(99) → return 0
Nilai 99 tidak ditemukan dalam stack
```

### Penjelasan
Fungsi `search()` melakukan linear search dari atas ke bawah. Setiap node dicek apakah `data`-nya sama dengan nilai yang dicari. Jika ditemukan, langsung return posisinya (dimulai dari 1). Jika sampai akhir stack tidak ditemukan, return 0 sebagai tanda "tidak ada".

---

## 10. replaceTop(int val) - Ganti Nilai Teratas

### Kode
```cpp
void replaceTop(int val) {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return;
    }
    top->data = val;
}
```

### Visualisasi: Replace Top dengan Nilai 99

**Kondisi Awal:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Proses: replaceTop(99)**
```cpp
if (isEmpty())      // false, stack ada isi
top->data = 99;     // ubah data di node teratas
```

**Kondisi Sesudah:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 99 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
       ↑
    BERUBAH!
```

### Perbandingan: replaceTop() vs pop() + push()

#### Cara 1: Menggunakan replaceTop() ✅
```cpp
replaceTop(99);  // Langsung ganti nilai
```
```
SEBELUM:  50 → 30 → 20
SESUDAH:  99 → 30 → 20

✅ Cepat (1 operasi)
✅ Efisien (tidak alokasi memori baru)
✅ Struktur stack tetap sama
```

#### Cara 2: Menggunakan pop() + push() ❌
```cpp
pop();      // Hapus 50
push(99);   // Tambah 99 baru
```
```
SEBELUM:  50 → 30 → 20
pop():    30 → 20 (hapus node [50])
push():   99 → 30 → 20 (buat node baru [99])

❌ Lambat (2 operasi)
❌ Tidak efisien (delete + alokasi memori baru)
❌ Lebih kompleks
```

### Penjelasan
Fungsi `replaceTop()` mengubah nilai elemen teratas tanpa mengubah struktur stack. Ini lebih efisien daripada menghapus dan menambah node baru karena hanya mengubah field `data` tanpa operasi memori yang mahal.

---

## 11. bottom() - Lihat Elemen Terbawah

### Kode
```cpp
int bottom() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return -1;
    }
    
    Node *temp = top;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}
```

### Visualisasi: Mencari Elemen Bottom

**Kondisi Stack:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │ ← BOTTOM
     └────┴─────┘      └────┴─────┘      └────┴──────┘
```

**Iterasi 1:**
```cpp
Node *temp = top;  // temp → [50]
```
```
       top
        ↓
       temp
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘

while (temp->next != nullptr)  // true ([50]->next ada)
    temp = temp->next;         // pindah ke [30]
```

**Iterasi 2:**
```
       top
        ↓
     ┌────┬─────┐       temp
     │ 50 │  •──┼─────→   ↓
     └────┴─────┘      ┌────┬─────┐      ┌────┬──────┐
                       │ 30 │  •──┼─────→│ 20 │ NULL │
                       └────┴─────┘      └────┴──────┘

while (temp->next != nullptr)  // true ([30]->next ada)
    temp = temp->next;         // pindah ke [20]
```

**Iterasi 3:**
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐       temp
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→   ↓
     └────┴─────┘      └────┴─────┘      ┌────┬──────┐
                                          │ 20 │ NULL │
                                          └────┴──────┘

while (temp->next != nullptr)  // false ([20]->next = NULL)
    // Loop berhenti, temp sudah di node terakhir!

return temp->data;  // return 20
```

**Hasil:**
```
bottom() → return 20
Elemen terbawah adalah 20
```

### Perbedaan: peek() vs bottom()

#### peek() - Lihat Atas
```cpp
peek();  // Langsung akses top->data
```
```
       top ← LIHAT INI
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘

peek() → return 50
⏱️ Kompleksitas: O(1) - konstant time
```

#### bottom() - Lihat Bawah
```cpp
bottom();  // Harus traversal sampai akhir
```
```
       top
        ↓
     ┌────┬─────┐      ┌────┬─────┐      ┌────┬──────┐
     │ 50 │  •──┼─────→│ 30 │  •──┼─────→│ 20 │ NULL │
     └────┴─────┘      └────┴─────┘      └────┴──────┘
                                             ↑
                                        LIHAT INI

bottom() → return 20
⏱️ Kompleksitas: O(n) - linear time
```

### Penjelasan
Fungsi `bottom()` harus melakukan traversal dari `top` sampai node terakhir untuk menemukan elemen terbawah. Loop berjalan sampai `temp->next == nullptr`, yang menandakan `temp` sudah berada di node terakhir. Ini berbeda dengan `peek()` yang bisa langsung akses `top->data`.

---

## 📊 Tabel Ringkasan Kompleksitas Waktu

| Operasi | Kompleksitas | Penjelasan |
|---------|-------------|------------|
| `createStack()` | O(1) | Hanya set pointer ke NULL |
| `isEmpty()` | O(1) | Hanya cek 1 kondisi |
| `push()` | O(1) | Insert di head, tidak perlu traversal |
| `pop()` | O(1) | Delete dari head, tidak perlu traversal |
| `peek()` | O(1) | Akses langsung ke top |
| `size()` | O(n) | Harus hitung semua node |
| `displayAll()` | O(n) | Harus print semua node |
| `clear()` | O(n) | Harus pop() semua node |
| `search()` | O(n) | Worst case: cek semua node |
| `replaceTop()` | O(1) | Hanya ubah 1 field |
| `bottom()` | O(n) | Harus traversal sampai akhir |

**Keterangan:**
- **O(1)** = Constant time, sangat cepat, tidak terpengaruh ukuran stack
- **O(n)** = Linear time, waktu bertambah sebanding dengan jumlah elemen

---

## 🎯 Keuntungan Stack dengan Linked List

### ✅ Kelebihan

1. **Ukuran Dinamis**
   ```
   Tidak ada batasan ukuran seperti array
   Stack bisa tumbuh sesuai kebutuhan (selama ada memori)
   ```

2. **Efisiensi Push/Pop**
   ```
   Operasi push dan pop O(1) - sangat cepat
   Tidak perlu shift elemen seperti di array
   ```

3. **Tidak Ada Memory Waste**
   ```
   Hanya alokasi memori sesuai kebutuhan
   Tidak ada space kosong yang terbuang
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
   Harus traversal dari top
   ```

3. **Cache Locality Buruk**
   ```
   Node tersebar di memori, tidak bersebelahan
   Array lebih baik untuk cache performance
   ```

---

## 💡 Kapan Menggunakan Stack?

### Use Cases Stack

1. **Function Call Stack**
   ```cpp
   void funcA() {
       funcB();  // Push funcA ke stack
   }             // Pop funcA dari stack
   
   void funcB() {
       funcC();  // Push funcB ke stack
   }             // Pop funcB dari stack
   ```

2. **Undo/Redo Functionality**
   ```
   User Action Stack:
   [Edit Text]
   [Insert Image]  ← top (Undo akan batalkan ini)
   [Delete Paragraph]
   
   Undo → Pop dari stack
   ```

3. **Expression Evaluation**
   ```
   Infix: 3 + 4 * 2
   Postfix: 3 4 2 * +
   
   Menggunakan stack untuk evaluasi
   ```

4. **Backtracking Algorithms**
   ```
   Maze solving, DFS, Browser history
   ```

5. **Parentheses Matching**
   ```cpp
   "(())" → valid
   "(()" → invalid
   
   Gunakan stack untuk cek balancing
   ```

---

## 🧪 Contoh Program Lengkap

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = nullptr;

// ===== FUNGSI-FUNGSI STACK =====

void createStack() {
    top = nullptr;
}

bool isEmpty() {
    return top == nullptr;
}

void push(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    cout << "✅ Push " << data << " berhasil!\n";
}

void pop() {
    if (isEmpty()) {
        cout << "❌ Stack kosong!\n";
        return;
    }
    Node *oldTop = top;
    int removedData = top->data;
    top = top->next;
    delete oldTop;
    cout << "✅ Pop " << removedData << " berhasil!\n";
}

void peek() {
    if (isEmpty()) {
        cout << "❌ Stack kosong!\n";
        return;
    }
    cout << "🔝 Top = " << top->data << endl;
}

void displayAll() {
    if (isEmpty()) {
        cout << "❌ Stack kosong!\n";
        return;
    }
    
    Node *temp = top;
    cout << "\n📚 Isi Stack (atas → bawah):\n";
    cout << "┌─────┐\n";
    while (temp != nullptr) {
        cout << "│ " << temp->data << "   │";
        if (temp == top) cout << " ← top";
        cout << "\n";
        temp = temp->next;
    }
    cout << "└─────┘\n";
}

int size() {
    int count = 0;
    Node *temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clear() {
    while (!isEmpty()) {
        pop();
    }
    cout << "✅ Stack berhasil dikosongkan!\n";
}

int search(int value) {
    Node *temp = top;
    int indeks = 1;
    while (temp != nullptr) {
        if (temp->data == value)
            return indeks;
        temp = temp->next;
        indeks++;
    }
    return 0;
}

void replaceTop(int val) {
    if (isEmpty()) {
        cout << "❌ Stack kosong!\n";
        return;
    }
    int oldValue = top->data;
    top->data = val;
    cout << "✅ Top berhasil diganti: " << oldValue << " → " << val << "\n";
}

int bottom() {
    if (isEmpty()) {
        cout << "❌ Stack kosong!\n";
        return -1;
    }
    
    Node *temp = top;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}

// ===== MAIN PROGRAM =====

int main() {
    createStack();
    
    cout << "\n========== DEMO STACK ==========\n\n";
    
    // Push beberapa elemen
    cout << "--- PUSH OPERATION ---\n";
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    // Display stack
    displayAll();
    
    // Peek top
    cout << "\n--- PEEK OPERATION ---\n";
    peek();
    
    // Size
    cout << "\n--- SIZE OPERATION ---\n";
    cout << "📊 Ukuran stack: " << size() << " elemen\n";
    
    // Bottom
    cout << "\n--- BOTTOM OPERATION ---\n";
    cout << "🔻 Bottom = " << bottom() << "\n";
    
    // Search
    cout << "\n--- SEARCH OPERATION ---\n";
    int cari = 30;
    int hasil = search(cari);
    if (hasil != 0)
        cout << "🔍 Nilai " << cari << " ditemukan di posisi " << hasil << "\n";
    else
        cout << "❌ Nilai " << cari << " tidak ditemukan\n";
    
    // Replace top
    cout << "\n--- REPLACE TOP ---\n";
    replaceTop(99);
    displayAll();
    
    // Pop beberapa elemen
    cout << "\n--- POP OPERATION ---\n";
    pop();
    pop();
    displayAll();
    
    // Clear stack
    cout << "\n--- CLEAR OPERATION ---\n";
    clear();
    displayAll();
    
    cout << "\n========== DEMO SELESAI ==========\n";
    
    return 0;
}
```

### Output Program:

```
========== DEMO STACK ==========

--- PUSH OPERATION ---
✅ Push 10 berhasil!
✅ Push 20 berhasil!
✅ Push 30 berhasil!
✅ Push 40 berhasil!
✅ Push 50 berhasil!

📚 Isi Stack (atas → bawah):
┌─────┐
│ 50   │ ← top
│ 40   │
│ 30   │
│ 20   │
│ 10   │
└─────┘

--- PEEK OPERATION ---
🔝 Top = 50

--- SIZE OPERATION ---
📊 Ukuran stack: 5 elemen

--- BOTTOM OPERATION ---
🔻 Bottom = 10

--- SEARCH OPERATION ---
🔍 Nilai 30 ditemukan di posisi 3

--- REPLACE TOP ---
✅ Top berhasil diganti: 50 → 99

📚 Isi Stack (atas → bawah):
┌─────┐
│ 99   │ ← top
│ 40   │
│ 30   │
│ 20   │
│ 10   │
└─────┘

--- POP OPERATION ---
✅ Pop 99 berhasil!
✅ Pop 40 berhasil!

📚 Isi Stack (atas → bawah):
┌─────┐
│ 30   │ ← top
│ 20   │
│ 10   │
└─────┘

--- CLEAR OPERATION ---
✅ Pop 30 berhasil!
✅ Pop 20 berhasil!
✅ Pop 10 berhasil!
✅ Stack berhasil dikosongkan!
❌ Stack kosong!

========== DEMO SELESAI ==========
```

---

## 🎓 Kesimpulan

### Konsep Penting Stack

1. **LIFO (Last In, First Out)**
   - Elemen terakhir masuk = pertama keluar
   - Seperti tumpukan piring

2. **Pointer `top`**
   - Selalu menunjuk ke elemen paling atas
   - Semua operasi berkaitan dengan `top`

3. **Operasi Utama**
   - `push()` = tambah di atas (O(1))
   - `pop()` = hapus dari atas (O(1))
   - `peek()` = lihat yang paling atas (O(1))

4. **Memory Management**
   - Selalu `delete` node yang tidak terpakai
   - Gunakan pointer sementara (`oldTop`, `temp`)
   - Hindari memory leak!

### Tips Debugging Stack

1. **Selalu cek `isEmpty()` sebelum operasi**
   ```cpp
   // ❌ SALAH
   cout << top->data;  // Crash jika stack kosong!
   
   // ✅ BENAR
   if (!isEmpty()) {
       cout << top->data;
   }
   ```

2. **Visualisasi di kertas**
   ```
   Gambar box untuk setiap node
   Ikuti pointer next dengan panah
   Tandai posisi top
   ```

3. **Gunakan cout untuk debug**
   ```cpp
   cout << "DEBUG: top = " << top << endl;
   cout << "DEBUG: top->data = " << top->data << endl;
   ```

---

## 📚 Latihan Soal

### Soal 1: Reverse String
Implementasikan fungsi untuk membalik string menggunakan stack!
```cpp
Input: "HELLO"
Output: "OLLEH"
```

### Soal 2: Balanced Parentheses
Cek apakah tanda kurung seimbang menggunakan stack!
```cpp
Input: "((()))"
Output: VALID

Input: "(()"
Output: INVALID
```


---

**Made with ❤️** 