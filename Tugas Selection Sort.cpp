#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 100
int a, i, jmlh, jmlhbf, x, y, k, l, bublsort, srcsort;
void lihatdata();
void AscndBubblesort(int n, int mode);
void DescndBubblesort(int n, int mode);
void AscendSelectionSort(int n, int mode);

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
	"no" "Nama Mahasiswa", "NPM", "Alamat", "Jenis Kelamin", "Tanggal Lahir", "Semester", "IPK");
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
	printf("\n 5. BubbleSort Data");
	printf("\n 6. Selection Sorting Data");
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
		printf(" Pilih Mode Sorting dengan Metode Bubblesort :\n 1.Ascending\n 2.-\n -------\n Pilih : ");
		scanf("%d", &bublsort);
		if(bublsort==1){
			AscndBubblesort(jmlh, bublsort);
		}
		system("cls");
		goto menu;
	}
	if(pilih==6){
		system("cls");
		printf(" Pilih Mode Sorting dengan Metode Selection Sorting :\n 1.Ascending\n 2.-\n -------\n Pilih : ");
		scanf("%d", &srcsort);
		if(srcsort==1){
			AscendSelectionSort(jmlh, srcsort);
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
	printf(" Masukkan kategori Data Mahasiswa yang ingin disorting : \n 1.Nama\n 2.NPM\n 3.Tanggal Lahir\n 4.Semester\n 5.IPK");
	printf("\n Masukkan pilihan : ");
	scanf("%d", &pilbub);
	switch(pilbub) {
		case 1:
			for (int j=0; j<n-1; j++) {	 
	        	for (int i=j+1; i<n; i++) {	 
	            if (strcmp(data[j].nama, data[i].nama) > 0) { 
	                strcpy(temp, data[j].nama); 
	                strcpy(data[j].nama, data[i].nama); 
	                strcpy(data[i].nama, temp); 
	            	} 
	        	} 
    		}
			printf(" Hasil Pengurutan : "); 
    		for (int i=0; i<n; i++) {
        		printf("\n String %d is %s\n", i+1, data[i].nama);  
        	}
			break;
		case 2:
			for (int j=0; j<n-1; j++) {	 
	        	for (int i=j+1; i<n; i++) {	 
	            if (strcmp(data[j].npm, data[i].npm) > 0) { 
	                strcpy(temp, data[j].npm); 
	                strcpy(data[j].npm, data[i].npm); 
	                strcpy(data[i].npm, temp); 
	            	} 
	        	} 
    		}
			printf(" Hasil Pengurutan : "); 
    		for (int i=0; i<n; i++) {
        		printf("\n String %d is %s\n", i+1, data[i].npm);  
        	}
			break;
		case 3:
			for(sb=0; sb<n; sb++){
				for(pb=0; pb<n-sb-1; pb++){
					if(data[pb].tgl_lahir > data[pb+1].tgl_lahir){
						tmp = data[pb].semester;
						data[pb].tgl_lahir = data[pb+1].tgl_lahir;
						data[pb+1].tgl_lahir=tmp;
					}
				}
			}
			printf("\n < Hasil pengurutan >\n");
			for(l=0; l<a; l++){
			printf("  | %d |\n", data[l].tgl_lahir);		
			}
			break;
		case 4: 
			for(sb=0; sb<n; sb++){
				for(pb=0; pb<n-sb-1; pb++){
					if(data[pb].semester > data[pb+1].semester){
						tmp = data[pb].semester;
						data[pb].semester = data[pb+1].semester;
						data[pb+1].semester=tmp;
					}
				}
			}
			printf("\n < Hasil pengurutan >\n");
			for(l=0; l<a; l++){
			printf("  | %d |\n", data[l].semester);		
			}
			break;
		case 5:
			for(sb=0; sb<n; sb++){
				for(pb=0; pb<n-sb-1; pb++){
					if(data[pb].ipk > data[pb+1].ipk){
						tmp = data[pb].ipk;
						data[pb].ipk = data[pb+1].ipk;
						data[pb+1].ipk=tmp;
					}
				}
			}
			printf("< Hasil pengurutan >\n");
			for(l=0; l<a; l++){
			printf("| %2f |\n", data[l].ipk);		
			}
			break;
	}
	printf(" Pengurutan BubbleSort Selesai ! tekan untuk melanjutkan...");
	getch();system("cls");
}

void AscendSelectionSort(int n, int mode){
	int i, j, min_idx, pilscr, tmpss, posisi, swap;
	char temp[MAX], minStr[MAX];;
	printf(" Anda memilih-%d\n\n", mode);
	Sleep(1000);
	printf(" Masukkan kategori Data Mahasiswa yang ingin disorting : \n 1.Nama\n 2.NPM\n 3.Tanggal Lahir\n 4.Semester\n 5.IPK");
	printf("\n Masukkan pilihan : ");
	scanf("%d", &pilscr);
	switch(pilscr) {
		case 1:
			// proses ke-x		     
		    for (i = 0; i < n-1; i++) 
		    { 
		        // cari elemen minimum
		        int min_idx = i; 
		        strcpy(minStr, data[i].nama); 
		        for (j = i+1; j < n; j++) 
		        { 
		            // jika min lebih besar dari data[j] 
		            if (strcmp(minStr, data[j].nama) > 0) 
		            { 
		                // tampung data[j] menjadi minStr dan update min_idx 
		                strcpy(minStr, data[j].nama); 
		                min_idx = j; 
		            } 
		        } 
		   
		        // Swap elemen terkecil dengan index terdepan 
		        if (min_idx != i) 
		        { 
		            char tempss[MAX]; 
		            strcpy(tempss, data[i].nama); //swap item[pos] and item[i] 
		            strcpy(data[i].nama, data[min_idx].nama); 
		            strcpy(data[min_idx].nama, tempss); 
		        } 
		    }
			printf("\n Hasil Pengurutan Selection Sort Nama (char) : \n"); 
		    for (i = 0; i < n; i++) {
		        printf(" urutan ke-%d: %s \n", i, data[i].nama);   
		        }
		    printf("\n");
			break;
		case 2:
			// proses ke-x
		    for (i = 0; i < n-1; i++) 
		    { 
		        // cari elemen minimum
		        int min_idx = i; 
		        strcpy(minStr, data[i].npm); 
		        for (j = i+1; j < n; j++) 
		        { 
		            // jika min lebih besar dari data[j] 
		            if (strcmp(minStr, data[j].npm) > 0) 
		            { 
		                // tampung data[j] menjadi minStr dan update min_idx 
		                strcpy(minStr, data[j].npm); 
		                min_idx = j; 
		            } 
		        } 
		   
		        // Swap elemen terkecil dengan index terdepan 
		        if (min_idx != i) 
		        { 
		            char tempss[MAX]; 
		            strcpy(tempss, data[i].npm); //swap item[pos] and item[i] 
		            strcpy(data[i].npm, data[min_idx].npm); 
		            strcpy(data[min_idx].npm, tempss); 
		        } 
		    }
			printf("\n Hasil Pengurutan Selection Sort Npm (char) : \n"); 
		    for (i = 0; i < n; i++) {
		        printf(" urutan ke-%d: %s \n", i, data[i].npm);   
		        }
		    printf("\n");
			break;
		case 3:
			for(i = 0; i < (n-1); i++){
			    posisi = i;
			    for (j = i + 1; j < n; j++){
			      	if(data[posisi].tgl_lahir > data[j].tgl_lahir){
			        posisi = j;
			      	}
			    }
			    if(posisi != i){
			      	swap = data[i].tgl_lahir;
			      	data[i].tgl_lahir = data[posisi].tgl_lahir;
			      	data[posisi].tgl_lahir = swap;
			    }
		  	}
			printf(" Hasil pengurutan Selection Sort Tanggal Lahir :\n");
			for(i = 0; i < n; i++){
			    printf(" urutan ke-%d : %d \n", i, data[i].tgl_lahir);
			}
			printf("\n");
			break;
		case 4:
			for(i = 0; i < (n-1); i++){
			    posisi = i;
			    for (j = i + 1; j < n; j++){
			      	if(data[posisi].semester > data[j].semester){
			        posisi = j;
			      	}
			    }
			    if(posisi != i){
			      	swap = data[i].semester;
			      	data[i].semester = data[posisi].semester;
			      	data[posisi].semester = swap;
			    }
		  	}
			printf(" Hasil pengurutan Selection Sort Semester :\n");
			for(i = 0; i < n; i++){
			    printf(" urutan ke-%d : %d \n", i, data[i].semester);
			}
			printf("\n");
			break;
		case 5:
			for(i = 0; i < (n-1); i++){
			    posisi = i;
			    for (j = i + 1; j < n; j++){
			      	if(data[posisi].ipk > data[j].ipk){
			        posisi = j;
			      	}
			    }
			    if(posisi != i){
			      	swap = data[i].ipk;
			      	data[i].ipk = data[posisi].ipk;
			      	data[posisi].ipk = swap;
			    }
		  	}
			printf(" Hasil pengurutan Selection Sort IPK :\n");
			for(i = 0; i < n; i++){
			    printf(" urutan ke-%d : %d \n", i, data[i].ipk);
			}
			printf("\n");
			break;
	}
	printf(" Pengurutan Selection Short Selesai ! tekan untuk melanjutkan...");
	getch();system("cls");
}

