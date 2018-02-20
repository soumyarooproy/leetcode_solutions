class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """

        # If n is negative, compute (1/x)**(-n)
        x, n = (1/x, -n) if n < 0 else (x, n)
        
        # Let n be <b_{k-1}, b_{k-2}, ... b_{0}> in bits
        # So, n = 2**(k-1)*b_{k-1}
        #         + 2**(k-2)*b_{k-2}
        #         + ...
        #         + 2**(0)*b_{0}
        #
        # So, x**n = x**(2**(k-1)*b_{k-1}
        #                + 2**(k-2)*b_{k-2}
        #                + ...
        #                + 2**(0)*b_{0})
        #
        #          = (x**(2**(k-1)*b_{k-1}))
        #            * (x**(2**(k-2)*b_{k-2})
        #            * (...)
        #            * (x**(2**(0)*b_{0}), since x**(a+b) = (x**a) * (x**b)
        #
        # So, extract the bits from n in LSB to MSB order and compute
        # x**(2**k) as (x**(2**(k-1)))**2
        
        res = 1.0        
        while n:         # iterate over bits of n in LSB->MSB order
            if n & 0x1:
                res *= x
            x *= x       # compute x**(2**k) as (x**(2**(k-1)))**2
            n >>= 1
        
        return res
