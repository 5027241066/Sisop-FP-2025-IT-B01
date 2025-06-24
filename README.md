# Sisop-FP-2025-IT-B01
# Final Project Sistem Operasi IT

## Peraturan
1. Waktu pengerjaan dimulai hari Kamis (19 Juni 2025) setelah soal dibagikan hingga hari Rabu (25 Juni 2025) pukul 23.59 WIB.
2. Praktikan diharapkan membuat laporan penjelasan dan penyelesaian soal dalam bentuk Readme(github).
3. Format nama repository github “Sisop-FP-2025-IT-[Kelas][Kelompok]” (contoh:Sisop-FP-2025-IT-A01).
4. Setelah pengerjaan selesai, seluruh source code dan semua script bash, awk, dan file yang berisi cron job ditaruh di github masing - masing kelompok, dan link github dikumpulkan pada form yang disediakan. Pastikan github di setting ke publik.
5. Commit terakhir maksimal 10 menit setelah waktu pengerjaan berakhir. Jika melewati maka akan dinilai berdasarkan commit terakhir.
6. Jika tidak ada pengumuman perubahan soal oleh asisten, maka soal dianggap dapat diselesaikan.
7. Jika ditemukan soal yang tidak dapat diselesaikan, harap menuliskannya pada Readme beserta permasalahan yang ditemukan.
8. Praktikan tidak diperbolehkan menanyakan jawaban dari soal yang diberikan kepada asisten maupun praktikan dari kelompok lainnya.
9. Jika ditemukan indikasi kecurangan dalam bentuk apapun di pengerjaan soal final project, maka nilai dianggap 0.
10. Pengerjaan soal final project sesuai dengan modul yang telah diajarkan.

## Kelompok 1

Nama | NRP
--- | ---
Balqis Sani Sabillah | 5027241002
Dira Muhammad Ilyas Shafar Anwar | 5027241033
Ahmad Yafi Ar Rizq | 5027241066
Nadia Fauziazahra Kusumastuti | 5027241094

## Deskripsi Soal

Memvisualisasikan proses fork dalam sistem. Program menyediakan menu untuk membuat proses baru menggunakan fork, lalu menampilkan struktur pohon proses yang terbentuk, lengkap dengan PID, PPID, dan hubungan antarproses secara visual agar mudah dipahami.

### Catatan

> Insert catatan dari pengerjaan kalian... (contoh dibawah) // hapus line ini

Struktur repository:
```
.
..
```

## Pengerjaan

> Buat program dengan menu untuk membuat fork dan menampilkan visualisasi fork yang dibuat (PID, PPID, dan hubungan garis).

**Teori**

Dalam sistem operasi, proses adalah program yang sedang berjalan, memiliki PID (Process ID) dan PPID (Parent Process ID). Proses dapat membuat child process menggunakan system call fork(). Namun, fork() membuat proses baru dengan memori terpisah sehingga data child tidak otomatis tersimpan di parent.

Untuk membangun dan menampilkan pohon proses, semua data PID dan hubungan parent-child harus tersimpan dalam satu memori yang sama. Oleh karena itu, simulasi fork lebih tepat digunakan agar pohon proses dapat ditampilkan secara utuh dan konsisten dalam satu program.

**Solusi**

- Menu interaktif: membuat fork, menampilkan pohon proses, dan keluar.
- Setiap proses disimpan sebagai node dengan PID dan PPID.
- Fork disimulasikan dengan memberi PID baru dan mencatat relasinya.
- Visualisasi ditampilkan dengan traversal rekursif dan indentasi pohon.

> Insert poin soal...

**Teori**

...

**Solusi**

...

**Video Menjalankan Program**
...

## Daftar Pustaka

Sitasi 1
Sitasi 2
Sitasi 3
