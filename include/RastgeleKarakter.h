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
** DOSYA ADI..............: RastgeleKarakter.h
**
** AÇIKLAMA
** --------
** Rastgele karakter üretimini sağlayacak yapıya ait tüm sabit tanımlamaların,
** sınıfların (structs), siniflara ait degiskenlerin, fonksiyonların ve 
** fonksiyon göstericilerinin bildiriminin yapıldığı kütüphane.
**********************************************************************************/

//Preprocessor directives
#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

//Kullanilan kutuphaneler
#include "Random.h"
#include <ctype.h>

//Rastgele cumle olusturulmasi icin tanimlanan sabitler
#define SENTENCE_LENGTH		22
#define FIRST_WORD_LENGTH	4
#define SECOND_WORD_LENGTH	5
#define THIRD_WORD_LENGTH	6
#define FOURTH_WORD_LENGTH	7
#define SPACE				' '
#define DOT_SIGN			'.'

//Rasgele karakter uretimi icin belirlenen ASCII sinirlari
struct AsciiLimits {
	int little_a;
	int little_z;
	int big_A;
	int big_Z;
};

//Ascii degiskenlerine erisimi saglayacak AsciiLimits ornegi
struct AsciiLimits asciiLetter;		

//Rastgele karakter uretimi icin olusturulan ana sinif
struct MYRANDOMCHARACTER
{
	Random randNum;		//Random sinifina ait ornek

	//Fonksiyon Göstericileri
	void (*SetLimits)();
	char (*RandChar)(struct MYRANDOMCHARACTER*);
	char* (*RandChars)(struct MYRANDOMCHARACTER*, unsigned);
	char (*BetweenChar)(struct MYRANDOMCHARACTER*, char, char);
	char* (*BetweenChars)(struct MYRANDOMCHARACTER*, char, char, unsigned);
	char (*SelectChar)(struct MYRANDOMCHARACTER*, char*);
	char* (*SelectChars)(struct MYRANDOMCHARACTER*, char*, unsigned);
	char* (*CreateSentence)(struct MYRANDOMCHARACTER*, int);
	void (*Destruct)(struct MYRANDOMCHARACTER*);
};

//Olusturulan sinifin ozelliklerini tasiyan RastgeleKarakter ornegi
typedef struct MYRANDOMCHARACTER* RastgeleKarakter;

//Rastgele karakter uretimi fonksiyonlari
RastgeleKarakter ConstructRandomCharacter();
void SetAsciiLimits();
char RandomChar(RastgeleKarakter);
char* MultipleRandomChar(RastgeleKarakter, unsigned);
char BetweenTwoCharsRandomChar(RastgeleKarakter, char, char);
char* BetweenTwoCharsRandomChars(RastgeleKarakter, char, char, unsigned);
char SelectRandomChar(RastgeleKarakter, char*);
char* SelectRandomChars(RastgeleKarakter, char*, unsigned);
char* CreateRandomSentence(RastgeleKarakter, int);
void DestructRandomCharacter(RastgeleKarakter);

#endif
