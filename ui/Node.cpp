//
// Created by pavel on 04.06.18.
//

#include "Node.h"

Node* Node::getParentNode() const {
    return parent;
}

void Node::setParentNode(Node *parent) {
    this->parent = parent;
}
