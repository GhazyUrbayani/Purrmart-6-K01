# PURRMART-CLI

**PURRMART** adalah aplikasi simulasi berbasis **Command Line Interface (CLI)** yang dikembangkan sebagai tugas besar mata kuliah Algoritma dan Struktur Data (IF2111). Aplikasi ini menyimulasikan aktivitas jual beli pada e-commerce dengan menggunakan berbagai fitur interaktif.

---

## Fitur Utama
1. **Menampilkan Barang Toko**: Lihat daftar barang yang tersedia di toko.
2. **Permintaan dan Penyuplaian Barang**: Ajukan barang baru ke toko dan suplaikan barang berdasarkan antrian.
3. **Bekerja untuk Menghasilkan Uang**: Pilih pekerjaan atau tantangan untuk mendapatkan uang virtual.
4. **Mekanisme Login dan Register**: Buat akun atau masuk dengan kredensial pengguna.
5. **Menyimpan dan Memuat Progress**: Simpan state aplikasi dan muat kembali dari file konfigurasi.
6. **Sistem Keranjang Barang**: Memasukkan, mengeluarkan, hingga menampilkan barang-barang pada keranjang.
7. **Melakukan Pembayaran Barang di Keranjang**: Membeli barang-barang yang berada di dalam keranjang, akan mengurangi jumlah uang.
8. **Sistem Wishlist**: Memungkinkan pengguna untuk menambah, mengurangi, dan menukar posisi barang hingga menampilkan barang-barang dalam wishlist.
9. **Riwayat Pembelian**: Menampilkan riwayat pembelian yang telah dilakukan sebelumnya
10. **Mekanisme Profile**: Melihat data diri pengguna untuk suatu akun tertentu

---

## Teknologi yang Digunakan
- **Bahasa Pemrograman**: C
- **Library yang Digunakan**: 
  - `stdio.h`
  - `stdlib.h`
  - `time.h`
  - `math.h`

---

## Struktur Folder
- ├── data/             # Folder berisi data untuk game Wordle
- ├── save/             # Folder untuk menyimpan save states
- ├── src/              # Source code utama
- │   ├── ADT/            # Folder berisi ADT yang digunakan
- │   ├── command/        # Folder berisi file-file commands
- │   ├── Wishlist/        # Folder berisi file-file commands yang khusus untuk Wishlist
- │   ├── store/          # Folder berisi implementasi STORE dan CART
- │   ├── structs/        # Folder berisi implementasi USER dan ITEM
- │   ├── work/           # Folder berisi implementasi WORK, WORDLE, dan GAME
- │   └── main.c          # Entry point aplikasi
- ├── tests/            # Folder berisi tests untuk beberapa fitur program
- ├── Makefile          # Makefile untuk membuat program dan tests
- └── README.md         # Dokumentasi project
- *Dokumen pendukung tugas besar yang lain dan lebih lengkap di Folder G-Drive

---

## Identitas Kelompok
- Nama Anggota 1: [Inggried Amelia Deswanty] (NIM: 18223035)
- Nama Anggota 2: [M. Andiananto Bismaramadhan] (NIM: 18221028)
- Nama Anggota 3: [Muhammad Faiz Alfikrona] (NIM: 18223009)
- Nama Anggota 4: [Noeriza Aqila Wibawa] (NIM: 18223095)
- Nama Anggota 5: [Ghazy Achmed Movlech Urbayani] (NIM: 18223093)

---

## Cara Kompilasi dan Menjalankan Program
1. **Clone Repository**
   ```bash
   git clone https://github.com/GhazyUrbayani/Purrmart-6-K01.git
   cd Purrmart-6-K01
   ```
2. **Compile**
    ```bash
    make main
    ```
3. Run
    ```bash
    ./main
    ```
## Catatan
Pastikan file konfigurasi awal berada di folder `save/`
