#pragma once
#include "main.h"

class Calculator
{
public:
	int getResult(char oper)
	{
		if (oper == '+')
			return m_Num1 + m_Num2;
		else if (oper == '-')
			return m_Num1 - m_Num2;
		else if (oper == '*')
			return m_Num1 * m_Num2;
		else if (oper == '/')
			return m_Num1 / m_Num2;
	}
	int m_Num1;
	int m_Num2;
};

class AbstractCalculator
{
public:
	int virtual getResult() { return 0; }
	int m_Num1;
	int m_Num2;
};

class AddCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

class MinusCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

class TimesCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

class DivideCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 / m_Num2;
	}
};