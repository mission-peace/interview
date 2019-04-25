#Rabin Karp algorithm
# Java code https://github.com/mission-peace/interview/blob/master/src/com/interview/string/RabinKarpSearch.java

prime = 101
def pattern_matching(text, pattern):
    m = len(pattern)
    n = len(text)
    pattern_hash = create_hash(pattern, m)
    text_hash = create_hash(text, m)
    for i in range(0, n - m + 1):
        if pattern_hash == text_hash:
            if check_equal(text[i:i+m], pattern):
                return i
        if i < n - m:
            text_hash = recalculate_hash(text, i, i+m, text_hash, m)
    return -1

def check_equal(str1, str2):
    if len(str1) != len(str2):
        return False
    for i, j in zip(str1, str2):
        if i != j:
            return False
    return True

def create_hash(input, end):
    hash = 0
    for i in range(0, end):
        hash = hash + ord(input[i])*pow(prime, i)
    return hash

def recalculate_hash(input, old_index, new_index, old_hash, pattern_len):
    new_hash = old_hash - ord(input[old_index])
    new_hash //= prime
    new_hash += ord(input[new_index])*pow(prime, pattern_len - 1)
    # print(locals(), new_hash) # uncomment to debug
    return new_hash

inputs = [("TusharRoy", "sharRoy"), ("TusharRoy", "Roy"),
    ("TusharRoy", "shar"), ("TusharRoy", "usha"),
    ("TusharRoy", "Tus"), ("TusharRoy", "Roa"),
    ("abcd", "cd")]
for text, pattern in inputs:
    index = pattern_matching(text, pattern)
    print("{} in {} at {}".format(pattern, text, index))
