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

    printf("[----- [강수빈] [2023078011] -----]\n");

	do{
        // 옵션 출력
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

        // 문자 입력받음
		printf("Command = ");
		scanf(" %c", &command);

        // 문자에 따라 다른 함수 동작
		switch(command) {
		case 'z': case 'Z': // z 입력시 초기화 함수 호출
			initializeBST(&head);
			break;
		case 'q': case 'Q': // q 입력시 메모리 해제 함수 호출
			freeBST(head);
			break;
		case 'n': case 'N': // n 입력시 삽입 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);  // 삽입할 값을 입력받음
			insert(head, key); // head 주소와 key값을 전달
			break;
		case 'd': case 'D': // d 입력시 삭제 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);  // 삭제할 값을 입력받음
			deleteLeafNode(head, key);  // head 주소와 key값을 전달
			break;
		case 'f': case 'F': // f 입력시 반복적 탐색 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);  // 탐색할 값을 입력받음
			ptr = searchIterative(head, key);   // head 주소와 key값을 전달하고 주솟값을 리턴받음
			if(ptr != NULL) 
				printf("\n node [%d] found at %p\n", ptr->key, ptr);    // 찾은 노드 출력
			else
				printf("\n Cannot find the node [%d]\n", key);  // 못찾은 경우 출력
			break;
		case 's': case 'S': // s 입력시 재귀적 탐색 함수 호출
			printf("Your Key = ");
			scanf("%d", &key);  // 탐색할 값을 입력받음
			ptr = searchRecursive(head->left, key); // head 주소와 key값을 전달하고 주솟값을 리턴받음
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);    // 찾은 노드 출력
			else
				printf("\n Cannot find the node [%d]\n", key);  // 못찾은 경우 출력
			break;

		case 'i': case 'I': // i 입력시 inorder 정렬 함수 호출
			inorderTraversal(head->left);   // head 주소와 루트 주소 전달
			break;
		case 'p': case 'P': // p 입력시 preorder 정렬 함수 호출
			preorderTraversal(head->left);
			break; 
		case 't': case 'T': // t 입력시 postorder 정렬 함수 호출
			postorderTraversal(head->left);
			break;
		default:    // 다른 문자 입력시
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");  // 문구 출력
			break;
		}

	}while(command != 'q' && command != 'Q');   // q 입력시 종료

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
    if(ptr){
    inorderTraversal(ptr->left); // 왼쪽 노드로 이동
    printf("[ %d ]   ", ptr->key); // 현재 노드 출력
    inorderTraversal(ptr->right);  // 오른쪽 노드로 이동
    }
}

void preorderTraversal(Node* ptr) // preorder 정렬 함수
{
    if(ptr){
    printf("[ %d ]   ", ptr->key);   // 현재 노드 출력
    preorderTraversal(ptr->left);    // 왼쪽 노드로 이동
    preorderTraversal(ptr->right);   // 오른쪽 노드로 이동
    }
}

void postorderTraversal(Node* ptr) // postorder 정렬 함수
{
    if(ptr){
    postorderTraversal(ptr->left);   // 왼쪽 노드로 이동
    postorderTraversal(ptr->right);     // 오른쪽 노드로 이동
    printf("[ %d ]   ", ptr->key);  // 현재 노드 출력
    }
}


int insert(Node* head, int key)  // 삽입 함수
{ 
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;  // 새로운 노드에 key값 넣음
    newNode->left = NULL; // 새로운 노드의 왼쪽 자식 노드 NULL로 초기화
    newNode->right = NULL;  // 새로운 노드의 오른쪽 자식 노드 NULL로 초기화

// 루트가 없는 경우
    if (head->left == NULL) {
        head->left = newNode;   // 루트 노드로 새로운 노드 연결
        return 1;
    }

// 루트가 있는 경우
    Node* parent = NULL; // 부모 노드
    Node* cur = head->left; // 현재 노드

// 삽입할 위치 찾기 (가리키는 곳이 NULL이면 삽입할 위치 찾았으므로 반복문 종료)
    while (cur != NULL) {
        parent = cur;
        if (key < cur->key) {  // key값이 현재 노드의 key값보다 작으면
            cur = cur->left;    // 왼쪽 자식 노드로 이동
        } else if (key > cur->key) {    // key값이 현재 노드의 key값보다 크면
            cur = cur->right;   // 오른쪽 자식 노드로 이동
        } else {    // key값이 현재 노드의 key값과 같으면
            free(newNode); // 새로운 노드 메모리 해제
            return 0;
        }
    }

    if (key < parent->key) {    // 부모 노드(가리키고 있는 노드의 전 노드)의 key값보다 작으면
        parent->left = newNode; // 부모 노드의 왼쪽 자식 노드로 새로운 노드 연결
    } else {    // 부모 노드의 key값보다 크면
        parent->right = newNode;    // 부모 노드의 오른쪽 자식 노드로 새로운 노드 연결
    }

    return 1;
}

int deleteLeafNode(Node* head, int key) // 삭제 함수
{
    Node* parent = head;
    Node* cur = head->left;

    while (cur != NULL && cur->key != key) {
        parent = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (cur == NULL || (cur->left != NULL || cur->right != NULL)) {
        printf("the node [%d] is not a leaf.\n", key);
        return 0;
    }

    if (parent->left == cur) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }

    free(cur);
    return 1;
}

Node* searchRecursive(Node* ptr, int key)  // 재귀적 탐색 함수
{
    if (ptr == NULL || ptr->key == key) {
        return ptr;
    }

    if (key < ptr->key) {
        return searchRecursive(ptr->left, key);
    } else {
        return searchRecursive(ptr->right, key);
    }
}

Node* searchIterative(Node* head, int key)  // 반복적 탐색 함수
{
    Node* cur = head->left;

    while (cur != NULL) {
        if (cur->key == key) {
            return cur;
        }

        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    return NULL;
}

// 이진 탐색 트리의 모든 노드를 메모리에서 해제하는 함수
int freeBST(Node* head) 
{
    // 트리가 비어있거나 루트 노드만 있는 경우
    if (head == head->right) {
        free(head); // 루트 노드 메모리 해제
        return 1;
    }

    // 왼쪽 서브트리가 있는 경우
    if (head->left != NULL) {
        freeBST(head->left); // 왼쪽 서브트리의 모든 노드 메모리 해제
    }

    // 오른쪽 서브트리가 있는 경우
    if (head->right != NULL && head->right != head) {
        freeBST(head->right); // 오른쪽 서브트리의 모든 노드 메모리 해제
    }

    free(head); // 현재 노드의 메모리 해제
    return 1;
}





