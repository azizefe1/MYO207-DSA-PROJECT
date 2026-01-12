// İsim SOYİSİM : Aziz Efe ERYILMAZ
// Öğrenci Numarası : 2420171031
// BTK Akademi Sertifika Bağlantısı : https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=bx1hLxdg7z

#include <stdio.h>

void dizi_yazdir(int dizi[], int BOYUT) {
	int i; 
	for (i=0; i<BOYUT; i++) {
		printf("%3d", dizi[i]);
	}
	printf("\n");
}

void arayaeklemeli_sirala(int dizi[], int BOYUT) {
	int i, j;      
	int anahtar;   
	
	for (i=1; i<BOYUT; i++) { 
		anahtar = dizi[i]; 
		for (j=i-1; j>=0 && anahtar<dizi[j]; j--) {
			dizi[j+1] = dizi[j];
		}
		dizi[j+1] = anahtar;
		printf("iter.%2d: ", i);
		dizi_yazdir(dizi, BOYUT);
	}
}
int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
	int orta_ind = (ilk_ind + son_ind) / 2;
	if (ilk_ind > son_ind) {
		return -1;
	}
	if (search == dizi[orta_ind]) {
		return orta_ind;
	}
	else if (search > dizi[orta_ind]) {
		return ikili_arama(dizi, BOYUT, search, orta_ind+1, son_ind);
	} 
	else {
		return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind-1);
	}
}

int main() {
	int A[] = {45, 12, 89, 3, 22, 10, 77, 56, 34, 15};
	int N = sizeof(A) / sizeof(A[0]);
	int aranan, sonuc;
	
	printf("--- ORIJINAL DIZI ---\n");
	dizi_yazdir(A, N);
	printf("\n");

	arayaeklemeli_sirala(A, N);
	
	printf("\n--- SIRALANMIS DIZI ---\n");
	dizi_yazdir(A, N);
	
	printf("\nAramak istediginiz deger: ");
	scanf("%d", &aranan);
	
	sonuc = ikili_arama(A, N, aranan, 0, N-1);
	
	if (sonuc == -1) {
		printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
	}
	else {
		printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);
	}
	return 0;
}