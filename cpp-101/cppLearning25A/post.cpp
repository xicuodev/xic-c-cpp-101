#include "post.h"

Post::Post(int id) {
	m_Id = id;
}

string Post::PostNameOf(int id) {
	switch (id)
	{
	case EMPLOYEE:
		return "职工";
	case MANAGER:
		return "经理";
	case BOSS:
		return "老板";
	default:
		return "未知岗位";
	}
}

string Post::PostDutyOf(int id) {
	switch (id)
	{
	case EMPLOYEE:
		return "完成经理交给的任务。";
	case MANAGER:
		return "完成老板交给的任务，给职工派发任务。";
	case BOSS:
		return "给职工和经理发工资，给经理派发任务。";
	default:
		return "未知岗位的职责";
	}
}