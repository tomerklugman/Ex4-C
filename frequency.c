#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "trie.h"

int main(int argc, char* argv[]) {	
	node* head=createnode();
	char chars[150];
	char word[150];	
	while(scanf("%s", word)!=EOF) {
		insert(head, word);
	}
	if(argv[1]!=NULL) {
		if(strcmp("r", argv[1])==0) {
			printreverse(head,chars,0);
		}	
	}else{
	        printTraverse(head,chars,0);
	}	
	freetrie(head);
	return 0;
}