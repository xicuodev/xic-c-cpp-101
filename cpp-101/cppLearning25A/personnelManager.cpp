#include "personnelManager.h"

PersonnelManager::PersonnelManager() {
	int numToLoad = NumToLoad();
	if (numToLoad <= 0) {
		m_IsNoSave = true;
		m_NumNow = 0;
		m_PtrsNow = NULL;
	}
	else {
		m_IsNoSave = false;
		m_NumNow = numToLoad;
		m_PtrsNow = new Personnel * [m_NumNow];
		LoadNow();
	}
}

PersonnelManager::~PersonnelManager() {

}

void PersonnelManager::ShowMenu() {
	cout << "======== 欢迎使用人员管理系统 ========" << endl;
	cout << "======== 0. 退出管理系统" << endl;
	cout << "======== 1. 添加人员信息" << endl;
	cout << "======== 2. 显示人员信息" << endl;
	cout << "======== 3. 删除人员信息" << endl;
	cout << "======== 4. 修改人员信息" << endl;
	cout << "======== 5. 查找人员信息" << endl;
	cout << "======== 6. 按照编号排序" << endl;
	cout << "======== 7. 清除人员信息" << endl;
	cout << "======================================" << endl;
}

int PersonnelManager::RequireAndExecuteChoice() {
	int choice;
	cout << "请输入您的选项：";
	cin >> choice;
	switch (choice) {
	case 0: // 退出管理系统
		ExitSystem();
		break;
	case 1: // 增加人员信息
		RequireAndAddStaff();
		break;
	case 2: // 显示人员信息
		ShowAllNow();
		break;
	case 3: // 删除人员信息
		RequireAndDeleteStaff();
		break;
	case 4: // 修改人员信息
		RequireAndModifyStaff();
		break;
	case 5: // 查找人员信息
		RequireAndFindStaff();
		break;
	case 6: // 按照编号排序
		RequireAndSortStaff();
		break;
	case 7: // 清除人员信息
		ClearStaff();
		break;
	default:
		system("cls");
		break;
	}
	return choice;
}

void PersonnelManager::ExitSystem() {
	SaveNow();
	cout << "======================== 欢迎下次使用！" << endl;
}

void PersonnelManager::RequireAndAddStaff() {
	int numToAdd = 0;
	cout << "======== 输入要添加的人员人数：";
	cin >> numToAdd;
	if (numToAdd <= 0) {
		cout << "======== 输入的数字有误！" << endl << endl;
		return;
	}

	int numNew = m_NumNow + numToAdd;
	Personnel** ptrsNew = new Personnel * [numNew]; // 开辟一个更长的新数组

	if (m_PtrsNow != NULL) { // 复制现数组中的所有元素到新数组中
		for (int i = 0; i < m_NumNow; i++) {
			ptrsNew[i] = m_PtrsNow[i];
		}
	}

	int id = 0; string name = "缺省姓名"; int postId = 0; int index = 0;
	for (int i = 0; i < numToAdd; i++) {
		cout << "======== 输入第 " << i + 1 << " 名要添加的人员的信息：" << endl;

		do {
			cout << "====== 编号：";
			cin >> id;
			if (id < 0) { // 输入负数视作放弃本次添加
				delete[] ptrsNew; // 对自己 new 出来的东西负责
				return;
			}
			index = IndexOf(id);
			if (index >= 0) cout << "== 编号 " << id << " 的人员已存在，请检查！" << endl;
		} while (index >= 0);
		
		cout << "====== 姓名：";
		cin >> name;
		cout << "====== 岗位编号：";
		cin >> postId;
		ptrsNew[m_NumNow + i] = Staff(id, name, postId);
	}

	delete[] m_PtrsNow;
	m_PtrsNow = ptrsNew;
	m_NumNow = numNew;

	cout << "======== 成功添加 " << numToAdd << " 名人员！" << endl << endl;

	SaveNow();
}

void PersonnelManager::ShowAllNow() {
	if (!m_NumNow) {
		cout << "== 没有任何人员信息可供显示，请先【添加人员信息】。" << endl;
		return;
	}
	for (int i = 0; i < m_NumNow; i++) {
		cout << "== 第 " << i + 1 << " 名人员：";
		m_PtrsNow[i]->ShowInfo();
	}
}

