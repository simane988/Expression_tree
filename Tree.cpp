#include "Tree.h"

bool Tree::isOperator(char c)
{
	if (c == '+' || c == '-' ||
		c == '*' || c == '/')
		return true;
	return false;
}

void Tree::printTreePreorder(TreeNode* root, int space, ostream& ans)
{
	// �������� ������ �� �������, �.�. ��� �����������
	if (!root)
		return;
	// ����������� ����, ������� �������� ��������� ��� ����� "���������" ������ ������
	int COUNT = 3;
	// ���������� ���������� �������� � ������ ������ ������
	space += COUNT;
	// ������ ��������
	for (int i = COUNT; i < space; ++i)
		ans << " ";
	// ����� �������� ����
	ans << root->value << endl;
	// ���������� ����� ������� ��� ������ ����
	printTreePreorder(root->left, space, ans);
	// ���������� ����� ������� ��� ������ ����
	printTreePreorder(root->right, space, ans);
}

void Tree::printTree(TreeNode* root, int space, ostream& ans)
{
	// �������� ������ �� �������, �.�. ��� �����������
	if (!root)
		return;
	// ����������� ����, ������� �������� ��������� ��� ����� "���������" ������ ������
	int COUNT = 9;
	// ���������� ���������� �������� � ������ ������ ������
	space += COUNT;
	// ���������� ����� ������� ��� ������ ����
	printTree(root->left, space, ans);
	// ������ ��������
	for (int i = COUNT; i < space; ++i)
		ans << " ";
	// ����� �������� ����
	ans << root->value << endl;
	// ���������� ����� ������� ��� ������ ����
	printTree(root->right, space, ans);
}

TreeNode* Tree::newNode(char v)
{
	// ������ ����� ����
	TreeNode* temp = new TreeNode;
	// ������ �� �������� �������� ������������� � nullptr
	temp->left = temp->right = nullptr;
	// ������������� ���������� � ������� �������� � �������������� ����� ����
	temp->value = v;
	// ���������� ����
	return temp;
}

Tree::Tree(string postfix)
{
	stack<TreeNode*> st; // ���� ��� ���������
	TreeNode* t, * t1, * t2; // ��������� ����������

	// ������� ��������� � ����������� �����
	for (int i = 0; i < postfix.length(); i++)
	{
		// ���� ���� �� �������� ������ �������� => �������� ���������
		if (!isOperator(postfix[i])) {
			// �� ������ ����� ���� �� ��������� ��������
			t = newNode(postfix[i]);
			// � ��������� ��� � ����
			st.push(t);
		}
		// ���� ���� �������� ������ ��������
		else {
			// �� ������ ����� ���� �� ��������� ��������
			t = newNode(postfix[i]);
			
			// �������� ��������� ��� ����� � ����� � ������� �� �� �� ����
			t1 = st.top();
			st.pop();
			t2 = st.top();
			st.pop();

			// ������������� �� ��� ����� ��� �������� ����
			t->right = t1;
			t->left = t2;

			// ��������� ���������� ���� � ����
			st.push(t);
		}
	}

	// �������� ����� ������� ���� (��������) �� �����
	t = st.top();
	// ������� ��� �� �����, �.�. ���� ������� ������
	st.pop();

	// ������������� �������� ��������� ���� � ���������� ������ ��� �������� ��������� ����
	this->root = t; 
}

string Tree::toString()
{
	stringstream ans; // �������� stringstream ��� ��������������� ������ ��������� ������
	printTree(this->root, 0, ans);
	return ans.str(); // �������������� stringstream � string
}

string Tree::toStringPreorder()
{
	stringstream ans; // �������� stringstream ��� ��������������� ������ ��������� ������
	printTreePreorder(this->root, 0, ans);
	return ans.str(); // �������������� stringstream � string
}
