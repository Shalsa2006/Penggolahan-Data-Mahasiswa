# Program Pengelolaan Data Mahasiswa

Program ini memungkinkan pengelolaan data mahasiswa dengan menggunakan struktur data `map<long, string>` yang menyimpan informasi mahasiswa berdasarkan NIM. Program ini menyediakan beberapa fitur seperti menambah, melihat, memperbarui, dan menghapus data mahasiswa.

## Penjelasan Struktur Data

### 1. **`map<long, string>`:**
- **Deskripsi**: Struktur data `map` di C++ adalah wadah (container) yang menyimpan pasangan nilai (key-value) yang terurut. Dalam hal ini, tipe key-nya adalah `long` (untuk menyimpan NIM mahasiswa) dan tipe value-nya adalah `string` (untuk menyimpan nama mahasiswa).
- **Kelebihan**: Elemen-elemen dalam `map` diurutkan berdasarkan key secara otomatis. Ini memungkinkan pencarian, penyisipan, dan penghapusan elemen yang efisien dengan waktu rata-rata O(log n) karena penggunaan struktur pohon biner terurut (balanced binary tree) di bawahnya.

### 2. **Peran dalam Program:**
- **`students`**: Variabel `students` adalah sebuah objek dari `map<long, string>` yang berfungsi untuk menyimpan data mahasiswa. Key yang digunakan adalah NIM mahasiswa (tipe data `long`), dan value yang terkait dengan key tersebut adalah nama mahasiswa (tipe data `string`).
  
- **Fungsi `createStudent`**: Fungsi ini menambahkan data mahasiswa baru ke dalam `students` dengan NIM sebagai key dan nama sebagai value. Sebelum penambahan, fungsi memeriksa apakah NIM sudah ada dalam `students`. Jika NIM sudah ada, data tidak akan ditambahkan untuk menghindari duplikasi.

- **Fungsi `readStudents`**: Fungsi ini menampilkan seluruh data mahasiswa yang ada dalam `students`. Data ditampilkan dalam urutan berdasarkan NIM (karena `map` secara otomatis mengurutkan key). Setiap entri menampilkan NIM, nama, tahun angkatan (dihitung dari NIM), dan tiga digit terakhir NIM.

- **Fungsi `updateStudent`**: Fungsi ini memungkinkan pembaruan data mahasiswa berdasarkan NIM yang dimasukkan. NIM dicari di dalam `students`, dan jika ditemukan, nama mahasiswa yang terkait dengan NIM tersebut diperbarui. Jika NIM tidak ditemukan, fungsi akan memberi tahu pengguna bahwa mahasiswa dengan NIM tersebut tidak ada.

- **Fungsi `deleteStudent`**: Fungsi ini menghapus data mahasiswa berdasarkan NIM yang dimasukkan. Jika NIM ditemukan dalam `students`, maka data mahasiswa dengan NIM tersebut akan dihapus. Jika tidak ditemukan, pengguna akan diberi tahu bahwa data tersebut tidak ada.

### 3. **Keuntungan Penggunaan `map` dalam Program Ini:**
- **Pengurutan Otomatis**: Data mahasiswa akan selalu disusun berdasarkan NIM, memudahkan pencarian dan penampilan data dalam urutan yang diinginkan.
- **Pencarian Cepat**: Karena menggunakan pohon biner terurut, operasi pencarian data (misalnya, saat meng-update atau menghapus data berdasarkan NIM) dilakukan dalam waktu logaritmik, yang efisien bahkan jika jumlah data mahasiswa cukup besar.
- **Tidak Ada Duplikasi Key**: Dengan menggunakan `map`, setiap NIM hanya dapat muncul satu kali sebagai key. Ini membantu mencegah duplikasi NIM dalam data mahasiswa.

Secara keseluruhan, penggunaan `map<long, string>` memungkinkan pengelolaan data mahasiswa dengan cara yang terstruktur dan efisien, dengan jaminan bahwa data akan disimpan dalam urutan yang benar dan dapat diakses dengan cepat.

## Fitur Program

