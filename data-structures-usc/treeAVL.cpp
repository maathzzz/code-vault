#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int height(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(Node *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* rotateRight(Node *y) {
    Node *x = y->left;
    Node *T = x->right;

    x->right = y;
    y->left = T;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

Node* rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T = y->left;

    y->left = x;
    x->right = T;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

Node* insert(Node* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    return node; 
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    return root; 
}

Node* balanceTree(Node* root) {
    if (root == NULL) return root;

    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) >= 0)
            return rotateRight(root); // Caso LL
        else {
            root->left = rotateLeft(root->left);
            return rotateRight(root); // Caso LR
        }
    }

    if (balance < -1) {
        if (getBalance(root->right) <= 0)
            return rotateLeft(root); 
        else {
            root->right = rotateRight(root->right);
            return rotateLeft(root); 
        }
    }

    return root;
}

void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    int COUNT = 5;
    space += COUNT;

    printTree(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    printTree(root->left, space);
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

void waitForEnter() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

int main() {
    Node* root = NULL;
    int option, value;

   do {
    printf("\nMenu:\n");
    printf("1. Inserir elemento\n");
    printf("2. Excluir elemento\n");
    printf("3. Exibir em Pre-ordem\n");
    printf("4. Exibir em Pos-ordem\n");
    printf("5. Exibir em Ordem Simetrica\n");
    printf("6. Balancear arvore\n");
    printf("7. Exibir em formato de grafo\n");
    printf("8. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            root = insert(root, value);
            waitForEnter();
            break;
        case 2:
            printf("Digite o valor a ser excluido: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            waitForEnter();
            break;
        case 3:
            printf("Arvore em Pre-ordem: ");
            preOrder(root);
            printf("\n");
            waitForEnter();
            break;
        case 4:
            printf("Arvore em Pos-ordem: ");
            postOrder(root);
            printf("\n");
            waitForEnter();
            break;
        case 5:
            printf("Arvore em Ordem Simetrica: ");
            inOrder(root);
            printf("\n");
            waitForEnter();
            break;
        case 6:
            root = balanceTree(root);
            printf("Arvore balanceada.\n");
            waitForEnter();
            break;
        case 7:
            printf("Arvore em formato de grafo:\n");
            printTree(root, 0);
            waitForEnter();
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            waitForEnter();
    }
    system("cls");
} while (option != 8);


    return 0;
}
