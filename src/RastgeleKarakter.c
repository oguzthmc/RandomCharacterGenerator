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
** DOSYA ADI..............: RastgeleKarakter.c
**
** AÇIKLAMA
** --------
** RastgeleKarakter.h kütüphanesindeki fonksiyonlar implement edilmiştir.  
** Rastgele karakter üretecek yapıya ait çeşitli fonksiyonlar ile constructor     
** ve destructor'ın yazıldığı program.
**********************************************************************************/

//Kutuphanemizin yuklenmesi
#include "RastgeleKarakter.h"

//RastgeleKarakter tipinde bir ornek olusturulmus ve nesne yonelimlideki gibi bir
//sinifa ait constructor'a benzetim yapilmistir. Ayrica fonksiyon gostericilerinin, 
//kendi fonksiyonlarini gosterme islemi gerceklestirilmistir.
RastgeleKarakter ConstructRandomCharacter()
{
	RastgeleKarakter rk;
	rk = (RastgeleKarakter)malloc(sizeof(struct MYRANDOMCHARACTER));
	rk->randNum = ConstructRandom();

	rk->SetLimits = &SetAsciiLimits;
	rk->RandChar = &RandomChar;
	rk->RandChars = &MultipleRandomChar;
	rk->BetweenChar = &BetweenTwoCharsRandomChar;
	rk->BetweenChars = &BetweenTwoCharsRandomChars;
	rk->SelectChar = &SelectRandomChar;
	rk->SelectChars = &SelectRandomChars;
	rk->CreateSentence = &CreateRandomSentence;
	rk->Destruct = &DestructRandomCharacter;

	return rk;
}

//Ascii limitlerinin set edildigi fonksiyon
void SetAsciiLimits()
{
	asciiLetter.little_a = 97;
	asciiLetter.little_z = 122;
	asciiLetter.big_A = 65;
	asciiLetter.big_Z = 90;
}

//Rastgele bir karakter ureten fonksiyon
char RandomChar(RastgeleKarakter randCh)
{
	SetAsciiLimits();	//ascii limitleri belirlenmesi

	//Random sinifinin fonksiyonu ile uretim yapilir.
	unsigned rndNum = GenerateRandom(asciiLetter.big_Z, randCh->randNum);
	int i;
	//Rastgele uretilen sayi istenen aralikta degilse, tekrar uret.
	for (i = 0; !((rndNum >= asciiLetter.little_a && rndNum <= asciiLetter.little_z) 
			|| (rndNum >= asciiLetter.big_A && rndNum <= asciiLetter.big_Z)); ++i)
	{
		rndNum = GenerateRandom(asciiLetter.little_z, randCh->randNum);
	}
	return (char)rndNum;	//Uretilen karakter dondurulur.
}

//Rastgele birden cok karakter ureten fonksiyon
char* MultipleRandomChar(RastgeleKarakter randCh, unsigned howMany)
{
	//Uretilecek karakterler icin bellekte yer ayrilmasi
	char* randChars = (char*)malloc(sizeof(char) * howMany);
	unsigned j = 0;		//dongu degiskeni
	//Kac tane uretelim?
	while (j < howMany) 
	{
		//Uretilen karakterin diziye atilmasi
		randChars[j] = RandomChar(randCh);
		j++;	//bir sonraki iterasyona gec.
	}
	return randChars;	//Sonuc dizisini dondur.
}

//Verilen karakterler arasında rastgele bir karakter ureten fonksiyon
char BetweenTwoCharsRandomChar(RastgeleKarakter randCh, char start, char finish)
{
	SetAsciiLimits();	//ascii limitleri belirlenmesi
	//Random sinifinin fonksiyonu ile uretim yapilir.
	unsigned rndNum = GenerateRandom(asciiLetter.little_z, randCh->randNum);
	//Uretilen sayi istenen araliklarda ve degerde degilse, yeniden uret.
	do 
	{
		rndNum = GenerateRandom(asciiLetter.little_z, randCh->randNum);
	} while (!(rndNum >= (int)start && rndNum <= (int)finish) || 
				(rndNum > asciiLetter.big_Z && rndNum < asciiLetter.little_a));

	return (char)rndNum;	//Uretilen karakteri dondur.
}

//Verilen karakterler arasında rastgele birden cok karakter ureten fonksiyon
char* BetweenTwoCharsRandomChars(RastgeleKarakter randCh, char start, char finish, unsigned howMany)
{
	SetAsciiLimits();	//ascii limitleri belirlenmesi
	//Uretilecek karakterlere heap'te yer tahsisi
	char* randChars = (char*) malloc(sizeof(char) * howMany);
	unsigned k, l;	//dongu degiskenleri
	//Random sinifinin fonksiyonu ile uretim yapilir.
	unsigned rndNum = GenerateRandom(asciiLetter.little_z, randCh->randNum);
	k = 0;
	//Kac tane uretelim?
	while (k < howMany)
	{
		//Uretilen sayi istenen araliklarda ve degerde degilse, yeniden uret.
		for (l = 0; !(rndNum >= (int)start && rndNum <= (int)finish); ++l)
		{
			rndNum = GenerateRandom(asciiLetter.little_z, randCh->randNum);
		}
		//Uretilen sayinin karakter karsiliginin sonuc dizisine atilmasi
		randChars[k] = (char)rndNum;
		//Normal akis devam ediyorsa, uretimi yap.
		rndNum = GenerateRandom(asciiLetter.little_z, randCh->randNum);
		k++;	//bir sonraki iterasyona gec.
	}
	randChars[k] = '\0';	//Sonuc dizisi kapatildi.
	return randChars;		//Sonucu dizisi donduruldu.
}

