function solution(array, commands) {
    var answer = [];
    commands.forEach(function(element){
        var temp = array.slice(element[0]-1, element[1]);
        temp.sort((a,b)=> a-b);
        answer.push(temp[element[2]-1]);
    })
    return answer;
}