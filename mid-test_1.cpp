/*
Nama			: Salma Alifia Shafira
NPM				: 140810180058
Tanggal Buat	: 24 April 2019
Deskripsi		: Singly Linked List
Soal			: UTS Struktur Data 2019
*/

#include <iostream>
using namespace std;

struct ElemtList{
	int nopesanan;
	char nama[30];
	int jumlah;
	int harga;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}

void createElemt(pointer& pBaru){
    pBaru=new ElemtList;
    cout << "No 		: ";cin >>pBaru->nopesanan;
    cout << "Nama Makanan    : ";cin >>pBaru->nama;
    cout << "Jumlah		: "; cin >>pBaru->jumlah;
    cout << "Harga Makanan	: ";cin >>pBaru->harga;
 pBaru->next=NULL;
}
void insertFirst(List& First, pointer pBaru){
    if(First==NULL)
  First=pBaru;
  else{
   pBaru->next=First;
   First=pBaru;
  }
}

void traversal(List First){
    pointer pBantu;
 pBantu=First;
 cout << "No \t"<< "Nama Makanan\t"<< "Jumlah\t"<<"Harga Makanan\t"<<endl;
 while(pBantu != NULL){
        cout <<pBantu->nopesanan<<"\t"<<pBantu->nama<<"\t\t"<<pBantu->jumlah<<"\t"<<pBantu->harga<<endl;
  pBantu=pBantu->next;
 }
}

void deleteFirst(List& First, pointer& pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void insertLast(List& First, pointer pBaru){

    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
    }
    last->next=pBaru;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    cout << "Delete last"<<endl;
    if (First==NULL){
        pHapus=NULL;
        cout << "List Kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        precLast=NULL;
        while(last->next !=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}
void insertAfter(List& First,pointer pCari,pointer pBaru){
    if (pCari->next==NULL)
        pCari->next=pBaru;
    else {
        pBaru->next=pCari->next;
        pCari->next=pBaru;
    }
}

void linearSearch(List First,int key, int& found, pointer& pCari){
    found=0;
    pCari=First;
    while (found==0 && pCari!=NULL) {
        if (pCari->nopesanan==key)
            found=1;
        else
        pCari=pCari->next;
        }

}

void update(List& First, int key) {
  pointer pToUpdate = NULL;
  cout << "Nama: "; cin >> pToUpdate->harga;
  cout << endl;
}

void sortin(List& First){
  int count = 0, i;
  pointer start,curr,trail,temp;
  start=First;
  curr=NULL;
  trail=NULL;
  temp=NULL;

  while(start != NULL) {
    count++;
    start = start->next;
  }

  for(i = 0; i<count; ++i) {

    curr = trail = First;

    while (curr->next != NULL) {
      if (curr->nopesanan > curr->next->nopesanan) {

        temp = curr->next;
        curr->next = curr->next->next;
        temp->next = curr;

        if(curr == First)
          First = trail = temp;
        else
          trail->next = temp;
        curr = temp;
      }
      trail = curr;
      curr = curr->next;
    }
  }
}

int main()
{
    pointer p,pCari;
    List m;
    int ketemu;
    int kunci;
    int pilih;

    createList(m);
    while(1){
        system("cls");
        cout<<"Menu Restoran LALALALA"<<endl;
        cout<<"1. Masukkan Pesanan "<<endl;
        cout<<"2. Update Jumlah Pesanan"<<endl;
        cout<<"3. Tampilkan"<<endl;
        cout<<"4. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElemt(p);
            insertFirst(m, p);
            sortin(m);
        break;

        case 2:
            cout<<"\nMasukkan No Pesanan : "; cin>>kunci;
            linearSearch(m,kunci,ketemu,pCari);
            if (ketemu){
                cout<<"Ditemukan yang dicari "<<endl;
                update(m,kunci);
            }
            else {
                cout<<" Tidak Ditemukan yang dicari "<<endl;
            }
        break;

        case 3:
            traversal(m);
        break;

        case 4:
            return 0;
            break;
        }
        system("pause");
    }

    return 0;
}