void PersonnelManager::RequireAndDeleteStaff() {
	int id; int index;
	do {
		cout << "== 输入要删除的人员的编号：";
		cin >> id;
		if (id < 0) return; // 输入负数视作放弃本次删除
		index = IndexOf(id);
		if (index == -1) {
			cout << "== 没有找到编号为 " << id << " 的人员，请检查！" << endl;
		}
	} while (index == -1);

	DeleteStaff(index);
	cout << "======== 成功删除编号为 " << id << " 的人员！" << endl << endl;

	SaveNow();
}

void PersonnelManager::RequireAndModifyStaff() {
	int id; int index; string name; int postId;
	do {
		cout << "== 输入要修改的人员的编号（负数为放弃本次修改）：";
		cin >> id;
		if (id < 0) return;
		index = IndexOf(id);
		if (index == -1) cout << "== 找不到编号 " << id << " 的人员，请检查！" << endl;
	} while (index == -1);
	
	int indexTemp = index;
	do {
		cout << "== 新的编号（负数为不修改）：";
		cin >> id;
		if (id < 0) break;
		index = IndexOf(id);
		if (index != -1) cout << "== 编号 " << id << " 的人员已存在，请检查！" << endl;
	} while (index != -1);
	index = indexTemp;

	cout << "== 新的姓名（0 为不修改）：";
	cin >> name;
	cout << "== 新的岗位编号（负数为不修改）：";
	cin >> postId;

	if (id < 0) id = m_PtrsNow[index]->m_Id;
	if (name == "0") name = m_PtrsNow[index]->m_Name;
	if (postId < 0) postId = m_PtrsNow[index]->m_PostId;

	cout << "== 修改前的该人员：";
	m_PtrsNow[index]->ShowInfo();

	delete m_PtrsNow[index];
	m_PtrsNow[index] = Staff(id, name, postId);

	cout << "== 修改后的该人员：";
	m_PtrsNow[index]->ShowInfo();

	SaveNow();
}

void PersonnelManager::RequireAndFindStaff() {
	int choice; int id; string name; int index = -1; int numFound = 0;
	cout << "== 选择一个查找方式（0 - 按编号查找；1 - 按姓名查找；其他 - 放弃本次查找）：";
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "== 输入要查找的人员的编号：";
		cin >> id;
		for (int i = 0; i < m_NumNow; i++) {
			if (m_PtrsNow[i]->m_Id == id) {
				index = i; numFound++; break;
			}
		}
		if (!numFound) cout << "== 查无此人，请检查。" << endl;
		else {
			cout << "== 找到编号为 " << id << " 的人员：" << endl;
			m_PtrsNow[index]->ShowInfo();
		}
		break;
	case 1:
		cout << "== 输入要查找的人员的姓名：";
		cin >> name;
		for (int i = 0; i < m_NumNow; i++) {
			if (m_PtrsNow[i]->m_Name == name) {
				index = i; numFound++;
				cout << "== 找到第 " << numFound << " 名姓名为 " << name << " 的人员：" << endl;
				m_PtrsNow[index]->ShowInfo();
			}
		}
		if (!numFound) cout << "== 查无此人，请检查。" << endl;
		break;
	default:
		return;
	}
}

void PersonnelManager::RequireAndSortStaff() {
	int choice; Personnel* temp;

	cout << "== 准备排序，排序前的人员列表：" << endl;
	ShowAllNow();

	cout << "== 选择一个排序方式（0 - 按编号升序；1 - 按编号降序；其他 - 放弃本次排序）：";
	cin >> choice;
	switch (choice)
	{
	case 0: // 0 - 按编号升序
		for (int i = 0; i < m_NumNow - 1; i++) { // 冒泡排序
			for (int j = 0; j < m_NumNow - 1 - i; j++) {
				if (m_PtrsNow[j]->m_Id > m_PtrsNow[j + 1]->m_Id) {
					temp = m_PtrsNow[j];
					m_PtrsNow[j] = m_PtrsNow[j + 1];
					m_PtrsNow[j + 1] = temp;
				}
			}
		}
		break;
	case 1: // 1 - 按编号降序
		for (int i = 0; i < m_NumNow - 1; i++) { // 冒泡排序
			for (int j = 0; j < m_NumNow - 1 - i; j++) {
				if (m_PtrsNow[j]->m_Id < m_PtrsNow[j + 1]->m_Id) {
					temp = m_PtrsNow[j];
					m_PtrsNow[j] = m_PtrsNow[j + 1];
					m_PtrsNow[j + 1] = temp;
				}
			}
		}
		break;
	default:
		return;
	}
	cout << "== 已完成排序，排序后的人员列表：" << endl;
	ShowAllNow();
}

