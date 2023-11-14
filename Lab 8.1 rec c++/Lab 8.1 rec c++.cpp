#include <iostream>
#include <string>
using namespace std;
int Count(const std::string s, size_t pos = 0, int k = 0)
{
	if (pos >= s.length() || k > 2) {
		return -1;
	}

	if (s[pos] == ',') {
		if (k == 2) {
			return pos;
		}
		else {
			return Count(s, pos + 1, k + 1);
		}
	}
	else {
		return Count(s, pos + 1, k);
	}
}
string Change(string& s, size_t pos = 0)
{
	if (pos >= s.length() || s.find(',', pos) == std::string::npos) {
		return s;
	}

	pos = s.find(',', pos);
	s.replace(pos, 1, "**");
	return Change(s, pos + 2);
}

int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	cout << "Char until third coma:  " << Count(str) << endl;
	string dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}