#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    char title[50];
    struct Node* child;
    struct Node* sibling;
} Node;

// Create node
Node* createNode(char title[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Add child
void addChild(Node* parent, char title[]) {
    Node* newNode = createNode(title);

    if (parent->child == NULL) {
        parent->child = newNode;
    } else {
        Node* temp = parent->child;
        while (temp->sibling != NULL)
            temp = temp->sibling;
        temp->sibling = newNode;
    }
}

// Display tree
void display(Node* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++)
        printf("  ");

    printf("- %s\n", root->title);

    display(root->child, level + 1);
    display(root->sibling, level);
}

// Search node
Node* search(Node* root, char title[]) {
    if (root == NULL) return NULL;

    if (strcmp(root->title, title) == 0)
        return root;

    Node* found = search(root->child, title);
    if (found) return found;

    return search(root->sibling, title);
}

// Update node
void update(Node* root, char oldTitle[], char newTitle[]) {
    Node* node = search(root, oldTitle);

    if (node) {
        strcpy(node->title, newTitle);
        printf("Updated successfully!\n");
    } else {
        printf("Node not found!\n");
    }
}

// Delete (simple version: deletes leaf node)
void deleteNode(Node* root, char title[]) {
    if (root == NULL) return;

    Node* prev = NULL;
    Node* curr = root->child;

    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0) {
            if (prev == NULL)
                root->child = curr->sibling;
            else
                prev->sibling = curr->sibling;

            free(curr);
            printf("Deleted successfully!\n");
            return;
        }

        prev = curr;
        curr = curr->sibling;
    }

    deleteNode(root->child, title);
    deleteNode(root->sibling, title);
}

// Main menu
int main() {
    Node* root = createNode("E-Book");

    int choice;
    char parent[50], title[50], newTitle[50];

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add Section\n");
        printf("2. Delete Section\n");
        printf("3. Update Section\n");
        printf("4. Search Section\n");
        printf("5. Display TOC\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter parent title: ");
                scanf("%s", parent);
                printf("Enter new section title: ");
                scanf("%s", title);

                Node* p = search(root, parent);
                if (p)
                    addChild(p, title);
                else
                    printf("Parent not found!\n");
                break;

            case 2:
                printf("Enter title to delete: ");
                scanf("%s", title);
                deleteNode(root, title);
                break;

            case 3:
                printf("Enter old title: ");
                scanf("%s", title);
                printf("Enter new title: ");
                scanf("%s", newTitle);
                update(root, title, newTitle);
                break;

            case 4:
                printf("Enter title to search: ");
                scanf("%s", title);
                if (search(root, title))
                    printf("Found!\n");
                else
                    printf("Not found!\n");
                break;

            case 5:
                display(root, 0);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}