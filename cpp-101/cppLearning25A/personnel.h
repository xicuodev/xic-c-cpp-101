#pragma once
#include "main.h"
#include "post.h"

class Personnel {
public:
	// ��ʾ��Ա��Ϣ
	virtual void ShowInfo();

	int m_Id;		// ��Ա���
	string m_Name;	// ��Ա����
	int m_PostId;	// ��Ա���ڸ�λ���
};