func majorityElement(nums []int) int {
    ans, cnt := nums[0], 1
    for i := 1; i < len(nums); i++ {
        if nums[i] == ans {
            cnt++
        } else {
            cnt--
        }
        if cnt == 0 {
            ans = nums[i + 1]
            cnt = 0
        }
    }
    return ans
}