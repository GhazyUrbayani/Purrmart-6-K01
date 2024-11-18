# Struktur Folder

- ├── ADT/
- │   ├── listdin/
- │   │   ├── listdin.h   # Header untuk ListDin
- │   │   ├── listdin.c   # Implementasi ListDin
- │   │   ├── tester_listdin.c    # Driver/testing ListDin
- │   ├── queue/
- │   │   ├── queue.h     # Header untuk Queue
- │   │   ├── queue.c     # Implementasi Queue
- │  │   ├── tester_queue.c    # Driver/testing Queue
- │   ├── stack/
- │   │   ├── stack.h     # Header untuk Stack
- │   │   ├── stack.c     # Implementasi Stack
- │   │   ├── tester_stack.c    # Driver/testing Stack

## Cara Menjalankan Tester

Kompilasi Tester: Pastikan Anda berada di folder src/ADT. Gunakan perintah berikut untuk setiap tester:

- `gcc -o tester_listdin listdin.c tester_listdin.c`
- `gcc -o tester_queue queue.c tester_queue.c`
- `gcc -o tester_stack stack.c tester_stack.c`

Jalankan Tester: Jalankan program hasil kompilasi:

- `./tester_listdin`
- `./tester_queue`
- `./tester_stack`
