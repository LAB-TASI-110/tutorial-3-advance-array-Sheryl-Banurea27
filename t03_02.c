#include <stdio.h>
#include <stdlib.h> 
int main() {
    int n, i;
    long long totalNilai = 0;
    double rataRata;
    int countAboveOrEqualAvg = 0;
    int *nilaiMahasiswa; 
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah mahasiswa harus bilangan bulat positif.\n");
        return 1;
    }

    
    nilaiMahasiswa = (int *)malloc(n * sizeof(int));
    if (nilaiMahasiswa == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &nilaiMahasiswa[i]);
        if (nilaiMahasiswa[i] < 0 || nilaiMahasiswa[i] > 100) {
            printf("Nilai tidak valid. Masukkan nilai antara 0-100.\n");
            free(nilaiMahasiswa); 
            return 1;
        }
        totalNilai += nilaiMahasiswa[i];
    }

    rataRata = (double)totalNilai / n;

    
    for (i = 0; i < n; i++) {
        if (nilaiMahasiswa[i] >= rataRata) {
            countAboveOrEqualAvg++;
        }
    }
    printf("\n");
    printf("%lld\n", totalNilai);
    printf("%.2lf\n", rataRata);
    printf("%d\n", countAboveOrEqualAvg);

    free(nilaiMahasiswa); 
    return 0;
}
