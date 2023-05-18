func canJump(nums []int) bool {
    n := len(nums)
    maxi := nums[0]
    for i := 1; i < n; i++ {
        if maxi < i {
            return false
        }
        maxi = int(math.Max(float64(maxi), float64(i + nums[i])))
    }
    return true
}