#include <string>
#include <cctype>
#include <clocale>
#include <Windows.h>
#include <array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

int findIndex(vector <string> a, string b)
{
	int i;
	for (i = 0; i != a.size(); i++)
	{
		if (a[i] == b)
			return i;
	}
	i = -1;
	return i;

}

bool compare(const string& left, const string& right)
{
	string num1, num2;
	float nom1, nom2;
	int i = 0;


	while (left[i] != '-')
	{
		num1 += left[i];
		i += 1;
	}

	i = 0;

	while (right[i] != '-')
	{
		num2 += right[i];
		i += 1;
	}

	nom1 = stof(num1);
	nom2 = stof(num2);



	return nom1 > nom2;
}

bool compare_surname(const string& left, const string& right)
{
	string surname1, surname2;
	int i = 0;


	while (left[i] != ':')
	{
		surname1 += left[i];
		i += 1;
	}

	i = 0;

	while (right[i] != ':')
	{
		surname2 += right[i];
		i += 1;
	}


	return surname1 > surname2;
}

bool compare_subj1(const string& left, const string& right)
{
	string subj1, subj2;
	int i = 0;
	i = left.find(':') + 2;
	while (left[i] != ' ' or left[i + 1] != '-')
	{
		subj1 += left[i];
		i += 1;
	}

	i = right.find(':') + 2;

	while (right[i] != ' ' or right[i + 1] != '-')
	{
		subj2 += right[i];
		i += 1;
	}
	return subj1 > subj2;
}

bool compare_subj2(const string& left, const string& right)
{
	string subj1, subj2;
	int i = 0;
	i = left.find(',') + 2;
	while (left[i] != ' ' and left[i + 1] != '-')
	{
		subj1 += left[i];
		i += 1;
	}

	i = right.find(',') + 2;

	while (right[i] != ' ' and right[i + 1] != '-')
	{
		subj2 += right[i];
		i += 1;
	}
	return subj1 > subj2;
}

bool compare_subj3(const string& left, const string& right)
{
	string subj1, subj2;
	string left1 = left, right1 = right;
	int i = 0;
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 2);
	cout << left1 << endl;
	while (left1[i] != ' ' and left1[i + 1] != '-')
	{
		subj1 += left1[i];
		i += 1;
	}

	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 2);
	cout << right1 << endl;
	i = 0;
	while (right1[i] != ' ' and right1[i + 1] != '-')
	{
		subj2 += right1[i];
		i += 1;
	}
	return subj1 > subj2;
}

bool compare_subj4(const string& left, const string& right)
{
	string subj1, subj2;
	string left1 = left, right1 = right;
	int i = 0;
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 2);
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 2);
	cout << left1 << endl;
	while (left1[i] != '.')
	{
		subj1 += left1[i];
		i += 1;
	}

	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 2);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 2);
	cout << right1 << endl;
	i = 0;
	while (right1[i] != '.')
	{
		subj2 += right1[i];
		i += 1;
	}
	return subj1 > subj2;
}

bool compare_mark1(const string& left, const string& right)
{
	string mark1, mark2;
	int i = 0;
	while (left[i] != ',')
	{
		if (isdigit(left[i]) != 0 and left[i - 2] == '-')
		{
			mark1 = left[i];
			break;

		}
		i += 1;
	}
	i = 0;
	while (right[i] != ',')
	{
		if (isdigit(right[i]) != 0 and right[i - 2] == '-')
		{
			mark2 = right[i];
			break;
		}
		i += 1;
	}
	return mark1 > mark2;
}

bool compare_mark2(const string& left, const string& right)
{
	string mark1, mark2;
	string left1 = left, right1 = right;
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	int i = 0;
	while (left1[i] != ',')
	{
		if (isdigit(left1[i]) != 0 and left1[i - 2] == '-')
		{
			mark1 = left1[i];
			break;

		}
		i += 1;
	}
	i = 0;
	while (right1[i] != ',')
	{
		if (isdigit(right1[i]) != 0 and right1[i - 2] == '-')
		{
			mark2 = right1[i];
			break;
		}
		i += 1;
	}
	return mark1 > mark2;
}

