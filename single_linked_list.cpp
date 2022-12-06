#include <iostream>

using namespace std;

// deklarasi single linked list
struct Buku
{

    // komponen / member
    string judul, pengarang;
    int tahunTerbit;

    Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *before;

// create single linked list
void createSingleLinkedList(string judul, string pengarang, int tB)
{
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

// print single linked list
int countSingleLinkedList()
{
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

// tambahAwal Single linked list
void addFirst(string judul, string pengarang, int tB)
{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

// tambahAkhir Single linked list
void addLast(string judul, string pengarang, int tB)
{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tB;

        // tranversing
        cur = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

// Remove First
void removeFirst()
{
    del = head;
    head = head->next;
    delete del;
}

// Remove Last
void removeLast()
{
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// remove middle
void removeMiddle(int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        cur = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                before = cur;
            }
            if (nomor == posisi)
            {
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}

// ubahAwal Single linked list
void changeFirst(string judul, string pengarang, int tB)
{
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

// ubahAkhir Single linked list
void changeLast(string judul, string pengarang, int tB)
{
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

// ubah Tengah Single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1 || posisi == countSingleLinkedList())
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        cur = head;
        int nomor = 1;
        while (nomor < posisi)
        {
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tB;
    }
}

// print single linked list
void printSingleLinkedList()
{
    cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
    cur = head;
    while (cur != NULL)
    {
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

        cur = cur->next;
    }
}

int main()
{

    createSingleLinkedList("Clean Code", "Robert Cecil Martin", 2008);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addFirst("The Pragmatic Programmer", "Andy Hunt, Dave Thomas", 1999);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addLast("Introduction to Algorithms", "Ronald L. Rivest", 1989);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    removeFirst();

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addLast("Design Patterns Elements of Reusable Object-Oriented Software", "Erich Gamma, John Vlissides, Ralph Johnson, Richard Helm", 1994);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    removeLast();

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    changeFirst("Refactoring", "Kent Beck", 1999);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addMiddle("The C Programming Language", "Dennis Ritchie, Brian Kernighan", 1978, 2);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    addMiddle("Algorithms", "Kevin Wayne, Robert Sedgewick", 2010, 2);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    removeMiddle(5);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;

    changeMiddle("Hacking: The Art of Exploitation", "Jon Erickson", 2008, 2);

    printSingleLinkedList();

    cout << "\n\n"
         << endl;
}