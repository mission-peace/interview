package com.interview.dynamic;

import org.junit.Assert;
import org.junit.Test;

public class WildCardMatchingTest {

    @Test
    public void testIsMatch() {
        WildCardMatching wildCardMatching = new WildCardMatching();

        Assert.assertTrue(wildCardMatching.isMatch("xaylmz", "x?y*z"));
        Assert.assertFalse(wildCardMatching.isMatch("aa","a"));
        Assert.assertTrue(wildCardMatching.isMatch("aa","aa"));
        Assert.assertFalse(wildCardMatching.isMatch("aaa","aa"));
        Assert.assertTrue(wildCardMatching.isMatch("aa", "*"));
        Assert.assertTrue(wildCardMatching.isMatch("aa", "a*"));
        Assert.assertTrue(wildCardMatching.isMatch("ab", "?*"));
        Assert.assertFalse(wildCardMatching.isMatch("aab", "c*a*b"));
        Assert.assertTrue(wildCardMatching.isMatch("", ""));
        Assert.assertFalse(wildCardMatching.isMatch("", "a"));
        Assert.assertFalse(wildCardMatching.isMatch("a", ""));
        Assert.assertTrue(wildCardMatching.isMatch("", "*"));
        Assert.assertFalse(wildCardMatching.isMatch("", "?"));
        Assert.assertTrue(wildCardMatching.isMatch("abefcdgiescdfimde", "ab*cd?i*de"));
        Assert.assertTrue(wildCardMatching.isMatch("aaaa", "***a"));
    }

    @Test
    public void testIsMatchRecursive() {
        WildCardMatching wildCardMatching = new WildCardMatching();

        Assert.assertTrue(wildCardMatching.isMatchRecursive("xaylmz", "x?y*z"));
        Assert.assertFalse(wildCardMatching.isMatchRecursive("aa","a"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("aa","aa"));
        Assert.assertFalse(wildCardMatching.isMatchRecursive("aaa","aa"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("aa", "*"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("aa", "a*"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("ab", "?*"));
        Assert.assertFalse(wildCardMatching.isMatchRecursive("aab", "c*a*b"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("", ""));
        Assert.assertFalse(wildCardMatching.isMatchRecursive("", "a"));
        Assert.assertFalse(wildCardMatching.isMatchRecursive("a", ""));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("", "*"));
        Assert.assertFalse(wildCardMatching.isMatchRecursive("", "?"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("abefcdgiescdfimde", "ab*cd?i*de"));
        Assert.assertTrue(wildCardMatching.isMatchRecursive("aaaa", "***a"));
    }
}
