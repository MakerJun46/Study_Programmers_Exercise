def solution(s):
    answer = ""
    l = list(s)

    l.sort()
    l.reverse()

    for i in range(0, len(l)) :
        if(l[i].islower()) :
            front = l[i:]
            back = l[:i]
            break

    for i in front :
        answer += i

    for i in back :
        answer += i

    return answer

print(solution("caCbdA"))
print(solution("Zbcdefg"))


"""
# Best Answer
def solution(s):
    return "".join(sorted(list(s), reverse=True));
"""