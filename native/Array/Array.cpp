#include "Array.h"
#include <cstdlib>
#include <sstream>

using namespace std;
using namespace JSM;


void Array::contains(CScriptVar *c, void *data) {
  CScriptVar *obj = c->getParameter("obj");
  CScriptVarLink *v = c->getParameter("this")->firstChild;

  bool contains = false;
  while (v) {
    if (v->var->equals(obj)) {
    contains = true;
    break;
    }
    v = v->nextSibling;
  }

  c->getReturnVar()->setInt(contains);
}

void Array::remove(CScriptVar *c, void *data) {
  CScriptVar *obj = c->getParameter("obj");
  vector<int> removedIndices;
  CScriptVarLink *v;
  // remove
  v = c->getParameter("this")->firstChild;
  while (v) {
    if (v->var->equals(obj)) {
    removedIndices.push_back(v->getIntName());
    }
    v = v->nextSibling;
  }
  // renumber
  v = c->getParameter("this")->firstChild;
  while (v) {
    int n = v->getIntName();
    int newn = n;
    for (size_t i=0;i<removedIndices.size();i++)
    if (n>=removedIndices[i])
      newn--;
    if (newn!=n)
    v->setIntName(newn);
    v = v->nextSibling;
  }
}

void Array::join(CScriptVar *c, void *data) {
  string sep = c->getParameter("separator")->getString();
  CScriptVar *arr = c->getParameter("this");

  ostringstream sstr;
  int l = arr->getArrayLength();
  for (int i=0;i<l;i++) {
  if (i>0) sstr << sep;
  sstr << arr->getArrayIndex(i)->getString();
  }

  c->getReturnVar()->setString(sstr.str());
}



void Array::registerFunctions(CTinyJS *tinyJS) {
  tinyJS->addNative("function Array.contains(obj)", &Array::contains, 0);
  tinyJS->addNative("function Array.remove(obj)", &Array::remove, 0);
  tinyJS->addNative("function Array.join(separator)", &Array::join, 0);
}
