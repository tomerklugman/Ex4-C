#ifndef _TRIE_H
#define _TRIE_H

#define NUM_LETTERS ((int)26)

typedef enum {
	FALSE = 0,
	TRUE = 1
} boolean;

typedef struct node {
	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];
	boolean isendword;
	boolean isword;
} node;

node* createnode(void);
node *freetrie(node *root);
void makesmallandremovespecial(char *str);
void insert(node* head,char* word);
void printTraverse(node* node, char* word,int rank);
void printreverse(node* node, char* word, int rank);

#endif 
