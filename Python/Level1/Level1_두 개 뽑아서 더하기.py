import  itertools

def solution(numbers):

    result = set()
    permutation = list(itertools.permutations(numbers, 2))

    for i in permutation :
        result.add(sum(i))

    answer = list(result)
    answer.sort()

    return answer

#return sorted(list(set(answer))) .. sorted(iterator, data, reverse) => 정렬된 자료형 반환




print(solution([1,2,3,4]))
