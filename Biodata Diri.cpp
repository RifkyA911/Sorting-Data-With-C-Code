#include <stdio.h>
#include <conio.h>

char biodata(char nama[], long long npm, char prodi[], char alamat[]) {
	printf("\tNama\t: %s\n", nama);
	printf("\tNPM\t: %lld\n", npm);
	printf("\tProdi\t: %s\n", prodi);
	printf("\tAlamat\t: %s\n", alamat);
}

int main () {
	char nama[] = "Rifky Akhmad Fernanda";
	long long npm = 18081010126;
	char prodi[] = "Teknik Informatika, FIK, UPN Veteran Jawa Timur";
	char alamat[] = "Bojonegoro, Jawa Timur";
	printf("\n\tBiodata Diri\n\t============\n");
	biodata(nama, npm, prodi, alamat);
	return 0;
}
