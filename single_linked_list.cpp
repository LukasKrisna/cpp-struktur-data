#include <iostream>

using namespace std;

struct Buku
{
    string judul, pengarang;
    int tahunTerbit;

    Buku *next;
};

int main()
{
    // Inisialisasi Single Linked List
    Buku *node1, *node2, *node3;

    node1 = new Buku();
    node2 = new Buku();
    node3 = new Buku();

    // Pengisian node1
    node1->judul = "Javascript";
    node1->pengarang = "Brendan Eich";
    node1->tahunTerbit = 1995;
    node1->next = node2;

    // Pengisian node2
    node2->judul = "Golang";
    node2->pengarang = "Robert Griesemer";
    node2->tahunTerbit = 2009;
    node2->next = node3;

    // Pengisian node3
    node3->judul = "Rust";
    node3->pengarang = "Graydon Hoare";
    node3->tahunTerbit = 2010;
    node3->next = NULL;

    // Print Single Linked List
    Buku *cur;
    cur = node1;

    while (cur != NULL)
    {
        cout << "\nJudul Buku: " << cur->judul << endl;
        cout << "Pengarang Buku: " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku: " << cur->tahunTerbit << endl;

        cur = cur->next;
    }

    return 0;
}
