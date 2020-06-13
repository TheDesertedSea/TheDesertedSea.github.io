---
layout: default
---

## 自己写的一个txt文本加密小程序
2020/6/13

使用的是栅格加密法

使用方法：

将file1加密存于file2:
jiiemii -e file1 fil2

将file1解密存于file2:
jiiemii -e file1 fil2

```c++
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

	vector<string> wv,result;
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

	//读取文件内容，以行为单位
	while (getline(ifs, line))
	{
		wv.push_back(line);
	}

	if (strcmp(argv[1],"-e")==0)
	{//加密，创建两个迭代器分别从头和从尾，同时遍历目标行的string,头放一个字符到结果string，尾放一个在后面，依次进行
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
				//头放一个
				temp.push_back(*b);
				++b;
				//尾放一个
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
	{//解密，创建两个迭代器分别从头和从尾，遍历目标行的string，头只遍历奇数位置，尾只遍历偶数位置，
		//先让头遍历到的字符全部放入结果string，再让尾遍历到的字符放入其后
		for (auto l : wv)
		{
			string temp;
			if (l.size() == 0 || l.size() == 1)
			{
				result.push_back(temp);
				continue;
			}

			auto b = l.begin(), e = l.end() - 1;

			//先让头遍历完奇数位置
			if (l.size() % 2 != 0)
			{  //奇数长度需让尾对齐偶数位置
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

			//再让尾遍历完偶数位置
			while (e != l.begin() + 1)
			{
				temp.push_back(*e);
				e -= 2;
			}
			temp.push_back(*e);

			//存储该行信息
			result.push_back(temp);
		}
	}

	//输出最终结果到存储文件
	for (auto e : result)
	{
		ofs << e << endl;
	}
	return 0;

}

```

[back](../index.html)