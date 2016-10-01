//
// Created by Francesco Fiduccia on 8/6/16.
//

#include "Trine.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

namespace ds {

    void Trine::addWord(const string &word) {
        TrineNode *trineNode = this->getTrineNode(word);
        if (trineNode->word == word) {
            cerr << "word is already tracked '" << word << "'" << endl;
            return;
        } else {
            // the node has a word
            // the word is longer than the prefix

            if (trineNode->hasWord()
                && trineNode->word.length() > (trineNode->position + 1)) {
                // the trinode contains a word

                trineNode->addChild(trineNode->word);
                trineNode->word = "";
                addWord(word);
            } else {
                trineNode->addChild(word);
            }
        }
        // TODO
    }

    trine_iterator Trine::getWordWithPrefix(const string &prefix) {
        TrineNode *node = this->getTrineNode(prefix);
        return trine_iterator(node);
    }

    /**
     * Return the TrineNode with the longest match against the prefix
     *
     * @param prefix
     * @return
     */
    TrineNode *Trine::getTrineNode(const string &prefix) {


        unsigned long position = 0;
        TrineNode *current = this;
        // prefix[position];
        //current = this->prefix_ChildrenMap[];

        //findNextTreeNode(prefix.at(position), this->children);

        /*
        do {

            c = prefix.at(position);

             if ( current->prefixChildrenMap.count(c) > 0) {
                current = current->prefixChildrenMap.at(c);
            } else {
                current = nullptr;
            }
            position++;

        }
        // current exists
        */
        char c = prefix.at(position);
        while (current != nullptr && current->prefixChildrenMap.count(c) > 0) {
            current = current->prefixChildrenMap.at(c);
            c = prefix.at(position);
        }
        //&& !(current->hasWord() && current->word.compare(prefix)));
        return current;
    }

    void TrineNode::createChildTrineNode(const string &word, unsigned long position) {
        string prefix = word.substr(0, position + 1);
        TrineNode *child = new TrineNode(word, prefix, position, this);
        this->children.emplace_back(child);
        this->prefixChildrenMap[child->getPrefix()] = child;
    }

    Trine::Trine() : TrineNode("", "", -1, nullptr) {


    }

    const string &trine_iterator::getNext() {
        if (current == nullptr) {
            current = this->node;
        } else if (current->word.size() > 0) {

        } else if (current->hasChildren()) {
            // TODO
            // INSERT an INDEX
            unsigned long index;
            current = current->getChild(index);
        } else {

        }
        return current->word;
    }

    trine_iterator::trine_iterator(TrineNode *node)
            : node(node) {}

    stack<unsigned long> trine_iterator::getNextPosition() const {
        stack<unsigned long> pnext = this->positions;
        const TrineNode *scan = current;
        while (pnext.size() > 0 && scan->children.size() == pnext.top()) {

            pnext.pop();
            pnext.top();
            scan = scan->parent;
        }
        //
        // there are children and
        // and we have not reached the last children
        //
        if (scan->children.size() > 0 &&
            (pnext.size() == 0 ||
             scan->children.size() > pnext.top())) {
            unsigned long next = pnext.top() + 1;
            pnext.emplace(next);
        }

        return pnext;
    }

    bool trine_iterator::hasNext() const {
        bool result;
        if (this->current != nullptr
            && this->positions.size() > 0
            && this->current->children.size() > this->positions.top()) {
            result = true;
        } else {
            result = !this->getNextPosition().empty();
        }
        return result;
    }

    string trine_iterator::toString() {
        ostringstream ost;
        bool hasNext;
        do {
            ost << "node: " << this->getNext();
            hasNext = this->hasNext();
            if (hasNext) {
                ost << ",";
            }
        } while (hasNext);
        return ost.str();
    }

    bool TrineNode::hasChildren() const {
        return this->children.size() > 0;
    }

    TrineNode *TrineNode::getChild(unsigned long index) {
        TrineNode *child;
        if (this->children.size() > index) {
            child = this->children.at(index);
        } else {
            child = nullptr;
        }
        return child;
    }

    bool TrineNode::hasWord() const {
        return this->word.size() > 0;
    }

    bool TrineNode::isLeaf() const {
        return this->hasChildren() && this->hasWord();
    }

    void TrineNode::addChild(const string &word) {
        // Add a child node
        this->createChildTrineNode(word, this->position + 1);
        /*
            if (this->hasWord()) {

            }
        */
    }

    char TrineNode::getPrefix() const {
        return this->prefix.at(this->position);
    }


    TrineNode::TrineNode(const string &word, const string &prefix, const unsigned long position, TrineNode *parent) :
            word(word),
            prefix(prefix),
            position(position),
            parent(parent) {


    }
/*
    ostream &operator<<(ostream &ost, const trine_iterator &iterator) {

    }
*/
}