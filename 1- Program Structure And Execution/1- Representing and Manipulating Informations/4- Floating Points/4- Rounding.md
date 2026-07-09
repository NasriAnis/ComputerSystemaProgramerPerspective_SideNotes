Since floating point can only approximate real arithmetic since the precision and range are limited so we need to find the closest result that can represent the floating point. for this we use rounding.

One problem rounding encounter is for values halfway between two possibilities for example 1.5 We cant for example round to the nearest so alternative approaches are to maintain a lower and upper bound on the number.

The IEEE defines four different rounding modes :
![](../../../Attachements/Pasted%20image%2020260709100838.png)

Some will say whats the point in even but in statistics etc rounding to even (nearest alternative) avoids this statistical bias in most real-life situations. It will round upward about 50% of the time and round downward about 50% of the time. Contrary to other rounding alternative.
 
Round-to-even rounding can be applied even when we are not rounding to a whole number. We simply consider whether the least significant digit is even or odd. For example, suppose we want to round decimal numbers to the nearest hundredth. We would round 1.2349999 to 1.23 and 1.2350001 to 1.24, regardless of rounding mode, since they are not halfway between 1.23 and 1.24. On the other hand, we would round both 1.2350000 and 1.2450000 to 1.24, since 4 is even.

If you always round 0.5 up ("round half up"), repeated rounding of many halfway values introduces a consistent upward _bias_ — your sums/averages creep upward over many operations. Round-to-even is _unbiased_: over many halfway cases, you round up roughly as often as you round down (since evens and odds alternate), so the errors cancel out on average rather than accumulating in one direction. That's exactly why IEEE 754 floating-point uses round-to-even as its default rounding mode.

Same thing can be applied when rounding to binary numbers for example. where encountering 1 we round up and encountering 0 we round down.

example rounding to the nearest half:
![](../../../Attachements/Pasted%20image%2020260709102613.png)

