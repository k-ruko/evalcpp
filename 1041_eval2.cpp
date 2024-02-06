// deprian pagesong/226201041
//binary search sebagai fungsi

#include <iostream>
#include "mypustaka.h"
using namespace std;

//protoptipe fungsi
bool bSearch(int arr[], int cari, int low, int high, int *posisi, int* loop);

//fungsiutama
int main()
{
	//dekalarasi
	int jml, min, maks, dicari;
	bool ketemu;
	int loop = 0;
	
	//masukkan jumlah data, min, maks
	cout << "Masukkan jumlah data : ";
	cin >> jml;
	cout << "Masukkan nilai angka terkecil : ";
	cin >> min;
	cout << "Masukkan nilai angka terbesar : ";
	cin >> maks;
	
	//deklarasi array dan ambil data random
	int data[jml];
	inputRand(data, jml, min, maks);
	
	//lakukan sortir
	insertionSort(data, jml, "ASC");
	
	//cetak isi array
	cout << "\n\nData di dalam array:\n";
	cetakArr(data, jml);
	
	//masukkan data yang dicari
	cout << "\nMasukkan angka yang dicari : ";
	cin >> dicari;
	
	//lakukan binari search
	int pos=0;
	ketemu = bSearch(data, dicari, 0, jml-1, &pos, &loop);
	 //cetak hasil pencarian
	if(ketemu)
	{
		cout << "\nData ditemukan " << dicari << " pada indeks " << pos << " setelah melakukan " << loop << " looping";
	} 
	else
	{
		cout << "\nData tidak ditemukan setelah melakukan " << loop << " kali";
	}
	
	return 0;
}

//fungsi binary search
bool bSearch(int arr[], int cari, int low, int high, int *posisi, int* loop)
{
	int mid = (low+high)/2;
	bool ketemu = false;

	//looping untuk memeriksa data pakah ditemukan atau tidak ditemukan
	while(low <= high and not ketemu)
	{
		cout << "\nLow=" << low << " Mid=" << mid << " High=" << high;
 		if(arr[mid] == cari)
		{
			ketemu = true;
			*posisi = mid;
		}
		else if (arr[mid] > cari)
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		*loop += 1;
	}
	return ketemu;
}