bool compare_mark3(const string& left, const string& right)
{
	string mark1, mark2;
	string left1 = left, right1 = right;
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	int i = 0;
	while (left1[i] != ',')
	{
		if (isdigit(left1[i]) != 0 and left1[i - 2] == '-')
		{
			mark1 = left1[i];
			break;

		}
		i += 1;
	}
	i = 0;
	while (right1[i] != ',')
	{
		if (isdigit(right1[i]) != 0 and right1[i - 2] == '-')
		{
			mark2 = right1[i];
			break;
		}
		i += 1;
	}
	return mark1 > mark2;
}

bool compare_mark4(const string& left, const string& right)
{
	string mark1, mark2;
	string left1 = left, right1 = right;
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	left1.erase(left1.begin() + 0, left1.begin() + left1.find(',') + 1);
	right1.erase(right1.begin() + 0, right1.begin() + right1.find(',') + 1);
	int i = 0;
	while (left1[i] != ',')
	{
		if (isdigit(left1[i]) != 0 and left1[i - 2] == '-')
		{
			mark1 = left1[i];
			break;

		}
		i += 1;
	}
	i = 0;
	while (right1[i] != ',')
	{
		if (isdigit(right1[i]) != 0 and right1[i - 2] == '-')
		{
			mark2 = right1[i];
			break;
		}
		i += 1;
	}
	return mark1 > mark2;
}

