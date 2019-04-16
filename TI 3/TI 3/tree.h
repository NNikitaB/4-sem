#ifndef _TREE
#define _TREE
#include "pch.h"
#include <string>

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <map>
using namespace std;

#define MAXWORD 100
struct tnode {                // ���� ������
	string word;                  // ��������� �� ������ (�����)
	int sm;
	struct tnode *left;          // ����� �������
	struct tnode *right;         // ������ �������
};
struct tnode *addtree(struct tnode *p, string& w, int cond);
void freemem(tnode *tree);
void treeprint(struct tnode *p);
void treeprint_in_Map(struct tnode * root, map <string, string>& Map_Table, string* st);
#endif //PCH_H
