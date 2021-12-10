#include <string>
#include <vector>

using namespace std;

void getNext(string word, vector<int>& next);

int kmpFind(string sentence, string word){
    if(word == "" || word.size() > sentence.size()) 
        return -1;
    vector<int> next(word.size());
    getNext(word, next);
    int i = 0, j = 0;
    while(i < sentence.size() && j < word.size()){
        while(j > 0 && sentence[i] != word[j]){
            j = next[j-1];
        }
        if(sentence[i] == word[j]){
            ++j;
        }
        ++i;
    }
    return j == word.size() ? i-j : -1;
}

void getNext(string word, vector<int>& next){
    next[0] = 0;
    for(int i = 1, j = 0; i < word.size(); ++i){
        while(j > 0 && word[i] != word[j]){
            j = next[j-1];
        }
        if(word[i] == word[j]){
            ++j;
        }
        next[i] = j;
    }
}

