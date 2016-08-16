#include <stdio.h>
#include <stdlib.h>

struct node
{
		int number; 
		struct node *left; 
		struct node *right;
};

struct node *make_btree(struct node *root, int number)
{
	if(!root)
    {
		root = (struct node*)malloc(sizeof(struct node));
		root -> number = number;
		root -> left = NULL;
		root -> right = NULL;
	}
	else if (number <= root -> number)
		root -> left = make_btree(root -> left, number);
	else
		root -> right = make_btree(root -> right, number);
	return root;
}
		
void view_btree(struct node *root)
{
	if (root)
    {
		view_btree(root -> left);
		printf("%d \n", root -> number);
		view_btree(root -> right);
	}
}

void del_btree(struct node *root)
{
	if(root == NULL)
    {
		return ;
	}
	if(root -> left != NULL)
    {
		del_btree(root -> left);
	}
	if(root -> right != NULL)
    {
		del_btree(root -> right);
	}
	free(root);
	root = NULL;	
}

int main(void)
{
	struct node *root = NULL;
	int num, i;
	int *array;

	printf("Please, enter number of tree elements!\n");
	scanf("%d", &num);
	array = (int*)malloc(num*sizeof(int));
	printf("Enter tree elements!\n");
	for(i=0; i<num; i++)
    {
		scanf("%d", &array[i]);
	}
	for(i=0; i<num; i++)
    {
		root = make_btree(root, array[i]);
	}
	view_btree(root);
	printf("\n");
	free(array);
	del_btree(root);
	return 0;
}
