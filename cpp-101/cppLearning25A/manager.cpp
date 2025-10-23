#include "manager.h"

Manager::Manager(int id, string name) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_PostId = MANAGER;
}