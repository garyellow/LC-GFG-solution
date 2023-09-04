class Solution {
    companion object {
        var arr = arrayOf(BigInteger.ONE)
    }

    init {
        if (arr.size == 1) {
            var ans = BigInteger.ONE
            for (x in 1..10000) {
                ans *= x.toBigInteger()
                arr += ans
            }
        }
    }

    fun trailingZeroes(n: Int): Int {
        var num = arr[n]
        return num.toString().length - num.toString().trimEnd('0').length
    }
}