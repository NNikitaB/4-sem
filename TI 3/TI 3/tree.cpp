#include "pch.h"
#include "tree.h"
#include <string>

// Функция добавления узла к дереву
struct tnode *addtree(struct tnode *p, string& w,int cond) {
	
	if (p == NULL) {
		p = (struct tnode *)new(struct tnode);
		p->word = w;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		p->left = p->right = NULL;
		p->sm = cond;
	}
	else  if (cond == 0)
		p->left = addtree(p->left, w,cond);
	else
		p->right = addtree(p->right, w,cond);
	return p;
}
// Функция удаления поддерева
void freemem(tnode *tree) {
	if (tree != NULL) {
		freemem(tree->left);
		freemem(tree->right);
		delete tree;
	}
}
// Функция вывода дерева
void treeprint(struct tnode * p) {
	if (p != NULL  ) {
		if (p->left == NULL && p->right == NULL)cout << p->sm << ' ' << p->word << '\n';
		treeprint(p->left);
		
		treeprint(p->right);
		
		
	}
}
void treeprint_in_Map(struct tnode * root, map <string, string>& Map_Table,string* st) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL){Map_Table.insert(pair<string, string>(root->word, *st)); return;}
		//[root->word] = st;
		st->push_back('0');
		treeprint_in_Map(root->left, Map_Table, st );
		st->pop_back();
		st->push_back('1');
		treeprint_in_Map(root->right, Map_Table,st);
		st->pop_back();


	}
}