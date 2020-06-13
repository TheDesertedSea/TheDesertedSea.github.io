#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		return 0;
	}

	vector<string> wv;
	string line;

	//打开文件
	ifstream ifs;
	ofstream ofs;
	try
	{
		ifs.open(argv[2]);
		ofs.open(argv[3], ios_base::ios_base::trunc);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	//输出文件内容
	while (getline(ifs, line))
	{
		wv.push_back(line);
	}

	vector<string> result;

	if (strcmp(argv[1],"-e")==0)
	{
		for (auto l : wv)
		{
			string temp;
			if (l.size() == 0 || l.size() == 1)
			{
				result.push_back(temp);
				continue;
			}

			auto b = l.begin(), e = l.end() - 1;
			while (b < e)
			{
				temp.push_back(*b);
				++b;
				temp.push_back(*e);
				--e;
			}
			if (b == e)
			{
				temp.push_back(*b);
			}

			result.push_back(temp);
		}

	}
	else if (strcmp(argv[1], "-d") == 0)
	{
		for (auto l : wv)
		{
			string temp;
			if (l.size() == 0 || l.size() == 1)
			{
				result.push_back(temp);
				continue;
			}

			auto b = l.begin(), e = l.end() - 1;
			if (l.size() % 2 != 0)
			{
				--e;
				while (b != l.end() - 1)
				{
					temp.push_back(*b);
					b += 2;
				}
				temp.push_back(*b);
			}
			else
			{
				while (b != l.end())
				{
					temp.push_back(*b);
					b += 2;
				}
			}

			while (e != l.begin() + 1)
			{
				temp.push_back(*e);
				e -= 2;
			}
			temp.push_back(*e);

			result.push_back(temp);
		}
	}

	/*for (auto e : result)
	{
		cout << e << endl;
	}
	*/

	for (auto e : result)
	{
		ofs << e << endl;
	}
	return 0;

}