package com.interview.misc;

import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * Given a nested list of integers, implement an iterator to flatten it.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/
 */
public class NestedIterator implements Iterator<Integer> {

    private final Deque<NestedInteger> stack;
    private NestedInteger current;
    private final Deque<Integer> positionStack;
    private int position = 0;

    public NestedIterator(List<NestedInteger> nestedList) {
        NestedInteger ni = new NestedIntegerImpl(nestedList);
        current = ni;
        this.stack = new LinkedList<>();
        this.positionStack = new LinkedList<>();
    }

    @Override
    public Integer next() {
        return current.getList().get(position++).getInteger();
    }

    @Override
    public boolean hasNext() {
        if (position < current.getList().size()) {
            NestedInteger i = current.getList().get(position);
            if (i.isInteger()) {
                return true;
            } else {
                stack.offerFirst(current);
                positionStack.offerFirst(position + 1);
                current = i;
                position = 0;
                return hasNext();
            }
        } else {
            if (stack.isEmpty()) {
                return false;
            }
            current = stack.pollFirst();
            position = positionStack.pollFirst();
            return hasNext();
        }
    }
}

class NestedIntegerImpl extends NestedInteger {

    private List<NestedInteger> list;
    NestedIntegerImpl(List<NestedInteger> list) {
        this.list = list;
    }

    @Override
    public boolean isInteger() {
        return false;
    }

    @Override
    public Integer getInteger() {
        return null;
    }

    @Override
    public List<NestedInteger> getList() {
        return list;
    }
}


abstract class NestedInteger {
    abstract boolean isInteger();
    abstract Integer getInteger();
    abstract List<NestedInteger> getList();
}