bool check_for_numbers_in_surname(string a)
{
	for (int i = 0; i != a.length(); i++)
	{
		if (isdigit(a[i]) != 0)
			return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int answ1;
	string answ2;
	string st, name, name_of_subj, filename;
	vector <string> average_value;
	vector <string> all_st;
	vector <string> all_st1;
	bool er = 0;
	do
	{
		cout << "Меню" << endl;
		cout << "Введите номер пункта, который вы хотите выполнить" << endl;
		cout << "1. Произвести ввод данных для формирования файлов" << endl;
		cout << "2. Обновить (Добавить/удалить) входные данные записанные в файл (Формируемые файлы также обновятся)" << endl;
		cout << "3. Выполнить сортировку в файле с вводимым именем" << endl;
		cout << "4. Завершить программу" << endl << endl;
		cout << ">";
		cin >> answ1;
		cout << endl;
		system("cls");
		if (answ1 == 1)
		{
			do
			{
				cout << "Использовать ввод с клавиатуры (0) или из файла (1)?" << endl << endl << ">";
				cin >> answ2;
				cout << endl;
				filename = name + ".txt";
				if (answ2 == "0")
				{
					cout << "Введите название файла в который будут записаны исходные данные ('-' для имени по умолчанию):" << endl << endl;
					cout << ">";
					cin >> name;
					if (name == "-")
					{
						name = "Default Name №" + to_string(rand()) + to_string(rand()) + to_string(rand());
						cout << "Было выбрано имя по умолчанию: " << name << endl << endl;
					}
					filename = name + ".txt";
					ofstream out0(filename);
					string infos, OZU1[4], OZU2[4];
					getline(cin, infos);
					do
					{
						string string_for_file;
						cout << "Введите фамилию студента" << endl << endl << ">"; // у них не должно быть ничего лишнего?
						do
						{
							getline(cin, infos);
							if (check_for_numbers_in_surname(infos) == 1)
							{
								cout << endl << "Фамилия не должна содержать цифр! Повторите Ввод" << endl << endl << ">";
							}
						} while (check_for_numbers_in_surname(infos) == 1);

						cout << endl;
						if (infos == "-")
						{
							break;
						}
						string_for_file += infos;
						string_for_file += ": ";
						cout << "Введите экзамен и оценку через дефис, каждые на новой строке (Пример: История-5)" << endl << endl;
						for (int i5 = 0; i5 != 4; i5++)
						{
							cout << i5 + 1 << ">";
							infos.clear();
							getline(cin, infos);

							OZU1[i5] = infos[infos.find('-') + 1];
							infos.erase(infos.find('-'));
							OZU2[i5] = infos;
						}

						string_for_file = string_for_file + OZU2[0] + " - " + OZU1[0] + ", ";
						string_for_file = string_for_file + OZU2[1] + " - " + OZU1[1] + ", ";
						string_for_file = string_for_file + OZU2[2] + " - " + OZU1[2] + ", ";
						string_for_file = string_for_file + OZU2[3] + " - " + OZU1[3] + ".";

						out0 << string_for_file << endl;
						cout << endl << "(Введите '-' для завершения ввода)" << endl;
					} while (infos != "-");
					out0.close();
					ifstream in(filename);

				}
				else if (answ2 == "1")
				{
					bool err = 0;
					cout << "Введите название файла из которого будут взяты исходные данные (Готовый файл по умолчанию 'Список'):" << endl << endl;
					cout << ">";
					cin >> name;
					filename = name + ".txt";
					ifstream in(filename);
					err = in.is_open();
					while (err != 1)
					{
						cout << endl;
						cerr << "Ошибка открытия файла: " << filename << endl << "Повторите ввод названия" << endl << endl << ">";
						name.clear();
						in.close();
						cin >> name;
						filename = name + ".txt";
						ifstream in(filename);
						err = in.is_open();
					}
					cout << endl;
					cout << "Содержимое файла " << filename << endl << endl;
					ifstream show2(filename);
					while (getline(show2, st))
					{
						cout << st << endl;
					}

				}
				else
				{
					er = 1;
					cout << "Ошибка, повторите ввод!" << endl << endl << ">";
				}

			} while (er == 1);

			vector <string> subjects;
			ifstream in(filename);
			while (getline(in, st))
			{
				int i2 = st.find(':') + 2;
				int num_subj = 0;
				string subject;
				do
				{
					while (st[i2] != '-')
					{
						subject += st[i2];
						i2 += 1;
					}
					subject.erase(subject.length() - 1, 1);
					i2 += 5;
					subjects.push_back(subject);
					num_subj += 1;
					subject = "";
				} while (num_subj != 4);
			}

			sort(subjects.begin(), subjects.end());
			auto it = unique(subjects.begin(), subjects.end());
			subjects.erase(it, subjects.end());
			cout << endl;
			cout << "Наименования экзаменов: ";
			for (int i9 = 0; i9 != subjects.size(); i9++)
			{
				cout << subjects[i9];
				if (i9 != subjects.size() - 1)
					cout << ", ";
				else
					cout << ".";
			}



			cout << endl << "Введите название дисциплины, для второго файла" << endl << endl << ">";
			getline(cin, name_of_subj);
			getline(cin, name_of_subj);
			cout << endl << endl;

		}
		else if (answ1 == 2)
		{
			int num_of_str = 0;
			string st1;
			cout << "Введите название файла для удаления/добавления данных" << endl << endl << ">";
			cin >> name;
			cout << endl << endl << "Данные из файла с номерами строк:" << endl;
			filename = name + ".txt";
			ifstream show(filename);
			while (getline(show, st1))
			{
				cout << num_of_str << " > " << st1 << endl;
				num_of_str += 1;
				all_st1.push_back(st1);
			}
			int answ3;
			cout << endl << "Удалить (0) или добавить данные (1)?" << endl << endl << ">";
			cin >> answ3;
			cout << endl;
			if (answ3 == 0)
			{
				int num_str;
				cout << "Какую строку удалить?" << endl << endl << ">";
				cin >> num_str;
				cout << endl;
				all_st1.erase(all_st1.begin() + num_str);
				getline(cin, name_of_subj);
			}
			else
			{
				cout << "Данные для добавления:" << endl << endl << ">";
				string infos = "", string_for_file, OZU1[4], OZU2[4];
				getline(cin, infos);
				do
				{

					cout << "Введите фамилию студента" << endl << endl << ">";

					do
					{
						getline(cin, infos);
						if (check_for_numbers_in_surname(infos) == 1)
						{
							cout << endl << "Фамилия не должна содержать цифр! Повторите Ввод" << endl << endl << ">";
						}
					} while (check_for_numbers_in_surname(infos) == 1);
					cout << endl;
					if (infos == "-")
					{
						break;
					}
					string_for_file = "";
					string_for_file += infos;
					string_for_file += ": ";
					cout << "Введите экзамен и оценку через дефис, каждые на новой строке (Пример: История-5)" << endl << endl;
					for (int i5 = 0; i5 != 4; i5++)
					{
						cout << i5 + 1 << ">";
						infos.clear();
						getline(cin, infos);

						OZU1[i5] = infos[infos.find('-') + 1];
						infos.erase(infos.find('-'));
						OZU2[i5] = infos;
					}

					string_for_file = string_for_file + OZU2[0] + " - " + OZU1[0] + ", ";
					string_for_file = string_for_file + OZU2[1] + " - " + OZU1[1] + ", ";
					string_for_file = string_for_file + OZU2[2] + " - " + OZU1[2] + ", ";
					string_for_file = string_for_file + OZU2[3] + " - " + OZU1[3] + ".";
					all_st1.push_back(string_for_file);
					string_for_file += "\n";
					cout << endl << "(Введите '-' для завершения ввода)" << endl;
				} while (infos != "-");
			}
			show.close();
			ofstream changed_file(filename);
			for (int i7 = 0; i7 != all_st1.size(); i7++)
			{
				changed_file << all_st1[i7] << endl;
			}
			cout << endl << "Введите название дисциплины, для второго файла" << endl << endl << ">";
			getline(cin, name_of_subj);
			cout << endl << endl;
		}
		else if (answ1 == 3)
		{
			cout << "Введите название файла для сортировки данных" << endl << endl << ">";
			cin >> name;
			filename = name + ".txt";
			ifstream sorta(filename);
			vector <string> all_st_for_sort;

			cout << "Содержимое файла: " << endl << endl;
			while (getline(sorta, st))
			{
				all_st_for_sort.push_back(st);
				cout << st << endl;
			}
			system("cls");
			cout << endl << endl;
			int answ5;
			cout << "Отсортировать по:" << endl;
			cout << "1. Фамилии по убыванию (по алфавиту)" << endl;
			cout << "2. Фамилии по возрастанию (по алфавиту)" << endl << endl;

			cout << "3. 1-ый предмет по убыванию (по алфавиту)" << endl;
			cout << "4. 1-ый предмет по возрастанию (по алфавиту)" << endl << endl;

			cout << "5. 2-ый предмет по убыванию (по алфавиту)" << endl;
			cout << "6. 2-ый предмет по возрастанию (по алфавиту)" << endl << endl;

			cout << "7. 3-ый предмет по убыванию (по алфавиту)" << endl;
			cout << "8. 3-ый предмет по возрастанию (по алфавиту)" << endl << endl;

			cout << "9. 4-ый предмет по убыванию (по алфавиту)" << endl;
			cout << "10. 4-ый предмет по возрастанию (по алфавиту)" << endl << endl;

			cout << "11. 1-ая оценка по убыванию" << endl;
			cout << "12. 1-ая оценка по возрастанию" << endl << endl;

			cout << "13. 2-ая оценка по убыванию" << endl;
			cout << "14. 2-ая оценка по возрастанию" << endl << endl;

			cout << "15. 3-ая оценка по убыванию" << endl;
			cout << "16. 3-ая оценка по возрастанию" << endl << endl;

			cout << "17. 4-ая оценка по убыванию" << endl;
			cout << "18. 4-ая оценка по возрастанию" << endl << endl;

			cout << "Выберите один из пунктов " << endl << ">";
			cin >> answ5;
			cout << endl;
			if (answ5 == 1 or answ5 == 2)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_surname); //От Я до А
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 3 or answ5 == 4)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_subj1);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 5 or answ5 == 6)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_subj2);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 7 or answ5 == 8)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_subj3);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 9 or answ5 == 10)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_subj4);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 11 or answ5 == 12)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_mark1);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 13 or answ5 == 14)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_mark2);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 15 or answ5 == 16)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_mark3);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			if (answ5 == 17 or answ5 == 18)
			{
				sort(begin(all_st_for_sort), end(all_st_for_sort), compare_mark4);
				if (answ5 == 2)
					reverse(all_st_for_sort.begin(), all_st_for_sort.end());
			}
			ofstream sorted(filename);
			cout << "Содержимое после сортировки: " << endl << endl;
			for (int i9 = 0; i9 != all_st_for_sort.size(); i9++)
			{
				sorted << all_st_for_sort[i9] << endl;
				cout << all_st_for_sort[i9] << endl;
			}
			cout << endl << endl;
		}
		else
		{
			break;
		}
		if (answ1 == 1 or answ1 == 2)
		{
			bool Er = 0;
			ifstream in(filename);
			string filename1 = "List_with_4_5.txt", filename2 = "List_with_5_of_entered_name.txt", filename3 = "List_with_average_value_sort.txt";
			int f1 = 0;
			int answ7;
			string name123;
			do
			{
				cout << "Сменить имена формируемых файлов 1, 2, 3 (изменить имя файла 1, 2, 3 соотвественно)" << endl;
				cout << "или продолжить (4)" << endl << endl << ">";
				cin >> answ7;
				if (answ7 == 1)
				{
					cout << endl << "Новое имя для " << answ7 << " файла" << endl << endl << ">";
					cin >> name123;
					filename1 = name123 + ".txt";
				}
				if (answ7 == 2)
				{
					cout << "Новое имя для " << answ7 << " файла" << endl << endl << ">";
					cin >> name123;
					filename2 = name123 + ".txt";
				}
				if (answ7 == 3)
				{
					cout << "Новое имя для " << answ7 << " файла" << endl << endl << ">";
					cin >> name123;
					filename3 = name123 + ".txt";
				}
				name123.clear();
				cout << endl;
			} while (answ7 != 4);
			ofstream out(filename1);
			ofstream out2(filename2);
			ofstream out3(filename3);
			average_value.clear();
			while (getline(in, st))
			{
				vector <string> subjects;
				all_st.push_back(st);
				string last_name;
				vector <int> marks;
				vector <string> surname;
				bool flag = true;
				int i = 0;
				do
				{
					last_name += st[i];
					i += 1;
				} while (st[i] != ':');

				surname.push_back(last_name); //поиск фамилии

				for (i = 0; i != st.length(); i++)
				{
					if (isdigit(st[i]) != 0 and st[i - 2] == '-')
					{
						marks.push_back((int)st[i] - 48);  //поиск оценок
						if (((int)st[i] - 48) < 4)
						{
							flag = false; //флаг хорошиста
						}
					}
				}
				int i2 = st.find(':') + 2;
				int num_subj = 0;
				string subject;
				do
				{
					while (st[i2] != '-')
					{
						subject += st[i2];
						i2 += 1;
					}
					subject.erase(subject.length() - 1, 1);
					i2 += 5;
					subjects.push_back(subject);  //поиск названия дисциплины
					num_subj += 1;
					subject = "";
				} while (num_subj != 4);

				if (flag == true)
				{
					out << st << endl; //Запись в файл хорошистов
				}
				if (findIndex(subjects, name_of_subj) != -1 and marks[findIndex(subjects, name_of_subj)] == 5) //Запись в отличники по дисциплине с клавы
				{
					out2 << st << endl;
				}
				float sum = 0.0;
				for (int i = 0; i != marks.size(); i++)
				{
					sum += marks[i];
				}
				average_value.push_back(to_string(sum / marks.size()) + "-" + to_string(f1));   // поиск среднего значения оценок
				f1 += 1;
				sort(begin(average_value), end(average_value), compare);

				st.clear();

			}
			string av_val;
			for (int i = 0; i != average_value.size(); i++)
			{
				av_val = average_value[i];
				int a = average_value[i].length() - 1;
				out3 << all_st[int(av_val[a]) - 48] << "  Ср. знач. - ";
				av_val.erase(av_val.size() - 2);
				out3 << av_val << endl;
			}
			out.close();
			out2.close();
			out3.close();
			ifstream vivod1(filename1);
			ifstream vivod2(filename2);
			ifstream vivod3(filename3);
			cout << "Содержимое файла " << filename1 << endl;
			while (getline(vivod1, st))
			{
				cout << st << endl;
			}

			cout << endl << endl;
			cout << "Содержимое файла " << filename2 << endl;
			while (getline(vivod2, st))
			{
				cout << st << endl;
			}

			cout << endl << endl;
			cout << "Содержимое файла " << filename3 << endl;
			while (getline(vivod3, st))
			{
				cout << st << endl;
			}
			cout << endl << endl;
		}
	} while (true);
}
