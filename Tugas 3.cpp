#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int a, i, jmlh, jmlhbf, x, y, k, l;
void lihatdata();

typedef struct data_mahasiswa{
	char nama[35];
	char npm[15];
	char alamat[100];
	char jeniskelamin[16];
	int tgl_lahir;
	int semester;
	float ipk;
}dt_mhs;
dt_mhs data[100];

void inputdata() {
	printf(" Input nilai data Mahasiswa\n ================================\n");
	printf(" masukan jumlah data mahasiswa yang ingin di buat : ");scanf("%d", &jmlh);
	printf("\n Anda memasukkan nilai : %d", jmlh);
	Sleep(1500);
	system("cls");
	//input data
	int iplus=1;
	for(i=0; i<jmlh; i++) {
		printf("\n\t-----------------\n Masukkan data mahasiswa ke - %d\n===============================\n", iplus);
		printf(" Masukkan Nama Lengkap: ");scanf("%s", data[a].nama);
		printf(" Masukkan NPM : ");scanf("%s", data[a].npm);
		printf(" Masukkan Alamat Kabupaten : ");scanf("%s", data[a].alamat);
		printf(" Masukkan Jenis Kelamin: ");scanf("%s", data[a].jeniskelamin);
		printf(" Masukkan TTL(DDMMYYYY) : ");scanf("%d", &data[a].tgl_lahir);
		printf(" Masukkan Semester : ");scanf("%d", &data[a].semester);
		printf(" Masukkan IPK : ");scanf("%f", &data[a].ipk);
		iplus++;a++;
	}
	printf("\n Data berhasil tersimpan !");
    Sleep(900);
	system("cls");
	lihatdata();
}

void lihatdata() {
	//print data
	printf(" Data Mahasiswa\n =====================\n");
	int l, no_data=1;
	printf (" | %3s | %-7s | %s | %3s | %3s | %3s | %3s |\n\n", 
	"no" "Nama Mahasiswa", "NPM", "Alamat", "Jenis Kelamin", "Tanggal Lahir", "Semester");
	for(l=0; l<a; l++){
		printf("| %d | %s, %s, %s, %s, %d, %d, %2f \n", no_data, data[l].nama, data[l].npm, data[l].alamat, 
		data[l].jeniskelamin, data[l].tgl_lahir, data[l].semester, data[l].ipk);
		no_data++;
	}
	printf("\n\n\n tekan untuk kembali ke menu...");
	getch();system("cls");
}

void hapusdata() {
	printf(" Hapus Data Mahasiswa\n ===========================\n Hapus data nomer indeks ke = ");scanf("%d", &x);
	y=x-1;
	a--;
	for(int d=y; d<a; d++)
	{data[d]=data[d+1];}
	printf("\n data ke-%d berhasil dihapus! tekan untuk melanjutkan...", x);
	getch();system("cls");
}


void editdata(){
	printf(" Edit Data Mahasiswa\n ==========================\n Masukan nomer indeks data yang ingin di ubah = ");
	scanf("%d", &k);
	l=k-1;
	printf(" Masukkan Nama Lengkap: ");scanf("%s", data[l].nama);
	printf(" Masukkan NPM : ");scanf("%s", data[a].npm);
	printf(" Masukkan Alamat Kabupaten : ");scanf("%s", data[l].alamat);
	printf(" Masukkan Jenis Kelamin: ");scanf("%s", data[l].jeniskelamin);
	printf(" Masukkan TTL(DDMMYYYY) : ");scanf("%d", &data[l].tgl_lahir);
	printf(" Masukkan Semester : ");scanf("%d", &data[l].semester);
	printf(" Masukkan IPK : ");scanf("%f", &data[l].ipk);
	lihatdata();
}

int main () {
	int pilih; char c[4];
	printf("\n\n\n\t\t\tSelamat Datang di Program pendataan Mahasiswa!\n\n\t\t\t tekan tombol apapun untuk melanjutkan...");
	getch();system("cls");
	menu:
	printf("\n ================================ MENU PENDATAAN MAHASISWA =================================");
	printf("\n 1. Masukkan data");
	printf("\n 2. Hapus Data");
	printf("\n 3. Lihat Data");
	printf("\n 4. Edit Data");
	printf("\n 5. Keluar");
	printf("\n \n Masukkan Pilihan : ");
	scanf("%d", &pilih);
	if(pilih==1){
		system("cls");
		inputdata();
		goto menu;
	}  
	if(pilih==2){
		system("cls");
		hapusdata();
		goto menu;
	} 
	if(pilih==3){
		system("cls");
		lihatdata();
		goto menu;
	} 
	if(pilih==4){
		system("cls");
		editdata();
		goto menu;
	} 
	printf("\n Program Selesai...");
}

