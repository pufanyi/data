#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s;
	while(getline(cin, s))
	{
		s.push_back('\n');
		for(unsigned i = 0; i < s.length(); ++i)
			if(s[i] == '\n')
				puts("haha");
	}
	return 0;
}