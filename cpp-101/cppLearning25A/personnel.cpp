#include "personnel.h"

void Personnel::ShowInfo() {
	cout << "��ţ�"		<< this->m_Id						<< "\t"
		 << "������"		<< this->m_Name						<< "\t"
		 << "��λ��"		<< Post::PostNameOf(this->m_PostId)	<< "\t"
		 << "ְ��"		<< Post::PostDutyOf(this->m_PostId)	<< endl;
}