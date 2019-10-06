// Crypto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>
#include <wincrypt.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
//#pragma comment(lib,"crypt32.dll") 

using namespace std;


int main()
{

	setlocale(LC_ALL, "RUS");
	HCRYPTPROV hProv; // Дескриптор криптопровайдера

	LPTSTR pszName;

	DWORD dwType;

	DWORD cbName;

	DWORD dwIndex = 0;

	printf("\n Список доступных типов провайдеров.\n");

	printf("Тип  Имя типа провайдера.\n");

	printf("____ ________________________________\n");

	// Цикл перечисления типов криптопровайдеров.

	dwIndex = 0;


	struct Some {
		char* name;
		DWORD type;
	};

	vector<Some> list1;

	while (CryptEnumProviderTypes(dwIndex, NULL, 0, &dwType, NULL, &cbName))
	{
		pszName = (LPTSTR)LocalAlloc(LMEM_ZEROINIT, cbName);
		
		CryptEnumProviderTypes(dwIndex++, NULL, NULL, &dwType, pszName, &cbName);
		
		Some s;
		s.name = (char*)pszName;
		s.type = dwType;

		cout << reinterpret_cast<const char*>(pszName);

		list1.push_back(s);

		printf("%4.0d %s\n", dwType, pszName);

	}
	
	/*cout << "Пробежка по циклу" << endl;

	for (Some n : list1) {
		cout << "Имя: " << (char*)n.name <<" Тип: " << n.type << endl;

	}*/



	system("pause");
}