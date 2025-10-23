#pragma once
#include "personnel.h"

enum POST { // 0 - ְ����1 - ����2 - �ϰ�
	EMPLOYEE, MANAGER, BOSS
};

class Post { // ��λ
public:
	Post(int id);
	string static PostNameOf(int id);
	string static PostDutyOf(int id);
	int m_Id;
};