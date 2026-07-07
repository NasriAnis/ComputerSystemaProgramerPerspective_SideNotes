Before going any further we need to consider binary numbers having fractional values, for that lets examine decimal notation:
![](../../../Attachements/Pasted%20image%2020260706123250.png)

there each digit d range from 0 to 9 this representation represent a value d where d:
![](../../../Attachements/Pasted%20image%2020260706123337.png)

Note that the weight of the digits are relative to the decimal point (`.`), to the left digits are weighted by positive power of 10 (integral value) and to the right negative power of 10 (fractional value).

for example:  12.34 represents the number 1 × 10^1 + 2 × 10^0  + 3 × 10^−1 + 4 × 10^−2 = 12 34/100 .

**Note**: writing for example 12 34/100 mean 12 is the integral value left the (`.`) and 34/100 is the value right the (`.`) fractional value.

by analogy we can consider fractional binary number being represented the same way but the weight are of power of 2.
![](../../../Attachements/Pasted%20image%2020260706123827.png)
![](../../../Attachements/Pasted%20image%2020260706123834.png)

the (`.`) symbol is called the binary point. For example, 101.11 represents the number 1 × 2^2 + 0 × 2^1 + 1 × 2^0 + 1 × 2^−1 + 1 × 2^−2 = 4 + 0 + 1 + 1/2 + 1/4 = 5 4/3 .

One can readily see from Equation that shifting the binary point one position to the left has the effect of dividing the number by 2. For example, while 101.11 represents the number 5 3/4 , 10.111 represents the number 2 + 0 + 1/2 + 1/4 + 1/8 = 2 7/8 . Similarly, shifting the binary point one position to the right has the effect of multiplying the number by 2. For example, 1011.1 represents the number 8 + 0 + 2 + 1 + 1/2 = 11 1/2.

Assuming we consider only finite-length encoding, decimal notation cannot represent numbers such as 1/3, 5/7 exactly. Similarly, fractional binary notation can only represent numbers that can be written x * 2^y . Other values can only be approximated. For example, the number 1/5 can be represented exactly as the fractional decimal number 0.20. 

As a fractional binary number, however, we cannot represent it exactly and instead must approximate it with increasing accuracy by lengthening the binary representation:
![](../../../Attachements/Pasted%20image%2020260706125741.png)

Looking at 1/4 we can represent it clearly in binary since 1/4=1×2^−2.

---

## **Additional**:

from fraction to decimal: 

### Method 1: Long division

Just divide numerator by denominator: $3÷43 \div 4 3÷4$.

$3÷4=0.753 \div 4 = 0.753÷4=0.75$

Step by step: $3.00÷43.00 \div 4 3.00÷4$

- $30÷4=730 \div 4 = 7 30÷4=7$ remainder 22 2 → first decimal digit is 7
- $20÷4=520 \div 4 = 5 20÷4=5$ remainder 00 0 → second decimal digit is 5
- remainder is 0, so we stop

Result: 0.750.75 0.75

### Method 2: Make the denominator a power of 10

If you can multiply top and bottom to turn the denominator into 10,100,100010, 100, 1000 10,100,1000, etc., you can read off the decimal directly.

$34=3×254×25=75100=0.75\frac{3}{4} = \frac{3 \times 25}{4 \times 25} = \frac{75}{100} = 0.7543​=4×253×25​=10075​=0.75$

This works because 4×25=1004 \times 25 = 100 4×25=100. This method only works cleanly when the denominator's prime factors are only 2s and 5s (since $10=2×510 = 2 \times 5 10=2×5$) — which is exactly the case for 4=224 = 2^2 4=22.


from decimal to decimal: 

### Method: Multiply by 2 repeatedly

Take the fractional part, multiply by 2. The integer part (0 or 1) becomes the next binary digit. Keep the leftover fractional part and repeat.

$34=0.75\frac{3}{4} = 0.7543​=0.75$

|Step|Value|× 2|Integer part (bit)|Remaining fraction|
|---|---|---|---|---|
|1|0.75|1.50|**1**|0.50|
|2|0.50|1.00|**1**|0.00|

Remainder hits 0 → we stop.

Reading the bits top to bottom: $0.7510=0.1120.75_{10} = 0.11_2 0.7510​=0.112​$