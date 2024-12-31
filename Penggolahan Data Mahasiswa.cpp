#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <iomanip>
#include <limits>  

using namespace std;

void createStudent(map<long, string> &students);
void readStudents(const map<long, string> &students);
void updateStudent(map<long, string> &students);
void deleteStudent(map<long, string> &students);

bool isValidNIM(long nim); 
bool isValidName(string &name);

int main() {
    map<long, string> students;
    int choice;

    do {
        cout << "\n====== Menu ======" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Lihat Data Mahasiswa" << endl;
        cout << "3. Perbarui Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";

        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Pilihan tidak valid! Masukkan angka antara 1 hingga 5: ";
        }
        
        cin.ignore(); 

        switch (choice) {
            case 1:
                createStudent(students);
                break;
            case 2:
                readStudents(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                deleteStudent(students);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 5);

    return 0;
}

bool isValidNIM(long nim) {
    return nim >= 10000000000 && nim <= 99999999999; 
}

bool isValidName(string &name) {
    name = regex_replace(name, regex("^ +| +$"), "");
    return regex_match(name, regex("^[A-Za-z]+(?: [A-Za-z]+)*$")) && !name.empty(); 
}

void createStudent(map<long, string> &students) {
    long nim; 
    string name;
    cout << "\nMasukkan NIM: ";
    cin >> nim;
    cin.ignore(); 

    if (!isValidNIM(nim)) {
        cout << "NIM harus berupa 11 digit angka." << endl;
        return;
    }

    if (students.find(nim) != students.end()) {
        cout << "Mahasiswa dengan NIM " << nim << " sudah ada." << endl;
        return;
    }

    cout << "Masukkan Nama: ";
    getline(cin, name);

    if (!isValidName(name)) {
        cout << "Nama harus terdiri dari huruf, tidak boleh kosong, dan tidak boleh ada spasi di awal atau akhir." << endl;
        return;
    }

    students[nim] = name;
    cout << "Data mahasiswa berhasil ditambahkan." << endl;
}

void readStudents(const map<long, string> &students) { 
    if (students.empty()) {
        cout << "\nTidak ada data mahasiswa." << endl;
        return;
    }

    cout << "\nData Mahasiswa: " << endl;
    for (const auto &student : students) {
        int batchYear = 2000 + (student.first / 100000000) % 100; 
        int lastThreeDigits = student.first % 1000; 
        cout << "NIM: " << setw(11) << setfill('0') << student.first << " | Nama: " << student.second << " | Angkatan: " << batchYear << " | Tiga Digit Terakhir: " << setw(3) << setfill('0') << lastThreeDigits << endl;
    }
}

void updateStudent(map<long, string> &students) { 
    long nim; 
    string name;
    cout << "\nMasukkan NIM mahasiswa yang akan diperbarui: ";
    cin >> nim;
    cin.ignore(); 

    if (!isValidNIM(nim)) {
        cout << "NIM harus berupa 11 digit angka." << endl;
        return;
    }

    auto it = students.find(nim);
    if (it == students.end()) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }

    cout << "Masukkan Nama baru: ";
    getline(cin, name);

    if (!isValidName(name)) {
        cout << "Nama harus terdiri dari huruf, tidak boleh kosong, dan tidak boleh ada spasi di awal atau akhir." << endl;
        return;
    }

    students[nim] = name;
    cout << "Data mahasiswa berhasil diperbarui." << endl;
}

void deleteStudent(map<long, string> &students) { 
    long nim;
    cout << "\nMasukkan NIM mahasiswa yang akan dihapus: ";
    cin >> nim;
    cin.ignore(); 

    if (!isValidNIM(nim)) {
        cout << "NIM harus berupa 11 digit angka." << endl;
        return;
    }

    auto it = students.find(nim);
    if (it == students.end()) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }

    students.erase(it);
    cout << "Data mahasiswa berhasil dihapus." << endl;
}
