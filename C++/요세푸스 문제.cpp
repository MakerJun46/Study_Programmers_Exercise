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

	}

}