void PersonnelManager::ClearStaff() {
	int choice;
	cout << "== 是否确认清空人员信息？（1 - 是；其他 - 否）" << endl
		 << "== 输入您的选择：";
	cin >> choice;
	if (choice == 1) {
		ofstream ofs(SAVE_FILENAME, ios::trunc);
		ofs.close();
		
		if (!m_PtrsNow) {
			cout << "[Debug] 人员二级指针已经置空。" << endl;
			return;
		}

		for (int i = 0; i < m_NumNow; i++) {
			if (m_PtrsNow[i]) delete m_PtrsNow[i]; // 删除每个人员
		}
		delete[] m_PtrsNow; // 删除人员指针数组

		m_IsNoSave = true;
		m_NumNow = 0;
		m_PtrsNow = NULL;

		cout << "== 成功清空人员信息。" << endl;
	}
}

Personnel* PersonnelManager::Staff(int id, string name, int postId) {
	switch (postId)
	{
	case EMPLOYEE:
		return new Employee(id, name);
	case MANAGER:
		return new Manager(id, name);
	case BOSS:
		return new Boss(id, name);
	default:
		cout << "======== 使用了未知的岗位编号，缺省按职工处理，请检查。" << endl;
		return new Employee(id, name); // 缺省按职工处理
	}
}

int PersonnelManager::IndexOf(int id)
{
	for (int i = 0; i < m_NumNow; i++) {
		if (m_PtrsNow[i]->m_Id == id) { return i; }
	}
	return -1;
}

void PersonnelManager::DeleteStaff(int index) {
	delete m_PtrsNow[index]; // 删除目标人员
	for (int i = index; i < m_NumNow - 1; i++) {
		m_PtrsNow[i] = m_PtrsNow[i + 1]; // 将数组中的人员指针整体前移
	}
	m_PtrsNow[m_NumNow - 1] = NULL;
	m_NumNow--; // 逻辑上给人数减 1，以使末尾的人员指针在下次添加人员时被新的人员指针覆盖
}

void PersonnelManager::SaveNow() {
	ofstream ofs(SAVE_FILENAME, ios::out);
	for (int i = 0; i < m_NumNow; i++) {
		ofs << m_PtrsNow[i]->m_Id << " "
			<< m_PtrsNow[i]->m_Name << " "
			<< m_PtrsNow[i]->m_PostId << endl;
	}
	ofs.close();
	m_IsNoSave = false;

	cout << "====== " << m_NumNow << " 名人员的信息已保存到 " << SAVE_FILENAME << " 中。" << endl << endl;
}

int PersonnelManager::NumToLoad() {
	ifstream ifs(SAVE_FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "====== 找不到存档文件。" << endl;
		ifs.close();
		return 0;
	}
	else {
		char c; ifs >> c;
		cout << "[Debug] 读到首个字符为 " << c << endl;
		if (ifs.eof()) { // 判断上一次读取是否读到 EOF（文件尾）
			cout << "====== 找到存档文件，但其内容为空。" << endl;
			ifs.close();
			return 0;
		}
	}
	ifs.close();
	ifs.open(SAVE_FILENAME, ios::in); // 之前读过一次，导致读的位置改变，故重新打开一次复位
	int numToLoad = 0; int id; string name; int postId;
	while (ifs >> id && ifs >> name && ifs >> postId) {
		cout << "[Debug] 读到：" << id << " " << name << " " << postId << endl;
		numToLoad++;
	}
	ifs.close();
	cout << "[Debug] 读到 " << numToLoad << " 名人员。" << endl;
	return numToLoad;
}

void PersonnelManager::LoadNow() {
	ifstream ifs(SAVE_FILENAME, ios::in);
	int i = 0; int id; string name; int postId;
	while (ifs >> id && ifs >> name && ifs >> postId) {
		m_PtrsNow[i] = Staff(id, name, postId);
		i++;
	}
	ifs.close();
}
