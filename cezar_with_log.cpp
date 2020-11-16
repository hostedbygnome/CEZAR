#include <iostream> // необходимые библиотеки
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int text_size = 4096; // выделение буфера
	char text[4096] = {};
	bool flag1 = true;
	ofstream file;
	string path = "C:\\Users\\79991\\Desktop\\log.txt"; 
	file.open(path, fstream::in | fstream::out | fstream::app);
	do // цикл для проверки введенного сообщения на ошибку
	{
		cout << "word: ";
		cin.getline(text, text_size); // позволяет считывать строку текста
		for (int i = 0; i < strlen(text); i++)
		{
			if (!('A' <= text[i] && text[i] <= 'Z') && !('a' <= text[i] && text[i] <= 'z')) // условие
			{
				flag1 = false;
				break;
			}
			else
				flag1 = true;
		}
		if (flag1 == false)
			cout << "type error. only english" << endl; // уведомление об ошибке
	} while (flag1 == false);

	const int buffer = 80;
	char s[buffer];
	time_t t = time(0);
	strftime(s, buffer, "date %d:%m:%Y\ntime %H:%M:%S", localtime(&t));
	file << s << " | ";
	file << "user word : ";
	file << text << "\n";
	string shif_t; 
	bool flag = false;
	do // цикл для проверки введенных данных для сдвига
	{
		cout << "shift: ";
		cin >> shif_t;
		for (int i = 0; i < shif_t.length(); i++)
		{
			if (shif_t[i] > '9' || shif_t[i] < '0')
			{
				flag = false;
				break;
			}
			else
				flag = true;
		}
		if (flag == false)
		{
			cout << "type error. only numbers" << endl;
		}
	} while (flag == false);
	int shift = atoi(shif_t.c_str()); // перевод 'сдвига' ,после проверки на ошибку, в число

	while (shift > 26 || shift < 0)
	{
		cout << "shift: "; // ввод сдвига
		cin >> shift;
		if (shift > 26 || shift < 0) // условие об ошибке
			cout << "wrong shift. try again." << endl;
	}

	const int buffer1 = 80;
	char s1[buffer1];
	time_t t1 = time(0);
	strftime(s1, buffer1, "time %H:%M:%S", localtime(&t1));
	file << s1 << " | ";
	file << "user shift : ";
	file << shift << "\n";

	char decode = 0;
	while (decode != 'c' && decode != 'd') // проверка ввода на ошибку
	{
		cout << "code/decode? (c/d): "; // выбор кодирование / декодирование
		cin >> decode;
		if (decode != 'c' && decode != 'd')
			cout << "wrong char. try again." << endl; // уведомление об ошибке
	}
	if (decode == 'd') // вычисление сдвига для декодирования
		shift = 26 - shift;

	const int buffer2 = 80;
	char s2[buffer2];
	time_t t2 = time(0);
	strftime(s2, buffer2, "time %H:%M:%S", localtime(&t2));
	file << s2 << " | ";
	file << "user choice : ";
	if (decode == 'c')
	{
		file << "code" << endl;
	}
	else if (decode == 'd')
	{
		file << "decode" << endl;
	}

	for (int i = 0; text[i] != 0; i++) // расчет конечного сообщения
	{
		if ('a' <= text[i] && text[i] <= 'z')
			text[i] = (text[i] - 'a' + shift) % 26 + 'a';
		else if ('A' <= text[i] && text[i] <= 'Z')
			text[i] = (text[i] - 'A' + shift) % 26 + 'A';
	}

	if (decode == 'c') // вывод
	{
		cout << "coded: " << text << endl;
		const int buffer3 = 80;
		char s3[buffer3];
		time_t t3 = time(0);
		strftime(s3, buffer3, "time %H:%M:%S", localtime(&t3));
		file << s3 << " | ";
		file << "result : ";
		file << text << "\n";
	}
	else // вывод
	{
		cout << "decoded: " << text << endl;
		const int buffer4 = 80;
		char s4[buffer4];
		time_t t4 = time(0);
		strftime(s4, buffer4, "time %H:%M:%S", localtime(&t4));
		file << s4 << " | ";
		file << "result : ";
		file << text << "\n";
	}
	const int buffer5 = 80;
	char s5[buffer5];
	time_t t5 = time(0);
	strftime(s5, buffer5, "time %H:%M:%S", localtime(&t5));
	file << s5 << " | ";
	file << "end of program\n\n";
	file.close();
	return 0;
}
