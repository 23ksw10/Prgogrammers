from typing import List


class Solution:   #클래스 생성
    def assignment(self, fence: List[int]) -> int:
        start_black = [1] #시작이 검은색인 리스트
        start_white = [0] #시작이 흰색인 리스트
        start=1
        ans=0
        while start<len(fence): #입력 받은 리스트의 길이만큼 위의 두 리스트를 채워넣는다
            if start_black[start-1]==1: # 리스트값이
                start_black.append(0)
            else:
                start_black.append(1)
            if start_white[start-1]==1:
                start_white.append(0)
            else:
                start_white.append(1)
            start+=1
        start=0
        ans_white = 0 #시작이 흰색일 경우 차이
        ans_black = 0 #시작이 검은색일 경우 차이
        while start < len(fence):

            if start_black[start] != fence[start]: #비교하면서 다를 경우 증가
                ans_black+=1

            if start_white[start] != fence[start]: #비교하면서 다를 경우 증가
                ans_white+=1

            start += 1

        ans=min(ans_white,ans_black) #최솟값을 답으로 정한다
        return ans




fence = [1,1]
s=Solution()
ans=s.assignment(fence)

print(ans)




