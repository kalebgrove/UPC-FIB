#include "BinTree.hh"
#include <list>

typedef BinTree<string> BT;

int evaluate(BT t) {
  string value = t.value();
  if (value == "+") return evaluate(t.left()) + evaluate(t.right());
  if (value == "-") return evaluate(t.left()) - evaluate(t.right());
  if (value == "*") return evaluate(t.left()) * evaluate(t.right());
  return atoi(value.c_str());
}

void preorderTraversal(BT t, list<string> &l) {
  if (t.empty()) return;
  l.push_back(t.value());
  preorderTraversal(t.left(), l);
  preorderTraversal(t.right(), l);
}

void inorderTraversal(BT t, list<string> &l) {
  if (t.empty()) return;
  inorderTraversal(t.left(), l);
  l.push_back(t.value());
  inorderTraversal(t.right(), l);
}

void postorderTraversal(BT t, list<string> &l) {
  if (t.empty()) return;
  postorderTraversal(t.left(), l);
  postorderTraversal(t.right(), l);
  l.push_back(t.value());
}

void printList(list<string> l) {
  bool writespace = false;
  for (list<string>::iterator it = l.begin(); it != l.end(); it++) {
    if (writespace) cout << " ";
    writespace = true;
    cout << *it;
  }
  cout << endl;
}


int main() {
  BT t;
  t.setInputFormat(BT::INLINEFORMAT);
  t.setOutputFormat(BT::VISUALFORMAT);
  while (cin >> t) {
    cout << t << endl;
    {
      list<string> l;
      preorderTraversal(t, l);
      cout << "Preorder traversal: ";
      printList(l);
    }
    {
      list<string> l;
      inorderTraversal(t, l);
      cout << "Inorder traversal: ";
      printList(l);
    }
    {
      list<string> l;
      postorderTraversal(t, l);
      cout << "Postorder traversal: ";
      printList(l);
    }
    //cout << "Evaluate: " << evaluate(t) << endl;
  }
}