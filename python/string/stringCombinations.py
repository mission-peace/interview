# String Combinations


def string_combinations(string, freq, start, output, level):
    print "".join(output)
    while start < len(string):
        if freq[start] > 0:
            freq[start] -= 1
            output[level] = string[start]
            string_combinations(string, freq[:], start, output, level + 1)
            output[level] = ""
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


original_string = "AABC"
freq_array, unique_string = give_freq(original_string)
string_combinations(unique_string, freq_array, 0, [""] * len(original_string), 0)
