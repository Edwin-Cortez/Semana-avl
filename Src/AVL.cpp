#include "AVL.h"

int AVLTree::getHeight(Node* n) { return n ? n->height : 0; }

int AVLTree::getBalance(Node* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* AVLTree::insert(Node* node, Student s) {
    if (!node) {
        nodeCount++;
        return new Node(s);
    }

    if (s.skill_score < node->data.skill_score)
        node->left = insert(node->left, s);
    else if (s.skill_score > node->data.skill_score)
        node->right = insert(node->right, s);
    else {
        // BONUS: Desempate por ID si el score es igual
        if (s.student_id < node->data.student_id)
            node->left = insert(node->left, s);
        else
            node->right = insert(node->right, s);
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) return rotateRight(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) return rotateLeft(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void AVLTree::insert(Student s) { root = insert(root, s); }

void AVLTree::inOrder(Node* n, int &rank) {
    if (n) {
        inOrder(n->right, rank); // De mayor a menor
        std::cout << ++rank << ". " << n->data.full_name << " - Score: " << n->data.skill_score << std::endl;
        inOrder(n->left, rank);
    }
}

void AVLTree::displayRanking() {
    int rank = 0;
    std::cout << "\n--- RANKING ACADEMICO ---\n";
    inOrder(root, rank);
}

void AVLTree::searchByScore(int score) {
    Node* curr = root;
    while (curr) {
        if (curr->data.skill_score == score) {
            std::cout << "\nEstudiante encontrado:\n";
            std::cout << "Nombre: " << curr->data.full_name << "\nCarrera: " << curr->data.career << "\n";
            return;
        }
        curr = (score < curr->data.skill_score) ? curr->left : curr->right;
    }
    std::cout << "\nEstudiante con puntaje " << score << " no encontrado.\n";
}

void AVLTree::displayStats() {
    std::cout << "\n--- ESTADISTICAS DEL ARBOL ---\n";
    std::cout << "Altura actual: " << getHeight(root) << "\n";
    std::cout << "Factor de balance raiz: " << getBalance(root) << "\n";
    std::cout << "Cantidad de nodos: " << nodeCount << "\n";
}