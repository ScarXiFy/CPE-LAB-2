#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data; 
    struct Node *left;
    struct Node *right;
};

void printTreeRecursive(struct Node* node, int level) {
    if (node == NULL) {
        return;
    }

    printTreeRecursive(node->left, level + 1);

    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%s\n", node->data);

    printTreeRecursive(node->right, level + 1);
}

void printTree(struct Node* root) {
    printf("Expression Tree:\n");
    if (root == NULL) {
        printf("Empty\n");
        return;
    }
    printTreeRecursive(root, 0);
}

struct Node* createNode(char* data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = (char*)malloc(strlen(data) + 1);
    strcpy(node->data, data); 
    node->left = node->right = NULL;
    return node;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);  
    printf("%s ", root->data);     
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%s ", root->data);     
    preorderTraversal(root->left); 
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);  
    postorderTraversal(root->right); 
    printf("%s ", root->data); 
}

int main() {
    char x[10], y[10], z[10], temp1[10];
    int x1, y2, temp;
    // ... (code for creating the expression tree remains the same)

    struct Node* root = createNode("=");
    root->left = createNode("+");
    root->left->left = createNode("*");
    root->left->left->left = createNode("2");
    root->left->left->right = createNode("x");
    root->left->right = createNode("y");
    root->right = createNode("z");

    printTree(root);

    printf("\nEnter the value of x: ");
    scanf("%s", x);

    printf("Enter the value of y: ");
    scanf("%s", y);

    x1 = atoi(x);
    y2 = atoi(y);

    temp = 2 * x1 + y2;
    sprintf(z, "%d", temp);

    root->left->left->right = createNode(x);
    root->left->right = createNode(y);
    root->right = createNode(z);

    printTree(root);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}