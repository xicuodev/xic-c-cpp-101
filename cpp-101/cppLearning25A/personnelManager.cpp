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
	cout << "======== ��ӭʹ����Ա����ϵͳ ========" << endl;
	cout << "======== 0. �˳�����ϵͳ" << endl;
	cout << "======== 1. �����Ա��Ϣ" << endl;
	cout << "======== 2. ��ʾ��Ա��Ϣ" << endl;
	cout << "======== 3. ɾ����Ա��Ϣ" << endl;
	cout << "======== 4. �޸���Ա��Ϣ" << endl;
	cout << "======== 5. ������Ա��Ϣ" << endl;
	cout << "======== 6. ���ձ������" << endl;
	cout << "======== 7. �����Ա��Ϣ" << endl;
	cout << "======================================" << endl;
}

int PersonnelManager::RequireAndExecuteChoice() {
	int choice;
	cout << "����������ѡ�";
	cin >> choice;
	switch (choice) {
	case 0: // �˳�����ϵͳ
		ExitSystem();
		break;
	case 1: // ������Ա��Ϣ
		RequireAndAddStaff();
		break;
	case 2: // ��ʾ��Ա��Ϣ
		ShowAllNow();
		break;
	case 3: // ɾ����Ա��Ϣ
		RequireAndDeleteStaff();
		break;
	case 4: // �޸���Ա��Ϣ
		RequireAndModifyStaff();
		break;
	case 5: // ������Ա��Ϣ
		RequireAndFindStaff();
		break;
	case 6: // ���ձ������
		RequireAndSortStaff();
		break;
	case 7: // �����Ա��Ϣ
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
	cout << "======================== ��ӭ�´�ʹ�ã�" << endl;
}

void PersonnelManager::RequireAndAddStaff() {
	int numToAdd = 0;
	cout << "======== ����Ҫ��ӵ���Ա������";
	cin >> numToAdd;
	if (numToAdd <= 0) {
		cout << "======== �������������" << endl << endl;
		return;
	}

	int numNew = m_NumNow + numToAdd;
	Personnel** ptrsNew = new Personnel * [numNew]; // ����һ��������������

	if (m_PtrsNow != NULL) { // �����������е�����Ԫ�ص���������
		for (int i = 0; i < m_NumNow; i++) {
			ptrsNew[i] = m_PtrsNow[i];
		}
	}

	int id = 0; string name = "ȱʡ����"; int postId = 0; int index = 0;
	for (int i = 0; i < numToAdd; i++) {
		cout << "======== ����� " << i + 1 << " ��Ҫ��ӵ���Ա����Ϣ��" << endl;

		do {
			cout << "====== ��ţ�";
			cin >> id;
			if (id < 0) { // ���븺�����������������
				delete[] ptrsNew; // ���Լ� new �����Ķ�������
				return;
			}
			index = IndexOf(id);
			if (index >= 0) cout << "== ��� " << id << " ����Ա�Ѵ��ڣ����飡" << endl;
		} while (index >= 0);
		
		cout << "====== ������";
		cin >> name;
		cout << "====== ��λ��ţ�";
		cin >> postId;
		ptrsNew[m_NumNow + i] = Staff(id, name, postId);
	}

	delete[] m_PtrsNow;
	m_PtrsNow = ptrsNew;
	m_NumNow = numNew;

	cout << "======== �ɹ���� " << numToAdd << " ����Ա��" << endl << endl;

	SaveNow();
}

void PersonnelManager::ShowAllNow() {
	if (!m_NumNow) {
		cout << "== û���κ���Ա��Ϣ�ɹ���ʾ�����ȡ������Ա��Ϣ����" << endl;
		return;
	}
	for (int i = 0; i < m_NumNow; i++) {
		cout << "== �� " << i + 1 << " ����Ա��";
		m_PtrsNow[i]->ShowInfo();
	}
}

void PersonnelManager::RequireAndDeleteStaff() {
	int id; int index;
	do {
		cout << "== ����Ҫɾ������Ա�ı�ţ�";
		cin >> id;
		if (id < 0) return; // ���븺��������������ɾ��
		index = IndexOf(id);
		if (index == -1) {
			cout << "== û���ҵ����Ϊ " << id << " ����Ա�����飡" << endl;
		}
	} while (index == -1);

	DeleteStaff(index);
	cout << "======== �ɹ�ɾ�����Ϊ " << id << " ����Ա��" << endl << endl;

	SaveNow();
}

void PersonnelManager::RequireAndModifyStaff() {
	int id; int index; string name; int postId;
	do {
		cout << "== ����Ҫ�޸ĵ���Ա�ı�ţ�����Ϊ���������޸ģ���";
		cin >> id;
		if (id < 0) return;
		index = IndexOf(id);
		if (index == -1) cout << "== �Ҳ������ " << id << " ����Ա�����飡" << endl;
	} while (index == -1);
	
	int indexTemp = index;
	do {
		cout << "== �µı�ţ�����Ϊ���޸ģ���";
		cin >> id;
		if (id < 0) break;
		index = IndexOf(id);
		if (index != -1) cout << "== ��� " << id << " ����Ա�Ѵ��ڣ����飡" << endl;
	} while (index != -1);
	index = indexTemp;

	cout << "== �µ�������0 Ϊ���޸ģ���";
	cin >> name;
	cout << "== �µĸ�λ��ţ�����Ϊ���޸ģ���";
	cin >> postId;

	if (id < 0) id = m_PtrsNow[index]->m_Id;
	if (name == "0") name = m_PtrsNow[index]->m_Name;
	if (postId < 0) postId = m_PtrsNow[index]->m_PostId;

	cout << "== �޸�ǰ�ĸ���Ա��";
	m_PtrsNow[index]->ShowInfo();

	delete m_PtrsNow[index];
	m_PtrsNow[index] = Staff(id, name, postId);

	cout << "== �޸ĺ�ĸ���Ա��";
	m_PtrsNow[index]->ShowInfo();

	SaveNow();
}

void PersonnelManager::RequireAndFindStaff() {
	int choice; int id; string name; int index = -1; int numFound = 0;
	cout << "== ѡ��һ�����ҷ�ʽ��0 - ����Ų��ң�1 - ���������ң����� - �������β��ң���";
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "== ����Ҫ���ҵ���Ա�ı�ţ�";
		cin >> id;
		for (int i = 0; i < m_NumNow; i++) {
			if (m_PtrsNow[i]->m_Id == id) {
				index = i; numFound++; break;
			}
		}
		if (!numFound) cout << "== ���޴��ˣ����顣" << endl;
		else {
			cout << "== �ҵ����Ϊ " << id << " ����Ա��" << endl;
			m_PtrsNow[index]->ShowInfo();
		}
		break;
	case 1:
		cout << "== ����Ҫ���ҵ���Ա��������";
		cin >> name;
		for (int i = 0; i < m_NumNow; i++) {
			if (m_PtrsNow[i]->m_Name == name) {
				index = i; numFound++;
				cout << "== �ҵ��� " << numFound << " ������Ϊ " << name << " ����Ա��" << endl;
				m_PtrsNow[index]->ShowInfo();
			}
		}
		if (!numFound) cout << "== ���޴��ˣ����顣" << endl;
		break;
	default:
		return;
	}
}

