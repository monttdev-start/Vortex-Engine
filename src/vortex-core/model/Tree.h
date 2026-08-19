#ifndef VORTEX_ENGINE_TREE_H
#define VORTEX_ENGINE_TREE_H
#include <cstdint>

template <typename T>
struct Node {
    int64_t ID_HASH;
    T data;
    struct Node *left_node, *right_node, *father_node;
};

template <typename T>
class Tree {
private:
    struct Node<T> *root;

    Node<T> *_insert(Node<T> *r, int64_t *data) {
        if (r == nullptr) {
            r = new Node<T>;
            r->data = data;
            r->left = r->right = nullptr;
            r->height = 1;
            return r;
        }

        if (data < r->data)
            r->left = insert(r->left, data);
        else
            r->right = insert(r->right, data);

        r->height = calheight(r);

        if (bf(r) == 2 && bf(r->left) == 1)       r = llrotation(r);
        else if (bf(r) == -2 && bf(r->right) == -1) r = rrrotation(r);
        else if (bf(r) == -2 && bf(r->right) == 1)  r = rlrotation(r);
        else if (bf(r) == 2 && bf(r->left) == -1)   r = lrrotation(r);

        return r;
    }

    uint32_t _calheight(Node<T> *p) {
        /*optimizar este condicional*/

        if (p->left && p->right) {
            if (p->left->height < p->right->height) return p->right->height + 1;
            else return p->left->height + 1;
        }

        if (p->left && p->right == nullptr) return p->left->height + 1;
        if (p->left == nullptr && p->right) return p->right->height + 1;

        return -1;
    }

    uint32_t _bf(Node<T> *n) {
        if (n->left && n->right)
            return n->left->height - n->right->height;
        if (n->left && n->right == nullptr)
            return n->left->height;
        if (n->left == nullptr && n->right)
            return -n->right->height;

        return 0;
    }

    Node<T> *_llrotation(Node<T> *n) {
        Node<T> *p = n;
        Node<T> *tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }

    Node<T> *_rrrotation(Node<T> *n) {
        Node<T> *p = n;
        Node<T> *tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }

    Node<T> *_rlrotation(Node<T> *n) {
        Node<T> *p = n;
        Node<T> *tp = p->right;
        Node<T> *tp2 = p->right->left;

        p->right = tp2->left;
        tp->left = tp2->right;
        tp2->left = p;
        tp2->right = tp;


        return tp2;
    }

    Node<T> *_lrrotation(Node<T> *n) {
        Node<T> *p = n;
        Node<T> *tp = p->left;
        Node<T> *tp2 = p->left->right;

        p->left = tp2->right;
        tp->right = tp2->left;
        tp2->right = p;
        tp2->left = tp;

        return tp2;
    }

    Node<T> *_deleteNode(Node<T> *p, int data) {
        if (p->left == nullptr && p->right == nullptr) {
            if (p == this->root) this->root = nullptr;
            delete p;
            return nullptr;
        }
        Node<T> *q;

        if (p->data < data) p->right = deleteNode(p->right, data);
        else if (p->data > data) p->left  = deleteNode(p->left, data);

        else {
            if (p->left != nullptr) {
                q = inpre(p->left);
                p->data = q->data;
                p->left = deleteNode(p->left, q->data);
            } else {
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right, q->data);
            }
        }

        if (bf(p) == 2 && bf(p->left) == 1) p = llrotation(p);
        else if (bf(p) == 2 && bf(p->left) == -1) p = lrrotation(p);
        else if (bf(p) == 2 && bf(p->left) == 0) p = llrotation(p);
        else if (bf(p) == -2 && bf(p->right) == -1) p = rrrotation(p);
        else if (bf(p) == -2 && bf(p->right) == 1) p = rlrotation(p);
        else if (bf(p) == -2 && bf(p->right) == 0) p = rrrotation(p);

        return p;
    }

public:
    Tree() {
        this->root = nullptr;
    }
    ~Tree();

    void InsertTree(T data) {
        this->root = _insert(this->root, &data);
    }

    void DeleteTree(int64_t ID) {
        this->root = _deleteNode(this->root, ID);
    }

};


#endif
