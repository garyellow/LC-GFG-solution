/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    int index = 0;
    vector<NestedInteger> nestedList;
    NestedIterator *cur = nullptr;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->nestedList = nestedList;
    }
    
    int next() {
        if(cur && cur->hasNext()) return cur->next();
        return nestedList[index++].getInteger();
    }
    
    bool hasNext() {
        while(index < nestedList.size() && !(cur && cur->hasNext())) {
            if(nestedList[index].isInteger()) break;
            cur = new NestedIterator(nestedList[index++].getList());
        }
        return index < nestedList.size() || cur && cur->hasNext();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */