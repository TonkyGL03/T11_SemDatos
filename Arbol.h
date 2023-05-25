#ifndef ARBOL_H
#define ARBOL_H

template<typename T>
class Nodo {
public:
    T data;
    Nodo<T> *left;
    Nodo<T> *right;

    Nodo(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class ArbolB {
private:
    Nodo<T> *root;

public:
    ArbolB() : root(nullptr) {}

    void inserta(T value) {
        insertaRec(root, value);
    }

    void elimina(Nodo<T> *nodo) {
        root = eliminaRec(root, nodo);
    }

    Nodo<T>* localiza(T value) {
        return localizaRec(root, value);
    }

private:
    void insertaRec(Nodo<T> *&nodo, T value) {
        if (nodo == nullptr) {
            nodo = new Nodo<T>(value);
        } else if (value < nodo->data) {
            insertaRec(nodo->left, value);
        } else if (value > nodo->data) {
            insertaRec(nodo->right, value);
        }
    }

    Nodo<T>* eliminaRec(Nodo<T> *nodo, Nodo<T> *eliminar) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (eliminar->data < nodo->data) {
            nodo->left = eliminaRec(nodo->left, eliminar);
        } else if (eliminar->data > nodo->data) {
            nodo->right = eliminaRec(nodo->right, eliminar);
        } else {
            if (nodo->left == nullptr) {
                Nodo<T> *temp = nodo->right;
                delete nodo;
                return temp;
            } else if (nodo->right == nullptr) {
                Nodo<T> *temp = nodo->left;
                delete nodo;
                return temp;
            }

            Nodo<T> *minRight = encuentraMinimo(nodo->right);
            nodo->data = minRight->data;
            nodo->right = eliminaRec(nodo->right, minRight);
        }

        return nodo;
    }

    Nodo<T>* encuentraMinimo(Nodo<T> *nodo) {
        while (nodo->left != nullptr) {
            nodo = nodo->left;
        }
        return nodo;
    }

    Nodo<T>* localizaRec(Nodo<T> *nodo, T value) {
        if (nodo == nullptr || value == nodo->data) {
            return nodo;
        } else if (value < nodo->data) {
            return localizaRec(nodo->left, value);
        } else {
            return localizaRec(nodo->right, value);
        }
    }
};

#endif  // ARBOL_H
