#include "post.h"

Post::Post(int id) {
	m_Id = id;
}

string Post::PostNameOf(int id) {
	switch (id)
	{
	case EMPLOYEE:
		return "ְ��";
	case MANAGER:
		return "����";
	case BOSS:
		return "�ϰ�";
	default:
		return "δ֪��λ";
	}
}

string Post::PostDutyOf(int id) {
	switch (id)
	{
	case EMPLOYEE:
		return "��ɾ�����������";
	case MANAGER:
		return "����ϰ彻�������񣬸�ְ���ɷ�����";
	case BOSS:
		return "��ְ���;������ʣ��������ɷ�����";
	default:
		return "δ֪��λ��ְ��";
	}
}