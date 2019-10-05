// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	BitLen = len;
	//if (len % 4 == 0) {
	//	MemLen = (len - 1) / sizeof(int) + 1 ;
	//	pMem = new TELEM[MemLen];
	//}
	//else {
		MemLen = (BitLen / (sizeof(int))) + 1;
		pMem = new TELEM[MemLen];
		for (int i = 0; i < MemLen; i++)
			pMem[i] = 0;
	//}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
}

TBitField::~TBitField()
{
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << 32 * GetMemIndex(n) + n % (sizeof(TELEM) * 8);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n<0 || n>BitLen) {
		throw(" ");
	}
	else {
		pMem[GetMemIndex(n)] |= GetMemMask(n);
	}
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n<0 || n>BitLen) {
		throw(" ");
	}
	else {
		pMem[GetMemIndex(n)] &= ~GetMemMask(n);
	}
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n<0 || n>BitLen) {
		throw(" ");
	}
	else {
		return pMem[GetMemIndex(n)] & GetMemMask(n);
	}
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (this == &bf)
		return *this;
	this->BitLen = bf.BitLen;
	this->MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++) {
		pMem[i] |= bf.pMem[i];
	}
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen)

		return 0;

	for (int i = 0; i < BitLen; i++)

		if (pMem[i] != bf.pMem[i])

			return 0;

	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
  return TBitField(1);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
  return TBitField(1);
}

TBitField TBitField::operator~(void) // отрицание
{
  return TBitField(1);
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
  return istr;
}


ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
  return ostr;
}
