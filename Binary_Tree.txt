#include <iostream>

using namespace std;

template<class T>

class BinaryTreeNode
{

    BinaryTreeNode <T>* _left;
    BinaryTreeNode<T>* _right;
    BinaryTreeNode<T>* _parent;

    template<class U>
    friend class Set;
    T _value{};
public:
   
    BinaryTreeNode(T var) : _value(var) { }

};

template<class T>

class Set
{
private:
    BinaryTreeNode<T>* root = NULL;

    int test = 0;
    T* arr;
    int _count = 0;
public:

    void go(T num, BinaryTreeNode<T>* root)
    {

        if (num > root->_value)
        {
            if (root->_right == NULL)
            {
                root->_right = new BinaryTreeNode<T>(num);
                root->_right->_right = NULL;
                root->_right->_left = NULL;
                root->_right->_parent = root;
                _count++;
            }
            else go(num, root->_right);
        }
        else if (num < root->_value)
        {
            if (root->_left == NULL)
            {
                root->_left = new BinaryTreeNode<T>(num);
                root->_left->_right = NULL;
                root->_left->_left = NULL;
                root->_left->_parent = root;
                _count++;
            }
            else go(num, root->_left);

        }
    }

    int size()
    {
        return _count;
    }

    void insert(T num)
    {

        if (root == NULL || _count == 0)
        {
            root = new BinaryTreeNode<T>(num);
            root->_right = NULL;
            root->_left = NULL;
            _count++;
        }
        else go(num, root);
    }


    void getToArray(BinaryTreeNode<T>* root)
    {
        if (root != NULL)
        {
            arr[test] = root->_value;
            test++;
            if (root->_left != NULL) getToArray(root->_left);

            if (root->_right != NULL) getToArray(root->_right);
        }


    }
    void sorted()
    {
        test = 0;
        if (size() == 0) return;

        if (arr != NULL)
        {
            delete[] arr;
            arr = new T[size()];
        }
        else arr = new T[size()];

        getToArray(root);
        bool check = true;
        int size3 = size();
        while (check == true)
        {
            check = false;
            for (int i = 0; i < size3 - 1; i++)
            {
                if (arr[i] < arr[i + 1])
                {
                    check = true;
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
    void print()
    {
        int size2 = size();
        sorted();
        for (int i = 0; i < size2; i++)
        {
            cout << arr[i] << endl;
        }

    }

    BinaryTreeNode<T>* find(T num)
    {
        if (root == NULL) return NULL;

        if (root->_value == num) return root;
        else if (num > root->_value)  findNext(num, root->_right);
        else if (num < root->_value) findNext(num, root->_left);
    }

    BinaryTreeNode<T>* findNext(T num, BinaryTreeNode<T>* root)
    {
        if (num == root->_value)
        {
            return root;
        }
        else if (num > root->_value)findNext(num, root->_right);
        else if (num < root->_value)findNext(num, root->_left);
    }

    BinaryTreeNode<T>* begin()
    {
        if (_count != 0)
        {
            sorted();
            int size2 = size();
            clear();
            int i = 0;
            root = new BinaryTreeNode<T>(arr[i]);
            while (i != size2 + 1)
            {
                insert(arr[i]);
                i++;
            }
            return root;
        }

    }

    BinaryTreeNode<T>* end()
    {
        if (_count != 0)
        {
            sorted();
            int size2 = size();
            clear();
            int i = 0;
            root = new BinaryTreeNode<T>(arr[i]);
            while (i != size2 + 1)
            {
                insert(arr[i]);
                i++;
            }
            BinaryTreeNode<T>* temp = root;
            while (temp->_left != NULL)
            {
                temp = temp->_left;
            }
            return temp->_parent;
        }
    }
    void clear()
    {
        if (root == NULL) return;
        else clearTest(root);
    }
    void clearTest(BinaryTreeNode<T>* root)
    {
        if (root != NULL) clearTest(root->_left);
        if (root != NULL) clearTest(root->_right);
        delete root;
        _count = 0;
    }

    void erase(T num)
    {
        sorted();
        for (int i = 0; i < size(); i++)
        {
            if (num == arr[i])
            {
                if (i != size() - 1)
                {
                    for (int j = i; j < size() - 1; j++)
                    {
                        arr[j] = arr[j + 1];
                    }
                    int size2 = _count - 1;
                    clear();
                    int i = 0;
                    while (i != size2 + 1)
                    {
                        insert(arr[i]);
                        i++;
                    }
                }

                else
                {
                    int size2 = _count - 1;
                    clear();
                    int i = 0;
                    while (i != size2)
                    {
                        insert(arr[i]);
                        i++;
                    }
                }
            }
        }
    }


};

int main()
{

    Set<double> test1;
    test1.insert(39.5);
    test1.insert(50.1);
    test1.insert(7);
    test1.insert(8);
    test1.insert(9);
    test1.insert(10);
    test1.clear();
    test1.insert(20);
    test1.insert(17);
    test1.insert(16);
    cout << "size " << test1.size() << endl;
    test1.print();
}
