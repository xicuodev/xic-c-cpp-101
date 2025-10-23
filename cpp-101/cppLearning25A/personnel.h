#pragma once
#include "main.h"
#include "post.h"

class Personnel {
public:
	// 显示人员信息
	virtual void ShowInfo();

	int m_Id;		// 人员编号
	string m_Name;	// 人员姓名
	int m_PostId;	// 人员所在岗位编号
};