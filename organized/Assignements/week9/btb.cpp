#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
	vector<int> vec;
	int t;
	cin >> t;
	while (t--)
	{

		long long int n, q, previous = 0, mode = 0;
		cin >> n >> q;
		int num, x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			vec.push_back(num);
		}
		while (q--)
		{
			cin >> x;
			if (x == 1)
			{
				cin >> y;
				vec.push_back(y);
			}
			else if (x == 2)
				cout << floor(accumulate(vec.begin(), vec.end(), 0.0) / vec.size()) << endl;
			else if (x == 3)
			{
				for (int i = 0; i < vec.size(); i++)
				{
					int frequency = 0;
					for (int j = 0; j < vec.size(); j++)
					{
						if (vec[i] == vec[j])
							frequency++;
					}
					if (frequency > previous)
					{
						mode = vec[i];
						previous = frequency;
					}
				}
				cout << mode << endl;
			}
		}
	}
	return 0;
}