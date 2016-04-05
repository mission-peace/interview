package com.interview;

import org.junit.Assert;

import java.util.List;

public class TestUtil {
    public static void compareList(List<String> expected, List<String> actual) {
        int i = 0;
        for (String str : expected) {
            Assert.assertEquals(str, actual.get(i++));
        }
    }
}
