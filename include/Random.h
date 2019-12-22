/*********************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** BSM208 - PROGRAMLAMA DİLLERİNİN PRENSİPLERİ DERSİ
** 2018-2019 BAHAR DÖNEMİ
**
** ÖDEV NUMARASI..........: 3
** ÖĞRENCİ ADI............: OĞUZHAN TOHUMCU
** ÖĞRENCİ NUMARASI.......: B181210397
** DERSİN ALINDIĞI GRUP...: 1-B
** DOSYA ADI..............: Random.h
**
** AÇIKLAMA
** --------
** Rastgele sayi üretimini sağlayacak yapıya ait tüm sabit tanımlamaların,
** sınıfların (structs), siniflara ait degiskenlerin, fonksiyonların ve 
** fonksiyon göstericilerinin bildiriminin yapıldığı kütüphane.
**********************************************************************************/

//Preprocessor directives
#ifndef RANDOM_H
#define RANDOM_H

//Kullanilan kutuphaneler
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Random sinifindaki kullanilan sabit tanimlamalari
#define	SHIFT_RIGHT_ZERO	0
#define SHIFT_RIGHT_ONE		1
#define SHIFT_RIGHT_TWO		2
#define	SHIFT_RIGHT_THREE	3
#define	SHIFT_RIGHT_FIVE	5
#define SHIFT_LEFT_FIFTEEN	15
#define AND_ONE				1

#define INITIAL_BITS		0x00000
#define INITIAL_ADDRESS		0xACE1u
#define	PRIOR_CONTENT		0
 
//Kendi random sinifimiz
struct MYRANDOM
{
	//Sinif degiskenleri
	unsigned currentBit;
	unsigned short currentAddress;
	unsigned prior;

	//Fonksiyon gostericileri
	int (*CurrentTime)();
	unsigned (*Generate)(unsigned, struct MYRANDOM*);
	void (*Destruct)(struct MYRANDOM*);
};

//Random sinifimiza ait ornek
typedef struct MYRANDOM* Random;

//Random sinifinda kullanilan fonksiyonlar
Random ConstructRandom();
int SystemCurrentTime();
unsigned GenerateRandom(unsigned, const Random);
void DestructRandom(Random);


#endif
