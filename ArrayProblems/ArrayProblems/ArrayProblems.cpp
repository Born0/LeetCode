#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void missingNumber(vector<int>& v);
int removeDuplicates(vector<int>& v);
void elementRemoveAt(vector<int>& v, int i);
int elementRemove(vector<int>& v, int data);
int searchInsert(vector<int>& v, int target);
vector<int> plusOne(vector<int>& v);
void merge(vector<int>& v1, int m, vector<int>& v2, int n);
int singleNumber(vector<int>& v);
int majorityElement(vector<int>& v);
bool containsDuplicate(vector<int>& v);
void moveZeroes(vector<int>& v);

int main()
{

    vector<int> v{1,2,3,4,5 };

    moveZeroes(v);
    for (size_t i = 0;i < v.size();i++)
    {
        cout << v[i];
    }
    cout << endl;


  /*  vector<int>v2 = { 2,5,6 };

    merge(v,3,v2,3);
 
    cout <<endl<< "merged :" << endl;

    for (size_t i = 0;i < v.size();i++)
    {
        cout << v[i];
    }*/



}



void missingNumber(vector<int>& v)
{
    int s = v.size();

    sort(v.begin(), v.end());
    if (v[0] != 0)
    {
        cout << "missing: " << 0;
        return;
    }
    if (s == 1 && v[0]==1)
    {
        cout << "missing: " << 0;
        return;
    }
    bool flag = false;

    for (size_t i = 0;i < s-1;i++)
    {
        if (v[i]+1 !=v[i+1])
        {
            flag = true;
            cout << "missing: " << ++v[i];
            break;
        }
    }

    if (!flag)
    {
        cout << "missing: " << v[s-1]+1;
    }
}

int removeDuplicates(vector<int>& v) 
{
    int s = v.size();

    for (size_t i = 0; i < v.size()-1; i++)
    {
        if (v[i] == v[i + 1] && v[i]!=INT16_MIN)
        {
            v.erase(v.begin() + (i + 1));
           // elementRemover(v, i + 1);
            i -= 1;
        }
    }
    return v.size();
}
void elementRemoveAt(vector<int>& v, int i)
{
    int s = v.size();
    if (s - 1 == i)
    {
        v[s - 1] = INT16_MIN;
    }
    else
    {
        for (size_t j = i;j < s-1;j++)
        {
            v[j] = v[j + 1];
        }
        v[s - 1] = INT16_MIN;
    }

}

int elementRemove(vector<int>& v, int data)
{
    for (size_t i=0;i<v.size();i++)
    {
        if (v[i] == data)
        {
            v.erase(v.begin() + i);
            i--;
        }     
    }
    return v.size();
}

int searchInsert(vector<int>& v, int target) 
{
    if (v[0] > target)
    {
        return 0;
    }
    else if (v[v.size() - 1] < target)
    {
        return v.size();
    }
    else
    {
        vector<int>::iterator it = find(v.begin(), v.end(), target);
        if (it != v.end())
        {
            return it - v.begin();
        }
        else
        {
            for (size_t i = 1; i < v.size();i++)
            {
                if (v[i] > target)
                {
                    if (v[i - 1] < target)
                    {
                        return i ;
                    }
                }
            }
        }
    }
    return -2;

}

vector<int> plusOne(vector<int>& v)
{
   
    int s = v.size();
    if (v[ s- 1] != 9)
    {
        v[s - 1] += 1;
        return v;
    }
    else
    {
        //1 8 9 9 9
        int carry = 0;
        for (int i = s - 1;i >= 0;i--)
        {
            if (v[i]==9)
            {
                v[i] = 0;
                carry = 1;
            }
            else
            {
                v[i] += 1;
                carry = 0;
                break;
            }
        }
        if (carry)
        {
            v.insert(v.begin(), 1);
        }
        return v;
    }
}

void merge(vector<int>& v1, int m, vector<int>& v2, int n) 
{
    v1.erase(v1.begin() + m, v1.end());
    for (auto i : v2)
    {
        v1.push_back(i);
    }
    sort( v1.begin(), v1.end());

    /*for (size_t i = 0;i < v1.size();i++)
    {
        cout << v1[i];
    }

    int i = 0, j = 0;
    for (i = 0;i < m;)
    {
        if ( j < n)
        {
            if ( v1[i] <= v2[j])
            {
                i++;
            }
            else
            {
                v1.insert(v1.begin()+i,v2[j]);
                j++;
            }
        }
        else
        {
            break;
        }
    }*/
    /*int s = v1.size() - n;
    v1.erase( v1.begin()+s, v1.end());*/
}

int singleNumber(vector<int>& v) 
{
    if (v.size() == 1)
    {
        return v[0];
    }
    sort(v.begin(), v.end());
    for (size_t i = 0;i < v.size() ;i++)
    {
        if (v[i] == v[i + 1])
        {
            i++;
        }
        else
        {
            return v[i];
        }
    }
    return -1;
}
int majorityElement(vector<int>& v) 
{
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}
bool containsDuplicate(vector<int>& v) 
{
    sort(v.begin(), v.end());
    bool flag = false;

    for (size_t i = 0; i < v.size()-1; i++)
    {
        if (v[i] == v[i + 1])
        {
            flag = true;
        }
    }
    return flag;
}
void moveZeroes(vector<int>& v) {
    int s = v.size();
    v.erase(
            remove(v.begin(), v.end(), 0),
            v.end());

    int res= accumulate(v.begin() + 1, v.begin() + 4, 0);
    cout << res;

    /*int n = s - v.size();
    for (size_t i = 0;i < n;i++)
    {
        v.push_back(0);
    }*/

}
