//
// Created by heyue on 2022/4/13.
//
using  namespace  std;
#ifndef INTERVIEWS_BASIC_ALGORITHM_H
#define INTERVIEWS_BASIC_ALGORITHM_H

void quick_sort(vector<int>& array, int start, int end);

int binary_search(vector<int>& nums, int target);

void heap_adjust(vector<int>& nums, int len, int index);

void heap_sort(vector<int>& nums);

void bucket_sort(vector<int>& nums);

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
#endif //INTERVIEWS_BASIC_ALGORITHM_H
