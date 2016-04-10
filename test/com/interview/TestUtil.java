package com.interview;

import org.junit.Assert;

import java.util.List;

public class TestUtil<T> {
    public void compareList(List<T> expected, List<T> actual) {
        int i = 0;
        for (T str : expected) {
            Assert.assertEquals("Failed at index " + i, str, actual.get(i++));
        }
    }
}
