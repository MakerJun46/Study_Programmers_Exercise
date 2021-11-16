#include <iostream>
#include <list>

using namespace std;

void main()
{
	int n, k;

	cin >> n >> k;

	list<int> list_numbers;
	list<int>::iterator it = list_numbers.begin();

	for (int i = 1; i <= n; i++)
	{
		list_numbers.push_back(i);
	}

	while (!list_numbers.empty())
	{
		for (int i = 0; i < k; i++)
		{
			if (it == list_numbers.end())
				it = list_numbers.begin();
			it++;
		}
		cout << *it << endl;

		auto tmp = it;

		if (tmp++ == list_numbers.end())
		{
			it--;
		}
		else
		{
			it++;
		}
		list_numbers.erase(tmp);
	}
}