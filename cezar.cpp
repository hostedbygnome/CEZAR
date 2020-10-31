#include <iostream> // необходимые библиотеки
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
	int text_size = 4096; // выделение буфера
	char text[4096] = {};
	bool flag1 = true;
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


	for (int i = 0; text[i] != 0; i++) // расчет конечного сообщения
	{
		if ('a' <= text[i] && text[i] <= 'z')
			text[i] = (text[i] - 'a' + shift) % 26 + 'a';
		else if ('A' <= text[i] && text[i] <= 'Z')
			text[i] = (text[i] - 'A' + shift) % 26 + 'A';
	}

	if (decode == 'c') // вывод
		cout << "coded: " << text << endl;
	else // вывод
		cout << "decoded: " << text << endl;

	return 0;
}
