# break single word with no spaces with multiple words into spaces
# https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/BreakMultipleWordsWithNoSpaceIntoSpace.java

def break_word(input, dicts):
    if len(input) == 0:
        return ""
    string = ""
    for i in range(len(input)):
        string += input[i]
        if string in dicts:
            r = break_word(input[i+1:], dicts)
            if r is not None:
                string += " " + r
                return string
    return None;

dicts = ["play", "to", "had", "I", "like"]
input = "Ihadliketoplay"
result = break_word(input, dicts)
print(result)    
