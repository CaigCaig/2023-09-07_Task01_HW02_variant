#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <variant>

using namespace std;

variant<int, string, vector<int>> get_variant() {
	srand(time(nullptr));
	int random_variable = rand() % 3;

	variant<int, string, vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	variant<int, string, vector<int>> val;

	val = get_variant();

	if (holds_alternative<int>(val))
	{
		cout << get<int>(val) * 2;
	}
	else if (holds_alternative<string>(val))
	{
		cout << get<string>(val);
	}
	else if (holds_alternative<vector<int>>(val))
	{
		for (auto& i : get<vector<int>>(val))
		{
			cout << i << ' ';
		}
	}

	cout << endl;
	system("pause");
}