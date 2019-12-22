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
** DOSYA ADI..............: Test.c
**
** AÇIKLAMA
** --------
** Nesne yönelimliliğe benzetim yapılarak geliştirilen yapının kontrolü yapılır.  
** Ayrıca RastgeleKarakter sınıfının örneği oluşturularak, doğru çalışıp 
** çalışmadığı test edilir. Bunun sonucunda, istenen formatta çıktı elde edilir.
**********************************************************************************/

#include "RastgeleKarakter.h"

int main(int argc, char const *argv[])
{
	int i;		//dongu degiskeni
	char startCh = 'a';		//baslangıc karakteri
	char finishCh = 'k';	//bitis karakteri
	char *specifiedChars = "gyucne";	//ornek karakter seti

	//RastgeleKarakter sinifinin bir objesi olusturulur.
	RastgeleKarakter randomly = ConstructRandomCharacter();

	//Welcome screen
	printf("\n ------------------------------------"); 
	printf("# RASTGELE KARAKTER URETIMI EKRANINA HOSGELDINIZ #");
	printf("------------------------------------\n");
	printf("\t\t\t\t\t--------------------------------------------\n");
	
	//Rastgele olarak uretilen birer karakter ekrana yazdirildi.
	printf(" Rastgele Karakter: %c\n", RandomChar(randomly));
	printf(" Rastgele Karakter: %c\n", RandomChar(randomly));

	//Istenen sayida rastgele olarak uretilen karakterler konsola yazdirildi.
	printf(" Rastgele 3 Karakter: %s\n", MultipleRandomChar(randomly, 3));
	printf(" Rastgele 3 Karakter: %s\n", MultipleRandomChar(randomly, 3));
	printf(" Rastgele 5 Karakter: %s\n", MultipleRandomChar(randomly, 5));

	//Verilen iki karakter arasinda sirasiyla bir ve iki karakter uretildi ve ekranda gosterildi.
	printf(" Verilen iki karakter (a,k): %c\n", BetweenTwoCharsRandomChar(randomly, startCh, finishCh));
	printf(" Verilen iki karakter (a,k): %s\n", BetweenTwoCharsRandomChars(randomly, startCh, finishCh, 2));

	//Belirtilen karakterler arasindan rastgele uretilen birer karakter ekrana yazdirildi.
	//Ardindan bu sefer 2 karakter uretilerek ayni islem uygulandi.
	printf(" Belirtilen Karakterler (g,y,u,c,n,e): %c\n", SelectRandomChar(randomly, specifiedChars));
	printf(" Belirtilen Karakterler (g,y,u,c,n,e): %c\n", SelectRandomChar(randomly, specifiedChars));
	printf(" Belirtilen Karakterler (g,y,u,c,n,e): %s\n", SelectRandomChars(randomly, specifiedChars, 2));

	//Rastgele 100 karakter, tek tek rastgele uretilerek olusturuldu.
	printf(" Rastgele 100 Karakter: ");
	for (int i = 0; i < 100; ++i)
	{
		printf("%c", RandomChar(randomly));
	}
	printf("\n");

	//Verilen cumle tipinde, SENTENCE_LENGTH (macro) uzunlugunda rastgele cumle turetildi.
	//Cumlenin uzunlugu degistirilmesi icin, SENTENCE_LENGTH degistirilmelidir.
	//Cumle tipi 0, 1 ve 2 degerlerini alabilir.
	printf(" %d karakterli Cumle: %s\n", SENTENCE_LENGTH, CreateRandomSentence(randomly, 1));

	//Olusturulan RandomKarakter ornegi yok edildi.
	DestructRandomCharacter(randomly);

	return 0;
}