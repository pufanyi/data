#include <cstdio>
#include <cctype>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string TYPE[] =
{
	"RESERVED", //	±£Áô×Ö	1
	"NUMBER", //	Êý×Ö	2
	"STRING", //	×Ö·û´®	3
	"SYMBOL", //	·ûºÅ	4
	"NAME", //		±äÁ¿Ãû	5
	"EOL", //		»»ÐÐ·û	6
	"COMMENT" //	×¢ÊÍ	7
};

struct SYMBOL
{
	string all[26] =
	{
		"+", "-", "*", "/", "%", "^", "#",
		"==", "~=", "<=", ">=", "<", ">", "=",
		"(", ")", "{", "}", "[", "]",
		";", ":", ",", ".", "..", "..."
	};

	set<string> all_symbol;

	SYMBOL ()
	{
		all_symbol.clear();
		for(int i = 0; i < 26; ++i)
			all_symbol.insert(all[i]);
	}

	inline bool is_symbol(string s)
	{
		return all_symbol.count(s);
	}
} symb;

struct RESERVED
{
	string all[21] =
	{
		"and", "break", "do", "else", "elseif",
		"end", "false", "for", "function", "if",
		"in", "local", "nil", "not", "or",
		"repeat", "return", "then", "true", "until", "while"
	};

	set<string> all_reserved;

	RESERVED ()
	{
		all_reserved.clear();
		for(int i = 0; i < 21; ++i)
			all_reserved.insert(all[i]);
	}

	inline bool is_reserved(string s)
	{
		return all_reserved.count(s);
	}
} rese;

struct Token
{
	int typ;
	string s;

	Token (int tp = 6, string ss = "")
	{
		typ = tp, s = ss;
	}
};

struct NUMBER
{
	inline bool is_zf(char c)
	{
		return c == '+' || c == '-';
	}

	inline bool is_10_int(const register string& s)
	{
		unsigned l = 0;
		while(l < s.length() && is_zf(s[l]))
			l++;
		if(l >= s.length())
			return false;
		while(l < s.length() && isdigit(s[l]))
			l++;
		return l == s.length();
	}

	inline bool is_0x_char(char c)
	{
		return isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F');
	}

	inline bool is_0x_int(const register string& s)
	{
		unsigned l = 0;
		while(l < s.length() && is_zf(s[l]))
			l++;
		if(l + 1 >= s.length())
			return false;
		if(s[l] != '0' || (s[l + 1] != 'x' && s[l + 1] != 'X'))
			return false;
		l += 2;
		while(l < s.length() && is_0x_char(s[l]))
			l++;
		return l == s.length();
	}

	inline bool is_float(const register string& s)
	{
		unsigned l = 0;
		while(l < s.length() && is_zf(s[l]))
			l++;
		if(l + 1 >= s.length())
			return false;
		int hav_e = -1, hav_d = -1;
		for(unsigned i = l; i < s.length(); ++i)
		{
			if(s[i] == '.')
			{
				if(~hav_d)
					return false;
				else
					hav_d = i + 1;
			}
			else if(s[i] == 'E' || s[i] == 'e')
			{
				if(~hav_e)
					return false;
				else
					hav_e = i + 1;
			}
			else if(s[i] != '-' && s[i] != '+' && !isdigit(s[i]))
				return false;
		}
		if((~hav_e) && (~hav_d))
		{
			if(hav_e < hav_d || (hav_d == 1 && hav_e - hav_d == 1))
				return false;
			return ((hav_d == 1) || is_10_int(s.substr(0, hav_d - 1)))
			       && (is_10_int(s.substr(hav_d, hav_e - hav_d - 1))
			           ||(hav_e - hav_d == 1))
			       && is_10_int(s.substr(hav_e));
		}
		else if(~hav_e)
		{
			return is_10_int(s.substr(0, hav_e - 1))
			       && is_10_int(s.substr(hav_e));
		}
		else if(~hav_d)
		{
			return ((hav_d == 1) || is_10_int(s.substr(0, hav_d - 1)))
			       && is_10_int(s.substr(hav_d));
		}
		else
			return false;
	}

	inline int is_number(const register string& s)
	{
		if(s[0] == '+' || s[0] == '-')
			return 0;
		if(is_10_int(s))
			return 1;
		else if(is_0x_int(s))
			return 2;
		else if(is_float(s))
			return 3;
		else
			return 0;
	}
} numb;

class BUF
{
	private:
		string s;
		unsigned nowl;

		inline bool can_be_a_name(char c)
		{
			return isalpha(c) || c == '_' || isdigit(c);
		}

		inline bool can_be_a_number(char c)
		{
			return isdigit(c) || c == '.' || c == '-' || c == '+'
			       || c == 'E' || c == 'e'
			       || c == 'x' || c == 'X'
			       || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F');
		}

	public:
		BUF()
		{
			nowl = 0;
			s = "";
		}

		inline Token read()
		{
			Token ans;
			if(nowl == s.length())
			{
				if(!getline(cin, s))
					return Token(-1);
				nowl = 0;
				s.push_back('\n');
			}
			while(s[nowl] == ' ')
				nowl++;
			if(s[nowl] == '\n')
			{
				nowl++;
				return ans;
			}
			if(s[nowl] == '-' && s[nowl + 1] == '-')
			{
				nowl = s.length();
				return ans;
			}
			if(s[nowl] == '"')
			{
				bool zy = false;
				ans.s.push_back(s[nowl++]);
				while(zy || s[nowl] != '"')
				{
					if(!zy && s[nowl] == '\\')
						zy = true;
					else
						zy = false;
					ans.s.push_back(s[nowl++]);
				}
				ans.s.push_back(s[nowl++]);
				ans.typ = 3;
				return ans;
			}
			if(s[nowl] == '\'')
			{
				bool zy = false;
				ans.s.push_back(s[nowl++]);
				while(zy || s[nowl] != '\'')
				{
					if(!zy && s[nowl] == '\\')
						zy = true;
					else
						zy = false;
					ans.s.push_back(s[nowl++]);
				}
				ans.typ = 3;
				return ans;
			}
			if(isalpha(s[nowl]))
			{
				while(can_be_a_name(s[nowl]))
					ans.s.push_back(s[nowl++]);
				if(rese.is_reserved(ans.s))
					ans.typ = 1;
				else
					ans.typ = 5;
				return ans;
			}
			else
			{
				int r = 0;
				if(s[nowl] != '+' && s[nowl] != '-')
				{
					while(can_be_a_number(s[nowl + r]))
						r++;
					while(r && !numb.is_number(s.substr(nowl, r)))
						r--;
				}
				if(r)
				{
					ans.s = s.substr(nowl, r);
					nowl += r;
					ans.typ = 2;
				}
				else
				{
					string lst = ans.s = "";
					lst.push_back(s[nowl++]);
					while(symb.is_symbol(lst))
					{
						ans.s.push_back(s[nowl - 1]);
						lst.push_back(s[nowl++]);
					}
					nowl--;
					ans.typ = 4;
				}
				return ans;
			}
		}
} buf;

int main()
{
	Token s;
	while(s = buf.read(), ~s.typ)
	{
		s.typ--;
		if(s.typ == 5)
			cout << '[' << TYPE[s.typ] << ']' << '\n';
		else
			cout << '[' << TYPE[s.typ] << ']' << ' ' << s.s << '\n';
	}
	return 0;
}
