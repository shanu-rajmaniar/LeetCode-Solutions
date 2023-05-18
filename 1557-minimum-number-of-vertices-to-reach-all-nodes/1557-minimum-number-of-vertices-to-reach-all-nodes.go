func findSmallestSetOfVertices(n int, edges [][]int) []int {
    vec := make([]int, n)
    for _, num := range edges {
        vec[num[1]]++
    }
    var ans []int
    for i := 0; i < n; i++ {
        if vec[i] == 0 {
            ans = append(ans, i)
        }
    }
    return ans;
}