#pragma once
#include "personnel.h"

enum POST { // 0 - 职工；1 - 经理；2 - 老板
	EMPLOYEE, MANAGER, BOSS
};

class Post { // 岗位
public:
	Post(int id);
	string static PostNameOf(int id);
	string static PostDutyOf(int id);
	int m_Id;
};