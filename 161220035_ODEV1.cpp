#include <stdio.h>
#include <stdlib.h>

typedef struct polinom
{ int katsayi;
int us;
struct polinom *sonraki;
} Polinomlar;
Polinomlar *ilk=NULL,*son=NULL,*p1,*ilk2=NULL,*son2=NULL,*p2,*ilk3=NULL,*son3=NULL,*p3;


Polinomlar *BilgiAl(int kat3,int us3);
void Sirali_Ekle(Polinomlar *p3);

Polinomlar * Polinom_Topla(Polinomlar * p1, Polinomlar * p2){
		Polinomlar *gecici;
		Polinomlar *gecici2;
		int k,u,x=0,y=0;
		gecici=ilk;
		gecici2=ilk2;
		
		while(gecici !=NULL){
			while(gecici2 != NULL){
				if(gecici->us==gecici2->us){	
					k=gecici->katsayi+gecici2->katsayi;
					u=gecici->us;
					p3=BilgiAl(k,u);
					Sirali_Ekle(p3);
					x++;
				}
			
				gecici2=gecici2->sonraki;
			}
			
			if(x==0){
				p3=BilgiAl(gecici->katsayi,gecici->us);
					Sirali_Ekle(p3);
				
			}
			x=0;
			gecici2=ilk2;
			gecici=gecici->sonraki;
		}
		gecici=ilk;
		gecici2=ilk2;
	
		while(gecici2 !=NULL){	
			while(gecici != NULL){
				if(gecici2->us==gecici->us){
					p3=BilgiAl((gecici2->katsayi+gecici->katsayi),(gecici2->us));
					Sirali_Ekle(p3);
					y++;
				}
				gecici=gecici->sonraki;
			}
			if(y==0){
				p3=BilgiAl(gecici2->katsayi,gecici2->us);
					Sirali_Ekle(p3);
				
			}
			y=0;
			gecici=ilk;
			gecici2=gecici2->sonraki;
		}
		
	return p3;
	
	
}
void Sirali_Ekle(Polinomlar *p3){
	Polinomlar *gecici;
	if(ilk3==NULL){
		ilk3=p3;
		son3=p3;
		son3->sonraki=NULL;
	}
	else
	{
		//Girilen sayi ilk sayidan kucuk ise
        if ((ilk3->us) < (p3->us)) {
            p3->sonraki=ilk3;
            ilk3=p3;
        } else {
            gecici = ilk3;
            
            while (gecici != NULL) {
                //gecici elemaninin sonraki null ise ve son elemandan buyukse
                  if(gecici->katsayi==p3->katsayi && gecici->us==p3->us) {
                	
				break;
				}
                if (gecici->sonraki == NULL && (gecici->us) > (p3->us)) {
                    p3->sonraki = NULL;
                    gecici->sonraki = p3;
                    break;
                }
                //Araya Ekleme
                if ((gecici->sonraki->us) < (p3->us)) {
                    p3->sonraki = gecici->sonraki;
                    gecici->sonraki = p3;
                    break;
                }
                
              
                
                gecici = gecici->sonraki;
            }
	}
	
}
}
Polinomlar *BilgiAl(int kat3,int us3)
{
	p1=(Polinomlar*)malloc(sizeof(Polinomlar));
 	  
 	  p1->katsayi=kat3;
 	  p1->us=us3;
	return p1;
}
void Ekle(Polinomlar *p1){
	if(ilk==NULL){
		ilk=p1;
		son=p1;
		son->sonraki=NULL;
	}
	else
	{
		son->sonraki=p1;
		son=p1;
		son->sonraki=NULL;
	}
	
}
void Ekle2(Polinomlar *p2){
	if(ilk2==NULL){
		ilk2=p2;
		son2=p2;
		son2->sonraki=NULL;
	}
	else
	{
		son2->sonraki=p2;
		son2=p2;
		son2->sonraki=NULL;
	}
	
}

void Listele(){
	Polinomlar *gecici;
	gecici=ilk;
	while(gecici!=NULL){
		printf("%dx^%d ",gecici->katsayi,gecici->us);
		gecici=gecici->sonraki;
	}
	printf("\n");
}
void Listele2(){
	Polinomlar *gecici;
	gecici=ilk2;
	while(gecici!=NULL){
		printf("%dx^%d ",gecici->katsayi,gecici->us);
		gecici=gecici->sonraki;
	}
	printf("\n");
}
void Listele3(){
	Polinomlar *gecici;
	gecici=ilk3;
	if(gecici==NULL)printf("p3 bos");
	while(gecici!=NULL){
		printf("%dx^%d ",gecici->katsayi,gecici->us);
		gecici=gecici->sonraki;
	}
}

main(){
	Polinomlar *p1,*p2,*p3,*gecici;
	int kat2=0,us2=0,i=0,q=0;
	int dizi[6];
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	 if ((fp1 = fopen ("polinom1.txt", "r")) == NULL) {
      printf("Dosya acma hatasi!");
      exit(1);
  } 
  if ((fp2 = fopen ("polinom2.txt", "r")) == NULL) {
      printf("Dosya acma hatasi!");
      exit(1);
  } 

if ((fp3 = fopen ("polinom3.txt", "w")) == NULL) {
      printf("Dosya acma hatasi!");
      exit(1);
  }  
  
 while(!feof(fp1)){
 	
 	dizi[i]=getc(fp1)-'0';
 	if(dizi[i]==-3)q++;
 	if(dizi[i]<10 && dizi[i]>=0 && i==0){	 
	 if(q!=0){
	 	dizi[i]=dizi[i]-(2*dizi[i]);
	 	kat2=dizi[i];
	 	q=0;
	 }else
	  	kat2=dizi[i];
	 
 	i++;
}
else if(dizi[i]<10 && dizi[i]>=0 && i==1){
	us2=dizi[i];
	p1=BilgiAl(kat2,us2);
 	Ekle(p1);
 	kat2=0;
 	us2=0;
	i=0;
}

}
if(kat2!=0 && us2==0)
{
	p1=BilgiAl(kat2,us2);
 	Ekle(p1);
}

Listele();
i=0;

 while(!feof(fp2)){

 	dizi[i]=getc(fp2)-'0';
 
 if(dizi[i]==-3)q++;
 	if(dizi[i]<10 && dizi[i]>=0 && i==0){	 
	 if(q!=0){
	 	dizi[i]=dizi[i]-(2*dizi[i]);
	 	kat2=dizi[i];
	 	q=0;
	 	
	 }else
	 kat2=dizi[i];
	 
 	i++;
 	
}

else if(dizi[i]<10 && dizi[i]>=0 && i==1){
	us2=dizi[i];
	p2=BilgiAl(kat2,us2);
 	Ekle2(p2);
	i=0;
}
 }
 if(kat2!=0 && us2==0)
{
	p2=BilgiAl(kat2,us2);
 	Ekle(p2);
}
  Listele2();
 p3=Polinom_Topla(p1,p2);
 
Listele3();
gecici=ilk3;
while(gecici!=NULL){

fprintf (fp3,"%d",gecici->katsayi );
if(gecici->us!=0){
fprintf(fp3,"x");
fprintf (fp3,"%d",gecici->us );
}
gecici=gecici->sonraki;
if(gecici!=NULL&& gecici->katsayi>0)fprintf(fp3,"+");
}
}
