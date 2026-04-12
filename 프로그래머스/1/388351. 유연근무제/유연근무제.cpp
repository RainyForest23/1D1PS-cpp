#include <string>
#include <vector>

/*
[이 문제를 풀기 전 구조를 잡고 들어가보자]
C1. 시간은 어떻게?
Thought1. 
- 시간을 두개의 구조로 나눠야 할 것 같다.
- input % 100 :: HH
- {input - (입력 % 100)*100} :: MM

MM += 10;

if(MM > 59) {
    HH += 1;
    MM = MM -60;
    }
return (HH*100+MM);
    
    
}


*/

using namespace std;



int addTenMinutes(int time){
    int HH, MM;
    
    MM = time % 100; // 여기서 % 잘못 사용했음. 
    HH = time / 100; // "/" 은 그 몫을 알려주니까.
    // 처음 나의 생각 :HH = (time - (time % 100))/100;
    
    MM += 10;
    
    if (MM >= 60){ // MM > 59 보다 MM >= 60 이 더 자연스러움.
        HH += 1;
        MM = MM -60;
        
        
        return HH*100+MM;
        
    }else return HH*100+MM;
    
    /*
    % 연산자 : 나누는 수로 나누었을때의 나머지 !! 출력임!! 몫 출력이 아니라!!
    */
  
}


bool checkLate(int startday, int schedule, vector<int> timelog ){
    
    // vector<vector<int>> isLate(N, vector<int>(N, 1)) 
    // 내 의도 : timelogs 배열과 같은 크기의 배열인 isLate(N, 1로 초기화) 만들어서,
    // 이걸 bool 대신 사용하여 만약 지각이라면 isLate 배열에 0 으로 업데이트 하기.
    // 과한건 알겠는데, 일단 이게 가능할지 궁금함. 어떻게 써야하는지?
    // 지금 문제에서는 그냥 어차피 한번이라도 지각하면 나가리니까 안써도 될것같긴함.
    
    // startday = 3(wed)
    // 0 1 2 3 4 5 6 
    // 3 4 5 6 7 1 2 
    
    // startday = 5(Fri)
    // 0 1 2 3 4 5 6 
    // 5 6 7 1 2 3 4
    

        int limit = addTenMinutes(schedule);

        for (int j=0; j<7; j++){
            // 여기서 실제 요일 매칭 계산 : % 연산 통해 맞추면 된다.
            int day = (j + startday - 1) % 7 + 1; // 이 형태는 알아두자 그냥.
            // 1부터 시작하게 +1로 맞춰주고, 나머지도 다시 맞도록 -1 하는 것
            
            if (day == 6 || day == 7){
                continue;
            }
            if (timelog[j] > limit){
                return false;
            }
        }
    return true;
    
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    
    for(int i=0; i<schedules.size(); i++){
        if(checkLate(startday, schedules[i], timelogs[i])==true){
            /*
            여기서 변수가 의미하는건, 
            - 1차원 vector schedules
            - 2차원 vector timelogs
            여도, 실제로 함수 checkLate가 인자로 받고자 하는 것은 
            
            - 0차원 정수 schedule
            - 1차원 vector timelogs
            
            이므로, 각각에 [i]를 써줘야
            - 1차원 vector schedules의 [i]번째 저장된 "정수"
            - 2차원 vector timelogs의 [i]번째행인 "1차원 배열"
            이 호출되는 것이다.
            
            */
            
            answer += 1;
        }
    } return answer;
    
}

/*
checkLate 함수는 직원 1명에 대한 정보만 받는다.

따라서 solution에서 전체 데이터 중 i번째 직원의 정보만 꺼내서 넘겨야 한다.

- schedules는 전체 직원의 희망 출근 시각 목록(vector<int>)
- schedules[i]는 i번째 직원의 희망 출근 시각 1개(int)

- timelogs는 전체 직원의 출근 기록표(vector<vector<int>>)
- timelogs[i]는 i번째 직원의 7일 출근 기록 1줄(vector<int>)

즉 [i]를 붙이면
- schedules 전체 -> schedules[i] : int 하나
- timelogs 전체 -> timelogs[i] : vector<int> 한 줄
로 바뀌어서, checkLate의 매개변수 형태에 맞게 전달된다.
*/
