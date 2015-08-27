#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{ 
	ifstream file("32bit.asm");
	ofstream file2("convert_64bit.asm");
	string a;
	if(file.is_open())
	{ 
		while(getline(file, a))
		{ 
			const char *x = a.c_str();
			if(strcmp(x, "text db \"Hello World\", 0xa")==0)
				file2 << "text: db \"Hello World\", 0xa" << "\n";
			else if(strcmp(x, "length equ $-text")==0)
				file2 << "length: equ $-text" << "\n";
			else if(strcmp(x, "mov eax, 4")==0)
				file2 << "\tmov\t rax, 1" << "\n";
			else if(strcmp(x, "mov ebx, 1")==0)
				file2 << "\tmov\t rcx, 1" << "\n";
			else if(strcmp(x, "mov edx, length")==0)
				file2 << "\tmov\t rbp, length" << "\n";
			else if(strcmp(x, "mov ecx, text")==0)
				file2 << "\tmov\t rsp, text" << "\n";
			else if(strcmp(x, "int 80h")==0)
				file2 << "\tsyscall" << "\n";
			else if(strcmp(x, "mov ebx, 0")==0)
				file2 << "\tmov\t rcx, 0" << "\n";
			else if(strcmp(x, "mov eax, 1")==0)
				file2 << "\tmov\t rax, 60" << "\n";
			else
				file2 << x << "\n";
		}
		file.close();
		file2.close();
	}
	else
		cout<<"Unable to open file!"<<endl;
	return 0;
}

