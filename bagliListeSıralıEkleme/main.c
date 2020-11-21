#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//kitap kaydedilecek basım yılına göre küçükten büyüğe olacak şekilde

typedef struct n{
char yazar[20];
char kitapAdi[20];
int basimYili;
int isbn;
struct n *next;
}node;

node * kitapEkle(node * liste,char kitapAdi[20],char yazar[20],int isbn,int basimYili){
if(liste == NULL){
    liste = (node *)malloc(sizeof(node));
    strcpy(liste->kitapAdi,kitapAdi);
    strcpy(liste->yazar,yazar);
    liste->basimYili = basimYili;
    liste->isbn = isbn;
    liste->next = NULL;
    return liste;
}

node * temp = (node *)malloc(sizeof(node));
strcpy(temp->yazar,yazar);
strcpy(temp->kitapAdi,kitapAdi);
temp->basimYili = basimYili;
temp->isbn = isbn;


// eklenen kitabın basım yılı listenin başındaki kitabın basım yılından eski ise (en başa eklenmesi gerekiyor ise)

if(liste->basimYili> temp->basimYili){
    temp->next = liste;
    return temp;
}

node * iter = liste;
while(temp->basimYili>iter->basimYili && iter->next != NULL)
    iter = iter->next;
node * temp2 = iter->next;
iter->next = temp;
temp->next = temp2;
return liste;
}


void listele(node * liste){
node * iter = liste;
while(iter->next != NULL){
    printf("\n Basim Yili : %d \n ISBN : %d \n Kitap Adi : %s \n Yazar Adi : %s \n ",iter->basimYili,iter->isbn,iter->kitapAdi,iter->yazar);
    iter  = iter->next;
}
printf("\n Basim Yili : %d \n ISBN : %d \n Kitap Adi : %s \n Yazar Adi : %s \n ",iter->basimYili,iter->isbn,iter->kitapAdi,iter->yazar);
}

void kitapBul(node * liste,int isbn){
node * iter = liste;
while(iter->next != NULL)
{
    if(iter->isbn == isbn){
    printf("\n Basim Yili : %d \n ISBN : %d \n Kitap Adi : %s \n Yazar Adi : %s \n ",iter->basimYili,iter->isbn,iter->kitapAdi,iter->yazar);
}
iter = iter->next;
}
}

node * kitapSil(node * liste,int isbn){
//listenin başından mı sileceğimi kontrol ediyorum
if(liste->isbn == isbn){
    node * temp = liste->next;
    free(liste);
    return temp;
}

node * iter = liste;

while(iter->next != NULL){
    if(iter->next->isbn == isbn){
        node * temp = iter->next->next;
        free(iter->next);
        iter->next = temp;
        return liste;
    }
    iter = iter->next;
}

// en sondaki kitabı kontrol ediyorum
if(iter->isbn == isbn){
    free(iter);
    return liste;
}

}

int main()
{
    node * liste = NULL;
    liste = kitapEkle(liste,"sucveceza","dostoyevski",1,1860);
    liste = kitapEkle(liste,"savasvebaris","tolstoy",2,1870);
    liste = kitapEkle(liste,"kasagi","omerseyfettin",3,1360);
    liste = kitapEkle(liste,"godhatesusall","mody",4,1260);
    listele(liste);
    printf("\n");
    kitapBul(liste,3);
    printf("Kitap Bulundu \n");
    kitapSil(liste,3);
    printf("\n Kitap silindi \n");
    listele(liste);
    return 0;
}
