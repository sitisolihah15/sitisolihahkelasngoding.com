#include <stdio.h>
#include <string.h>

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
char nama[50];
int nilai;
char grade;
};

struct Mahasiswa data[100];
int jumlahMahasiswa = 0;

// Fungsi untuk menentukan nilai huruf
char tentukanGrade(int nilai) {
if (nilai >= 85) {
return 'A';
} else if (nilai >= 70) {
return 'B';
} else if (nilai >= 60) {
return 'C';
} else if (nilai >= 50) {
return 'D';
} else {
return 'E';
}
}

// Fungsi input data mahasiswa
void inputData() {
int i;

printf("\n===== DAFTAR INPUT DATA MAHASISWA =====\n");
printf("Masukkan jumlah mahasiswa: ");
scanf("%d", &jumlahMahasiswa);
getchar();

if (jumlahMahasiswa <= 0 || jumlahMahasiswa > 100) {
printf("Jumlah mahasiswa tidak valid. Maksimal 100.\n");
jumlahMahasiswa = 0;
return;
}

for (i = 0; i < jumlahMahasiswa; i++) {
printf("\nData mahasiswa ke-%d\n", i + 1);

printf("Nama : ");
fgets(data[i].nama, sizeof(data[i].nama), stdin);
data[i].nama[strcspn(data[i].nama, "\n")] = '\0';

do {
printf("Nilai : ");
scanf("%d", &data[i].nilai);
getchar();

if (data[i].nilai < 0 || data[i].nilai > 100) {
printf("Nilai harus di antara 0 sampai 100, silakan input ulang.\n");
}

} while (data[i].nilai < 0 || data[i].nilai > 100);

data[i].grade = tentukanGrade(data[i].nilai);
}

printf("\nData mahasiswa berhasil disimpan.\n");
}

// Fungsi menampilkan semua data
void tampilkanData() {
int i;

if (jumlahMahasiswa == 0) {
printf("\nBelum ada data yang diinput.\n");
return;
}

printf("\n===== DATA MAHASISWA =====\n");
printf("---------------------------------------------------\n");
printf("No\tNama\t\t\tNilai\tGrade\n");
printf("---------------------------------------------------\n");

for (i = 0; i < jumlahMahasiswa; i++) {
printf("%d\t%-20s\t%d\t%c\n", i + 1, data[i].nama, data[i].nilai, data[i].grade);
}
}

// Fungsi analisis nilai
void analisisNilai() {
int i;
int total = 0;

int nilaiTertinggi, nilaiTerendah;
int lulus = 0, tidakLulus = 0;
float rataRata;

if (jumlahMahasiswa == 0) {
printf("\nBelum ada data yang diinput.\n");
return;
}

nilaiTertinggi = data[0].nilai;
nilaiTerendah = data[0].nilai;

for (i = 0; i < jumlahMahasiswa; i++) {
total += data[i].nilai;

if (data[i].nilai > nilaiTertinggi) {
nilaiTertinggi = data[i].nilai;
}

if (data[i].nilai < nilaiTerendah) {
nilaiTerendah = data[i].nilai;
}

if (data[i].nilai >= 60) {
lulus++;
} else {
tidakLulus++;
}
}

rataRata = (float) total / jumlahMahasiswa;

printf("\n===== ANALISIS NILAI =====\n");
printf("Rata-rata nilai : %.2f\n", rataRata);
printf("Nilai tertinggi : %d\n", nilaiTertinggi);
printf("Nilai terendah : %d\n", nilaiTerendah);
printf("Jumlah mahasiswa lulus : %d\n", lulus);
printf("Jumlah tidak lulus : %d\n", tidakLulus);
}

// Fungsi menampilkan ranking
void tampilkanRanking() {
int i, j;
struct Mahasiswa sementara;
struct Mahasiswa urut[100];

if (jumlahMahasiswa == 0) {
printf("\nBelum ada data yang diinput.\n");
return;
}

for (i = 0; i < jumlahMahasiswa; i++) {
urut[i] = data[i];
}

for (i = 0; i < jumlahMahasiswa - 1; i++) {
for (j = 0; j < jumlahMahasiswa - i - 1; j++) {
if (urut[j].nilai < urut[j + 1].nilai) {
sementara = urut[j];
urut[j] = urut[j + 1];
urut[j + 1] = sementara;
}

}
}

printf("\n===== RANKING MAHASISWA =====\n");
printf("---------------------------------------------------\n");
printf("Rank\tNama\t\t\tNilai\tGrade\n");
printf("---------------------------------------------------\n");

for (i = 0; i < jumlahMahasiswa; i++) {
printf("%d\t%-20s\t%d\t%c\n", i + 1, urut[i].nama, urut[i].nilai, urut[i].grade);
}
}

// Program utama
int main() {
int pilihan;

do {
printf("\n========== MENU ==========\n");
printf("1. Input Data Mahasiswa\n");
printf("2. Tampilkan Semua Data\n");
printf("3. Analisis Nilai\n");
printf("4. Tampilkan Ranking\n");
printf("5. Keluar\n");
printf("Pilih menu: ");
scanf("%d", &pilihan);
getchar();

switch (pilihan) {
case 1:
inputData();

break;
case 2:
tampilkanData();
break;
case 3:
analisisNilai();
break;
case 4:
tampilkanRanking();
break;
case 5:
printf("\nProgram selesai. Terima kasih.\n");
break;
default:
printf("\nPilihan menu tidak tersedia.\n");
}

} while (pilihan != 5);

return 0;
}
