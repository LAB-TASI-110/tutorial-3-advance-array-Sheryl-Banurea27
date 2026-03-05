#include <stdio.h>

int main() {
    int n, i;
    int nilai;
    long long totalNilai = 0;
    double rataRata;

    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah mahasiswa harus bilangan bulat positif.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &nilai);
        if (nilai < 0 || nilai > 100) {
            printf("Nilai tidak valid. Masukkan nilai antara 0-100.\n");
            return 1;
        }
        totalNilai += nilai;
    }

    rataRata = (double)totalNilai / n;
    printf("\n");
    printf("%lld\n", totalNilai);
    printf("%.2lf\n", rataRata);

    return 0;
}
