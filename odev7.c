#include <stdio.h>
#include <conio.h>
#include <string.h>
enum ok {ust=72,alt=80,sol=75,sag=77
};
int main()
{
	int ay,yil,aygunsayisi,yilxx,x,y,ayxx;
	char ay_ad[15];//ayin numaras�n� ald�ktan sonra bunu isme �evirmek i�in.
	printf("Ay ve yil bilgisini giriniz(AA/YYYY)");
	scanf("%d/%d",&ay,&yil);
	while(ay<1||ay>12||yil<1900){
	if((ay<1||ay>12)&&yil<1900){
		printf("[1-12] arasinda ay degeri giriniz\n1900 yili ve sonrasi icin yil degeri giriniz\n\n");
		printf("Ay ve yil bilgisini giriniz(AA/YYYY)");
		scanf("%d/%d",&ay,&yil);}
	else if(ay<1||ay>12){printf("[1-12] arasinda ay degeri giriniz\n\n");
	printf("Ay ve yil bilgisini giriniz(AA/YYYY)");
	scanf("%d/%d",&ay,&yil);}
	else if(yil<1900){
	printf("1900 yili ve sonrasi icin yil degeri giriniz\n\n");
	printf("Ay ve yil bilgisini giriniz(AA/YYYY)");
	scanf("%d/%d",&ay,&yil);}
	}//ge�ersiz giri�lerin ay�klanmas� yukar�daki while ile �nlendi
	yilxx=yil;//yil de�eri a�a��daki uzun g�n denkleminde de�i�ebilece�inden yede�e al�nd�
	ayxx=ay;//ay de�eri a�a��daki uzun g�n denkleminde de�i�ebilece�inden yede�e al�nd�
	enum ok tus;
	while(1){
	int ngun=1,i=0,ibb=0,gun=1;
	gun=(gun+=ay<3?yil--:yil-2,23*ay/9+gun+4+yil/4-yil/100+yil/400)%7;
	switch (ay){
		case 1:
			strcpy(ay_ad,"Ocak");
			aygunsayisi=31;
			break;
		case 2:
			strcpy(ay_ad,"Subat");
			if(yil%4==0||yil%100==0)
			aygunsayisi=29;
			else
			aygunsayisi=28;
			break;
		case 3:
			strcpy(ay_ad,"Mart");
			aygunsayisi=31;
			break;
		case 4:
			strcpy(ay_ad,"Nisan");
			aygunsayisi=30;
			break;
		case 5:
			strcpy(ay_ad,"Mayis");
			aygunsayisi=31;
			break;
		case 6:
			strcpy(ay_ad,"Haziran");
			aygunsayisi=30;
			break;
		case 7:
			strcpy(ay_ad,"Temmuz");
			aygunsayisi=31;
			break;
		case 8:
			strcpy(ay_ad,"Agustos");
			aygunsayisi=31;
			break;
		case 9:
			strcpy(ay_ad,"Eylul");
			aygunsayisi=30;
			break;
		case 10:
			strcpy(ay_ad,"Ekim");
			aygunsayisi=31;
			break;
		case 11:
			strcpy(ay_ad,"Kasim");
			aygunsayisi=30;
			break;
		case 12:
			strcpy(ay_ad,"Aralik");
			aygunsayisi=31;
			break;
	}//bu switch ile aylara numaralar�na g�re isimleri verildi
	system("cls");
	printf("%s %d TAKVIMI\n",ay_ad,yilxx);
	printf("PZT\tSALI\tCARS\tPERS\tCUMA\tCMT\tPAZ\n");
	for(y=0;y<6;y++){
		for(x=0,ibb=0;ngun<aygunsayisi+1&&ibb<7;x++){
			if(gun==0){gun=7;
			}
			if(i<gun-1){printf("\t");i++;
			}else{
			printf("%d\t",ngun);
			ngun++;}ibb++;
		}
		printf("\n");
	}
	printf("Ok tuslariyla takvimde gecis yapabilirsiniz");
	tus=getch();//kullan�c�dan al�ndan tu�a g�re takvimde de�i�iklikler olacak. bunlar i�in tu� istendi.
	switch(tus){
		case ust:
			yilxx--;
			yil=yilxx;
			break;
		case alt:
			yilxx++;
			yil=yilxx;
			break;
		case sol:
			if(ayxx==1){
				ayxx=12;
				yilxx--;
				yil=yilxx;
				ay=ayxx;
			}
			else{
				ayxx--;
				ay=ayxx;
			}
			break;
		case sag:
			if(ayxx==12){
				ayxx=1;
				yilxx++;
				yil=yilxx;
				ay=ayxx;
			}
			else{
				ayxx++;
				ay=ayxx;
			}
			break;
	}
	}
	return 0;
}