1. **Tambah Data Mahasiswa**
2. **Lihat Data Mahasiswa**
3. **Perbarui Data Mahasiswa**
4. **Hapus Data Mahasiswa**
5. **Keluar Program**

## Cara Penggunaan

1. **Menambah Data Mahasiswa**
    - Pilih opsi **1. Tambah Data Mahasiswa**.
    - Masukkan **NIM** mahasiswa yang terdiri dari 11 digit angka. Jika NIM tidak valid (misalnya kurang dari atau lebih dari 11 digit), sistem akan memberikan pesan kesalahan.
    - Masukkan **Nama** mahasiswa. Nama harus terdiri dari huruf dan tidak boleh kosong atau memiliki spasi di awal atau akhir.
    - Jika data valid, program akan menambahkan data mahasiswa dan memberikan konfirmasi bahwa data berhasil ditambahkan.
    - Jika NIM sudah ada, program akan memberitahukan bahwa mahasiswa dengan NIM tersebut sudah terdaftar.

2. **Lihat Data Mahasiswa**
    - Pilih opsi **2. Lihat Data Mahasiswa**.
    - Program akan menampilkan daftar semua mahasiswa yang telah terdaftar, diurutkan berdasarkan **NIM**. Setiap entri data mahasiswa akan menampilkan:
        - **NIM** (dengan format 11 digit).
        - **Nama mahasiswa**.
        - **Angkatan** (dihitung berdasarkan 2 digit pertama dari NIM).
        - **Tiga digit terakhir NIM**.
    - Jika tidak ada data mahasiswa yang tersimpan, program akan menampilkan pesan bahwa data mahasiswa tidak ada.

3. **Perbarui Data Mahasiswa**
    - Pilih opsi **3. Perbarui Data Mahasiswa**.
    - Masukkan **NIM** mahasiswa yang datanya akan diperbarui.
    - Jika NIM tidak ditemukan dalam database, sistem akan memberitahukan bahwa mahasiswa dengan NIM tersebut tidak ada.
    - Masukkan **Nama baru** untuk mahasiswa tersebut.
    - Jika nama valid, data akan diperbarui, dan program akan memberi tahu bahwa data berhasil diperbarui.

4. **Hapus Data Mahasiswa**
    - Pilih opsi **4. Hapus Data Mahasiswa**.
    - Masukkan **NIM** mahasiswa yang datanya akan dihapus.
    - Jika NIM tidak ditemukan dalam database, program akan memberitahukan bahwa mahasiswa dengan NIM tersebut tidak ada.
    - Jika NIM ditemukan, data mahasiswa tersebut akan dihapus, dan program akan memberi konfirmasi bahwa data berhasil dihapus.

5. **Keluar dari Program**
    - Pilih opsi **5. Keluar** untuk menutup aplikasi.
    - Program akan keluar setelah memberikan pesan konfirmasi.

## Contoh Alur Penggunaan

1. **Menambah Data**:
    - Pilih **1. Tambah Data Mahasiswa**.
    - Masukkan **NIM** `12345678901`.
    - Masukkan **Nama** `Budi Santoso`.
    - Sistem akan menambahkan data mahasiswa dengan NIM `12345678901` dan nama `Budi Santoso`.

2. **Lihat Data**:
    - Pilih **2. Lihat Data Mahasiswa**.
    - Program akan menampilkan:
    ```
    NIM: 12345678901 | Nama: Budi Santoso | Angkatan: 2012 | Tiga Digit Terakhir: 901
    ```

3. **Perbarui Data**:
    - Pilih **3. Perbarui Data Mahasiswa**.
    - Masukkan **NIM** `12345678901`.
    - Masukkan **Nama baru** `Budi Setiawan`.
    - Program akan memperbarui nama mahasiswa dengan NIM `12345678901` menjadi `Budi Setiawan`.

4. **Hapus Data**:
    - Pilih **4. Hapus Data Mahasiswa**.
    - Masukkan **NIM** `12345678901`.
    - Program akan menghapus data mahasiswa dengan NIM `12345678901`.

5. **Keluar**:
    - Pilih **5. Keluar** untuk keluar dari program.
