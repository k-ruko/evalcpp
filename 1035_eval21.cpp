//Nama : Ade Cipta Pratama
//NIM : 226201035

//binary seacrh
#include <iostream>
#include "pustakaku.h"
using namespace std;

//prototipe fungsi
bool bSearch(int arr[], int cari, int low, int high, int *posisi, int *hitung);

//fungsi utama
int main()
{
	//deklarasi
	int jml, min, maks, dicari;
	bool ketemu;
	
	//masukkan jumlah data, min, maks
	cout << "Masukkan jumlah data: ";
	cin >> jml;
	cout << "Masukkan nilai angka terkecil: ";
	cin >> min;
	cout << "Masukkan nilai angka terbesar: ";
	cin >> maks;
	
	//deklarasi array dan ambil data random
	int data[jml];
	inputRand(data, jml, min, maks);
	
	//lakukan sortir
	selectionSort(data, jml, "ASC");
	
	//cetak isi array
	cout << "\n\nData di dalam array:\n";
	cetakArr(data, jml);
	
	//masukkan data yang dicari
	cout << "\nMasukkan angka yang dicari: ";
	cin >> dicari;
	
	//lakukan binary search
	int pos=0;
	int hitung=0;
	ketemu = bSearch(data, dicari, 0, jml-1 , &pos, &hitung);

	//cetak hasil pencarian
	if(ketemu) {
		cout << "\nAngka " << dicari << " ditemukan pada index ke-" << pos << " setelah " << hitung << " kali looping";
	} else {
		cout << "\nAngka " << dicari << " TIDAK ditemukan setelah " << hitung << " kali looping";
	}	
	
	return 0;
}

//fungsi binary search
bool bSearch(int arr[], int cari, int low, int high, int *posisi, int *hitung){
	int mid = (low+high)/2;
	int loop = 0;
	bool ketemu=false;
	
//looping untuk memeriksa data apakah ditemukan atau tidak ditemukan
	while(low <= high and not ketemu){
		cout << "\nlow" << low << " mid=" << mid << " high=" << high << " loop=" << loop;
		if(arr[mid] == cari){
			ketemu = true;
			*posisi = mid;
		} else if (arr[mid] > cari){
			high = mid - 1;
			mid = (low+high)/2;
		} else {
			low = mid + 1;
			mid = (low+high)/2;
		}
		loop++;
	}
	*hitung = loop;
	return ketemu;
}
