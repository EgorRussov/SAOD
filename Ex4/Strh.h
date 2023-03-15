#pragma once
#include <cstring>
class Str {
	char* m_pszText;
public:
	Str() 
	{
		m_pszText = new char[1] {0};
	}

	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}
	Str(const Str& s)
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}
	const Str& operator = (const Str& s)
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}

	operator const char* ()const { return m_pszText; }
	Str& operator +=(const char* sz) {
		if (sz) {
			size_t len = strlen(m_pszText) + strlen(sz) + 1;
			char* newStr = new char[len];
			strcpy_s(newStr, len, m_pszText);
			strcat_s(newStr, len, sz);
			delete[] m_pszText;
			m_pszText = newStr;
		}
		return *this;
	}
	Str operator+(const char* sz) const {
		if (sz) {
			size_t len = strlen(m_pszText) + strlen(sz) + 1;
			char* newStr = new char[len];
			strcpy_s(newStr, len, m_pszText);
			strcat_s(newStr, len, sz);
			Str result(newStr);
			delete[] newStr;
			return result;
		}
		return *this;
	}
	~Str() { delete[]m_pszText; }
};