void PersonnelManager::RequireAndSortStaff() {
	int choice; Personnel* temp;

	cout << "== ׼����������ǰ����Ա�б�" << endl;
	ShowAllNow();

	cout << "== ѡ��һ������ʽ��0 - ���������1 - ����Ž������� - �����������򣩣�";
	cin >> choice;
	switch (choice)
	{
	case 0: // 0 - ���������
		for (int i = 0; i < m_NumNow - 1; i++) { // ð������
			for (int j = 0; j < m_NumNow - 1 - i; j++) {
				if (m_PtrsNow[j]->m_Id > m_PtrsNow[j + 1]->m_Id) {
					temp = m_PtrsNow[j];
					m_PtrsNow[j] = m_PtrsNow[j + 1];
					m_PtrsNow[j + 1] = temp;
				}
			}
		}
		break;
	case 1: // 1 - ����Ž���
		for (int i = 0; i < m_NumNow - 1; i++) { // ð������
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
	cout << "== �����������������Ա�б�" << endl;
	ShowAllNow();
}

void PersonnelManager::ClearStaff() {
	int choice;
	cout << "== �Ƿ�ȷ�������Ա��Ϣ����1 - �ǣ����� - ��" << endl
		 << "== ��������ѡ��";
	cin >> choice;
	if (choice == 1) {
		ofstream ofs(SAVE_FILENAME, ios::trunc);
		ofs.close();
		
		if (!m_PtrsNow) {
			cout << "[Debug] ��Ա����ָ���Ѿ��ÿա�" << endl;
			return;
		}

		for (int i = 0; i < m_NumNow; i++) {
			if (m_PtrsNow[i]) delete m_PtrsNow[i]; // ɾ��ÿ����Ա
		}
		delete[] m_PtrsNow; // ɾ����Աָ������

		m_IsNoSave = true;
		m_NumNow = 0;
		m_PtrsNow = NULL;

		cout << "== �ɹ������Ա��Ϣ��" << endl;
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
		cout << "======== ʹ����δ֪�ĸ�λ��ţ�ȱʡ��ְ���������顣" << endl;
		return new Employee(id, name); // ȱʡ��ְ������
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
	delete m_PtrsNow[index]; // ɾ��Ŀ����Ա
	for (int i = index; i < m_NumNow - 1; i++) {
		m_PtrsNow[i] = m_PtrsNow[i + 1]; // �������е���Աָ������ǰ��
	}
	m_PtrsNow[m_NumNow - 1] = NULL;
	m_NumNow--; // �߼��ϸ������� 1����ʹĩβ����Աָ�����´������Աʱ���µ���Աָ�븲��
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

	cout << "====== " << m_NumNow << " ����Ա����Ϣ�ѱ��浽 " << SAVE_FILENAME << " �С�" << endl << endl;
}

int PersonnelManager::NumToLoad() {
	ifstream ifs(SAVE_FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "====== �Ҳ����浵�ļ���" << endl;
		ifs.close();
		return 0;
	}
	else {
		char c; ifs >> c;
		cout << "[Debug] �����׸��ַ�Ϊ " << c << endl;
		if (ifs.eof()) { // �ж���һ�ζ�ȡ�Ƿ���� EOF���ļ�β��
			cout << "====== �ҵ��浵�ļ�����������Ϊ�ա�" << endl;
			ifs.close();
			return 0;
		}
	}
	ifs.close();
	ifs.open(SAVE_FILENAME, ios::in); // ֮ǰ����һ�Σ����¶���λ�øı䣬�����´�һ�θ�λ
	int numToLoad = 0; int id; string name; int postId;
	while (ifs >> id && ifs >> name && ifs >> postId) {
		cout << "[Debug] ������" << id << " " << name << " " << postId << endl;
		numToLoad++;
	}
	ifs.close();
	cout << "[Debug] ���� " << numToLoad << " ����Ա��" << endl;
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
