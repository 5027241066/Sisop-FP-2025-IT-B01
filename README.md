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

Struktur repository:
```
.
├── fork.c
└── README.md
```

## Pengerjaan

> Buat program dengan menu untuk membuat fork dan menampilkan visualisasi fork yang dibuat (PID, PPID, dan hubungan garis).

### **Teori**

### 1. Konsep Fork dan Hirarki Proses (Silberschatz) ###
Dalam sistem operasi modern seperti Unix/Linux, fork() adalah sistem call untuk membuat proses baru. Proses baru akan menjadi salinan dari proses pemanggil, membentuk hubungan induk-anak (parent-child). Proses-proses ini secara alami membentuk sebuah process tree atau pohon proses, seperti ditunjukkan pada Figure 3.9 di buku Silberschatz.

![3.9 Figure](./assets/process_tree_from_silberchatz)

Setiap proses dapat membuat proses baru (child proses) yang membuat proses-proses ini berbentuk seperti tree
(Silberschatz, Operating System Concepts Essentials)

### 2. Deskripsi dan Struktur Proses (Stallings) ###
William Stallings menjelaskan bahwa setiap proses dalam sistem OS memiliki atribut penting seperti:

PID (Process ID)

PPID (Parent Process ID)

State (status proses: running, ready, blocked)

Child pointer list (untuk proses anak)

Proses ini dikelola melalui Process Control Block (PCB) yang menyimpan semua informasi penting proses.

### 3. Visualisasi Hirarki Proses (Tanenbaum) ###
Tanenbaum menjelaskan bahwa proses dapat digambarkan sebagai struktur tree karena adanya relasi orang tua-anak antar proses. Setiap node memiliki PID, PPID, dan dapat memiliki banyak anak. Konsep ini penting untuk memahami interaksi proses dan manajemen memori/eksekusi.

Setiap child proses dapat memiliki anak(child) lebih dari satu dan masing masing anaknya itu juga dapat memiliki anak lagi membentuk tree of processess yang dalam dan luas
(Tanenbaum, Modern Operating Systems)

#### **Solusi**
Struktur Data
```c
typedef struct ProcessNode {
    int pid;
    int ppid;
    int childCount;
    struct ProcessNode* children[10];
} ProcessNode;
```
Struct ProcessNode adalah representasi simpul pohon proses.
Setiap simpul menyimpan:

PID: ID unik proses

PPID: ID parent

ChildCount dan array pointer ke proses anak

Simulasi Fork
```c
ProcessNode* child = createProcessNode(currentPID++, parent->pid);
```
Saat pengguna memilih “Buat Fork” dari menu, proses anak baru dibuat dan ditambahkan ke parent->children.

Fungsi createProcessNode() menciptakan proses baru dengan PID unik.

Proses ini tidak benar-benar memanggil fork() OS, tapi hanya membuat objek baru di memori dan menghubungkannya dengan induknya.

Visualisasi Pohon
```c
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

### 4. Process Table & Process Control Block (PCB) ### 
Silberschatz menjelaskan bahwa setiap proses di dalam sistem operasi direpresentasikan oleh Process Control Block (PCB) yang berisi informasi penting tentang proses tersebut. Semua PCB proses aktif disimpan oleh sistem dalam sebuah struktur yang disebut process table, yang memungkinkan sistem melakukan manajemen proses seperti penjadwalan dan terminasi.

Solusi
Struktur PCB
``` c
typedef struct ProcessNode {
    int pid;
    int ppid;
    int childCount;
    struct ProcessNode* children[10];
} ProcessNode;
```
Struct ProcessNode berfungsi sebagai PCB simulasi, menyimpan ID proses (PID), ID parent (PPID), dan daftar anak-anaknya (relasi proses).

Process Table
```c
ProcessNode* processList[100];
int processCount = 0;

void addProcess(ProcessNode* node) {
    processList[processCount++] = node;
}
processList[] adalah representasi dari process table, tempat semua ProcessNode (PCB) disimpan dan dikelola.
```

Lookup Proses
```c
ProcessNode* findProcess(int pid) {
    for (int i = 0; i < processCount; i++) {
        if (processList[i]->pid == pid) {
            return processList[i];
        }
    }
    return NULL;
}
```
Sebelum membuat child, sistem akan mencari parent di process table menggunakan PID, menyerupai proses lookup PCB oleh OS.

### 5. Simulasi OS: Eksplorasi Parent-Child dan Wait (Jurnal Visualizing the Modern Operating System: Simulation Experiments Supporting Enhanced Learning. Business School, Edge Hill University, Ormskirk, UK.)

Dalam sebuah jurnal mengenai simulator OS untuk pembelajaran oleh Mustafa B., dijelaskan bagaimana sistem simulator dapat membentuk dan memvisualisasikan relasi proses parent-child. Simulator tersebut memungkinkan mahasiswa untuk:

Membuat proses baru dan mengamati hierarki proses melalui tampilan pohon proses.

Memverifikasi bahwa child process mewarisi global memory dari parent-nya.

Mengeksplorasi efek ketika parent process mati terhadap child-nya (anak menjadi orphan dan diadopsi oleh root/induk atas).

Mempelajari peran statement wait() yang membuat parent tertunda hingga semua child selesai.

Simulasi ini juga menunjukkan bagaimana wait dan fork diimplementasikan melalui software interrupt, memperlihatkan interaksi antara kode assembly, simulasi CPU, dan layanan OS.

### **Video Menjalankan Program** ###

[Klik di sini untuk melihat video](https://github.com/user-attachments/assets/7d4e003c-45fa-4be0-93f1-ee7f623662e9)
## Daftar Pustaka ###

Sitasi 1

https://dl.acm.org/doi/book/10.5555/2601626  
Silberschatz, A., Galvin, P. B., & Gagne, G. (2011). Operating System Concepts Essentials (8th ed.). John Wiley & Sons. [Lihat p. 108–111 (108=130 di pdf)]

Sitasi 2

Stallings, W. (2018). Operating Systems: Internals and Design Principles (9th ed.). Pearson Education.

Sitasi 3

Tanenbaum, A. S., & Bos, H. (2015). Modern Operating Systems (4th ed.). Pearson. 

Sitasi 4

https://dl.acm.org/doi/book/10.5555/2601626  
Silberschatz, Galvin, & Gagne, Operating System Concepts Essentials, 8th ed., John Wiley & Sons, 2011, p. 112

Sitasi 5

[https://research.edgehill.ac.uk/ws/portalfiles/portal/20096957/Paper_Final_Version_ACM_ITE_New_York_2011.pdf](https://doi.org/10.1145/2047594.2047650)  
Mustafa, B. (n.d.). Visualizing the Modern Operating System: Simulation Experiments Supporting Enhanced Learning. Business School, Edge Hill University, Ormskirk, UK. Retrieved from 
