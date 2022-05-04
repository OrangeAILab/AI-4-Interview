//
// Created by Orange on 2022/4/13.
//本节包含基础的数据结构与基础的算法
/*
 * 基础的数据结构：
 *          线性表:
 *              创建链表/循环双向链表以及基础的增删改查:
 *
 *              创建顺序栈/队列、链式栈/队列以及基础的增删改查:
 *
 *              创建双向队列/优先队列以及基础的增删改查:
 *                  优先队列:priority_queue<Type, Container, Functional>
 *
 *
 *          二叉树:
 *              递归方式创建二叉树:
 *              非递归方式创建二叉树:
 *              字典树:[Done]
 *
 *          图：
 *              迪杰斯特拉
 *              弗洛伊德
 *              拓扑排序
 *
 * 排序算法：
 *         快速排序:
 *         归并排序:
 *         桶排序:
 *         堆排序:
 *
 * 查找算法：
 *         二分查找:
 *         哈希查找:
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <math.h>
#include <functional>
#include <algorithm>


using namespace std;

//字典树  208. 实现 Trie 【字典树】
class Trie{
private:
    bool is_words;
    Trie* dict[26];

public:
    //构造函数
    Trie(){
        this->is_words = false;

        for(int i = 0; i < 26; ++i){
            this->dict[i] = nullptr;
        }
    }

    //析构函数
    ~Trie(){
        for(int i = 0; i < 26; ++i){
            if(this->dict[i] != nullptr) delete this->dict[i];
        }
    }

    //插入
    void insert(string word){
        Trie* root = this;
        for(auto& ch : word){
            int id = ch - 'a';
            if (root->dict[id] == nullptr)  root->dict[id] = new Trie();
            root = root->dict[id];
        }
        root->is_words = true;//构成完整的单词
    }

    //查找
    bool search(string word){
        Trie* root = this;
        for(auto& ch : word){
            int id = ch - 'a';
            if (root->dict[id] == nullptr) return false;
            root = root->dict[id];
        }
        return root->is_words;
    }

    //前缀
    bool startsWith(string prefix){
        Trie* root = this;
        for(auto& ch : prefix){
            int id = ch - 'a';
            if (root->dict[id] == nullptr) return false;
            root = root->dict[id];
        }
        return true;
    }

};


//桶排序
void bucket_sort(vector<int>& nums){
    /*
     *
     * 平均时间复杂度：O(n + k)
     *最佳时间复杂度：O(n + k)
     *最差时间复杂度：O(n ^ 2)
     *空间复杂度：O(n * k)
     *稳定性：稳定
    */
    int n = nums.size();

    //计算桶的个数  get max min
    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());
    int bucket_numbers = (max - min) / n + 1;//均匀分布

    vector<int>* bucket = new vector<int>[bucket_numbers];//桶的个数

    //映射到桶内
    //int k = int(sqrt(n));
    for(int i = 0; i < n; ++i){
        int id = (nums[i] - min) / n;
        bucket[id].push_back(nums[i]);
    }

    //桶内排序
    for(int i = 0; i < bucket_numbers; ++i){
        if(bucket[i].size() > 0){
            std::sort(bucket[i].begin(), bucket[i].end());
        }
    }

    //拼接所有桶
    int index = 0;
    for(int i = 0; i < bucket_numbers; ++i){
        for(int j = 0; j < bucket[i].size(); ++j){
            nums[index++] = bucket[i][j];
        }
    }
}



//堆排序
void heap_adjust(vector<int>& nums, int len, int index){
    /*
     *时间复杂度：O(nlogn)
     *空间复杂度：O(1)
     *稳定性：不稳定
     */

    int left = index * 2 + 1;
    int right = index * 2 + 2;

    int max_index = index;

    if (left < len && nums[left] > nums[max_index]) max_index = left;
    if (right < len && nums[right] > nums[max_index]) max_index = right;

    if (max_index != index){
        std::swap(nums[index], nums[max_index]);
        heap_adjust(nums, len, max_index);//按照max_index进行递归是通过递归自动调整子树
    }

}

void heap_sort(vector<int>& nums){
    int size = nums.size();
    //构建堆（大顶堆）
    for(int i = size / 2 - 1; i >= 0; --i){
        heap_adjust(nums, size, i);
    }

    //调整堆
    for(int i = size - 1; i >= 1; --i){
        std::swap(nums[0], nums[i]);
        heap_adjust(nums, i, 0);//从索引0开始（堆顶）
    }
}


//二分查找   T = O(log n)
int binary_search(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (high - low ) / 2 + low;
        int mid_num = nums[mid];
        if ( target == mid_num){
            return mid;
        }else if(target < mid_num){
            high = mid - 1;
        }else if(target > mid_num){
            low = mid + 1;
        }
    }
    return -1;
}


//快速排序
void quick_sort(vector<int>& array, int start, int end){
    /*
     * 49 , 38, 65, 97, 76, 12, 27, 50
     *平均时间复杂度：O（nlogn）
     *最坏时间复杂度：O（n*n）
     *辅助空间O（logn）
     *稳定性：不稳定
     */

    if ( start < end){
        int i = start;
        int j = end;
        int temp = array[i];

        while(i < j){
            while(i < j && array[j] > temp){
                --j;
            }
            array[i] = array[j];
            while(i < j && array[i] <= temp){
                ++i;
            }
            array[j] = array[i];
        }
        //a quick sort has done!
        array[i] = temp;
        //sub
        quick_sort(array, start, i - 1);
        quick_sort(array, i + 1, end);

    }else{
        return;
    }
}


