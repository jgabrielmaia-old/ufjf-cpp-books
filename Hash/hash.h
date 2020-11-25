template <typename T>
class HashNode
{
public:
    int hit_count;
    HashNode *next;
    int key;
    T value;
    HashNode(int key, T value, HashNode<T> *next);
};

template <typename T>
class HashTable
{
private:
    HashNode<T> **nodeChainedList;
    int capacity;

public:
    HashTable(int capacity);
    ~HashTable();

    void insert(int key, T value);
    T fetch(int key);
};
