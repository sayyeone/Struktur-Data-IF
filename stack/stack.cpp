#include "stack.h" // => STACK MERUPAKAN TIPE DATA DENGAN PRINSIP LAST IN, FIRST OUT

Node *top = nullptr;

void createStack() // PRINSIPNYA HAMPIR SAMA KYK CREATE LIST YG DI SLL, KITA INISIALISAI BIASANYA FIRST = NULL
{
    top = nullptr;
}

bool isEmpty() // PENGECEKAN APAKAH STACKNYA ITU ADA ISINYA/KOSONG? KALAU IYA, DITANDAI DENGAN YG NAMANYA TOP == NULL, KITA MELAKUKAN YG NAMANYA PENGECEKAN TERLEBIH DAHULU 
{
    return top == nullptr; //DICEK APAKAH TOPNYA = NULL? KALAU IYA BERARTI KITA RETURNKAN DIA SEBAGAI NULL
}

void push(int data) // SAMA AJA KYK KITA MEMBUAT NEW ELEMEN DI NODE YG BARU, NAH DISINI KITA IMPLEMENTASIKAN DIA SEBAGAI SLL KOK BISA TAU? SOALNYA INI KITA LIAT, DISINI KAN ADA YG NAMANYA DATA SAMA NEXTNYA OTOMATIS DIA MERUPAKAN SLL
{
    Node *newNode = new Node(); // ALOKASI MEMORI BARU DI STACKNYA, KITA MEMBUTUHKAN NODE BARU DENGAN BANTUAN POINTER YG NAMANYA NEWNODE INI TADI YG BERISI TIPE DATANYA ADALAH NODE YG BERUPA STRUCT ISINYA ADA INFO SAMA NEXTNYA
    newNode->data = data; // KITA UDAH BERHASIL MEMBUAT NODE BARUNYA TAPI ISINYA MASIH KOSONG, NAH KARENA KITA UDAH MENDEFINISIKAN KALAU MISALNYA DI NEW NODE ITU KAN BERARTI ISINYA ADA DATA SAMA NEXTNYA, NAH BIAR ADA ISINYA DAN GA SALAH KITA ITU MENGISI NILAI DARI DATA ITU DENGAN DATA YG BARUSAN KITA INPUTKAN DIDALAM PARAMETERNYA YAITU INT DATA TERSEBUT
    newNode->next = top; // KITA UDAH BERHASIL MEMBUAT YG NAMANYA NEW NODENYA TAPI YG BAGIAN NEXTNYA INI BELUM MENUNJUK KE MANA" NAH KITA PASANGKAN NEXTNYA ITU MENUNJUK KE BAGIAN TOPNYA
    top = newNode; // KEMUDIAN KITA UPDATE POSISI YG NODE BARU KITA MASUKKAN ITU AGAR NAMA POINTER YG MENUNJUKNYA ITU SI TOP
}

void pop() // INI BERARTI KITA INGIN MENGHAPUSKAN NODE YG PALING AWAL KITA MASUKKAN KARENA LAST IN FIRST OUT YA
{
    if (isEmpty()) // KITA MENGECEK DULU APAKAH STACKNYA INI MASIH KOSONG / TIDAK DENGAN MEMANGGIL FUNGSI ISEMPTY => JIKA DIA KOSONG MAKA APA YG DILAKUKAN/ KITA MERETURNKAN DIA MENJADI STACK KOSONG
    {
        cout << "Stack kosong!\n";
        return; // KITA HARUS MEMAKAI RETURN KARENA KITA INGIN PROSEDUR POP INI DIA BERHENTI DAN TIDAK MELANJUTKAN KE BARIS KODE SELANJUTNYA, NAH JIKA KITA TANPA RETURN PROGRAM ITU AKAN MENJALANKAN BARIS KODE YG BERIKUTNYA
    }

    Node *oldTop = top; // KITA MEMBUAT POINTER BARU YG NAMANYA OLDTOP, NAH APA YG DILAKUKAN OLEH OLD TOP INI? YG DILAKUKAN OLD TOP INI KITA JELAS MENDEFINISIKAN SI OLD TOP INI DENGAN TIPE NODE KEMUDIAN KITA MENGISI NILAINYA / ASSIGN DENGAN TOP KARENA APA? KITA HANYA BISA MELAKUKAN YG NAMANYA OPERASI POP ITU DI BAGIAN YG ATAS, MAKA KITA MEMBUTUHKAN YG NAMANYA TOP
    top = top->next;
    delete oldTop;
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Top = " << top->data << endl;
}

void displayAll()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }

    Node *temp = top;
    cout << "Isi Stack (atas → bawah):\n";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int size()
{
    int count = 0;
    Node *temp = top;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clear()
{
    while (!isEmpty())
    {
        pop();
    }
}

int search(int value)
{
    Node *temp = top;
    int indeks = 1;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return indeks;
        temp = temp->next;
        indeks++;
    }
    return false;
}

void replaceTop(int val)
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    top->data = val;
}

int bottom()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return -1;
    }

    Node *temp = top;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp->data;
}
