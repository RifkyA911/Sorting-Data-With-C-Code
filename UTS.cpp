#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 100
int a, i, jmlh, jmlhbf, x, y, k, l, bublsort, srcsort;
void lihatdata();
void AscndBubblesort(int n, int mode);
void DescndBubblesort(int n, int mode);

typedef struct data_barang{
	char nama_barang[35];
	char kategori[15];
	int sku;
	int tgl_pengiriman;
	int harga_satuan;
	int jumlah_stock;
}dt_brg;
dt_brg data[100];

void inputdata() {
	printf(" Input data Barang\n ================================\n");
	printf(" masukan jumlah data barang yang ingin di buat : ");scanf("%d", &jmlh);
	printf("\n data barang akan dibuat dengan jumlah antrian : %d", jmlh);
	Sleep(1500);
	system("cls");
	//input data
	int iplus=1;
	for(i=0; i<jmlh; i++) {
		printf("\n\t-----------------\n Masukkan data barang ke - %d\n===============================\n", iplus);
		printf(" Masukkan Nama barang: ");scanf("%s", data[a].nama_barang);
		printf(" Masukkan Kategori : ");scanf("%s", data[a].kategori);
		printf(" Masukkan SKU : ");scanf("%d", &data[a].sku);
		printf(" Masukkan Tanggal Pengiriman (DDMMYYYY) : ");scanf("%d", &data[a].tgl_pengiriman);
		printf(" Masukkan Harga Satuan : ");scanf("%d", &data[a].harga_satuan);
		printf(" Masukkan Jumlah stock : ");scanf("%d", &data[a].jumlah_stock);
		iplus++;a++;
	}
	printf("\n Data Barang berhasil tersimpan !");
    Sleep(900);
	system("cls");
	lihatdata();
}

void lihatdata() {
	//print data
	printf(" Data Mahasiswa\n =====================\n");
	int l, no_data=1;
	printf (" | %3s | %-7s | %s | %3s | %3s | %3s | %3s |\n\n", 
	"no" "Nama Barang", "Kategori", "SKU", "Tanggal Pengiriman (DDMMYYYY)", "Harga Satuan", "Jumlah Stock");
	for(l=0; l<a; l++){
		printf("| %d | %s, %s, %d, %d, %d, %d \n", no_data, data[l].nama_barang, data[l].kategori, data[l].sku, 
		data[l].tgl_pengiriman, data[l].harga_satuan, data[l].jumlah_stock);
		no_data++;
	}
	printf("\n\n\n tekan untuk kembali ke menu...");
	getch();system("cls");
}

void hapusdata() {
	printf(" Hapus Data Barang\n ===========================\n Hapus data nomer indeks ke = ");scanf("%d", &x);
	y=x-1;
	a--;
	for(int d=y; d<a; d++)
	{data[d]=data[d+1];}
	printf("\n data ke-%d berhasil dihapus! tekan untuk melanjutkan...", x);
	getch();system("cls");
}


void editdata(){
	printf(" Edit Data Barang\n ==========================\n Masukan nomer indeks data yang ingin di ubah = ");
	scanf("%d", &k);
	l=k-1;
		printf(" Masukkan Nama barang: ");scanf("%s", data[l].nama_barang);
		printf(" Masukkan Kategori : ");scanf("%s", data[l].kategori);
		printf(" Masukkan SKU : ");scanf("%d", &data[l].sku);
		printf(" Masukkan Tanggal Pengiriman (DDMMYYYY) : ");scanf("%d", &data[l].tgl_pengiriman);
		printf(" Masukkan Harga Satuan : ");scanf("%d", &data[l].harga_satuan);
		printf(" Masukkan Jumlah stock : ");scanf("%d", &data[l].jumlah_stock);
	lihatdata();
}

int main () {
	int pilih; char c[4];
	printf("\n\n\n\n\t\t\tSelamat Datang di Program inventarisasi stok BAROKAH MINIMARKET PAK ADI!\n\n\t\t\t tekan tombol apapun untuk melanjutkan...");
	getch();system("cls");
	menu:
	printf("\n ================================ MENU BAROKAH MINIMARKET PAK ADI =================================");
	printf("\n 1. Masukkan Data Barang");
	printf("\n 2. Hapus Data Barang");
	printf("\n 3. Lihat Data Barang");
	printf("\n 4. Edit Data Barang");
	printf("\n 5. Urutkan Data Barang (BubbleSort)");
	printf("\n 7. Keluar");
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
	if(pilih==5){
		system("cls");
		printf(" Pilih Mode Sorting Data Barang dengan Metode Bubblesort :\n 1.Ascending\n 2.-\n -------\n Pilih : ");
		scanf("%d", &bublsort);
		if(bublsort==1){
			AscndBubblesort(jmlh, bublsort);
		}
		system("cls");
		goto menu;
	}
	printf("\n Program Selesai...");
}

void AscndBubblesort(int n, int mode) {
	int pb, sb, pilbub, cint, tmp;
	char temp[MAX];
	printf(" Anda memilih-%d\n\n", mode);
	Sleep(1000);
	printf(" Masukkan kategori Data Barang yang ingin disorting : \n 1.SKU Barang\n 2.Harga Barang\n 3.Jumlah Stock Barang\n");
	printf("\n Masukkan pilihan : ");
	scanf("%d", &pilbub);
	switch(pilbub) {
		case 1:
			for(sb=0; sb<n; sb++){
				for(pb=0; pb<n-sb-1; pb++){
					if(data[pb].sku > data[pb+1].sku){
						tmp = data[pb].sku;
						data[pb].sku = data[pb+1].sku;
						data[pb+1].sku=tmp;
					}
				}
			}
			printf("\n < Hasil pengurutan >\n");
			if(data[l].nama_barang)
			for(l=0; l<a; l++){
			printf("| %d |\n", data[l].sku);		
			}
			break;
		case 2: 
			for(sb=0; sb<n; sb++){
				for(pb=0; pb<n-sb-1; pb++){
					if(data[pb].harga_satuan > data[pb+1].harga_satuan){
						tmp = data[pb].harga_satuan;
						data[pb].harga_satuan = data[pb+1].harga_satuan;
						data[pb+1].harga_satuan=tmp;
					}
				}
			}
			printf("\n < Hasil pengurutan >\n");
			for(l=0; l<a; l++){
			printf("  | %d |\n", data[l].harga_satuan);		
			}
			break;
		case 3: 
			for(sb=0; sb<n; sb++){
				for(pb=0; pb<n-sb-1; pb++){
					if(data[pb].jumlah_stock > data[pb+1].jumlah_stock){
						tmp = data[pb].jumlah_stock;
						data[pb].jumlah_stock = data[pb+1].jumlah_stock;
						data[pb+1].jumlah_stock=tmp;
					}
				}
			}
			printf("\n < Hasil pengurutan >\n");
			for(l=0; l<a; l++){
			printf("  | %d |\n", data[l].jumlah_stock);		
			}
			break;
	}
	printf(" Pengurutan BubbleSort Selesai ! tekan untuk melanjutkan...");
	getch();system("cls");
}


