#include <iostream>
#include <fstream>
#include <string>

std::string replace_str(std::string line, std::string s1, std::string s2)
{
	std::string temp = "";
	bool flag = false;
	int size = line.size();
	int s_size = s1.size();
	for (int i = 0; i < size; i++)
	{
		temp += line[i];
		flag = false;
		if (temp.size() >= static_cast<std::size_t>(s_size)) {
			for (int j = 0; j < s_size; j++)
			{
				if (temp[temp.size() - s_size + j] != s1[j])
					break ;
				if (j == s_size - 1)
					flag = true;
			}
		}
		if (flag == true)
		{
			temp.erase(temp.end() - s_size, temp.end());
			temp += s2;
		}
	}
	return temp;
}

int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open()) {
			std::cerr << "입력 파일을 열 수 없다." << std::endl;
			return 1;
		}

		std::string newFile(argv[1]);
		newFile += ".replace";
		std::ofstream outputFile(newFile.c_str());
		if (!outputFile.is_open()) {
			std::cerr << "출력 파일을 열 수 없다." << std::endl;
			inputFile.close();
			return 1;
		}

		std::string line;
		while (std::getline(inputFile, line)) {
			std::string temp = replace_str(line, argv[2], argv[3]);
			outputFile << temp << std::endl;
		}

		inputFile.close();
		outputFile.close();
	}
	return 0;
}
