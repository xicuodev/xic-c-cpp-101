#include <stdio.h>
#include "postOf.h"
int main1() {
	char mid[] = "x/(i-j)*y";
	char* post = postOf(mid);
	printf("%s", post);
	return 0;
}

#include "thread-tree.h"
int main() {
	char str[] = "ABDH##I##EJ###CF##G##";
	ThreadTree root;
	int index = 0;
	strTreeInOrder(str, &root, &index);
	inOrder(inOrderThreading(root));
	return 0;
}