#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define pay 10
#include <iomanip>

/*
//структура: массив слов из 10 символов
struct words{
	char ms[pay];
}colv[50]; // пусть 50 слов

*/

int G=pay; // колво элементов

//собственная манипуляторная функция НЕ ПАРАМЕТРИЗОВАННАЯ
//для вывода
ostream &setup(ostream &stream){
	// выравнивание по правому краю
	stream.setf(ios::right);
	// ширина поля вывода в n символов
	// установка символа как заполнитель
	stream<<setw(3)<<setfill('!');
	return stream;
}

// создание двоичного-бинарного файла
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

// чтение файла
void ShowFile(char mas[pay]){
	ifstream fbin;
	fbin.open("out.bin",ios::binary);
	cout<<right<<"В двоичном файле:\n";
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

//добавление данных в конец
void AppEndFile(char mas[pay]){	
	ofstream fbout;
	fbout.open("out.bin",ios::binary|ios::app);
	cout<<"\n Элемент:\t";
	for(int j=0;j<G;j++){
		cin>>mas[j];
		fbout<<mas[j];
	}
	fbout<<endl;		
	fbout.close();
	G=G+1;
}


//Модификация - замена слова
void Modif(char mas[pay]){
	char key[pay],zam[pay];
	cout<<"\tКакое слово заменить в файле?\n";
	cout<<"\tСлово:\t";
	for(int d=0;d<pay;d++)cin>>key[d];
	cout<<"\tЧем это слово заменить?\n";
	cout<<"\tНовое слово:\t";
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



//удаление данных
void DelInfo(char mas[pay]){
	char key[pay];
	cout<<"\tВведите слово на удаление\n";
	cout<<"\tСлово:\t";
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
	cout<<"\tРабота с БИНАРНЫМ файлом\n";
	CreateFile(mas);

	do{
		cout<<"\n 0- Выход\n";
		cout<<"\t 1- Показать содержимое файла\n";
		cout<<"\t 2- Добавление в конец файла\n";
		cout<<"\t 3- Модификация файла. Замена слова\n";
		cout<<"\t 4- Удаление данных\n";
		cout<<"\tКолво записей: "<<G;
		cout<<"\n\tВыберите действие\t";
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
