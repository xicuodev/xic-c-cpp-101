#include "personnel.h"

void Personnel::ShowInfo() {
	cout << "编号："		<< this->m_Id						<< "\t"
		 << "姓名："		<< this->m_Name						<< "\t"
		 << "岗位："		<< Post::PostNameOf(this->m_PostId)	<< "\t"
		 << "职责："		<< Post::PostDutyOf(this->m_PostId)	<< endl;
}