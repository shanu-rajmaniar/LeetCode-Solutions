func findDuplicate(nums []int) int {
    var n int = len(nums)
    for i := 0; i < n; i++ {
        x := int(math.Abs(float64(nums[i])))
        if nums[x] < 0 {
            return x
        }
        nums[x] *= -1
    }
    return 1;
}