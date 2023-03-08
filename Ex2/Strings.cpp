#include <iostream>
using namespace std;
void string_copy(char* d, char* t) {
	char* pd = t, * ps = d;
	for (int i = 0; i < strlen(t); i++) {
		*pd = *ps;
		pd++;
		ps++;
	}
}
int len(const char* s) {
	int lenght = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		lenght++;
	}
	return lenght;
}
int compare(const char* s, const char* t) {
	if (len(s) > len(t)) return 1;
	if (len(s) < len(t)) return -1;
	else return 0;
}
int main()
{
	char str[] = "Hello!";
	cout << str << endl;
	cout << strlen(str) << ' ' << sizeof(str) << endl;
	char t[32];
	//for (char* pd = t, *ps = str; *pd++ = *ps++;);
	string_copy(str, t);
	char str2[] = "k";
	cout << len(str) << " " << compare(str, str2);
}

