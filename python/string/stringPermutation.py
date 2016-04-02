# String Permutations

"""
Given a string print all the permutations of the string
"""


def string_permutations(string, freq, output, level):
    if level == len(output):
        print "".join(output)
    start = 0
    while start < len(string):
        if freq[start] > 0:
            freq[start] -= 1
            output[level] = string[start]
            string_permutations(string, freq[:], output, level + 1)
            freq[start] += 1
        start += 1
    return None


def give_freq(string):
    freq_map = {}
    unique_string = ''.join([j for i, j in enumerate(string) if j not in string[:i]])
    for s in string:
        if s in freq_map:
            freq_map[s] += 1
        else:
            freq_map[s] = 1
    return [freq_map[s] for s in unique_string], unique_string

if __name__ == "__main__":
    original_string = "AABC"
    freq_array, unique_string = give_freq(original_string)
    string_permutations(unique_string, freq_array, [""] * len(original_string), 0)
