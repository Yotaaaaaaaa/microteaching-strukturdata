# microteaching-strukturdata
Berisi program final project struktur data yang pernah saya buat dengan mencakup semua materi yang ada.
Program Pemutar Musik

Program ini dibuat dengan bahasa C++, menggunakan struktur data Queue, Array, Sorting, Searching, dan Pointer.  
Setiap menu memiliki implementasi materi tertentu, berikut penjelasannya:

Menu atau Fitur Program

1. Play Music (play)  
   - Materi: Queue (FIFO)  
   - Mengambil lagu paling depan sebagai lagu yang diputar.  
   - Menggeser seluruh elemen ke kiri dan menurunkan indeks akhir.  

2. Tampilkan Playlist (tampilLagu)  
   - Materi: Array  
   - Menelusuri dari awal sampai akhir, mencetak `idLagu | judul | penyanyi`.  
   - Jika kosong, otomatis akan diberi perintah untuk mengisi playlist terlebih dahulu.  

3. Tambahkan Playlist (inQueue)  
   - Materi: Queue  
   - Menambahkan lagu baru ke antrean playlist.  

4. Urutkan berdasarkan ID (sortingById)  
   - Materi: Bubble Sort (Ascending)  
   - Mengurutkan berdasarkan ID Lagu.  
   - ID dipakai sebagai prioritas lagu ketika menambahkan playlist.  

5. Urutkan berdasarkan Judul (sortingByJudul)  
   - Materi: Bubble Sort  

6. Urutkan berdasarkan Penyanyi (sortingByPenyanyi)  
   - Materi: Bubble Sort  

7. Cari Lagu Berdasarkan ID (searchById)  
   - Materi: Binary Search  
   - Dilakukan pada array yang sudah diurutkan berdasarkan ID.  

8. Cari Lagu Berdasarkan Judul (searchByJudul)  
   - Materi: Binary Search  
   - Dilakukan pada array yang sudah diurutkan berdasarkan Judul.  

9. Cari Lagu Berdasarkan Penyanyi (searchByPenyanyi)  
   - Materi: Binary Search  
   - Dilakukan pada array yang sudah diurutkan berdasarkan Penyanyi.
     
0. Clear (clear)  
   - Mengosongkan playlist dengan menyetel `awal = akhir = -1`.  
