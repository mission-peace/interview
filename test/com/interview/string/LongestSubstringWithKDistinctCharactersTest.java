package com.interview.string;

import org.junit.Assert;
import org.junit.Test;

public class LongestSubstringWithKDistinctCharactersTest {

    @Test
    public void testDifferenceCases() {
        LongestSubstringWithKDistinctCharacters longestSubstringWithKDistinctCharacters = new LongestSubstringWithKDistinctCharacters();
        Assert.assertEquals(3, longestSubstringWithKDistinctCharacters.lengthOfLongestSubstringKDistinct("eceba", 2));
        Assert.assertEquals(1, longestSubstringWithKDistinctCharacters.lengthOfLongestSubstringKDistinct("aba", 1));
        Assert.assertEquals(5, longestSubstringWithKDistinctCharacters.lengthOfLongestSubstringKDistinct("caebegcle", 4));
        Assert.assertEquals(0, longestSubstringWithKDistinctCharacters.lengthOfLongestSubstringKDistinct("eceba", 0));
    }
}
