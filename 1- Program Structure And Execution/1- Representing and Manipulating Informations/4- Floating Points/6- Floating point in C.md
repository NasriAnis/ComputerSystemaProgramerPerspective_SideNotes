All versions of C provide two different floating-point data types: float(single precision) and double(double precision) in addition machines uses round to even mode.

Unfortunately, since the C standards do not re- quire the machine to use IEEE floating point, there are no standard methods to change the rounding mode or to get special values such as −0, +∞, −∞, or NaN.

Most systems provide a combination of include (.h) files and procedure libraries to provide access to these features, but the details vary from one system to an- other. For example, the GNU compiler gcc defines program constants INFINITY (for +∞) and NAN (for NaN) when the following sequence occurs in the program file:
```
#define _GNU_SOURCE 1
#include <math.h>
```

Note How we can define stuff :
```
#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)
```

![](../../../Attachements/Pasted%20image%2020260711111228.png)