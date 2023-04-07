#include <iostream>
#include <string>
using namespace std;

struct Motor {
    string merk;
    string plat;
    int tahun;
    Motor* next;
};

Motor* head = NULL;
Motor* tail = NULL;

void addMotor(string merk, string plat, int tahun) {
    Motor* motor = new Motor;
    motor->merk = merk;
    motor->plat = plat;
    motor->tahun = tahun;
    motor->next = NULL;

    if (head == NULL) {
        head = motor;
        tail = motor;
    } else {
        tail->next = motor;
        tail = motor;
    }

    cout << "Motor berhasil ditambahkan ke antrian." << endl;
}

void removeMotor() {
    if (head == NULL) {
        cout << "Antrian kosong." << endl;
    } else {
        Motor* temp = head;
        head = head->next;
        delete temp;

        cout << "Motor berhasil dikeluarkan dari antrian." << endl;
    }
}

void displayAntrian() {
    if (head == NULL) {
        cout << "Antrian kosong." << endl;
    } else {
        cout << "Antrian saat ini:" << endl;
        Motor* current = head;

        while (current != NULL) {
            cout << current->merk << " - " << current->plat << " - " << current->tahun << endl;
            current = current->next;
        }
    }
}

int main() {
    int choice;
    string merk, plat;
    int tahun;

    do {
        cout << "Silakan pilih opsi:" << endl;
        cout << "1. Tambah motor ke antrian" << endl;
        cout << "2. Keluarkan motor dari antrian" << endl;
        cout << "3. Tampilkan antrian saat ini" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan merk motor: ";
                cin >> merk;
                cout << "Masukkan plat motor: ";
                cin >> plat;
                cout << "Masukkan tahun motor: ";
                cin >> tahun;
                addMotor(merk, plat, tahun);
                break;

            case 2:
                removeMotor();
                break;

            case 3:
                displayAntrian();
                break;

            case 4:
                cout << "Terima kasih." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
