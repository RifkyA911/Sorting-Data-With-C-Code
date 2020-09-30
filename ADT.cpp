#include <stdio.h>
#include <conio.h>
 
typedef struct {
	char npm[40];
	int sampleA;
	int sampleB;
	int sampleC;
	char nama[50];
	float totalMean;
}NilaiMhs;
 
NilaiMhs InputNilaiMhs (NilaiMhs N) {
	printf("Tugas 2 Pemlan A \n\n");
	printf(" INPUT NILAI PENGUJIAN SAMPEL DATA X OLEH MAHASISWA\n");
	printf("---------------------------------------------------\n");
	printf(" Nama\t\t\t:\t");scanf("%[^\n]", &N.nama);
	printf(" NPM\t\t\t:\t");scanf("%s", &N.npm);
	printf(" Nilai Sample A\t\t:\t");scanf("%d", &N.sampleA);
	printf(" Nilai Sample B\t\t:\t");scanf("%d", &N.sampleB);
	printf(" Nilai Sample C\t\t:\t");scanf("%d", &N.sampleC);
	printf(" Selesai input...\n\n\n");
	return N;
}
 
void TampilDataNilaiMhs (NilaiMhs N) {
	printf(" LAPORAN NILAI PENGUJIAN SAMPLE DATA X OLEH MAHASISWA\n");
	printf("-----------------------------------------------------\n");
	printf(" Nama\t\t\t:\t%s\n", N.nama);
	printf(" NPM\t\t\t:\t%s\n", N.npm);
	printf(" Nilai Sample A\t\t:\t%d\n", N.sampleA);
	printf(" Nilai Sample B\t\t:\t%d\n", N.sampleB);
	printf(" Nilai Sample C\t\t:\t%d\n", N.sampleC);
	printf("\n\n");
}

float HitungMean (NilaiMhs N) {
	return(float (N.sampleA + N.sampleB + N.sampleC)/3);
}
 
int main(void)
{
	NilaiMhs N;
	N=InputNilaiMhs(N);
	TampilDataNilaiMhs(N);
	N.totalMean = HitungMean(N);
	printf(" Nilai rata-rata sampel : %.4f", N.totalMean);
	return 0;
}
