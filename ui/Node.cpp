//
// Created by pavel on 04.06.18.
//

#include "Node.h"


void Node::setMarginTop(float margin) {
    this->marginTop = margin;
}

void Node::setMarginBottom(float margin) {
    this->marginBottom = margin;
}

float Node::getMarginTop() const {
    return marginTop;
}

float Node::getMarginBottom() const {
    return marginBottom;
}

Node* Node::getParentNode() const {
    return parent;
}

void Node::setParentNode(Node *parent) {
    this->parent = parent;
}
