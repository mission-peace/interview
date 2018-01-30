# python2

p = 101     #Big prime no.
def read_input():
    return raw_input().strip(), raw_input().strip()

def print_occurrences(output):
    print ' '.join(map(str, output))

def get_occurrences(pattern, text):
    return [
        i
        for i in range(len(text) - len(pattern) + 1)
        if text[i:i + len(pattern)] == pattern
    ]

def createHash(st):
    h = 0
    for i in range(len(st)):
        h += ord(st[i]) * (p**i)
    return h

def preComputeHashes(string, m):
    H = [0] * (len(string)-m+1)
    #print len(H)
    s = string[len(string)-m : ]
    H[len(string)-m] = createHash(s)
    for i in range(len(string)-m-1, -1, -1):
        H[i] = (H[i+1] - ord(string[i+m])*(p**(m-1)))*p + ord(string[i])
    #print H
    return H
    #H[0] = createHash(s[:m])
    #for i in range():

def rabinKarp(pattern, string):
    result = []
    pHash = createHash(pattern)
    #print pHash
    H = preComputeHashes(string, len(pattern))
    for i in range(len(string) - len(pattern) +1):
        if H[i] != pHash:
            continue
        elif pattern == string[i:i+len(pattern)]:
            result.append(i)
    #print result
    return result

if __name__ == '__main__':
    print_occurrences(rabinKarp(raw_input().strip(), raw_input().strip()))
