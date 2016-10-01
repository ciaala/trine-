//
// Created by Francesco Fiduccia on 8/6/16.
//

#ifndef DATA_STRUCTURE_TRINE_H
#define DATA_STRUCTURE_TRINE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
namespace ds {

    class TrineNode;

    class trine_iterator {
    private:
        stack<unsigned long> positions;
        TrineNode *node;
        TrineNode *current;
    public:
        trine_iterator(TrineNode *node);

        bool hasNext() const;

        const string &getNext();
//        friend ostream &operator<<(ostream &ost, const trine_iterator &iterator);
        stack<unsigned long,
                deque<unsigned long, allocator<unsigned long>>
        > getNextPosition() const;
        string toString();
    };

    class TrineNode {

    private:
        TrineNode(const string &word, const string &prefix, const unsigned long position, TrineNode *parent = nullptr);

        const TrineNode *parent;
        string word;
        const string prefix;
        const unsigned long position;

        vector<TrineNode *> children;
        unordered_map<char, TrineNode *> prefixChildrenMap;

        void createChildTrineNode(const string &word, unsigned long position);

    public:
//        TrineNode(const string &word, const string &prefix, const unsigned long position);

        void addChild(const string &word);

        bool hasChildren() const ;

        bool isLeaf() const ;

        bool hasWord() const;

        TrineNode *getChild(unsigned long index);

        // FRIEND Declaration
        friend class trine_iterator;

        friend class Trine;

        char getPrefix() const;

    };

    class Trine : public TrineNode {
    private:


    public:
        Trine();

    private:
        TrineNode *getTrineNode(const string &prefix);
        //  TrineNode *findNextTreeNode(char character, vector<TrineNode*> &children);


    public:
        void addWord(const string &prefix);

        trine_iterator getWordWithPrefix(const string &prefix);


    };

}


#endif //DATA_STRUCTURE_TRINE_H
