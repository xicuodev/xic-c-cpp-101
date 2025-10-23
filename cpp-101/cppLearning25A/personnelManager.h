#pragma once
#include "personnel.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define SAVE_FILENAME "personnel_save.txt"

class PersonnelManager {
public:
	PersonnelManager();
	~PersonnelManager();
	void ShowMenu();
	int RequireAndExecuteChoice();
	// 0. �˳�����ϵͳ
	void ExitSystem();
	// 1. �����Ա��Ϣ
	void RequireAndAddStaff();
	// 2. ��ʾ������Ա
	void ShowAllNow();
	// 3. ɾ����Ա��Ϣ
	void RequireAndDeleteStaff();
	// 4. �޸���Ա��Ϣ
	void RequireAndModifyStaff();
	// 5. ������Ա��Ϣ
	void RequireAndFindStaff();
	// 6. ���ձ������
	void RequireAndSortStaff();
	// 7. �����Ա��Ϣ
	void ClearStaff();

private:
	// ������̬��Ա��Ϣ
	Personnel* Staff(int id, string name, int postId);
	// ��ȡ�����Ա���򣬲����ڷ��� -1
	int IndexOf(int id);
	// ɾ��ָ�������Ա
	void DeleteStaff(int index);
	// ���浱ǰ��Ա��Ϣ
	void SaveNow();
	// ͳ�ƴ浵��Ա����
	int NumToLoad();
	// äĿ��ȡ�浵
	void LoadNow();

	int m_NumNow;
	Personnel** m_PtrsNow;
	bool m_IsNoSave;
};

void mainPM() {
	PersonnelManager pm; int choice = 0;
	do {
		pm.ShowMenu();
		choice = pm.RequireAndExecuteChoice();
	} while (choice != 0);
}
