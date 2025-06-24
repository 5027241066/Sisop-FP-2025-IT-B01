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
├── fork.c
└── README.md
```

## Pengerjaan

> Buat program dengan menu untuk membuat fork dan menampilkan visualisasi fork yang dibuat (PID, PPID, dan hubungan garis).

### **Teori**

##### 1. Konsep Fork dan Hirarki Proses (Silberschatz)
Dalam sistem operasi modern seperti Unix/Linux, fork() adalah sistem call untuk membuat proses baru. Proses baru akan menjadi salinan dari proses pemanggil, membentuk hubungan induk-anak (parent-child). Proses-proses ini secara alami membentuk sebuah process tree atau pohon proses, seperti ditunjukkan pada Figure 3.9 di buku Silberschatz.

“Each of these new processes may in turn create other processes, forming a tree of processes.”
— Silberschatz, Operating System Concepts Essentials, p. 111

##### 2. Deskripsi dan Struktur Proses (Stallings)
William Stallings menjelaskan bahwa setiap proses dalam sistem OS memiliki atribut penting seperti:

PID (Process ID)

PPID (Parent Process ID)

State (status proses: running, ready, blocked)

Child pointer list (untuk proses anak)

Proses ini dikelola melalui Process Control Block (PCB) yang menyimpan semua informasi penting proses.

##### 3. Visualisasi Hirarki Proses (Tanenbaum)
Tanenbaum menjelaskan bahwa proses dapat digambarkan sebagai struktur tree karena adanya relasi orang tua-anak antar proses. Setiap node memiliki PID, PPID, dan dapat memiliki banyak anak. Konsep ini penting untuk memahami interaksi proses dan manajemen memori/eksekusi.

“Since children may also have children, an original process can build up an entire tree of children, grandchildren, and further descendants.”
— Tanenbaum, Modern Operating Systems, p. 737

#### **Solusi**
Struktur Data
typedef struct ProcessNode {
    int pid;
    int ppid;
    int childCount;
    struct ProcessNode* children[10];
} ProcessNode;
Struct ProcessNode adalah representasi simpul pohon proses.
Setiap simpul menyimpan:

PID: ID unik proses

PPID: ID parent

ChildCount dan array pointer ke proses anak

Simulasi Fork
```
ProcessNode* child = createProcessNode(currentPID++, parent->pid);
```
Saat pengguna memilih “Buat Fork” dari menu, proses anak baru dibuat dan ditambahkan ke parent->children.

Fungsi createProcessNode() menciptakan proses baru dengan PID unik.

Proses ini tidak benar-benar memanggil fork() OS, tapi hanya membuat objek baru di memori dan menghubungkannya dengan induknya.

Visualisasi Pohon
```
void displayProcessTree(ProcessNode* node, int depth) {
    for (int i = 0; i < depth; i++) printf("    ");
    printf("PID: %d (PPID: %d)\n", node->pid, node->ppid);

    for (int i = 0; i < node->childCount; i++) {
        displayProcessTree(node->children[i], depth + 1);
    }
}
```
Rekursi digunakan untuk menampilkan pohon proses secara depth-first.
Indentasi (depth) memberikan efek visual seperti cabang pohon.
Hasilnya mirip pstree atau htop pada Linux.

Menu Interaktif
Pengguna diberi 3 opsi:

Menambahkan proses (fork)

Menampilkan pohon proses

Keluar dari program

Proses root dibuat pertama kali sebagai proses utama dengan PPID = 0.


> Insert poin soal...

**Teori**

...

**Solusi**

...

**Video Menjalankan Program**
...

## Daftar Pustaka

Sitasi 1
Silberschatz, A., Galvin, P. B., & Gagne, G. (2018). Operating System Concepts. Wiley.

Sitasi 2
Sitasi 3
