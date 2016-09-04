//
// Created by Francesco Fiduccia on 8/6/16.
//

#include "trine.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

namespace ds {

    void Trine::addWord(const string &word) {
        TrineNode *trineNode = this->getTrineNode(word);
        if (trineNode != nullptr) {
            if (trineNode->word == word) {
                cerr << "" << endl;
                return;
            }
            if (trineNode->isLeaf() && trineNode->hasChildren()) {
                // the trinode contains a word

                trineNode->addChild(word);
            } else {
                trineNode->addChild(word);
            }
            // TODO
        } else {
            this->createChildTrineNode(word, 0);

        }
    }

    trine_iterator Trine::getWordWithPrefix(const string &prefix) {
        TrineNode *node = this->getTrineNode(prefix);
        return trine_iterator(node);
    }

    TrineNode *Trine::getTrineNode(const string &prefix) {


        unsigned long position = 0;
        TrineNode *current;
        // prefix[position];
        //current = this->prefixChildrenMap[];

        //findNextTreeNode(prefix.at(position), this->children);
        current = this;
        do {
            char c = prefix.at(position);
            current = current->getChild(c);
            position++;

        } while (current != nullptr && !(current->hasWord() && current->word.compare(prefix)));
        return current;
    }

    void TrineNode::createChildTrineNode(const string &word, unsigned long position) {
        string prefix = word.substr(0, position + 1);
        TrineNode *child = new TrineNode(word, prefix, position, this);
        this->children.emplace_back(child);
        this->prefixChildrenMap[child->getPrefix()] = child;
    }

    Trine::Trine() : TrineNode("", "", 0, nullptr) {


    }

    const string &trine_iterator::getNext() {
        if (current == nullptr) {
            current = this->node;
        } else if (current->word.size() > 0) {
            
        } else if (current->hasChildren()) {
            // TODO
            // INSERT an INDEX

            current = current->getChild(index);
        } else {

        }
        return current->word;
    }

    trine_iterator::trine_iterator(TrineNode *node) : node(node) {

    }

    stack<unsigned long> trine_iterator::getNextPosition() const {
        stack<unsigned long> pnext = this->positions;
        const TrineNode *scan = current;
        while (scan->children.size() == pnext.top()) {

            pnext.pop();
            pnext.top();
            pnext.emplace();

            scan = scan->parent;
        }
        return pnext;
    }

    bool trine_iterator::hasNext() const {
        bool result = false;
        if (this->current->children.size() > positions.top()) {
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
            ost << this->getNext();
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