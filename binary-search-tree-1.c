/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {   //부모 노드????
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;  // 노드 포인터 head 선언
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {  //초기화 함수

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)  // inorder 정렬 함수
{
    inorderTraversal(ptr->left); // 왼쪽 노드로 이동
    printf("[ %d ]   ", ptr->key); // 현재 노드 출력
    inorderTraversal(ptr->right);  // 오른쪽 노드로 이동
}

void preorderTraversal(Node* ptr) // preorder 정렬 함수
{
    printf("[ %d ]   ", ptr->key);   // 현재 노드 출력
    inorderTraversal(ptr->left);    // 왼쪽 노드로 이동
    inorderTraversal(ptr->right);   // 오른쪽 노드로 이동
}

void postorderTraversal(Node* ptr) // postorder 정렬 함수
{
    inorderTraversal(ptr->left);   // 왼쪽 노드로 이동
    inorderTraversal(ptr->right);     // 오른쪽 노드로 이동
    printf("[ %d ]   ", ptr->key);  // 현재 노드 출력
}


int insert(Node* head, int key)  // 삽입 함수
{ 
    Node* newNode = (Node*)malloc(sizeof(Node));  // 새로운 노드 생성
    newNode->key = key;  // 새로운 노드의 키 값 설정
    newNode->left = NULL;  // 새로운 노드의 왼쪽 자식 초기화
    newNode->right = NULL;  // 새로운 노드의 오른쪽 자식 초기화

    Node* cur = head->left;  // 현재 노드를 루트 노드로 설정
    Node* parent = NULL;  // 부모 노드 초기화

    while (cur != NULL) {
        parent = cur;  // 현재 노드를 부모 노드로 설정

        if (key < cur->key) {
            cur = cur->left;  // 왼쪽 자식으로 이동
        } 
        else if (key > cur->key) {
            cur = cur->right;  // 오른쪽 자식으로 이동
        } 
        else {
            free(newNode);  // 이미 같은 키 값이 존재하므로 새로운 노드를 해제하고 종료
            return 0;
        }
    }

// 트리가 비어있는 경우
    if (parent == NULL) {
        head->left = newNode;  //  새로운 노드를 루트 노드로 설정
    } else if (key < parent->key) {
        parent->left = newNode;  // 부모 노드의 왼쪽 자식으로 새로운 노드를 연결
    } else {
        parent->right = newNode;  // 부모 노드의 오른쪽 자식으로 새로운 노드를 연결
    }

    return 1;  // 삽입 성공
}

int deleteLeafNode(Node* head, int key) // 삭제 함수
{

}

Node* searchRecursive(Node* ptr, int key)  // 재귀적 탐색 함수
{

}

Node* searchIterative(Node* head, int key)  // 반복적 탐색 함수
{

}


int freeBST(Node* head)
{

}





