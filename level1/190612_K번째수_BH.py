def solution(array, commands):
    answer = []

    for i in range(len(commands)):
        Temp = []
        for j in range(commands[i][1] - commands[i][0] + 1):
            Temp.append(array[commands[i][0] + j - 1])

        Temp.sort()
        answer.append(Temp[commands[i][2] - 1])

    return answer