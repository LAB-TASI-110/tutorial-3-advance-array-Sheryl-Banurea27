#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk malloc dan free
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN

int main() {
    int n, i;
    long long totalNilai = 0;
    double rataRata;
    int countAboveOrEqualAvg = 0;
    int minNilai = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int maxNilai = INT_MIN; // Inisialisasi dengan nilai minimum integer
    int rangeNilai;
    int *nilaiMahasiswa; // Pointer untuk array dinamis

    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah mahasiswa harus bilangan bulat positif.\n");
        return 1;
    }

    // Alokasi memori dinamis untuk menyimpan nilai mahasiswa
    nilaiMahasiswa = (int *)malloc(n * sizeof(int));
    if (nilaiMahasiswa == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &nilaiMahasiswa[i]);
        if (nilaiMahasiswa[i] < 0 || nilaiMahasiswa[i] > 100) {
            printf("Nilai tidak valid. Masukkan nilai antara 0-100.\n");
            free(nilaiMahasiswa); // Bebaskan memori sebelum keluar
            return 1;
        }
        totalNilai += nilaiMahasiswa[i];

        // Update nilai minimum dan maksimum
        if (nilaiMahasiswa[i] < minNilai) {
            minNilai = nilaiMahasiswa[i];
        }
        if (nilaiMahasiswa[i] > maxNilai) {
            maxNilai = nilaiMahasiswa[i];
        }
    }

    rataRata = (double)totalNilai / n;

    // Hitung berapa banyak mahasiswa yang nilainya >= rata-rata
    for (i = 0; i < n; i++) {
        if (nilaiMahasiswa[i] >= rataRata) {
            countAboveOrEqualAvg++;
        }
    }
    
    // Hitung rentang nilai
    rangeNilai = maxNilai - minNilai;
    printf("\n");
    printf("%lld\n", totalNilai);
    printf("%.2lf\n", rataRata);
    printf("%d\n", countAboveOrEqualAvg);
    printf("%d\n", rangeNilai);

    free(nilaiMahasiswa); // Bebaskan memori yang dialokasikan
    return 0;
}
