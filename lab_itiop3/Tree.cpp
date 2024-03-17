#include <functional>
#include "proto/Tree.h"
#include "proto/Stack.h"

Tree::Tree()
{
    left = nullptr;
    right = nullptr;
    value = 0;
}

Tree::Tree(float value)
{
    left = nullptr;
    right = nullptr;
    this->value = value;
}

Tree::~Tree()
{
    delete left, right;
    left, right = nullptr, nullptr;
}

float Tree::sum()
{
    float res = 0;

    Stack *stack = new Stack;
    Tree *cur = this;
    while (cur)
    {
        res += cur->value;
        if (cur->left && cur->right)
        {
            stack->push(cur->right);
            cur = cur->left;
        }
        else if (!cur->left && !cur->right)
            if (stack->size() > 1)
                cur = stack->pop();
            else
                cur = nullptr;
        else
            cur = cur->left ? cur->left : cur->right;
    }

    delete stack;
    stack = nullptr;

    return res;
}

void Tree::add(float value)
{
    Tree *t = new Tree(value);
    Tree *cur = this;
    Tree *buff;
    while (cur)
    {
        buff = cur;
        cur = value > cur->value ? cur->left : cur->right;
    }

    value > buff->value ? buff->left = t : buff->right = t;
}

void Tree::print(std::ostream &os)
{
    std::function<void(Tree *, std::string, std::ostream &)> func;
    func = [&](Tree *tree, std::string str, std::ostream &os)
    {
        if (tree->right)
            func(tree->right, str + "-", os);

        os << str << tree->value << std::endl;

        if (tree->left)
            func(tree->left, str + "-", os);
    };
    func(this, "", os);
}
