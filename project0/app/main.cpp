// Binh Nguyen - binhnn1 - 34707912

#include <iostream>

std::string repeat(std::string word, int n)
{
	std::string result;
	for (int i=0; i<n; i++)
		result+=word;
	return result;
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
    	std::cout << std::string(n-i,' ');
    	std::cout << repeat("*",2*i+1) << std::endl;
    	std::cout << std::string(n-i,' ');
    	std::cout << repeat("* ",i) << "*" << std::endl;
    }
    std::cout << repeat("*",2*n+1) << std::endl;
    return 0;
}

