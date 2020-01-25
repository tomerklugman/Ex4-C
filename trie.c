#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "trie.h"

// Allocate new trie node and set it to null
node* createnode()
{ 
	//node* mynode;
	node* mynode = (node*)malloc(sizeof(node));
	mynode->isendword = FALSE;
	int i=0;
	
	while(i<NUM_LETTERS) 
	{
		mynode->children[i] = NULL;
		i++;	
	}
	
	return mynode;
}

// Free node memory allocation
node *freetrie(node *root)
{	
	for(int i=0;i < NUM_LETTERS;i++)
		if(root->children[i] != NULL)
			freetrie(root->children[i]);
		
	free(root);
	return NULL;
}

// Makes big chars to small and removes special chars
void makesmallandremovespecial(char *str)
{ 
	int nextword = 0;
	int size = strlen(str);
	char *words = (char*)malloc(strlen(str));
	
	for(int i=0;i<size;i++)
	{
		if(!isalpha(str[i]))
			continue;
		
		*(words+nextword) = tolower(str[i]);
		nextword++;
	}
	
	words[nextword] = 0;
	strcpy(str,words);
    free(words);
}

// Inserts new word chars and adds count to each node
void insert(node* root,char* word)
{ 
	makesmallandremovespecial(word);
	node* temp = root;
	
	for(int i=0;i<strlen(word);i++)
	{
		if(temp->children[word[i]-A_VALUE] == NULL)
		{
			temp->children[word[i]-A_VALUE] = createnode();
			temp = temp->children[word[i]-A_VALUE];
			temp->letter = word[i];								
		}
		else
			temp = temp->children[word[i]-A_VALUE];			
	}
	
	temp->count++;
	temp->isword = TRUE;		
}

// Prints the desired way.
void printTraverse(node* node, char* word,int rank)
{
    if(node == NULL)
		return;
	
	if(rank <= strlen(word))
		word[rank-1]=0;
	
	strncat(word,&node->letter,1);
	if(node->isword==TRUE) 
		printf("%s\t%ld\n",word,node->count);		
	
	for(int i=0;i<NUM_LETTERS;i++) 		
		if(node->children[i] != NULL) 
			printTraverse(node->children[i],word,rank+1);
}

// Prints the reverse of the desired way.
void printreverse(node* node, char* word, int rank)
{
    if(node==NULL)
		return;

	if(rank<=strlen(word)) 
		word[rank-1]=0;

	strncat(word,&node->letter,1);
	if(node->isword==TRUE) 
		printf("%s\t%ld\n",word,node->count);
	
	for(int i=NUM_LETTERS-1;i>=0;i--) 
		if(node->children[i]!=NULL) 
			printreverse(node->children[i],word,rank+1);
}

