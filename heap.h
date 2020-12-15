#pragma once
#include<iostream>
using namespace std;
#include<vector>

//小堆
class Heap
{
public:
    vector<int> _hp;       //用向量进行存储
    Heap(){}
    Heap(const int* array, int size)
    {
        _hp.resize(size);
        for (int i = 0; i < size; ++i)
            _hp[i] = array[i];

        _CreateHeap();
    }   //用数组构造堆

    void Push(const int& data)
    {
        _hp.push_back(data);
        if (_hp.size() < 2)
            return;
        _AdjustUp(_hp.size() - 1);
    }

    void Pop()   //删除堆顶
    {
        if (Empty())   return;       //如果为空 直接返回 
        int last = _hp.size() - 1;
        swap(_hp[last], _hp[0]);    //将最后一个和第一个交换 
        _hp.pop_back();
        _AdjustDown(0);
    }



    bool Empty()const
    {
        return _hp.empty();   //通过vector判断 
    }

    int Size()const
    {
        return _hp.size();
    }

    int Top()                //返回堆顶
    {
        return _hp[0];
    }

private:
    void _AdjustUp(int child)
    {
        int parent = (child - 1) >> 1;

        while (child != 0)
        {
            if (_hp[parent] > _hp[child])
            {
                swap(_hp[parent], _hp[child]);
                child = parent;
                parent = (child - 1) >> 1;
            }
            else
            {
                return;
            }
        }
    }
    void _CreateHeap()
    {
        //当前叶子结点只有一个结点或者没有结点，直接退出，不用调整
        if (_hp.size() <= 1)
            return;

        //树中至少有两个结点，找倒数第一个非叶子结点，开始调整
        int root = (_hp.size() - 2) >> 1;
        for (; root >= 0; --root)
            _AdjustDown(root);
    }

    void _AdjustDown(int Parent)
    {
        //使用child标记最小孩子
        int size = _hp.size();
        int child = Parent * 2 + 1;
        while (child < size)
        {
            //找左右孩子中最小的
            if (child + 1 < size && _hp[child] > _hp[child + 1])
                child += 1;

            if (_hp[Parent] > _hp[child])
            {
                swap(_hp[Parent], _hp[child]);
                Parent = child;
                child = Parent * 2 + 1;
            }
            else
            {
                return;
            }
        }
    }
};