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
	// 0. 退出管理系统
	void ExitSystem();
	// 1. 添加人员信息
	void RequireAndAddStaff();
	// 2. 显示所有人员
	void ShowAllNow();
	// 3. 删除人员信息
	void RequireAndDeleteStaff();
	// 4. 修改人员信息
	void RequireAndModifyStaff();
	// 5. 查找人员信息
	void RequireAndFindStaff();
	// 6. 按照编号排序
	void RequireAndSortStaff();
	// 7. 清除人员信息
	void ClearStaff();

private:
	// 创建多态人员信息
	Personnel* Staff(int id, string name, int postId);
	// 获取编号人员次序，不存在返回 -1
	int IndexOf(int id);
	// 删除指定编号人员
	void DeleteStaff(int index);
	// 保存当前人员信息
	void SaveNow();
	// 统计存档人员个数
	int NumToLoad();
	// 盲目读取存档
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
