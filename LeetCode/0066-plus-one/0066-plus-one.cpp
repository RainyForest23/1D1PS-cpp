// Leethub Test용. 나중에 다시 풀어봐야 함

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // 뒤에서부터 처리
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            // 9인 경우 0으로 만들고 carry 넘김
            digits[i] = 0;
        }
        
        // 여기까지 오면 전부 9였다는 뜻 → 1000... 형태
        digits.insert(digits.begin(), 1);
        return digits;
    }
};