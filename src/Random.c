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
** DOSYA ADI..............: Random.c
**
** AÇIKLAMA
** --------
** Random.h kütüphanesindeki fonksiyonlar implement edilmiştir.  
** Rastgele sayi üretecek yapıya ait çeşitli fonksiyonlar ile constructor     
** ve destructor'ın yazıldığı program.
**********************************************************************************/

#include "Random.h"

//Random turunde bir ornek olusturulmus ve nesne yonelimlideki gibi bir sinifa
//ait constructor'a benzetim yapilmistir. Ayrica fonksiyon gostericilerinin, kendi
//fonksiyonlarini gosterme islemi gerceklestirilmistir.
Random ConstructRandom() 
{
	Random rndm;
	rndm = (Random) malloc(sizeof(struct MYRANDOM));

	rndm->currentAddress = INITIAL_ADDRESS;
	rndm->prior = PRIOR_CONTENT;
	rndm->currentBit = INITIAL_BITS;
	
	rndm->CurrentTime = &SystemCurrentTime;
	rndm->Generate = &GenerateRandom;
	rndm->Destruct = &DestructRandom;
	
	return rndm;
}

//Sistemin anlik zamaninin alinmasi
int SystemCurrentTime()
{
	clock_t ct = clock();
	return ct;
}

//Maksimum olarak girilen end degeri kadar olacak sekilde rastgele sayi uretilmesi
unsigned GenerateRandom(unsigned end, const Random randNum)
{
	unsigned generatedNumber;	//sonuc olarak uretilecek sayi

	//Gelen Random sinif ornegi uzerinde gerekli ayarlamalarin yapilmasi
	randNum->currentBit = ((randNum->currentAddress >> SHIFT_RIGHT_ZERO) ^ (randNum->currentAddress >> SHIFT_RIGHT_TWO) ^ 
							(randNum->currentAddress >> SHIFT_RIGHT_THREE) ^ (randNum->currentAddress >> SHIFT_RIGHT_FIVE) ) & AND_ONE;
	randNum->currentAddress = (randNum->currentAddress >> SHIFT_RIGHT_ONE) | (randNum->currentBit << SHIFT_LEFT_FIFTEEN);
	randNum->prior = randNum->currentAddress;

	//Rastgele sayi uretimi islemi
	generatedNumber = ((unsigned)SystemCurrentTime() % end) * randNum->currentAddress;

	return generatedNumber;		//uretilen sayiyi dondur
}

//Rastgele sayi uretimi sirasinda kullanilan objenin yok edilmesi.
void DestructRandom(Random randNum) 
{
	//Eger NULL ise, islem yapma.
	if (randNum == NULL)
		return;

	free(randNum);
	randNum = NULL;
}