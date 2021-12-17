#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define pay 10
#include <iomanip>

/*
//���������: ������ ���� �� 10 ��������
struct words{
	char ms[pay];
}colv[50]; // ����� 50 ����

*/

int G=pay; // ����� ���������

//����������� �������������� ������� �� �����������������
//��� ������
ostream &setup(ostream &stream){
	// ������������ �� ������� ����
	stream.setf(ios::right);
	// ������ ���� ������ � n ��������
	// ��������� ������� ��� �����������
	stream<<setw(3)<<setfill('!');
	return stream;
}

// �������� ���������-��������� �����
void CreateFile(char mas[pay]){
	ifstream fin;
	ofstream fbout;
	fin.open("word.txt");
	fbout.open("out.bin",ios::binary);
	for (int i = 0; i < G; i++) {
		for (int j = 0; j < pay; j++) {
			fin>>mas[j];
			fbout<<mas[j];
		}
		fbout<<endl;
	}
	fbout.close();
	fin.close();
}

// ������ �����
void ShowFile(char mas[pay]){
	ifstream fbin;
	fbin.open("out.bin",ios::binary);
	cout<<right<<"� �������� �����:\n";
	for (int i = 0; i < G; i++) {
		cout<<setup;
		for (int j = 0; j < pay; j++) {
			fbin>>mas[j];
			cout<<mas[j];
		}
		cout<<endl;
	}
	fbin.close();
}

//���������� ������ � �����
void AppEndFile(char mas[pay]){	
	ofstream fbout;
	fbout.open("out.bin",ios::binary|ios::app);
	cout<<"\n �������:\t";
	for(int j=0;j<G;j++){
		cin>>mas[j];
		fbout<<mas[j];
	}
	fbout<<endl;		
	fbout.close();
	G=G+1;
}


//����������� - ������ �����
void Modif(char mas[pay]){
	char key[pay],zam[pay];
	cout<<"\t����� ����� �������� � �����?\n";
	cout<<"\t�����:\t";
	for(int d=0;d<pay;d++)cin>>key[d];
	cout<<"\t��� ��� ����� ��������?\n";
	cout<<"\t����� �����:\t";
	for(int d=0;d<pay;d++)cin>>zam[d];	
	ifstream fbin;
	ofstream vrem;
	vrem.open("vrem.bin",ios::binary);
	fbin.open("out.bin",ios::binary);
	for(int i=0;i<G;i++){
		for(int j=0;j<pay;j++){
			fbin>>mas[j];
			//vrem<<mas[j];
			if(mas[j]==key[j])mas[j]=zam[j];
			vrem<<mas[j];
			//if(zam[j]==mas[j])cout<<mas[j];
			
			
		}
		vrem<<endl;
	}
	vrem.close();
	fbin.close();
	remove("out.bin");
	rename("vrem.bin","out.bin");
}



//�������� ������
void DelInfo(char mas[pay]){
	char key[pay];
	cout<<"\t������� ����� �� ��������\n";
	cout<<"\t�����:\t";
	for(int d=0;d<pay;d++)cin>>key[d];
	ifstream fbin;
	ofstream vrem;
	vrem.open("vrem.bin",ios::binary);
	fbin.open("out.bin",ios::binary);
	for(int i=0;i<G;i++){
		for(int j=0;j<pay;j++){
			fbin>>mas[j];
			if(key[j]!=mas[j])vrem<<mas[j];
		}
		vrem<<endl;
	}
	vrem.close();
	fbin.close();
	G=G-1;
	remove("out.bin");
	rename("vrem.bin","out.bin");
}


int main() {
	setlocale(LC_ALL, "Russian");
	
	char mas[pay];
	int count,ch;
	cout<<"\t������ � �������� ������\n";
	CreateFile(mas);

	do{
		cout<<"\n 0- �����\n";
		cout<<"\t 1- �������� ���������� �����\n";
		cout<<"\t 2- ���������� � ����� �����\n";
		cout<<"\t 3- ����������� �����. ������ �����\n";
		cout<<"\t 4- �������� ������\n";
		cout<<"\t����� �������: "<<G;
		cout<<"\n\t�������� ��������\t";
		cin>>ch;
		
		switch(ch){
			case 1:{ShowFile(mas); break;}
			case 2:{AppEndFile(mas); break;}
			case 3:{Modif(mas); break;}
			case 4:{DelInfo(mas); break;}
		}
		
	}while(ch!=0);
	

	return 0;
}