# PURRMART-CLI

**PURRMART** adalah aplikasi simulasi berbasis **Command Line Interface (CLI)** yang dikembangkan sebagai tugas besar mata kuliah Algoritma dan Struktur Data (IF2111). Aplikasi ini mensimulasikan aktivitas jual beli pada e-commerce dengan menggunakan berbagai fitur interaktif.

---

## Fitur Utama
1. **Menampilkan Barang Toko**: Lihat daftar barang yang tersedia di toko.
2. **Permintaan dan Penyuplaian Barang**: Ajukan barang baru ke toko dan suplaikan barang berdasarkan antrian.
3. **Wishlist dan Keranjang**: Simpan barang ke wishlist atau tambahkan ke keranjang untuk dibeli.
4. **Bekerja untuk Menghasilkan Uang**: Pilih pekerjaan atau tantangan untuk mendapatkan uang virtual.
5. **Mekanisme Login dan Register**: Buat akun atau masuk dengan kredensial pengguna.
6. **Menyimpan dan Memuat Progress**: Simpan state aplikasi dan muat kembali dari file konfigurasi.

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
.
- ├── bin/               # File binary hasil kompilasi
- ├── save/              # Folder untuk menyimpan File save state
- ├── src/               # Source code utama
- | ├── ADT/               # Folder berisi ADT yang digunakan
- | ├── console.c          # Implementasi commands
- | ├── console.h          # Header untuk commands
- | ├── main.c             # Entry point aplikasi
- └── README.md          # Dokumentasi project
*Dokumen pendukung tugas besar di Folder G-Drive

## Identitas Kelompok
- Nama Anggota 1: [	Inggried Amelia Deswanty] (NIM: 18223035)
- Nama Anggota 2: [	M. Andiananto Bismaramadhan] (NIM: 18221028)
- Nama Anggota 3: [	Muhammad Faiz Alfikrona] (NIM: 18223009)
- Nama Anggota 4: [	Noeriza Aqila Wibawa] (NIM: 18223095)
- Nama Anggota 5: [Ghazy Achmed Movlech Urbayani] (NIM: 18223093)

---

## Cara Kompilasi dan Menjalankan Program
1. **Clone Repository**
   ```bash
   git clone https://github.com/username/PURRMART-CLI.git
   cd PURRMART-CLI

## Catatan
Pastikan file konfigurasi awal berada di folder `save/`
