//
// Created by heyue on 2022/4/22.
//

#ifndef INTERVIEWS_ARRAY_H
#define INTERVIEWS_ARRAY_H

using namespace  std;

int nthUglyNumber(int n);

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

//剑指 Offer II 065. 最短的单词编码 [字典树的应用]
int minimumLengthEncoding(vector<string>& words);

class Trie2{
private:
    bool is_new_word;
    Trie2* dict[26];

public:
    Trie2(){

        this->is_new_word = false;
        for(int i = 0; i < 26; ++i){
            this->dict[i] = nullptr;
        }
    }

    ~Trie2(){
        for(int i = 0; i < 26; ++i){
            if(this->dict[i] != nullptr) delete this->dict[i];
        }
    }

    int insert(string& word){
        /* 输入word = “time”
         * 插入 "emit"
         * 返回 "emit#" 编码长度 5
         * 插入 "em"
         * 由于"emit"已经插入,"em"一个新单词，返回编码长度0
         */
        Trie2* root = this;
        root->is_new_word = false;
        int size = word.size();
        for(int i = size - 1; i >=0; --i){
            int id = word[i] - 'a';
            if(root->dict[id] == nullptr){
                root->dict[id] = new Trie2();
                //"emit": new word ----"em":not a new word
                root = root->dict[id];
                root->is_new_word = true;
            }else{
                root = root->dict[id];
                root->is_new_word = false;
            }
        }
        return root->is_new_word ? (size + 1 ) : 0;
    }

    bool serach(string word){
        Trie2* root = this;
        for(auto& ch : word){
            int id = ch - 'a';
            if(root->dict[id] == nullptr) return  false;
            root = root->dict[id];
        }
        return root->is_new_word;
    }

    bool startsWith(string prefix){
        Trie2* root = this;
        for(auto& ch : prefix){
            int id = ch - 'a';
            if(root->dict[id] == nullptr) return  false;
            root = root->dict[id];
        }
        return root->is_new_word;

    }

};
#endif //INTERVIEWS_ARRAY_H
