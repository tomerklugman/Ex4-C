#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "trie.h"

node* createnode(){ // allocate new trie node and set it to null
	node* mynode;
	mynode=(node*)malloc(sizeof(node));
	mynode->isendword=FALSE;
	int i=0;
	while(i<NUM_LETTERS) {
		mynode->children[i]=NULL;
		i++;	
	}
	return mynode;
}

node *freetrie(node *root){	// free node memory allocation
	for(int i=0;i<NUM_LETTERS;i++){
		if(root->children[i]!=NULL){
			freetrie(root->children[i]);
		}
	}
	free(root);
	return NULL;
}

void makesmallandremovespecial(char *str){ // makes big chars to small and removes special chars
	int nextword=0;
	int size=strlen(str);
	char *words=(char*)malloc(strlen(str));
	for(int i=0;i<size;i++){
		if(!isalpha(str[i])){
			continue;
		}
		*(words+nextword)=tolower(str[i]);
		nextword++;
	}
	words[nextword]=0;
	strcpy(str,words);
    free(words);
}

void insert(node* root,char* word) { // inserts new word chars and adds count to each node
	makesmallandremovespecial(word);
	node* temp=root;	
	for(int i=0;i<strlen(word);i++) {
		if(temp->children[word[i]-97]==NULL) {
			temp->children[word[i]-97]=createnode();
			temp=temp->children[word[i]-97];
			temp->letter=word[i];								
		
		}else{
			temp=temp->children[word[i]-97];			
		}

	}	
	temp->count++;
	temp->isword=TRUE;		
}

void printTraverse(node* node, char* word,int rank){
              if(node==NULL){
                return;
           }
	if(rank<=strlen(word)){
		word[rank-1]=0;
              }
	strncat(word,&node->letter,1);
	if(node->isword==TRUE) {
		printf("%s\t%ld\n",word,node->count);		
	}	
	for(int i=0;i<NUM_LETTERS;i++) {		
		if(node->children[i]!=NULL) {
		printTraverse(node->children[i],word,rank+1);
		}
	}
}

void printreverse(node* node, char* word, int rank){
               if(node==NULL){
                return;
                }
	if(rank<=strlen(word)) {
		word[rank-1]=0;
	}
	strncat(word,&node->letter,1);
	if(node->isword==TRUE) {
		printf("%s\t%ld\n",word,node->count);
	}
	for(int i=NUM_LETTERS-1;i>=0;i--) {
		if(node->children[i]!=NULL) {
			printreverse(node->children[i],word,rank+1);
		}
	}
}

