#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan node proses
typedef struct ProcessNode {
    int pid; // PID simulasi
    int ppid; // PPID simulasi
    int childCount;
    struct ProcessNode* children[10]; // Maksimal 10 child per proses
} ProcessNode;

ProcessNode* processList[100];
int processCount = 0;
int currentPID = 1; 

// Membuat node proses baru
ProcessNode* createProcessNode(int pid, int ppid) {
    ProcessNode* node = (ProcessNode*)malloc(sizeof(ProcessNode));
    node->pid = pid;
    node->ppid = ppid;
    node->childCount = 0;
    return node;
}

// Menambahkan node proses ke list
void addProcess(ProcessNode* node) {
    processList[processCount++] = node;
}

// Mencari proses berdasarkan PID
ProcessNode* findProcess(int pid) {
    for (int i = 0; i < processCount; i++) {
        if (processList[i]->pid == pid) {
            return processList[i];
        }
    }
    return NULL;
}

// Menampilkan tree secara rekursif
void displayProcessTree(ProcessNode* node, int depth) {
    for (int i = 0; i < depth; i++) printf("    ");
    printf("PID: %d (PPID: %d)\n", node->pid, node->ppid);

    for (int i = 0; i < node->childCount; i++) {
        displayProcessTree(node->children[i], depth + 1);
    }
}

int main() {
    int choice, parentPID;

    // Buat root process (simulasi proses utama)
    ProcessNode* root = createProcessNode(currentPID++, 0);
    addProcess(root);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Buat Fork\n");
        printf("2. Tampilkan Pohon Proses\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        if (scanf("%d", &choice) != 1) {
            printf("Input salah!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
            continue;
        }

        if (choice == 1) {
            printf("Masukkan PID parent (contoh: 1): ");
            if (scanf("%d", &parentPID) != 1) {
                printf("Input salah!\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
                continue;
            }

            ProcessNode* parent = findProcess(parentPID);
            if (parent == NULL) {
                printf("Parent dengan PID %d tidak ditemukan!\n", parentPID);
                continue;
            }

            ProcessNode* child = createProcessNode(currentPID++, parent->pid);
            addProcess(child);

            parent->children[parent->childCount++] = child;

            printf("Fork berhasil: PID %d | PPID %d\n", child->pid, child->ppid);

        } else if (choice == 2) {
            printf("\nVisualisasi Pohon Proses:\n");
            displayProcessTree(root, 0);

        } else if (choice == 3) {
            printf("Program selesai.\n");
            break;

        } else {
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