//Verilen karakter dizisinden rastgele bir karakter ureten fonksiyon
char SelectRandomChar(RastgeleKarakter randCh, char* chars)
{
	//Gelen karakter dizisinin boyutunun olculmesi
	unsigned size = (sizeof(chars) / sizeof(chars[0])) - 1;
	unsigned randomNumber;	//rastgele sayi sonucunun bulunacagi degisken

	//Uretilen sayi istenen araliklarda ve degerde degilse, yeniden uret.
	do {
		randomNumber = GenerateRandom(size, randCh->randNum);
	} while (!(randomNumber != 6 && randomNumber < size && randomNumber >= 0));

	return (char)chars[randomNumber];	//uretilen karakteri dondur.
}

//Verilen karakter dizisinden rastgele birden cok karakter ureten fonksiyon
char* SelectRandomChars(RastgeleKarakter randCh, char* chars, unsigned howMany)
{
	//Karakter dizisinden rastgele seçilecek karakterler icin heap'ten yer alinmasi 
	char *selected = (char*) malloc(sizeof(char) * howMany);
	//Gelen karakter dizisinin boyutunun belirlenmesi
	unsigned size = (sizeof(chars) / sizeof(chars[0])) - 1;
	unsigned randomNumber;	//rastgele sayi sonucunun bulunacagi degisken
	unsigned l = 0;		//dongu degiskeni

	//Kac tane isteniyorsa, o kadar rastgele uretim yap.
	do
	{
		//Uretilen sayi istenen araliklarda ve degerde degilse, yeniden uret.
		do 
		{
			randomNumber = GenerateRandom(size, randCh->randNum);
		} while (!(randomNumber != 6 && randomNumber < size && randomNumber >= 0));
		//Uretilen sayinin indeksinde yer alan karakterin sonuc dizisine atilmasi
		selected[l] = chars[randomNumber];
		//Random sayi uretimi
		randomNumber = GenerateRandom(size, randCh->randNum);	
		l++;	//Bir sonraki iterasyona gec.
	} while (l < howMany);
	selected[l] = '\0';		//String tamamlandi.
	return selected;	//Sonunda uretilen char dizisini dondur.
}

//Istenen tipte ve boyutta rastgele karakter ureten fonksiyon
char* CreateRandomSentence(RastgeleKarakter randCh, int sentenceType)
{
	//Cumlenin olusturulacagi bellek bolgesinde yer tahsis edilmesi
	char *randomSentence = (char*)malloc(sizeof(char) * SENTENCE_LENGTH+1);
	unsigned int index;			//cumledeki harfler uzerinde ilerleyecek degisken
	int spaceAndDotCount = 4;	//toplam bosluk sayisi (3) + nokta (1)

	for (index = 0; index < SENTENCE_LENGTH + spaceAndDotCount; ++index)
	{
		randomSentence[index] = RandomChar(randCh);
		//Eger cumle turu 0 ise; cumlenin ilk harfi buyuk, digerleri kucuk olan cumle uret.
		if (sentenceType == 0)
		{
			//Eger ilk kelimenin bas harfi kucukse, buyuk yap.
			if (index == 0)
			{
				randomSentence[index] = toupper(randomSentence[index]);
			}
			//Diger karakterler buyukse, kucuge cevir.
			else {
				randomSentence[index] = tolower(randomSentence[index]);
			}
		}
		//Eger cumle turu 1 ise; her kelimenin ilk harfi buyuk, digerleri kucuk olan cumle uret.
		else if (sentenceType == 1)
		{
			//Her kelimenin bas harflerinin buyuk yapilmasi islemi
			if (index == 0 || index == FIRST_WORD_LENGTH + 1 || 
				index == FIRST_WORD_LENGTH + 1 + SECOND_WORD_LENGTH + 1 ||
				index == FIRST_WORD_LENGTH + 1 + SECOND_WORD_LENGTH + 1 + THIRD_WORD_LENGTH + 1 ||
				index == FIRST_WORD_LENGTH + 1 + SECOND_WORD_LENGTH + 1 + THIRD_WORD_LENGTH + 1 + FOURTH_WORD_LENGTH + 1)
			{
				randomSentence[index] = toupper(randomSentence[index]);
			}
			//Kelimenin bas harfi haricindeki harflerini kucuk yap.
			else {
				randomSentence[index] = tolower(randomSentence[index]);
			}
		}
		//Eger cumle turu 2 ise; rastgele uretilen karakteri direkt gonder ve bir şey yapmadan devam et.
		else if (sentenceType == 2)
		{
			;
		}

		//Bosluklarin koyulmasi gereken yerlerin ayarlanmasi
		if (index == FIRST_WORD_LENGTH || index == FIRST_WORD_LENGTH + SECOND_WORD_LENGTH + 1 || 
			index == FIRST_WORD_LENGTH + SECOND_WORD_LENGTH + THIRD_WORD_LENGTH + 1 + 1 ||
			index == FIRST_WORD_LENGTH + SECOND_WORD_LENGTH + THIRD_WORD_LENGTH + FOURTH_WORD_LENGTH + 1 + 1 + 1)
		{
			randomSentence[index] = SPACE;
		}

		//Cumle sonuna nokta koyulmasi
		if (index == SENTENCE_LENGTH + spaceAndDotCount - 1)
		{
			randomSentence[index] = DOT_SIGN;
		}
	}
	randomSentence[index] = '\0';
	return randomSentence;
}

//Rastgele karakter uretimi sirasinda kullanilan objenin ve onun gosterdigi Random sinifi objesinin yok edilmesi.
void DestructRandomCharacter(RastgeleKarakter randCh)
{
	//Eger NULL ise, islem yapma.
	if (randCh == NULL)
		return;
	
	free(randCh->randNum);
	randCh->randNum = NULL;

	free(randCh);
	randCh = NULL;
}

