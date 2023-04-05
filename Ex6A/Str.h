#pragma once
#include "_str.h";

class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }		//если не копи€, то создаем
	Str(const char* p) {		// новый ресурс
		m_pStr = new _str(p);
	}
	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ссылаемс€ на тот же ресурс
		m_pStr->AddRef(); 	// отмечаем, что сослались
	}
	~Str() {
		m_pStr->Release(); 	// Ќе уничтожаем ресурс!
	}				// ”меньшаем счетчик ссылок!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); 
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}
	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {		// добавление ничего не изменит!
			_str* pstrTmp = new _str; 	// Ќовый ресурс
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}
	operator const char* () const {
		return m_pStr->m_pszData;
	}
	int find(const char* t, int off) const {
		const int lenT = strlen(t);
		const int lenS = strlen(m_pStr->m_pszData);

		if (lenT == 0 || off >= lenS) return -1;

		for (int i = off; i < lenS - lenT + 1; i++) {
			if (m_pStr->m_pszData[i] == t[0]) {
				int j = 1;
				while (j < lenT && m_pStr->m_pszData[i + j] == t[j]) j++;				
				if (j == lenT) return i;	
			}
		}
		return -1;
	}
};