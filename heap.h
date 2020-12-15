#pragma once
#include<iostream>
using namespace std;
#include<vector>

//С��
class Heap
{
public:
    vector<int> _hp;       //���������д洢
    Heap(){}
    Heap(const int* array, int size)
    {
        _hp.resize(size);
        for (int i = 0; i < size; ++i)
            _hp[i] = array[i];

        _CreateHeap();
    }   //�����鹹���

    void Push(const int& data)
    {
        _hp.push_back(data);
        if (_hp.size() < 2)
            return;
        _AdjustUp(_hp.size() - 1);
    }

    void Pop()   //ɾ���Ѷ�
    {
        if (Empty())   return;       //���Ϊ�� ֱ�ӷ��� 
        int last = _hp.size() - 1;
        swap(_hp[last], _hp[0]);    //�����һ���͵�һ������ 
        _hp.pop_back();
        _AdjustDown(0);
    }



    bool Empty()const
    {
        return _hp.empty();   //ͨ��vector�ж� 
    }

    int Size()const
    {
        return _hp.size();
    }

    int Top()                //���ضѶ�
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
        //��ǰҶ�ӽ��ֻ��һ��������û�н�㣬ֱ���˳������õ���
        if (_hp.size() <= 1)
            return;

        //����������������㣬�ҵ�����һ����Ҷ�ӽ�㣬��ʼ����
        int root = (_hp.size() - 2) >> 1;
        for (; root >= 0; --root)
            _AdjustDown(root);
    }

    void _AdjustDown(int Parent)
    {
        //ʹ��child�����С����
        int size = _hp.size();
        int child = Parent * 2 + 1;
        while (child < size)
        {
            //�����Һ�������С��
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